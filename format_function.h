#if defined(_MSC_VER)
#pragma once
#endif


#ifndef __FORMAT_TEMPLATE_H__
#define __FORMAT_TEMPLATE_H__

#include "pystring_algorithm_template.h"
#include "data_conv.h"

namespace string_format
{
template <typename T_STRING>
void replace_argv_once(T_STRING& str_input,const T_STRING& old_str, const T_STRING& new_str)
{
	if (old_str.empty())
		return;
	size_t index;
	if ((index = str_input.find(old_str)) != T_STRING::npos)
	{
		str_input.replace(
			index,
			old_str.size(),
			new_str
		);
	}
	return;
}

std::string& format_argv(std::string& str_input, int n);
std::u16string& format_argv(std::u16string& str_input, int n);
std::u32string& format_argv(std::u32string& str_input, int n);

std::string& format_argv(std::string& str_input, long double ld64_input, int n_decimal_digits = 2);
std::u16string& format_argv(std::u16string& str_input, long double ld64_input, int n_decimal_digits = 2);
std::u32string& format_argv(std::u32string& str_input, long double ld64_input, int n_decimal_digits = 2);

std::string& format_argv(std::string& str_input, const std::string& str_argv);
std::u16string& format_argv(std::u16string& str_input, const std::u16string& str_argv);
std::u32string& format_argv(std::u32string& str_input, const std::u32string& str_argv);
}
#endif
