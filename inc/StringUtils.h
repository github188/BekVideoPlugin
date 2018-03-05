#pragma once

#ifndef __STRING_UTILS_H__
#define __STRING_UTILS_H__

#include "DllExport.h"

/**
* @class CStringUtils
* @brief 字符串操作静态类
*
* 用于操作字符串
*/

class CStringUtils
{
public:
	/** @brief 宽字符串转为UTF8编码字符串
	*	@param [in]	 wstr 输入的宽字符串
	*	@param [out] ustr 输出的UTF-8字符串
	*/
	static DLL_COMMONLIB_API void WINAPI Unicode2UTF8(const std::wstring& wstr, std::string& ustr);

	/** @brief 宽字符串转为窄字符串
	*	@param [in]	wstr	输入的宽字符串
	*	@param [out] str	输出窄字符串
	*/
	static DLL_COMMONLIB_API void WINAPI Unicode2ASCII(const std::wstring& wstr, std::string& str);

	/** @brief UTF8字符串转为宽字符串
	*	@param [in]	 ustr 输入的UTF-8字符串
	*	@param [out] wstr 输出的宽字符串
	*/

	static DLL_COMMONLIB_API void WINAPI UTF82Unicode(const std::string& ustr, std::wstring& wstr);


	/** @brief utf8字符串转为窄字符串
	*	@param [in]	 ustr	输入的UTF-8字符串
	*	@param [out] str	输出的窄字符串
	*/
	static DLL_COMMONLIB_API void WINAPI UTF82ASCII(const std::string& ustr, std::string& str);

	/** @brief 窄字符串转为宽字符串
	*	@param [in]	 str	输入的窄字符串
	*	@param [out] wstr	输出的宽字符串
	*/
	static DLL_COMMONLIB_API void WINAPI ASCII2Unicode(const std::string& str, std::wstring& wstr);


	/** @brief 窄字符串转为UTF8字符串
	*	@param [in]	 str	输入的窄字符串
	*	@param [out] ustr	输出的UTF-8字符串
	*/
	static DLL_COMMONLIB_API void WINAPI ASCII2UTF8(const std::string& str, std::string& ustr);


	/** @brief 格式化字符串
	*	@param [in]	 fmt	字符串格式模板
	*	@param [in]  ...	可变参数
	*	@return 返回格式化的字符串
	*	@par 示例
	*	@code
	*		std::string str;
	*		str=Format("1+1=%d",1+1);
	*		//执行后，str的值为 1+1=2
	*	@endcode
	*	字符串格式模板中的可打印类型，可参看如下地址
	*	https://msdn.microsoft.com/en-us/library/hf4y5e3w(v=vs.90).aspx
	*  @warning
	*		在使用该函数时需要主要，如果在格式输出时存在宽->窄字符串转换，同时待转换文字中包含了非ASCII字符，同时未指定语言区域，或语言区域不匹配，会导致转换失效。
	*		如
	@code
	std::string str;
	str=StringUtil::Format("宽字符[%S]",L"中文");
	//转换后str的值为""
	//如果程序设置了语言，如初始化时调用了setlocale(LC_ALL,"chs");
	//则转换后的str值为"宽字符[中文]"
	str=StringUtil::Format("宽字符[%S]",L"AAA");
	//如果是该形式则不影响,因为待转换的文字仅包含ASCII字符
	@endcode
	*/
	static DLL_COMMONLIB_API std::string WINAPI Format(const char *fmt, ...);

	/** @brief 格式化字符串
	*	@param [in]	 fmt	字符串格式模板
	*	@param [in]  ...	可变参数
	*	@return 返回格式化的字符串
	*	字符串格式模板中的可打印类型，可参看如下地址
	*	https://msdn.microsoft.com/en-us/library/hf4y5e3w(v=vs.90).aspx
	*	@par 示例
	*	@code
	*		std::wstring str;
	*		str=Format(L"1+1=%d",1+1);
	*		//执行后，str的值为 1+1=2
	*	@endcode
	*/
	static DLL_COMMONLIB_API std::wstring WINAPI Format(const wchar_t *fmt, ...);

	/** @brief 除去字符串开头和末尾的空格
	*	@param [in]	 str	字符串格式模板
	*	@return 返回修整后的字符串
	*/
	static DLL_COMMONLIB_API void WINAPI TrimString(std::string& str);

	/** @brief 除去字符串开头和末尾的空格
	*	@param [in]	 str	字符串格式模板
	*	@return 返回修整后的字符串
	*/
	static DLL_COMMONLIB_API void WINAPI TrimString(std::wstring& str);

	/** @brief 宽字符转为窄字符
	*	@param [in]	ws	输入的宽字符串
	*	@param [in] codepage 输入需要转换成的字符编码
	*	@return	返回窄字符串
	*/
	static DLL_COMMONLIB_API std::string WINAPI Convert(const std::wstring& ws, UINT codepage = CP_UTF8);

	/** @brief 窄字符转为宽字符
	*	@param [in]	s	输入的窄字符串
	*	@param [in] codepage 输入当前窄字符的编码
	*	@return	返回宽字符串
	*/
	static DLL_COMMONLIB_API std::wstring WINAPI Convert(const std::string& s, UINT codepage = CP_UTF8);

	/** @brief 字符串替换，将字符中特定的内容更换指定的内容
	*	@param [in,out]	str 需要转换的字符串
	*	@param [in] old_Value 输入需要转换的子字符串
	*	@param [in] new_Value 输入需要替换为的字符串
	*	@par 示例
	*	@code
	*		std::string str="&123&456&abc";
	*		ReplaceAllString(str,"&","#");
	*		//执行后，str将被修改为#123#456#abc
	*	@endcode
	*/
	static DLL_COMMONLIB_API void WINAPI ReplaceAllString(std::string& str, const std::string& old_Value, const std::string& new_Value);

	/** @brief 字符串替换，将字符中特定的内容更换指定的内容
	*	@param [in,out]	str 需要转换的字符串
	*	@param [in] old_Value 输入需要转换的子字符串
	*	@param [in] new_Value 输入需要替换为的字符串
	*	@par 示例
	*	@code
	*		std::wstring str=L"&123&456&abc";
	*		ReplaceAllString(str,L"&",L"#");
	*		//执行后，str将被修改为#123#456#abc
	*	@endcode
	*/
	static DLL_COMMONLIB_API void WINAPI ReplaceAllString(std::wstring& str, const std::wstring& old_Value, const std::wstring& new_Value);

	/** @brief 字符串分割
	*	@param [in]	srcString 待切割的字符串
	*	@param [in] separator 使用的分割元素
	*	@param [out] strList  输出的分割后的字符串列表
	*	@par 示例
	*	@code
	*		std::vector<string> strarry;
	*		SplitString("a|bc||123","|",strarry);
	*		//此时将会对 对该字符串 按 "|" 进行分割。分割完后结果为 a、b、123 3个字符串
	*	@endcode
	*/
	static DLL_COMMONLIB_API void WINAPI SplitString(const std::string &srcString, const std::string &separator, std::vector<std::string> &strList);


	/** @brief 字符串分割
	*	@param [in]	srcString 待切割的字符串
	*	@param [in] separator 使用的分割元素
	*	@param [out] strList  输出的分割后的字符串列表
	*	@par 示例
	*	@code
	*		std::vector<wstring> strarry;
	*		SplitString(L"a|bc||123",L"|",strarry);
	*		//此时将会对 对该字符串 按 "|" 进行分割。分割完后结果为 a、b、123 3个字符串
	*	@endcode
	*/
	static DLL_COMMONLIB_API void WINAPI SplitString(const std::wstring &srcString, const std::wstring &separator, std::vector<std::wstring> &strList);



	/** @brief 转换为小写字符串
	*	@param [in]	srcString 待转换的字符串
	*	@return 返回小写字符串
	*	@par 示例
	*	@code
	*		std::wstring str=ToLower(L"Abcd");
	*	@endcode
	*/
	static DLL_COMMONLIB_API std::wstring WINAPI ToLower(const std::wstring &srcString);

	/** @brief 转换为小写字符串
	*	@param [in]	srcString 待转换的字符串
	*	@return 返回小写字符串
	*	@par 示例
	*	@code
	*		std::string str=ToLower(L"Abcd");
	*	@endcode
	*/
	static DLL_COMMONLIB_API std::string WINAPI ToLower(const std::string  &srcString);

	/** @brief 转换为大写字符串
	*	@param [in]	srcString 待转换的字符串
	*	@return 返回大写字符串
	*	@par 示例
	*	@code
	*		std::wstring str=ToUpper(L"Abcd");
	*	@endcode
	*/
	static DLL_COMMONLIB_API std::wstring WINAPI ToUpper(const std::wstring &srcString);

	/** @brief 转换为大写字符串
	*	@param [in]	srcString 待转换的字符串
	*	@return 返回大写字符串
	*	@par 示例
	*	@code
	*		std::string str=ToUpper(L"Abcd");
	*	@endcode
	*/
	static DLL_COMMONLIB_API std::string WINAPI ToUpper(const std::string  &srcString);
};


#endif