#pragma once

// BekVideoPluginPropPage.h : CBekVideoPluginPropPage 属性页类的声明。


// CBekVideoPluginPropPage : 有关实现的信息，请参阅 BekVideoPluginPropPage.cpp。

class CBekVideoPluginPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CBekVideoPluginPropPage)
	DECLARE_OLECREATE_EX(CBekVideoPluginPropPage)

// 构造函数
public:
	CBekVideoPluginPropPage();

// 对话框数据
	enum { IDD = IDD_PROPPAGE_BEKVIDEOPLUGIN };

// 实现
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 消息映射
protected:
	DECLARE_MESSAGE_MAP()
};

