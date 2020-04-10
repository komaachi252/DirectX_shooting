/**
* @file Game_Manager.h
* @brief �Q�[���Ǘ��w�b�_
* @author ���r
* @date 2020/03/18
*/

#pragma once
#ifndef GAME_MANAGER_H_
#define GAME_MANAGER_H_
#include <memory>
#include <Windows.h>
#include "Scene.h"

/** @def
* �}�N���̃R�����g
*/

/**
* @class
* @brief �ȒP�ȃN���X�̐���
* @details �ڍׂȃN���X�̐���
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
* �����Ɋ֐��̐���������
* @brief �v�����
* @param (������) �����̐���
* @param (������) �����̐���
* @return �߂�l�̐���
* @sa �Q�Ƃ��ׂ��֐��������΃����N���\���
* @detail �ڍׂȐ���
*/

#endif
