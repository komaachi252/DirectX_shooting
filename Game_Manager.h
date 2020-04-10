/**
* @file Game_Manager.h
* @brief ゲーム管理ヘッダ
* @author 矢吹一俊
* @date 2020/03/18
*/

#pragma once
#ifndef GAME_MANAGER_H_
#define GAME_MANAGER_H_
#include <memory>
#include <Windows.h>
#include "Scene.h"

/** @def
* マクロのコメント
*/

/**
* @class
* @brief 簡単なクラスの説明
* @details 詳細なクラスの説明
*/
class Game_Manager
{
public:
	enum Scene_State
	{
		NONE,
		TITLE,
		GAME,
		RESULT,
		SCENE_MAX,
	};
private:
	static constexpr const Scene_State INIT_SCENE = TITLE;
	static constexpr const int FADE_FRAME_DEFAULT = 60;
	Scene_State m_scene_state;
	Scene_State m_next_scene_state;
	std::unique_ptr<Scene> m_scene;
	int m_fade_frame;
public:
	bool Init(HWND hwnd, HINSTANCE instance);
	~Game_Manager(void);
	void Update(void);
	void Draw(void);
	void Set_Next_Scene(Scene_State next_scene, int fade_frame = FADE_FRAME_DEFAULT);
	void Scene_Change(void);
};

/**
* @fn
* ここに関数の説明を書く
* @brief 要約説明
* @param (引数名) 引数の説明
* @param (引数名) 引数の説明
* @return 戻り値の説明
* @sa 参照すべき関数を書けばリンクが貼れる
* @detail 詳細な説明
*/

#endif
