// BekVideoPluginPropPage.cpp : CBekVideoPluginPropPage 属性页类的实现。

#include "stdafx.h"
#include "BekVideoPlugin.h"
#include "BekVideoPluginPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CBekVideoPluginPropPage, COlePropertyPage)

// 消息映射

BEGIN_MESSAGE_MAP(CBekVideoPluginPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CBekVideoPluginPropPage, "BEKVIDEOPLUGIN.BekVideoPluginPropPage.1",
	0x45e6a68b, 0x9637, 0x4ce7, 0xba, 0xbb, 0x2c, 0x4a, 0xea, 0xf0, 0x8f, 0xa)

// CBekVideoPluginPropPage::CBekVideoPluginPropPageFactory::UpdateRegistry -
// 添加或移除 CBekVideoPluginPropPage 的系统注册表项

BOOL CBekVideoPluginPropPage::CBekVideoPluginPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_BEKVIDEOPLUGIN_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CBekVideoPluginPropPage::CBekVideoPluginPropPage - 构造函数

CBekVideoPluginPropPage::CBekVideoPluginPropPage() :
	COlePropertyPage(IDD, IDS_BEKVIDEOPLUGIN_PPG_CAPTION)
{
}

// CBekVideoPluginPropPage::DoDataExchange - 在页和属性间移动数据

void CBekVideoPluginPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CBekVideoPluginPropPage 消息处理程序
