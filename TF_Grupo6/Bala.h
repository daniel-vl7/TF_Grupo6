#pragma once
#include <iostream>
using namespace System::Drawing;
//ERROR EN MOVIMIENTO 
class Bala {
private:
	int x, y;
	int dx;
	int width, height;
	bool visible;
	int idx, idy;

public:
	Bala(int x, int y, int width, int height) {
		dx = 7;
		visible = true;
		idx = idy = 0;
	}
	~Bala(){}

	void dibujar(Graphics^ g, Bitmap^ bmp) {
		Rectangle section = Rectangle(idx * width, idy * height, width, height);
		Rectangle zoom = Rectangle(x, y, width * 1.0, height * 1.0);
		g->DrawImage(bmp, zoom, section, GraphicsUnit::Pixel);
	}

	void mover() {
		
		if (x > 0)x -= dx;
		idx = 0;
		idx++;
		if (idx > 1)idx = 0;
	}

	int getX() { return x; }
	int getXWidth() { return x + width * 1.0; }
	int getY() { return y; }
	int getYHeight() { return y + height * 1.0; }

	bool getVisible() { return visible; }
	void setVisible(bool value) { visible = value; }

	Rectangle getRectangle() {
		return  Rectangle(x, y, width * 1.0, height * 1.0);
	}
};