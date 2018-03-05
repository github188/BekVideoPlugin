 /**
 * @file LogBase.h
 * @brief logϵͳ�����ӿ�
 */
#ifndef __LOGBASE_H__
#define __LOGBASE_H__

#include "DllExport.h"

/**
 * @brief ���Եȼ�
 */
enum log_level_t
{
    LOG_LEVEL_FATAL = 1, /**< �������� */
    LOG_LEVEL_ERROR = 2, /**< ���� */
    LOG_LEVEL_WARN  = 3, /**< ���� */
    LOG_LEVEL_INFO  = 4, /**< ��Ϣ */
    LOG_LEVEL_DEBUG = 5, /**< ���� */
    LOG_LEVEL_TRACE = 6, /**< ���� */

    LOG_TYPE_DUMP   = 100, /**< DUMP��Ϣ */
    LOG_TYPE_TMP    = 101, /**< ��ʱ���� */
};

/**
 * @brief log���������
 */
enum log_output_type_t
{
    LOG_OUTPUT_DISABLE  = 0x0, /* ����log */
    LOG_OUTPUT_STDERR   = 0x1, /* ���������̨ */
    LOG_OUTPUT_DBGPORT  = 0x2, /* �����Windows���Կ� */
    LOG_OUTPUT_FILE     = 0x3, /* ������ļ� */
};

/**
 * @brief ��������ļ��仯
 */
#define CTLOG_INIT_FLAGS_MONITOR 0x1

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief ��ʼ��logϵͳ
 *
 * @param[in] config_file               �����ļ�·��\n
 *                                      �����һ��������NULL���������ļ������ڣ���ʹ��Ĭ��ֵ
 * @param[in] flags                     ��CTLOG_INIT_FLAGS_XXXXX ����
 *
 * @return �ɹ� ��0\n
 *         ʧ�� 0
 */
#ifdef _WIN32
int DLL_COMMONLIB_API LogBase_initW(const wchar_t *config_file);
int DLL_COMMONLIB_API LogBase_initExW(const wchar_t *config_file, int flags);
#endif
int DLL_COMMONLIB_API LogBase_initA(const char *config_file);
int DLL_COMMONLIB_API LogBase_initExA(const char *config_file, int flags);
#ifdef _UNICODE 
#define LogBase_init LogBase_initW
#define LogBase_initEx LogBase_initExW
#else
#define LogBase_init LogBase_initA
#define LogBase_initEx LogBase_initExA
#endif

/**
 * @brief ����logϵͳ�ַ������Ͳ��� 
 *
 * @param[in] modulename ģ������"GLOBAL"��ʾȫ��(Ĭ��)����
 * @param[in] filedname  ����
 * @param[in] value      ֵ
 */
#ifdef _WIN32
void DLL_COMMONLIB_API LogBase_SetOptStrW(const wchar_t *modulename,
                                 const wchar_t *filedname, 
                                 const wchar_t *value);
#endif
void DLL_COMMONLIB_API LogBase_SetOptStrA(const char *modulename,
                                 const char *filedname, 
                                 const char *value);
#ifdef _UNICODE 
#define LogBase_SetOptStr LogBase_SetOptStrW
#else
#define LogBase_SetOptStr LogBase_SetOptStrA
#endif

/**
 * @brief ����logϵͳint���Ͳ��� 
 *
 * @param[in] modulename ģ������"GLOBAL"��ʾȫ��(Ĭ��)����
 * @param[in] filedname  ����
 * @param[in] value      ֵ
 */
#ifdef _WIN32
void DLL_COMMONLIB_API LogBase_SetOptIntW(const wchar_t *modulename,
                                 const wchar_t *filedname, 
                                 int value);
#endif
void DLL_COMMONLIB_API LogBase_SetOptIntA(const char *modulename,
                                 const char *filedname, 
                                 int value);
#ifdef _UNICODE 
#define LogBase_SetOptInt LogBase_SetOptIntW
#else
#define LogBase_SetOptInt LogBase_SetOptIntA
#endif

/**
 * @brief ����log�������
 *
 * @param[in] type �������
 * @see   log_output_type_t
 */
#define LogBase_setOutput(type) \
    LogBase_SetOptInt(_T("GLOBAL"), _T("log_output_type"), (log_output_type_t)(type));
/**
 * @brief ����log����ļ���
 *
 * @param[in] filename
 */
#define LogBase_setLogFile(filename) \
    { LogBase_SetOptStr(_T("GLOBAL"), _T("log_output_filepath"), (filename));  \
      LogBase_SetOptInt(_T("GLOBAL"), _T("log_output_type"),     LOG_OUTPUT_FILE); }

/**
 * @brief ����/����DUMP
 *
 * @param filename
 */
#define LogBase_enableDump(bEnable) \
    LogBase_SetOptInt(_T("GLOBAL"), _T("log_dump"), bEnable);

/**
 * @brief ����logĬ�ϵȼ�
 *
 * @param[in] level log�ȼ�
 * @see log_level_t
 */
#define LogBase_setLogLevel(level) \
    LogBase_SetOptInt(_T("GLOBAL"), _T("log_level"), (log_level_t)(level));

/**
 * @brief ������������
 */
void DLL_COMMONLIB_API LogBase_reload();

#ifdef _WIN32
void DLL_COMMONLIB_API LogBase_printfW(const wchar_t *module_name,
                              log_level_t loglevel, 
                              const char *function_name,
                              const char *file_name,
                              int line,
                              _Printf_format_string_ const wchar_t *pszFormat, ...);
#endif
void DLL_COMMONLIB_API LogBase_printfA(const char *module_name,
                              enum  log_level_t loglevel, 
                              const char *function_name,
                              const char *file_name,
                              int line,
                              _Printf_format_string_ const char *pszFormat, ...)
                              __attribute__((__format__(__printf__,6,7)));
#ifdef _UNICODE 
#define LogBase_printf LogBase_printfW
#else
#define LogBase_printf LogBase_printfA
#endif

/**
 * @brief ���ٵȼ���־���
 *
 * @param[in] fmt ��ʽ���ַ���
 */
#define L_TRACE(...) LogBase_printf(MODULE_NAME, LOG_LEVEL_TRACE, __FUNCTION__, __FILE__, __LINE__, __VA_ARGS__);
#define L_TRACE_ENTER() L_TRACE(_T("Enter\n"))
#define L_TRACE_LEAVE() L_TRACE(_T("Leave\n"))
#define L_TRACE_EXIT() L_TRACE(_T("Exit\n"))

/**
 * @brief ���Եȼ���־���
 *
 * @param[in] fmt ��ʽ���ַ���
 */
#define L_DEBUG(...) LogBase_printf(MODULE_NAME, LOG_LEVEL_DEBUG, __FUNCTION__, __FILE__, __LINE__, __VA_ARGS__);
/**
 * @brief ��Ϣ�ȼ���־���
 *
 * @param[in] fmt ��ʽ���ַ���
 */
#define L_INFO(...)  LogBase_printf(MODULE_NAME, LOG_LEVEL_INFO,  __FUNCTION__, __FILE__, __LINE__, __VA_ARGS__);
/**
 * @brief ����ȼ���־���
 *
 * @param[in] fmt ��ʽ���ַ���
 */
#define L_WARN(...)  LogBase_printf(MODULE_NAME, LOG_LEVEL_WARN,  __FUNCTION__, __FILE__, __LINE__, __VA_ARGS__);
/**
 * @brief ����ȼ���־���
 *
 * @param[in] fmt ��ʽ���ַ���
 */
#define L_ERROR(...) LogBase_printf(MODULE_NAME, LOG_LEVEL_ERROR, __FUNCTION__, __FILE__, __LINE__, __VA_ARGS__);
/**
 * @brief ��������ȼ���־���
 *
 * @param[in] fmt ��ʽ���ַ���
 */
#define L_FATAL(...) LogBase_printf(MODULE_NAME, LOG_LEVEL_FATAL, __FUNCTION__, __FILE__, __LINE__, __VA_ARGS__);


/**
 * @brief ��ʱ���Ժ� \n
 * ��һ������Ϣǿ�������ֻ������ʱ����, �ύ��svn�İ汾����������һ����
 *
 * @param[in] fmt ��ʽ���ַ���
 */
#define L_TEMP(...) LogBase_printf(MODULE_NAME, LOG_TYPE_TMP, __FUNCTION__, __FILE__, __LINE__, __VA_ARGS__);

#ifdef _WIN32
void DLL_COMMONLIB_API LogBase_dumpW(const wchar_t *module_name, int bForce, const char *function_name, const char *file_name, int line,
                            const void *buf, int len);
#endif
void DLL_COMMONLIB_API LogBase_dumpA(const char *module_name, int bForce, const char *function_name, const char *file_name, int line,
                            const void *buf, int len);
#ifdef _UNICODE 
#define LogBase_dump LogBase_dumpW
#else
#define LogBase_dump LogBase_dumpA
#endif

/**
 * @brief dump���ݿ�
 *
 * @param[in] buf         ���ݵ�ַ
 * @param[in] len         ���ݿ��С
 */
#define L_DUMP(buf, len) LogBase_dump(MODULE_NAME, 0, __FUNCTION__, __FILE__, __LINE__, buf, len);

/**
 * @brief dump����, ֻ������ʱ����, �ύ��svn�İ汾������ʹ��
 *
 * @param[in] buf         ���ݵ�ַ
 * @param[in] len         ���ݿ��С
 */
#define L_TMPDUMP(buf, len) LogBase_dump(MODULE_NAME, 1, __FUNCTION__, __FILE__, __LINE__, buf, len);

/**
 * @brief ����logϵͳ
 */
void DLL_COMMONLIB_API LogBase_done(void);

#ifdef __cplusplus
}
#endif

#endif
