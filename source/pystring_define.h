#if defined(_MSC_VER)
    #pragma once
#endif

//定义公共定义
#ifndef __PYTHON_STRING_PUBLIC_DEFINE_H__
    #define __PYTHON_STRING_PUBLIC_DEFINE_H__

    #include <cstdint>
    #include <cstddef>
    #include <string>
    //WCHAR_MAX
    #include <cwchar>
    #include <vector>
    #include <map>
    #include <memory>
    #include <string_view>


    typedef signed long long long_max_t;
    typedef unsigned long long long_max_u;

    typedef signed long long int_max_t;
    typedef unsigned long long uint_max_t;

    #define MAX_INT_MAX_T (INTMAX_MAX)
    #define MIN_INT_MAX_T (INTMAX_MIN)
    #define MAX_UINT_MAX_T (UINTMAX_MAX)
    #define MIN_UINT_MAX_T (0)

    #define MIN_SIZE_T (0)
    #define MAX_SIZE_T ((size_t)(-1))

    //#define U8TEXT(text) u8##text
    #define U16TEXT(text) u##text
    #define U32TEXT(text) U##text
    #define WTEXT(text) L##text

    #define EMPTYE_C_STRING ("")
    #define EMPTYE_C_WSTRING (L"")
    //#define EMPTYE_C_U8STRING (u8"")
    #define EMPTYE_C_U16STRING (u"")
    #define EMPTYE_C_U32STRING (U"")

    #define SPACE_C_CHAR (' ')
    #define SPACE_C_WCHAR (L' ')
    //#define SPACE_C_U8CHAR (u8' ')
    #define SPACE_C_U16CHAR (u' ')
    #define SPACE_C_U32CHAR (U' ')

    #if WCHAR_MAX == 0xff
        #define WCHAR_IS_UTF16CHAR 1
    #elif WCHAR_MAX == 0xffff
        #define WCHAR_IS_UTF32CHAR 1
    #else
        #define WCHAR_IS_UTF8CHAR 1
    #endif
    /*
    #define MAX_INT_MAX_T ((int_max_t)9223372036854775807ll)
    #define MIN_INT_MAX_T (-9223372036854775807i64 - 1)
    //#define MAX_UINT_MAX_T (0xffffffffffffffffui64)
    #define MAX_UINT_MAX_T ((uint_max_t)-1)
    #define MIN_UINT_MAX_T (0)
    */

    /*
    //9223372036854775807i64
    #define MAX_SIGNED_LONG64 (9223372036854775807ll)
    #define MAX_SIGNED_LONG64_NUM ((long_max_t)9223372036854775807ll)
    #define MAX_UNSIGNED_LONG64_NUM ((long_max_u)-1)
    #define MIN_SIGNED_LONG64        (-9223372036854775807i64 - 1)
    //#define INT64_MIN        (-9223372036854775807i64 - 1)
    */


#endif //__PYTHON_STRING_PUBLIC_DEFINE_H__
