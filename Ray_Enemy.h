/**
* @file Ray_Enemy.h
* @brief レイヘッダ
* @author 矢吹一俊
* @date 2020/03/18
*/

#pragma once
#ifndef RAY_ENEMY_H_
#define RAY_ENEMY_H_
#include "Anim_Space_Ship.h"

/**
* @class Ray_Enemy
* @brief レイクラス
* @details
*/
class Ray_Enemy : public Anim_Space_Ship
{
public:
	static constexpr const char* FILE_NAME = "rays.png";
	static constexpr const int TEX_WIDTH = 256;
	static constexpr const int TEX_HEIGHT = 256;
	static constexpr const int DRAW_WIDTH = 128;
	static constexpr const int DRAW_HEIGHT = 128;
	static constexpr const float MOVE_SPEED = 7.0f;
	static constexpr const int FRAME_DIVIDE = 4;
	static constexpr const int WIDTH_NUM = 2;
	static constexpr const int HEIGHT_NUM = 2;
private:
	static constexpr const int STRAIGHT_TO_ANGLE_FRAME = 70;
	enum Mode {
		STRAIGHT,
		GET_ANGLE,
		APPROACH
	};
	Mode m_mode;
	int m_angle;
	int m_elapsed_frame;
public:
	Ray_Enemy(Object_Tag tag, int draw_priority, const char* file_name, int tex_width, int tex_height, int draw_width, int draw_height, const D3DXVECTOR2& pos, float move_speed, int width_num, int height_num, int frame_divide);
	~Ray_Enemy(void);
	void Update(std::list<std::shared_ptr<Game_Object>>& objects);
	void Move(std::list<std::shared_ptr<Game_Object>>& objects);
};


#endif
