#ifndef UNIT_H
#define UNIT_H
struct Vec2{
    int e1;
    int e2;
    int& x(){ return e1;}
	int x() const { return e1; }
    int& y(){ return e2;}
	int y() const { return e2; }
    int& width(){return e1;}
    int& height(){return e2;}
	bool operator!=(const Vec2& other) const {
    	return x() != other.x() || y() != other.y();
	}
};

using Position = Vec2;

enum Color {BLACK=0, RED, GREEN, YELLOW, BLUE, PINK, CYAN, WHITE, NOCHANGE};

#endif
