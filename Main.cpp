/**
* @file main.cpp
* @brief Žåˆ—
* @author –îˆêr
* @date 2020/03/18
*/

#include "App.h"

int APIENTRY WinMain(HINSTANCE instance, HINSTANCE prev_instance, LPSTR cmd_line, int cmd_show)
{
	//!  Žg—p‚µ‚È‚¢
	UNREFERENCED_PARAMETER(prev_instance);
	UNREFERENCED_PARAMETER(cmd_line);

	App *app = new App(instance);
	int param = app->Run(cmd_show);

	delete app;
	return param;
}