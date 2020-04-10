/**
* @file Game_Scene.h
* @brief ゲームシーンヘッダ
* @author 矢吹一俊
* @date 2020/03/18
*/

#pragma once
#ifndef GAME_SCENE_H_
#define GAME_SCENE_H_
#include "Scene.h"

/**
* @class Game_Scene
* @brief ゲームシーン処理クラス
* @details
*/
class Game_Scene : public Scene
{
public:
	Game_Scene(void);
	~Game_Scene(void);
	void Update(void);
	void Draw(void);
};


#endif