#pragma once
#include "Controlador.h"
#include "Enemigo.h" //NO PERTENCE A NIVEL 1 (SOLO PRUEBA)
#include "Bala.h"
#include <string>
#include "Nivel2.h"
using namespace std;

namespace TFGrupo6 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	public ref class FrmMain : public System::Windows::Forms::Form
	{
	public:
		FrmMain(void)
		{
			InitializeComponent();
			
			srand(time(NULL));

			g = pnlCanvas->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, pnlCanvas->ClientRectangle);

			bmpPersonaje = gcnew Bitmap("personaje1.png");
			bmpMapa = gcnew Bitmap("City1.png");
			bmpResiduo = gcnew Bitmap("lata1.png");
			bmpAliado = gcnew Bitmap("aliado.png");
			//LEVEL 2
			bmpEnemigo = gcnew Bitmap("enemigoSpray.png");
			bmpBala = gcnew Bitmap("bala.png");
			bmpMapa2 = gcnew Bitmap("City2.png");

			personaje = new Personaje(30, 400, 10, 10, bmpPersonaje->Width / 4, bmpPersonaje->Height / 4, 0);
			aliado = new Aliado(personaje->getY(), bmpAliado->Width / 10, bmpAliado->Height / 1);
			control = new Controlador();
			//lvl 2
			enemigo = new Enemigo(700, 260, 10, 10, bmpEnemigo->Width/4, bmpEnemigo->Height, 0);
			//bala = new Bala(700, 260, bmpBala->Width / 2, bmpBala->Height);
			control->crearResiduos(buffer->Graphics);
			//probar
			
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FrmMain()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Panel^ pnlCanvas;

	protected:
	private: System::ComponentModel::IContainer^ components;

	private:

		// ** buffer elements **
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;

		Bitmap^ bmpMapa;
		Bitmap^ bmpPersonaje;
		Bitmap^ bmpResiduo;
		Bitmap^ bmpAliado;
		Bitmap^ bmpEnemigo;
		Bitmap^ bmpBala;

		Aliado* aliado;
		Enemigo* enemigo;//levl 2
		//Bala* bala;//level 2

		Bitmap^ bmpMapa2;

		Personaje* personaje;
		Controlador* control;
		
		
	private: System::Windows::Forms::Label^ lblContador;
	private: System::Windows::Forms::Label^ lblTexto;




#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pnlCanvas = (gcnew System::Windows::Forms::Panel());
			this->lblTexto = (gcnew System::Windows::Forms::Label());
			this->lblContador = (gcnew System::Windows::Forms::Label());
			this->pnlCanvas->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FrmMain::timer1_Tick);
			// 
			// pnlCanvas
			// 
			this->pnlCanvas->Controls->Add(this->lblTexto);
			this->pnlCanvas->Controls->Add(this->lblContador);
			this->pnlCanvas->Location = System::Drawing::Point(1, -1);
			this->pnlCanvas->Name = L"pnlCanvas";
			this->pnlCanvas->Size = System::Drawing::Size(1280, 720);
			this->pnlCanvas->TabIndex = 0;
			// 
			// lblTexto
			// 
			this->lblTexto->AutoSize = true;
			this->lblTexto->BackColor = System::Drawing::Color::Turquoise;
			this->lblTexto->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTexto->Location = System::Drawing::Point(1056, 26);
			this->lblTexto->Name = L"lblTexto";
			this->lblTexto->Size = System::Drawing::Size(99, 21);
			this->lblTexto->TabIndex = 2;
			this->lblTexto->Text = L"Residuos:";
			// 
			// lblContador
			// 
			this->lblContador->AutoSize = true;
			this->lblContador->BackColor = System::Drawing::Color::Aquamarine;
			this->lblContador->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblContador->ForeColor = System::Drawing::Color::Red;
			this->lblContador->Location = System::Drawing::Point(1161, 21);
			this->lblContador->Name = L"lblContador";
			this->lblContador->Size = System::Drawing::Size(103, 25);
			this->lblContador->TabIndex = 1;
			this->lblContador->Text = L"Residuos: ";
			// 
			// FrmMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1281, 720);
			this->Controls->Add(this->pnlCanvas);
			this->Name = L"FrmMain";
			this->Text = L"Juego";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmMain::FrmMain_KeyDown);
			this->pnlCanvas->ResumeLayout(false);
			this->pnlCanvas->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//clear
		buffer->Graphics->Clear(Color::WhiteSmoke);
		//collision
		control->colisionResiduo(personaje);
		//move 
		//LEVEL 2
		enemigo->mover(buffer->Graphics);
		/*bala->mover();*/
		//control->moverTodo(buffer->Graphics);
		control->finalizaNivel1(buffer->Graphics,aliado,personaje);
		//draw
		buffer->Graphics->DrawImage(bmpMapa, 0, 0, bmpMapa->Width * 1.0, bmpMapa->Height * 0.75);

		personaje->dibujar(buffer->Graphics, bmpPersonaje);
		//LEVEL 2
		enemigo->dibujar(buffer->Graphics, bmpEnemigo);
		/*bala->dibujar(buffer->Graphics, bmpBala);*/

		if (control->getctdResiduos() == 0) {
			//->dibujar(buffer->Graphics, bmpAliado);
			Nivel2^ nivel2 = gcnew Nivel2();
			nivel2->Show();
			this->timer1->Enabled = false;
			
		}

		control->dibujarTodo(buffer->Graphics, bmpResiduo);

		lblContador->Text = Convert::ToString(control->getContadorResiduos());

		//render
		buffer->Render(g);
	}

	private: System::Void FrmMain_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		
		switch (e->KeyCode)
		{
		case Keys::A:
			personaje->mover(buffer->Graphics, 'A');
			break;
		case Keys::D:
			personaje->mover(buffer->Graphics, 'D');
			break;
		case Keys::W:
			personaje->mover(buffer->Graphics, 'W');
			break;
		case Keys::S:
			personaje->mover(buffer->Graphics, 'S');
			break;
		/*case Keys::Enter:
			Bala* bala = new Bala(700, 260, bmpBala->Width / 2, bmpBala->Height);
			break;*/
		}
	}
};
}
