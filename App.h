/**
* @file App.h
* @brief �A�v���w�b�_
* @author ���r
* @date 2020/03/18
*/

#pragma once
#ifndef APP_H_
#define APP_H_
#include <Windows.h>

/**
* @class App
* @brief �A�v�������N���X
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
	* @brief �A�v�����s����
	* @return �E�B���h�E���b�Z�[�W
	*/
	int Run(int cmd_show);
};

#endif