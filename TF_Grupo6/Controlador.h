#pragma once
#include "Sujeto.h"
#include "Personaje.h"
#include "Agente.h"
#include "Residuo.h"
#include "Aliado.h"
#include <vector>

using namespace std;

class Controlador {
private:
	
	int ctdResiduos;
	vector<Residuo*> residuos;
	int contResiduos;

public:

	Controlador(){
		ctdResiduos = 10;
		contResiduos = 0;
		
	}
	~Controlador(){}

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
			r = new Residuo(50 + rand() % 600, 300 + rand() % 135, bmpResiduo->Width, bmpResiduo->Height, tipo);
			residuos.push_back(r);

			_sleep(10);
		}
			
	}

	void dibujarTodo(Graphics^g, Bitmap^ bmpResiduo) {
		//bmpResiduo por defecto = "lata1.png"
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


	//instanciar en main? 

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
	
	void finalizaNivel1(Graphics^g, Aliado* aliado, Personaje* heroe) {
		if (ctdResiduos == 0) {
			aliado->mover(g, heroe->getX());
		}
	}

	int getctdResiduos() { return ctdResiduos; }
	int getContadorResiduos() { return contResiduos; }
};