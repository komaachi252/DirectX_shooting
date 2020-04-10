/**
* @file Item.h
* @brief アイテムヘッダ
* @author 矢吹一俊
* @date 2020/03/18
*/

#pragma once
#ifndef ITEM_H_
#define ITEM_H_
#include "Anim_Polygon2D.h"
#include "Circle_Collision.h"
/**
* @class Item
* @brief アイテムクラス
* @details
*/
class Item : public Anim_Polygon2D
{
public:
	enum Item_Type
	{
		NORMAL,
		PENETRATE,
		TRIDENT,
		METEOR,
		SHIELD
	};
	static constexpr const float ITEM_RADIUS = 32.0f;
private:
	Item_Type m_type;
	float m_move_speed;
	Circle_Collsion* m_circle_colli;
public:
	Item(Object_Tag tag, int draw_priority, const char* file_name, int tex_width, int tex_height, int draw_width, int draw_height, const D3DXVECTOR2& pos,
		int width_num, int height_num, bool is_loop, int frame_divide, Item_Type type, float move_speed);
	~Item(void);
	void Update(std::list<std::shared_ptr<Game_Object>>& objects);
	Item_Type Get_Item_Type(void);
	const Circle_Collsion* Get_Collision(void);
};

#endif