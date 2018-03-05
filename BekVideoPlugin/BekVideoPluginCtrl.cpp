// BekVideoPluginCtrl.cpp : CBekVideoPluginCtrl ActiveX �ؼ����ʵ�֡�

#include "stdafx.h"
#include "BekVideoPlugin.h"
#include "BekVideoPluginCtrl.h"
#include "BekVideoPluginPropPage.h"
#include "afxdialogex.h"

#define MODULE_NAME	L"BekVideoPluginCtrl"

CBekVideoPluginApp g_bekVideoPluginApp;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CBekVideoPluginCtrl, COleControl)

// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CBekVideoPluginCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// ����ӳ��

BEGIN_DISPATCH_MAP(CBekVideoPluginCtrl, COleControl)
END_DISPATCH_MAP()

// �¼�ӳ��

BEGIN_EVENT_MAP(CBekVideoPluginCtrl, COleControl)
END_EVENT_MAP()

// ����ҳ

// TODO: ������Ҫ��Ӹ�������ҳ�����ס���Ӽ���!
BEGIN_PROPPAGEIDS(CBekVideoPluginCtrl, 1)
	PROPPAGEID(CBekVideoPluginPropPage::guid)
END_PROPPAGEIDS(CBekVideoPluginCtrl)

// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CBekVideoPluginCtrl, "BEKVIDEOPLUGIN.BekVideoPluginCtrl.1",
	0x1eff5809, 0x3926, 0x4d69, 0x89, 0xf0, 0xbb, 0x2a, 0x5d, 0x1c, 0x14, 0x35)

// ����� ID �Ͱ汾

IMPLEMENT_OLETYPELIB(CBekVideoPluginCtrl, _tlid, _wVerMajor, _wVerMinor)

// �ӿ� ID

const IID IID_DBekVideoPlugin = { 0xF5A5DCD7, 0x34C5, 0x44CD, { 0x8E, 0xF9, 0x23, 0xA4, 0xBB, 0x88, 0x8, 0xFB } };
const IID IID_DBekVideoPluginEvents = { 0x5C6621D6, 0xF2F1, 0x4602, { 0xA9, 0xE4, 0x18, 0x98, 0x2B, 0x30, 0xD5, 0x4 } };

// �ؼ�������Ϣ

static const DWORD _dwBekVideoPluginOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CBekVideoPluginCtrl, IDS_BEKVIDEOPLUGIN, _dwBekVideoPluginOleMisc)

// CBekVideoPluginCtrl::CBekVideoPluginCtrlFactory::UpdateRegistry -
// ��ӻ��Ƴ� CBekVideoPluginCtrl ��ϵͳע�����

BOOL CBekVideoPluginCtrl::CBekVideoPluginCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO:  ��֤���Ŀؼ��Ƿ���ϵ�Ԫģ���̴߳������
	// �йظ�����Ϣ����ο� MFC ����˵�� 64��
	// ������Ŀؼ������ϵ�Ԫģ�͹�����
	// �����޸����´��룬��������������
	// afxRegApartmentThreading ��Ϊ 0��

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_BEKVIDEOPLUGIN,
			IDB_BEKVIDEOPLUGIN,
			afxRegApartmentThreading,
			_dwBekVideoPluginOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


// CBekVideoPluginCtrl::CBekVideoPluginCtrl - ���캯��

CBekVideoPluginCtrl::CBekVideoPluginCtrl()
{
	InitializeIIDs(&IID_DBekVideoPlugin, &IID_DBekVideoPluginEvents);
	// TODO:  �ڴ˳�ʼ���ؼ���ʵ�����ݡ�
}

// CBekVideoPluginCtrl::~CBekVideoPluginCtrl - ��������

CBekVideoPluginCtrl::~CBekVideoPluginCtrl()
{
	// TODO:  �ڴ�����ؼ���ʵ�����ݡ�
}

// CBekVideoPluginCtrl::OnDraw - ��ͼ����

void CBekVideoPluginCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO:  �����Լ��Ļ�ͼ�����滻����Ĵ��롣
	
	m_DlgPlayRealTime.MoveWindow(rcBounds, 1);
}

// CBekVideoPluginCtrl::DoPropExchange - �־���֧��

void CBekVideoPluginCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Ϊÿ���־õ��Զ������Ե��� PX_ ������
}


// CBekVideoPluginCtrl::OnResetState - ���ؼ�����ΪĬ��״̬

void CBekVideoPluginCtrl::OnResetState()
{
	COleControl::OnResetState();  // ���� DoPropExchange ���ҵ���Ĭ��ֵ

	// TODO:  �ڴ��������������ؼ�״̬��
}


// CBekVideoPluginCtrl ��Ϣ�������


int CBekVideoPluginCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	CRect rect;
	GetClientRect(&rect);

	L_INFO(_T("hel %d\n"), 45);

	m_DlgPlayRealTime.Create(IDD_DLG_PLAY_REALTIME, this);
	m_DlgPlayRealTime.MoveWindow(rect.left, rect.top, rect.Width(), rect.Height());
	m_DlgPlayRealTime.ShowWindow(SW_SHOW);

	return 0;
}
