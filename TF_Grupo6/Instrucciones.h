#pragma once

namespace TFGrupo6 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Instrucciones
	/// </summary>
	public ref class Instrucciones : public System::Windows::Forms::Form
	{
	public:
		Instrucciones(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//

			g = pnlInstrucciones->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, pnlInstrucciones->ClientRectangle);

			bmpInstrucciones = gcnew Bitmap("fondoInstrucciones.png");
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Instrucciones()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ pnlInstrucciones;
	protected:

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
	 
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;

		Bitmap^ bmpInstrucciones;
	private: System::Windows::Forms::Timer^ timerIns;
	private: System::ComponentModel::IContainer^ components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pnlInstrucciones = (gcnew System::Windows::Forms::Panel());
			this->timerIns = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// pnlInstrucciones
			// 
			this->pnlInstrucciones->Location = System::Drawing::Point(0, 0);
			this->pnlInstrucciones->Name = L"pnlInstrucciones";
			this->pnlInstrucciones->Size = System::Drawing::Size(1149, 665);
			this->pnlInstrucciones->TabIndex = 0;
			// 
			// timerIns
			// 
			this->timerIns->Enabled = true;
			this->timerIns->Tick += gcnew System::EventHandler(this, &Instrucciones::timerIns_Tick);
			// 
			// Instrucciones
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1148, 664);
			this->Controls->Add(this->pnlInstrucciones);
			this->Name = L"Instrucciones";
			this->Text = L"Instrucciones";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timerIns_Tick(System::Object^ sender, System::EventArgs^ e) {
		buffer->Graphics->DrawImage(bmpInstrucciones, 0, 0, bmpInstrucciones->Width * 0.51, bmpInstrucciones->Height * 0.4);

		buffer->Render(g);
	}
	};
}
