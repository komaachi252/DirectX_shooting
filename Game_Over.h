/**
* @file Game_Over.h
* @brief ゲームオーバーヘッダ
* @author 矢吹一俊
* @date 2020/03/18
*/

#pragma once
#ifndef GAME_OVER_H_
#define GAME_OVER_H_
#include "Polygon2D.h"
#include "App.h"

/**
* @class Game_Over
* @brief ゲームオーバークラス
* @details
*/
class Game_Over : public Polygon2D
{
public:
	static constexpr const int TEX_GAME_OVER_WIDTH = 190;
	static constexpr const int TEX_GAME_OVER_HEIGHT = 30;
	static constexpr const int GAME_OVER_WIDTH = 190.0f;
	static constexpr const int GAME_OVER_HEIGHT = 30.0f;
	static constexpr const float GAME_OVER_POS_X = App::SCREEN_WIDTH * 0.5f;
	static constexpr const float GAME_OVER_POS_Y = 615.0f;
	static constexpr const int NEXT_SCENE_FRAME = 180;
	static constexpr const float BULLET_SPEED = 15.0f;
	static constexpr const char* FILE_NAME = "gameover.png";
private:
	int m_frame;
public:
	Game_Over(Object_Tag tag, int draw_priority, const char* file_name, int width, int height, const D3DXVECTOR2& pos);
	void Update(std::list<std::shared_ptr<Game_Object>>& objects);
};

#endif