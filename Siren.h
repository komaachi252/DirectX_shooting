/**
* @file Siren.h
* @brief �T�C�����w�b�_
* @author ���r
* @date 2020/03/18
*/
#pragma once
#ifndef SIREN_H_
#define SIREN_H_
#include "Game_Object.h"

class Siren
{
private:
	bool m_is_used;
	int m_frame;
	int m_cnt;
	int m_fade_state;
public:
	Siren(void);
	void Update(void);
	void Start(void);
};

#endif

