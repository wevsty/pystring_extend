
#include "pystring_class.h"
#include "pystring_function.h"
#include "pystring_utf32_function.h"
#include <stdarg.h> // to use va_args ( format )
//#include <algorithm> // transform

pystring_utf32_class::pystring_utf32_class() : u32string_proxy()
{
}

pystring_utf32_class::pystring_utf32_class(const std::u32string & u32_input) : u32string_proxy(u32_input)
{
}

pystring_utf32_class::pystring_utf32_class(const std::u32string && u32_input) : u32string_proxy(u32_input)
{
}

pystring_utf32_class::pystring_utf32_class(const u32string_proxy & u32_input) : u32string_proxy(u32_input)
{
}

pystring_utf32_class::pystring_utf32_class(const u32string_proxy && u32_input) : u32string_proxy(u32_input)
{
}

pystring_utf32_class::pystring_utf32_class(const pystring_utf32_class & u32_input) : u32string_proxy(u32_input)
{
}

pystring_utf32_class::pystring_utf32_class(const pystring_utf32_class && u32_input) : u32string_proxy(u32_input)
{
}

pystring_utf32_class::pystring_utf32_class(const std::u32string &str, size_t pos, size_t len)
	: u32string_proxy(str, pos, len)
{
}

pystring_utf32_class::pystring_utf32_class(const u32string_proxy &str, size_t pos, size_t len)
	: u32string_proxy(str, pos, len)
{
}

pystring_utf32_class::pystring_utf32_class(const pystring_utf32_class &str, size_t pos, size_t len)
	: u32string_proxy(str.var_container, pos, len)
{
}

pystring_utf32_class::pystring_utf32_class(const char32_t *s) : u32string_proxy(s)
{
}

pystring_utf32_class::pystring_utf32_class(const char32_t *s, size_t n) : u32string_proxy(s, n)
{
}

pystring_utf32_class::pystring_utf32_class(size_t n, char32_t c) : u32string_proxy(n, c)
{
}

pystring_utf32_class::pystring_utf32_class(std::initializer_list<char32_t> il) : u32string_proxy(il)
{
}

pystring_utf32_class::pystring_utf32_class(const std::u16string &u16_input)
{
	uft_conv::utf16_to_utf32(u16_input, var_container);
}

pystring_utf32_class::pystring_utf32_class(const std::string &u8_input)
{
	uft_conv::utf8_to_utf32(u8_input, var_container);
}
/*
pystring_utf32_class::pystring_utf32_class(const char *u8_input)
{
uft_conv::utf8_to_utf32(u8_input, var_container);
}
*/
#ifdef _MSC_VER
//On Win wchar_t is 2 bytes
pystring_utf32_class::pystring_utf32_class(const std::wstring &wchar_input)
{
	std::u16string u16_str = uft_conv::wstring_to_u16string(wchar_input);
	uft_conv::utf16_to_utf32(u16_str, var_container);
}
#elif __GNUC__
//On Linux wchar_t is 4 bytes
pystring_utf32_class::pystring_utf32_class(const std::wstring &wchar_input)
{
	var_container = uft_conv::wstring_to_u32string(wchar_input);
}
#endif //_MSC_VER
pystring_utf32_class::~pystring_utf32_class()
{
	//生成虚析构函数，方便自行继承修改
}

pystring_utf32_class & pystring_utf32_class::operator= (const pystring_utf32_class &str)
{
	var_container = str.var_container;
	return *this;
}

pystring_utf32_class & pystring_utf32_class::operator= (const pystring_utf32_class &&str)
{
	var_container = str.var_container;
	return *this;
}

//切片方法
pystring_utf32_class pystring_utf32_class::py_slice(long_max_t start,
	long_max_t end) const
{
	return pystring_utf32::slice(var_container, start, end);
}

//返回一个首字母大写其他小写的字符串
//"this IS string" -> "This is string"
pystring_utf32_class pystring_utf32_class::py_capitalize() const
{
	return pystring_utf32::capitalize(var_container);
}

//返回一个原字符串居中的新字符串,并使用fillchar(默认空格)填充至长度 width 的新字符串
//"This is Test." -> "FFFThis is Test.FFFF"
pystring_utf32_class pystring_utf32_class::py_center(std::u32string::size_type width,
	const char32_t fillchar) const
{
	return pystring_utf32::center(var_container, width, fillchar);
}

//返回字符串中指定字符或者字符串的数目。
//"this is string" -> "is" -> ret 2
long_max_t pystring_utf32_class::py_count(const pystring_utf32_class &substr,
	long_max_t start, long_max_t end) const
{
	return pystring_utf32::count(var_container, substr.var_container, start, end);
}

//判断字符串开头是否等于suffix
bool pystring_utf32_class::py_startswith(const pystring_utf32_class &suffix,
	long_max_t start, long_max_t end) const
{
	return pystring_utf32::startswith(var_container, suffix.var_container, start, end);
}

//判断字符串结尾是否等于suffix
bool pystring_utf32_class::py_endswith(const pystring_utf32_class &suffix,
	long_max_t start, long_max_t end) const
{
	return pystring_utf32::endswith(var_container, suffix.var_container, start, end);
}

//扩展/t为空格（默认为8个）并保持行末尾对齐
pystring_utf32_class pystring_utf32_class::py_expandtabs(int tabsize) const
{
	return pystring_utf32::expandtabs(var_container, tabsize);
}

//find() 方法检测字符串中是否包含子字符串 substr
//如果指定 beg（开始） 和 end（结束） 范围，则检查是否包含在指定范围内
//如果包含子字符串返回开始的索引值，否则返回 - 1
long_max_t pystring_utf32_class::py_find(const pystring_utf32_class &substr,
	long_max_t start, long_max_t end) const
{
	return pystring_utf32::find(var_container, substr.var_container, start, end);
}

//rfind() 方法从右边开始检测字符串中是否包含子字符串 substr
//如果指定 beg（开始） 和 end（结束） 范围，则检查是否包含在指定范围内
//如果包含子字符串返回开始的索引值，否则返回 - 1
long_max_t pystring_utf32_class::py_rfind(const pystring_utf32_class &substr,
	long_max_t start, long_max_t end) const
{
	return pystring_utf32::rfind(var_container, substr.var_container, start, end);
}

//index() 方法检测字符串中是否包含子字符串 substr
//如果指定 beg（开始） 和 end（结束） 范围，则检查是否包含在指定范围内
//如果包含子字符串返回开始的索引值，否则返回 - 1
long_max_t pystring_utf32_class::py_index(const pystring_utf32_class &substr,
	long_max_t start, long_max_t end) const
{
	return pystring_utf32::index(var_container, substr.var_container, start, end);
}

//rindex() 方法从右边开始检测字符串中是否包含子字符串 substr
//如果指定 beg（开始） 和 end（结束） 范围，则检查是否包含在指定范围内
//如果包含子字符串返回开始的索引值，否则返回 - 1
long_max_t pystring_utf32_class::py_rindex(const pystring_utf32_class &substr,
	long_max_t start, long_max_t end) const
{
	return pystring_utf32::rindex(var_container, substr.var_container, start, end);
}

//如果string至少有一个字符并且所有字符都是字母或数字则返回 true, 否则返回 false
// "a1"   -> true
// "a1\n" -> false
bool pystring_utf32_class::py_isalnum() const
{
	return pystring_utf32::isalnum(var_container);
}

//如果string至少有一个字符并且所有字符都是字母则返回 true, 否则返回 false
// "a1\n" -> false
// "abc" -> true
bool pystring_utf32_class::py_isalpha() const
{
	return pystring_utf32::isalpha(var_container);
}

//如果string至少有一个字符并且所有字符都是数字则返回 true, 否则返回 false
// "-10" -> false
// "10" -> true
bool pystring_utf32_class::py_isdigit() const
{
	return pystring_utf32::isdigit(var_container);
}

//如果string中包含至少一个字母，并且所有字符都是小写，则返回 true，否则返回 false
//"abc123.0" -> true
//"A1" -> false
//"11" -> false
bool pystring_utf32_class::py_islower() const
{
	return pystring_utf32::isdigit(var_container);
}

//如果string至少有一个字符并且所有字符都是空格（包括\r\n\t\f\v）则返回 true, 否则返回 false
bool pystring_utf32_class::py_isspace() const
{
	return pystring_utf32::isspace(var_container);
}

//检测字符串中所有的单词拼写首字母是否为大写，且其他字母为小写
//"this is" -> false
//"This Is" -> true
bool pystring_utf32_class::py_istitle() const
{
	return pystring_utf32::istitle(var_container);
}

//如果string中包含至少一个字母，并且所有字符都是大写，则返回 true，否则返回 false
//"ABC123.0" -> true
//"a1" -> false
//"11" -> false
bool pystring_utf32_class::py_isupper() const
{
	return pystring_utf32::isupper(var_container);
}

//将序列中的元素以指定的字符连接生成一个新的字符串。
pystring_utf32_class pystring_utf32_class::py_join(const std::u32string &str,
	std::vector<std::u32string> &seq) const
{
	return pystring_utf32::join(str, seq);
}

//将序列中的元素以指定的字符连接生成一个新的字符串。
pystring_utf32_class pystring_utf32_class::py_join(std::vector<std::u32string> &seq) const
{
	return pystring_utf32::join(var_container, seq);
}

//将序列中的元素以指定的字符连接生成一个新的字符串。
pystring_utf32_class pystring_utf32_class::py_join(const pystring_utf32_class &str,
	std::vector<pystring_utf32_class> &seq) const
{
	std::vector<std::u32string> vec_tmp(to_vector_std_u32string(seq));
	return pystring_utf32::join(str.var_container, vec_tmp);
}

//将序列中的元素以指定的字符连接生成一个新的字符串。
pystring_utf32_class pystring_utf32_class::py_join(std::vector<pystring_utf32_class> &seq) const
{
	std::vector<std::u32string> vec_tmp(to_vector_std_u32string(seq));
	return pystring_utf32::join(var_container, vec_tmp);
}

//返回一个原字符串左对齐,并使用空格填充至长度 width 的新字符串
pystring_utf32_class pystring_utf32_class::py_ljust(long_max_t width, char32_t fillchar) const
{
	return pystring_utf32::ljust(var_container, width, fillchar);
}

//返回一个原字符串右对齐,并使用空格填充至长度 width 的新字符串
pystring_utf32_class pystring_utf32_class::py_rjust(long_max_t width, char32_t fillchar) const
{
	return pystring_utf32::rjust(var_container, width, fillchar);
}

//转换所有字符为小写
pystring_utf32_class pystring_utf32_class::py_lower() const
{
	return pystring_utf32::lower(var_container);
}

//转换所有字符为大写
pystring_utf32_class pystring_utf32_class::py_upper() const
{
	return pystring_utf32::upper(var_container);
}

//lstrip() 方法用于截掉字符串左边的空格(包括\t\r\n)或指定字符。
pystring_utf32_class pystring_utf32_class::py_lstrip(const pystring_utf32_class &chars) const
{
	return pystring_utf32::lstrip(var_container, chars.var_container);
}

//rstrip() 方法用于截掉字符串左边的空格(包括\t\r\n)或指定字符。
pystring_utf32_class pystring_utf32_class::py_rstrip(const pystring_utf32_class &chars) const
{
	return pystring_utf32::rstrip(var_container, chars.var_container);
}

//返回一个3元的元组，第一个为分隔符左边的子串，第二个为分隔符本身，第三个为分隔符右边的子串。
//"https://baidu.com" -> ('https', '://', 'baidu.com')
std::vector<pystring_utf32_class> pystring_utf32_class::py_partition(const pystring_utf32_class &sep)
const
{
	std::vector<std::u32string> vec_tmp(pystring_utf32::partition(var_container,
		sep.var_container));
	return to_vector_utfpystring(vec_tmp);
}

//从右边开始返回一个3元的元组，第一个为分隔符左边的子串，第二个为分隔符本身，第三个为分隔符右边的子串。
//"https://baidu.com" -> ('https', '://', 'baidu.com')
std::vector<pystring_utf32_class> pystring_utf32_class::py_rpartition(const pystring_utf32_class &sep)
const
{
	std::vector<std::u32string> vec_tmp(pystring_utf32::rpartition(var_container,
		sep.var_container));
	return to_vector_utfpystring(vec_tmp);
}

//把 string 中的 str1 替换成 str2, 如果 count 指定，则替换不超过 count 次.
pystring_utf32_class pystring_utf32_class::py_replace(const pystring_utf32_class &oldstr,
	const pystring_utf32_class &newstr, long_max_t count) const
{
	return pystring_utf32::replace(var_container, oldstr.var_container, newstr.var_container,
		count);
}

//strip() 方法用于截掉字符串两边的空格(包括\t\r\n)或指定字符。
pystring_utf32_class pystring_utf32_class::py_strip(const pystring_utf32_class &chars) const
{
	return pystring_utf32::strip(var_container, chars.var_container);
}

//字符串从右分割
std::vector<pystring_utf32_class> pystring_utf32_class::py_rsplit(const pystring_utf32_class &chars
	, long_max_t maxsplit) const
{
	std::vector<std::u32string> vec_tmp(pystring_utf32::rsplit(var_container,
		chars.var_container, maxsplit));
	return to_vector_utfpystring(vec_tmp);
}

//字符串分割
std::vector<pystring_utf32_class> pystring_utf32_class::py_split(const pystring_utf32_class &chars
	, long_max_t maxsplit) const
{
	std::vector<std::u32string> vec_tmp(pystring_utf32::split(var_container,
		chars.var_container, maxsplit));
	return to_vector_utfpystring(vec_tmp);
}

//字符串大小写翻转
pystring_utf32_class pystring_utf32_class::py_swapcase() const
{
	return pystring_utf32::swapcase(var_container);
}

//返回"标题化"的 string,就是说所有单词都是以大写开始，其余字母均为小写
//"This is.no 123" -> "This Is.No 123"
pystring_utf32_class pystring_utf32_class::py_title() const
{
	return pystring_utf32::title(var_container);
}

//用于字符映射的转换
//参数1是被转换的字符串，第2个参数是字符串，表示需要转换的字符，第3个参数是字符串表示转换的目标。
//两个字符串的长度必须相同，为一一对应的关系。
//pystring_utf32_class translate("abbc","bc","de") -> "adde"
pystring_utf32_class pystring_utf32_class::py_translate(const pystring_utf32_class &intab,
	const pystring_utf32_class &outtab) const
{
	return pystring_utf32::translate(var_container, intab.var_container, outtab.var_container);
}

//从左边开始使用字符0填充至指定长度，返回新字符串使原字符串右对齐。
//zfill("test",10); -> "000000test"
pystring_utf32_class pystring_utf32_class::py_zfill(std::u32string::size_type width) const
{
	return pystring_utf32::zfill(var_container, width);
}

//python风格的字符串格式化
// format(U"{} + {} = {}",std::vector<pystring_utf32_class>{U"1",U"2",U"3"})
pystring_utf32_class pystring_utf32_class::py_format(const pystring_utf32_class format_str,
	std::vector<pystring_utf32_class> vec_format_list) const
{
	std::vector<std::u32string> vec_tmp(to_vector_std_u32string(vec_format_list));
	return pystring_utf32::format(format_str.var_container, vec_tmp);
}

//取两个字符串之间的字符串
pystring_utf32_class pystring_utf32_class::py_between_start_and_end_string(const pystring_utf32_class
	&str_start,
	const pystring_utf32_class &str_end) const
{
	return pystring_utf32::between_start_and_end_string(var_container,
		str_start.var_container,
		str_end.var_container);
}

//取两个字符串之间的字符串所在的起始位置和长度
bool pystring_utf32_class::py_between_start_and_end_pos(const pystring_utf32_class &str_start,
	const pystring_utf32_class &str_end,
	std::u32string::size_type &n_start,
	std::u32string::size_type &n_copylen) const
{
	return pystring_utf32::between_start_and_end_pos(var_container, str_start.var_container,
		str_end.var_container,
		n_start, n_copylen);
}

//转换为整形数字
long long pystring_utf32_class::to_long64() const
{
	return convert_type::to_long64(var_container);
}

//转换字符串为浮点数
long double pystring_utf32_class::to_long_double() const
{
	return convert_type::to_long_double(var_container);
}

//转换整形数字为字符串
pystring_utf32_class pystring_utf32_class::from_long64(long long l64_input)
{
	var_container = convert_type::long64_to_u32string(l64_input);
	return *this;
}

//转换浮点数为字符串
pystring_utf32_class pystring_utf32_class::from_long_double(long double ld64_input)
{
	var_container = convert_type::long_double_to_u32string(ld64_input);
	return *this;
}

//转换为pystring_utf32_class
pystring_utf32_class pystring_utf32_class::to_pystring_utf(long long l64_input)
{
	return convert_type::long64_to_u32string(l64_input);
}

pystring_utf32_class pystring_utf32_class::to_pystring_utf(long double ld64_input)
{
	return convert_type::long_double_to_u32string(ld64_input);
}

//to UTF-8
std::string pystring_utf32_class::to_std_string() const
{
	std::string str_ret;
	uft_conv::utf32_to_utf8(var_container, str_ret);
	return str_ret;
}

//to UTF-16
std::u16string pystring_utf32_class::to_std_u16string() const
{
	std::u16string str_ret;
	uft_conv::utf32_to_utf16(var_container, str_ret);
	return str_ret;
}

//std::vector<std::u32string>转换为std::vector<pystring_utf32_class>
std::vector<pystring_utf32_class> pystring_utf32_class::to_vector_utfpystring(
	std::vector<std::u32string> &vec_str) const
{
	std::vector<pystring_utf32_class> vec_ret;
	size_t n_vec_str_size = vec_str.size();
	vec_ret.resize(n_vec_str_size);
	for (size_t i = 0; i < n_vec_str_size; i++)
	{
		vec_ret[i] = std::move(vec_str[i]);
	}
	return vec_ret;
}
//std::vector<pystring_utf32_class>转换为std::vector<std::u32string>
std::vector<std::u32string> pystring_utf32_class::to_vector_std_u32string(
	std::vector<pystring_utf32_class> &vec_utfstr) const
{
	std::vector<std::u32string> vec_ret;
	size_t n_vec_str_size = vec_utfstr.size();
	vec_ret.resize(n_vec_str_size);
	for (size_t i = 0; i < n_vec_str_size; i++)
	{
		vec_ret[i] = std::move(vec_utfstr[i].var_container);
	}
	return vec_ret;
}

//pystring_ext
// basic constructor
// 基本构造函数
pystring_ext::pystring_ext() : std_string_proxy()
{

}

pystring_ext::pystring_ext(const std::string &str_input) : std_string_proxy(str_input)
{

}

pystring_ext::pystring_ext(const std::string &&str_input) : std_string_proxy(str_input)
{

}

pystring_ext::pystring_ext(const std_string_proxy &str_input) : std_string_proxy(str_input)
{

}

pystring_ext::pystring_ext(const std_string_proxy &&str_input) : std_string_proxy(str_input)
{

}

pystring_ext::pystring_ext(const pystring_ext &str_input) : std_string_proxy(str_input)
{

}

pystring_ext::pystring_ext(const pystring_ext &&str_input) : std_string_proxy(str_input)
{

}

pystring_ext::pystring_ext(const std::string &str, size_t pos, size_t len)
	: std_string_proxy(str, pos,len)
{

}

pystring_ext::pystring_ext(const std_string_proxy &str, size_t pos, size_t len)
	: std_string_proxy(str, pos, len)
{

}

pystring_ext::pystring_ext(const pystring_ext &str, size_t pos, size_t len)
	: std_string_proxy(str, pos, len)
{

}

pystring_ext::pystring_ext(const char *s) : std_string_proxy(s)
{

}

pystring_ext::pystring_ext(const char *s, size_t n) : std_string_proxy(s, n)
{

}

pystring_ext::pystring_ext(size_t n, char c) : std_string_proxy(n,c)
{

}
//range constructor skip

pystring_ext::pystring_ext(std::initializer_list<char> il) : std_string_proxy(il)
{

}

pystring_ext::~pystring_ext()
{

}

pystring_ext& pystring_ext::operator= (const pystring_ext &str)
{
	var_container = str.var_container;
	return *this;
}

pystring_ext& pystring_ext::operator= (const pystring_ext &&str)
{
	var_container = str.var_container;
	return *this;
}
/*
//类型转换
pystring_ext::operator std::string&()
{
	return var_container;
}

pystring_ext::operator const std::string&() const
{
	return var_container;
}
*/

//切片方法
pystring_ext pystring_ext::py_slice(long_max_t start,
	long_max_t end) const
{
	return pystring_function::slice(var_container, start, end);
}

//返回一个首字母大写其他小写的字符串
//"this IS string" -> "This is string"
pystring_ext pystring_ext::py_capitalize() const
{
	return pystring_function::capitalize(var_container);
}

//返回一个原字符串居中的新字符串,并使用fillchar(默认空格)填充至长度 width 的新字符串
//"This is Test." -> "FFFThis is Test.FFFF"
pystring_ext pystring_ext::py_center(std::string::size_type width,
	const char fillchar)const
{
	return pystring_function::center(var_container, width, fillchar);
}

//返回字符串中指定字符或者字符串的数目。
//"this is string" -> "is" -> ret 2
long_max_t pystring_ext::py_count(const std::string &substr,
	long_max_t start, long_max_t end) const
{
	return pystring_function::count(var_container, substr, start, end);
}

//判断字符串开头是否等于suffix
bool pystring_ext::py_startswith(const std::string &suffix,
	long_max_t start, long_max_t end) const
{
	return pystring_function::startswith(var_container, suffix, start, end);
}

//判断字符串结尾是否等于suffix
bool pystring_ext::py_endswith(const std::string &suffix,
	long_max_t start, long_max_t end) const
{
	return pystring_function::endswith(var_container, suffix, start, end);
}

//扩展/t为空格（默认为8个）并保持行末尾对齐
pystring_ext pystring_ext::py_expandtabs(int tabsize) const
{
	return pystring_function::expandtabs(var_container, tabsize);
}

//find() 方法检测字符串中是否包含子字符串 substr
//如果指定 beg（开始） 和 end（结束） 范围，则检查是否包含在指定范围内
//如果包含子字符串返回开始的索引值，否则返回 - 1
long_max_t pystring_ext::py_find(const std::string &substr,
	long_max_t start, long_max_t end) const
{
	return pystring_function::find(var_container, substr, start, end);
}

//rfind() 方法从右边开始检测字符串中是否包含子字符串 substr
//如果指定 beg（开始） 和 end（结束） 范围，则检查是否包含在指定范围内
//如果包含子字符串返回开始的索引值，否则返回 - 1
long_max_t pystring_ext::py_rfind(const std::string &substr,
	long_max_t start, long_max_t end) const
{
	return pystring_function::rfind(var_container, substr, start, end);
}

//index() 方法检测字符串中是否包含子字符串 substr
//如果指定 beg（开始） 和 end（结束） 范围，则检查是否包含在指定范围内
//如果包含子字符串返回开始的索引值，否则返回 - 1
long_max_t pystring_ext::py_index(const std::string &substr,
	long_max_t start, long_max_t end)
{
	return pystring_function::index(var_container, substr, start, end);
}

//rindex() 方法从右边开始检测字符串中是否包含子字符串 substr
//如果指定 beg（开始） 和 end（结束） 范围，则检查是否包含在指定范围内
//如果包含子字符串返回开始的索引值，否则返回 - 1
long_max_t pystring_ext::py_rindex(const std::string &substr,
	long_max_t start, long_max_t end)
{
	return pystring_function::rindex(var_container, substr, start, end);
}

//如果string至少有一个字符并且所有字符都是字母或数字则返回 true, 否则返回 false
// "a1"   -> true
// "a1\n" -> false
bool pystring_ext::py_isalnum() const
{
	return pystring_function::isalnum(var_container);
}

//如果string至少有一个字符并且所有字符都是字母则返回 true, 否则返回 false
// "a1\n" -> false
// "abc" -> true
bool pystring_ext::py_isalpha() const
{
	return pystring_function::isalpha(var_container);
}

//如果string至少有一个字符并且所有字符都是数字则返回 true, 否则返回 false
// "-10" -> false
// "10" -> true
bool pystring_ext::py_isdigit() const
{
	return pystring_function::isdigit(var_container);
}

//如果string中包含至少一个字母，并且所有字符都是小写，则返回 true，否则返回 false
//"abc123.0" -> true
//"A1" -> false
//"11" -> false
bool pystring_ext::py_islower() const
{
	return pystring_function::isdigit(var_container);
}

//如果string至少有一个字符并且所有字符都是空格（包括\r\n\t\f\v）则返回 true, 否则返回 false
bool pystring_ext::py_isspace() const
{
	return pystring_function::isspace(var_container);
}

//检测字符串中所有的单词拼写首字母是否为大写，且其他字母为小写
//"this is" -> false
//"This Is" -> true
bool pystring_ext::py_istitle() const
{
	return pystring_function::istitle(var_container);
}

//如果string中包含至少一个字母，并且所有字符都是大写，则返回 true，否则返回 false
//"ABC123.0" -> true
//"a1" -> false
//"11" -> false
bool pystring_ext::py_isupper() const
{
	return pystring_function::isupper(var_container);
}

//将序列中的元素以指定的字符连接生成一个新的字符串。
pystring_ext pystring_ext::py_join(const std::string &str,
	std::vector<std::string> &seq) const
{
	return pystring_function::join(str, seq);
}

//将序列中的元素以指定的字符连接生成一个新的字符串。
pystring_ext pystring_ext::py_join(std::vector<std::string> &seq) const
{
	return pystring_function::join(var_container, seq);
}

//将序列中的元素以指定的字符连接生成一个新的字符串。
pystring_ext pystring_ext::py_join(const std::string &str,
	std::vector<pystring_ext> &seq) const
{
	std::vector<std::string> vec_tmp(to_vector_std_string(seq));
	return pystring_function::join(str, vec_tmp);
}

//将序列中的元素以指定的字符连接生成一个新的字符串。
pystring_ext pystring_ext::py_join(std::vector<pystring_ext> &seq) const
{
	std::vector<std::string> vec_tmp(to_vector_std_string(seq));
	return pystring_function::join(var_container, vec_tmp);
}

//返回一个原字符串左对齐,并使用空格填充至长度 width 的新字符串
pystring_ext pystring_ext::py_ljust(long_max_t width, char fillchar) const
{
	return pystring_function::ljust(var_container, width, fillchar);
}

//返回一个原字符串右对齐,并使用空格填充至长度 width 的新字符串
pystring_ext pystring_ext::py_rjust(long_max_t width, char fillchar) const
{
	return pystring_function::rjust(var_container, width, fillchar);
}

//转换所有字符为小写
pystring_ext pystring_ext::py_lower() const
{
	return pystring_function::lower(var_container);
}

//转换所有字符为大写
pystring_ext pystring_ext::py_upper() const
{
	return pystring_function::upper(var_container);
}

//lstrip() 方法用于截掉字符串左边的空格(包括\t\r\n)或指定字符。
pystring_ext pystring_ext::py_lstrip(const std::string &chars) const
{
	return pystring_function::lstrip(var_container, chars);
}

//rstrip() 方法用于截掉字符串左边的空格(包括\t\r\n)或指定字符。
pystring_ext pystring_ext::py_rstrip(const std::string &chars) const
{
	return pystring_function::rstrip(var_container, chars);
}

//返回一个3元的元组，第一个为分隔符左边的子串，第二个为分隔符本身，第三个为分隔符右边的子串。
//"https://baidu.com" -> ('https', '://', 'baidu.com')
std::vector<pystring_ext> pystring_ext::py_partition(const std::string &sep)
const
{
	std::vector<std::string> vec_tmp(pystring_function::partition(var_container, sep));
	return to_vector_pystring_ext(vec_tmp);
}

//从右边开始返回一个3元的元组，第一个为分隔符左边的子串，第二个为分隔符本身，第三个为分隔符右边的子串。
//"https://baidu.com" -> ('https', '://', 'baidu.com')
std::vector<pystring_ext> pystring_ext::py_rpartition(const std::string &sep)
const
{
	std::vector<std::string> vec_tmp(pystring_function::rpartition(var_container, sep));
	return to_vector_pystring_ext(vec_tmp);
}

//把 string 中的 str1 替换成 str2, 如果 count 指定，则替换不超过 count 次.
pystring_ext pystring_ext::py_replace(const std::string &oldstr,
	const std::string &newstr, long_max_t count) const
{
	return pystring_function::replace(var_container, oldstr, newstr, count);
}

//strip() 方法用于截掉字符串两边的空格(包括\t\r\n)或指定字符。
pystring_ext pystring_ext::py_strip(const std::string &chars) const
{
	return pystring_function::strip(var_container, chars);
}

//字符串从右分割
std::vector<pystring_ext> pystring_ext::py_rsplit(const std::string &chars
	, long_max_t maxsplit) const
{
	std::vector<std::string> vec_tmp(pystring_function::rsplit(var_container, chars, maxsplit));
	//return convert_type::convert_vector_type_move<pystring_ext, std::string>(vec_tmp);
	return to_vector_pystring_ext(vec_tmp);
}

//字符串分割
std::vector<pystring_ext> pystring_ext::py_split(const std::string &chars
	, long_max_t maxsplit) const
{
	std::vector<std::string> vec_tmp(pystring_function::split(var_container, chars, maxsplit));
	return to_vector_pystring_ext(vec_tmp);
}

//字符串大小写翻转
pystring_ext pystring_ext::py_swapcase() const
{
	return pystring_function::swapcase(var_container);
}

//返回"标题化"的 string,就是说所有单词都是以大写开始，其余字母均为小写
//"This is.no 123" -> "This Is.No 123"
pystring_ext pystring_ext::py_title() const
{
	return pystring_function::title(var_container);
}

//用于字符映射的转换
//参数1是被转换的字符串，第2个参数是字符串，表示需要转换的字符，第3个参数是字符串表示转换的目标。
//两个字符串的长度必须相同，为一一对应的关系。
//pystring_ext translate("abbc","bc","de") -> "adde"
pystring_ext pystring_ext::py_translate(const std::string &intab,
	const std::string &outtab) const
{
	return pystring_function::translate(var_container, intab, outtab);
}

//从左边开始使用字符0填充至指定长度，返回新字符串使原字符串右对齐。
//zfill("test",10); -> "000000test"
pystring_ext pystring_ext::py_zfill(std::string::size_type width) const
{
	return pystring_function::zfill(var_container, width);
}

//python风格的字符串格式化
// format(U"{} + {} = {}",std::vector<std::string>{U"1",U"2",U"3"})
pystring_ext pystring_ext::py_format(std::string format_str,
	std::vector<std::string > vec_format_list) const
{
	return pystring_function::format(format_str, vec_format_list);
}

//取两个字符串之间的字符串
pystring_ext pystring_ext::py_between_start_and_end_string(
	const std::string &str_start,
	const std::string &str_end) const
{
	return pystring_function::between_start_and_end_string(var_container, str_start, str_end);
}

//取两个字符串之间的字符串所在的起始位置和长度
bool pystring_ext::py_between_start_and_end_pos(const std::string &str_start,
	const std::string &str_end,
	std::string::size_type &n_start,
	std::string::size_type &n_copylen) const
{
	return pystring_function::between_start_and_end_pos(var_container, str_start, str_end,
		n_start, n_copylen);
}

//转换为整形数字
long long pystring_ext::to_long64() const
{
	return convert_type::to_long64<pystring_ext>(var_container);
	//return convert_type::to_long64((const std::string)var_container);
}

//转换字符串为浮点数
long double pystring_ext::to_long_double() const
{
	return convert_type::to_long_double(var_container);
	//return convert_type::to_long_double((const std::string)var_container);
}

//转换整形数字为字符串
pystring_ext pystring_ext::from_long64(long long l64_input)
{
	var_container = convert_type::long64_to_string(l64_input);
	return var_container;
}

//转换浮点数为字符串
pystring_ext pystring_ext::from_long_double(long double ld64_input)
{
	var_container = convert_type::long_double_to_string(ld64_input);
	return var_container;
}

//转换为pystring_ext
pystring_ext pystring_ext::to_pystring_ext(long long l64_input)
{
	return convert_type::long64_to_string(l64_input);
}

pystring_ext pystring_ext::to_pystring_ext(long double ld64_input)
{
	return convert_type::long_double_to_string(ld64_input);
}

pystring_ext pystring_ext::c_format(const char *format, ...)
{
	va_list argptr;
	va_start(argptr, format);
	//stdarg.h
	//vsnprintf返回需要缓冲区的字符数（字符数不含末尾的0）
	size_t n_count = vsnprintf(NULL, 0, format, argptr);
	//n_count + 1 算上0后需要的字符数
	size_t n_buffer_size = (n_count + 1) * sizeof(char);
	char *buf = new char[n_buffer_size * sizeof(char)];
	memset(buf, 0, n_buffer_size);
	//给申请的空间清零
	vsnprintf(buf, n_buffer_size, format, argptr);
	va_end(argptr);
	std::string ret_str(buf, n_count);
	delete[]buf;
	return ret_str;
}
//to_std_string返回一个std::string预防兼容性问题
std::string pystring_ext::to_std_string() const
{
	std::string str_ret((std::string)var_container);
	return str_ret;
}

//to UTF-16
std::u16string pystring_ext::to_std_u16string()
{
	std::u16string u16_data;
	uft_conv::utf8_to_utf16(var_container, u16_data);
	return u16_data;
}

//to UTF-32
std::u32string pystring_ext::to_std_u32string()
{
	std::u32string u32_data;
	uft_conv::utf8_to_utf32(var_container, u32_data);
	return u32_data;
}

//private std::vector<pystring_ext> to_vector_pystring_ext(const std::vector<std::string> &vec_str) const;
std::vector<pystring_ext>
pystring_ext::to_vector_pystring_ext
(std::vector<std::string> &vec_str) const
{
	std::vector<pystring_ext> vec_ret;
	size_t n_vec_str_size = vec_str.size();
	vec_ret.resize(n_vec_str_size);
	for (size_t i = 0; i < n_vec_str_size; i++)
	{
		vec_ret[i] = std::move(vec_str[i]);
	}
	return vec_ret;
}

//private std::vector<std::string> to_vector_std_string(std::vector<pystring_ext> &vec_pystr) const;
std::vector<std::string>
pystring_ext::to_vector_std_string
(std::vector<pystring_ext> &vec_pystr) const
{
	std::vector<std::string> vec_ret;
	size_t n_vec_str_size = vec_pystr.size();
	vec_ret.resize(n_vec_str_size);
	for (size_t i = 0; i < n_vec_str_size; i++)
	{
		vec_ret[i] = std::move((std::string)vec_pystr[i]);
	}
	return vec_ret;
}
