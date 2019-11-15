/******************************************************************

* Copyright(c) 2019 wevsty
* All rights reserved.

* 文件名称: string_algorithm_template.h
* 简要描述: string算法模板

* 更新日期: 2019/04/03
* 作者: wevsty
* 说明: 存放各种std::string有关的算法模板
 ******************************************************************/
 
#if defined(_MSC_VER)
#pragma once
#endif

//定义公共定义
#ifndef __STRING_EXTEND_ALGORITHM_TEMPLATE_H__
#define __STRING_EXTEND_ALGORITHM_TEMPLATE_H__

#include "compiler_macros.h"
#include "pystring_define.h"
#include <string>
namespace string_extend
{
    //将所有replace_old替换为replace_new
    //max_replace_count为最大替换次数
    template <typename T_STRING>
    void replace_direct(
        T_STRING &replace_source,
        const T_STRING &replace_old,
        const T_STRING &replace_new,
        size_t max_replace_count = MAX_SIZE_T
    )
    {
        if (replace_old.empty())
        {
            return;
        }
        if (max_replace_count == 0)
        {
            return;
        }
        size_t index;
        while ((index = replace_source.find(replace_old)) != T_STRING::npos)
        {
            replace_source.replace(
                index,
                replace_old.size(),
                replace_new
            );
            max_replace_count--;
            if(max_replace_count == 0)
            {
                break;
            }
        }
        return;
    }
    
    template <typename T_STRING,typename T_CONTAINER>
    void split(const T_STRING &source,
               const T_STRING &delim,
               T_CONTAINER &output,
               size_t n_count = MAX_SIZE_T
              )
    {
        size_t n_index_start = 0;
        size_t n_index_end = source.find(delim, n_index_start);
        size_t n_offset = 0;
        while(n_index_end != T_STRING::npos)
        {
            if(n_count <= 0 )
            {
                n_index_end = T_STRING::npos;
                break;
            }
            n_count--;
            n_offset = n_index_end - n_index_start;
            output.push_back(source.substr(n_index_start, n_offset));
            n_index_start = n_index_end + delim.size();
            n_index_end = source.find(delim, n_index_start);
        }
        n_offset = n_index_end - n_index_start;
        if(n_offset > 0)
        {
            output.push_back(source.substr(n_index_start, n_offset));
        }
    }
    
    template <typename T_STRING>
    void tolower_direct(T_STRING &input)
    {
        const size_t n_strlen = input.size();
        for (size_t i = 0; i < n_strlen; i++)
        {
            auto &ch = input.at(i);
            ch = std::tolower(ch);
        }
    }

    template <typename T_STRING>
    void toupper_direct(T_STRING &input)
    {
        const size_t n_strlen = input.size();
        for (size_t i = 0; i < n_strlen; i++)
        {
            auto &ch = input.at(i);
            ch = std::toupper(ch);
        }
    }
    
    template <typename T_STRING>
	bool ends_with(
        const T_STRING &source,
		const T_STRING &suffix
	)
	{
        size_t source_len = source.size();
		size_t suffix_len = suffix.size();
        if(suffix_len > source_len)
        {
            return false;
        }
        size_t source_start_pos = source_len - suffix_len;
		if (source.compare(source_start_pos, source_len,suffix) != 0)
		{
			return false;
		}
		return true;
	}
    
    template <typename T_STRING>
	bool starts_with(
        const T_STRING &source,
		const T_STRING &suffix
	)
	{
        size_t source_len = source.size();
		size_t suffix_len = suffix.size();
        if(suffix_len > source_len)
        {
            return false;
        }
		if (source.compare(0, suffix_len,suffix) != 0)
		{
			return false;
		}
		return true;
	}
}
#endif //__STRING_EXTEND_ALGORITHM_TEMPLATE_H__