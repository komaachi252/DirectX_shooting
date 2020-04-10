/**
* @file Boss_Bullet_Generator.h
* @brief ボス弾生成ヘッダ
* @author 矢吹一俊
* @date 2020/03/18
*/
#pragma once
#ifndef BOSS_BULLET_GENERATOR_H_
#define BOSS_BULLET_GENERATOR_H_
#include "Bullet_Generator.h"

/**
* @class Boss_Bullet_Generator
* @brief ボス弾生成クラス
* @details
*/
class Boss_Bullet_Generator : public Bullet_Generator
{
public:
	static constexpr const char* FILE_NAME = "cannon.png";
	static constexpr const int TEX_WIDTH = 64;
	static constexpr const int TEX_HEIGHT = 64;
	static constexpr const int DRAW_WIDTH = 25;
	static constexpr const int DRAW_HEIGHT = 25;
	static constexpr const float MOVE_SPEED = 7.0f;
public:
	Boss_Bullet_Generator(void);
	void Generate(std::list<std::shared_ptr<Game_Object>>& objects, const D3DXVECTOR2& pos);
};

#endif
