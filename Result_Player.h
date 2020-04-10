/**
* @file Result_Player.h
* @brief リザルトプレイヤーヘッダ
* @author 矢吹一俊
* @date 2020/03/18
*/

#pragma once
#ifndef RESULT_PLAYER_H_
#define RESULT_PLAYER_H_
#include "Polygon2D.h"
#include "App.h"

/**
* @class Result_Player
* @brief リザルトプレイヤークラス
* @details
*/
class Result_Player : public Polygon2D
{
public:
	static constexpr const int TEX_PLAYER_WIDTH = 256;
	static constexpr const int TEX_PLAYER_HEIGHT = 128;
	static constexpr const float PLAYER_WIDTH = 192.0f;
	static constexpr const float PLAYER_HEIGHT = 96.0f;
	static constexpr const float PLAYER_SPEED = 4.0f;
	static constexpr const float END_POS_X = 1000.0f;
	static constexpr const float END_POS_Y = App::SCREEN_HEIGHT * 0.5f;
private:
	int m_angle;
public:
	Result_Player(Object_Tag tag, int draw_priority, const char* file_name, int tex_width, int tex_height, int draw_width, int draw_height, const D3DXVECTOR2& pos);
	~Result_Player(void);
	void Update(std::list<std::shared_ptr<Game_Object>>& objects);
	void Draw(void);
};

#endif