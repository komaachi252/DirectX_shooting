/**
* @file Player.h
* @brief �v���C���[�w�b�_
* @author ���r
* @date 2020/03/18
*/

#pragma once
#ifndef PLAYER_H_
#define PLAYER_H_
#include "Space_Ship.h"
#include "Bullet_Generator.h"
#include "Effect_Generator.h"
#include "Item.h"

/**
* @class Player
* @brief �v���C���[�N���X
* @details 
*/
class Player : public Space_Ship
{
protected:
	//!  �����W���甭�ˌ��܂ł̋����w
	static constexpr const float MUZZLE_DISTANCE_X = 80.0f;
	//!  �����W���甭�ˌ��܂ł̋����x
	static constexpr const float MUZZLE_DISTANCE_Y = 3.0f;
	//!  �Փ˗p�v���C���[��
	static constexpr const float PLAYER_COLLI_WIDTH = 157.0f;
	//!  �Փ˗p�v���C���[����
	static constexpr const float PLAYER_COLLI_HEIGHT = 123.0f;
	static constexpr const float DISTANCE_ENGINE_X = -82.0f;
	static constexpr const float DISTANCE_ENGINE_Y = 5.0f;
private:
	std::unique_ptr<Bullet_Generator> m_bullet;
	std::unique_ptr<Effect_Generator> m_effect;
	Item::Item_Type m_item_type;
public:
	Player(Object_Tag tag, int draw_priority, const char* file_name, int tex_width, int tex_height, int draw_width, int draw_height, const D3DXVECTOR2& pos, float move_speed);
	~Player(void);
	void Update(std::list<std::shared_ptr<Game_Object>>& objects);
	void Draw(void);
	void Bullet_Shot(std::list<std::shared_ptr<Game_Object>>& objects);
	void Input(D3DXVECTOR2& dir_vec, bool& is_shot);
	void Move(const D3DXVECTOR2& dir_vec);
	void Set_BG_V(std::list<std::shared_ptr<Game_Object>>& objects, float dir_y);
};

#endif