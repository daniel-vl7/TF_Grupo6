#pragma once
#include <iostream>
using namespace System::Drawing;

class Bala {
private:
	int x, y;
	int dx;
	int width, height;
	bool visible;


public:
	Bala(int x, int y, int width, int height) {
		this->x = x;
		this->y = y;
		this->width = width;
		this->height=height;
		dx = 7;
		visible = true;
		
	}
	~Bala(){}

	void dibujar(Graphics^ g, Bitmap^ bmp) {
		g->DrawImage(bmp, x, y, width * 0.1, height * 0.1);
	}

	void mover() {
		
		if (x >= 0)x -= dx;
		
	}

	int getX() { return x; }
	int getY() { return y; }
	

	bool getVisible() { return visible; }
	void setVisible(bool value) { visible = value; }

	Rectangle getRectangle() {
		return  Rectangle(x, y, width * 0.1, height * 0.1);
	}
};