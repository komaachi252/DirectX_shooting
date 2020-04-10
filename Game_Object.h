/**
* @file Game_Object.h
* @brief ゲームオブジェクトヘッダ
* @author 矢吹一俊
* @date 2020/03/18
*/
#pragma once
#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_
#include <vector>
#include <list>
#include <memory>

/**
* @class Game_Object
* @brief オブジェクト抽象クラス
* @details
*/
class Game_Object
{
public:
	/**
	* @enum Game_Tag
	* @brief オブジェクト識別タグ
	*/
	enum Object_Tag
	{
		//!  タグが必要ない場合はNONE
		NONE = 0,
		PLAYER,
		ENEMY,
		RAYS_DUMMY,
		OCT_BOSS,
		BG,
		GROUND,
		BOSS_UI,
		BOSS_BAR,
		TYPE_UI,
		SHIELD,
		BULLET,
		PENETRATE_BULLET,
		TAG_MAX
	};
	enum Object_State
	{
		ACTIVE,
		EXPLOSION,
		INACTIVE,
		STATE_MAX
	};
	enum Object_Draw_Priority : int
	{
		DRAW_BG_1 = 99,
		DRAW_BG_2 = 98,
		DRAW_BG_3 = 97,
		DRAW_GROUND = 96,
		DRAW_EEFECT = 15,
		DRAW_ITEM = 14,
		DRAW_BULLET = 13,
		DRAW_SHIELD = 12,
		DRAW_PLAYER = 11,
		DRAW_ENEMY = 10,
		DRAW_OCT_HEAD = 9,
		DRAW_EXPLOSION = 8,
		DRAW_BOSS_UI = 7,
		DRAW_BOSS_BAR = 6
	};
private:
protected:
	//! オブジェクト種類識別タグ
	Object_Tag m_object_tag;
	Object_State m_object_state;
	int m_draw_priority;
public:
	Game_Object(Object_Tag tag, int draw_priority):m_object_tag(tag),m_object_state(ACTIVE),m_draw_priority(draw_priority) { }
	virtual ~Game_Object(void) {}
	virtual void Update(std::list<std::shared_ptr<Game_Object>>& objects) = 0;
	virtual void Draw(void) = 0;
	Object_Tag Get_Object_Tag(void) { return m_object_tag; }
	Object_State Get_Object_State(void) { return m_object_state; }
	int Get_Draw_Priority(void) { return m_draw_priority; }
	void Set_Object_State(Object_State state) { m_object_state = state; }
};

#endif
