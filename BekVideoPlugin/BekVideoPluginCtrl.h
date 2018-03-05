#pragma once
#include "PlayRealTime.h"

// BekVideoPluginCtrl.h : CBekVideoPluginCtrl ActiveX �ؼ����������


// CBekVideoPluginCtrl : �й�ʵ�ֵ���Ϣ������� BekVideoPluginCtrl.cpp��

class CBekVideoPluginCtrl : public COleControl
{
	DECLARE_DYNCREATE(CBekVideoPluginCtrl)

// ���캯��
public:
	CBekVideoPluginCtrl();

// ��д
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// ʵ��
protected:
	~CBekVideoPluginCtrl();

	DECLARE_OLECREATE_EX(CBekVideoPluginCtrl)    // �๤���� guid
	DECLARE_OLETYPELIB(CBekVideoPluginCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CBekVideoPluginCtrl)     // ����ҳ ID
	DECLARE_OLECTLTYPE(CBekVideoPluginCtrl)		// �������ƺ�����״̬

// ��Ϣӳ��
	DECLARE_MESSAGE_MAP()

// ����ӳ��
	DECLARE_DISPATCH_MAP()

// �¼�ӳ��
	DECLARE_EVENT_MAP()

// ���Ⱥ��¼� ID
public:
	enum {
	};
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

public:
	CPlayRealTime m_DlgPlayRealTime;
};

