/**
* @file Bullet.h
* @brief 弾ヘッダ
* @author 矢吹一俊
* @date 2020/03/18
*/

#pragma once
#ifndef BULLET_H_
#define BULLET_H_

#include "Move_Polygon2D.h"
#include "Circle_Collision.h"

class Bullet : public Move_Polygon2D
{
protected:
	//!  当たり判定用クラス
	Circle_Collsion* m_circle_colli;
public:
	Bullet(Object_Tag tag, int draw_priority, const char* file_name, int width, int height, const D3DXVECTOR2& from_pos, const D3DXVECTOR2& to_pos, float move_speed, After_Move after);
	Bullet(Object_Tag tag, int draw_priority, const char* file_name, int tex_width, int tex_height, int draw_width, int draw_height,
		const D3DXVECTOR2& from_pos, const D3DXVECTOR2& to_pos, float move_speed, After_Move after);
	~Bullet(void);
	void Update(std::list<std::shared_ptr<Game_Object>>& objects);
	const Circle_Collsion& Get_Collision(void);
};

#endif