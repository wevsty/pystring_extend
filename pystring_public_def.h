#if defined(_MSC_VER)
#pragma once
#endif

//定义公共定义
#ifndef __PYTHON_STRING_PUBLIC_DEFINE_H__
#define __PYTHON_STRING_PUBLIC_DEFINE_H__

#define COMPILER_SUPPORT_CPP_STANDARD 2017

#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>
#include <map>
#include <memory>
#if COMPILER_SUPPORT_CPP_STANDARD >= 2017
#include <string_view>
#endif

typedef signed long long long_max_t;
typedef unsigned long long long_max_u;

typedef signed long long int_max_t;
typedef unsigned long long uint_max_t;

#define MAX_INT_MAX_T (INTMAX_MAX)
#define MIN_INT_MAX_T (INTMAX_MIN)
#define MAX_UINT_MAX_T (UINTMAX_MAX)
#define MIN_UINT_MAX_T (0)

//#define U8TEXT(text) u8##text
#define U16TEXT(text) u##text
#define U32TEXT(text) U##text
#define WTEXT(text) L##text

#define EMPTYE_C_STRING ("")
#define EMPTYE_C_WSTRING (WTEXT(""))
//#define EMPTYE_C_U8STRING (u8"")
#define EMPTYE_C_U16STRING (U16TEXT(""))
#define EMPTYE_C_U32STRING (U32TEXT(""))

#define SPACE_C_CHAR (' ')
#define SPACE_C_WCHAR (WTEXT(' '))
//#define SPACE_C_U8CHAR (u8' ')
#define SPACE_C_U16CHAR (U16TEXT(' '))
#define SPACE_C_U32CHAR (U32TEXT(' '))



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
