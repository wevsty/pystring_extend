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
#include "pystring_utf32_function.h"

//isdecimal() encode decode
namespace pystring_utf32_function
{
	//安全转换unsigned到signed
	long_max_t safe_to_sigend_cast(size_t n_input)
	{
		long_max_t n_out = (long_max_t)n_input;
		assert(n_out >= 0);
		/*
		if (n_out < (long_max_t)0)
		{
		throw(std::runtime_error("Integer Overflow"));
		}
		*/
		return n_out;
	}

	//安全转换signed到unsigned
	std::u32string::size_type safe_to_unsigend_cast(long_max_t n_input)
	{
		std::u32string::size_type n_out = (std::u32string::size_type)n_input;
		assert(n_out == (long_max_u)n_input);
		/*
		if (n_out < (long_max_t)0)
		{
		throw(std::runtime_error("Integer Overflow"));
		}
		*/
		return n_out;
	}

	//调整开始和结束下标，主要用于负数时
	void adjust_indices(long_max_t &start, long_max_t &end, long_max_t &len)
	{
		if (end > len)
		{
			end = len;
		}
		else if (end < 0)
		{
			end += len;
			if (end < 0)
			{
				end = 0;
			}
		}
		if (start < 0)
		{
			start += len;
			if (start < 0)
			{
				start = 0;
			}
		}
	}

	//转换类型
	//convert<string>(10)
	//convert<int>(string)
	template<typename out_type, typename in_value>
	out_type convert_type(const in_value &t)
	{
		std::stringstream stream;
		stream << t;
		//向流中传值
		out_type result;
		//这里存储转换结果
		stream >> result;
		//向result中写入值
		return result;
	}

	//切片方法
	std::u32string slice(const std::u32string &str, long_max_t start,
		long_max_t end)
	{
		long_max_t str_len = safe_to_sigend_cast(str.size());
		adjust_indices(start, end, str_len);
		if (start >= end)
		{
			return U"";
		}
		return str.substr(safe_to_unsigend_cast(start),
			safe_to_unsigend_cast(end - start));
	}

	//find() 方法检测字符串(str)中是否包含子字符串(sub)
	//如果指定 beg（开始） 和 end（结束） 范围，则检查是否包含在指定范围内
	//如果包含子字符串返回开始的索引值，否则返回 - 1
	long_max_t find(const std::u32string &str, const std::u32string &sub,
		long_max_t start, long_max_t end)
	{
		//long_max_t start = input_start;
		//long_max_t end = input_end;
		long_max_t len = safe_to_sigend_cast(str.size());
		adjust_indices(start, end, len);
		//如果end小于start，那么表示不可能查找到结果。
		if (end < start)
		{
			return (long_max_t)-1;
		}
		std::u32string::size_type result = str.find(sub, safe_to_unsigend_cast(start));
		if (result == std::u32string::npos ||
			(result + sub.size() >(std::u32string::size_type)end))
		{
			return (long_max_t)-1;
		}
		return safe_to_sigend_cast(result);
	}

	//与find()同义
	long_max_t index(const std::u32string &str, const std::u32string &sub,
		long_max_t start, long_max_t end)
	{
		return find(str, sub, start, end);
	}

	//类似于 find()函数，不过是从右边开始查找
	long_max_t rfind(const std::u32string &str, const std::u32string &sub,
		long_max_t start, long_max_t end)
	{
		//long_max_t start = input_start;
		//long_max_t end = input_end;
		long_max_t len = safe_to_sigend_cast(str.size());
		adjust_indices(start, end, len);
		//如果end小于start，那么表示不可能查找到结果。
		if (end < start)
		{
			return (long_max_t)-1;
		}
		std::u32string::size_type result = str.rfind(sub, safe_to_unsigend_cast(end));
		if (result == std::u32string::npos ||
			result < (std::u32string::size_type)start ||
			(result + sub.size() >(std::u32string::size_type)end))
		{
			return (long_max_t)-1;
		}
		return safe_to_sigend_cast(result);
	}

	//与rfind()同义
	long_max_t rindex(const std::u32string &str, const std::u32string &sub,
		long_max_t start, long_max_t end)
	{
		return rfind(str, sub, start, end);
	}

	//把 string 中的 str1 替换成 str2, 如果 count 指定，则替换不超过 count 次.
	std::u32string replace(const std::u32string &str, const std::u32string &oldstr,
		const std::u32string &newstr, long_max_t count)
	{
		long_max_t sofar = 0;
		long_max_t cursor = 0;
		std::u32string str_ret(str);
		long_max_t oldlen = safe_to_sigend_cast(oldstr.size());
		long_max_t newlen = safe_to_sigend_cast(newstr.size());
		cursor = find(str_ret, oldstr, cursor);
		while (cursor != -1 && cursor <= safe_to_sigend_cast(str_ret.size()))
		{
			if (count > -1 && sofar >= count)
			{
				break;
			}
			str_ret.replace(cursor, oldlen, newstr);
			cursor += newlen;
			if (oldlen != 0)
			{
				cursor = find(str_ret, oldstr, cursor);
			}
			else
			{
				++cursor;
			}
			++sofar;
		}
		return str_ret;
	}

	std::vector<std::u32string> split_whitespace(const std::u32string &str,
		long_max_t maxsplit)
	{
		std::vector<std::u32string> vec_ret;
		std::u32string::size_type i;
		std::u32string::size_type n_start_pos;
		std::u32string::size_type n_str_len = str.size();
		for (i = n_start_pos = 0; i < n_str_len; )
		{
			//找到第一个非空字符
			while (i < n_str_len && std::isspace(str[i]))
			{
				i++;
			}
			n_start_pos = i;
			//寻找下一个空字符
			while (i < n_str_len && !std::isspace(str[i]))
			{
				i++;
			}
			//如果找到了可分割的字符
			if (n_start_pos < i)
			{
				if (maxsplit-- <= 0)
				{
					break;
				}
				vec_ret.push_back(str.substr(n_start_pos, i - n_start_pos));
				//性能优化
				while (i < n_str_len && ::isspace(str[i]))
				{
					i++;
				}
				n_start_pos = i;
			}
		}
		if (n_start_pos < n_str_len)
		{
			vec_ret.push_back(str.substr(n_start_pos, n_str_len - n_start_pos));
		}
		return vec_ret;
	}

	//字符串分割
	std::vector<std::u32string> split(const std::u32string &str,
		const std::u32string &sep,
		long_max_t maxsplit)
	{
		std::vector<std::u32string> vec_ret;
		if (maxsplit < 0)
		{
			maxsplit = MAX_SIGNED_LONG64_NUM;    //vec_ret.max_size();
		}
		if (sep.size() == 0)
		{
			return split_whitespace(str, maxsplit);
		}
		std::u32string::size_type i = 0;
		std::u32string::size_type n_start_pos = 0;
		std::u32string::size_type n_strlen = str.size();
		std::u32string::size_type n_sep_len = sep.size();
		while (i + n_sep_len <= n_strlen)
		{
			if (str.compare(i, n_sep_len, sep) == 0)
			{
				if (maxsplit-- <= 0)
				{
					break;
				}
				vec_ret.push_back(str.substr(n_start_pos, i - n_start_pos));
				i = n_start_pos = i + n_sep_len;
			}
			else
			{
				i++;
			}
		}
		vec_ret.push_back(str.substr(n_start_pos, n_strlen - n_start_pos));
		return vec_ret;
	}

	std::vector<std::u32string> rsplit_whitespace(const std::u32string &str,
		long_max_t maxsplit)
	{
		std::vector<std::u32string> vec_ret;
		std::u32string::size_type n_strlen = str.size();
		std::u32string::size_type i;
		std::u32string::size_type n_strart_pos;
		for (i = n_strart_pos = n_strlen; i > 0; )
		{
			while (i > 0 && std::isspace(str[i - 1]))
			{
				i--;
			}
			n_strart_pos = i;
			while (i > 0 && !std::isspace(str[i - 1]))
			{
				i--;
			}
			if (n_strart_pos > i)
			{
				if (maxsplit-- <= 0)
				{
					break;
				}
				vec_ret.push_back(str.substr(i, n_strart_pos - i));
				while (i > 0 && std::isspace(str[i - 1]))
				{
					i--;
				}
				n_strart_pos = i;
			}
		}
		if (n_strart_pos > 0)
		{
			vec_ret.push_back(str.substr(0, n_strart_pos));
		}
		std::reverse(vec_ret.begin(), vec_ret.end());
		//reverse_strings(result);
		return vec_ret;
	}

	std::vector<std::u32string> rsplit(const std::u32string &str,
		const std::u32string &sep, long_max_t maxsplit)
	{
		std::vector<std::u32string> vec_ret;
		if (maxsplit < 0)
		{
			return split(str, sep, maxsplit);
		}
		if (sep.size() == 0)
		{
			return rsplit_whitespace(str, maxsplit);
		}
		long_max_t i;
		long_max_t n_start_pos;
		long_max_t n_strlen = safe_to_sigend_cast(str.size());
		long_max_t n_sep_len = safe_to_sigend_cast(sep.size());
		i = n_start_pos = n_strlen;
		while (i >= n_sep_len)
		{
			if (str[i - 1] == sep[n_sep_len - 1]
				&& str.substr(i - n_sep_len, n_sep_len) == sep)
			{
				if (maxsplit-- <= 0)
				{
					break;
				}
				vec_ret.push_back(str.substr(i, n_start_pos - i));
				i = n_start_pos = i - n_sep_len;
			}
			else
			{
				i--;
			}
		}
		vec_ret.push_back(str.substr(0, n_start_pos));
		std::reverse(vec_ret.begin(), vec_ret.end());
		return vec_ret;
		//reverse_strings(result);
	}

	//将序列中的元素以指定的字符连接生成一个新的字符串。
	std::u32string join(const std::u32string &str,
		std::vector<std::u32string> &seq)
	{
		std::u32string str_ret(U"");
		if (seq.empty() == true)
		{
			return str_ret;
		}
		str_ret = seq[0];
		for (std::vector<std::u32string>::const_iterator it = seq.begin() + 1;
			it != seq.end();
			it++
			)
		{
			str_ret += str + *it;
		}
		return str_ret;
	}

	//返回一个3元的元组，第一个为分隔符左边的子串，第二个为分隔符本身，第三个为分隔符右边的子串。
	//"https://baidu.com" -> ('https', '://', 'baidu.com')
	std::vector<std::u32string> partition(const std::u32string &str,
		const std::u32string &sep)
	{
		std::vector< std::u32string > result(3);
		long_max_t index = find(str, sep);
		if (index < 0)
		{
			result[0] = str;
			result[1] = U"";
			result[2] = U"";
		}
		else
		{
			result[0] = str.substr(0, index);
			result[1] = sep;
			result[2] = str.substr(index + sep.size(), str.size());
		}
		return result;
	}

	//类似于partition()函数,不过是从右边开始查找.
	//返回一个3元的元组，第一个为分隔符左边的子串，第二个为分隔符本身，第三个为分隔符右边的子串。
	//"https://baidu.com" -> ('https', '://', 'baidu.com')
	std::vector<std::u32string> rpartition(const std::u32string &str,
		const std::u32string &sep)
	{
		std::vector< std::u32string > result(3);
		long_max_t index = rfind(str, sep);
		if (index < 0)
		{
			result[0] = U"";
			result[1] = U"";
			result[2] = str;
		}
		else
		{
			result[0] = str.substr(0, index);
			result[1] = sep;
			result[2] = str.substr(index + sep.size(), str.size());
		}
		return result;
	}

	//lstrip() 方法用于截掉字符串左边的空格(包括\t\r\n)或指定字符。
	std::u32string lstrip(const std::u32string &str, const std::u32string &chars)
	{
		bool b_strip_space = true;
		if (chars.empty() != true)
		{
			b_strip_space = false;
		}
		const std::u32string::size_type n_strlen = str.size();
		std::u32string::size_type n_start_pos = 0;
		for (std::u32string::size_type i = 0;
			i < n_strlen; i++)
		{
			if (b_strip_space == true)
			{
				if (std::isspace(str[i]) == 0)
				{
					//不为空格时
					n_start_pos = i;
					break;
				}
			}
			else
			{
				if (chars.find(str[i]) == std::u32string::npos)
				{
					//当字符串当前字符第一次不在过滤列表时
					n_start_pos = i;
					break;
				}
			}
		}
		return str.substr(n_start_pos);
	}

	//rstrip() 方法用于截掉字符串右边的空格(包括\t\r\n)或指定字符。
	std::u32string rstrip(const std::u32string &str, const std::u32string &chars)
	{
		bool b_strip_space = true;
		if (chars.empty() != true)
		{
			b_strip_space = false;
		}
		std::u32string::size_type n_end_pos = 0;
		std::u32string::size_type n_strlen = str.size();
		for (std::u32string::size_type i = n_strlen - 1;
			i < n_strlen; i--)
		{
			if (b_strip_space == true)
			{
				if (std::isspace(str[i]) == 0)
				{
					//不为空格时
					n_end_pos = i + 1;
					break;
				}
			}
			else
			{
				if (chars.find(str[i]) == std::u32string::npos)
				{
					//当字符串当前字符第一次不在过滤列表时
					n_end_pos = i + 1;
					break;
				}
			}
		}
		return str.substr(0, n_end_pos);
	}

	//strip() 方法用于截掉字符串两边的空格(包括\t\r\n)或指定字符。
	std::u32string strip(const std::u32string &str, const std::u32string &chars)
	{
		bool b_strip_space = true;
		if (chars.empty() != true)
		{
			b_strip_space = false;
		}
		const std::u32string::size_type n_strlen = str.size();
		std::u32string::size_type n_start_pos = 0;
		for (std::u32string::size_type i = 0;
			i < n_strlen; i++)
		{
			if (b_strip_space == true)
			{
				if (std::isspace(str[i]) == 0)
				{
					//不为空格时
					n_start_pos = i;
					break;
				}
			}
			else
			{
				if (chars.find(str[i]) == std::u32string::npos)
				{
					//当字符串当前字符第一次不在过滤列表时
					n_start_pos = i;
					break;
				}
			}
		}
		std::u32string::size_type n_end_pos = 0;
		for (std::u32string::size_type i = n_strlen - 1;
			i < n_strlen; i--)
		{
			if (b_strip_space == true)
			{
				if (std::isspace(str[i]) == 0)
				{
					//不为空格时
					n_end_pos = i + 1;
					break;
				}
			}
			else
			{
				if (chars.find(str[i]) == std::u32string::npos)
				{
					//当字符串当前字符第一次不在过滤列表时
					n_end_pos = i + 1;
					break;
				}
			}
		}
		std::u32string::size_type n_copy_len = n_end_pos - n_start_pos;
		return str.substr(n_start_pos, n_copy_len);
	}

	//字符串按行分割
	std::vector<std::u32string> splitlines(const std::u32string &str_data,
		bool b_keepends)
	{
		std::vector<std::u32string> vec_split_str;
		std::u32string::size_type n_str_len = str_data.size();
		std::u32string str_buff(U"");
		for (std::u32string::size_type i = 0; i < n_str_len; i++)
		{
			if (str_data[i] == U'\r')
			{
				if (str_data[i + 1] == U'\n')
				{
					i++;
					if (b_keepends == true)
					{
						str_buff.append(U"\r\n");
					}
					vec_split_str.push_back(str_buff);
					str_buff.clear();
				}
				else
				{
					if (b_keepends == true)
					{
						str_buff.push_back(U'\r');
					}
					vec_split_str.push_back(str_buff);
					str_buff.clear();
				}
			}
			else if (str_data[i] == U'\n')
			{
				if (b_keepends == true)
				{
					str_buff.push_back(U'\n');
				}
				vec_split_str.push_back(str_buff);
				str_buff.clear();
			}
			else
			{
				str_buff.push_back(str_data[i]);
				continue;
			}
		}
		if (str_buff.empty() != true)
		{
			vec_split_str.push_back(str_buff);
		}
		return vec_split_str;
	}

	//字符串大小写翻转
	std::u32string swapcase(const std::u32string &old_str)
	{
		std::u32string str_ret(old_str);
		char32_t ch_tmp;
		for (std::u32string::iterator it = str_ret.begin(); it != str_ret.end(); it++)
		{
			ch_tmp = *it;
			//发现大写字母则改小写
			if (std::isupper(ch_tmp) != 0)
			{
				ch_tmp = (char)std::tolower(ch_tmp);
				*it = ch_tmp;
			}
			else if (std::islower(ch_tmp) != 0)
			{
				//发现小写字母则改大写
				ch_tmp = (char)std::toupper(ch_tmp);
				*it = ch_tmp;
			}
		}
		return str_ret;
	}

	//翻转字符串
	std::u32string string_reverse(const std::u32string &old_str)
	{
		std::u32string str_ret(old_str);
		std::reverse(str_ret.begin(), str_ret.end());
		return str_ret;
	}

	//返回一个首字母大写其他小写的字符串
	//"this IS string" -> "This is string"
	std::u32string capitalize(const std::u32string &oldstr)
	{
		std::u32string str_ret(oldstr);
		std::u32string::size_type len = str_ret.size();
		std::u32string::size_type i;
		if (len > 0)
		{
			if (std::islower(str_ret[0]))
			{
				str_ret[0] = (char)std::toupper(str_ret[0]);
			}
		}
		for (i = 1; i < len; ++i)
		{
			if (std::isupper(str_ret[i]))
			{
				str_ret[i] = (char)std::tolower(str_ret[i]);
			}
			//str_ret.push_back((char)std::tolower(oldstr[i]));
		}
		return str_ret;
	}

	//返回一个原字符串居中的新字符串,并使用fillchar(默认空格)填充至长度 width 的新字符串
	//"This is Test." -> "FFFThis is Test.FFFF"
	std::u32string center(const std::u32string &str, std::u32string::size_type width,
		const char32_t fillchar)
	{
		std::u32string::size_type len = str.size();
		std::u32string::size_type marg, left;
		if (len >= width)
		{
			return str;
		}
		marg = width - len;
		left = marg / 2 + (marg & width & 1);
		return std::u32string(left, fillchar) + str + std::u32string(marg - left, fillchar);
	}

	//返回字符串中指定字符或者字符串的数目。
	//"this is string" -> "is" -> ret 2
	long_max_t count(const std::u32string &str, const std::u32string &substr,
		long_max_t start, long_max_t end)
	{
		long_max_t n_count = 0;
		long_max_t cursor = start;
		while (1)
		{
			cursor = find(str, substr, cursor, end);
			if (cursor < 0)
			{
				break;
			}
			cursor += safe_to_sigend_cast(substr.size());
			n_count++;
		}
		return n_count;
	}

	//判断字符串结尾是否等于suffix
	bool endswith(const std::u32string &str, const std::u32string &suffix,
		long_max_t start, long_max_t end)
	{
		long_max_t str_len = safe_to_sigend_cast(str.size());
		long_max_t suffix_len = safe_to_sigend_cast(suffix.size());
		adjust_indices(start, end, str_len);
		if (end - start < suffix_len || start > str_len)
		{
			return false;
		}
		if (end - suffix_len > start)
		{
			start = end - suffix_len;
		}
		if (str.compare(safe_to_unsigend_cast(start), safe_to_unsigend_cast(suffix_len),
			suffix) != 0)
		{
			return false;
		}
		return true;
	}

	//判断字符串结尾是否等于prefix
	bool startswith(const std::u32string &str, const std::u32string &prefix,
		long_max_t start, long_max_t end)
	{
		long_max_t str_len = safe_to_sigend_cast(str.size());
		long_max_t prefix_len = safe_to_sigend_cast(prefix.size());
		adjust_indices(start, end, str_len);
		if (start + prefix_len > str_len)
		{
			return false;
		}
		if (end - start >= prefix_len)
		{
			if (str.compare(safe_to_unsigend_cast(start), safe_to_unsigend_cast(prefix_len),
				prefix) != 0)
			{
				return false;
			}
		}
		return true;
	}

	//扩展/t为空格（默认为8个）并保持行末尾对齐
	std::u32string expandtabs(const std::u32string &str, int tabsize)
	{
		std::u32string str_ret(str);
		std::u32string::size_type len = str.size(), i = 0;
		std::u32string::size_type offset = 0;
		std::u32string::size_type jump_char_num = 0;
		std::u32string::size_type u_tabsize;
		if (tabsize < 0)
		{
			u_tabsize = 0;
		}
		else
		{
			u_tabsize = (std::u32string::size_type)tabsize;
		}
		for (i = 0; i < len; ++i)
		{
			if (str[i] == U'\t')
			{
				if (u_tabsize > 0)
				{
					std::u32string::size_type fillsize = tabsize - (jump_char_num % u_tabsize);
					jump_char_num += fillsize;
					str_ret.replace(i + offset, 1, std::u32string(fillsize, U' '));
					offset += fillsize - 1;
				}
				else
				{
					str_ret.replace(i + offset, 1, U"");
					offset -= 1;
				}
			}
			else
			{
				jump_char_num++;
				if (str[i] == U'\n' || str[i] == U'\r')
				{
					jump_char_num = 0;
				}
			}
		}
		return str_ret;
	}

	//如果string至少有一个字符并且所有字符都是字母或数字则返回 true, 否则返回 false
	// "a1"   -> true
	// "a1\n" -> false
	bool isalnum(const std::u32string &str)
	{
		if (str.empty())
		{
			return false;
		}
		for (std::u32string::const_iterator it = str.begin();
			it != str.end(); it++)
		{
			//是否为字母或者数字
			if (std::isalnum(*it) == 0)
			{
				//不是数字或字幕则直接返回false
				return false;
			}
		}
		return true;
	}

	//如果string至少有一个字符并且所有字符都是字母则返回 true, 否则返回 false
	// "a1\n" -> false
	// "abc" -> true
	bool isalpha(const std::u32string &str)
	{
		if (str.empty())
		{
			return false;
		}
		for (std::u32string::const_iterator it = str.begin();
			it != str.end(); it++)
		{
			//是否为字母
			if (std::isalpha(*it) == 0)
			{
				return false;
			}
		}
		return true;
	}

	//如果string至少有一个字符并且所有字符都是数字则返回 true, 否则返回 false
	// "-10" -> false
	// "10" -> true
	bool isdigit(const std::u32string &str)
	{
		if (str.empty())
		{
			return false;
		}
		for (std::u32string::const_iterator it = str.begin();
			it != str.end(); it++)
		{
			//是否为数字
			if (std::isdigit(*it) == 0)
			{
				return false;
			}
		}
		return true;
	}

	//如果string至少有一个字符并且所有字符都是空格（包括\r\n\t\f\v）则返回 true, 否则返回 false
	bool isspace(const std::u32string &str)
	{
		if (str.empty())
		{
			return false;
		}
		for (std::u32string::const_iterator it = str.begin();
			it != str.end(); it++)
		{
			//是否为空格
			if (std::isspace(*it) == 0)
			{
				return false;
			}
		}
		return true;
	}

	//检测字符串中所有的单词拼写首字母是否为大写，且其他字母为小写
	//"this is" -> false
	//"This Is" -> true
	bool istitle(const std::u32string &str)
	{
		if (str.empty())
		{
			return false;
		}
		bool b_need_upper = true;
		bool b_have_isalpha = false;
		int ch_tmp;
		for (std::u32string::const_iterator it = str.begin();
			it != str.end(); it++)
		{
			ch_tmp = *it;
			if (std::islower(ch_tmp) != 0)
			{
				//如果是小写但是应该大写
				if (b_need_upper == true)
				{
					return false;
				}
				b_need_upper = false;
				b_have_isalpha = true;
			}
			else if (std::isupper(ch_tmp) != 0)
			{
				//如果是大写但是应该小写
				if (b_need_upper == false)
				{
					return false;
				}
				b_need_upper = false;
				b_have_isalpha = true;
			}
			else
			{
				b_need_upper = true;
			}
		}
        if(b_have_isalpha == true)
		{
            return true;
		}
		return false;
	}

	//如果string中包含至少一个字母，并且所有字符都是小写，则返回 true，否则返回 false
	//"abc123.0" -> true
	//"A1" -> false
	//"11" -> false
	bool islower(const std::u32string &str)
	{
		bool b_have_lower = false;
		int ch_tmp = 0;
		for (std::u32string::const_iterator it = str.begin();
			it != str.end(); it++)
		{
			ch_tmp = *it;
			if (b_have_lower == false)
			{
				if (std::islower(ch_tmp) != 0)
				{
					//是小写字母
					b_have_lower = true;
					continue;
				}
			}
			if (std::isupper(ch_tmp) != 0)
			{
				//发现大写字母返回false
				return false;
			}
		}
		return b_have_lower;
	}

	//如果string中包含至少一个字母，并且所有字符都是大写，则返回 true，否则返回 false
	//"ABC123.0" -> true
	//"a1" -> false
	//"11" -> false
	bool isupper(const std::u32string &str)
	{
		bool b_have_upper = false;
		int ch_tmp = 0;
		for (std::u32string::const_iterator it = str.begin();
			it != str.end(); it++)
		{
			ch_tmp = *it;
			if (b_have_upper == false)
			{
				if (std::isupper(ch_tmp) != 0)
				{
					//是大写字母
					b_have_upper = true;
					continue;
				}
			}
			if (std::islower(ch_tmp) != 0)
			{
				//发现小写字母返回false
				return false;
			}
		}
		return b_have_upper;
	}

	//定义ch_tolow函数为了兼容编译器
	inline int ch_tolower(int ch)
	{
		return std::tolower(ch);
	}

	//定义ch_toupper函数为了兼容编译器
	inline int ch_toupper(int ch)
	{
		return std::toupper(ch);
	}

	//转换所有字符为小写
	std::u32string lower(const std::u32string &str)
	{
		std::u32string str_ret(str);
		std::transform(str_ret.begin(), str_ret.end(), str_ret.begin(), pystring_utf32_function::ch_tolower);
		return str_ret;
	}

	//转换所有字符为大写
	std::u32string upper(const std::u32string &str)
	{
		std::u32string str_ret(str);
		std::transform(str_ret.begin(), str_ret.end(), str_ret.begin(), pystring_utf32_function::ch_toupper);
		return str_ret;
	}

	//返回一个原字符串左对齐,并使用空格填充至长度 width 的新字符串
	std::u32string ljust(const std::u32string &str, long_max_t width, char32_t fillchar)
	{
		std::u32string::size_type len = str.size();
		if (safe_to_sigend_cast(len) >= width)
		{
			return str;
		}
		return str + std::u32string(width - len, fillchar);
	}

	//返回一个原字符串右对齐,并使用空格填充至长度 width 的新字符串
	std::u32string rjust(const std::u32string &str, long_max_t width, char32_t fillchar)
	{
		std::u32string::size_type len = str.size();
		if (safe_to_sigend_cast(len) >= width)
		{
			return str;
		}
		return std::u32string(width - len, fillchar) + str;
	}

	//返回"标题化"的 string,就是说所有单词都是以大写开始，其余字母均为小写
	//"This is.no 123" -> "This Is.No 123"
	std::u32string title(const std::u32string  &str)
	{
		std::u32string str_ret(str);
		if (str_ret.empty())
		{
			return str_ret;
		}
		bool b_need_upper = true;
		int ch_tmp;
		for (std::u32string::iterator it = str_ret.begin();
			it != str_ret.end(); it++)
		{
			ch_tmp = *it;
			if (std::islower(ch_tmp) != 0)
			{
				//如果是小写但是应该大写
				if (b_need_upper == true)
				{
					*it = std::toupper(ch_tmp);
				}
				b_need_upper = false;
			}
			else if (std::isupper(ch_tmp) != 0)
			{
				//如果是大写但是应该小写
				if (b_need_upper == false)
				{
					*it = std::tolower(ch_tmp);
				}
				b_need_upper = false;
			}
			else
			{
				b_need_upper = true;
			}
		}
		return str_ret;
	}

	//从左边开始使用字符0填充至指定长度，返回新字符串使原字符串右对齐。
	//zfill("test",10); -> "000000test"
	std::u32string zfill(const std::u32string &str, std::u32string::size_type width)
	{
		std::u32string::size_type len = str.size();
		if (len >= width)
		{
			return str;
		}
		std::u32string str_ret(str);
		std::u32string::size_type fill = width - len;
		str_ret = std::u32string(fill, U'0') + str_ret;
		if (str_ret[fill] == U'+' || str_ret[fill] == U'-')
		{
			str_ret[0] = str_ret[fill];
			str_ret[fill] = U'0';
		}
		return str_ret;
	}

	//用于字符映射的转换
	//参数1是被转换的字符串，第2个参数是字符串，表示需要转换的字符，第3个参数是字符串表示转换的目标。
	//两个字符串的长度必须相同，为一一对应的关系。
	//std::u32string translate("abbc","bc","de") -> "adde"
	std::u32string translate(const std::u32string &old_str, const std::u32string &intab,
		const std::u32string &outtab)
	{
		std::u32string::size_type n_intab_length = intab.length();
		if (n_intab_length != outtab.length() || n_intab_length == 0)
		{
			return old_str;
		}
		std::map<char32_t, char32_t> map_tables;
		for (std::u32string::size_type n = 0; n < n_intab_length; n++)
		{
			map_tables[intab[n]] = outtab[n];
		}
		std::u32string ret_str;
		for (std::u32string::const_iterator it = old_str.begin(); it != old_str.end(); it++)
		{
			std::map<char32_t, char32_t>::const_iterator map_it = map_tables.find(*it);
			if (map_it == map_tables.end())
			{
				ret_str.push_back(*it);
			}
			else
			{
				ret_str.push_back(map_it->second);
			}
		}
		return ret_str;
	}

	//取两个字符串之间的字符串所在的起始位置和长度
	bool between_start_and_end_pos(const std::u32string  &str_data,
		const std::u32string  &str_start,
		const std::u32string  &str_end,
		std::u32string::size_type &n_start,
		std::u32string::size_type &n_copylen)
	{
		n_start = 0;
		n_copylen = std::u32string::npos;
		if (str_start.empty() == true)
		{
			return false;
		}
		n_start = str_data.find(str_start);
		if (std::u32string::npos == n_start)
		{
			return false;
		}
		n_start += str_start.length();
		if (str_end.empty() == true)
		{
			return true;
		}
		std::u32string::size_type n_end = str_data.find(str_end, n_start);
		if (std::u32string::npos == n_end)
		{
			return false;
		}
		n_copylen = n_end - n_start;
		return true;
	}

	//取两个字符串之间的字符串
	std::u32string between_start_and_end_string(const std::u32string  &str_data,
		const std::u32string  &str_start,
		const std::u32string  &str_end)
	{
		std::u32string::size_type n_start = 0;
		std::u32string::size_type n_copylen = std::u32string::npos;
		if (between_start_and_end_pos(str_data, str_start, str_end, n_start, n_copylen) == true)
		{
			return str_data.substr(n_start, n_copylen);
		}
		return U"";
	}

	//python风格的字符串格式化
	// format(U"{} + {} = {}",std::vector<std::u32string>{U"1",U"2",U"3"})
	std::u32string format(std::u32string format_str, std::vector<std::u32string > vec_format_list)
	{
		std::u32string  str_ret;
		std::u32string::size_type n_formatlen = format_str.size();
		std::u32string::size_type n_format_start_pos = 0;
		std::u32string::size_type n_format_list_num = 0;
		for (std::u32string::size_type i = 0; i < n_formatlen; i++)
		{
			if (format_str[i] == U'{')
			{
				i++;
				n_format_start_pos = i;
				while (i < n_formatlen)
				{
					if (format_str[i] != U'}')
					{
						i++;
					}
					else
					{
						break;
					}
				}
				std::u32string::size_type n_copy = i - n_format_start_pos;
				if (n_copy > 0)
				{
					std::u32string  str_num = format_str.substr(n_format_start_pos, n_copy);
					size_t n_codenum = (size_t)convert_type::to_long64(str_num);
					str_ret.append(vec_format_list[n_codenum]);
					continue;
				}
				str_ret.append(vec_format_list[n_format_list_num]);
				n_format_list_num++;
			}
			else
			{
				str_ret.push_back(format_str[i]);
			}
		}
		return str_ret;
	}
}

