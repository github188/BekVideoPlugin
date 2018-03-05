// BekVideoPlugin.cpp : CBekVideoPluginApp �� DLL ע���ʵ�֡�

#include "stdafx.h"
#include "BekVideoPlugin.h"

#include "CatHelp.h"
#include <ObjSafe.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CBekVideoPluginApp theApp;

const GUID CDECL _tlid = { 0xFC71C06D, 0x2BE1, 0x451A, { 0xA5, 0x3D, 0x7B, 0x67, 0xA8, 0xEF, 0x3A, 0xDB } };

const CATID CLSID_SafeItem = { 0x1eff5809, 0x3926, 0x4d69, { 0x89, 0xf0, 0xbb, 0x2a, 0x5d, 0x1c, 0x14, 0x35 } };

const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CBekVideoPluginApp::InitInstance - DLL ��ʼ��

BOOL CBekVideoPluginApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO:  �ڴ�������Լ���ģ���ʼ�����롣

		//�������Ļ���
		setlocale(LC_ALL, ".936");

		//��ע����ȡ����·��
		m_wstrCurrentPath = _T("");
		wstring keyPath = _T("SOFTWARE\\Bekzoyo\\BekVideoPlugin");
		wstring keyStr = _T("PATH");
		DWORD dwLen = 0;
		CRegOperation::RegReadString(HKEY_LOCAL_MACHINE, keyPath.c_str(), keyStr.c_str(), NULL, &dwLen, _T(""));
		if (dwLen > 0)
		{
			TCHAR* szStr = new TCHAR[dwLen];
			if (CRegOperation::RegReadString(HKEY_LOCAL_MACHINE, keyPath.c_str(), keyStr.c_str(), szStr, &dwLen, _T("123")))
			{
				m_wstrCurrentPath = szStr;
			}
			delete[]szStr;
		}
		if (!CWinUtils::FileExists(m_wstrCurrentPath))
		{
			AfxMessageBox(_T("��Ƶ�ؼ���ʼ��ʧ��!"));
			return FALSE;
		}

		//Ŀ¼��ʼ��
		wstring wstrLogPath = m_wstrCurrentPath + _T("\\log");
		if (!CWinUtils::FileExists(wstrLogPath))
		{
			CWinUtils::CreateDirectorys(wstrLogPath);
		}

		//��־ģ���ʼ��
		wstring wsLogConf = m_wstrCurrentPath + _T("\\conf\\BekVideoPlugin_logconf.ini");
		wstring wsLogPath = _T("\"") + m_wstrCurrentPath + _T("\\log\\BekVideoPlugin.log\"");
		WritePrivateProfileString(_T("GLOBAL"), _T("log_output_filepath"), wsLogPath.c_str(), wsLogConf.c_str());	//������־�ļ�·��
		LogBase_init(wsLogConf.c_str());
	}

	return bInit;
}



// CBekVideoPluginApp::ExitInstance - DLL ��ֹ

int CBekVideoPluginApp::ExitInstance()
{
	// TODO:  �ڴ�������Լ���ģ����ֹ���롣

	LogBase_done();

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - ������ӵ�ϵͳע���

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	//ע��ؼ���ʼ����ȫ���
	HRESULT hr = CreateComponentCategory(CATID_SafeForInitializing,
		L"Controls safely initializable from persistent data!");
	if (FAILED(hr))
	{
		return hr;
	}
	hr = RegisterCLSIDInCategory(CLSID_SafeItem,
		CATID_SafeForInitializing);
	if (FAILED(hr))
	{
		return hr;
	}

	//ע��ؼ��ű���ȫ���
	hr = CreateComponentCategory(CATID_SafeForScripting,
		L"Controls safely  scriptable!");
	if (FAILED(hr))
	{
		return hr;
	}
	hr = RegisterCLSIDInCategory(CLSID_SafeItem,
		CATID_SafeForScripting);
	if (FAILED(hr))
	{
		return hr;
	}

	return NOERROR;
}



// DllUnregisterServer - �����ϵͳע������Ƴ�

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	//ɾ���ؼ���ʼ����ȫ���
	HRESULT hr = UnRegisterCLSIDInCategory(CLSID_SafeItem, CATID_SafeForInitializing);
	if (FAILED(hr))
	{
		return hr;
	}

	//ɾ���ؼ��ű���ȫ���
	hr = UnRegisterCLSIDInCategory(CLSID_SafeItem, CATID_SafeForScripting);
	if (FAILED(hr))
	{
		return hr;
	}

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
