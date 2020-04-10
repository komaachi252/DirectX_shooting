/**
* @file Debug_Font_Manager.h
* @brief デバッグログ表示ヘッダ
* @author 矢吹一俊
* @date 2020/03/18
*/

#pragma once
#ifndef DEBUG_FONT_MANAGER_H_
#define DEBUG_FONT_MANAGER_H_
#include <d3dx9.h>

/**
* @class Debug_Font_Manager
* @brief デバッグログ表示クラス
*/
class Debug_Font_Manager
{
private:
	static constexpr const int DEBUG_PRINTF_BUFFER_MAX = 256;
	LPD3DXFONT m_d3dx_font;
public:
	Debug_Font_Manager(void);
	~Debug_Font_Manager(void);
	void Draw(int x, int y, const char* pFormat, ...);
};

#endif