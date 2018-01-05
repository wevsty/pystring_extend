#if defined(_MSC_VER)
#pragma once
#endif
#ifndef __PYTHON_STRING_FUNCTION_H__
#define __PYTHON_STRING_FUNCTION_H__

#include <algorithm>
#include <cctype>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <cassert>//assert断言
#include <stdexcept>//std except
#include "data_conv.h"
#include "py_string_public_def.h"


//isdecimal() encode decode
namespace pystring_function
{
	//安全转换unsigned到signed
	long_max_t safe_to_sigend_cast(size_t n_input);

	//安全转换signed到unsigned
	std::string::size_type safe_to_unsigend_cast(long_max_t n_input);

	//调整开始和结束下标，主要用于负数时
	void adjust_indices(long_max_t &start, long_max_t &end, long_max_t &len);

	//切片方法
	std::string slice(const std::string &str, long_max_t start = 0,
		long_max_t end = MAX_SIGNED_LONG64_NUM);

	//find() 方法检测字符串(str)中是否包含子字符串(sub)
	//如果指定 beg（开始） 和 end（结束） 范围，则检查是否包含在指定范围内
	//如果包含子字符串返回开始的索引值，否则返回 - 1
	long_max_t find(const std::string &str, const std::string &sub,
		long_max_t start = 0, long_max_t end = MAX_SIGNED_LONG64_NUM);

	//与find()同义
	long_max_t index(const std::string &str, const std::string &sub,
		long_max_t start = 0, long_max_t end = MAX_SIGNED_LONG64_NUM);

	//类似于 find()函数，不过是从右边开始查找
	long_max_t rfind(const std::string &str, const std::string &sub,
		long_max_t start = 0, long_max_t end = MAX_SIGNED_LONG64_NUM);

	//与rfind()同义
	long_max_t rindex(const std::string &str, const std::string &sub,
		long_max_t start = 0, long_max_t end = MAX_SIGNED_LONG64_NUM);

	//把 string 中的 str1 替换成 str2, 如果 count 指定，则替换不超过 count 次.
	std::string replace(const std::string &str, const std::string &oldstr,
		const std::string &newstr, long_max_t count = MAX_SIGNED_LONG64_NUM);

	std::vector<std::string> split_whitespace(const std::string &str,
		long_max_t maxsplit = MAX_SIGNED_LONG64_NUM);

	//字符串分割
	std::vector<std::string> split(const std::string &str,
		const std::string &sep = "",
		long_max_t maxsplit = MAX_SIGNED_LONG64_NUM);

	std::vector<std::string> rsplit_whitespace(const std::string &str,
		long_max_t maxsplit = MAX_SIGNED_LONG64_NUM);

	std::vector<std::string> rsplit(const std::string &str,
		const std::string &sep = "", long_max_t maxsplit = MAX_SIGNED_LONG64_NUM);

	//将序列中的元素以指定的字符连接生成一个新的字符串。
	std::string join(const std::string &str,
		std::vector<std::string> &seq);

	//返回一个3元的元组，第一个为分隔符左边的子串，第二个为分隔符本身，第三个为分隔符右边的子串。
	//"https://baidu.com" -> ('https', '://', 'baidu.com')
	std::vector<std::string> partition(const std::string &str,
		const std::string &sep);

	//类似于partition()函数,不过是从右边开始查找.
	//返回一个3元的元组，第一个为分隔符左边的子串，第二个为分隔符本身，第三个为分隔符右边的子串。
	//"https://baidu.com" -> ('https', '://', 'baidu.com')
	std::vector<std::string> rpartition(const std::string &str,
		const std::string &sep);

	//lstrip() 方法用于截掉字符串左边的空格(包括\t\r\n)或指定字符。
	std::string lstrip(const std::string &str, const std::string &chars = "");

	//rstrip() 方法用于截掉字符串右边的空格(包括\t\r\n)或指定字符。
	std::string rstrip(const std::string &str, const std::string &chars = "");

	//strip() 方法用于截掉字符串两边的空格(包括\t\r\n)或指定字符。
	std::string strip(const std::string &str, const std::string &chars = "");

	//字符串按行分割
	std::vector<std::string> splitlines(const std::string &str_data,
		bool b_keepends = false);

	//字符串大小写翻转
	std::string swapcase(const std::string &old_str);
    
	//翻转字符串
	std::string string_reverse(const std::string &old_str);

	//返回一个首字母大写其他小写的字符串
	//"this IS string" -> "This is string"
	std::string capitalize(const std::string &oldstr);

	//返回一个原字符串居中的新字符串,并使用fillchar(默认空格)填充至长度 width 的新字符串
	//"This is Test." -> "FFFThis is Test.FFFF"
	std::string center(const std::string &str, std::string::size_type width,
		const char fillchar = ' ');

	//返回字符串中指定字符或者字符串的数目。
	//"this is string" -> "is" -> ret 2
	long_max_t count(const std::string &str, const std::string &substr,
		long_max_t start = 0, long_max_t end = MAX_SIGNED_LONG64_NUM);

	//判断字符串结尾是否等于suffix
	bool endswith(const std::string &str, const std::string &suffix,
		long_max_t start = 0, long_max_t end = MAX_SIGNED_LONG64_NUM);

	//判断字符串结尾是否等于prefix
	bool startswith(const std::string &str, const std::string &prefix,
		long_max_t start = 0, long_max_t end = MAX_SIGNED_LONG64_NUM);

	//扩展/t为空格（默认为8个）并保持行末尾对齐
	std::string expandtabs(const std::string &str, int tabsize = 8);

	//如果string至少有一个字符并且所有字符都是字母或数字则返回 true, 否则返回 false
	// "a1"   -> true
	// "a1\n" -> false
	bool isalnum(const std::string &str);

	//如果string至少有一个字符并且所有字符都是字母则返回 true, 否则返回 false
	// "a1\n" -> false
	// "abc" -> true
	bool isalpha(const std::string &str);

	//如果string至少有一个字符并且所有字符都是数字则返回 true, 否则返回 false
	// "-10" -> false
	// "10" -> true
	bool isdigit(const std::string &str);

	//如果string至少有一个字符并且所有字符都是空格（包括\r\n\t\f\v）则返回 true, 否则返回 false
	bool isspace(const std::string &str);

	//检测字符串中所有的单词拼写首字母是否为大写，且其他字母为小写
	//"this is" -> false
	//"This Is" -> true
	bool istitle(const std::string &str);

	//如果string中包含至少一个字母，并且所有字符都是小写，则返回 true，否则返回 false
	//"abc123.0" -> true
	//"A1" -> false
	//"11" -> false
	bool islower(const std::string &str);

	//如果string中包含至少一个字母，并且所有字符都是大写，则返回 true，否则返回 false
	//"ABC123.0" -> true
	//"a1" -> false
	//"11" -> false
	bool isupper(const std::string &str);
    
	//定义ch_tolow函数为了兼容编译器
	inline int ch_tolower(int ch);

	//定义ch_toupper函数为了兼容编译器
	inline int ch_toupper(int ch);
	
	//转换所有字符为小写
	std::string lower(const std::string &str);

	//转换所有字符为大写
	std::string upper(const std::string &str);

	//返回一个原字符串左对齐,并使用空格填充至长度 width 的新字符串
	std::string ljust(const std::string &str, long_max_t width, char fillchar = ' ');

	//返回一个原字符串右对齐,并使用空格填充至长度 width 的新字符串
	std::string rjust(const std::string &str, long_max_t width, char fillchar = ' ');

	//返回"标题化"的 string,就是说所有单词都是以大写开始，其余字母均为小写
	//"This is.no 123" -> "This Is.No 123"
	std::string title(const std::string  &str);

	//从左边开始使用字符0填充至指定长度，返回新字符串使原字符串右对齐。
	//zfill("test",10); -> "000000test"
	std::string zfill(const std::string &str, std::string::size_type width);

	//用于字符映射的转换
	//参数1是被转换的字符串，第2个参数是字符串，表示需要转换的字符，第3个参数是字符串表示转换的目标。
	//两个字符串的长度必须相同，为一一对应的关系。
	//std::string translate("abbc","bc","de") -> "adde"
	std::string translate(const std::string &old_str, const std::string &intab,
		const std::string &outtab);

	//取两个字符串之间的字符串所在的起始位置和长度
	bool between_start_and_end_pos(const std::string &str_data,
		const std::string &str_start,
		const std::string &str_end,
		std::string::size_type &n_start,
		std::string::size_type &n_copylen);

	//取两个字符串之间的字符串
	std::string between_start_and_end_string(const std::string &str_data,
		const std::string &str_start,
		const std::string &str_end = "");
        
	//python风格的字符串格式化
	// format("{} + {} = {}",std::vector<std::string>{"1","2","3"})
	std::string format(std::string format_str, std::vector<std::string> vec_format_list);
}
#endif // !__PYTHON_STRING_FUNCTION_H__
