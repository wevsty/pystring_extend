#if defined(_MSC_VER)
#pragma once
#endif
#ifndef __PYTHON_STRING_CLASS_CPP_H__
#define __PYTHON_STRING_CLASS_CPP_H__

#include "pystring_function.h"
#include "pystring_utf32_function.h"
#include <stdarg.h> // to use va_args ( format )
//#include <algorithm> // transform
#include "base_string_template.h"
class pystring_utf32_class : public u32string_proxy
{
public:

	//复用基类构造函数
	//using u32string_proxy::u32string_proxy;
	//构造函数
	pystring_utf32_class();
	pystring_utf32_class(const std::u32string &u32_input);
	pystring_utf32_class(const std::u32string &&u32_input);
	pystring_utf32_class(const u32string_proxy &u32_input);
	pystring_utf32_class(const u32string_proxy &&u32_input);
	pystring_utf32_class(const pystring_utf32_class &u32_input);
	pystring_utf32_class(const pystring_utf32_class &&u32_input);
	pystring_utf32_class(const std::u32string &str, size_t pos, size_t len = npos);
	pystring_utf32_class(const u32string_proxy &str, size_t pos, size_t len = npos);
	pystring_utf32_class(const pystring_utf32_class &str, size_t pos, size_t len = npos);
	pystring_utf32_class(const char32_t *s);
	pystring_utf32_class(const char32_t *s, size_t n);
	pystring_utf32_class(size_t n, char32_t c);
	//range constructor
	template <class InputIterator>
	pystring_utf32_class(InputIterator first, InputIterator last) : u32string_proxy(first, last)
	{

	}
	pystring_utf32_class(std::initializer_list<char32_t> il);
	pystring_utf32_class(const std::u16string &u16_input);
	pystring_utf32_class(const std::string &u8_input);

#ifdef _MSC_VER
	//On Win wchar_t is 2 bytes
	pystring_utf32_class(const std::wstring &wchar_input);
#elif __GNUC__
	//On Linux wchar_t is 4 bytes
	pystring_utf32_class(const std::wstring &wchar_input);
#endif //_MSC_VER
	virtual ~pystring_utf32_class();

	pystring_utf32_class &operator= (const pystring_utf32_class &str);
	pystring_utf32_class &operator= (const pystring_utf32_class &&str);

	//切片方法
	pystring_utf32_class py_slice(long_max_t start = 0,
		long_max_t end = MAX_SIGNED_LONG64_NUM) const;

	//返回一个首字母大写其他小写的字符串
	//"this IS string" -> "This is string"
	pystring_utf32_class py_capitalize() const;

	//返回一个原字符串居中的新字符串,并使用fillchar(默认空格)填充至长度 width 的新字符串
	//"This is Test." -> "FFFThis is Test.FFFF"
	pystring_utf32_class py_center(std::u32string::size_type width,
		const char32_t fillchar = U' ') const;

	//返回字符串中指定字符或者字符串的数目。
	//"this is string" -> "is" -> ret 2
	long_max_t py_count(const pystring_utf32_class &substr,
		long_max_t start = 0, long_max_t end = MAX_SIGNED_LONG64_NUM) const;

	//判断字符串开头是否等于suffix
	bool py_startswith(const pystring_utf32_class &suffix,
		long_max_t start = 0, long_max_t end = MAX_SIGNED_LONG64_NUM) const;

	//判断字符串结尾是否等于suffix
	bool py_endswith(const pystring_utf32_class &suffix,
		long_max_t start = 0, long_max_t end = MAX_SIGNED_LONG64_NUM) const;

	//扩展/t为空格（默认为8个）并保持行末尾对齐
	pystring_utf32_class py_expandtabs(int tabsize = 8) const;

	//find() 方法检测字符串中是否包含子字符串 substr
	//如果指定 beg（开始） 和 end（结束） 范围，则检查是否包含在指定范围内
	//如果包含子字符串返回开始的索引值，否则返回 - 1
	long_max_t py_find(const pystring_utf32_class &substr,
		long_max_t start = 0, long_max_t end = MAX_SIGNED_LONG64_NUM) const;

	//rfind() 方法从右边开始检测字符串中是否包含子字符串 substr
	//如果指定 beg（开始） 和 end（结束） 范围，则检查是否包含在指定范围内
	//如果包含子字符串返回开始的索引值，否则返回 - 1
	long_max_t py_rfind(const pystring_utf32_class &substr,
		long_max_t start = 0, long_max_t end = MAX_SIGNED_LONG64_NUM) const;

	//index() 方法检测字符串中是否包含子字符串 substr
	//如果指定 beg（开始） 和 end（结束） 范围，则检查是否包含在指定范围内
	//如果包含子字符串返回开始的索引值，否则返回 - 1
	long_max_t py_index(const pystring_utf32_class &substr,
		long_max_t start = 0, long_max_t end = MAX_SIGNED_LONG64_NUM) const;

	//rindex() 方法从右边开始检测字符串中是否包含子字符串 substr
	//如果指定 beg（开始） 和 end（结束） 范围，则检查是否包含在指定范围内
	//如果包含子字符串返回开始的索引值，否则返回 - 1
	long_max_t py_rindex(const pystring_utf32_class &substr,
		long_max_t start = 0, long_max_t end = MAX_SIGNED_LONG64_NUM) const;

	//如果string至少有一个字符并且所有字符都是字母或数字则返回 true, 否则返回 false
	// "a1"   -> true
	// "a1\n" -> false
	bool py_isalnum() const;

	//如果string至少有一个字符并且所有字符都是字母则返回 true, 否则返回 false
	// "a1\n" -> false
	// "abc" -> true
	bool py_isalpha() const;

	//如果string至少有一个字符并且所有字符都是数字则返回 true, 否则返回 false
	// "-10" -> false
	// "10" -> true
	bool py_isdigit() const;

	//如果string中包含至少一个字母，并且所有字符都是小写，则返回 true，否则返回 false
	//"abc123.0" -> true
	//"A1" -> false
	//"11" -> false
	bool py_islower() const;

	//如果string至少有一个字符并且所有字符都是空格（包括\r\n\t\f\v）则返回 true, 否则返回 false
	bool py_isspace() const;

	//检测字符串中所有的单词拼写首字母是否为大写，且其他字母为小写
	//"this is" -> false
	//"This Is" -> true
	bool py_istitle() const;

	//如果string中包含至少一个字母，并且所有字符都是大写，则返回 true，否则返回 false
	//"ABC123.0" -> true
	//"a1" -> false
	//"11" -> false
	bool py_isupper() const;

	//将序列中的元素以指定的字符连接生成一个新的字符串。
	pystring_utf32_class py_join(const std::u32string &str,
		std::vector<std::u32string> &seq) const;

	//将序列中的元素以指定的字符连接生成一个新的字符串。
	pystring_utf32_class py_join(std::vector<std::u32string> &seq) const;

	//将序列中的元素以指定的字符连接生成一个新的字符串。
	pystring_utf32_class py_join(const pystring_utf32_class &str,
		std::vector<pystring_utf32_class> &seq) const;

	//将序列中的元素以指定的字符连接生成一个新的字符串。
	pystring_utf32_class py_join(std::vector<pystring_utf32_class> &seq) const;

	//返回一个原字符串左对齐,并使用空格填充至长度 width 的新字符串
	pystring_utf32_class py_ljust(long_max_t width, char32_t fillchar = U' ') const;

	//返回一个原字符串右对齐,并使用空格填充至长度 width 的新字符串
	pystring_utf32_class py_rjust(long_max_t width, char32_t fillchar = U' ') const;

	//转换所有字符为小写
	pystring_utf32_class py_lower() const;

	//转换所有字符为大写
	pystring_utf32_class py_upper() const;

	//lstrip() 方法用于截掉字符串左边的空格(包括\t\r\n)或指定字符。
	pystring_utf32_class py_lstrip(const pystring_utf32_class &chars = U"") const;

	//rstrip() 方法用于截掉字符串左边的空格(包括\t\r\n)或指定字符。
	pystring_utf32_class py_rstrip(const pystring_utf32_class &chars = U"") const;

	//返回一个3元的元组，第一个为分隔符左边的子串，第二个为分隔符本身，第三个为分隔符右边的子串。
	//"https://baidu.com" -> ('https', '://', 'baidu.com')
	std::vector<pystring_utf32_class> py_partition(const pystring_utf32_class &sep) const;

	//从右边开始返回一个3元的元组，第一个为分隔符左边的子串，第二个为分隔符本身，第三个为分隔符右边的子串。
	//"https://baidu.com" -> ('https', '://', 'baidu.com')
	std::vector<pystring_utf32_class> py_rpartition(const pystring_utf32_class &sep) const;

	//把 string 中的 str1 替换成 str2, 如果 count 指定，则替换不超过 count 次.
	pystring_utf32_class py_replace(const pystring_utf32_class &oldstr,
		const pystring_utf32_class &newstr, long_max_t count = MAX_SIGNED_LONG64_NUM) const;

	//strip() 方法用于截掉字符串两边的空格(包括\t\r\n)或指定字符。
	pystring_utf32_class py_strip(const pystring_utf32_class &chars = U"") const;

	//字符串从右分割
	std::vector<pystring_utf32_class> py_rsplit(const pystring_utf32_class &chars = U""
		, long_max_t maxsplit = MAX_SIGNED_LONG64_NUM) const;

	//字符串分割
	std::vector<pystring_utf32_class> py_split(const pystring_utf32_class &chars = U""
		, long_max_t maxsplit = MAX_SIGNED_LONG64_NUM) const;

	//字符串大小写翻转
	pystring_utf32_class py_swapcase() const;

	//返回"标题化"的 string,就是说所有单词都是以大写开始，其余字母均为小写
	//"This is.no 123" -> "This Is.No 123"
	pystring_utf32_class py_title() const;

	//用于字符映射的转换
	//参数1是被转换的字符串，第2个参数是字符串，表示需要转换的字符，第3个参数是字符串表示转换的目标。
	//两个字符串的长度必须相同，为一一对应的关系。
	//pystring_utf32_class translate("abbc","bc","de") -> "adde"
	pystring_utf32_class py_translate(const pystring_utf32_class &intab,
		const pystring_utf32_class &outtab) const;

	//从左边开始使用字符0填充至指定长度，返回新字符串使原字符串右对齐。
	//zfill("test",10); -> "000000test"
	pystring_utf32_class py_zfill(std::u32string::size_type width) const;

	//python风格的字符串格式化
	// format(U"{} + {} = {}",std::vector<std::u32string>{U"1",U"2",U"3"})
	pystring_utf32_class py_format(const pystring_utf32_class format_str,
		std::vector<std::u32string> vec_format_list) const;

	//python风格的字符串格式化
	// format(U"{} + {} = {}",std::vector<std::u32string>{U"1",U"2",U"3"})
	pystring_utf32_class py_format(const pystring_utf32_class format_str,
		std::vector<pystring_utf32_class> vec_format_list) const;

	//取两个字符串之间的字符串
	pystring_utf32_class py_between_start_and_end_string(const pystring_utf32_class &str_start,
		const pystring_utf32_class &str_end = U"") const;

	//取两个字符串之间的字符串所在的起始位置和长度
	bool py_between_start_and_end_pos(const pystring_utf32_class &str_start,
		const pystring_utf32_class &str_end,
		std::u32string::size_type &n_start,
		std::u32string::size_type &n_copylen) const;

	//转换为整形数字
	long long to_long64() const;

	//转换字符串为浮点数
	long double to_long_double() const;

	//转换整形数字为字符串
	pystring_utf32_class from_long64(long long l64_input);

	//转换浮点数为字符串
	pystring_utf32_class from_long_double(long double ld64_input);

	//转换为pystring_utf32_class
	static pystring_utf32_class to_pystring_utf(long long l64_input);

	static pystring_utf32_class to_pystring_utf(long double ld64_input);

	//to UTF-8
	std::string to_std_string() const;

	//to UTF-16
	std::u16string to_std_u16string() const;

};

class pystring_ext : public std_string_proxy
{
public:
	// basic constructor
	// 基本构造函数
	pystring_ext();
	pystring_ext(const std::string &str_input);
	pystring_ext(const std::string &&str_input);
	pystring_ext(const std_string_proxy &str_input);
	pystring_ext(const std_string_proxy &&str_input);
	pystring_ext(const pystring_ext &str_input);
	pystring_ext(const pystring_ext &&str_input);
	pystring_ext(const std::string &str, size_t pos, size_t len = npos);
	pystring_ext(const std_string_proxy &str, size_t pos, size_t len = npos);
	pystring_ext(const pystring_ext &str, size_t pos, size_t len = npos);
	pystring_ext(const char *s);
	pystring_ext(const char *s, size_t n);
	pystring_ext(size_t n, char c);
	//range constructor
	template <class InputIterator>
	pystring_ext(iterator first, iterator last) : std_string_proxy(first, last)
	{

	}
	pystring_ext(std::initializer_list<char> il);

	virtual ~pystring_ext();

	pystring_ext& operator= (const pystring_ext &str);
	pystring_ext& operator= (const pystring_ext &&str);

	//类型转换模板
	//operator std::string&();
	//operator const std::string&() const;

	//切片方法
	pystring_ext py_slice(long_max_t start,
		long_max_t end = MAX_SIGNED_LONG64_NUM) const;

	//返回一个首字母大写其他小写的字符串
	//"this IS string" -> "This is string"
	pystring_ext py_capitalize() const;

	//返回一个原字符串居中的新字符串,并使用fillchar(默认空格)填充至长度 width 的新字符串
	//"This is Test." -> "FFFThis is Test.FFFF"
	pystring_ext py_center(std::string::size_type width,
		const char fillchar = ' ') const;

	//返回字符串中指定字符或者字符串的数目。
	//"this is string" -> "is" -> ret 2
	long_max_t py_count(const std::string &substr,
		long_max_t start = 0, long_max_t end = MAX_SIGNED_LONG64_NUM) const;

	//判断字符串开头是否等于suffix
	bool py_startswith(const std::string &suffix,
		long_max_t start = 0, long_max_t end = MAX_SIGNED_LONG64_NUM) const;

	//判断字符串结尾是否等于suffix
	bool py_endswith(const std::string &suffix,
		long_max_t start = 0, long_max_t end = MAX_SIGNED_LONG64_NUM) const;

	//扩展/t为空格（默认为8个）并保持行末尾对齐
	pystring_ext py_expandtabs(int tabsize = 8) const;

	//find() 方法检测字符串中是否包含子字符串 substr
	//如果指定 beg（开始） 和 end（结束） 范围，则检查是否包含在指定范围内
	//如果包含子字符串返回开始的索引值，否则返回 - 1
	long_max_t py_find(const std::string &substr,
		long_max_t start = 0, long_max_t end = MAX_SIGNED_LONG64_NUM) const;

	//rfind() 方法从右边开始检测字符串中是否包含子字符串 substr
	//如果指定 beg（开始） 和 end（结束） 范围，则检查是否包含在指定范围内
	//如果包含子字符串返回开始的索引值，否则返回 - 1
	long_max_t py_rfind(const std::string &substr,
		long_max_t start = 0, long_max_t end = MAX_SIGNED_LONG64_NUM) const;

	//index() 方法检测字符串中是否包含子字符串 substr
	//如果指定 beg（开始） 和 end（结束） 范围，则检查是否包含在指定范围内
	//如果包含子字符串返回开始的索引值，否则返回 - 1
	long_max_t py_index(const std::string &substr,
		long_max_t start = 0, long_max_t end = MAX_SIGNED_LONG64_NUM);

	//rindex() 方法从右边开始检测字符串中是否包含子字符串 substr
	//如果指定 beg（开始） 和 end（结束） 范围，则检查是否包含在指定范围内
	//如果包含子字符串返回开始的索引值，否则返回 - 1
	long_max_t py_rindex(const std::string &substr,
		long_max_t start = 0, long_max_t end = MAX_SIGNED_LONG64_NUM);

	//如果string至少有一个字符并且所有字符都是字母或数字则返回 true, 否则返回 false
	// "a1"   -> true
	// "a1\n" -> false
	bool py_isalnum() const;

	//如果string至少有一个字符并且所有字符都是字母则返回 true, 否则返回 false
	// "a1\n" -> false
	// "abc" -> true
	bool py_isalpha() const;

	//如果string至少有一个字符并且所有字符都是数字则返回 true, 否则返回 false
	// "-10" -> false
	// "10" -> true
	bool py_isdigit() const;

	//如果string中包含至少一个字母，并且所有字符都是小写，则返回 true，否则返回 false
	//"abc123.0" -> true
	//"A1" -> false
	//"11" -> false
	bool py_islower() const;

	//如果string至少有一个字符并且所有字符都是空格（包括\r\n\t\f\v）则返回 true, 否则返回 false
	bool py_isspace() const;

	//检测字符串中所有的单词拼写首字母是否为大写，且其他字母为小写
	//"this is" -> false
	//"This Is" -> true
	bool py_istitle() const;

	//如果string中包含至少一个字母，并且所有字符都是大写，则返回 true，否则返回 false
	//"ABC123.0" -> true
	//"a1" -> false
	//"11" -> false
	bool py_isupper() const;

	//将序列中的元素以指定的字符连接生成一个新的字符串。
	pystring_ext py_join(const std::string &str,
		std::vector<std::string> &seq) const;

	//将序列中的元素以指定的字符连接生成一个新的字符串。
	pystring_ext py_join(std::vector<std::string> &seq) const;

	//将序列中的元素以指定的字符连接生成一个新的字符串。
	pystring_ext py_join(const std::string &str,
		std::vector<pystring_ext> &seq) const;

	//将序列中的元素以指定的字符连接生成一个新的字符串。
	pystring_ext py_join(std::vector<pystring_ext> &seq) const;

	//返回一个原字符串左对齐,并使用空格填充至长度 width 的新字符串
	pystring_ext py_ljust(long_max_t width, char fillchar = ' ') const;

	//返回一个原字符串右对齐,并使用空格填充至长度 width 的新字符串
	pystring_ext py_rjust(long_max_t width, char fillchar = ' ') const;

	//转换所有字符为小写
	pystring_ext py_lower() const;

	//转换所有字符为大写
	pystring_ext py_upper() const;

	//lstrip() 方法用于截掉字符串左边的空格(包括\t\r\n)或指定字符。
	pystring_ext py_lstrip(const std::string &chars = "") const;

	//rstrip() 方法用于截掉字符串左边的空格(包括\t\r\n)或指定字符。
	pystring_ext py_rstrip(const std::string &chars = "") const;

	//返回一个3元的元组，第一个为分隔符左边的子串，第二个为分隔符本身，第三个为分隔符右边的子串。
	//"https://baidu.com" -> ('https', '://', 'baidu.com')
	std::vector<pystring_ext> py_partition(const std::string &sep) const;

	//从右边开始返回一个3元的元组，第一个为分隔符左边的子串，第二个为分隔符本身，第三个为分隔符右边的子串。
	//"https://baidu.com" -> ('https', '://', 'baidu.com')
	std::vector<pystring_ext> py_rpartition(const std::string &sep) const;

	//把 string 中的 str1 替换成 str2, 如果 count 指定，则替换不超过 count 次.
	pystring_ext py_replace(const std::string &oldstr,
		const std::string &newstr, long_max_t count = MAX_SIGNED_LONG64_NUM) const;

	//strip() 方法用于截掉字符串两边的空格(包括\t\r\n)或指定字符。
	pystring_ext py_strip(const std::string &chars = "") const;

	//字符串从右分割
	std::vector<pystring_ext> py_rsplit(const std::string &chars = ""
		, long_max_t maxsplit = MAX_SIGNED_LONG64_NUM) const;

	//字符串分割
	std::vector<pystring_ext> py_split(const std::string &chars = ""
		, long_max_t maxsplit = MAX_SIGNED_LONG64_NUM) const;

	//字符串大小写翻转
	pystring_ext py_swapcase() const;

	//返回"标题化"的 string,就是说所有单词都是以大写开始，其余字母均为小写
	//"This is.no 123" -> "This Is.No 123"
	pystring_ext py_title() const;

	//用于字符映射的转换
	//参数1是被转换的字符串，第2个参数是字符串，表示需要转换的字符，第3个参数是字符串表示转换的目标。
	//两个字符串的长度必须相同，为一一对应的关系。
	//pystring_ext translate("abbc","bc","de") -> "adde"
	pystring_ext py_translate(const std::string &intab,
		const std::string &outtab) const;

	//从左边开始使用字符0填充至指定长度，返回新字符串使原字符串右对齐。
	//zfill("test",10); -> "000000test"
	pystring_ext py_zfill(std::string::size_type width) const;

	//python风格的字符串格式化
	// format(U"{} + {} = {}",std::vector<std::string>{U"1",U"2",U"3"})
	pystring_ext py_format(std::string format_str,
		std::vector<std::string> vec_format_list) const;

	//python风格的字符串格式化
	// format(U"{} + {} = {}",std::vector<pystring_ext>{U"1",U"2",U"3"})
	pystring_ext py_format(std::string format_str,
		std::vector<pystring_ext> vec_format_list) const;

	//取两个字符串之间的字符串
	pystring_ext py_between_start_and_end_string(const std::string &str_start,
		const std::string &str_end = "") const;

	//取两个字符串之间的字符串所在的起始位置和长度
	bool py_between_start_and_end_pos(const std::string &str_start,
		const std::string &str_end,
		std::string::size_type &n_start,
		std::string::size_type &n_copylen) const;

	//转换为整形数字
	long long to_long64() const;

	//转换字符串为浮点数
	long double to_long_double() const;

	//转换整形数字为字符串
	pystring_ext from_long64(long long l64_input);

	//转换浮点数为字符串
	pystring_ext from_long_double(long double ld64_input);

	//转换为pystring_ext
	static pystring_ext to_pystring_ext(long long l64_input);

	static pystring_ext to_pystring_ext(long double ld64_input);

	static pystring_ext c_format(const char *format, ...);

	//to_std_string返回一个std::string预防兼容性问题
	std::string to_std_string() const;

	//to UTF-16
	std::u16string to_std_u16string();

	//to UTF-32
	std::u32string to_std_u32string();

};
#endif // !__PYTHON_STRING_CLASS_CPP_H__
