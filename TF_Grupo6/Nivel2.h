#pragma once
#include "Enemigo.h"
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
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Panel^ pnlCanvas2;

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
	private: System::Windows::Forms::Label^ label1;
		   Enemigo* enemigo2;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pnlCanvas2 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pnlCanvas2->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			// 
			// pnlCanvas2
			// 
			this->pnlCanvas2->Controls->Add(this->label1);
			this->pnlCanvas2->Location = System::Drawing::Point(0, 0);
			this->pnlCanvas2->Name = L"pnlCanvas2";
			this->pnlCanvas2->Size = System::Drawing::Size(1280, 720);
			this->pnlCanvas2->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(278, 111);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(59, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"prueba";
			// 
			// Nivel2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1281, 720);
			this->Controls->Add(this->pnlCanvas2);
			this->Name = L"Nivel2";
			this->Text = L"Nivel2";
			this->pnlCanvas2->ResumeLayout(false);
			this->pnlCanvas2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
		buffer->Graphics->Clear(Color::WhiteSmoke);
		buffer->Graphics->DrawImage(bmpMapa2, 0, 0, bmpMapa2->Width * 1.0, bmpMapa2->Height * 0.75);
		buffer->Render(g);
	}
	};
}
