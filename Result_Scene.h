/**
* @file Result_Scene.h
* @brief ���U���g�V�[���w�b�_
* @author ���r
* @date 2020/03/18
*/

#pragma once
#ifndef RESULT_SCENE_H_
#define RESULT_SCENE_H_
#include "Scene.h"

/**
* @class Result_Scene
* @brief ���U���g�V�[�������N���X
* @details
*/
class Result_Scene : public Scene
{
public:
	Result_Scene(void);
	~Result_Scene(void);
	void Update(void);
	void Draw(void);
};


#endif