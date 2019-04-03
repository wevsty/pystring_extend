/******************************************************************

* Copyright(c) 2019 wevsty
* All rights reserved.

* 文件名称: pystring_algorithm_template.h
* 简要描述: pystring算法模板

* 更新日期: 2018/12/27
* 作者: wevsty
* 说明: 存放各种字符串有关的算法模板
 ******************************************************************/

#if defined(_MSC_VER)
    #pragma once
#endif

#ifndef __PYTHON_GEN_STRING_FUNCTION_TEMPLATE_H__
#define __PYTHON_GEN_STRING_FUNCTION_TEMPLATE_H__

#include "pystring_define.h"
#include <vector>
#include <map>
#include <string>
#include <algorithm> //transform
#include <cctype> //std::isspace等函数
#include <cassert> //assert断言
#include <stdexcept> //std except

namespace pystring_algorithm
{
    /******************************************************************
    * 函数名：safe_to_signed_cast
    * 描述：安全转换unsigned到signed
    * 返回值：int_max_t
    * 参数：
    * n_input 一个无符号数。
    ******************************************************************/
    template <typename T_UINT = size_t>
    int_max_t safe_to_signed_cast(T_UINT n_input)
    {
        int_max_t n_out = (int_max_t)n_input;
        #ifdef ENABLE_PYSTRING_RUNTIME_EXCEPT
        if (n_out < (int_max_t)0)
        {
            throw(std::runtime_error("Integer Overflow"));
        }
        #else
        assert(n_out >= 0);
        #endif
        return n_out;
    }

    /******************************************************************
    * 函数名：safe_to_unsigned_cast
    * 描述：安全转换unsigned到signed
    * 返回值：size_t
    * 参数：
    * n_input 一个无符号数。
    ******************************************************************/
    template <typename T_INT = int_max_t>
    size_t safe_to_unsigned_cast(T_INT n_input)
    {
        size_t n_out = (size_t)n_input;
        #ifdef ENABLE_PYSTRING_RUNTIME_EXCEPT
        if (n_out < (int_max_t)0)
        {
            throw(std::runtime_error("Integer Overflow"));
        }
        #else
        assert(n_out == (size_t)n_input);
        #endif
        return n_out;
    }

    /******************************************************************
    * 函数名：adjust_indices
    * 描述：调整开始和结束下标，主要用于负数时。
    start和end为正数时
    * 返回值：size_t
    * 参数：
    * n_input 一个无符号数。
    ******************************************************************/
    template <typename T_INT = int_max_t>
    void adjust_indices(T_INT &start, T_INT &end, T_INT &len)
    {
        if (start > len)
        {
            start = len;
        }
        else if (start < 0)
        {
            start += len;
            if (start < 0)
            {
                start = 0;
            }
        }
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

    }

    //STL容器内容翻转
    template <typename T_STL>
    T_STL reverse_stl(const T_STL &input_stl)
    {
        T_STL str_ret(input_stl);
        std::reverse(str_ret.begin(), str_ret.end());
        return str_ret;
    }

    template <typename T_STRING>
    inline T_STRING make_string_range(const T_STRING &t_input, int_max_t start, int_max_t pos)
    {
        return t_input.substr(start, pos);
    }

    inline std::string_view make_string_range(const std::string &t_input, int_max_t start, int_max_t pos)
    {
        std::string_view str_view(&t_input[start], pos);
        return str_view;
    }

    inline std::wstring_view make_string_range(const std::wstring &t_input, int_max_t start, int_max_t pos)
    {
        std::wstring_view str_view(&t_input[start], pos);
        return str_view;
    }

    inline std::u16string_view make_string_range(const std::u16string &t_input, int_max_t start, int_max_t pos)
    {
        std::u16string_view str_view(&t_input[start], pos);
        return str_view;
    }

    inline std::u32string_view make_string_range(const std::u32string &t_input, int_max_t start, int_max_t pos)
    {
        std::u32string_view str_view(&t_input[start], pos);
        return str_view;
    }
    /************************************************************************************************************************************/

    /******************************************************************
    * 函数名：slice
    * 描述：切片方法
    * 功能：从字符串中取出指定位置的内容。
    * 返回值：取出字符串的副本
    * 参数：
    * str_input 输入的字符串。
    * n_start 取出的开头位置。
    * n_end 取出的结束位置。
    ******************************************************************/
    template <typename T_STRING>
    T_STRING slice(const T_STRING &str_input,
                   int_max_t n_start = 0,
                   int_max_t n_end = MAX_INT_MAX_T
                  )
    {
        int_max_t n_strlen = safe_to_signed_cast(str_input.size());
        adjust_indices(n_start, n_end, n_strlen);
        if (n_start >= n_end)
        {
            return T_STRING();
        }
        return str_input.substr(safe_to_unsigned_cast(n_start),
                                safe_to_unsigned_cast(n_end - n_start));
    }

    /******************************************************************
    * 函数名: find
    * 描述: 字符串查找方法。
    * 功能: 检测字符串(str_input)中是否包含子字符串(str_find_substr)。
    * 如果指定 n_start（开始）和 n_end（结束）范围，则检查是否包含在指定范围内。
    * 如果包含子字符串返回开始的索引值，否则返回-1。
    * 返回值：子字符串的序号。
    * 参数：
    * str_input 输入的字符串。
    * str_find_substr 要查找的子字符串。
    * n_start 查找的开头位置。
    * n_end 查找的结束位置。
    ******************************************************************/
    template <typename T_STRING>
    int_max_t find(const T_STRING &str_input,
                   const T_STRING &str_find_substr,
                   int_max_t n_start = 0,
                   int_max_t n_end = MAX_INT_MAX_T
                  )
    {
        int_max_t n_len = safe_to_signed_cast(str_input.size());
        adjust_indices(n_start, n_end, n_len);
        //如果n_end小于n_start，那么表示不可能查找到结果。
        if (n_end < n_start)
        {
            return (int_max_t) -1;
        }
        size_t result = str_input.find(str_find_substr, safe_to_unsigned_cast(n_start));
        if (result == T_STRING::npos ||
            (result + str_find_substr.size() > (size_t)n_end))
        {
            return (int_max_t) -1;
        }
        return safe_to_signed_cast(result);
    }

    //index与find()同义
    //省略模板，直接通过重载实现
    /*
    template <typename T_STRING>
    int_max_t index(const T_STRING &str_input,
    const T_STRING &str_find_substr,
    int_max_t n_start = 0,
    int_max_t n_end = MAX_UINT_MAX_T
    )
    {
    return find(str_input, str_find_substr, n_start, n_end);
    }
    */

    /******************************************************************
    * 函数名: rfind
    * 描述: 类似于find，但是是从字符串右侧开始查找。
    * 功能: 从右侧开始检测字符串(str_input)中是否包含子字符串(str_find_substr)。
    * 如果指定 n_start（开始）和 n_end（结束）范围，则检查是否包含在指定范围内。
    * 如果包含子字符串返回开始的索引值，否则返回-1。
    * 返回值：子字符串的序号。
    * 参数：
    * str_input 输入的字符串。
    * str_find_substr 要查找的子字符串。
    * n_start 查找的开头位置。
    * n_end 查找的结束位置。
    ******************************************************************/
    template <typename T_STRING>
    int_max_t rfind(const T_STRING &str_input,
                    const T_STRING &str_find_substr,
                    int_max_t n_start = 0,
                    int_max_t n_end = MAX_INT_MAX_T
                   )
    {
        int_max_t n_input_len = safe_to_signed_cast(str_input.size());
        adjust_indices(n_start, n_end, n_input_len);

        //如果要查找的内容是空字符串，则返回结束位置（即为0）
        if (str_find_substr.empty() == true)
        {
            return n_end;
        }
        //如果n_end小于n_start，那么表示不可能查找到结果。
        if (n_end < n_start)
        {
            return (int_max_t) -1;
        }
        //如果开头位置和结尾位置相等，则说明输入为空字符串
        if (n_end == n_start)
        {
            return (int_max_t) -1;
        }

        //如果不支持C++17，make_string_range将等效于substr
        //T_STRING str_find_range = str_input.substr((size_t)n_start, (size_t)n_end - n_start);
        //如果支持C++17则可以少复制一次
        auto str_find_range = make_string_range(str_input, n_start, n_end - n_start);

        size_t result = str_find_range.rfind(str_find_substr);
        if (result == T_STRING::npos)
        {
            return (int_max_t) -1;
        }
        return safe_to_signed_cast(result + n_start);
    }

    //rindex与rfind()同义
    //省略模板，直接通过重载实现
    /*
    template <typename T_STRING>
    int_max_t rindex(const T_STRING &str_input,
    const T_STRING &str_find_substr,
    int_max_t n_start = 0,
    int_max_t n_end = MAX_UINT_MAX_T
    )
    {
    return rfind(str_input, str_find_substr, n_start, n_end);
    }
    */

    /******************************************************************
    * 函数名: replace
    * 描述: 字符串替换函数
    * 功能: 把string中的oldstr替换成newstr,如果指定了count，则替换不超过count次.
    * 返回值：替换完成后的字符串副本。
    * 参数：
    * str_input 输入的字符串。
    * oldstr 要查找的字符串。
    * newstr 将要用来替换的字符串。
    * n_count 替换次数。
    ******************************************************************/
    template <typename T_STRING>
    T_STRING replace(const T_STRING &str_input,
                     const T_STRING &oldstr,
                     const T_STRING &newstr,
                     int_max_t n_count = MAX_INT_MAX_T
                    )
    {
        int_max_t n_allow_replace_count = n_count;
        size_t cursor = 0;
        T_STRING str_ret(str_input);
        size_t oldlen = oldstr.size();
        size_t newlen = newstr.size();

        if (n_allow_replace_count <= 0)
        {
            return str_ret;
        }

        cursor = str_ret.find(oldstr, cursor);
        while (cursor != T_STRING::npos && cursor <= str_ret.size())
        {
            if (n_allow_replace_count <= 0)
            {
                break;
            }
            n_allow_replace_count--;
            str_ret.replace(cursor, oldlen, newstr);
            cursor += newlen;
            if (oldlen != 0)
            {
                cursor = str_ret.find(oldstr, cursor);
            }
            else
            {
                ++cursor;
            }
        }
        return str_ret;
    }

    /******************************************************************
    * 函数名: split_whitespace
    * 描述: 字符串分割空字符（空格、\t、等）
    * 功能: 把str_input按照空字符进行分割储存到返回的STL容器中，最大分割maxsplit次。
    * 返回值：无
    * 参数：
    * vec_output 用来存放结果的STL容器。
    * str_input 输入的字符串。
    * maxsplit 最大分割次数。
    ******************************************************************/
    template <typename T_VECTOR, typename T_STRING>
    void split_whitespace(T_VECTOR &vec_output,
                          const T_STRING &str_input,
                          int_max_t maxsplit = MAX_INT_MAX_T
                         )
    {
        size_t i = 0;
        size_t n_start_pos = 0;
        size_t n_str_len = str_input.size();
        while (i < n_str_len)
        {
            if (maxsplit <= 0)
            {
                break;
            }
            else
            {
                maxsplit--;
            }
            //寻找一个非空字符作为起点
            while (i < n_str_len && std::isspace(str_input[i]))
            {
                i++;
            }
            n_start_pos = i;
            //寻找下一个空字符
            while (i < n_str_len && !std::isspace(str_input[i]))
            {
                i++;
            }
            //如果找到了可分割的字符
            if (n_start_pos < i)
            {
                vec_output.push_back(str_input.substr(n_start_pos, i - n_start_pos));
                n_start_pos = i;
            }
        }
        if (n_start_pos < n_str_len)
        {
            vec_output.push_back(str_input.substr(n_start_pos, n_str_len - n_start_pos));
        }
        return;
    }

    /******************************************************************
    * 函数名: split
    * 描述: 字符串分割
    * 功能: 把str_input按照制定字符串进行分割储存到返回的STL容器中，最大分割maxsplit次。
    * 返回值：无
    * 参数：
    * vec_output 用来存放结果的STL容器。
    * str_input 输入的字符串。
    * sep 分割特征字符串。
    * maxsplit 最大分割次数。
    ******************************************************************/
    template <typename T_VECTOR, typename T_STRING>
    void split(
    T_VECTOR &vec_output,
    const T_STRING &str_input,
    const T_STRING &sep,
    int_max_t maxsplit = MAX_INT_MAX_T
    )
    {
        vec_output.clear();
        if (maxsplit < 0)
        {
            maxsplit = MAX_INT_MAX_T;    //vec_output.max_size();
        }
        if (maxsplit == 0)
        {
            vec_output.push_back(str_input);
            return;
        }
        if (sep.size() == 0)
        {
            split_whitespace(vec_output, str_input, maxsplit);
            return;
        }
        size_t i = 0;
        size_t n_start_pos = 0;
        size_t n_strlen = str_input.size();
        size_t n_sep_len = sep.size();
        while (i + n_sep_len <= n_strlen)
        {
            if (str_input.compare(i, n_sep_len, sep) == 0)
            {
                if (maxsplit-- <= 0)
                {
                    break;
                }
                vec_output.push_back(str_input.substr(n_start_pos, i - n_start_pos));
                i = n_start_pos = i + n_sep_len;
            }
            else
            {
                i++;
            }
        }
        vec_output.push_back(str_input.substr(n_start_pos, n_strlen - n_start_pos));
        return;
    }

    /******************************************************************
    * 函数名: rsplit_whitespace
    * 描述: 从右开始字符串分割空字符（空格、\t、等）
    * 功能: 从右开始把str_input按照空字符进行分割储存到返回的STL容器中，最大分割maxsplit次。
    * 返回值：无
    * 参数：
    * vec_output 用来存放结果的STL容器。
    * str_input 输入的字符串。
    * maxsplit 最大分割次数。
    ******************************************************************/
    template <typename T_VECTOR, typename T_STRING>
    void rsplit_whitespace(
    T_VECTOR &vec_output,
    const T_STRING &str_input,
    int_max_t maxsplit = MAX_INT_MAX_T
    )
    {
        vec_output.clear();
        size_t n_strlen = str_input.size();
        size_t i;
        size_t n_strart_pos;
        for (i = n_strart_pos = n_strlen; i > 0; )
        {
            while (i > 0 && std::isspace(str_input[i - 1]))
            {
                i--;
            }
            n_strart_pos = i;
            while (i > 0 && !std::isspace(str_input[i - 1]))
            {
                i--;
            }
            if (n_strart_pos > i)
            {
                if (maxsplit-- <= 0)
                {
                    break;
                }
                vec_output.push_back(str_input.substr(i, n_strart_pos - i));
                while (i > 0 && std::isspace(str_input[i - 1]))
                {
                    i--;
                }
                n_strart_pos = i;
            }
        }
        if (n_strart_pos > 0)
        {
            vec_output.push_back(str_input.substr(0, n_strart_pos));
        }
        std::reverse(vec_output.begin(), vec_output.end());
        //reverse_strings(vec_out_result);
        return;
    }

    /******************************************************************
    * 函数名: rsplit
    * 描述: 从右开始字符串分割
    * 功能: 从右开始把str_input按照制定字符串进行分割储存到返回的STL容器中，最大分割maxsplit次。
    * 返回值：无
    * 参数：
    * vec_output 用来存放结果的STL容器。
    * str_input 输入的字符串。
    * sep 分割特征字符串。
    * maxsplit 最大分割次数。
    ******************************************************************/
    template <typename T_VECTOR, typename T_STRING>
    void rsplit(
    T_VECTOR &vec_output,
    const T_STRING &str_input,
    const T_STRING &sep,
    int_max_t maxsplit = MAX_INT_MAX_T
    )
    {
        vec_output.clear();
        if (maxsplit < 0)
        {
            split(vec_output, str_input, sep, maxsplit);
            return;
        }
        if (sep.size() == 0)
        {
            return rsplit_whitespace(vec_output, str_input, maxsplit);
        }
        int_max_t i;
        int_max_t n_start_pos;
        int_max_t n_strlen = safe_to_signed_cast(str_input.size());
        int_max_t n_sep_len = safe_to_signed_cast(sep.size());
        i = n_start_pos = n_strlen;
        while (i >= n_sep_len)
        {
            if (str_input[i - 1] == sep[n_sep_len - 1]
                && str_input.substr(i - n_sep_len, n_sep_len) == sep)
            {
                if (maxsplit-- <= 0)
                {
                    break;
                }
                vec_output.push_back(str_input.substr(i, n_start_pos - i));
                i = n_start_pos = i - n_sep_len;
            }
            else
            {
                i--;
            }
        }
        vec_output.push_back(str_input.substr(0, n_start_pos));
        std::reverse(vec_output.begin(), vec_output.end());
        return;
        //reverse_strings(vec_out_result);
    }

    /******************************************************************
    * 函数名: join
    * 描述: 将序列中的元素以指定的字符连接生成一个新的字符串。
    * 功能: 将seq中的元素以str作为连接符连接成新字符串。
    * 返回值：无
    * 参数：
    * str 连接符字符串。
    * seq 要连接的存放元素的STL容器。
    * str_output 用来存放结果的STL容器。
    ******************************************************************/
    template <typename T_VECTOR, typename T_STRING>
    void join(const T_STRING &str,
              const T_VECTOR &seq,
              T_STRING &str_output
             )
    {
        if (seq.empty() == true)
        {
            str_output.clear();
            return;
        }
        str_output = seq[0];
        for (typename T_VECTOR::const_iterator it = seq.begin() + 1;
             it != seq.end();
             it++
            )
        {
            str_output += str + *it;
        }
        return;
    }

    /******************************************************************
    * 函数名: partition
    * 描述: 返回一个3元的元组，第一个为分隔符左边的子串，第二个为分隔符本身，第三个为分隔符右边的子串。
    * 举例: "https://baidu.com" -> ('https', '://', 'baidu.com')
    * 返回值：无
    * 参数：
    * vec_out_result 用来存放结果的STL容器。
    * str 被分割的字符串。
    * seq 分隔符。
    ******************************************************************/
    template <typename T_VECTOR, typename T_STRING>
    void partition(
    T_VECTOR &vec_out_result,
    const T_STRING &str,
    const T_STRING &sep
    )
    {
        vec_out_result.resize(3);
        int_max_t index = find(str, sep);
        if (index < 0)
        {
            vec_out_result[0] = str;
            vec_out_result[1] = T_STRING();
            vec_out_result[2] = T_STRING();
        }
        else
        {
            vec_out_result[0] = str.substr(0, index);
            vec_out_result[1] = sep;
            vec_out_result[2] = str.substr(index + sep.size(), str.size());
        }
        return;
    }

    /******************************************************************
    * 函数名: rpartition
    * 描述: 类似于partition()函数,不过是从右边开始查找。
    * 返回一个3元的元组，第一个为分隔符左边的子串，第二个为分隔符本身，第三个为分隔符右边的子串。
    * 举例: "https://baidu.com" -> ('https', '://', 'baidu.com')
    * 返回值：无
    * 参数：
    * vec_out_result 用来存放结果的STL容器。
    * str 被分割的字符串。
    * seq 分隔符。
    ******************************************************************/
    template <typename T_VECTOR, typename T_STRING>
    void rpartition(
    T_VECTOR &vec_out_result,
    const T_STRING &str,
    const T_STRING &sep
    )
    {
        vec_out_result.resize(3);
        int_max_t index = rfind(str, sep);
        if (index < 0)
        {
            vec_out_result[0] = T_STRING();
            vec_out_result[1] = T_STRING();
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

    /******************************************************************
    * 函数名: rpartition
    * 描述: 字符串按行进行分割。
    * 返回值：无
    * 参数：
    * vec_out_split_str 用来存放结果的STL容器。
    * str_data 被分割的字符串。
    * b_keepends 是否保留末尾的换行符。
    ******************************************************************/
    template <typename T_VECTOR, typename T_STRING>
    void splitlines(
    T_VECTOR &vec_out_split_str,
    const T_STRING &str_data,
    bool b_keepends
    )
    {
        vec_out_split_str.clear();
        size_t n_str_len = str_data.size();
        T_STRING str_buff;
        for (size_t i = 0; i < n_str_len; i++)
        {
            if (str_data[i] == '\r')
            {
                if (str_data[i + 1] == '\n')
                {
                    i++;
                    if (b_keepends == true)
                    {
                        //str_buff.append("\r\n");
                        str_buff.push_back('\r');
                        str_buff.push_back('\n');
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

    /******************************************************************
    * 函数名: lstrip
    * 描述: 截掉字符串左边的空格(包括\t\r\n)或指定字符。
    * 返回值：截取完毕的字符串副本
    * 参数：
    * str_input 等待截取的字符串。
    * chars 截取标志，如为空表示截取空白(包括空格\t\r\n)字符。
    ******************************************************************/
    template <typename T_STRING>
    T_STRING lstrip(const T_STRING &str_input, const T_STRING &chars = T_STRING())
    {
        bool b_strip_space = true;
        if (chars.empty() != true)
        {
            b_strip_space = false;
        }
        const size_t n_strlen = str_input.size();
        size_t n_start_pos = 0;
        for (size_t i = 0; i < n_strlen; i++)
        {
            if (b_strip_space == true)
            {
                if (std::isspace(str_input[i]) == 0)
                {
                    //不为空格时
                    n_start_pos = i;
                    break;
                }
            }
            else
            {
                if (chars.find(str_input[i]) == T_STRING::npos)
                {
                    //当字符串当前字符第一次不在过滤列表时
                    n_start_pos = i;
                    break;
                }
            }
        }
        return str_input.substr(n_start_pos);
    }

    /******************************************************************
    * 函数名: rstrip
    * 描述: 截掉字符串右边的空格(包括\t\r\n)或指定字符。
    * 返回值：截取完毕的字符串副本
    * 参数：
    * str_input 等待截取的字符串。
    * chars 截取标志，如为空表示截取空白(包括空格\t\r\n)字符。
    ******************************************************************/
    template <typename T_STRING>
    T_STRING rstrip(const T_STRING &str_input, const T_STRING &chars = T_STRING())
    {
        bool b_strip_space = true;
        if (chars.empty() != true)
        {
            b_strip_space = false;
        }
        size_t n_end_pos = 0;
        size_t n_strlen = str_input.size();
        for (size_t i = n_strlen - 1; i < n_strlen; i--)
        {
            if (b_strip_space == true)
            {
                if (std::isspace(str_input[i]) == 0)
                {
                    //不为空格时
                    n_end_pos = i + 1;
                    break;
                }
            }
            else
            {
                if (chars.find(str_input[i]) == T_STRING::npos)
                {
                    //当字符串当前字符第一次不在过滤列表时
                    n_end_pos = i + 1;
                    break;
                }
            }
        }
        return str_input.substr(0, n_end_pos);
    }

    /******************************************************************
    * 函数名: strip
    * 描述: 截掉字符串两边的空格(包括\t\r\n)或指定字符。
    * 返回值：截取完毕的字符串副本
    * 参数：
    * str_input 等待截取的字符串。
    * chars 截取标志，如为空表示截取空白(包括空格\t\r\n)字符。
    ******************************************************************/
    template <typename T_STRING>
    T_STRING strip(const T_STRING &str_input, const T_STRING &chars)
    {
        bool b_strip_space = true;
        if (chars.empty() != true)
        {
            b_strip_space = false;
        }
        const size_t n_strlen = str_input.size();
        size_t n_start_pos = 0;
        for (size_t i = 0; i < n_strlen; i++)
        {
            if (b_strip_space == true)
            {
                if (std::isspace(str_input[i]) == 0)
                {
                    //不为空格时
                    n_start_pos = i;
                    break;
                }
            }
            else
            {
                if (chars.find(str_input[i]) == T_STRING::npos)
                {
                    //当字符串当前字符第一次不在过滤列表时
                    n_start_pos = i;
                    break;
                }
            }
        }
        size_t n_end_pos = 0;
        for (size_t i = n_strlen - 1;
             i < n_strlen; i--)
        {
            if (b_strip_space == true)
            {
                if (std::isspace(str_input[i]) == 0)
                {
                    //不为空格时
                    n_end_pos = i + 1;
                    break;
                }
            }
            else
            {
                if (chars.find(str_input[i]) == T_STRING::npos)
                {
                    //当字符串当前字符第一次不在过滤列表时
                    n_end_pos = i + 1;
                    break;
                }
            }
        }
        size_t n_copy_len = n_end_pos - n_start_pos;
        return str_input.substr(n_start_pos, n_copy_len);
    }

    /******************************************************************
    * 函数名: swapcase
    * 描述: 翻转字符串大小写
    * 返回值：翻转完毕的字符串副本
    * 参数：
    * str_input 等待翻转的字符串。
    ******************************************************************/
    template <typename T_STRING>
    T_STRING swapcase(const T_STRING &str_input)
    {
        T_STRING str_ret(str_input);
        for (typename T_STRING::iterator it = str_ret.begin();
             it != str_ret.end();
             it++
            )
        {
            //std::isupper或者std::islower参数和返回值均为int,使用int保存信息是为了避免截断char32_t等类型中的非字母信息。
            //由于UTF8-32的字母部分是兼容的，所以可以强制的把int转回char并不会导致数据丢失。
            int ch_tmp = *it;
            //发现大写字母则改小写
            if (std::isupper(ch_tmp) != 0)
            {
                *it = static_cast<char>(std::tolower(ch_tmp));
                continue;
            }
            else if (std::islower(ch_tmp) != 0)
            {
                //发现小写字母则改大写
                *it = static_cast<char>(std::toupper(ch_tmp));
                continue;
            }
        }
        return str_ret;
    }


    /******************************************************************
    * 函数名: capitalize
    * 描述: 字符串转换为首字母大写其他小写的字符串
    * 举例："this IS string" -> "This is string"
    * 返回值：返回一个首字母大写其他小写的字符串
    * 参数：
    * oldstr 等待翻转的字符串。
    ******************************************************************/
    template <typename T_STRING>
    T_STRING capitalize(const T_STRING &oldstr)
    {
        T_STRING str_ret(oldstr);
        size_t len = str_ret.size();
        if (len > 0)
        {
            if (std::islower(str_ret[0]) != 0)
            {
                str_ret[0] = (char)std::toupper(str_ret[0]);
            }
        }
        for (size_t i = 1; i < len; ++i)
        {
            if (std::isupper(str_ret[i]))
            {
                str_ret[i] = (char)std::tolower(str_ret[i]);
            }
            //str_ret.push_back((char)std::tolower(oldstr[i]));
        }
        return str_ret;
    }

    /******************************************************************
    * 函数名: center
    * 描述: 返回一个原字符串居中的新字符串,并使用fillchar(默认空格)填充至长度 width 的新字符串
    * 举例：This is Test." -> "FFFThis is Test.FFFF"
    * 返回值：居中新的字符串
    * 参数：
    * str_input 等待居中的字符串。
    * width 新字符串的宽度。
    * fillchar 填充的字符。
    ******************************************************************/
    template <typename T_STRING, typename T_CHAR>
    T_STRING center(const T_STRING &str_input,
                    size_t width,
                    const T_CHAR fillchar
                   )
    {
        size_t len = str_input.size();
        size_t marg, left;
        if (len >= width)
        {
            return str_input;
        }
        marg = width - len;
        left = marg / 2 + (marg & width & 1);
        return T_STRING(left, fillchar) + str_input + T_STRING(marg - left, fillchar);
    }

    /******************************************************************
    * 函数名: count
    * 描述: 返回字符串中指定字符或者字符串的次数。
    * 举例："this is string" -> "is" -> return 2
    * 返回值：出现指定字符串的次数
    * 参数：
    * str_input 被查找的字符串。
    * substr 将要查找的字符串。
    * start 查找开始位置。
    * end 查找结束位置。
    ******************************************************************/
    template <typename T_STRING>
    int_max_t count(const T_STRING &str_input,
                    const T_STRING &substr,
                    int_max_t start,
                    int_max_t end
                   )
    {
        int_max_t n_count = 0;
        int_max_t cursor = start;
        while (1)
        {
            cursor = find(str_input, substr, cursor, end);
            if (cursor < 0)
            {
                break;
            }
            cursor += safe_to_signed_cast(substr.size());
            n_count++;
        }
        return n_count;
    }

    /******************************************************************
    * 函数名: endswith
    * 描述: 判断字符串结尾是否等于指定字符串。
    * 举例："test.exe" is "exe" -> return true
    * 返回值：是否符合条件
    * 参数：
    * str_input 被查找的字符串。
    * suffix 将要查找的字符串。
    * start 查找开始位置。
    * end 查找结束位置。
    ******************************************************************/
    template <typename T_STRING>
    bool endswith(const T_STRING &str_input,
                  const T_STRING &suffix,
                  int_max_t start,
                  int_max_t end
                 )
    {
        int_max_t str_len = safe_to_signed_cast(str_input.size());
        int_max_t suffix_len = safe_to_signed_cast(suffix.size());
        adjust_indices(start, end, str_len);
        if (end - start < suffix_len || start > str_len)
        {
            return false;
        }
        if (end - suffix_len > start)
        {
            start = end - suffix_len;
        }
        if (str_input.compare(safe_to_unsigned_cast(start), safe_to_unsigned_cast(suffix_len),
                              suffix) != 0)
        {
            return false;
        }
        return true;
    }

    /******************************************************************
    * 函数名: startswith
    * 描述: 判断字符串开头是否等于指定字符串。
    * 举例："test.exe" is "test" -> return true
    * 返回值：是否符合条件
    * 参数：
    * str_input 被查找的字符串。
    * prefix 将要查找的字符串。
    * start 查找开始位置。
    * end 查找结束位置。
    ******************************************************************/
    template <typename T_STRING>
    bool startswith(const T_STRING &str_input,
                    const T_STRING &prefix,
                    int_max_t start,
                    int_max_t end
                   )
    {
        int_max_t str_len = safe_to_signed_cast(str_input.size());
        int_max_t prefix_len = safe_to_signed_cast(prefix.size());
        adjust_indices(start, end, str_len);
        if (start + prefix_len > str_len)
        {
            return false;
        }
        if (end - start >= prefix_len)
        {
            if (str_input.compare(safe_to_unsigned_cast(start), safe_to_unsigned_cast(prefix_len),
                                  prefix) != 0)
            {
                return false;
            }
        }
        return true;
    }

    /******************************************************************
    * 函数名: expandtabs
    * 描述: 扩展\t为空格（默认为8个）并保持行末尾对齐
    * 返回值：修改完毕的字符串副本
    * 参数：
    * str_input 被查找的字符串。
    * tabsize \t的扩展数。
    ******************************************************************/
    template <typename T_STRING>
    T_STRING expandtabs(const T_STRING &str_input, int tabsize)
    {
        T_STRING str_ret(str_input);
        size_t len = str_input.size(), i = 0;
        size_t offset = 0;
        size_t jump_char_num = 0;
        size_t u_tabsize;
        if (tabsize < 0)
        {
            u_tabsize = 0;
        }
        else
        {
            u_tabsize = (size_t)tabsize;
        }
        for (i = 0; i < len; ++i)
        {
            if (str_input[i] == '\t')
            {
                if (u_tabsize > 0)
                {
                    size_t fillsize = tabsize - (jump_char_num % u_tabsize);
                    jump_char_num += fillsize;
                    str_ret.replace(i + offset, 1, T_STRING(fillsize, ' '));
                    offset += fillsize - 1;
                }
                else
                {
                    str_ret.replace(i + offset, 1, T_STRING());
                    offset -= 1;
                }
            }
            else
            {
                jump_char_num++;
                if (str_input[i] == '\n' || str_input[i] == '\r')
                {
                    jump_char_num = 0;
                }
            }
        }
        return str_ret;
    }

    /******************************************************************
    * 函数名: isalnum
    * 描述: 如果string至少有一个字符并且所有字符都是字母或数字则返回 true, 否则返回 false
    * 举例：
    *  "a1"   -> true
    *  "a1\n" -> false
    * 返回值：true 或者 false
    * 参数：
    * str_input 要检测的字符串。
    ******************************************************************/
    template <typename T_STRING>
    bool isalnum(const T_STRING &str_input)
    {
        if (str_input.empty())
        {
            return false;
        }
        for (typename T_STRING::const_iterator it = str_input.begin();
             it != str_input.end(); it++)
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

    /******************************************************************
    * 函数名: isalpha
    * 描述: 如果string至少有一个字符并且所有字符都是字母则返回 true, 否则返回 false
    * 举例：
    *  "a1\n" -> false
    *  "abc" -> true
    * 返回值：true 或者 false
    * 参数：
    * str_input 要检测的字符串。
    ******************************************************************/
    template <typename T_STRING>
    bool isalpha(const T_STRING &str_input)
    {
        if (str_input.empty())
        {
            return false;
        }
        for (typename T_STRING::const_iterator it = str_input.begin();
             it != str_input.end(); it++)
        {
            //是否为字母
            if (std::isalpha(*it) == 0)
            {
                return false;
            }
        }
        return true;
    }

    /******************************************************************
    * 函数名: isdigit
    * 描述: 如果string至少有一个字符并且所有字符都是数字则返回 true, 否则返回 false
    * 举例：
    *  "-10" -> false
    *  "10" -> true
    * 返回值：true 或者 false
    * 参数：
    * str_input 要检测的字符串。
    ******************************************************************/
    template <typename T_STRING>
    bool isdigit(const T_STRING &str_input)
    {
        if (str_input.empty())
        {
            return false;
        }
        for (typename T_STRING::const_iterator it = str_input.begin();
             it != str_input.end(); it++)
        {
            //是否为数字
            if (std::isdigit(*it) == 0)
            {
                return false;
            }
        }
        return true;
    }

    /******************************************************************
    * 函数名: isspace
    * 描述: 如果string至少有一个字符并且所有字符都是空格（包括\r\n\t\f\v）则返回 true, 否则返回 false
    * 举例：
    *  " \r\n" -> true
    *  " a   " -> false
    * 返回值：true 或者 false
    * 参数：
    * str_input 要检测的字符串。
    ******************************************************************/
    template <typename T_STRING>
    bool isspace(const T_STRING &str_input)
    {
        if (str_input.empty())
        {
            return false;
        }
        for (typename T_STRING::const_iterator it = str_input.begin();
             it != str_input.end(); it++)
        {
            //是否为空格
            if (std::isspace(*it) == 0)
            {
                return false;
            }
        }
        return true;
    }

    /******************************************************************
    * 函数名: istitle
    * 描述: 检测字符串中所有的单词拼写首字母是否为大写，且其他字母为小写
    * 举例：
    *  "this is" -> false
    *  "This Is" -> true
    * 返回值：true 或者 false
    * 参数：
    * str_input 要检测的字符串。
    ******************************************************************/
    template <typename T_STRING>
    bool istitle(const T_STRING &str_input)
    {
        if (str_input.empty())
        {
            return false;
        }
        bool b_need_upper = true;
        bool b_have_isalpha = false;
        int ch_tmp;
        for (typename T_STRING::const_iterator it = str_input.begin();
             it != str_input.end(); it++)
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
        if (b_have_isalpha == true)
        {
            return true;
        }
        return false;
    }

    /******************************************************************
    * 函数名: islower
    * 描述: 如果string中包含至少一个字母，并且所有字符都是小写，则返回 true，否则返回 false
    * 举例：
    *  "abc123.0" -> true
    *  "A1" -> false
    * 返回值：true 或者 false
    * 参数：
    * str_input 要检测的字符串。
    ******************************************************************/
    template <typename T_STRING>
    bool islower(const T_STRING &str_input)
    {
        bool b_have_lower = false;
        int ch_tmp = 0;
        for (typename T_STRING::const_iterator it = str_input.begin();
             it != str_input.end(); it++)
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

    /******************************************************************
    * 函数名: islower
    * 描述: 如果string中包含至少一个字母，并且所有字符都是大写，则返回 true，否则返回 false
    * 举例：
    *  "ABC123.0" -> true
    *  "a1" -> false
    * 返回值：true 或者 false
    * 参数：
    * str_input 要检测的字符串。
    ******************************************************************/
    template <typename T_STRING>
    bool isupper(const T_STRING &str_input)
    {
        bool b_have_upper = false;
        int ch_tmp = 0;
        for (typename T_STRING::const_iterator it = str_input.begin();
             it != str_input.end(); it++)
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

    /******************************************************************
    * 函数名: lower
    * 描述: 转换所有字符为小写。
    * 返回值：转换完成的字符串副本。
    * 参数：
    * str_input 要转换的字符串。
    ******************************************************************/
    template <typename T_STRING>
    T_STRING lower(const T_STRING &str_input)
    {
        T_STRING str_ret(str_input);
        std::transform(str_ret.begin(), str_ret.end(), str_ret.begin(), pystring_algorithm::ch_tolower);
        return str_ret;
    }

    /******************************************************************
    * 函数名: upper
    * 描述: 转换所有字符为大写。
    * 返回值：转换完成的字符串副本。
    * 参数：
    * str_input 要转换的字符串。
    ******************************************************************/
    template <typename T_STRING>
    T_STRING upper(const T_STRING &str_input)
    {
        T_STRING str_ret(str_input);
        std::transform(str_ret.begin(), str_ret.end(), str_ret.begin(), pystring_algorithm::ch_toupper);
        return str_ret;
    }

    /******************************************************************
    * 函数名: ljust
    * 描述: 返回一个原字符串左对齐,并使用空格填充至长度 width 的新字符串。
    * 返回值：转换完成的字符串副本。
    * 参数：
    * str_input 要转换的字符串。
    * width 填充到宽度
    * fillchar 填充字符
    ******************************************************************/
    template <typename T_STRING, typename T_CHAR>
    T_STRING ljust(const T_STRING &str_input, int_max_t width, T_CHAR fillchar)
    {
        size_t len = str_input.size();
        if (safe_to_signed_cast(len) >= width)
        {
            return str_input;
        }
        return str_input + T_STRING(width - len, fillchar);
    }

    /******************************************************************
    * 函数名: rjust
    * 描述: 返回一个原字符串右对齐,并使用空格填充至长度 width 的新字符串。
    * 返回值：转换完成的字符串副本。
    * 参数：
    * str_input 要转换的字符串。
    * width 填充到宽度
    * fillchar 填充字符
    ******************************************************************/
    template <typename T_STRING, typename T_CHAR>
    T_STRING rjust(const T_STRING &str_input, int_max_t width, T_CHAR fillchar)
    {
        size_t len = str_input.size();
        if (safe_to_signed_cast(len) >= width)
        {
            return str_input;
        }
        return T_STRING(width - len, fillchar) + str_input;
    }

    /******************************************************************
    * 函数名: title
    * 描述: 返回"标题化"的 string,就是说所有单词都是以大写开始，其余字母均为小写。
    * 举例："This is.no 123" -> "This Is.No 123"
    * 返回值：转换完成的字符串副本。
    * 参数：
    * str_input 要转换的字符串。
    ******************************************************************/
    template <typename T_STRING>
    T_STRING title(const T_STRING &str_input)
    {
        T_STRING str_ret(str_input);
        if (str_ret.empty())
        {
            return str_ret;
        }
        bool b_need_upper = true;
        int ch_tmp;
        for (typename T_STRING::iterator it = str_ret.begin(); it != str_ret.end(); it++)
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

    /******************************************************************
    * 函数名: zfill
    * 描述: 从左边开始使用字符0填充至指定长度，返回新字符串使原字符串右对齐。
    * 举例：zfill("test",10); -> "000000test"
    * 返回值：转换完成的字符串副本。
    * 参数：
    * str_input 要转换的字符串。
    * width 填充长度。
    ******************************************************************/
    template <typename T_STRING>
    T_STRING zfill(const T_STRING &str_input, size_t width)
    {
        size_t len = str_input.size();
        if (len >= width)
        {
            return str_input;
        }
        T_STRING str_ret(str_input);
        size_t fill = width - len;
        str_ret = T_STRING(fill, '0') + str_ret;
        if (str_ret[fill] == '+' || str_ret[fill] == '-')
        {
            str_ret[0] = str_ret[fill];
            str_ret[fill] = '0';
        }
        return str_ret;
    }

    /******************************************************************
    * 函数名: zfill
    * 描述: 用于字符映射的转换。
    * 举例：std::string translate("abbc","bc","de") -> "adde"
    * 返回值：转换完成的字符串副本。
    * 参数：
    * old_str 被转换的字符串。
    * intab 需要转换的字符表。
    * outtab 转换的目标字符表。
    * 注意两个字符串的长度必须相同，为一一对应的关系
    ******************************************************************/
    template <typename T_STRING>
    T_STRING translate(const T_STRING &old_str, const T_STRING &intab,
                       const T_STRING &outtab)
    {
        size_t n_intab_length = intab.length();
        if (n_intab_length != outtab.length() || n_intab_length == 0)
        {
            return old_str;
        }
        std::map<int, int> map_tables;
        for (size_t n = 0; n < n_intab_length; n++)
        {
            map_tables[intab[n]] = outtab[n];
        }
        T_STRING ret_str;
        for (typename T_STRING::const_iterator it = old_str.begin(); it != old_str.end(); it++)
        {
            std::map<int, int>::const_iterator map_it = map_tables.find(*it);
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

    /******************************************************************
    * 函数名: get_middle_of_pos
    * 描述: 取两个字符串之间的字符串所在的起始位置和长度.
    * 返回值：是否找到结果。
    * 参数：
    * str_data 要分析的字符串。
    * str_start 开始标志。
    * str_end 结束标志。
    * n_start 返回寻找结果对于输入的起始位置。
    * n_copylen 返回寻找结果结束对于开始位置向后偏移的数量。
    ******************************************************************/
    template <typename T_STRING>
    bool get_middle_of_pos(const T_STRING &str_data,
                           const T_STRING &str_start,
                           const T_STRING &str_end,
                           size_t &n_start,
                           size_t &n_copylen)
    {
        n_start = 0;
        n_copylen = T_STRING::npos;
        if (str_start.empty() == true)
        {
            return false;
        }
        n_start = str_data.find(str_start);
        if (T_STRING::npos == n_start)
        {
            return false;
        }
        n_start += str_start.length();
        if (str_end.empty() == true)
        {
            return true;
        }
        size_t n_end = str_data.find(str_end, n_start);
        if (T_STRING::npos == n_end)
        {
            n_end = str_data.size();
        }
        n_copylen = n_end - n_start;
        return true;
    }

    /******************************************************************
    * 函数名: get_middle_of
    * 描述: 取字符串中两个字符串之间的字符串
    * 返回值：寻找到的字符串副本，如未查找到结果返回空字符串。
    * 参数：
    * str_data 要分析的字符串。
    * str_start 开始标志。
    * str_end 结束标志。
    ******************************************************************/
    template <typename T_STRING>
    T_STRING get_middle_of(const T_STRING &str_data,
                           const T_STRING &str_start,
                           const T_STRING &str_end)
    {
        size_t n_start = 0;
        size_t n_copylen = T_STRING::npos;
        if (get_middle_of_pos(str_data, str_start, str_end, n_start, n_copylen) == true)
        {
            return str_data.substr(n_start, n_copylen);
        }
        return T_STRING();
    }

    /******************************************************************
    * 函数名: delete_middle_of
    * 描述: 删除字符串中两个字符串中间的字符串
    * 返回值：删除内容后的字符串副本。
    * 参数：
    * str_input_text 要分析的字符串。
    * str_start_flag 开始标志。
    * str_end_flag 结束标志。
    * n_count 最大删除次数。
    ******************************************************************/
    template <typename T_STRING>
    T_STRING delete_middle_of(const T_STRING &str_input_text,
                              const T_STRING &str_start_flag,
                              const T_STRING &str_end_flag,
                              int_max_t n_count
                             )
    {
        T_STRING str_ret;
        size_t n_allow_delete_count = n_count;
        if (n_allow_delete_count <= 0)
        {
            return str_input_text;
        }
        size_t n_strart_pos = 0;
        size_t n_end_pos = str_input_text.find(str_start_flag);
        while (n_end_pos != T_STRING::npos)
        {
            if (n_allow_delete_count <= 0)
            {
                break;
            }
            n_allow_delete_count--;
            str_ret.append(str_input_text.substr(n_strart_pos, n_end_pos - n_strart_pos));
            if (str_end_flag.empty() == true)
            {
                n_strart_pos = T_STRING::npos;
                break;
            }
            n_strart_pos = str_input_text.find(str_end_flag, n_end_pos);
            if (n_strart_pos != T_STRING::npos)
            {
                n_strart_pos += str_end_flag.size();
            }
            else
            {
                break;
            }
            n_end_pos = str_input_text.find(str_start_flag, n_strart_pos);
        }
        if (n_strart_pos != T_STRING::npos)
        {
            str_ret.append(str_input_text.substr(n_strart_pos));
        }
        return str_ret;
    }

    /******************************************************************
    * 函数名: truncate
    * 描述: 截断字符串
    * 返回值：截断内容后的字符串副本。
    * 参数：
    * str_input 要分析的字符串。
    * str_truncate 要截断的字符串。
    ******************************************************************/
    template <typename T_STRING>
    T_STRING truncate(const T_STRING &str_input,
                      const T_STRING &str_truncate)
    {
        T_STRING str_ret;
        size_t n_find = str_input.find(str_truncate);
        if (n_find == T_STRING::npos)
        {
            str_ret = str_input;
        }
        else
        {
            str_ret = str_input.substr(0, n_find);
        }
        return str_ret;
    }

    /******************************************************************
    * 函数名: truncate
    * 描述: 截断字符串中标志的任意字符
    * 返回值：截断内容后的字符串副本。
    * 参数：
    * str_input 要分析的字符串。
    * str_truncate 要截断的字符串。
    ******************************************************************/
    template <typename T_STRING>
    T_STRING truncate_char(const T_STRING &str_input,
                           const T_STRING &str_truncate)
    {
        T_STRING str_ret;
        size_t n_find = str_input.find_first_of(str_truncate);
        if (n_find == T_STRING::npos)
        {
            str_ret = str_input;
        }
        else
        {
            str_ret = str_input.substr(0, n_find);
        }
        return str_ret;
    }
}
#endif //__PYTHON_GEN_STRING_FUNCTION_TEMPLATE_H__
