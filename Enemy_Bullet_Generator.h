/**
* @file Enemy_Bullet_Generator.h
* @brief ìGíeê∂ê¨ÉwÉbÉ_
* @author ñÓêÅàÍèr
* @date 2020/03/18
*/
#pragma once
#ifndef ENEMY_BULLET_GENERATOR_H_
#define ENEMY_BULLET_GENERATOR_H_
#include "Bullet_Generator.h"

/**
* @class Enemy_Bullet_Generator
* @brief ìGíeê∂ê¨ÉNÉâÉX
* @details
*/
class Enemy_Bullet_Generator : public Bullet_Generator
{
public:
	static constexpr const char* FILE_NAME = "bullet2.png";
	static constexpr const int TEX_WIDTH = 64;
	static constexpr const int TEX_HEIGHT = 64;
	static constexpr const int DRAW_WIDTH = 30;
	static constexpr const int DRAW_HEIGHT = 30;
	static constexpr const float MOVE_SPEED = 7.0f;
public:
	Enemy_Bullet_Generator(void);
	void Generate(std::list<std::shared_ptr<Game_Object>>& objects, const D3DXVECTOR2& pos);
};

#endif