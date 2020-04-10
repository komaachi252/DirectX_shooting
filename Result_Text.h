/**
* @file Result_Text.h
* @brief リザルトテキストヘッダ
* @author 矢吹一俊
* @date 2020/03/18
*/

#pragma once
#ifndef RESULT_TEXT_H_
#define RESULT_TEXT_H_
#include "Polygon2D.h"
#include "App.h"

/**
* @class Result_Text
* @brief リザルトテキストクラス
* @details
*/
class Result_Text : public Polygon2D
{
public:
	static constexpr const int TEX_RESULT_LOGO_WIDTH = 142;
	static constexpr const int TEX_RESULT_LOGO_HEIGHT = 30;
	static constexpr const float RESULT_LOGO_WIDTH = 284.0f;
	static constexpr const float RESULT_LOGO_HEIGHT = 60.0f;
	static constexpr const float RESULT_POS_X = App::SCREEN_WIDTH * 0.5f;
	static constexpr const float RESULT_POS_Y = -RESULT_LOGO_HEIGHT * 0.5f;
	static constexpr const float LOGO_END_POS = (App::SCREEN_HEIGHT * 0.1f);
	static constexpr const int NEXT_FRAME = 1080;
	static constexpr const int TEX_ENTER_WIDTH = 208;
	static constexpr const int TEX_ENTER_HEIGHT = 48;
	static constexpr const float ENTER_WIDTH = 208.0f;
	static constexpr const float ENTER_HEIGHT = 48.0f;
	static constexpr const float ENTER_POS_X = App::SCREEN_WIDTH * 0.5f;
	static constexpr const float ENTER_POS_Y = App::SCREEN_HEIGHT * 0.8f;
	static constexpr const float RESULT_SPEED = 5.0f;
	static constexpr const char* LOGO_FILE_NAME = "resultlogo.png";
	static constexpr const char* ENTER_FILE_NAME = "pressenter.png";

private:
	int m_angle;
	int m_enter_tex_id;
	D3DXVECTOR2 m_enter_pos;
public:
	Result_Text(Object_Tag tag, int draw_priority, const char* file_name, int tex_width, int tex_height, int draw_width, int draw_height, const D3DXVECTOR2& pos);
	~Result_Text(void);
	void Update(std::list<std::shared_ptr<Game_Object>>& objects);
	void Draw(void);
};

#endif