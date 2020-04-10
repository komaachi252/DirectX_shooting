/**
* @file Space_Ship.h
* @brief ‰F’ˆ‘Dƒwƒbƒ_
* @author –îˆêr
* @date 2020/03/18
*/

#pragma once
#ifndef SPACE_SHIP_H_
#define SPACE_SHIP_H_
#include <d3dx9.h>
#include "Polygon2D.h"
#include "Circle_Collision.h"
#include "Explosion_Generator.h"

/**
* @class Space_Ship
* @brief ‰F’ˆ‘DƒNƒ‰ƒX
* @details ‰~‚Ì“–‚½‚è”»’è‚ğ•Û‚µ‚Ä‚¢‚é
*/
class Space_Ship : public Polygon2D
{
protected:
	Circle_Collsion* m_circle_colli;
	float m_move_speed;
	std::unique_ptr<Explosion_Generator> m_explosion;
public:
	Space_Ship(Object_Tag tag, int draw_priority, const char* file_name, int width, int height, const D3DXVECTOR2& pos, float move_speed);
	Space_Ship(Object_Tag tag, int draw_priority, const char* file_name, int tex_width, int tex_height, int draw_width, int draw_height, const D3DXVECTOR2& pos, float move_speed);
	virtual ~Space_Ship(void);
	virtual void Update(std::list<std::shared_ptr<Game_Object>>& objects);
	//virtual void Draw(void);
	const Circle_Collsion& Get_Collision(void) const;
};

#endif