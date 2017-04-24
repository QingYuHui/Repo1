#include "MainForm.h"

using namespace SpeedControl;

[STAThread]

int main()
{
	Application::EnableVisualStyles();
	Application::Run(gcnew MainForm());
	return 0;
}