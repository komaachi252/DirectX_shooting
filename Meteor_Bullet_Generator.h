/**
* @file Meteor_Bullet_Generator.h
* @brief メテオ弾生成ヘッダ
* @author 矢吹一俊
* @date 2020/03/18
*/
#pragma once
#ifndef METEOR_BULLET_GENERATOR_H_
#define METEOR_BULLET_GENERATOR_H_
#include "Bullet_Generator.h"

/**
* @class Meteor_Bullet_Generator
* @brief メテオ弾生成クラス
* @details
*/
class Meteor_Bullet_Generator : public Bullet_Generator
{
public:
	static constexpr const char* FILE_NAME = "meteor2.png";
	static constexpr const int TEX_WIDTH = 128;
	static constexpr const int TEX_HEIGHT = 128;
	static constexpr const int DRAW_WIDTH = 128;
	static constexpr const int DRAW_HEIGHT = 128;
	static constexpr const float MOVE_SPEED = 15.0f;

public:
	Meteor_Bullet_Generator(void);
	void Generate(std::list<std::shared_ptr<Game_Object>>& objects, const D3DXVECTOR2& pos);
};

#endif