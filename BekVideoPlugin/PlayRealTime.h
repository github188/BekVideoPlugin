#pragma once


// CPlayRealTime �Ի���

class CPlayRealTime : public CDialogEx
{
	DECLARE_DYNAMIC(CPlayRealTime)

public:
	CPlayRealTime(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPlayRealTime();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_PLAY_REALTIME };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
