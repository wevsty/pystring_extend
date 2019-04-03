# pystring_extend

A C++ class compatible std::string and Python string style.  
一个兼容std::string和Python String风格的C++字符串库。
 
# Levels of thread safety

Conditionally safe

# Compiler compatibility

| Compiler                    | Build Test    |
| --------------------------- |:-------------:|
| Microsoft Visual C++ 2017   | pass          |
| MinGW.org GCC-8.2.0-3       | pass          |
| Others                      | unknow        |

Note : Compilation needs to support C++17 standards.

注：编译需要支持C++17标准。

# Build

You can choose to use CMake or Codelite to compile directly.  
你可以选择使用CMake或者Codelite直接编译。

# example

More examples of use can be found in test_case.cpp  
更多的使用例子可以查看test_case.cpp。

```cpp
template <typename T1, typename T2>
void check_equal(T1 chk1, T2 chk2)
{
    if (chk1 != chk2)
    {
        throw std::runtime_error("Exceptional results");
    }
}

void test_pystring_class()
{
    //test std::string
    std::string std_test_string = "std::String";
    pystring_ext py_test_string(pystring_ext::make_string_reference(std_test_string));
    check_equal(py_test_string.py_lower(), "std::string");
    check_equal(py_test_string.py_upper(), "STD::STRING");
    py_test_string.tolower_direct();
    check_equal(std_test_string, "std::string");
    py_test_string.toupper_direct();
    check_equal(std_test_string, "STD::STRING");
    //test std::u16string
    u16pystring_ext utf_test_string = u" Utf16 ";
    check_equal(utf_test_string.py_lower(), u" utf16 ");
    check_equal(utf_test_string.py_upper(), u" UTF16 ");
    check_equal(utf_test_string.py_strip(), u"Utf16");
    //test std::u16string convert
    std::string std_test_convert = utf_test_string.to_std_string();
    check_equal(std_test_convert," Utf16 ");
}
```

# QuickStart
You can use pystring_ext directly like std::string.  
你可以直接向std::string一样使用pystring_ext.

pystring_ext can be cast to std::string.  
pystring_ext可以被强制转换为std::string。

Note: pystring_ext does not support various stream operations.  
注意：pystring_ext不支持各种流操作。

If you need to use Python-style functions, add py_.  
如果你需要使用Python风格的函数，请在Python对应的函数名前加上py_.  

If you need to convert to other types, you can see the function of the to_ or from_ prefix.  
如果你需要转换为其他类型可以查看to_或者from_前缀的函数。

```cpp
void test()
{
    pystring_ext py_test;
    //py_lower() Returns a string of all lowercase.
    std::cout << (std::string)py_test.py_lower() <<std::endl;
}
```
# LICENSE

MIT License

# Thanks

UnicodeConv.cpp and UnicodeConv.h from benikabocha.

Original project address : https://github.com/benikabocha/unicode_conv