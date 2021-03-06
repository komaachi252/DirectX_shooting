/**
* @file main.cpp
* @brief 主処理
* @author 矢吹一俊
* @date 2020/03/18
*/

#include "App.h"

int APIENTRY WinMain(HINSTANCE instance, HINSTANCE prev_instance, LPSTR cmd_line, int cmd_show)
{
	//!  使用しない
	UNREFERENCED_PARAMETER(prev_instance);
	UNREFERENCED_PARAMETER(cmd_line);

	App *app = new App(instance);
	int param = app->Run(cmd_show);

	delete app;
	return param;
}