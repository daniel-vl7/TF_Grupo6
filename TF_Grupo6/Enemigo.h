#pragma once
#include "Sujeto.h"

class Enemigo :public Sujeto {

public:
	Enemigo(int x, int y, int dx, int dy, int width, int height, int direction): 
		Sujeto(x, y, dx, dy, width, height, direction) {}
	~Enemigo(){}

	void mover(Graphics^ g) {
		if (y + (height / 4) * 1.0 <= (g->VisibleClipBounds.Height / 1.7) || y + height > g->VisibleClipBounds.Height) {
			dy *= -1;
			idx = 0;
		}
		y += dy;
		idx++;
		if (idx > 3) idx = 0;

	}
};