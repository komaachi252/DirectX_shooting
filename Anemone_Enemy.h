/**
* @file Anemone_Enemy.h
* @brief アネモネヘッダ
* @author 矢吹一俊
* @date 2020/03/18
*/

#pragma once
#ifndef ANEMONE_ENEMY_H_
#define ANEMONE_ENEMY_H_
#include "Space_Ship.h"
#include "Homing_Bullet_Generator.h"

/**
* @class Anemone_Enemy
* @brief アネモネクラス
* @details
*/
class Anemone_Enemy : public Space_Ship
{
public:
	static constexpr const char* FILE_NAME = "anemones.png";
	static constexpr const int TEX_WIDTH = 128;
	static constexpr const int TEX_HEIGHT = 64;
	static constexpr const int DRAW_WIDTH = 128;
	static constexpr const int DRAW_HEIGHT = 64;
	static constexpr const float MOVE_SPEED = 4.0f;
	static constexpr const int FRAME_BULLET_TIME = 120; //フレーム
	static constexpr const float RADIUS = 32.0f;
	static constexpr const float ANEMONE_POS_Y = 700.0f;
	
private:
	std::unique_ptr<Homing_Bullet_Generator> m_bullet;
	bool m_is_shot;
	int m_elapsed_frame;
public:
	Anemone_Enemy(Object_Tag tag, int draw_priority, const char* file_name, int tex_width, int tex_height, int draw_width, int draw_height, const D3DXVECTOR2& pos, float move_speed);
	~Anemone_Enemy(void);
	void Update(std::list<std::shared_ptr<Game_Object>>& objects);
	void Move(void);
	void Shot(std::list<std::shared_ptr<Game_Object>>& objects);
};


#endif
