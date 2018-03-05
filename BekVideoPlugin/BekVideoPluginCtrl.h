#pragma once
#include "PlayRealTime.h"

// BekVideoPluginCtrl.h : CBekVideoPluginCtrl ActiveX 控件类的声明。


// CBekVideoPluginCtrl : 有关实现的信息，请参阅 BekVideoPluginCtrl.cpp。

class CBekVideoPluginCtrl : public COleControl
{
	DECLARE_DYNCREATE(CBekVideoPluginCtrl)

// 构造函数
public:
	CBekVideoPluginCtrl();

// 重写
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// 实现
protected:
	~CBekVideoPluginCtrl();

	DECLARE_OLECREATE_EX(CBekVideoPluginCtrl)    // 类工厂和 guid
	DECLARE_OLETYPELIB(CBekVideoPluginCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CBekVideoPluginCtrl)     // 属性页 ID
	DECLARE_OLECTLTYPE(CBekVideoPluginCtrl)		// 类型名称和杂项状态

// 消息映射
	DECLARE_MESSAGE_MAP()

// 调度映射
	DECLARE_DISPATCH_MAP()

// 事件映射
	DECLARE_EVENT_MAP()

// 调度和事件 ID
public:
	enum {
	};
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

public:
	CPlayRealTime m_DlgPlayRealTime;
};

