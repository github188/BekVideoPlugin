#pragma once


// CPlayRealTime 对话框

class CPlayRealTime : public CDialogEx
{
	DECLARE_DYNAMIC(CPlayRealTime)

public:
	CPlayRealTime(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPlayRealTime();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_PLAY_REALTIME };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
