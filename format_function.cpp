#include "format_function.h"

namespace string_format
{
	std::string& format_argv(std::string& str_input, int n)
	{
		replace_argv_once(str_input, std::string("%d"), convert_type::int_to_string(n));
		return str_input;
	}

	std::u16string& format_argv(std::u16string& str_input, int n)
	{
		replace_argv_once(str_input, std::u16string(u"%d"), convert_type::int_to_u16string(n));
		return str_input;
	}

	std::u32string& format_argv(std::u32string& str_input, int n)
	{
		replace_argv_once(str_input, std::u32string(U"%d"), convert_type::int_to_u32string(n));
		return str_input;
	}

	std::string& format_argv(std::string& str_input, long double ld64_input, int n_decimal_digits)
	{
		replace_argv_once(str_input, std::string("%f"), convert_type::float_to_string(ld64_input, n_decimal_digits));
		return str_input;
	}

	std::u16string& format_argv(std::u16string& str_input, long double ld64_input, int n_decimal_digits)
	{
		replace_argv_once(str_input, std::u16string(u"%f"), convert_type::float_to_u16string(ld64_input, n_decimal_digits));
		return str_input;
	}

	std::u32string& format_argv(std::u32string& str_input, long double ld64_input, int n_decimal_digits)
	{
		replace_argv_once(str_input, std::u32string(U"%f"), convert_type::float_to_u32string(ld64_input, n_decimal_digits));
		return str_input;
	}

	std::string& format_argv(std::string& str_input, const std::string& str_argv)
	{
		replace_argv_once(str_input, std::string("%s"), str_argv);
		return str_input;
	}

	std::u16string& format_argv(std::u16string& str_input, const std::u16string& str_argv)
	{
		replace_argv_once(str_input, std::u16string(u"%s"), str_argv);
		return str_input;
	}

	std::u32string& format_argv(std::u32string& str_input, const std::u32string& str_argv)
	{
		replace_argv_once(str_input, std::u32string(U"%s"), str_argv);
		return str_input;
	}

} //namespace string_format end