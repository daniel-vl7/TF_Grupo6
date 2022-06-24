#pragma once
#include <iostream>
using namespace System::Drawing;

//clase padre de personaje y enemigo

class Sujeto {
protected:
	int x, y;
	int idx, idy;
	int dx, dy;
	int width, height;
	int direction;
	bool visible;
	
public:
	Sujeto(int x, int y, int dx, int dy, int width, int height, int direction){
		this->x = x;
		this->y = y;
		this->dx = dx;
		this->dy = dy;
		this->width = width;
		this->height = height;
		this->direction = direction;
		
		visible = true;
		idx = idy = 0;
	}
	~Sujeto(){}
	
	void dibujar(Graphics^ g, Bitmap^ bmp) {
		Rectangle section = Rectangle(idx * width, idy * height, width, height);
		Rectangle zoom = Rectangle(x, y, width * 1.0, height * 1.0);
		g->DrawImage(bmp, zoom, section, GraphicsUnit::Pixel);
	}

	virtual void mover(){}
	bool getVisible() { return visible; }
	void setVisible(bool value) { visible = value; }

	int getX() { return x; }
	int getY() { return y; }
	int getDirection() { return direction; }

	void setX(int value) { x = value; }
	void setY(int value) { y = value; }
	void setDxy(int value) { dx = value; dy = value; }

	Rectangle getRectangle() {
		return Rectangle(x, y, width, height);
	}
};