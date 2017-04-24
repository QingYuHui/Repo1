#include "MyForm.h"

using namespace CADConvert;

[STAThread]

int main()
{
	Application::EnableVisualStyles();
	Application::Run(gcnew MyForm());
	return 0;
}