/**
* @file Anim_Polygon2D.h
* @brief アニメ2Dポリゴンオブジェクトヘッダ
* @author 矢吹一俊
* @date 2020/03/18
*/

#pragma once
#ifndef ANIM_POLYGON_2D_H_
#define ANIM_POLYGON_2D_H_
#include <d3dx9.h>
#include "Polygon2D.h"

/**
* @class Anim_Polygon2D
* @brief アニメ２Ｄポリゴンクラス
* @details
*/
class Anim_Polygon2D : public Polygon2D
{
protected:
	int m_frame;
	int m_width_num;
	int m_height_num;
	bool m_is_loop;
	int m_frame_divide;
public:
	Anim_Polygon2D(Object_Tag tag, int draw_priority, const char* file_name, int tex_width, int tex_height, int draw_width, int draw_height, const D3DXVECTOR2& pos,
		int width_num, int height_num, bool is_loop, int frame_divide);
	virtual ~Anim_Polygon2D(void);
	virtual void Update(std::list<std::shared_ptr<Game_Object>>& objects);
	virtual void Draw(void);
};

#endif