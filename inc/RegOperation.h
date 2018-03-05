#pragma once

#ifndef __REG_OPERATION_H__
#define __REG_OPERATION_H__

#include "DllExport.h"

/** 
 * @class CRegOperation
 * @brief 注册表操作静态类
 *
 * 用于操作注册表
 */
class CRegOperation
{
public:
    /**
     * @brief 读取注册表中的DWORD, 如果失败则使用默认值
     *
     * @param[in]  Key         根键值
     * @param[in]  Subkeyname   子键名
     * @param[in]  ValueName    项名字
     * @param[out] Value          值
     * @param[in]  DefaultVal   默认值
     *
     * @return 是否成功
     */
    static DLL_COMMONLIB_API BOOL WINAPI RegReadDword(
        HKEY Key, 
        const CHAR *Subkeyname, 
        const CHAR *ValueName, 
        DWORD *Value, 
        DWORD DefaultVal);

    static DLL_COMMONLIB_API BOOL WINAPI RegReadDword(
        HKEY Key, 
        const WCHAR *Subkeyname, 
        const WCHAR *ValueName, 
        DWORD *Value, 
        DWORD DefaultVal);

    /**
     * @brief 读取会话对应的HKEY_USER注册表中的DWORD, 如果失败则使用默认值
     *        使用前注意需要有相关权限
     *
     * @param[in]  SessionID    会话ID
     * @param[in]  Subkeyname   子键名
     * @param[in]  ValueName    项名字
     * @param[out] Value        值
     * @param[in]  DefaultVal   默认值
     *
     * @return 是否成功
     */
    static DLL_COMMONLIB_API BOOL WINAPI RegReadDword(
        DWORD SessionId,
        const CHAR *Subkeyname, 
        const CHAR *ValueName, 
        DWORD *Value, 
        DWORD DefaultVal);

    static DLL_COMMONLIB_API BOOL WINAPI RegReadDword(
        DWORD SessionId, 
        const WCHAR *Subkeyname, 
        const WCHAR *ValueName, 
        DWORD *Value, 
        DWORD DefaultVal);

    /**
     * @brief 读取注册表字符串, 如果失败则使用默认值
     *
     * @param[in]  Key          根键值
     * @param[in]  Subkeyname   子键名
     * @param[in]  ValueName    项名字
     * @param[out] Buffer       读取缓冲区
     * @param[inout] Length     读取缓冲区大小
     * @param[in]  DefaultVal   默认值
     *
     * @return 是否成功
     */
    static DLL_COMMONLIB_API BOOL WINAPI RegReadString(
        HKEY Key,
        const CHAR *Subkeyname,
        const CHAR *ValueName, 
        CHAR  *Buffer,
        DWORD *Length,
        const CHAR *DefaultVal);

    static DLL_COMMONLIB_API BOOL WINAPI RegReadString(
        HKEY Key,
        const WCHAR *Subkeyname,
        const WCHAR *ValueName, 
        WCHAR  *Buffer,
        DWORD *Length,
        const WCHAR *DefaultVal);

    /**
     * @brief 读取会话对应的HKEY_USER注册表中的字符串, 如果失败则使用默认值
     *        使用前注意需要有相关权限
     *
     * @param[in]  SessionID    会话ID
     * @param[in]  Subkeyname   子键名
     * @param[in]  ValueName    项名字
     * @param[out] Value        值
     * @param[in]  DefaultVal   默认值
     *
     * @return 是否成功
     */
    static DLL_COMMONLIB_API BOOL WINAPI RegReadString(
        DWORD SessionId,
        const CHAR *Subkeyname,
        const CHAR *ValueName, 
        CHAR  *Buffer,
        DWORD *Length,
        const CHAR *DefaultVal);

    static DLL_COMMONLIB_API BOOL WINAPI RegReadString(
        DWORD SessionId, 
        const WCHAR *Subkeyname,
        const WCHAR *ValueName, 
        WCHAR  *Buffer,
        DWORD *Length,
        const WCHAR *DefaultVal);

    /**
     * @brief 写入注册表DWORD
     *
     * @param[in] Key          根键值
     * @param[in] Subkeyname   子键名
     * @param[in] ValueName    项名字
     * @param[in] Value        值
     *
     * @return 是否成功
     */
     static DLL_COMMONLIB_API BOOL WINAPI RegWriteDword(
         HKEY Key, 
         const CHAR *Subkeyname, 
         const CHAR *ValueName, 
         DWORD Value);

     static DLL_COMMONLIB_API BOOL WINAPI RegWriteDword(
         HKEY Key, 
         const WCHAR *Subkeyname, 
         const WCHAR *ValueName, 
         DWORD Value);

    /**
     * @brief 写入注册表字符串
     *
     * @param[in] Key          根键值
     * @param[in] Subkeyname   子键名
     * @param[in] ValueName    项名字
     * @param[in] Value        值
     *
     * @return 是否成功
     */
     static DLL_COMMONLIB_API BOOL WINAPI RegWriteString(
         HKEY Key, 
         const CHAR *Subkeyname, 
         const CHAR *ValueName, 
         const CHAR *Value);

     static DLL_COMMONLIB_API BOOL WINAPI RegWriteString(
         HKEY Key, 
         const WCHAR *Subkeyname, 
         const WCHAR *ValueName, 
         const WCHAR *Value);

    /**
     * @brief 读取注册表多字符串
     *
     * @param[in] Key          根键值
     * @param[in] Subkeyname   子键名
     * @param[in] ValueName    项名字
     * @param[out] Buffer       读取缓冲区
     * @param[inout] Length     读取缓冲区大小
     *
     * @return 是否成功
     */
     static DLL_COMMONLIB_API BOOL WINAPI RegReadMultiString(
         HKEY Key, 
         const CHAR *Subkeyname, 
         const CHAR *ValueName, 
         CHAR *Buffer, 
         DWORD *Length);

     static DLL_COMMONLIB_API BOOL WINAPI RegReadMultiString(
         HKEY Key, 
         const WCHAR *Subkeyname, 
         const WCHAR *ValueName, 
         WCHAR *Buffer, 
         DWORD *Length);

    /**
     * @brief 读取会话对应的HKEY_USER注册表中的字符串, 如果失败则使用默认值
     *        使用前注意需要有相关权限
     *
     * @param[in]  SessionID    会话ID
     * @param[in]  Subkeyname   子键名
     * @param[in]  ValueName    项名字
     * @param[out] Buffer       读取缓冲区
     * @param[inout] Length     读取缓冲区大小
     *
     * @return 是否成功
     */
     static DLL_COMMONLIB_API BOOL WINAPI RegReadMultiString(
         DWORD SessionId, 
         const CHAR *Subkeyname, 
         const CHAR *ValueName, 
         CHAR *Buffer, 
         DWORD *Length);

     static DLL_COMMONLIB_API BOOL WINAPI RegReadMultiString(
         DWORD SessionId, 
         const WCHAR *Subkeyname, 
         const WCHAR *ValueName, 
         WCHAR *Buffer, 
         DWORD *Length);

    /**
     * @brief 读取注册表, REG_BINARY类型
     *
     * @param[in] hKey          根键值，可选值:     \n
     *                          HKEY_CLASSES_ROOT   \n
     *                          HKEY_CURRENT_USER   \n
     *                          HKEY_LOCAL_MACHINE  \n
     *                          HKEY_USERS 
     * @param[in]  subkeyname   子键名
     * @param[in]  valueName    项名字
     * @param[out] val          值
     * @param[out] vallen       值长度
     *
     * @return
     *      ERROR_SUCCESS: 读取成功\n
     *      其他值:        使用默认值
     */
     static DLL_COMMONLIB_API BOOL WINAPI ReadBinary(
         HKEY hKey,
         const CHAR *subkeyname,
         const CHAR *valueName,
         BYTE **val,
         int *vallen);

     static DLL_COMMONLIB_API BOOL WINAPI ReadBinary(
         HKEY hKey,
         const WCHAR *subkeyname,
         const WCHAR *valueName,
         BYTE **val,
         int *vallen);
};

#endif