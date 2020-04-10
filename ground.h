/**
* @file ground.h
* @brief ínñ ÉwÉbÉ_
* @author ñÓêÅàÍèr
* @date 2020/03/18
*/

#pragma once
#ifndef GROUND_H_
#define GROUND_H_
#include "Polygon2D.h"

class Ground : public Polygon2D
{
public:
	static constexpr const float GROUND_SPEED = 3.0f;
	static constexpr const float HALF_TO_END = 1024.0f;
	static constexpr const float SCALE = 3.0f;
	enum Mode {
		NONE,
		START,
		HALF,
		END
	};
private:
	int m_cut_x;
	Mode m_mode;
public:
	Ground(Object_Tag tag, int draw_priority, const char* file_name, int tex_width, int tex_height, int draw_width, int draw_height, const D3DXVECTOR2& pos);
	void Update(std::list<std::shared_ptr<Game_Object>>& objects);
	void Draw(void);
};

#endif