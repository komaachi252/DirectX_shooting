/**
* @file Shield_Generator.h
* @brief �V�[���h�����w�b�_
* @author ���r
* @date 2020/03/18
*/
#pragma once
#ifndef SHIELD_GENERATOR_H_
#define SHIELD_GENERATOR_H_
#include <memory>
#include <list>
#include <d3dx9.h>
#include "Game_Object.h"
/**
* @class Shield_Generator
* @brief �e�����N���X
* @details
*/
class Shield_Generator
{
public:
	static constexpr const int WIDTH = 128;
	static constexpr const int HEIGHT = 128;
	static constexpr const char* FILE_NAME = "shield.png";

public:
	Shield_Generator(void);
	void Generate(std::list<std::shared_ptr<Game_Object>>& objects, const D3DXVECTOR2& pos);
};

#endif
