#include "MainForm.h"

using namespace Puzzle;

[STAThread]

int main()
{
	Application::EnableVisualStyles();
	Application::Run(gcnew MainForm());
	return 0;
}