// PlayRealTime.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BekVideoPlugin.h"
#include "PlayRealTime.h"
#include "afxdialogex.h"


// CPlayRealTime �Ի���

IMPLEMENT_DYNAMIC(CPlayRealTime, CDialogEx)

CPlayRealTime::CPlayRealTime(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DLG_PLAY_REALTIME, pParent)
{

}

CPlayRealTime::~CPlayRealTime()
{
}

void CPlayRealTime::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPlayRealTime, CDialogEx)
END_MESSAGE_MAP()


// CPlayRealTime ��Ϣ�������
