#pragma once

#ifndef __WIN_UTILS_H__
#define __WIN_UTILS_H__

#include "DllExport.h"

#ifndef _UNICODE
typedef std::string tstring;
#else
typedef std::wstring tstring;
#endif

#ifndef MAX_SIZE_OF_HOSTNMAE
#define MAX_SIZE_OF_HOSTNMAE 31
#endif

//os��־
#define OS_WINXP         0
#define OS_WIN2003       1
#define OS_WINVISTA      2
#define OS_WIN2008       OS_WINVISTA
#define OS_WIN7          3
#define OS_WIN2008R2     OS_WIN7
#define OS_WIN8          4
#define OS_WIN2012       OS_WIN8
#define OS_WIN81         5
#define OS_WIN2012R2     OS_WIN81
#define OS_WIN10         OS_WIN81

/** 
 * @class CWinUtils
 * @brief Windows���ò�������
 */
class CWinUtils
{
public:
	/**
	* @brief ��ȡ�����������Լ���������MAC��ַ
	*
	* @param[out] numOfNic ������
	* @param[out] mac      ����mac��ַ����һ��������ַmac[0-5], �ڶ���������ַmac[6-11] ...
	*
	* @return �ɹ� TRUE  \n
	*         ʧ�� FALSE
	*/
	static DLL_COMMONLIB_API BOOL WINAPI GetMacList(
		int *numOfNic, std::vector<BYTE> &mac);

	/**
	* @brief ��ȡ������������MAC��ַ
	*
	* @param[out] mac      ����mac��ַ
	*
	* @return �ɹ� TRUE  \n
	*         ʧ�� FALSE
	*/
	static DLL_COMMONLIB_API BOOL WINAPI GetMacAddress(WCHAR* mac);

	/**
	* @brief ��ȡ����ip��ַ�б�
	*
	* @param[out] ipList  ip�б�
	*
	*/
	static DLL_COMMONLIB_API void WINAPI GetIPList(std::vector<DWORD> &ipList);

	/**
	* @brief ��ȡ����������ip��ַ
	*
	* @param[out] IP  ip��ַ
	*
	*/
	static DLL_COMMONLIB_API BOOL WINAPI GetIPAddresss(WCHAR* IP);

	/**
	* @brief ��ȡ������
	*
	* @param[out] name windows�������
	*
	* @return �ɹ� TRUE  \n
	*         ʧ�� FALSE
	*/
	static DLL_COMMONLIB_API BOOL WINAPI GetHostname(
		char name[MAX_SIZE_OF_HOSTNMAE + 1]);

	/**
	* @brief �����Ƿ��Թ���Ա��ʽ����
	*
	* @return �ɹ� TRUE  \n
	*         ʧ�� FALSE
	*/
	static DLL_COMMONLIB_API BOOL WINAPI IsAdminMode();

	/**
	* @brief �ж��ļ����ǲ���ȫ·��
	*
	* @param[in] filename �ļ���
	*
	* @return �ɹ� TRUE  \n
	*         ʧ�� FALSE
	*/
	static DLL_COMMONLIB_API BOOL WINAPI IsFullpath(const TCHAR *filename);

	/**
	* @brief ��ȡ��ǰ�������ڻỰID
	*
	* @return �ỰID
	*/
	static DLL_COMMONLIB_API DWORD WINAPI GetSessionID();

	/**
	* @brief ��ȡ�Ự��½�û���
	*
	* @param[in] sessionID �ỰID
	* @param[out] username      ��¼�û���
	*
	* @return �ɹ� TRUE  \n
	*         ʧ�� FALSE
	*/
	static DLL_COMMONLIB_API BOOL WINAPI GetSessionUserName(DWORD sessionID, tstring &username);

	/**
	* @brief �����ֽ�ת��Ϊ���ַ�
	*
	* @param[in] input ���ֽڴ�
	*
	* @return ���ַ���
	*/
	static DLL_COMMONLIB_API std::string WINAPI Wchar2Ansi(const WCHAR *input);

	/**
	* @brief �����ַ���ת��Ϊ���ַ���
	*
	* @param[in] input ���ַ���
	*
	* @return ���ֽڴ�
	*/
	static DLL_COMMONLIB_API std::wstring WINAPI Ansi2WideString(const char *input);

	/**
	* @brief ��ȡ��ǰ��������
	*
	* @return ��������
	*/
	static DLL_COMMONLIB_API tstring WINAPI GetCurrentProcessName();

	/**
	* @brief ��ȡ��ǰ��������Ŀ¼
	*
	* @param[out] path ��ǰ��������Ŀ¼
	*/
	static DLL_COMMONLIB_API void WINAPI GetCurrentProcessPath(std::wstring &path);

	/**
	* @brief ��ȡ������Ϣ
	*
	* @param[in] errorCode Windows������
	*
	* @return Windows������Ϣ
	*/
	static DLL_COMMONLIB_API tstring WINAPI GetErrorMsg(DWORD errorCode);

#define WIN32_ERROR_STRING GetErrorMsg(GetLastError()).c_str()
#define WINNET_ERROR_STRING GetErrorMsg(WSAGetLastError()).c_str()

	/** @brief ��ȡ�ļ����ݵ��ڴ���
	*	@param[in]	filePath	�ļ�·��
	*	@param[out]	buf			�ļ�����
	*	@param[out] size		�ļ���С
	*	@return
	*		- 0 �ɹ�
	*		- ���� ʧ��
	*	@note ���ø�API�󣬽��Զ����ļ��ж�ȡ���ݣ���д�뵽�����С�������ڴ�ռ���API�ڲ����ɣ��ⲿ�ͷš�
	*	@warning	������ڴ��ɿ����룬�ⲿʹ�ú���Ҫ�ֶ��ͷš�ֻ�ʺ�С�ļ��Ĳ������ļ���С����С��30M��
	*/
	static DLL_COMMONLIB_API int	WINAPI ReadFileToBuf(const std::wstring &filePath, void *&buf, size_t &size);

	/** @brief ��ȡ�ļ����ݵ��ڴ���
	*	@param[in]	filePath	�ļ�·��
	*	@param[in]	buf			�ļ�����
	*	@param[in] size		�ļ���С
	*	@return
	*		- 0 �ɹ�
	*		- ���� ʧ��
	*	@note ���ø�API�󣬽������е�����д�뵽�ļ��У�����ļ����Ѿ�����������ᱻ���ǡ�
	*/
	static DLL_COMMONLIB_API int WINAPI  WriteBufToFile(const std::wstring &filePath, const void *buf, size_t size);

	/** @brief ��ȡָ��·����ʣ��ռ�
	*	@param[in]	path	·��
	*	@param[out] size	ʣ��ռ��С
	*	@return
	*		- 0 �ɹ�
	*		- ���� ʧ��
	*	@note �ÿռ���ָ���̵�ʣ��ռ䣬����·������Ӧ���Ĵ���
	*/
	static DLL_COMMONLIB_API int		WINAPI  GetDiskFreeSpaceByPath(const std::wstring &path, ULONGLONG &size);

	/** @brief ��ȡָ��·���Ĵ�����ʹ�õĿռ�
	*	@param[in]	path	·��
	*	@param[out] size	��ʹ�õĿռ��С
	*	@return
	*		- 0 �ɹ�
	*		- ���� ʧ��
	*	@note �ÿռ���ָ���̵�ʹ�ÿռ䣬����·������Ӧ���Ĵ���
	*/
	static DLL_COMMONLIB_API int	WINAPI  GetDiskUsedSpaceByPath(const std::wstring &path, ULONGLONG &size);

	/** @brief ��ȡָ��·�����ļ�����ռ�õĿռ��С
	*	@param[in]	path	·��
	*	@param[out] size	ռ�õĿռ��С
	*	@return
	*		- 0 �ɹ�
	*		- ���� ʧ��
	*	@note �ÿռ���ָ���̵�ʹ�ÿռ䣬����·������Ӧ���Ĵ���
	*/
	static DLL_COMMONLIB_API int	WINAPI GetDirectorysSize(const std::wstring &path, ULONGLONG &size);

	/** @brief ��ȡָ��·�����ļ���ռ�õĿռ��С
	*	@param[in]	path	·��
	*	@param[out] size	ռ�õĿռ��С
	*	@return
	*		- 0 �ɹ�
	*		- ���� ʧ��
	*	@note �ÿռ���ָ���̵�ʹ�ÿռ䣬����·������Ӧ���Ĵ���
	*/
	static DLL_COMMONLIB_API int	WINAPI  GetLocalFileSize(const std::wstring &path, ULONGLONG &size);

	/** @brief ����С��B����ʽ��ΪKB/MB/GB/TB
	*	@param[in]	size	��С
	*	@param[out] tailSize	β��
	*	@param[out] unit	��λKB/MB/GB/TB
	*	@return
	*		- 0 �ɹ�
	*		- ���� ʧ��
	*	@note
	*/
	static DLL_COMMONLIB_API int	WINAPI FormatFileSize(ULONGLONG &size, ULONGLONG &tailSize, std::wstring &unit);

	/** @brief ��������Ȩ��
	*	@param[in]	privilegesName	Ȩ������
	*	@return
	*		- 0 �ɹ�
	*		- ���� ʧ��
	*/
	static DLL_COMMONLIB_API BOOL WINAPI AdjustProcessPrivileges(const WCHAR* privilegesName);

	/** @brief �����ļ���
	*	@param[in]	path	�ļ���·��
	*	@return
	*		- true	�ɹ�
	*		- false	ʧ��
	*	@note ��API����ʵ�ִ����ļ���·�������ļ�·�������ڵ�����£����Եݹ鴴������Ŀ¼��
	*/
	static DLL_COMMONLIB_API bool	WINAPI CreateDirectorys(const std::wstring &path);


	/** @brief ɾ���ļ��к����ļ���
	*	@param[in]	dir	�ļ���·��
	*	@return
	*		- true	�ɹ�
	*		- false	ʧ��
	*	@note ��API���Եݹ�ɾ���ļ��к����ļ���
	*/
	static DLL_COMMONLIB_API bool	WINAPI RemoveDirectorys(const std::wstring &dir);


	/** @brief ö���ļ����µ������ļ�
	*	@param[in]	dir			�ļ���·��
	*	@param[in]	enumSubDir	�Ƿ�ö�����ļ���
	*	@param[out]	fileList	������ļ��б�
	*	@return
	*		- 0 �ɹ�
	*		- ���� ʧ��
	*/

	static DLL_COMMONLIB_API int	WINAPI EnumDirectoryFile(const std::wstring &dir, bool enumSubDir, std::list<std::wstring> &fileList);

	/** @brief ����ļ��Ƿ����
	*	@param[in]	filepath	�ļ�·��
	*	@return
	*		- true	�ļ�����
	*		- false	�ļ�������
	*/
	static DLL_COMMONLIB_API bool WINAPI FileExists(const std::wstring &filepath);

	/** @brief ��ȡϵͳUUID
	*	@param[in]	uuid	ϵͳuuid
	*	@return
	*		- true	�ɹ�
	*		- false	ʧ��
	*/
	static DLL_COMMONLIB_API BOOL WINAPI GetSystemUUID(CHAR* uuid);

	/** @brief ��ָ���û�������г���
	*	@param[in]	sessionId	�Ựid
	*	@param[in]	cmdline	���г���������
	*	@param[in]	wait	�Ƿ�ȴ����г���ִ�����
	*	@return
	*		- true	�ɹ�
	*		- false	ʧ��
	*/
	static DLL_COMMONLIB_API BOOL WINAPI RunApplicationInSession(DWORD sessionId, TCHAR* cmdline, BOOL wait);

	/** @brief ע��ָ���û����ĻỰ
	*	@param[in]	logoffUsername �û���
	*/
	static DLL_COMMONLIB_API void WINAPI LogoffSessionByUsername(CHAR* logoffUsername);

	/** @brief ��ǰ�Ƿ���64λ����ϵͳ
	*	@return
	*		- true	��
	*		- false	��
	*/
	static DLL_COMMONLIB_API BOOL WINAPI Is64BitOS();

	/** @brief ��ȡ����ϵͳ�汾
	*	@return ����ϵͳ�汾����"os��־"�궨�壬�� OS_WINXP
	*/
	static DLL_COMMONLIB_API DWORD GetOSVersion();

	/** @brief ��ȡ�Ựtoken
	*	@param[in]	sessionid �Ựid
	*	@param[out]	userToken token
	*	@return
	*		- true	�ɹ�
	*		- false	ʧ��
	*/
	static DLL_COMMONLIB_API BOOL GetSessionToken(DWORD sessionid, HANDLE* userToken);

	/** @brief ��ȡ UAC token
	*	@param[in]	userToken
	*	@param[out] uacToken
	*	@return
	*		- true	�ɹ�
	*		- false	ʧ��
	*/
	static DLL_COMMONLIB_API BOOL GetUacTokenForUserToken(HANDLE userToken, HANDLE *uacToken);
};

#endif