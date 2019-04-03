#if defined(_MSC_VER)
    #pragma once
#endif


#ifndef __FORMAT_STRING_TEMPLATE_H__
#define __FORMAT_STRING_TEMPLATE_H__

#include "pystring_algorithm_template.h"
#include "convert_data.h"
#include <cstdarg>

namespace string_format
{
    template <typename T_STRING>
    void replace_argv_once(T_STRING &str_input, const T_STRING &old_str, const T_STRING &new_str)
    {
        if (old_str.empty())
        {
            return;
        }
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

    std::string &format_argv(std::string &str_input, int n);
    std::u16string &format_argv(std::u16string &str_input, int n);
    std::u32string &format_argv(std::u32string &str_input, int n);

    std::string &format_argv(std::string &str_input, long double ld64_input, int n_decimal_digits = 2);
    std::u16string &format_argv(std::u16string &str_input, long double ld64_input, int n_decimal_digits = 2);
    std::u32string &format_argv(std::u32string &str_input, long double ld64_input, int n_decimal_digits = 2);

    std::string &format_argv(std::string &str_input, const std::string &str_argv);
    std::u16string &format_argv(std::u16string &str_input, const std::u16string &str_argv);
    std::u32string &format_argv(std::u32string &str_input, const std::u32string &str_argv);

}

namespace string_printf
{
    enum SUPRINTF_VECTOR_FLAG
    {
        //+
        PLUS = 0,
        //-
        MINUS
    };

    template <typename T_STRING>
    void fill_character_to_min_width(T_STRING &buffer, const T_STRING &input, unsigned int n_vector_flag, unsigned int n_width, int fill_character)
    {
        if(input.size() >= n_width)
        {
            buffer = input;
        }
        else
        {
            unsigned int n_fill_size = n_width - input.size();
            if(n_vector_flag == SUPRINTF_VECTOR_FLAG::PLUS)
            {
                for(unsigned int i = 0; i < n_fill_size; i++)
                {
                    buffer.push_back(fill_character);
                }
                buffer.append(input);
            }
            else
            {
                buffer.append(input);
                for(unsigned int i = 0; i < n_fill_size; i++)
                {
                    buffer.push_back(fill_character);
                }
            }
        }
    }

    template <typename T_STRING>
    void fill_number_character_to_min_width(T_STRING &buffer, const T_STRING &input, unsigned int n_vector_flag, unsigned int n_width, int fill_character)
    {
        if(input.size() >= n_width)
        {
            buffer = input;
        }
        else
        {
            unsigned int n_fill_size = n_width - input.size();
            bool b_dot = false;
            T_STRING remove_symbol_input(input);
            for(auto it = input.cbegin(); it != input.cend(); it++)
            {
                auto ch = *it;
                if(ch == '+' || ch == '-')
                {
                    buffer.push_back(ch);
                    n_fill_size--;
                }
                else if(ch == '.' )
                {
                    b_dot = true;
                    remove_symbol_input.push_back(ch);
                }
                else
                {
                    remove_symbol_input.push_back(ch);
                }
            }

            if(n_vector_flag == SUPRINTF_VECTOR_FLAG::PLUS)
            {
                for(unsigned int i = 0; i < n_fill_size; i++)
                {
                    buffer.push_back(fill_character);
                }
                buffer.append(input);
            }
            else
            {
                buffer.append(input);
                for(unsigned int i = 0; i < n_fill_size; i++)
                {
                    if(b_dot == true)
                    {
                        buffer.push_back(fill_character);
                    }
                    else
                    {
                        buffer.push_back('.');
                        b_dot = true;
                    }
                }
            }
        }
    }

    template <typename T_STRING>
    void tolower(T_STRING &input)
    {
        const size_t n_strlen = input.size();
        for (size_t i = 0; i < n_strlen; i++)
        {
            auto &ch = input.at(i);
            ch = std::tolower(ch);
        }
    }

    template <typename T_STRING>
    void toupper(T_STRING &input)
    {
        const size_t n_strlen = input.size();
        for (size_t i = 0; i < n_strlen; i++)
        {
            auto &ch = input.at(i);
            ch = std::tolower(ch);
        }
    }

    enum SUPRINTF_EXPRESSION_STATUS
    {
        //百分号标志
        PERCENT_FLAG = 0,
        //方向标志
        //VECTOR_FLAG,
        //宽度标志
        //WIDTH_FLAG,
        //小数点标志
        DOT_FLAG,
        //精度标志
        //PRECISION_FLAG
    };

    enum SUPRINTF_FILL_FLAG
    {
        //填充标志
        DISABLE_FILL = 0,
        ENABLE_FILL
    };

    //suprintf 模板
    //T_STRING tsuprintf(const T_STRING format, ...)
    //由于...无法传递，改为传递va_list
    template <typename T_STRING>
    T_STRING tsuprintf(const T_STRING format, va_list arg_ptr)
    {
        T_STRING formated;

        //va_list arg_ptr;
        //va_start(arg_ptr,format);
        for (auto it_ch = format.cbegin(); it_ch != format.cend(); it_ch++)
        {
            auto ch = *it_ch;
            if(ch == '%')
            {
                int n_vector_flag = 0;
                int n_fill_flag = SUPRINTF_FILL_FLAG::DISABLE_FILL;
                int n_fill_char = ' ';
                int n_width = 0;
                int n_precision = 2;
                int n_expression_status = SUPRINTF_EXPRESSION_STATUS::PERCENT_FLAG;
                while(++it_ch != format.cend())
                {
                    ch = *(it_ch);
                    //char next_ch = 0;
                    //if(it_ch+1 != format.cend())
                    //{
                    //    next_ch = *(it_ch);
                    //}
                    if(ch == '%')
                    {
                        formated.push_back(ch);
                        break;
                    }
                    else if(ch == '+')
                    {
                        n_vector_flag = SUPRINTF_VECTOR_FLAG::PLUS;
                        //continue
                    }
                    else if(ch == '-')
                    {
                        n_vector_flag = SUPRINTF_VECTOR_FLAG::MINUS;
                    }
                    else if(ch == '0')
                    {
                        n_fill_char = '0';
                    }
                    else if((ch >= '0') && (ch <= '9'))
                    {
                        if(n_expression_status < SUPRINTF_EXPRESSION_STATUS::DOT_FLAG)
                        {
                            n_width = ch - '0';
                        }
                        else
                        {
                            n_precision = ch - '0';
                        }
                        n_fill_flag = SUPRINTF_FILL_FLAG::ENABLE_FILL;
                    }
                    else if(ch == '.')
                    {
                        n_expression_status = SUPRINTF_EXPRESSION_STATUS::DOT_FLAG;
                    }
                    else if(ch == 'c')
                    {
                        int push_ch = va_arg(arg_ptr, int);
                        formated.push_back(push_ch);
                        break;
                    }
                    else if(ch == 'd')
                    {
                        int n_argv = va_arg(arg_ptr, int);
                        T_STRING string_number;
                        convert_type::int_to_string(string_number, n_argv);
                        if(n_fill_flag == SUPRINTF_FILL_FLAG::ENABLE_FILL)
                        {
                            T_STRING string_fill_number;
                            fill_number_character_to_min_width(string_fill_number, string_number, n_vector_flag, n_width, n_fill_char);
                            formated.append(string_fill_number);
                        }
                        else
                        {
                            formated.append(string_number);
                        }
                        break;
                    }
                    else if(ch == 'f')
                    {
                        double f_argv = va_arg(arg_ptr, double);
                        T_STRING string_number;
                        convert_type::float_to_string(string_number, f_argv, n_precision);
                        if(n_fill_flag == SUPRINTF_FILL_FLAG::ENABLE_FILL)
                        {
                            T_STRING string_fill_number;
                            fill_number_character_to_min_width(string_fill_number, string_number, n_vector_flag, n_width, n_fill_char);
                            formated.append(string_fill_number);
                        }
                        else
                        {
                            formated.append(string_number);
                        }
                        break;
                    }
                    else if(ch == 'x')
                    {
                        int n_argv = va_arg(arg_ptr, int);
                        T_STRING string_data;
                        convert_type::int_to_hex_string(string_data, n_argv);
                        if(n_fill_flag == SUPRINTF_FILL_FLAG::ENABLE_FILL)
                        {
                            T_STRING string_fill_data;
                            fill_character_to_min_width(string_fill_data, string_data, n_vector_flag, n_width, n_fill_char);
                            formated.append(string_fill_data);
                        }
                        else
                        {
                            formated.append(string_data);
                        }
                        break;
                    }
                    else if(ch == 'X')
                    {
                        int n_argv = va_arg(arg_ptr, int);
                        T_STRING string_data;
                        convert_type::int_to_hex_string(string_data, n_argv);
                        toupper(string_data);
                        if(n_fill_flag == SUPRINTF_FILL_FLAG::ENABLE_FILL)
                        {
                            T_STRING string_fill_data;
                            fill_character_to_min_width(string_fill_data, string_data, n_vector_flag, n_width, n_fill_char);
                            formated.append(string_fill_data);
                        }
                        else
                        {
                            formated.append(string_data);
                        }
                        break;
                    }
                    else if(ch == 'o')
                    {
                        int n_argv = va_arg(arg_ptr, int);
                        T_STRING string_data;
                        convert_type::int_to_oct_string(string_data, n_argv);
                        if(n_fill_flag == SUPRINTF_FILL_FLAG::ENABLE_FILL)
                        {
                            T_STRING string_fill_data;
                            fill_character_to_min_width(string_fill_data, string_data, n_vector_flag, n_width, n_fill_char);
                            formated.append(string_fill_data);
                        }
                        else
                        {
                            formated.append(string_data);
                        }
                        break;
                    }
                    else if(ch == 'O')
                    {
                        int n_argv = va_arg(arg_ptr, int);
                        T_STRING string_data;
                        convert_type::int_to_oct_string(string_data, n_argv);
                        toupper(string_data);
                        if(n_fill_flag == SUPRINTF_FILL_FLAG::ENABLE_FILL)
                        {
                            T_STRING string_fill_data;
                            fill_character_to_min_width(string_fill_data, string_data, n_vector_flag, n_width, n_fill_char);
                            formated.append(string_fill_data);
                        }
                        else
                        {
                            formated.append(string_data);
                        }
                        break;
                    }
                    else if(ch == 's')
                    {
                        //const char* s_argv = va_arg(arg_ptr, char*);
                        const decltype(ch) *s_argv = va_arg(arg_ptr, decltype(ch) *);
                        T_STRING string_data(s_argv);
                        if(n_fill_flag == SUPRINTF_FILL_FLAG::ENABLE_FILL)
                        {
                            T_STRING string_fill_data;
                            fill_character_to_min_width(string_fill_data, string_data, n_vector_flag, n_width, n_fill_char);
                            formated.append(string_fill_data);
                        }
                        else
                        {
                            formated.append(string_data);
                        }
                        break;
                    }
                    else if(ch == 'S')
                    {
                        const T_STRING *s_ptr_argv = va_arg(arg_ptr, T_STRING *);
                        T_STRING string_data(*s_ptr_argv);
                        if(n_fill_flag == SUPRINTF_FILL_FLAG::ENABLE_FILL)
                        {
                            T_STRING string_fill_data;
                            fill_character_to_min_width(string_fill_data, string_data, n_vector_flag, n_width, n_fill_char);
                            formated.append(string_fill_data);
                        }
                        else
                        {
                            formated.append(string_data);
                        }
                        break;
                    }
                    else if(ch == 'p')
                    {
                        void *ptrv = va_arg(arg_ptr, void *);
                        unsigned long long n_ptr = (unsigned long long)ptrv;
                        T_STRING string_data;
                        convert_type::int_to_hex_string(string_data, n_ptr);
                        T_STRING string_fill_data;
                        fill_character_to_min_width(string_fill_data, string_data, n_vector_flag, sizeof(void *), n_fill_char);
                        formated.append(string_fill_data);
                        break;
                    }
                    else
                    {
                        break;
                    }
                }

            }
            else
            {
                formated.push_back(ch);
            }
        }
        //va_end(arg_ptr);
        return formated;
    }
    //std::string suprintf(const char *format, ...);
    std::string suprintf(const std::string format, ...);
    std::u16string suprintf(const std::u16string format, ...);
    std::u32string suprintf(const std::u32string format, ...);
}

#endif
