/**
* @file Move_Polygon2D.h
* @brief ˆÚ“®ƒ|ƒŠƒSƒ“ƒwƒbƒ_
* @author –îˆêr
* @date 2020/03/18
*/

#pragma once
#ifndef MOVE_POLYGON2D_H_
#define MOVE_POLYGON2D_H_

#include "Polygon2D.h"

class Move_Polygon2D : public Polygon2D
{
public:
	enum Move_Direction
	{
		UP,
		DOWN,
		RIGHT,
		LEFT
	};
	enum After_Move
	{
		STOP,
		DESTROY,

	};
protected:
	D3DXVECTOR2 m_vec;
	D3DXVECTOR2 m_terget_pos;
	After_Move m_after;
	float m_move_speed;
	bool m_is_after;
public:
	
	Move_Polygon2D(Object_Tag tag, int draw_priority, const char* file_name, int width, int height, const D3DXVECTOR2& from_pos, const D3DXVECTOR2& to_pos, float move_speed, After_Move after);
	Move_Polygon2D(Object_Tag tag, int draw_priority, const char* file_name, int tex_width, int tex_height, int draw_width, int draw_height,
		const D3DXVECTOR2& from_pos, const D3DXVECTOR2& to_pos, float move_speed, After_Move after);

	void Update(std::list<std::shared_ptr<Game_Object>>& objects);
};


#endif