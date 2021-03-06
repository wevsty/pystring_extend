﻿#if defined(_MSC_VER)
    #pragma once
#endif
#ifndef __DATA_CONVERT_CPP__
#define __DATA_CONVERT_CPP__
#include "pystring_define.h"
#include <vector>
#include <string>
#include <memory.h>
#include <algorithm>

namespace convert_type
{
    //typedef long long int_max_t;
    template <typename STRING_TYPE>
    long long to_int_max(const STRING_TYPE str_input)
    {
        bool b_minus = false;
        long long n_ret = 0;
        if (str_input.empty() == true)
        {
            return n_ret;
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
                n_ret = ((n_ret * 10) + n_num);
            }
        }
        if (b_minus == true)
        {
            return -n_ret;
        }
        return n_ret;
    }

    //template<>
    long long to_int_max(const char *str_input);
    //template <>
    long long to_int_max(const char16_t *str_input);
    //template <>
    long long to_int_max(const char32_t *str_input);


    template <typename STRING_TYPE>
    long double to_float_max(const STRING_TYPE str_input)
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

    //template <>
    long double to_float_max(const char *str_input);
    //template <>
    long double to_float_max(const char16_t *str_input);
    //template <>
    long double to_float_max(const char32_t *str_input);

    // long 64 to string
    std::string int_to_string(long long l64_input);
    std::u16string int_to_u16string(long long l64_input);
    std::u32string int_to_u32string(long long l64_input);

    inline void int_to_string(std::string &str_output, long long l64_input)
    {
        str_output = int_to_string(l64_input);
    }

    inline void int_to_string(std::u16string &str_output, long long l64_input)
    {
        str_output = int_to_u16string(l64_input);
    }

    inline void int_to_string(std::u32string &str_output, long long l64_input)
    {
        str_output = int_to_u32string(l64_input);
    }


    //long double to string
    std::string float_to_string(long double ld64_input, int n_decimal_digits = 2);
    std::u16string float_to_u16string(long double ld64_input, int n_decimal_digits = 2);
    std::u32string float_to_u32string(long double ld64_input, int n_decimal_digits = 2);

    inline void float_to_string(std::string &str_output, long double ld64_input, int n_decimal_digits = 2)
    {
        str_output = float_to_string(ld64_input, n_decimal_digits);
    }

    inline void float_to_string(std::u16string &str_output, long double ld64_input, int n_decimal_digits = 2)
    {
        str_output = float_to_u16string(ld64_input, n_decimal_digits);
    }

    inline void float_to_string(std::u32string &str_output, long double ld64_input, int n_decimal_digits = 2)
    {
        str_output = float_to_u32string(ld64_input, n_decimal_digits);
    }

    std::string int_to_hex_string(long long num);
    std::u16string int_to_hex_u16string(long long num);
    std::u32string int_to_hex_u32string(long long num);

    inline void int_to_hex_string(std::string &str_output, long long num)
    {
        str_output = int_to_hex_string(num);
    }

    inline void int_to_hex_string(std::u16string &str_output, long long num)
    {
        str_output = int_to_hex_u16string(num);
    }

    inline void int_to_hex_string(std::u32string &str_output, long long num)
    {
        str_output = int_to_hex_u32string(num);
    }

    std::string int_to_oct_string(long long num);
    std::u16string int_to_oct_u16string(long long num);
    std::u32string int_to_oct_u32string(long long num);

    inline void int_to_oct_string(std::string &str_output, long long num)
    {
        str_output = int_to_oct_string(num);
    }

    inline void int_to_oct_string(std::u16string &str_output, long long num)
    {
        str_output = int_to_oct_u16string(num);
    }

    inline void int_to_oct_string(std::u32string &str_output, long long num)
    {
        str_output = int_to_oct_u32string(num);
    }

    template <typename OUTPUT_TYPE, typename INPUT_TYPE>
    std::vector<OUTPUT_TYPE> convert_vector_type(std::vector<INPUT_TYPE> vec_input)
    {
        std::vector<OUTPUT_TYPE> vec_ret;
        size_t n_vec_input_size = vec_input.size();
        vec_ret.resize(n_vec_input_size);
        for (size_t i = 0; i < n_vec_input_size; i++)
        {
            vec_ret[i] = vec_input[i];
        }
        return vec_ret;
    }

    template <typename OUTPUT_TYPE, typename INPUT_TYPE>
    std::vector<OUTPUT_TYPE> convert_vector_type_move(std::vector<INPUT_TYPE> vec_input)
    {
        std::vector<OUTPUT_TYPE> vec_ret;
        size_t n_vec_input_size = vec_input.size();
        vec_ret.resize(n_vec_input_size);
        for (size_t i = 0; i < n_vec_input_size; i++)
        {
            vec_ret[i] = std::move(vec_input[i]);
        }
        return vec_ret;
    }
}

namespace uft_conv
{
    bool utf8_to_utf32(const std::string &str_input, std::u32string &str_output);
    bool utf32_to_utf8(const std::u32string &str_input, std::string &str_output);
    bool utf16_to_utf32(const std::u16string &str_input, std::u32string &str_output);
    bool utf32_to_utf16(const std::u32string &str_input, std::u16string &str_output);
    bool utf8_to_utf16(const std::string &str_input, std::u16string &str_output);
    bool utf16_to_utf8(const std::u16string &str_input, std::string &str_output);

#ifdef WCHAR_IS_UTF16CHAR
    std::wstring u16string_to_wstring(const std::u16string &str_input);
    std::u16string wstring_to_u16string(const std::wstring &str_input);
    bool utf8_to_wstring(const std::string &str_input, std::wstring &str_output);
    bool utf16_to_wstring(const std::u16string &str_input, std::wstring &str_output);
    bool utf32_to_wstring(const std::u32string &str_input, std::wstring &str_output);
    bool wstring_to_utf8(const std::wstring &str_input,std::string &str_output);
    bool wstring_to_utf16(const std::wstring &str_input,std::u16string &str_output);
    bool wstring_to_utf32(const std::wstring &str_input,std::u32string &str_output);
#elif WCHAR_IS_UTF32CHAR
    std::wstring u32string_to_wstring(const std::u32string &str_input);
    std::u32string wstring_to_u32string(const std::wstring &str_input);
    bool utf8_to_wstring(const std::string &str_input, std::wstring &str_output);
    bool utf16_to_wstring(const std::u16string &str_input, std::wstring &str_output);
    bool utf32_to_wstring(const std::u32string &str_input, std::wstring &str_output);
    bool wstring_to_utf8(const std::wstring &str_input,std::string &str_output);
    bool wstring_to_utf16(const std::wstring &str_input,std::u16string &str_output);
    bool wstring_to_utf32(const std::wstring &str_input,std::u32string &str_output);
#endif // !WCHAR_IS_UTF16CHAR

    inline void convert_utf_string(std::string &input,std::string& output)
    {
        output = input;
    }
    
    inline void convert_utf_string(std::string &input,std::wstring& output)
    {
        utf8_to_wstring(input,output);
    }
    
    inline void convert_utf_string(std::string &input,std::u16string& output)
    {
        utf8_to_utf16(input,output);
    }
    
    inline void convert_utf_string(std::string &input,std::u32string& output)
    {
        utf8_to_utf32(input,output);
    }
    
    inline void convert_utf_string(std::wstring &input,std::string& output)
    {
        wstring_to_utf8(input,output);
    }
    
    inline void convert_utf_string(std::wstring &input,std::wstring& output)
    {  
        output = input;
    }
    
    inline void convert_utf_string(std::wstring &input,std::u16string& output)
    {
        wstring_to_utf16(input,output);
    }
    
    inline void convert_utf_string(std::wstring &input,std::u32string& output)
    {
        wstring_to_utf32(input,output);
    }
    
    inline void convert_utf_string(std::u16string &input,std::string& output)
    {
        utf16_to_utf8(input,output);
    }
    
    inline void convert_utf_string(std::u16string &input,std::wstring& output)
    {
        utf16_to_wstring(input,output);
    }
    
    inline void convert_utf_string(std::u16string &input,std::u16string& output)
    {
        output = input;
    }
    
    inline void convert_utf_string(std::u16string &input,std::u32string& output)
    {
        utf16_to_utf32(input,output);
    }
    
    inline void convert_utf_string(std::u32string &input,std::string& output)
    {
        utf32_to_utf8(input,output);
    }
    
    inline void convert_utf_string(std::u32string &input,std::wstring& output)
    {
        utf32_to_wstring(input,output);
    }
    
    inline void convert_utf_string(std::u32string &input,std::u16string& output)
    {
        utf32_to_utf16(input,output);
    }
    
    inline void convert_utf_string(std::u32string &input,std::u32string& output)
    {
        output = input;
    }

}
#endif // __UTF_CONVERT_CPP__
