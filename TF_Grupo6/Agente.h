#pragma once
#include "Sujeto.h"

class Agente : public Sujeto {
public:
	Agente(int x, int y, int dx, int dy, int width, int height, int direction) :
		Sujeto(x, y, dx, dy, width, height, direction) {}
	~Agente() {}

	void mover(Graphics^ g) {
		if (y + height * 1.0 > g->VisibleClipBounds.Height || y < 0) {
			dy *= -1;
		}
		//revisar
		if (dy > 0)idy = 0;
		else idy = 1;
		y += dy;

		idy++;
		if (idy > 2)idy = 0;
	}
};