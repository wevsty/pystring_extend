#if defined(_MSC_VER)
#pragma once
#endif
#ifndef __PYTHON_STRING_CLASS_CPP_H__
#define __PYTHON_STRING_CLASS_CPP_H__
#include "pystring_public_def.h"
#include "pystring_interface_function.h"
//#include <stdarg.h> // to use va_args ( format )
//#include <algorithm> // transform
#include "base_pystring_class_template.h"

typedef BASE_STRING_CLASS_EX<char32_t> u32pystring_ext;
typedef BASE_STRING_CLASS_EX<char16_t> u16pystring_ext;
typedef BASE_STRING_CLASS_EX<char> pystring_ext;
#endif // !__PYTHON_STRING_CLASS_CPP_H__
