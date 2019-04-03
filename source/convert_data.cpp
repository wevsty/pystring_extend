#include "convert_data.h"
#include "UnicodeConv.h"

namespace convert_type
{

    //template<>
    long long to_int_max(const char *str_input)
    {
        return to_int_max(std::string(str_input));
    }

    //template <>
    long long to_int_max(const char16_t *str_input)
    {
        return to_int_max(std::u16string(str_input));
    }

    //template <>
    long long to_int_max(const char32_t *str_input)
    {
        return to_int_max(std::u32string(str_input));
    }

    //template <>
    long double to_float_max(const char *str_input)
    {
        return to_float_max(std::string(str_input));
    }

    //template <>
    long double to_float_max(const char16_t *str_input)
    {
        return to_float_max(std::u16string(str_input));
    }

    //template <>
    long double to_float_max(const char32_t *str_input)
    {
        return to_float_max(std::u32string(str_input));
    }

    std::string int_to_string(long long l64_input)
    {
        long long l64_temp = l64_input;
        std::string str_ret;
        constexpr static const char num_tables[] = "0123456789";
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

    std::u16string int_to_u16string(long long l64_input)
    {
        long long l64_temp = l64_input;
        std::u16string str_ret;
        constexpr static const char16_t num_tables[] = u"0123456789";
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

    std::u32string int_to_u32string(long long l64_input)
    {
        long long l64_temp = l64_input;
        std::u32string str_ret;
        constexpr static const char32_t num_tables[] = U"0123456789";
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
    
    std::string float_to_string(long double ld64_input, int n_decimal_digits)
    {
        std::string str_ret;
        constexpr static const  char num_tables[] = "0123456789";
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

    std::u16string float_to_u16string(long double ld64_input,
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

    std::u32string float_to_u32string(long double ld64_input,
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
    
    std::string int_to_hex_string(long long input_number)
    {
        constexpr static const char hex_table[] = "0123456789abcdef";
        long long n_data = input_number;
        if (n_data == 0)
        {
            return "0";
        }
        std::string buffer;
        long long n_bytes_count = 0;
        long long n_bytes_len = sizeof(int);
        while(n_data != 0 && n_bytes_count++ < n_bytes_len)
        {
            buffer.push_back(hex_table[n_data & 0x0f]);
            n_data >>= 4;
        }
        std::reverse(buffer.begin(), buffer.end());
        return buffer;
    }

    std::u16string int_to_hex_u16string(long long input_number)
    {
        constexpr static const char16_t hex_table[] = u"0123456789abcdef";
        long long n_data = input_number;
        if (n_data == 0)
        {
            return u"0";
        }
        std::u16string buffer;
        long long n_bytes_count = 0;
        long long n_bytes_len = sizeof(int);
        while(n_data != 0 && n_bytes_count++ < n_bytes_len)
        {
            buffer.push_back(hex_table[n_data & 0x0f]);
            n_data >>= 4;
        }
        std::reverse(buffer.begin(), buffer.end());
        return buffer;
    }

    std::u32string int_to_hex_u32string(long long input_number)
    {
        constexpr static const char32_t hex_table[] = U"0123456789abcdef";
        long long n_data = input_number;
        if (n_data == 0)
        {
            return U"0";
        }
        std::u32string buffer;
        long long n_bytes_count = 0;
        long long n_bytes_len = sizeof(int);
        while(n_data != 0 && n_bytes_count++ < n_bytes_len)
        {
            buffer.push_back(hex_table[n_data & 0x0f]);
            n_data >>= 4;
        }
        std::reverse(buffer.begin(), buffer.end());
        return buffer;
    }
    
    std::string int_to_oct_string(long long input_number)
    {
        constexpr static const char oct_table[] = "01234567";
        long long n_data = input_number;
        if (n_data == 0)
        {
            return "0";
        }
        std::string buffer;
        long long n_bytes_count = 0;
        long long n_bytes_len = sizeof(int);
        while(n_data != 0 && n_bytes_count++ < n_bytes_len)
        {
            buffer.push_back(oct_table[n_data & 0x07]);
            n_data >>= 3;
        }
        std::reverse(buffer.begin(), buffer.end());
        return buffer;
    }

    std::u16string int_to_oct_u16string(long long input_number)
    {
        constexpr static const char16_t oct_table[] = u"01234567";
        long long n_data = input_number;
        if (n_data == 0)
        {
            return u"0";
        }
        std::u16string buffer;
        long long n_bytes_count = 0;
        long long n_bytes_len = sizeof(int);
        while(n_data != 0 && n_bytes_count++ < n_bytes_len)
        {
            buffer.push_back(oct_table[n_data & 0x07]);
            n_data >>= 3;
        }
        std::reverse(buffer.begin(), buffer.end());
        return buffer;
    }

    std::u32string int_to_oct_u32string(long long input_number)
    {
        constexpr static const char32_t oct_table[] = U"01234567";
        long long n_data = input_number;
        if (n_data == 0)
        {
            return U"0";
        }
        std::u32string buffer;
        long long n_bytes_count = 0;
        long long n_bytes_len = sizeof(int);
        while(n_data != 0 && n_bytes_count++ < n_bytes_len)
        {
            buffer.push_back(oct_table[n_data & 0x07]);
            n_data >>= 3;
        }
        std::reverse(buffer.begin(), buffer.end());
        return buffer;
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
        return ConvU8ToU32(str_input, str_output);
    }

    bool utf32_to_utf8(const std::u32string &str_input, std::string &str_output)
    {
        return ConvU32ToU8(str_input, str_output);
    }

    bool utf16_to_utf32(const std::u16string &str_input, std::u32string &str_output)
    {
        return ConvU16ToU32(str_input, str_output);
    }

    bool utf32_to_utf16(const std::u32string &str_input, std::u16string &str_output)
    {
        return ConvU32ToU16(str_input, str_output);
    }

    bool utf8_to_utf16(const std::string &str_input, std::u16string &str_output)
    {
        return ConvU8ToU16(str_input, str_output);
    }

    bool utf16_to_utf8(const std::u16string &str_input, std::string &str_output)
    {
        return ConvU16ToU8(str_input, str_output);
    }


    #ifdef WCHAR_IS_UTF16CHAR
    std::wstring u16string_to_wstring(const std::u16string &str_input)
    {
        std::wstring wstr_ret;
        wstr_ret.assign(str_input.begin(), str_input.end());
        return wstr_ret;
    }

    std::u16string wstring_to_u16string(const std::wstring &str_input)
    {
        std::u16string u16str_ret;
        u16str_ret.assign(str_input.begin(), str_input.end());
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

    bool wstring_to_utf8(const std::wstring &str_input,std::string &str_output)
    {
        std::u16string u16_str = wstring_to_u16string(str_input);
        if (utf16_to_utf8(u16_str, str_output) == true)
        {
            return true;
        }
        return false;
    }

    bool wstring_to_utf16(const std::wstring &str_input,std::u16string &str_output)
    {
        str_output = wstring_to_u16string(str_input);
        return true;
    }

    bool wstring_to_utf32(const std::wstring &str_input,std::u32string &str_output)
    {
        std::u16string u16_str = wstring_to_u16string(str_input);
        if (utf16_to_utf32(u16_str, str_output) == true)
        {
            return true;
        }
        return false;
    }
    #elif WCHAR_IS_UTF32CHAR
    std::wstring u32string_to_wstring(const std::u32string &str_input)
    {
        std::wstring wstr_ret;
        wstr_ret.assign(str_input.begin(), str_input.end());
        return wstr_ret;
    }

    std::u32string wstring_to_u32string(const std::wstring &str_input)
    {
        std::u32string u32str_ret;
        u32str_ret.assign(str_input.begin(), str_input.end());
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
    
    bool wstring_to_utf8(const std::wstring &str_input,std::string &str_output)
    {
        std::u32string u32_str = wstring_to_u32string(str_input);
        if (utf32_to_utf8(u32_str, str_output) == true)
        {
            return true;
        }
        return false;
    }

    bool wstring_to_utf16(const std::wstring &str_input,std::u16string &str_output)
    {
        std::u32string u32_str = wstring_to_u32string(str_input);
        if (utf32_to_utf16(u32_str, str_output) == true)
        {
            return true;
        }
        return false;
    }

    bool wstring_to_utf32(const std::wstring &str_input,std::u32string &str_output)
    {
        str_output = wstring_to_u32string(str_input);
        return true;
    }
    #endif // !WCHAR_IS_UTF16CHAR

}
