/**
* @file System_Timer_Manager.h
* @brief �V�X�e���^�C�}�[�w�b�_
* @author ���r
* @date 2020/03/18
*/

#ifndef SYSTEM_TIMER_H_
#define SYSTEM_TIMER_H_
#include <Windows.h>

/**
* @class System_Timer_Manager
* @brief �V�X�e���^�C�}�[�N���X
*/
class System_Timer_Manager
{
private:
	bool m_is_timer_stopped; // �X�g�b�v�t���O
	LONGLONG m_ticks_per_sec;  // �P�b�Ԃ̌v������
	LONGLONG m_stop_time;         // �X�g�b�v��������
	LONGLONG m_last_elapsed_time;  // �Ō�ɋL�^�����X�V����
	LONGLONG m_base_time;         // ��{����
public:
	static constexpr const float FPS_MEASUREMENT_TIME = 1.0f;
	int m_frame_count; // �t���[���J�E���^�[
	int m_FPS_base_frame_count; // FPS�v���̊�ƂȂ�t���[���J�E���^�[
	double m_FPS_base_time; // FPS�v���̊�ƂȂ鎞��
	double m_static_frame_time; // �t���[���Œ�p�v������
	float m_FPS; // FPS

	System_Timer_Manager(void);

	void Update(void);

	// �V�X�e���^�C�}�[�̃��Z�b�g
	void Reset(void);

	// �V�X�e���^�C�}�[�̃X�^�[�g
	void Start(void);

	// �V�X�e���^�C�}�[�̃X�g�b�v
	void Stop(void);

	// �V�X�e���^�C�}�[��0.1�b�i�߂�
	void Advance(void);

	// �v�����Ԃ̎擾
	double Get_Time(void);

	// ���݂̎��Ԃ��擾
	double Get_Absolute_Time(void);

	// �o�ߎ��Ԃ̎擾
	float Get_Elapsed_Time(void);

	// �V�X�e���^�C�}�[���~�܂��Ă��邩�H
	bool Is_Stoped(void);

	// ���݂̃X���b�h��1�̃v���Z�b�T�i���݂̃X���b�h�j�ɐ���
	void Limit_Thread_Affinity_To_Current_Proc(void);
	LARGE_INTEGER Get_Adjusted_Current_Time(void);
};

#endif // SYSTEM_TIMER_H_
