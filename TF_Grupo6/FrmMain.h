#pragma once
#include "Controlador.h"
#include "Nivel2.h"
#include <string>
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

			personaje = new Personaje(30, 400, 7, 7, bmpPersonaje->Width / 4, bmpPersonaje->Height / 4, 0);
			aliado = new Aliado(personaje->getY(), bmpAliado->Width / 10, bmpAliado->Height / 1);
			control = new Controlador();
			
			//lvl 2
			nivel2 = gcnew Nivel2();
			
			control->crearResiduos(buffer->Graphics);
	
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

		Aliado* aliado;
	
		Personaje* personaje;
		Controlador* control;
		
		Nivel2^ nivel2;
		
	private: System::Windows::Forms::Label^ lblContador;
	private: System::Windows::Forms::Button^ btnContinuar;
	private: System::Windows::Forms::Label^ lblIndicacion;
	private: System::Windows::Forms::Label^ lblArmadura;


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
			this->lblArmadura = (gcnew System::Windows::Forms::Label());
			this->lblIndicacion = (gcnew System::Windows::Forms::Label());
			this->btnContinuar = (gcnew System::Windows::Forms::Button());
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
			this->pnlCanvas->Controls->Add(this->lblArmadura);
			this->pnlCanvas->Controls->Add(this->lblIndicacion);
			this->pnlCanvas->Controls->Add(this->btnContinuar);
			this->pnlCanvas->Controls->Add(this->lblTexto);
			this->pnlCanvas->Controls->Add(this->lblContador);
			this->pnlCanvas->Location = System::Drawing::Point(1, -1);
			this->pnlCanvas->Name = L"pnlCanvas";
			this->pnlCanvas->Size = System::Drawing::Size(1280, 720);
			this->pnlCanvas->TabIndex = 0;
			// 
			// lblArmadura
			// 
			this->lblArmadura->AutoSize = true;
			this->lblArmadura->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->lblArmadura->Font = (gcnew System::Drawing::Font(L"Tahoma", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblArmadura->Location = System::Drawing::Point(709, 668);
			this->lblArmadura->Name = L"lblArmadura";
			this->lblArmadura->Size = System::Drawing::Size(326, 22);
			this->lblArmadura->TabIndex = 5;
			this->lblArmadura->Text = L"El aliado ha entregado la armadura";
			this->lblArmadura->Visible = false;
			// 
			// lblIndicacion
			// 
			this->lblIndicacion->AutoSize = true;
			this->lblIndicacion->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->lblIndicacion->Font = (gcnew System::Drawing::Font(L"Tahoma", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblIndicacion->Location = System::Drawing::Point(1065, 588);
			this->lblIndicacion->Name = L"lblIndicacion";
			this->lblIndicacion->Size = System::Drawing::Size(117, 19);
			this->lblIndicacion->TabIndex = 4;
			this->lblIndicacion->Text = L"Espera aquí ↓";
			this->lblIndicacion->Visible = false;
			// 
			// btnContinuar
			// 
			this->btnContinuar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->btnContinuar->Font = (gcnew System::Drawing::Font(L"Montserrat", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnContinuar->Location = System::Drawing::Point(391, 338);
			this->btnContinuar->Name = L"btnContinuar";
			this->btnContinuar->Size = System::Drawing::Size(486, 209);
			this->btnContinuar->TabIndex = 3;
			this->btnContinuar->Text = L"Continuar";
			this->btnContinuar->UseVisualStyleBackColor = false;
			this->btnContinuar->Visible = false;
			this->btnContinuar->Click += gcnew System::EventHandler(this, &FrmMain::btnContinuar_Click);
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
		
		buffer->Graphics->Clear(Color::WhiteSmoke);
		//collision
		control->colisionResiduo(personaje);
		//move 
		
		control->aparicionAliado(buffer->Graphics,aliado,personaje);
		//draw
		buffer->Graphics->DrawImage(bmpMapa, 0, 0, bmpMapa->Width * 1.0, bmpMapa->Height * 0.75);

		personaje->dibujar(buffer->Graphics, bmpPersonaje);
		
		

		if (control->getctdResiduos() == 0) {
			aliado->dibujar(buffer->Graphics, bmpAliado);	
			lblIndicacion->Visible = true;
		}

		if (aliado->getX() >=700) {
			btnContinuar->Visible = true;	
			lblArmadura->Visible = true;
		}

		control->dibujarTodo(buffer->Graphics, bmpResiduo);
		lblContador->Text = Convert::ToString(control->getContadorResiduos());
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
		
		}
	}
	
	private: System::Void btnContinuar_Click(System::Object^ sender, System::EventArgs^ e) {
		
		nivel2->Show();	
	}
};
}
