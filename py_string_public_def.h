#if defined(_MSC_VER)
#pragma once
#endif

//定义公共定义
#ifndef __PYTHON_STRING_PUBLIC_DEFINE_H__
#define __PYTHON_STRING_PUBLIC_DEFINE_H__
#include <stdint.h>
typedef signed long long long_max_t;
typedef unsigned long long long_max_u;
//9223372036854775807i64
#define MAX_SIGNED_LONG64 (9223372036854775807ll)
#define MAX_SIGNED_LONG64_NUM ((long_max_t)9223372036854775807ll)
#define MAX_UNSIGNED_LONG64_NUM ((long_max_u)-1)
//#define INT64_MIN        (-9223372036854775807i64 - 1)
#endif //__PYTHON_STRING_PUBLIC_DEFINE_H__
