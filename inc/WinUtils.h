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

//os标志
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
 * @brief Windows常用操作函数
 */
class CWinUtils
{
public:
	/**
	* @brief 获取机器网卡数以及各个网卡MAC地址
	*
	* @param[out] numOfNic 网卡数
	* @param[out] mac      网卡mac地址，第一个网卡地址mac[0-5], 第二个网卡地址mac[6-11] ...
	*
	* @return 成功 TRUE  \n
	*         失败 FALSE
	*/
	static DLL_COMMONLIB_API BOOL WINAPI GetMacList(
		int *numOfNic, std::vector<BYTE> &mac);

	/**
	* @brief 获取单网卡机器的MAC地址
	*
	* @param[out] mac      网卡mac地址
	*
	* @return 成功 TRUE  \n
	*         失败 FALSE
	*/
	static DLL_COMMONLIB_API BOOL WINAPI GetMacAddress(WCHAR* mac);

	/**
	* @brief 获取机器ip地址列表
	*
	* @param[out] ipList  ip列表
	*
	*/
	static DLL_COMMONLIB_API void WINAPI GetIPList(std::vector<DWORD> &ipList);

	/**
	* @brief 获取单网卡机器ip地址
	*
	* @param[out] IP  ip地址
	*
	*/
	static DLL_COMMONLIB_API BOOL WINAPI GetIPAddresss(WCHAR* IP);

	/**
	* @brief 获取主机名
	*
	* @param[out] name windows计算机名
	*
	* @return 成功 TRUE  \n
	*         失败 FALSE
	*/
	static DLL_COMMONLIB_API BOOL WINAPI GetHostname(
		char name[MAX_SIZE_OF_HOSTNMAE + 1]);

	/**
	* @brief 程序是否以管理员方式运行
	*
	* @return 成功 TRUE  \n
	*         失败 FALSE
	*/
	static DLL_COMMONLIB_API BOOL WINAPI IsAdminMode();

	/**
	* @brief 判断文件名是不是全路径
	*
	* @param[in] filename 文件名
	*
	* @return 成功 TRUE  \n
	*         失败 FALSE
	*/
	static DLL_COMMONLIB_API BOOL WINAPI IsFullpath(const TCHAR *filename);

	/**
	* @brief 获取当前进程所在会话ID
	*
	* @return 会话ID
	*/
	static DLL_COMMONLIB_API DWORD WINAPI GetSessionID();

	/**
	* @brief 获取会话登陆用户名
	*
	* @param[in] sessionID 会话ID
	* @param[out] username      登录用户名
	*
	* @return 成功 TRUE  \n
	*         失败 FALSE
	*/
	static DLL_COMMONLIB_API BOOL WINAPI GetSessionUserName(DWORD sessionID, tstring &username);

	/**
	* @brief 将宽字节转换为多字符
	*
	* @param[in] input 宽字节串
	*
	* @return 多字符串
	*/
	static DLL_COMMONLIB_API std::string WINAPI Wchar2Ansi(const WCHAR *input);

	/**
	* @brief 将多字符串转换为宽字符串
	*
	* @param[in] input 多字符串
	*
	* @return 宽字节串
	*/
	static DLL_COMMONLIB_API std::wstring WINAPI Ansi2WideString(const char *input);

	/**
	* @brief 获取当前进程名称
	*
	* @return 进程名称
	*/
	static DLL_COMMONLIB_API tstring WINAPI GetCurrentProcessName();

	/**
	* @brief 获取当前进程所在目录
	*
	* @param[out] path 当前进行所在目录
	*/
	static DLL_COMMONLIB_API void WINAPI GetCurrentProcessPath(std::wstring &path);

	/**
	* @brief 获取错误信息
	*
	* @param[in] errorCode Windows错误码
	*
	* @return Windows错误信息
	*/
	static DLL_COMMONLIB_API tstring WINAPI GetErrorMsg(DWORD errorCode);

#define WIN32_ERROR_STRING GetErrorMsg(GetLastError()).c_str()
#define WINNET_ERROR_STRING GetErrorMsg(WSAGetLastError()).c_str()

	/** @brief 读取文件内容到内存中
	*	@param[in]	filePath	文件路径
	*	@param[out]	buf			文件缓存
	*	@param[out] size		文件大小
	*	@return
	*		- 0 成功
	*		- 其他 失败
	*	@note 调用该API后，将自动从文件中读取内容，并写入到缓存中。缓存的内存空间由API内部生成，外部释放。
	*	@warning	缓存的内存由库申请，外部使用后，需要手动释放。只适合小文件的操作，文件大小必须小于30M。
	*/
	static DLL_COMMONLIB_API int	WINAPI ReadFileToBuf(const std::wstring &filePath, void *&buf, size_t &size);

	/** @brief 读取文件内容到内存中
	*	@param[in]	filePath	文件路径
	*	@param[in]	buf			文件缓存
	*	@param[in] size		文件大小
	*	@return
	*		- 0 成功
	*		- 其他 失败
	*	@note 调用该API后，将缓存中的内容写入到文件中，如果文件中已经存在内容则会被覆盖。
	*/
	static DLL_COMMONLIB_API int WINAPI  WriteBufToFile(const std::wstring &filePath, const void *buf, size_t size);

	/** @brief 获取指定路径的剩余空间
	*	@param[in]	path	路径
	*	@param[out] size	剩余空间大小
	*	@return
	*		- 0 成功
	*		- 其他 失败
	*	@note 该空间是指磁盘的剩余空间，即该路径所对应到的磁盘
	*/
	static DLL_COMMONLIB_API int		WINAPI  GetDiskFreeSpaceByPath(const std::wstring &path, ULONGLONG &size);

	/** @brief 获取指定路径的磁盘已使用的空间
	*	@param[in]	path	路径
	*	@param[out] size	已使用的空间大小
	*	@return
	*		- 0 成功
	*		- 其他 失败
	*	@note 该空间是指磁盘的使用空间，即该路径所对应到的磁盘
	*/
	static DLL_COMMONLIB_API int	WINAPI  GetDiskUsedSpaceByPath(const std::wstring &path, ULONGLONG &size);

	/** @brief 获取指定路径的文件夹所占用的空间大小
	*	@param[in]	path	路径
	*	@param[out] size	占用的空间大小
	*	@return
	*		- 0 成功
	*		- 其他 失败
	*	@note 该空间是指磁盘的使用空间，即该路径所对应到的磁盘
	*/
	static DLL_COMMONLIB_API int	WINAPI GetDirectorysSize(const std::wstring &path, ULONGLONG &size);

	/** @brief 获取指定路径的文件所占用的空间大小
	*	@param[in]	path	路径
	*	@param[out] size	占用的空间大小
	*	@return
	*		- 0 成功
	*		- 其他 失败
	*	@note 该空间是指磁盘的使用空间，即该路径所对应到的磁盘
	*/
	static DLL_COMMONLIB_API int	WINAPI  GetLocalFileSize(const std::wstring &path, ULONGLONG &size);

	/** @brief 将大小（B）格式化为KB/MB/GB/TB
	*	@param[in]	size	大小
	*	@param[out] tailSize	尾数
	*	@param[out] unit	单位KB/MB/GB/TB
	*	@return
	*		- 0 成功
	*		- 其他 失败
	*	@note
	*/
	static DLL_COMMONLIB_API int	WINAPI FormatFileSize(ULONGLONG &size, ULONGLONG &tailSize, std::wstring &unit);

	/** @brief 提升进程权限
	*	@param[in]	privilegesName	权限名称
	*	@return
	*		- 0 成功
	*		- 其他 失败
	*/
	static DLL_COMMONLIB_API BOOL WINAPI AdjustProcessPrivileges(const WCHAR* privilegesName);

	/** @brief 创建文件夹
	*	@param[in]	path	文件夹路径
	*	@return
	*		- true	成功
	*		- false	失败
	*	@note 该API可以实现创建文件夹路径。在文件路径不存在的情况下，可以递归创建各个目录。
	*/
	static DLL_COMMONLIB_API bool	WINAPI CreateDirectorys(const std::wstring &path);


	/** @brief 删除文件夹和子文件夹
	*	@param[in]	dir	文件夹路径
	*	@return
	*		- true	成功
	*		- false	失败
	*	@note 该API可以递归删除文件夹和子文件夹
	*/
	static DLL_COMMONLIB_API bool	WINAPI RemoveDirectorys(const std::wstring &dir);


	/** @brief 枚举文件夹下的所有文件
	*	@param[in]	dir			文件夹路径
	*	@param[in]	enumSubDir	是否枚举子文件夹
	*	@param[out]	fileList	输出的文件列表
	*	@return
	*		- 0 成功
	*		- 其他 失败
	*/

	static DLL_COMMONLIB_API int	WINAPI EnumDirectoryFile(const std::wstring &dir, bool enumSubDir, std::list<std::wstring> &fileList);

	/** @brief 检查文件是否存在
	*	@param[in]	filepath	文件路径
	*	@return
	*		- true	文件存在
	*		- false	文件不存在
	*/
	static DLL_COMMONLIB_API bool WINAPI FileExists(const std::wstring &filepath);

	/** @brief 获取系统UUID
	*	@param[in]	uuid	系统uuid
	*	@return
	*		- true	成功
	*		- false	失败
	*/
	static DLL_COMMONLIB_API BOOL WINAPI GetSystemUUID(CHAR* uuid);

	/** @brief 以指定用户身份运行程序
	*	@param[in]	sessionId	会话id
	*	@param[in]	cmdline	运行程序命令行
	*	@param[in]	wait	是否等待运行程序执行完成
	*	@return
	*		- true	成功
	*		- false	失败
	*/
	static DLL_COMMONLIB_API BOOL WINAPI RunApplicationInSession(DWORD sessionId, TCHAR* cmdline, BOOL wait);

	/** @brief 注销指定用户名的会话
	*	@param[in]	logoffUsername 用户名
	*/
	static DLL_COMMONLIB_API void WINAPI LogoffSessionByUsername(CHAR* logoffUsername);

	/** @brief 当前是否是64位操作系统
	*	@return
	*		- true	是
	*		- false	否
	*/
	static DLL_COMMONLIB_API BOOL WINAPI Is64BitOS();

	/** @brief 获取操作系统版本
	*	@return 操作系统版本，见"os标志"宏定义，如 OS_WINXP
	*/
	static DLL_COMMONLIB_API DWORD GetOSVersion();

	/** @brief 获取会话token
	*	@param[in]	sessionid 会话id
	*	@param[out]	userToken token
	*	@return
	*		- true	成功
	*		- false	失败
	*/
	static DLL_COMMONLIB_API BOOL GetSessionToken(DWORD sessionid, HANDLE* userToken);

	/** @brief 获取 UAC token
	*	@param[in]	userToken
	*	@param[out] uacToken
	*	@return
	*		- true	成功
	*		- false	失败
	*/
	static DLL_COMMONLIB_API BOOL GetUacTokenForUserToken(HANDLE userToken, HANDLE *uacToken);
};

#endif