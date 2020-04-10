/**
* @file Polygon2D.h
* @brief 2Dポリゴンオブジェクトヘッダ
* @author 矢吹一俊
* @date 2020/03/18
*/

#pragma once
#ifndef POLYGON_2D_H_
#define POLYGON_2D_H_
#include <d3dx9.h>
#include "Game_Object.h"

/**
* @class Polygon2D
* @brief ２Ｄポリゴンクラス
* @details
*/
class Polygon2D : public Game_Object
{
protected:
	D3DXVECTOR2 m_pos;
	int m_tex_id;
	int m_tex_width;
	int m_tex_height;
	int m_draw_width;
	int m_draw_height;
public:
	Polygon2D(Object_Tag tag, int draw_priority, const char* file_name, int width, int height, const D3DXVECTOR2& pos);
	Polygon2D(Object_Tag tag, int draw_priority, const char* file_name, int tex_width, int tex_height, int draw_width, int draw_height, const D3DXVECTOR2& pos);
	virtual ~Polygon2D(void);
	virtual void Update(std::list<std::shared_ptr<Game_Object>>& objects);
	virtual void Draw(void);
	const D3DXVECTOR2& Get_Position(void);
};

#endif