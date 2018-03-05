// BekVideoPluginCtrl.cpp : CBekVideoPluginCtrl ActiveX 控件类的实现。

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

// 消息映射

BEGIN_MESSAGE_MAP(CBekVideoPluginCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// 调度映射

BEGIN_DISPATCH_MAP(CBekVideoPluginCtrl, COleControl)
END_DISPATCH_MAP()

// 事件映射

BEGIN_EVENT_MAP(CBekVideoPluginCtrl, COleControl)
END_EVENT_MAP()

// 属性页

// TODO: 根据需要添加更多属性页。请记住增加计数!
BEGIN_PROPPAGEIDS(CBekVideoPluginCtrl, 1)
	PROPPAGEID(CBekVideoPluginPropPage::guid)
END_PROPPAGEIDS(CBekVideoPluginCtrl)

// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CBekVideoPluginCtrl, "BEKVIDEOPLUGIN.BekVideoPluginCtrl.1",
	0x1eff5809, 0x3926, 0x4d69, 0x89, 0xf0, 0xbb, 0x2a, 0x5d, 0x1c, 0x14, 0x35)

// 键入库 ID 和版本

IMPLEMENT_OLETYPELIB(CBekVideoPluginCtrl, _tlid, _wVerMajor, _wVerMinor)

// 接口 ID

const IID IID_DBekVideoPlugin = { 0xF5A5DCD7, 0x34C5, 0x44CD, { 0x8E, 0xF9, 0x23, 0xA4, 0xBB, 0x88, 0x8, 0xFB } };
const IID IID_DBekVideoPluginEvents = { 0x5C6621D6, 0xF2F1, 0x4602, { 0xA9, 0xE4, 0x18, 0x98, 0x2B, 0x30, 0xD5, 0x4 } };

// 控件类型信息

static const DWORD _dwBekVideoPluginOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CBekVideoPluginCtrl, IDS_BEKVIDEOPLUGIN, _dwBekVideoPluginOleMisc)

// CBekVideoPluginCtrl::CBekVideoPluginCtrlFactory::UpdateRegistry -
// 添加或移除 CBekVideoPluginCtrl 的系统注册表项

BOOL CBekVideoPluginCtrl::CBekVideoPluginCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO:  验证您的控件是否符合单元模型线程处理规则。
	// 有关更多信息，请参考 MFC 技术说明 64。
	// 如果您的控件不符合单元模型规则，则
	// 必须修改如下代码，将第六个参数从
	// afxRegApartmentThreading 改为 0。

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


// CBekVideoPluginCtrl::CBekVideoPluginCtrl - 构造函数

CBekVideoPluginCtrl::CBekVideoPluginCtrl()
{
	InitializeIIDs(&IID_DBekVideoPlugin, &IID_DBekVideoPluginEvents);
	// TODO:  在此初始化控件的实例数据。
}

// CBekVideoPluginCtrl::~CBekVideoPluginCtrl - 析构函数

CBekVideoPluginCtrl::~CBekVideoPluginCtrl()
{
	// TODO:  在此清理控件的实例数据。
}

// CBekVideoPluginCtrl::OnDraw - 绘图函数

void CBekVideoPluginCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO:  用您自己的绘图代码替换下面的代码。
	
	m_DlgPlayRealTime.MoveWindow(rcBounds, 1);
}

// CBekVideoPluginCtrl::DoPropExchange - 持久性支持

void CBekVideoPluginCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: 为每个持久的自定义属性调用 PX_ 函数。
}


// CBekVideoPluginCtrl::OnResetState - 将控件重置为默认状态

void CBekVideoPluginCtrl::OnResetState()
{
	COleControl::OnResetState();  // 重置 DoPropExchange 中找到的默认值

	// TODO:  在此重置任意其他控件状态。
}


// CBekVideoPluginCtrl 消息处理程序


int CBekVideoPluginCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	CRect rect;
	GetClientRect(&rect);

	L_INFO(_T("hel %d\n"), 45);

	m_DlgPlayRealTime.Create(IDD_DLG_PLAY_REALTIME, this);
	m_DlgPlayRealTime.MoveWindow(rect.left, rect.top, rect.Width(), rect.Height());
	m_DlgPlayRealTime.ShowWindow(SW_SHOW);

	return 0;
}
