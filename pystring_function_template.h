#if defined(_MSC_VER)
#pragma once
#endif
#ifndef __PYTHON_STRING_FUNCTION_TEMPLATE_H__
#define __PYTHON_STRING_FUNCTION_TEMPLATE_H__

#include "pystring_function.h"
#include "py_string_public_def.h"
#include <vector>
#include <string>

namespace pystring_function
{
	//转换类型
	//stream_convert_type<string>(10)
	//stream_convert_type<int>(string)
	template<typename out_type, typename in_value>
	out_type stream_convert_type(const in_value &t)
	{
		std::stringstream stream;
		stream << t;
		//向流中传值
		out_type result;
		//这里存储转换结果
		stream >> result;
		//向vec_out_result中写入值
		return result;
	}

	template <typename TEMPLATE_VECTOR_STRING>
	void split_whitespace(
		TEMPLATE_VECTOR_STRING &vec_output, const std::string &str,
		long_max_t maxsplit)
	{
		vec_output.clear();
		size_t i;
		size_t n_start_pos;
		size_t n_str_len = str.size();
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
				vec_output.push_back(str.substr(n_start_pos, i - n_start_pos));
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
			vec_output.push_back(str.substr(n_start_pos, n_str_len - n_start_pos));
		}
		return;
	}

	//字符串分割
	template <typename TEMPLATE_VECTOR_STRING>
	void split(
		TEMPLATE_VECTOR_STRING &vec_output,
		const std::string &str,
		const std::string &sep,
		long_max_t maxsplit)
	{
		vec_output.clear();
		if (maxsplit < 0)
		{
			maxsplit = MAX_SIGNED_LONG64_NUM;    //vec_output.max_size();
		}
		if (sep.size() == 0)
		{
			return split_whitespace(vec_output, str, maxsplit);
		}
		size_t i = 0;
		size_t n_start_pos = 0;
		size_t n_strlen = str.size();
		size_t n_sep_len = sep.size();
		while (i + n_sep_len <= n_strlen)
		{
			if (str.compare(i, n_sep_len, sep) == 0)
			{
				if (maxsplit-- <= 0)
				{
					break;
				}
				vec_output.push_back(str.substr(n_start_pos, i - n_start_pos));
				i = n_start_pos = i + n_sep_len;
			}
			else
			{
				i++;
			}
		}
		vec_output.push_back(str.substr(n_start_pos, n_strlen - n_start_pos));
		return;
	}

	template <typename TEMPLATE_VECTOR_STRING>
	void rsplit_whitespace(
		TEMPLATE_VECTOR_STRING &vec_output,
		const std::string &str,
		long_max_t maxsplit)
	{
		vec_output.clear();
		size_t n_strlen = str.size();
		size_t i;
		size_t n_strart_pos;
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
				vec_output.push_back(str.substr(i, n_strart_pos - i));
				while (i > 0 && std::isspace(str[i - 1]))
				{
					i--;
				}
				n_strart_pos = i;
			}
		}
		if (n_strart_pos > 0)
		{
			vec_output.push_back(str.substr(0, n_strart_pos));
		}
		std::reverse(vec_output.begin(), vec_output.end());
		//reverse_strings(vec_out_result);
		return;
	}

	template <typename TEMPLATE_VECTOR_STRING>
	void rsplit(
		TEMPLATE_VECTOR_STRING &vec_output,
		const std::string &str,
		const std::string &sep,
		long_max_t maxsplit
	)
	{
		vec_output.clear();
		if (maxsplit < 0)
		{
			split(vec_output, str, sep, maxsplit);
			return;
		}
		if (sep.size() == 0)
		{
			return rsplit_whitespace(vec_output, str, maxsplit);
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
				vec_output.push_back(str.substr(i, n_start_pos - i));
				i = n_start_pos = i - n_sep_len;
			}
			else
			{
				i--;
			}
		}
		vec_output.push_back(str.substr(0, n_start_pos));
		std::reverse(vec_output.begin(), vec_output.end());
		return;
		//reverse_strings(vec_out_result);
	}

	//将序列中的元素以指定的字符连接生成一个新的字符串。
	template <typename TEMPLATE_VECTOR_STRING, typename TEMPLATE_STRING>
	void join(const std::string &str,
		TEMPLATE_VECTOR_STRING &seq,
		TEMPLATE_STRING &str_output
	)
	{
		if (seq.empty() == true)
		{
			str_output.clear();
			return;
		}
		str_output = seq[0];
		for (typename TEMPLATE_VECTOR_STRING::const_iterator it = seq.begin() + 1;
			it != seq.end();
			it++
			)
		{
			str_output += str + *it;
		}
		return;
	}

	//返回一个3元的元组，第一个为分隔符左边的子串，第二个为分隔符本身，第三个为分隔符右边的子串。
	//"https://baidu.com" -> ('https', '://', 'baidu.com')
	template <typename TEMPLATE_VECTOR_STRING>
	void partition(
		std::vector< TEMPLATE_VECTOR_STRING > &vec_out_result,
		const std::string &str,
		const std::string &sep
	)
	{
		vec_out_result.resize(3);
		long_max_t index = find(str, sep);
		if (index < 0)
		{
			vec_out_result[0] = str;
			vec_out_result[1] = "";
			vec_out_result[2] = "";
		}
		else
		{
			vec_out_result[0] = str.substr(0, index);
			vec_out_result[1] = sep;
			vec_out_result[2] = str.substr(index + sep.size(), str.size());
		}
		return;
	}

	//类似于partition()函数,不过是从右边开始查找.
	//返回一个3元的元组，第一个为分隔符左边的子串，第二个为分隔符本身，第三个为分隔符右边的子串。
	//"https://baidu.com" -> ('https', '://', 'baidu.com')
	template <typename TEMPLATE_VECTOR_STRING>
	void rpartition(
		TEMPLATE_VECTOR_STRING &vec_out_result,
		const std::string &str,
		const std::string &sep
	)
	{
		vec_out_result.resize(3);
		long_max_t index = rfind(str, sep);
		if (index < 0)
		{
			vec_out_result[0] = "";
			vec_out_result[1] = "";
			vec_out_result[2] = str;
		}
		else
		{
			vec_out_result[0] = str.substr(0, index);
			vec_out_result[1] = sep;
			vec_out_result[2] = str.substr(index + sep.size(), str.size());
		}
		return;
	}

	//字符串按行分割
	template <typename TEMPLATE_VECTOR_STRING>
	void splitlines(
		TEMPLATE_VECTOR_STRING &vec_out_split_str,
		const std::string &str_data,
		bool b_keepends
	)
	{
		vec_out_split_str.clear();
		size_t n_str_len = str_data.size();
		std::string str_buff("");
		for (size_t i = 0; i < n_str_len; i++)
		{
			if (str_data[i] == '\r')
			{
				if (str_data[i + 1] == '\n')
				{
					i++;
					if (b_keepends == true)
					{
						str_buff.append("\r\n");
					}
					vec_out_split_str.push_back(str_buff);
					str_buff.clear();
				}
				else
				{
					if (b_keepends == true)
					{
						str_buff.push_back('\r');
					}
					vec_out_split_str.push_back(str_buff);
					str_buff.clear();
				}
			}
			else if (str_data[i] == '\n')
			{
				if (b_keepends == true)
				{
					str_buff.push_back('\n');
				}
				vec_out_split_str.push_back(str_buff);
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
			vec_out_split_str.push_back(str_buff);
		}
		return;
	}

	//python风格的字符串格式化
	// format("{} + {} = {}",TEMPLATE_VECTOR_STRING{"1","2","3"})
	template <typename TEMPLATE_VECTOR_STRING>
	void format(std::string format_str,
		TEMPLATE_VECTOR_STRING vec_format_list, std::string &str_output)
	{
		size_t n_formatlen = format_str.size();
		size_t n_format_start_pos = 0;
		size_t n_format_list_num = 0;
		for (size_t i = 0; i < n_formatlen; i++)
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
				size_t n_copy = i - n_format_start_pos;
				if (n_copy > 0)
				{
					std::string str_num = format_str.substr(n_format_start_pos, n_copy);
					size_t n_codenum = (size_t)convert_type::to_long64(str_num);
					str_output.append(vec_format_list[n_codenum]);
					continue;
				}
				str_output.append(vec_format_list[n_format_list_num]);
				n_format_list_num++;
			}
			else
			{
				str_output.push_back(format_str[i]);
			}
		}
		return;
	}

}//end pystring_function namespace
#endif //__PYTHON_STRING_FUNCTION_TEMPLATE_H__
