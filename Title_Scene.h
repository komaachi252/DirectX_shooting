/**
* @file Title_Scene.h
* @brief �^�C�g���V�[���w�b�_
* @author ���r
* @date 2020/03/18
*/

#pragma once
#ifndef TITLE_SCENE_H_
#define TITLE_SCENE_H_
#include "Scene.h"

/**
* @class Title_Scene
* @brief �^�C�g���V�[�������N���X
* @details
*/
class Title_Scene : public Scene
{
public:
	Title_Scene(void);
	~Title_Scene(void);
	void Update(void);
	void Draw(void);
};


#endif