/**
* @file Penetrate_Bullet_Generator.h
* @brief ä—í íeê∂ê¨ÉwÉbÉ_
* @author ñÓêÅàÍèr
* @date 2020/03/18
*/
#pragma once
#ifndef PENETRATE_BULLET_GENERATOR_H_
#define PENETRATE_BULLET_GENERATOR_H_
#include "Bullet_Generator.h"

/**
* @class Penetrate_Bullet_Generator
* @brief íeê∂ê¨ÉNÉâÉX
* @details
*/
class Penetrate_Bullet_Generator : public Bullet_Generator
{
public:
	static constexpr const char* FILE_NAME = "penetrate_bullet.png";
	static constexpr const int TEX_WIDTH = 64;
	static constexpr const int TEX_HEIGHT = 64;
	static constexpr const int DRAW_WIDTH = 25;
	static constexpr const int DRAW_HEIGHT = 25;
	static constexpr const float MOVE_SPEED = 15.0f;
public:
	Penetrate_Bullet_Generator(void);
	void Generate(std::list<std::shared_ptr<Game_Object>>& objects, const D3DXVECTOR2& pos);
};

#endif
