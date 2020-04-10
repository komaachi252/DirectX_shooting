/**
* @file Effect_Generator.h
* @brief �G�t�F�N�g�����w�b�_
* @author ���r
* @date 2020/03/18
*/
#pragma once
#ifndef EFFECT_GENERATOR_H_
#define EFFECT_GENERATOR_H_
#include <memory>
#include <list>
#include <d3dx9.h>
#include "Game_Object.h"
/**
* @class Effect_Generator
* @brief �G�t�F�N�g�����N���X
* @details
*/
class Effect_Generator
{
public:
	Effect_Generator(void);
	void Generate(std::list<std::shared_ptr<Game_Object>>& objects, const D3DXVECTOR2& pos, int width, int height, D3DCOLOR color, int life_frame);
};

#endif
