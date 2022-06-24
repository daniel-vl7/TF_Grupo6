#pragma once
#include <iostream>

using namespace System::Drawing;

class Residuo {
private:
	bool visible;
	int x, y;
	int width, height;
	//prueba
	int tipo;
public:
	Residuo(int x,int y, int width, int height,int tipo){
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
		this->tipo = tipo;
		visible = true;
	}
	~Residuo(){}

	void dibujar(Graphics^ g, Bitmap^ bmp) {
		g->DrawImage(bmp, x, y, width * 0.07, height * 0.07);
	}

	bool getVisible() { return visible; }
	void setVisible(bool value) { visible = value; }

	int getTipo() { return tipo; }
	void setTipo(int value) { tipo = value; }

	Rectangle getRectangle() {
		return Rectangle(x, y, width*0.5, height*0.5);
	}
};