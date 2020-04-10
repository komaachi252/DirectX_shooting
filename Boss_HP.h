/**
* @file Boss_HP.h
* @brief É{ÉXÇgÇoÉwÉbÉ_
* @author ñÓêÅàÍèr
* @date 2020/03/18
*/

#pragma once
#ifndef BOSS_HP_H_
#define BOSS_HP_H_
#include <d3dx9.h>
#include "Polygon2D.h"
#include "App.h"
#include "Enemy_Generator.h"
#include "Item.h"

/**
* @class Boss_HP
* @brief É{ÉXÇgÇoÉNÉâÉX
* @details
*/
class Boss_HP : public Polygon2D
{
public:
	static constexpr const char* FILE_NAME = "hp_bar.png";
	static constexpr const char* UI_FILE_NAME = "boss_hp.png";
	static constexpr const int TEX_WIDTH = 150;
	static constexpr const int TEX_HEIGHT = 30;
	static constexpr const int DRAW_WIDTH = 150.0f;
	static constexpr const int DRAW_HEIGHT = 30.0f;
	static constexpr const int TEX_BAR_WIDTH = 256;
	static constexpr const int TEX_BAR_HEIGHT = 30;
	static constexpr const float BAR_WIDTH = 270.0f;
	static constexpr const float BAR_HEIGHT = 30.0f;
	static constexpr const float LOGO_DISTANCE_X = DRAW_WIDTH * 0.5f + DRAW_WIDTH * 0.5f;
	static constexpr const float POS_X = App::SCREEN_WIDTH * 0.3f;
	static constexpr const float POS_Y = 100.0f;
	static constexpr const int END_FRAME = 360;
private:
	float m_damage_value;
	float m_hp;
	bool m_is_create;
public:
	Boss_HP(Object_Tag tag, int draw_priority, const char* file_name, int tex_width, int tex_height, int draw_width, int draw_height, const D3DXVECTOR2& pos, Enemy_Generator::Enemy_Type type);
	void Update(std::list<std::shared_ptr<Game_Object>>& objects);
	void Draw(void);
	void Sub_HP(Item::Item_Type type);
	void Create(std::list<std::shared_ptr<Game_Object>>& objects);
	void Destroy(std::list<std::shared_ptr<Game_Object>>& objects);
};

#endif