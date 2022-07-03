#pragma once
#include "Enemigo.h"
#include "Bala.h"
#include "Controlador.h"
namespace TFGrupo6 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Nivel2
	/// </summary>
	public ref class Nivel2 : public System::Windows::Forms::Form
	{
	public:
		Nivel2(void)
		{
			InitializeComponent();
			
			srand(time(NULL));

			g = pnlCanvas2->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, pnlCanvas2->ClientRectangle);

			bmpMapa2 = gcnew Bitmap("City2.png");
			bmpEnemigo2 = gcnew Bitmap("enemigoSpray.png");
			bmpPersonaje2 = gcnew Bitmap("personaje2l.png");
			bmpBala2 = gcnew Bitmap("bala.png");
			bmpResiduo2 = gcnew Bitmap("lata1.png");
			

			personaje2 = new Personaje(20, 390, 8, 8, bmpPersonaje2->Width / 4, bmpPersonaje2->Height / 4, 0);
			enemigo2 = new Enemigo(700, 260, 10, 10, bmpEnemigo2->Width / 4, bmpEnemigo2->Height, 0);

			control2 = new Controlador();
			control2->crearResiduos(buffer->Graphics);
			
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Nivel2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer2;
	protected:

	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		// buffer elements
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;

		Bitmap^ bmpMapa2;
		Bitmap^ bmpPersonaje2;
		Bitmap^ bmpResiduo2;
		
		Bitmap^ bmpEnemigo2;
		Bitmap^ bmpBala2;

		Personaje* personaje2;
		Enemigo* enemigo2;
		Bala* bala;

	private: System::Windows::Forms::Panel^ pnlCanvas2;
	private: System::Windows::Forms::Label^ lblVidas;
	private: System::Windows::Forms::Label^ lblEscudo;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lvlVidas;
	private: System::Windows::Forms::Label^ lblResiduos;
	private: System::Windows::Forms::Label^ lblCtdResiduos;
	private: System::Windows::Forms::Timer^ timerBalas;
	private: System::Windows::Forms::Label^ lblGanador;
	private: System::Windows::Forms::Label^ lblPerdedor;

		   Controlador* control2;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pnlCanvas2 = (gcnew System::Windows::Forms::Panel());
			this->lblCtdResiduos = (gcnew System::Windows::Forms::Label());
			this->lblResiduos = (gcnew System::Windows::Forms::Label());
			this->lblVidas = (gcnew System::Windows::Forms::Label());
			this->lblEscudo = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lvlVidas = (gcnew System::Windows::Forms::Label());
			this->timerBalas = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblPerdedor = (gcnew System::Windows::Forms::Label());
			this->lblGanador = (gcnew System::Windows::Forms::Label());
			this->pnlCanvas2->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Tick += gcnew System::EventHandler(this, &Nivel2::timer2_Tick);
			// 
			// pnlCanvas2
			// 
			this->pnlCanvas2->Controls->Add(this->lblGanador);
			this->pnlCanvas2->Controls->Add(this->lblPerdedor);
			this->pnlCanvas2->Controls->Add(this->lblCtdResiduos);
			this->pnlCanvas2->Controls->Add(this->lblResiduos);
			this->pnlCanvas2->Controls->Add(this->lblVidas);
			this->pnlCanvas2->Controls->Add(this->lblEscudo);
			this->pnlCanvas2->Controls->Add(this->label1);
			this->pnlCanvas2->Controls->Add(this->lvlVidas);
			this->pnlCanvas2->Location = System::Drawing::Point(0, 0);
			this->pnlCanvas2->Name = L"pnlCanvas2";
			this->pnlCanvas2->Size = System::Drawing::Size(1282, 720);
			this->pnlCanvas2->TabIndex = 0;
			// 
			// lblCtdResiduos
			// 
			this->lblCtdResiduos->AutoSize = true;
			this->lblCtdResiduos->Location = System::Drawing::Point(1146, 22);
			this->lblCtdResiduos->Name = L"lblCtdResiduos";
			this->lblCtdResiduos->Size = System::Drawing::Size(13, 20);
			this->lblCtdResiduos->TabIndex = 5;
			this->lblCtdResiduos->Text = L".";
			// 
			// lblResiduos
			// 
			this->lblResiduos->AutoSize = true;
			this->lblResiduos->BackColor = System::Drawing::Color::MediumPurple;
			this->lblResiduos->Font = (gcnew System::Drawing::Font(L"Tahoma", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblResiduos->Location = System::Drawing::Point(1042, 22);
			this->lblResiduos->Name = L"lblResiduos";
			this->lblResiduos->Size = System::Drawing::Size(98, 22);
			this->lblResiduos->TabIndex = 4;
			this->lblResiduos->Text = L"Residuos:";
			// 
			// lblVidas
			// 
			this->lblVidas->AutoSize = true;
			this->lblVidas->Location = System::Drawing::Point(105, 57);
			this->lblVidas->Name = L"lblVidas";
			this->lblVidas->Size = System::Drawing::Size(13, 20);
			this->lblVidas->TabIndex = 3;
			this->lblVidas->Text = L".";
			// 
			// lblEscudo
			// 
			this->lblEscudo->AutoSize = true;
			this->lblEscudo->Location = System::Drawing::Point(110, 22);
			this->lblEscudo->Name = L"lblEscudo";
			this->lblEscudo->Size = System::Drawing::Size(13, 20);
			this->lblEscudo->TabIndex = 2;
			this->lblEscudo->Text = L".";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Thistle;
			this->label1->Font = (gcnew System::Drawing::Font(L"Tahoma", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(29, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(86, 22);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Escudo: ";
			// 
			// lvlVidas
			// 
			this->lvlVidas->AutoSize = true;
			this->lvlVidas->BackColor = System::Drawing::Color::Thistle;
			this->lvlVidas->Font = (gcnew System::Drawing::Font(L"Tahoma", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lvlVidas->Location = System::Drawing::Point(29, 55);
			this->lvlVidas->Name = L"lvlVidas";
			this->lvlVidas->Size = System::Drawing::Size(70, 22);
			this->lvlVidas->TabIndex = 0;
			this->lvlVidas->Text = L"Vidas: ";
			// 
			// timerBalas
			// 
			this->timerBalas->Enabled = true;
			this->timerBalas->Interval = 2700;
			this->timerBalas->Tick += gcnew System::EventHandler(this, &Nivel2::timerBalas_Tick);
			// 
			// lblPerdedor
			// 
			this->lblPerdedor->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->lblPerdedor->Font = (gcnew System::Drawing::Font(L"Stencil", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPerdedor->Location = System::Drawing::Point(365, 256);
			this->lblPerdedor->Name = L"lblPerdedor";
			this->lblPerdedor->Size = System::Drawing::Size(571, 139);
			this->lblPerdedor->TabIndex = 6;
			this->lblPerdedor->Text = L"GAME OVER";
			this->lblPerdedor->Visible = false;
			// 
			// lblGanador
			// 
			this->lblGanador->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->lblGanador->Font = (gcnew System::Drawing::Font(L"Stencil", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblGanador->Location = System::Drawing::Point(365, 244);
			this->lblGanador->Name = L"lblGanador";
			this->lblGanador->Size = System::Drawing::Size(571, 139);
			this->lblGanador->TabIndex = 7;
			this->lblGanador->Text = L"GANASTE";
			this->lblGanador->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblGanador->Visible = false;
			// 
			// Nivel2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1281, 720);
			this->Controls->Add(this->pnlCanvas2);
			this->Name = L"Nivel2";
			this->Text = L"Nivel2";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Nivel2::Nivel2_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Nivel2::Nivel2_KeyDown);
			this->pnlCanvas2->ResumeLayout(false);
			this->pnlCanvas2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
		
		buffer->Graphics->Clear(Color::WhiteSmoke);

		control2->colisionResiduo(personaje2);
		control2->colisionBala(personaje2);


		if (control2->getEscudo() < 0) {
			this->lblEscudo->Visible = false;
		}

		if (control2->getVidas() <=0){
			this->lblVidas->Visible = false;
			this->lblPerdedor->Visible = true;
			this->timer2->Enabled = false;
			this->timerBalas->Enabled = false;
			
		}
		if (control2->getContadorResiduos() == 13) {
			this->lblGanador->Visible = true;
			this->timer2->Enabled = false;
			this->timerBalas->Enabled = false;
		}

		buffer->Graphics->DrawImage(bmpMapa2, 0, 0, bmpMapa2->Width * 1.0, bmpMapa2->Height * 0.75);
		personaje2->dibujar(buffer->Graphics, bmpPersonaje2);

		control2->moverBalas();
		enemigo2->mover(buffer->Graphics);

		enemigo2->dibujar(buffer->Graphics, bmpEnemigo2);
		control2->dibujarTodo(buffer->Graphics, bmpResiduo2);
		control2->dibujarBalas(buffer->Graphics, bmpBala2);

		lblVidas->Text = Convert::ToString(control2->getVidas());
		lblEscudo->Text = Convert::ToString(control2->getEscudo());
		lblCtdResiduos->Text = Convert::ToString(control2->getContadorResiduos());
		buffer->Render(g);
		
	}

	private: System::Void Nivel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void Nivel2_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::A:
			personaje2->mover(buffer->Graphics, 'A');
			break;
		case Keys::D:
			personaje2->mover(buffer->Graphics, 'D');
			break;
		case Keys::W:
			personaje2->mover(buffer->Graphics, 'W');
			break;
		case Keys::S:
			personaje2->mover(buffer->Graphics, 'S');
			break;

		}
	}
private: System::Void timerBalas_Tick(System::Object^ sender, System::EventArgs^ e) {
	Bala* b = new Bala(enemigo2->getX(), enemigo2->getY()*1.3, bmpBala2->Width, bmpBala2->Height);
	control2->agregarBala(b);
}
};
}
