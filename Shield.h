/**
* @file Sield.h
* @brief シールドヘッダ
* @author 矢吹一俊
* @date 2020/03/18
*/
#pragma once
#ifndef SHIELD_H_
#define SHIELD_H_
#include "Polygon2D.h"
#include "Circle_Collision.h"

class Shield : Polygon2D
{
private:
	static constexpr const float POS_X_DISTANCE = 80.0f;
	Circle_Collsion* m_circle_collision;
public:
	Shield(Object_Tag tag, int draw_priority, const char* file_name, int width, int height, const D3DXVECTOR2& pos);
	~Shield(void);
	void Update(std::list<std::shared_ptr<Game_Object>>& objects);
};

#endif