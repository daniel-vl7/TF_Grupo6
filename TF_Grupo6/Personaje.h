#pragma once
#include "Sujeto.h"
//clase hija de Sujeto
class Personaje : public Sujeto {
private:
public:
	Personaje(int x, int y, int dx, int dy, int width, int height, int direction) :
	Sujeto(x, y, dx, dy, width, height, direction) {}
	~Personaje(){}

	void mover(Graphics^ g, char i) {
		switch (i)
		{
		
		case 'A':
			if (x > 0) {
				x -= dx;
				idy = 1;
				direction = 1;
			}
			break;

		case 'D':
			if (x + width * 1.0 < g->VisibleClipBounds.Width) {
				x += dx;
				idy = 2;
				direction = 4;
			}
			break;

		case 'W':
			if (y > (g->VisibleClipBounds.Height)/1.7) { //sube hasta mitad del mapa
				y -= dy;
				idy = 3;
				direction = 2;
			}
			break;

		case 'S':
			if (y + height * 1.0 < g->VisibleClipBounds.Height) {
				y += dy;
				idy = 0;
				direction = 3;
			}
			break;
		}

		idx++;
		if (idx > 3)idx = 0;
	}
};