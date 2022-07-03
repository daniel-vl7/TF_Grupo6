#pragma once
#include "FrmMain.h"
#include "Instrucciones.h"
#include "Creditos.h"
namespace TFGrupo6 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Presentacion
	/// </summary>
	public ref class Presentacion : public System::Windows::Forms::Form
	{
	public:
		Presentacion(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			g = pnlMenu->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, pnlMenu->ClientRectangle);

			bmpFondo = gcnew Bitmap("fondoMenu.png");
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Presentacion()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ pnlMenu;
	protected:
	private: System::Windows::Forms::Timer^ timerMenu;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		
		//buffer elements
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;
		
		Bitmap^ bmpFondo;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pnlMenu = (gcnew System::Windows::Forms::Panel());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timerMenu = (gcnew System::Windows::Forms::Timer(this->components));
			this->pnlMenu->SuspendLayout();
			this->SuspendLayout();
			// 
			// pnlMenu
			// 
			this->pnlMenu->Controls->Add(this->button4);
			this->pnlMenu->Controls->Add(this->button3);
			this->pnlMenu->Controls->Add(this->button2);
			this->pnlMenu->Controls->Add(this->button1);
			this->pnlMenu->Location = System::Drawing::Point(0, 0);
			this->pnlMenu->Name = L"pnlMenu";
			this->pnlMenu->Size = System::Drawing::Size(1280, 719);
			this->pnlMenu->TabIndex = 0;
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::Gainsboro;
			this->button4->Font = (gcnew System::Drawing::Font(L"Stencil", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(892, 286);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(302, 132);
			this->button4->TabIndex = 3;
			this->button4->Text = L"CREDITOS";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &Presentacion::button4_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::RosyBrown;
			this->button3->Font = (gcnew System::Drawing::Font(L"Stencil", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(502, 366);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(231, 52);
			this->button3->TabIndex = 2;
			this->button3->Text = L"NIVEL 2";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Presentacion::button3_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::PaleTurquoise;
			this->button2->Font = (gcnew System::Drawing::Font(L"Stencil", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(502, 286);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(231, 52);
			this->button2->TabIndex = 1;
			this->button2->Text = L"NIVEL 1";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Presentacion::button2_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Gainsboro;
			this->button1->Font = (gcnew System::Drawing::Font(L"Stencil", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(45, 276);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(302, 132);
			this->button1->TabIndex = 0;
			this->button1->Text = L"INSTRUCCIONES";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Presentacion::button1_Click);
			// 
			// timerMenu
			// 
			this->timerMenu->Enabled = true;
			this->timerMenu->Tick += gcnew System::EventHandler(this, &Presentacion::timerMenu_Tick);
			// 
			// Presentacion
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1281, 720);
			this->Controls->Add(this->pnlMenu);
			this->Name = L"Presentacion";
			this->Text = L"Presentacion";
			this->pnlMenu->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timerMenu_Tick(System::Object^ sender, System::EventArgs^ e) {
		buffer->Graphics->DrawImage(bmpFondo, 0, 0, bmpFondo->Width * 0.45, bmpFondo->Height * 0.43);

		buffer->Render(g);
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		//inicia NIVEL 1
		FrmMain^ nivel1 = gcnew FrmMain();
		nivel1->Show();
		
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		//inicia NIVEL 2
		Nivel2^ nivel2 = gcnew Nivel2();
		nivel2->Show();

	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		//INSTRUCCIONES
		Instrucciones^ instruccion = gcnew Instrucciones();
		instruccion->Show();
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		//CREDITOS
		Creditos^ cred = gcnew Creditos();
		cred->Show();
	}
};
}
