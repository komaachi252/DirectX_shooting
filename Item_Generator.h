/**
* @file Item_Genetor.h
* @brief アイテム生成ヘッダ
* @author 矢吹一俊
* @date 2020/03/18
*/

#pragma once
#ifndef ITEM_GENERATOR_H_
#define ITEM_GENERATOR_H_
#include "Game_Object.h"
#include "Item.h"

/**
* @class Item_Generator
* @brief アイテム生成クラス
* @details
*/
class Item_Generator
{
public:
	static constexpr const char* FILE_NAME = "item.png";
	static constexpr const char* SHIELD_FILE_NAME = "item2.png";
	static constexpr const int TEX_WIDTH = 256;
	static constexpr const int TEX_HEIGHT = 256;
	static constexpr const int DRAW_WIDTH = 128;
	static constexpr const int DRAW_HEIGHT = 128;
	static constexpr const int FRAME_DIVIDE = 6;
	static constexpr const int WIDTH_NUM = 2;
	static constexpr const int HEIGHT_NUM = 2;
	static constexpr const float MOVE_SPEED = 15.0f;
	static constexpr const float ITEM_SPEED = 4.0f;
	static constexpr const int ITEM_GENERATE_MAX = 8;
private:
	static constexpr const int ITEM_GENERATE[ITEM_GENERATE_MAX] = { 20,21,12,21,22,20,10,21 };
	static constexpr const Item::Item_Type ITEM_TYPE[ITEM_GENERATE_MAX] = { Item::Item_Type::TRIDENT, Item::Item_Type::PENETRATE, Item::Item_Type::SHIELD, Item::Item_Type::METEOR,
		Item::Item_Type::TRIDENT, Item::Item_Type::SHIELD, Item::Item_Type::METEOR, Item::Item_Type::PENETRATE };
	static int m_generate_cnt;
	static int m_generate_arrow;
public:
	void Generate(std::list<std::shared_ptr<Game_Object>>& objects, const D3DXVECTOR2& pos);
	void Generate_Check(std::list<std::shared_ptr<Game_Object>>& objects, const D3DXVECTOR2& pos);
};


#endif
