/**
* @file Polygon2D.h
* @brief 2Dポリゴンオブジェクトヘッダ
* @author 矢吹一俊
* @date 2020/03/18
*/

#pragma once
#ifndef TITLE_PLAYER_H_
#define TITLE_PLAYER_H_

#include "Move_Polygon2D.h"

class Title_Player : public Move_Polygon2D
{
private:
	int m_count;
	int m_period;
	float m_amplitude;
public:
	Title_Player(Object_Tag tag, int draw_priority, const char* file_name, int tex_width, int tex_height, int draw_width, int draw_height,
		const D3DXVECTOR2& from_pos, const D3DXVECTOR2& to_pos, float move_speed, After_Move after_move);
	void Update(std::list<std::shared_ptr<Game_Object>>& objects);
	void Draw(void);
};



#endif