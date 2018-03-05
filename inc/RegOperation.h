#pragma once

#ifndef __REG_OPERATION_H__
#define __REG_OPERATION_H__

#include "DllExport.h"

/** 
 * @class CRegOperation
 * @brief ע��������̬��
 *
 * ���ڲ���ע���
 */
class CRegOperation
{
public:
    /**
     * @brief ��ȡע����е�DWORD, ���ʧ����ʹ��Ĭ��ֵ
     *
     * @param[in]  Key         ����ֵ
     * @param[in]  Subkeyname   �Ӽ���
     * @param[in]  ValueName    ������
     * @param[out] Value          ֵ
     * @param[in]  DefaultVal   Ĭ��ֵ
     *
     * @return �Ƿ�ɹ�
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
     * @brief ��ȡ�Ự��Ӧ��HKEY_USERע����е�DWORD, ���ʧ����ʹ��Ĭ��ֵ
     *        ʹ��ǰע����Ҫ�����Ȩ��
     *
     * @param[in]  SessionID    �ỰID
     * @param[in]  Subkeyname   �Ӽ���
     * @param[in]  ValueName    ������
     * @param[out] Value        ֵ
     * @param[in]  DefaultVal   Ĭ��ֵ
     *
     * @return �Ƿ�ɹ�
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
     * @brief ��ȡע����ַ���, ���ʧ����ʹ��Ĭ��ֵ
     *
     * @param[in]  Key          ����ֵ
     * @param[in]  Subkeyname   �Ӽ���
     * @param[in]  ValueName    ������
     * @param[out] Buffer       ��ȡ������
     * @param[inout] Length     ��ȡ��������С
     * @param[in]  DefaultVal   Ĭ��ֵ
     *
     * @return �Ƿ�ɹ�
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
     * @brief ��ȡ�Ự��Ӧ��HKEY_USERע����е��ַ���, ���ʧ����ʹ��Ĭ��ֵ
     *        ʹ��ǰע����Ҫ�����Ȩ��
     *
     * @param[in]  SessionID    �ỰID
     * @param[in]  Subkeyname   �Ӽ���
     * @param[in]  ValueName    ������
     * @param[out] Value        ֵ
     * @param[in]  DefaultVal   Ĭ��ֵ
     *
     * @return �Ƿ�ɹ�
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
     * @brief д��ע���DWORD
     *
     * @param[in] Key          ����ֵ
     * @param[in] Subkeyname   �Ӽ���
     * @param[in] ValueName    ������
     * @param[in] Value        ֵ
     *
     * @return �Ƿ�ɹ�
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
     * @brief д��ע����ַ���
     *
     * @param[in] Key          ����ֵ
     * @param[in] Subkeyname   �Ӽ���
     * @param[in] ValueName    ������
     * @param[in] Value        ֵ
     *
     * @return �Ƿ�ɹ�
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
     * @brief ��ȡע�����ַ���
     *
     * @param[in] Key          ����ֵ
     * @param[in] Subkeyname   �Ӽ���
     * @param[in] ValueName    ������
     * @param[out] Buffer       ��ȡ������
     * @param[inout] Length     ��ȡ��������С
     *
     * @return �Ƿ�ɹ�
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
     * @brief ��ȡ�Ự��Ӧ��HKEY_USERע����е��ַ���, ���ʧ����ʹ��Ĭ��ֵ
     *        ʹ��ǰע����Ҫ�����Ȩ��
     *
     * @param[in]  SessionID    �ỰID
     * @param[in]  Subkeyname   �Ӽ���
     * @param[in]  ValueName    ������
     * @param[out] Buffer       ��ȡ������
     * @param[inout] Length     ��ȡ��������С
     *
     * @return �Ƿ�ɹ�
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
     * @brief ��ȡע���, REG_BINARY����
     *
     * @param[in] hKey          ����ֵ����ѡֵ:     \n
     *                          HKEY_CLASSES_ROOT   \n
     *                          HKEY_CURRENT_USER   \n
     *                          HKEY_LOCAL_MACHINE  \n
     *                          HKEY_USERS 
     * @param[in]  subkeyname   �Ӽ���
     * @param[in]  valueName    ������
     * @param[out] val          ֵ
     * @param[out] vallen       ֵ����
     *
     * @return
     *      ERROR_SUCCESS: ��ȡ�ɹ�\n
     *      ����ֵ:        ʹ��Ĭ��ֵ
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