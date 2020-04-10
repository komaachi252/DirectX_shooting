/**
* @file Dinput_Manager.h
* @brief �L�[�{�[�h���̓w�b�_
* @author ���r
* @date 2020/03/18
*/

#ifndef DINPUT_H_
#define DINPUT_H_
#include <Windows.h>
// dinput.h���C���N���[�h����O�ɂ�������Ȃ��ƌx�����o��̂Œ���
#define DIRECTINPUT_VERSION (0x0800)
#include <dinput.h>

/**
* @class Dinput_Manager
* @brief ���͊Ǘ��N���X
*/
class Dinput_Manager
{
private:
	static constexpr const int NUM_KEY_MAX = 256;
	LPDIRECTINPUT8			m_input;					// DirectInput�I�u�W�F�N�g�ւ̃|�C���^
	LPDIRECTINPUTDEVICE8	m_dev_keyboard;				// ���̓f�o�C�X(�L�[�{�[�h)�ւ̃|�C���^
	BYTE					m_key_state[NUM_KEY_MAX];			// �L�[�{�[�h�̓��͏�񃏁[�N
	BYTE					m_key_state_trigger[NUM_KEY_MAX];	// �L�[�{�[�h�̃g���K�[��񃏁[�N
	BYTE					m_key_state_release[NUM_KEY_MAX];	// �L�[�{�[�h�̃����[�X��񃏁[�N
public:
	bool Init(HWND hwnd, HINSTANCE instance);
	bool Create_Input(HINSTANCE instance);
	~Dinput_Manager(void);
	void Update(void);
	bool Is_Press(int key);
	bool Is_Trigger(int key);
	bool Is_Release(int key);

};

/*------------------------------------------------------------------------------
   �֐��̃v���g�^�C�v�錾
------------------------------------------------------------------------------*/

// �L�[�{�[�h���̓��W���[���̏�����
//
// �߂�l�F�������o���Ȃ������ꍇfalse
//
// �����Fhinstance ... �C���X�^���X�n���h���iWinMain�̈����ȂǂŎ擾�j
//       hWnd      ... �E�B���h�E�n���h��
//
bool Keyboard_Initialize(HINSTANCE hInstance, HWND hWnd);

// �L�[�{�[�h���W���[���̏I������
void Keyboard_Finalize(void);

// �L�[�{�[�h���W���[���̍X�V
// ���L�[�{�[�h�S�̂̃L�[��Ԃ̎擾
//
void Keyboard_Update(void);

// �L�[�{�[�h�̃L�[��Ԃ̎擾
//
// Keyboard_Update()�Ŏ擾�����L�[�̏�Ԃ��m�F����֐��Q
//
// �߂�l�F�w��̃L�[��
//     Press   ... ������Ă���
//     Trigger ... �������u��
//     Release ... �������u��
// �ł������ꍇtrue��Ԃ�
//
// �����FnKey ... �L�[�w��iDIK_�`�Ƃ����L�[�񋓁j
//
bool Keyboard_IsPress(int nKey);
bool Keyboard_IsTrigger(int nKey);//�������u��
bool Keyboard_IsRelease(int nKey);//�������u��

#endif