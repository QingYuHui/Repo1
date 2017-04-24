#include "MainForm.h"

using namespace FileManager;

[STAThread]

int main()
{
	Application::EnableVisualStyles();
	Application::Run(gcnew MainForm());
	return 0;
}