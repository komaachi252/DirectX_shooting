/**
* @file singleton.h
* @brief シングルトンヘッダ
* @author 矢吹一俊
* @date 2020/03/18
*/

#pragma once
#ifndef SINGLETON_H_
#define SINGLETON_H_

/**
* @class Singleton
* @brief デザインパターン
* @details １つだけのオブジェクトを生成する
*/
template<typename T>
class Singleton
{
public:
	static T *Get_Instance(void)
	{
		return instance_ptr;
	}
	static bool Create();
	static void Destory();
protected:
	static T *instance_ptr;
	Singleton(); //! 隠しコンストラクタ
};

template<typename T>
T *Singleton<T>::instance_ptr = nullptr;

/**
* @fn void Create(void)
* @brief インスタンスを生成する
*/
template<typename T>
bool Singleton<T>::Create(void)
{
	if (!instance_ptr) {
		instance_ptr = new T;
		return true;
	}
	return false;
}

/**
* @fn void Destroy(void)
* @brief インスタンスを破棄する
*/
template<typename T>
void Singleton<T>::Destory(void)
{
	delete instance_ptr;
	instance_ptr = nullptr;
}

#endif	//! SINGLETON_H_
