/**
* @file App.h
* @brief アプリヘッダ
* @author 矢吹一俊
* @date 2020/03/18
*/

#pragma once
#ifndef APP_H_
#define APP_H_
#include <Windows.h>

/**
* @class App
* @brief アプリ処理クラス
* @details
*/
class App
{
private:
	static constexpr const char* CLASS_NAME = "GameWindow";
	static constexpr const char* WINDOW_CAPTION = "SPACE_DAWN";
	static constexpr const DWORD WINDOW_STYLE = WS_OVERLAPPEDWINDOW ^ (WS_THICKFRAME | WS_MAXIMIZEBOX);
	static LRESULT CALLBACK Wnd_Proc(HWND wnd, UINT msg, WPARAM w_param, LPARAM l_param);
	HWND m_hwnd;
	HINSTANCE m_instance;
public:
	static constexpr const int SCREEN_WIDTH = 1280;
	static constexpr const int SCREEN_HEIGHT = 720;
	App(HINSTANCE instance);
	/**
	* @fn Run(int cmd_show)
	* @brief アプリ実行処理
	* @return ウィンドウメッセージ
	*/
	int Run(int cmd_show);
};

#endif