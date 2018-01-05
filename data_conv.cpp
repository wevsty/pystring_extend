#include "data_conv.h"
#include "ConvertUTF.h"

namespace convert_type
{
	/*
	template <typename STRING_TYPE>
	long long to_long64(const STRING_TYPE str_input)
	{
	bool b_minus = false;
	long long l64_ret = 0;
	if (str_input.empty() == true)
	{
	return l64_ret;
	}
	size_t n_input = str_input.size();
	size_t i = 0;
	if (str_input[0] == '-')
	{
	i = 1;
	b_minus = true;
	}
	for (; i < n_input; i++)
	{
	int n_num = str_input[i] - '0';
	if (n_num > 9 || n_num < 0)
	{
	break;
	}
	else
	{
	l64_ret = ((l64_ret * 10) + n_num);
	}
	}
	if (b_minus == true)
	{
	return -l64_ret;
	}
	return l64_ret;
	}
	*/
	template<>
	long long to_long64(const char *str_input)
	{
		return to_long64(std::string(str_input));
	}

	template <>
	long long to_long64(const char16_t *str_input)
	{
		return to_long64(std::u16string(str_input));
	}

	template <>
	long long to_long64(const char32_t *str_input)
	{
		return to_long64(std::u32string(str_input));
	}

	/*
	template <typename STRING_TYPE>
	long double to_long_double(STRING_TYPE str_input)
	{
	bool b_minus = false;
	bool b_point = false;
	long double ld_ret = 0.0;
	long double ld_temp = 10;
	if (str_input.empty() == true)
	{
	return ld_ret;
	}
	size_t n_input = str_input.size();
	size_t i = 0;
	if (str_input[0] == '-')
	{
	i = 1;
	b_minus = true;
	}
	for (; i < n_input; i++)
	{
	int n_ch = str_input[i];
	if (n_ch == '.')
	{
	if (b_point == true)
	{
	break;
	}
	b_point = true;
	continue;
	}
	int n_num = n_ch - '0';
	if (n_num > 9 || n_num < 0)
	{
	break;
	}
	else
	{
	if (b_point == true)
	{
	ld_ret += n_num / ld_temp;
	ld_temp *= 10;
	}
	else
	{
	ld_ret = ((ld_ret * 10) + n_num);
	}
	}
	}
	if (b_minus == true)
	{
	return -ld_ret;
	}
	return ld_ret;
	}
	*/
	template <>
	long double to_long_double(const char *str_input)
	{
		return to_long_double(std::string(str_input));
	}

	template <>
	long double to_long_double(const char16_t *str_input)
	{
		return to_long_double(std::u16string(str_input));
	}

	template <>
	long double to_long_double(const char32_t *str_input)
	{
		return to_long_double(std::u32string(str_input));
	}

	std::string long64_to_string(long long l64_input)
	{
		long long l64_temp = l64_input;
		std::string str_ret;
		static char num_tables[] = "0123456789";
		if (l64_temp == 0)
		{
			return "0";
		}
		else if (l64_temp < 0)
		{
			str_ret.push_back('-');
			l64_temp = -l64_temp;
		}
		std::string reverse_str;
		while (true)
		{
			long long ld_div = l64_temp / 10;
			long long ld_mod = l64_temp % 10;
			reverse_str.push_back(num_tables[ld_mod]);
			l64_temp = ld_div;
			if (l64_temp == 0)
			{
				break;
			}
		}
		for (std::string::reverse_iterator rit = reverse_str.rbegin();
			rit != reverse_str.rend(); rit++)
		{
			str_ret.push_back(*rit);
		}
		return str_ret;
	}

	std::u16string long64_to_u16string(long long l64_input)
	{
		long long l64_temp = l64_input;
		std::u16string str_ret;
		static char16_t num_tables[] = u"0123456789";
		if (l64_temp == 0)
		{
			return u"0";
		}
		else if (l64_temp < 0)
		{
			str_ret.push_back(u'-');
			l64_temp = -l64_temp;
		}
		std::u16string reverse_str;
		while (true)
		{
			long long ld_div = l64_temp / 10;
			long long ld_mod = l64_temp % 10;
			reverse_str.push_back(num_tables[ld_mod]);
			l64_temp = ld_div;
			if (l64_temp == 0)
			{
				break;
			}
		}
		for (std::u16string::reverse_iterator rit = reverse_str.rbegin();
			rit != reverse_str.rend(); rit++)
		{
			str_ret.push_back(*rit);
		}
		return str_ret;
	}

	std::u32string long64_to_u32string(long long l64_input)
	{
		long long l64_temp = l64_input;
		std::u32string str_ret;
		static char32_t num_tables[] = U"0123456789";
		if (l64_temp == 0)
		{
			return U"0";
		}
		else if (l64_temp < 0)
		{
			str_ret.push_back(U'-');
			l64_temp = -l64_temp;
		}
		std::u32string reverse_str;
		while (true)
		{
			long long ld_div = l64_temp / 10;
			long long ld_mod = l64_temp % 10;
			reverse_str.push_back(num_tables[ld_mod]);
			l64_temp = ld_div;
			if (l64_temp == 0)
			{
				break;
			}
		}
		for (std::u32string::reverse_iterator rit = reverse_str.rbegin();
			rit != reverse_str.rend(); rit++)
		{
			str_ret.push_back(*rit);
		}
		return str_ret;
	}

	std::string long_double_to_string(long double ld64_input, int n_decimal_digits)
	{
		std::string str_ret;
		static char num_tables[] = "0123456789";
		//bool b_minus = false;
		if (ld64_input == 0)
		{
			return "0";
		}
		else if (ld64_input < 0)
		{
			str_ret.push_back('-');
			ld64_input = -ld64_input;
		}
		std::string reverse_str;
		long long l64_point_front = (long long)ld64_input;
		long double l64_point_back = ld64_input - l64_point_front;
		while (true)
		{
			long long ld_div = l64_point_front / 10;
			long long ld_mod = l64_point_front % 10;
			reverse_str.push_back(num_tables[ld_mod]);
			l64_point_front = ld_div;
			if (l64_point_front == 0)
			{
				break;
			}
		}
		for (std::string::reverse_iterator rit = reverse_str.rbegin(); rit != reverse_str.rend(); rit++)
		{
			str_ret.push_back(*rit);
		}
		str_ret.push_back('.');
		//小数点之后
		while (true)
		{
			if (n_decimal_digits-- <= 0)
			{
				break;
			}
			long double ld_div = l64_point_back * 10;
			long long ld_mod = ((long long)ld_div) % 10;
			l64_point_back = (long double)ld_div - (long long)ld_mod;
			str_ret.push_back(num_tables[ld_mod]);
		}
		return str_ret;
	}

	std::u16string long_double_to_u16string(long double ld64_input,
		int n_decimal_digits)
	{
		std::u16string str_ret;
		static char16_t num_tables[] = u"0123456789";
		//bool b_minus = false;
		if (ld64_input == 0)
		{
			return u"0";
		}
		else if (ld64_input < 0)
		{
			str_ret.push_back(u'-');
			ld64_input = -ld64_input;
		}
		std::u16string reverse_str;
		long long l64_point_front = (long long)ld64_input;
		long double l64_point_back = ld64_input - l64_point_front;
		while (true)
		{
			long long ld_div = l64_point_front / 10;
			long long ld_mod = l64_point_front % 10;
			reverse_str.push_back(num_tables[ld_mod]);
			l64_point_front = ld_div;
			if (l64_point_front == 0)
			{
				break;
			}
		}
		for (std::u16string::reverse_iterator rit = reverse_str.rbegin(); rit != reverse_str.rend(); rit++)
		{
			str_ret.push_back(*rit);
		}
		str_ret.push_back(u'.');
		//小数点之后
		while (true)
		{
			if (n_decimal_digits-- <= 0)
			{
				break;
			}
			long double ld_div = l64_point_back * 10;
			long long ld_mod = ((long long)ld_div) % 10;
			l64_point_back = (long double)ld_div - (long long)ld_mod;
			str_ret.push_back(num_tables[ld_mod]);
		}
		return str_ret;
	}

	std::u32string long_double_to_u32string(long double ld64_input,
		int n_decimal_digits)
	{
		std::u32string str_ret;
		static char32_t num_tables[] = U"0123456789";
		//bool b_minus = false;
		if (ld64_input == 0)
		{
			return U"0";
		}
		else if (ld64_input < 0)
		{
			str_ret.push_back(U'-');
			ld64_input = -ld64_input;
		}
		std::u32string reverse_str;
		long long l64_point_front = (long long)ld64_input;
		long double l64_point_back = ld64_input - l64_point_front;
		while (true)
		{
			long long ld_div = l64_point_front / 10;
			long long ld_mod = l64_point_front % 10;
			reverse_str.push_back(num_tables[ld_mod]);
			l64_point_front = ld_div;
			if (l64_point_front == 0)
			{
				break;
			}
		}
		for (std::u32string::reverse_iterator rit = reverse_str.rbegin(); rit != reverse_str.rend(); rit++)
		{
			str_ret.push_back(*rit);
		}
		str_ret.push_back(U'.');
		//小数点之后
		while (true)
		{
			if (n_decimal_digits-- <= 0)
			{
				break;
			}
			long double ld_div = l64_point_back * 10;
			long long ld_mod = ((long long)ld_div) % 10;
			l64_point_back = (long double)ld_div - (long long)ld_mod;
			str_ret.push_back(num_tables[ld_mod]);
		}
		return str_ret;
	}

}
//namespace convert_type

namespace uft_conv
{
	//typedef unsigned long uint32;
	//typedef unsigned short int uint16;
	//typedef unsigned char uint8;

	bool utf8_to_utf32(const std::string &str_input, std::u32string &str_output)
	{
		str_output.clear();
		//n_buffer_len为最长元素个数
		size_t n_buffer_len = str_input.size() + 1;
		size_t n_buffer_safe_len = n_buffer_len - 1;
		size_t n_buffer_size = n_buffer_len * sizeof(UTF32);
		UTF32 *utf_buffer = new UTF32[n_buffer_len];
		UTF32 *utf_buffer_bak = utf_buffer;
		UTF32 *utf_buffer_end = utf_buffer + n_buffer_safe_len;
		memset((void *)utf_buffer, 0, n_buffer_size);
		const UTF8 *u8_start = (const UTF8 *)str_input.c_str();
		const UTF8 *u8_end = u8_start + str_input.size();
		bool bret = false;
		ConversionResult conv_ret = ConvertUTF8toUTF32(&u8_start, u8_end, &utf_buffer,
			utf_buffer_end, strictConversion);
		if (conv_ret == conversionOK)
		{
			bret = true;
			str_output.append((char32_t *)utf_buffer_bak);
		}
		delete[] utf_buffer_bak;
		return bret;
	}

	bool utf32_to_utf8(const std::u32string &str_input, std::string &str_output)
	{
		str_output.clear();
		//一个UFT32字符最大可变成6个字节的UTF8
		size_t n_buffer_len = str_input.size() * 6 + 1;
		size_t n_buffer_safe_len = n_buffer_len - 1;
		size_t n_buffer_size = n_buffer_len * sizeof(UTF8);
		UTF8 *utf_buffer = new UTF8[n_buffer_len];
		UTF8 *utf_buffer_bak = utf_buffer;
		UTF8 *utf_buffer_end = utf_buffer + n_buffer_safe_len;
		memset((void *)utf_buffer, 0, n_buffer_size);
		const UTF32 *u32_start = (const UTF32 *)str_input.c_str();
		const UTF32 *u32_end = u32_start + str_input.size();
		bool bret = false;
		ConversionResult conv_ret = ConvertUTF32toUTF8(&u32_start, u32_end, &utf_buffer,
			utf_buffer_end, strictConversion);
		if (conv_ret == conversionOK)
		{
			bret = true;
			str_output.append((char *)utf_buffer_bak);
		}
		delete[] utf_buffer_bak;
		return bret;
	}

	bool utf16_to_utf32(const std::u16string &str_input, std::u32string &str_output)
	{
		str_output.clear();
		//UTF16存放一个字最多需要4个字节，一个UFT字符为2个字节，所以转化为UTF32最大需要size()*2个字节
		size_t n_buffer_len = str_input.size() + 1;
		size_t n_buffer_safe_len = n_buffer_len - 1;
		size_t n_buffer_size = n_buffer_len * sizeof(UTF32);
		UTF32 *utf_buffer = new UTF32[n_buffer_len];
		UTF32 *utf_buffer_bak = utf_buffer;
		UTF32 *utf_buffer_end = utf_buffer + n_buffer_safe_len;
		memset((void *)utf_buffer, 0, n_buffer_size);
		const UTF16 *u16_start = (const UTF16 *)str_input.c_str();
		const UTF16 *u16_end = u16_start + str_input.size();
		bool bret = false;
		ConversionResult conv_ret = ConvertUTF16toUTF32(&u16_start, u16_end,
			&utf_buffer, utf_buffer_end, strictConversion);
		if (conv_ret == conversionOK)
		{
			bret = true;
			str_output.append((char32_t *)utf_buffer_bak);
		}
		delete[] utf_buffer_bak;
		return bret;
	}

	bool utf32_to_utf16(const std::u32string &str_input, std::u16string &str_output)
	{
		str_output.clear();
		//UTF16存放一个字最多需要4个字节，一个UFT字符为2个字节，所以转化为UTF32最大需要size()*2个字节
		size_t n_buffer_len = str_input.size() * 2 + 1;
		size_t n_buffer_safe_len = n_buffer_len - 1;
		size_t n_buffer_size = n_buffer_len * sizeof(UTF16);
		UTF16 *utf_buffer = new UTF16[n_buffer_len];
		UTF16 *utf_buffer_bak = utf_buffer;
		UTF16 *utf_buffer_end = utf_buffer + n_buffer_safe_len;
		memset((void *)utf_buffer, 0, n_buffer_size);
		const UTF32 *u32_start = (const UTF32 *)str_input.c_str();
		const UTF32 *u32_end = u32_start + str_input.size();
		bool bret = false;
		ConversionResult conv_ret = ConvertUTF32toUTF16(&u32_start, u32_end,
			&utf_buffer, utf_buffer_end, strictConversion);
		if (conv_ret == conversionOK)
		{
			bret = true;
			str_output.append((char16_t *)utf_buffer_bak);
		}
		delete[] utf_buffer_bak;
		return bret;
	}

	bool utf8_to_utf16(const std::string &str_input, std::u16string &str_output)
	{
		str_output.clear();
		//n_buffer_len为最长元素个数
		size_t n_buffer_len = str_input.size() + 1;
		size_t n_buffer_safe_len = n_buffer_len - 1;
		size_t n_buffer_size = n_buffer_len * sizeof(UTF16);
		UTF16 *utf_buffer = new UTF16[n_buffer_len];
		UTF16 *utf_buffer_bak = utf_buffer;
		UTF16 *utf_buffer_end = utf_buffer + n_buffer_safe_len;
		memset((void *)utf_buffer, 0, n_buffer_size);
		const UTF8 *u8_start = (const UTF8 *)str_input.c_str();
		const UTF8 *u8_end = u8_start + str_input.size();
		bool bret = false;
		ConversionResult conv_ret = ConvertUTF8toUTF16(&u8_start, u8_end, &utf_buffer,
			utf_buffer_end, strictConversion);
		if (conv_ret == conversionOK)
		{
			bret = true;
			str_output.append((char16_t *)utf_buffer_bak);
		}
		delete[] utf_buffer_bak;
		return bret;
	}

	bool utf16_to_utf8(const std::u16string &str_input, std::string &str_output)
	{
		str_output.clear();
		//2个UFT16字符最大可变成6个字节的UTF8
		size_t n_buffer_len = str_input.size() * 6 + 1;
		size_t n_buffer_safe_len = n_buffer_len - 1;
		size_t n_buffer_size = n_buffer_len * sizeof(UTF8);
		UTF8 *utf_buffer = new UTF8[n_buffer_len];
		UTF8 *utf_buffer_bak = utf_buffer;
		UTF8 *utf_buffer_end = utf_buffer + n_buffer_safe_len;
		memset((void *)utf_buffer, 0, n_buffer_size);
		const UTF16 *u16_start = (const UTF16 *)str_input.c_str();
		const UTF16 *u16_end = u16_start + str_input.size();
		bool bret = false;
		ConversionResult conv_ret = ConvertUTF16toUTF8(&u16_start, u16_end, &utf_buffer,
			utf_buffer_end, strictConversion);
		if (conv_ret == conversionOK)
		{
			bret = true;
			str_output.append((char *)utf_buffer_bak);
		}
		delete[] utf_buffer_bak;
		return bret;
	}


#ifdef _MSC_VER
	std::wstring u16string_to_wstring(const std::u16string &str_input)
	{
		std::wstring wstr_ret;
		std::u16string::size_type n_input = str_input.size();
		wstr_ret.resize(n_input);
		for (std::u16string::size_type i = 0; i < n_input; i++)
		{
			wstr_ret[i] = str_input[i];
		}
		return wstr_ret;
	}

	std::u16string wstring_to_u16string(const std::wstring &str_input)
	{
		std::u16string u16str_ret;
		std::u16string::size_type n_input = str_input.size();
		u16str_ret.resize(n_input);
		for (std::u16string::size_type i = 0; i < n_input; i++)
		{
			u16str_ret[i] = str_input[i];
		}
		return u16str_ret;
	}

	bool utf8_to_wstring(const std::string &str_input, std::wstring &str_output)
	{
		std::u16string u16_str;
		if (utf8_to_utf16(str_input, u16_str) == true)
		{
			str_output = u16string_to_wstring(u16_str);
			return true;
		}
		return false;
	}

	bool utf16_to_wstring(const std::u16string &str_input, std::wstring &str_output)
	{
		std::u16string u16_str;
		str_output = u16string_to_wstring(u16_str);
		return true;
	}

	bool utf32_to_wstring(const std::u32string &str_input, std::wstring &str_output)
	{
		std::u16string u16_str;
		if (utf32_to_utf16(str_input, u16_str) == true)
		{
			str_output = u16string_to_wstring(u16_str);
			return true;
		}
		return false;
	}

#elif __GNUC__
	std::wstring u32string_to_wstring(const std::u32string &str_input)
	{
		std::wstring wstr_ret;
		std::u32string::size_type n_input = str_input.size();
		wstr_ret.resize(n_input);
		for (std::u32string::size_type i = 0; i < n_input; i++)
		{
			wstr_ret[i] = str_input[i];
		}
		return wstr_ret;
	}

	std::u32string wstring_to_u32string(const std::wstring &str_input)
	{
		std::u32string u32str_ret;
		std::u32string::size_type n_input = str_input.size();
		u32str_ret.resize(n_input);
		for (std::u32string::size_type i = 0; i < n_input; i++)
		{
			u32str_ret[i] = str_input[i];
		}
		return u32str_ret;
	}

	bool utf8_to_wstring(const std::string &str_input, std::wstring &str_output)
	{
		std::u32string u32_str;
		if (utf8_to_utf32(str_input, u32_str) == true)
		{
			str_output = u32string_to_wstring(u32_str);
			return true;
		}
		return false;
	}

	bool utf16_to_wstring(const std::u16string &str_input, std::wstring &str_output)
	{
		std::u32string u32_str;
		if (utf16_to_utf32(str_input, u32_str) == true)
		{
			str_output = u32string_to_wstring(u32_str);
			return true;
		}
		return false;
	}

	bool utf32_to_wstring(const std::u32string &str_input, std::wstring &str_output)
	{
		str_output = u32string_to_wstring(str_input);
		return true;
	}
	//#endif __GNUC__
	//#elif __MINGW32__

#endif // !_MSC_VER

}