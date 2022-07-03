#pragma once

namespace TFGrupo6 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Creditos
	/// </summary>
	public ref class Creditos : public System::Windows::Forms::Form
	{
	public:
		Creditos(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			g = pnlCred->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, pnlCred->ClientRectangle);

			bmpCreditos = gcnew Bitmap("fondoCreditos.png");
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Creditos()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ pnlCred;
	protected:

	private: System::Windows::Forms::Timer^ timerCred;
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;

		Bitmap^ bmpCreditos;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pnlCred = (gcnew System::Windows::Forms::Panel());
			this->timerCred = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// pnlCred
			// 
			this->pnlCred->Location = System::Drawing::Point(0, 0);
			this->pnlCred->Name = L"pnlCred";
			this->pnlCred->Size = System::Drawing::Size(1259, 665);
			this->pnlCred->TabIndex = 0;
			// 
			// timerCred
			// 
			this->timerCred->Enabled = true;
			this->timerCred->Tick += gcnew System::EventHandler(this, &Creditos::timerCred_Tick);
			// 
			// Creditos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1259, 664);
			this->Controls->Add(this->pnlCred);
			this->Name = L"Creditos";
			this->Text = L"Creditos";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timerCred_Tick(System::Object^ sender, System::EventArgs^ e) {
		buffer->Graphics->DrawImage(bmpCreditos, 0, 0, bmpCreditos->Width * 0.46, bmpCreditos->Height * 0.47);

		buffer->Render(g);
	}
	};
}
