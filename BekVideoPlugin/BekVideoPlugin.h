#pragma once

#include "CatHelp.h"

// BekVideoPlugin.h : BekVideoPlugin.DLL ����ͷ�ļ�

#if !defined( __AFXCTL_H__ )
#error "�ڰ������ļ�֮ǰ������afxctl.h��"
#endif

#include "resource.h"       // ������


// CBekVideoPluginApp : �й�ʵ�ֵ���Ϣ������� BekVideoPlugin.cpp��

class CBekVideoPluginApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();

public:
	wstring m_wstrCurrentPath;
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

