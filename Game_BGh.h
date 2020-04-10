/**
* @file Game_BG.h
* @brief ƒQ[ƒ€”wŒiƒwƒbƒ_
* @author –îˆêr
* @date 2020/03/18
*/

#pragma once
#ifndef GAME_BG_H_
#define GAME_BG_H_
#include "Polygon2D.h"

/**
* @class Game_BG
* @brief ƒQ[ƒ€”wŒiƒNƒ‰ƒX
* @details
*/
class Game_BG : public Polygon2D
{
private:
	float m_u;
	float m_v;
	float m_move_speed;
public:
	Game_BG(Object_Tag tag, int draw_priority, const char* file_name, int width, int height, const D3DXVECTOR2& pos, float move_speed);
	~Game_BG(void);
	void Update(std::list<std::shared_ptr<Game_Object>>& objects);
	void Draw(void);
	void Set_Dir_Y(float dir_y);
};

#endif