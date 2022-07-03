#pragma once
#include "Sujeto.h"
#include "Personaje.h"
#include "Residuo.h"
#include "Aliado.h"
#include "Bala.h"
#include <vector>

using namespace std;

class Controlador {
private:
	
	int ctdResiduos;
	int ctdBalas;
	int contResiduos;
	vector<Residuo*> residuos;
	vector<Bala*> balas;
	int vidas;
	int escudo;

public:

	Controlador(){
		ctdResiduos = 13;
		ctdBalas = 10;
		contResiduos = 0;
		vidas = 3;
		escudo = 6;
		
		for (int i = 0; i < ctdBalas; i++){
			Bala* b = new Bala(1, 1, 1, 1);
			balas.push_back(b);
		}
	}
	~Controlador(){}

	
	void agregarBala(Bala* bala) {
		balas.push_back(bala);
	}

	void crearResiduos(Graphics^ g){

		Bitmap^ bmpResiduo;

		int random;
		int tipo;
		for (int i = 0; i < ctdResiduos; i++)
		{
			random = rand() % 200;
			
			if (random % 3 == 0) {
				bmpResiduo = gcnew Bitmap("lata1.png");
				tipo = 1;
			}
			else if (random % 2 == 0) {
				bmpResiduo = gcnew Bitmap("botella1.png");
				tipo = 2;
			}
			else if (random % 8 == 0) {
				bmpResiduo = gcnew Bitmap("caja1.png");
				tipo = 3;
			}
			else {
				bmpResiduo = gcnew Bitmap("mascarilla1.png");
				tipo = 4;
			}

			Residuo* r;
			r = new Residuo(70 + rand() % 600, 300 + rand() % 135, bmpResiduo->Width, bmpResiduo->Height, tipo);
			residuos.push_back(r);

			_sleep(10);
		}
			
	}

	void moverBalas() {
		for (int i = 0; i < balas.size(); i++){
			balas[i]->mover();
		}
	}

	void dibujarTodo(Graphics^g, Bitmap^ bmpResiduo) {
		
		for (int i = 0; i < residuos.size(); i++){
			
			switch (residuos[i]->getTipo())
			{case 1:
				bmpResiduo = gcnew Bitmap("lata1.png");
				break;
			case 2:
				bmpResiduo = gcnew Bitmap("botella1.png");
				break;
			case 3:
				bmpResiduo = gcnew Bitmap("caja1.png");
				break;
			case 4:
				bmpResiduo = gcnew Bitmap("mascarilla1.png");
				break;
			}

			residuos[i]->dibujar(g,bmpResiduo);
		}
	}
	void dibujarBalas(Graphics^ g, Bitmap^ bmpBala) {
		for (int i = 0; i < balas.size(); i++){
			if (balas[i]->getX() > 10) {
				balas[i]->dibujar(g, bmpBala);
			}
		}
	}

	void colisionResiduo(Personaje* heroe) {
		if (residuos.size() >= 1)
		{
			for (int i = 0; i < residuos.size(); i++)
			{
				if (residuos[i]->getRectangle().IntersectsWith(heroe->getRectangle())) {
					residuos[i]->setVisible(false);
				}
			}
		}
		else{
			ctdResiduos = 0;
		}

		for (int i = 0; i < residuos.size(); i++){
			if (residuos[i]->getVisible()==false){
				residuos.erase(residuos.begin() + i);
				contResiduos++;
				ctdResiduos--;
			}
		}
	}
	
	void colisionBala(Personaje* personaje){
		for (int i = 0; i < balas.size(); i++){
			if (balas[i]->getX() <= 0) {
				balas[i]->setVisible(false);
			}
		}
		for (int i = 0; i < balas.size(); i++){
			if(personaje->getRectangle().IntersectsWith(balas[i]->getRectangle())) {
				balas[i]->setVisible(false);
				escudo--;
				if (escudo <= 0) vidas--;
			}
		}
		for (int i = 0; i < balas.size(); i++) {

			if (balas[i]->getVisible()==false) {
				balas.erase(balas.begin() + i);
			}
		}
	}

	void aparicionAliado(Graphics^g, Aliado* aliado, Personaje* personaje) {
		if (ctdResiduos == 0) {
			aliado->mover(g, personaje->getX());
		}
	}

	int getEscudo() { return escudo; }
	int getVidas() { return vidas; }
	int getctdResiduos() { return ctdResiduos; }
	int getContadorResiduos() { return contResiduos; }
};