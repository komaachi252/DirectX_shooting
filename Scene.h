/**
* @file Scene.h
* @brief シーンヘッダ
* @author 矢吹一俊
* @date 2020/03/18
*/
#pragma once
#ifndef SCENE_H_
#define SCENE_H_
#include <vector>
#include <list>
#include <memory>
#include "Game_Object.h"

/**
* @class Scene
* @brief シーン処理クラス
* @details
*/
class Scene
{
protected:
	//!  シーン内のオブジェクト
	std::list<std::shared_ptr<Game_Object>> m_objects;
public:
	Scene(void) {}
	virtual ~Scene(void) { m_objects.clear(); }
	virtual void Update(void)
	{
		for (auto obj : m_objects) {
			obj->Update(m_objects);
		}
		for (auto it = m_objects.begin(); it != m_objects.end();) {
			if ((*it)->Get_Object_State() == Game_Object::Object_State::INACTIVE) {
				it = m_objects.erase(it);
				continue;
			}else{
				it++;
			}
		}
	}
	virtual void Draw(void) 
	{
		for (auto obj : m_objects) {
			obj->Draw();
		}
	}

	void Draw_Sort(void)
	{
		m_objects.sort([](const auto& lhs, const auto& rhs) {
			return lhs->Get_Draw_Priority() > rhs->Get_Draw_Priority();
		});
	}
};

#endif