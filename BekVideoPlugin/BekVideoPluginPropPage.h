#pragma once

// BekVideoPluginPropPage.h : CBekVideoPluginPropPage ����ҳ���������


// CBekVideoPluginPropPage : �й�ʵ�ֵ���Ϣ������� BekVideoPluginPropPage.cpp��

class CBekVideoPluginPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CBekVideoPluginPropPage)
	DECLARE_OLECREATE_EX(CBekVideoPluginPropPage)

// ���캯��
public:
	CBekVideoPluginPropPage();

// �Ի�������
	enum { IDD = IDD_PROPPAGE_BEKVIDEOPLUGIN };

// ʵ��
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ��Ϣӳ��
protected:
	DECLARE_MESSAGE_MAP()
};

