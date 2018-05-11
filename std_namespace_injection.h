#ifndef PYTHON_STRING_STD_NAMESPACE_INJECTION_H_INCLUDED
#define PYTHON_STRING_STD_NAMESPACE_INJECTION_H_INCLUDED

#include "pystring_class.h"
#include "pystring_function.h"
#include "pystring_function_template.h"
#include "pystring_utf32_function.h"
#include "pystring_utf32_function_template.h"
/*
#include "py_string_public_def.h"
#include "base_string_template.h"
#include "convert_utf.h"
#include "data_conv.h"
*/
// std::hash 的自定义特化能注入 namespace std
namespace std
{
    template<>
    struct hash<pystring_ext> //: public hash<std::string>
    {
        typedef pystring_ext argument_type;
        typedef std::size_t result_type;
        result_type operator()(argument_type const& s) const
        {
            result_type const h1 ( std::hash<std::string>{}(s.to_std_string()) );
            return h1;
        }
    };
}

#endif // PYTHON_STRING_STD_NAMESPACE_INJECTION_H_INCLUDED
