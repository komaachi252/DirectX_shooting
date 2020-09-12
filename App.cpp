/**
* @file main.cpp
* @brief �又��
* @author ���r
* @date 2020/03/18
*/

#include "App.h"
#include "Manager/Game_Manager.h"
#include "Manager/System_Timer_Manager.h"
#include "Design_Pattern/Singleton.h"

App::App(HINSTANCE instance)
{
	WNDCLASS wc = {};//0�ŏ�����
	wc.lpfnWndProc = Wnd_Proc;//�֐���
	wc.lpszClassName = CLASS_NAME;
	wc.hInstance = m_instance = instance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_BACKGROUND + 1);

	RegisterClass(&wc);

	RECT window_rect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

	AdjustWindowRect(&window_rect, WINDOW_STYLE, FALSE);

	int window_width = window_rect.right - window_rect.left;
	int window_height = window_rect.bottom - window_rect.top;
	int desktop_width = GetSystemMetrics(SM_CXSCREEN);//���j�^�[��
	int desktop_height = GetSystemMetrics(SM_CYSCREEN);//���j�^�[����
	int window_x = max((desktop_width - window_width) / 2, 0);//��ʐ^�񒆂̍��W�𒲂ׂ�X
	int window_y = max((desktop_height - window_height) / 2, 0);//Y
	m_hwnd = CreateWindow(
		CLASS_NAME,//�N���X��
		WINDOW_CAPTION,//�E�B���h�E�̖��O
		WINDOW_STYLE,//�E�B���h�E�̌` �E�B���h�E�T�C�Y�Œ�
		window_x,//���W����X�@�e�L�X�g���܂߂ĕ�����
		window_y,//Y
		window_width,//��
		window_height,//����
		NULL,
		NULL,
		instance,
		NULL
	);
}

int App::Run(int cmd_show)
{
	ShowWindow(m_hwnd, cmd_show);
	UpdateWindow(m_hwnd);

	MSG msg = {};
	Singleton<Game_Manager>::Create();
	Singleton<System_Timer_Manager>::Create();
	
	if(!Singleton<Game_Manager>::Get_Instance()->Init(m_hwnd, m_instance)){
		return -1;
	}
	while (WM_QUIT != msg.message) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {//�Q�[���̏���
			double time = Singleton<System_Timer_Manager>::Get_Instance()->Get_Time();
			if (time - Singleton<System_Timer_Manager>::Get_Instance()->m_static_frame_time < 1.0f / 60.0f) {
				Sleep(0);
			}else {
				Singleton<System_Timer_Manager>::Get_Instance()->Update(time);
				Singleton<Game_Manager>::Get_Instance()->Update();
				Singleton<Game_Manager>::Get_Instance()->Draw();
			}
		}
	}
	Singleton<System_Timer_Manager>::Destory();
	Singleton<Game_Manager>::Destory();

	return(int)msg.wParam;
}

LRESULT CALLBACK App::Wnd_Proc(HWND wnd, UINT msg, WPARAM w_param, LPARAM l_param)
{
	switch (msg) {
	case WM_KEYDOWN://�L�[�̓��͂�������
		if (w_param == VK_ESCAPE) {//�L�[�̖��O�������Ă��� Escape�L�[�ŏI������悤�ɂ���
			SendMessage(wnd, WM_CLOSE, 0, 0);
		}
		break;

	case WM_CLOSE://�E�B���h�E����Ƃ��ɏo��
		if (MessageBox(wnd, "�{���ɏI�����Ă���낵���ł����H", "�m�F", MB_OKCANCEL | MB_DEFBUTTON2) == IDOK) {
			DestroyWindow(wnd);
		}
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);//WM_QUIT��GetMessage�ɏo��
		return 0;
	};
	return DefWindowProc(wnd, msg, w_param, l_param);//���̃��b�Z�[�W������������
}