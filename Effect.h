/**
* @file Effect.h
* @brief エフェクトヘッダ
* @author 矢吹一俊
* @date 2020/03/18
*/

#pragma once
#ifndef EFFECT_H_
#define EFFECT_H_
#include <d3dx9.h>
#include "Polygon2D.h"

/**
* @class Effect
* @brief エフェクトクラス
* @details
*/
class Effect : public Polygon2D
{
public:
	static constexpr const char* FILE_NAME = "engine.png";
	static constexpr const int TEX_WIDTH = 80;
	static constexpr const int TEX_HEIGHT = 80;
	static constexpr const float DRAW_WIDTH = 80;
	static constexpr const float DRAW_HEIGHT = 80;
private:
	int m_life_frame;
	int m_elapsed_frame;
	D3DCOLOR m_color;
	float m_scale;
	float m_sub_scale;
public:
	Effect(Object_Tag tag, int draw_priority, const char* file_name, int width, int height, const D3DXVECTOR2& pos, D3DCOLOR color, int life_frame);
	Effect(Object_Tag tag, int draw_priority, const char* file_name, int tex_width, int tex_height, int draw_width, int draw_height, const D3DXVECTOR2& pos, D3DCOLOR color, int life_frame);
	virtual ~Effect(void);
	virtual void Update(std::list<std::shared_ptr<Game_Object>>& objects);
	virtual void Draw(void);
};

#endif
