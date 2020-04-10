/**
* @file Oct_Head_Enemy.h
* @brief タコボスヘッダ
* @author 矢吹一俊
* @date 2020/03/18
*/

#pragma once
#ifndef OCT_HEAD_ENEMY_H_
#define OCT_HEAD_ENEMY_H_
#include "Space_Ship.h"
#include "App.h"
#include "Boss_Bullet_Generator.h"

/**
* @class Oct_Head_Enemy
* @brief タコ頭クラス
* @details
*/
class Oct_Head_Enemy : public Space_Ship
{
public:
	static constexpr const char* FILE_NAME = "sea.png";
	static constexpr const int TEX_WIDTH = 512;
	static constexpr const int TEX_HEIGHT = 512;
	static constexpr const int DRAW_WIDTH = 512;
	static constexpr const int DRAW_HEIGHT = 512;
	static constexpr const float MUZZLE_X = -170.0f;
	static constexpr const float MUZZLE_Y = -140.0f;
	static constexpr const float EYE_RADIUS = -140.0f;
	static constexpr const float EYE_MUZZLE = -35.0f;
	static constexpr const float COLLI_X = -35.0f;
	static constexpr const float COLLI_Y = 120.0f;
	static constexpr const float HEAD_RADIUS = 180.0f;
	static constexpr const int HEAD_HP = 15;
	static constexpr const float EXPLOSION_DISTANCE_X1 = 120.0f;
	static constexpr const float EXPLOSION_DISTANCE_X2 = 150.0f;
	static constexpr const float EXPLOSION_DISTANCE_X3 = -80.0f;
	static constexpr const float EXPLOSION_DISTANCE_Y1 = -40.0f;
	static constexpr const float EXPLOSION_DISTANCE_Y2 = -60.0f;
	static constexpr const float EXPLOSION_DISTANCE_Y3 =  40.0f;

	enum Mode {
		NORMAL,
		BREAK
	};
	Mode m_mode;
	int m_hp;
	int m_elapsed_frame;
	int m_alpha;
	std::unique_ptr<Boss_Bullet_Generator> m_bullet;
public:
	Oct_Head_Enemy(Object_Tag tag, int draw_priority, const char* file_name, int width, int height, const D3DXVECTOR2& pos, float move_speed);
	~Oct_Head_Enemy(void);
	void Update(std::list<std::shared_ptr<Game_Object>>& objects);
	void Draw(void);
	void Move(std::list<std::shared_ptr<Game_Object>>& objects);
	void Break(std::list<std::shared_ptr<Game_Object>>& objects);
	void Shot(std::list<std::shared_ptr<Game_Object>>& objects);
	void Explosion(std::list<std::shared_ptr<Game_Object>>& objects, const D3DXVECTOR2& pos);
	void Sub_HP(Item::Item_Type type);
};

#endif