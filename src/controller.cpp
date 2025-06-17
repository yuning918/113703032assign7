#include <iostream>
#include <ctime>
#include <thread>
#include <unistd.h>
#include <termios.h>
#include <set>
#include <algorithm>

#include "player.h"
#include "obstacle.h"
#include "environment.h"
#include "controller.h"
#include "gameObjectFactory.h"
#include "RPSGameObject.h"


Controller::Controller(View& view) : _view(view){		
	// Added codea(start)
		Position playerPos = {9,16};
		_objs.push_back(new player(playerPos));
		int x_top = rand() % 20;
		Position topPos = {x_top, -4};
		_objs.push_back(new obstacle(topPos, 0));
		int y_left = rand() % 4 + 15;
		Position leftPos = {-4, y_left};
		_objs.push_back(new obstacle(leftPos, 1));
		// (end)

}

Controller::~Controller() {
    for (RPSGameObject* _obj : _objs) {
        delete _obj;
    }
    _objs.clear();
}

void Controller::run() {
    // initial setup
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    configure_terminal();

    // init state
    int input = -1;
    clock_t start, end;

    // Main loop
    while (true) {
        start = clock();
        // game loop goes here
        input = read_input();

        // ESC to exit program
        if(input==27)break;

        this->handleInput(input);

        _view.resetLatest();
	// determine whether to generate new obstacle;
	bool newTop = true, newLeft = true;
	for(RPSGameObject* obj:_objs){
		if(obj->getType() == TOP && obj->getPosition().y() < 2) {
			newTop = false;
			break;
		}
		if(obj->getType() == LEFT && obj->getPosition().x() < 15) {
			newLeft = false;
			break;
		}
	}
	if(newTop){
		int x_top = rand() % 20;
		Position topPos = {x_top, -4};
		_objs.push_back(new obstacle(topPos, 0));
	}
	if(newLeft){
		int y_left = rand() % 4 + 15;
		Position leftPos = {-4, y_left};
		_objs.push_back(new obstacle(leftPos, 1));
	}

	// update	
	for(RPSGameObject* obj : _objs){
		obj->updateAll(obj);
	}
 
	// Is collision occur? If it happen to player, then game over.
	bool alive = true;
    	for (size_t i = 0; i < _objs.size(); ++i) {
		for (size_t j = i + 1; j < _objs.size(); ++j) {
        		ICollider* a = dynamic_cast<ICollider*>(_objs[i]);
        		ICollider* b = dynamic_cast<ICollider*>(_objs[j]);
           		if (a && b) {
				if(a -> intersect(b) || b-> intersect(a)){
					if (dynamic_cast<player*>(a)) alive = false;
					if (dynamic_cast<player*>(b)) alive = false;
            				a->onCollision(b);
            				b->onCollision(a);
				}
        		}
    		}
	}

	for(auto obj:_objs){
            _view.updateGameObject(obj);
	}
        _view.render();	

	if(!alive){
		std::cout << "Game Over!" << std::endl;
		break;
	}

        end = clock();

        // frame rate normalization
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        if (time_taken > SPF) continue;
        int frameDelay = int((SPF - time_taken) * 1000); // 0.1 seconds
        if(frameDelay > 0) std::this_thread::sleep_for(std::chrono::milliseconds(frameDelay)); // frame delay
    }

}



void Controller::handleInput(int keyInput){

    // If there is no input, do nothing.
    if(keyInput==-1)return;
    

    // TODO 
    // handle key events.
    for(RPSGameObject* obj : _objs) 
    {	
	player* p = dynamic_cast<player*>(obj);
        if (!p) continue;

        if (keyInput == 119) { // w = jump
	    p->jump();
            p->update(1);
        } else if(keyInput == 115){
	    p->update(2);
    	} else if (keyInput == 97) { // a = left
            p->update(3);
        } else if (keyInput == 100) { // d = right
            p->update(4);
        }
    }
	return;
}

void Controller::update(){

}
void reset_terminal() {
    printf("\e[m"); // reset color changes
    printf("\e[?25h"); // show cursor
    fflush(stdout);
    tcsetattr(STDIN_FILENO, TCSANOW, &old_termios);
}

// terminal initial configuration setup
void configure_terminal() {
tcgetattr(STDIN_FILENO, &old_termios);
	new_termios = old_termios; // save it to be able to reset on exit
    
    new_termios.c_lflag &= ~(ICANON | ECHO); // turn off echo + non-canonical mode
    new_termios.c_cc[VMIN] = 0;
    new_termios.c_cc[VTIME] = 0;

    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);

    printf("\e[?25l"); // hide cursor
    std::atexit(reset_terminal);
}


int read_input() {
    fflush(stdout);
   	char buf[4096]; // maximum input buffer
	int n = read(STDIN_FILENO, buf, sizeof(buf));
    return n > 0 ? buf[n - 1] : -1;
}

