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

namespace string_printf
{
    /*
    std::string suprintf(const std::string format, ...)
    {
        std::string formated;
        
        va_list arg_ptr;
        va_start(arg_ptr,format);
        for (auto it_ch=format.cbegin();it_ch!=format.cend();it_ch++)
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
                        std::string string_number = convert_type::int_to_string(n_argv);
                        if(n_fill_flag == SUPRINTF_FILL_FLAG::ENABLE_FILL)
                        {
                            std::string string_fill_number;
                            fill_number_character_to_min_width(string_fill_number,string_number,n_vector_flag,n_width,n_fill_char);
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
                        std::string string_number = convert_type::float_to_string(f_argv,n_precision);
                        if(n_fill_flag == SUPRINTF_FILL_FLAG::ENABLE_FILL)
                        {
                            std::string string_fill_number;
                            fill_number_character_to_min_width(string_fill_number,string_number,n_vector_flag,n_width,n_fill_char);
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
                        std::string string_data = convert_type::int_to_hex_string(n_argv);
                        if(n_fill_flag == SUPRINTF_FILL_FLAG::ENABLE_FILL)
                        {
                            std::string string_fill_data;
                            fill_character_to_min_width(string_fill_data,string_data,n_vector_flag,n_width,n_fill_char);
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
                        std::string string_data = convert_type::int_to_hex_string(n_argv);
                        toupper(string_data);
                        if(n_fill_flag == SUPRINTF_FILL_FLAG::ENABLE_FILL)
                        {
                            std::string string_fill_data;
                            fill_character_to_min_width(string_fill_data,string_data,n_vector_flag,n_width,n_fill_char);
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
                        std::string string_data = convert_type::int_to_oct_string(n_argv);
                        if(n_fill_flag == SUPRINTF_FILL_FLAG::ENABLE_FILL)
                        {
                            std::string string_fill_data;
                            fill_character_to_min_width(string_fill_data,string_data,n_vector_flag,n_width,n_fill_char);
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
                        std::string string_data = convert_type::int_to_oct_string(n_argv);
                        toupper(string_data);
                        if(n_fill_flag == SUPRINTF_FILL_FLAG::ENABLE_FILL)
                        {
                            std::string string_fill_data;
                            fill_character_to_min_width(string_fill_data,string_data,n_vector_flag,n_width,n_fill_char);
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
                        const char* s_argv = va_arg(arg_ptr, char*);
                        std::string string_data(s_argv);
                        if(n_fill_flag == SUPRINTF_FILL_FLAG::ENABLE_FILL)
                        {
                            std::string string_fill_data;
                            fill_character_to_min_width(string_fill_data,string_data,n_vector_flag,n_width,n_fill_char);
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
                        const std::string* s_ptr_argv = va_arg(arg_ptr, std::string*);
                        std::string string_data(*s_ptr_argv);
                        if(n_fill_flag == SUPRINTF_FILL_FLAG::ENABLE_FILL)
                        {
                            std::string string_fill_data;
                            fill_character_to_min_width(string_fill_data,string_data,n_vector_flag,n_width,n_fill_char);
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
                        void* ptrv = va_arg(arg_ptr, void*);
                        unsigned long long n_ptr= (unsigned long long)ptrv;
                        std::string string_data = convert_type::int_to_hex_string(n_ptr);
                        std::string string_fill_data;
                        fill_character_to_min_width(string_fill_data,string_data,n_vector_flag,sizeof(void*),n_fill_char);
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
        va_end(arg_ptr);
        return formated;
    }
    */
    /*
    std::string suprintf(const char *format, ...)
    {
        va_list arg_ptr;
        va_start(arg_ptr,format);
        std::string sformat(format);
        std::string ret = tsuprintf(sformat,arg_ptr);
        va_end(arg_ptr);
        return ret;
    }
    */
    std::string suprintf(const std::string format, ...)
    {
        va_list arg_ptr;
        va_start(arg_ptr,format);
        std::string ret = tsuprintf(format,arg_ptr);
        va_end(arg_ptr);
        return ret;
    }
    
    std::u16string suprintf(const std::u16string format, ...)
    {
        va_list arg_ptr;
        va_start(arg_ptr,format);
        std::u16string ret = tsuprintf(format,arg_ptr);
        va_end(arg_ptr);
        return ret;
    }
    
    std::u32string suprintf(const std::u32string format, ...)
    {
        va_list arg_ptr;
        va_start(arg_ptr,format);
        std::u32string ret = tsuprintf(format,arg_ptr);
        va_end(arg_ptr);
        return ret;
    }
} //namespace string_printf end