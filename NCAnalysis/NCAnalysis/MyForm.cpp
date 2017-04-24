#include "MyForm.h"

using namespace NCAnalysis;

[STAThread]

int main()
{
	Application::EnableVisualStyles();
	Application::Run(gcnew MyForm());
	return 0;
}