/**
* @file singleton.h
* @brief �V���O���g���w�b�_
* @author ���r
* @date 2020/03/18
*/

#pragma once
#ifndef SINGLETON_H_
#define SINGLETON_H_

/**
* @class Singleton
* @brief �f�U�C���p�^�[��
* @details �P�����̃I�u�W�F�N�g�𐶐�����
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
	Singleton(); //! �B���R���X�g���N�^
};

template<typename T>
T *Singleton<T>::instance_ptr = nullptr;

/**
* @fn void Create(void)
* @brief �C���X�^���X�𐶐�����
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
* @brief �C���X�^���X��j������
*/
template<typename T>
void Singleton<T>::Destory(void)
{
	delete instance_ptr;
	instance_ptr = nullptr;
}

#endif	//! SINGLETON_H_
