#pragma once

using namespace System::Drawing;

class Aliado
{
private:
	int x, y;
	int dx, dy;
	int idx, idy;
	int width, height;
	int direction;
public:
	Aliado(int y, int width, int height) {
		this->y = y;
		this->width = width;
		this->height = height;
		x = 30;
		dx = dy = 4;
		direction = 1;
		idx = idy = 0;
	}
	~Aliado(){}
	
	void dibujar(Graphics^ g, Bitmap^ bmpAliado) {
		Rectangle section = Rectangle(idx * width, idy * height, width, height);
		Rectangle zoom = Rectangle(x, y, width * 0.3, height * 0.3);
		g->DrawImage(bmpAliado, zoom, section, GraphicsUnit::Pixel);
	}

	void mover(Graphics^ g, int xPersonaje) {
		if (x + width * 0.3 <= xPersonaje)
		{
			if (direction == 1) idx = 0;
			x += dx;
			direction = 0;
		}
		
		if (xPersonaje != x) idx++;
		else idx = 0;

		if (idx >9) idx = 0;
	}
};