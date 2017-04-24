#include "MainForm.h"

using namespace Sort;

[STAThread]

int main()
{
	Application::EnableVisualStyles();
	Application::Run(gcnew MainForm());
	return 0;
}