#pragma once

#ifndef __STRING_UTILS_H__
#define __STRING_UTILS_H__

#include "DllExport.h"

/**
* @class CStringUtils
* @brief �ַ���������̬��
*
* ���ڲ����ַ���
*/

class CStringUtils
{
public:
	/** @brief ���ַ���תΪUTF8�����ַ���
	*	@param [in]	 wstr ����Ŀ��ַ���
	*	@param [out] ustr �����UTF-8�ַ���
	*/
	static DLL_COMMONLIB_API void WINAPI Unicode2UTF8(const std::wstring& wstr, std::string& ustr);

	/** @brief ���ַ���תΪխ�ַ���
	*	@param [in]	wstr	����Ŀ��ַ���
	*	@param [out] str	���խ�ַ���
	*/
	static DLL_COMMONLIB_API void WINAPI Unicode2ASCII(const std::wstring& wstr, std::string& str);

	/** @brief UTF8�ַ���תΪ���ַ���
	*	@param [in]	 ustr �����UTF-8�ַ���
	*	@param [out] wstr ����Ŀ��ַ���
	*/

	static DLL_COMMONLIB_API void WINAPI UTF82Unicode(const std::string& ustr, std::wstring& wstr);


	/** @brief utf8�ַ���תΪխ�ַ���
	*	@param [in]	 ustr	�����UTF-8�ַ���
	*	@param [out] str	�����խ�ַ���
	*/
	static DLL_COMMONLIB_API void WINAPI UTF82ASCII(const std::string& ustr, std::string& str);

	/** @brief խ�ַ���תΪ���ַ���
	*	@param [in]	 str	�����խ�ַ���
	*	@param [out] wstr	����Ŀ��ַ���
	*/
	static DLL_COMMONLIB_API void WINAPI ASCII2Unicode(const std::string& str, std::wstring& wstr);


	/** @brief խ�ַ���תΪUTF8�ַ���
	*	@param [in]	 str	�����խ�ַ���
	*	@param [out] ustr	�����UTF-8�ַ���
	*/
	static DLL_COMMONLIB_API void WINAPI ASCII2UTF8(const std::string& str, std::string& ustr);


	/** @brief ��ʽ���ַ���
	*	@param [in]	 fmt	�ַ�����ʽģ��
	*	@param [in]  ...	�ɱ����
	*	@return ���ظ�ʽ�����ַ���
	*	@par ʾ��
	*	@code
	*		std::string str;
	*		str=Format("1+1=%d",1+1);
	*		//ִ�к�str��ֵΪ 1+1=2
	*	@endcode
	*	�ַ�����ʽģ���еĿɴ�ӡ���ͣ��ɲο����µ�ַ
	*	https://msdn.microsoft.com/en-us/library/hf4y5e3w(v=vs.90).aspx
	*  @warning
	*		��ʹ�øú���ʱ��Ҫ��Ҫ������ڸ�ʽ���ʱ���ڿ�->խ�ַ���ת����ͬʱ��ת�������а����˷�ASCII�ַ���ͬʱδָ���������򣬻���������ƥ�䣬�ᵼ��ת��ʧЧ��
	*		��
	@code
	std::string str;
	str=StringUtil::Format("���ַ�[%S]",L"����");
	//ת����str��ֵΪ""
	//����������������ԣ����ʼ��ʱ������setlocale(LC_ALL,"chs");
	//��ת�����strֵΪ"���ַ�[����]"
	str=StringUtil::Format("���ַ�[%S]",L"AAA");
	//����Ǹ���ʽ��Ӱ��,��Ϊ��ת�������ֽ�����ASCII�ַ�
	@endcode
	*/
	static DLL_COMMONLIB_API std::string WINAPI Format(const char *fmt, ...);

	/** @brief ��ʽ���ַ���
	*	@param [in]	 fmt	�ַ�����ʽģ��
	*	@param [in]  ...	�ɱ����
	*	@return ���ظ�ʽ�����ַ���
	*	�ַ�����ʽģ���еĿɴ�ӡ���ͣ��ɲο����µ�ַ
	*	https://msdn.microsoft.com/en-us/library/hf4y5e3w(v=vs.90).aspx
	*	@par ʾ��
	*	@code
	*		std::wstring str;
	*		str=Format(L"1+1=%d",1+1);
	*		//ִ�к�str��ֵΪ 1+1=2
	*	@endcode
	*/
	static DLL_COMMONLIB_API std::wstring WINAPI Format(const wchar_t *fmt, ...);

	/** @brief ��ȥ�ַ�����ͷ��ĩβ�Ŀո�
	*	@param [in]	 str	�ַ�����ʽģ��
	*	@return ������������ַ���
	*/
	static DLL_COMMONLIB_API void WINAPI TrimString(std::string& str);

	/** @brief ��ȥ�ַ�����ͷ��ĩβ�Ŀո�
	*	@param [in]	 str	�ַ�����ʽģ��
	*	@return ������������ַ���
	*/
	static DLL_COMMONLIB_API void WINAPI TrimString(std::wstring& str);

	/** @brief ���ַ�תΪխ�ַ�
	*	@param [in]	ws	����Ŀ��ַ���
	*	@param [in] codepage ������Ҫת���ɵ��ַ�����
	*	@return	����խ�ַ���
	*/
	static DLL_COMMONLIB_API std::string WINAPI Convert(const std::wstring& ws, UINT codepage = CP_UTF8);

	/** @brief խ�ַ�תΪ���ַ�
	*	@param [in]	s	�����խ�ַ���
	*	@param [in] codepage ���뵱ǰխ�ַ��ı���
	*	@return	���ؿ��ַ���
	*/
	static DLL_COMMONLIB_API std::wstring WINAPI Convert(const std::string& s, UINT codepage = CP_UTF8);

	/** @brief �ַ����滻�����ַ����ض������ݸ���ָ��������
	*	@param [in,out]	str ��Ҫת�����ַ���
	*	@param [in] old_Value ������Ҫת�������ַ���
	*	@param [in] new_Value ������Ҫ�滻Ϊ���ַ���
	*	@par ʾ��
	*	@code
	*		std::string str="&123&456&abc";
	*		ReplaceAllString(str,"&","#");
	*		//ִ�к�str�����޸�Ϊ#123#456#abc
	*	@endcode
	*/
	static DLL_COMMONLIB_API void WINAPI ReplaceAllString(std::string& str, const std::string& old_Value, const std::string& new_Value);

	/** @brief �ַ����滻�����ַ����ض������ݸ���ָ��������
	*	@param [in,out]	str ��Ҫת�����ַ���
	*	@param [in] old_Value ������Ҫת�������ַ���
	*	@param [in] new_Value ������Ҫ�滻Ϊ���ַ���
	*	@par ʾ��
	*	@code
	*		std::wstring str=L"&123&456&abc";
	*		ReplaceAllString(str,L"&",L"#");
	*		//ִ�к�str�����޸�Ϊ#123#456#abc
	*	@endcode
	*/
	static DLL_COMMONLIB_API void WINAPI ReplaceAllString(std::wstring& str, const std::wstring& old_Value, const std::wstring& new_Value);

	/** @brief �ַ����ָ�
	*	@param [in]	srcString ���и���ַ���
	*	@param [in] separator ʹ�õķָ�Ԫ��
	*	@param [out] strList  ����ķָ����ַ����б�
	*	@par ʾ��
	*	@code
	*		std::vector<string> strarry;
	*		SplitString("a|bc||123","|",strarry);
	*		//��ʱ����� �Ը��ַ��� �� "|" ���зָ�ָ������Ϊ a��b��123 3���ַ���
	*	@endcode
	*/
	static DLL_COMMONLIB_API void WINAPI SplitString(const std::string &srcString, const std::string &separator, std::vector<std::string> &strList);


	/** @brief �ַ����ָ�
	*	@param [in]	srcString ���и���ַ���
	*	@param [in] separator ʹ�õķָ�Ԫ��
	*	@param [out] strList  ����ķָ����ַ����б�
	*	@par ʾ��
	*	@code
	*		std::vector<wstring> strarry;
	*		SplitString(L"a|bc||123",L"|",strarry);
	*		//��ʱ����� �Ը��ַ��� �� "|" ���зָ�ָ������Ϊ a��b��123 3���ַ���
	*	@endcode
	*/
	static DLL_COMMONLIB_API void WINAPI SplitString(const std::wstring &srcString, const std::wstring &separator, std::vector<std::wstring> &strList);



	/** @brief ת��ΪСд�ַ���
	*	@param [in]	srcString ��ת�����ַ���
	*	@return ����Сд�ַ���
	*	@par ʾ��
	*	@code
	*		std::wstring str=ToLower(L"Abcd");
	*	@endcode
	*/
	static DLL_COMMONLIB_API std::wstring WINAPI ToLower(const std::wstring &srcString);

	/** @brief ת��ΪСд�ַ���
	*	@param [in]	srcString ��ת�����ַ���
	*	@return ����Сд�ַ���
	*	@par ʾ��
	*	@code
	*		std::string str=ToLower(L"Abcd");
	*	@endcode
	*/
	static DLL_COMMONLIB_API std::string WINAPI ToLower(const std::string  &srcString);

	/** @brief ת��Ϊ��д�ַ���
	*	@param [in]	srcString ��ת�����ַ���
	*	@return ���ش�д�ַ���
	*	@par ʾ��
	*	@code
	*		std::wstring str=ToUpper(L"Abcd");
	*	@endcode
	*/
	static DLL_COMMONLIB_API std::wstring WINAPI ToUpper(const std::wstring &srcString);

	/** @brief ת��Ϊ��д�ַ���
	*	@param [in]	srcString ��ת�����ַ���
	*	@return ���ش�д�ַ���
	*	@par ʾ��
	*	@code
	*		std::string str=ToUpper(L"Abcd");
	*	@endcode
	*/
	static DLL_COMMONLIB_API std::string WINAPI ToUpper(const std::string  &srcString);
};


#endif