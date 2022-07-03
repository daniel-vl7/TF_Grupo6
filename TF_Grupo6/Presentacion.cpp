#include "Presentacion.h"
using namespace TFGrupo6;
using namespace System::Windows::Forms;

int main() {
	Application::EnableVisualStyles();
	Application::Run(gcnew Presentacion());

	return 0;
}
