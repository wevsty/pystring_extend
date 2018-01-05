# pystring_extend
 A C++ class compatible std::string and Python string style.
 一个兼容std::string和Python String风格的C++字符串库。
 
# Compiler compatibility
| Compiler                    | Build Test    |
| --------------------------- |:-------------:|
| Microsoft Visual C++ 2017   | pass          |
| gcc version 5.4.0 20160609  | pass          |
| Others                      | unknow        |

Note : Compilation needs to support C++11 standards.
注：编译需要支持C++11标准。

# 使用方法
 项目中提供了2类字符串处理函数（或者类），一类为不区分编码的字符串函数，另一类为强制使用utf32编码的字符串函数，在项目中可以自由的使用。使用方法如下：
 1. 直接调用函数。
 如果我们不需要考虑编码的问题，希望用字节的方式来处理数据，可以直接使用pystring_function命名空间下的处理函数。函数命名与Python中相同，第一个参数永远为被处理的字符串，后续参数与Python相同。函数名和参数请参考Python官方文档或者其他资料。
 
 ```cpp
    #include "pystring_function.h"
    #include <iostream>
    int main()
    {
    std::cout<<pystring_function::slice("abcdef", 2, 3)<<std::endl;
    //slice为切片函数，函数将会返回一个std::string对象，内容为"c"。
    //在举一些其他的例子
    //pystring_function::endswith("test.exe", "exe"); 将返回 true
    //pystring_function::lower("ThIs"); 将返回一个std::string对象,内容为"this"
    return 0;
    }
 ```
 如给我们希望使用UTF32编码来处理字符串，则可以使用pystring_utf32_function命名空间下的函数来处理。
 例如：
  ```cpp
    #include "pystring_utf32_function.h"
    #include <iostream>
    int main()
    {
    std::cout<<pystring_function::slice(U"abcdef", 2, 3)<<std::endl;
    //slice为切片函数，函数将会返回一个std::u32string对象，内容为U"c"。
    //在举一些其他的例子
    //pystring_function::endswith(U"test.exe", U"exe"); 将返回 true
    //pystring_function::lower(U"ThIs"); 将返回一个std::u32string对象,内容为U"this"
    return 0;
    }
 ```
 2. 使用封装好的类
 直接调用函数终归还是有很多的不便，为了尽可能保持兼容性和Python风格，这里也封装了字符串类。以字节方式处理的类为pystring_ext，以UTF32编码来处理的类为pystring_utf32_class。pystring_ext与std::string兼容，可以使用std::string的所有类成员函数。pystring_utf32_class与std::u32string兼容。可以根据自己的习惯用typedef来更改为自己喜欢的名字。
 此外类中还扩展了py_开头的函数，这些函数尽可能的与Python风格的字符串兼容。to_开头和from_的类型转换函数。
 举例：
   ```cpp
    #include "pystring_class.h"
    #include <iostream>
    int main()
    {
    //兼容std::string的初始化方法
    pystring_ext test_string("input data");
    
    //可以直接使用C++ STL的标准类成员函数，行为与STL一致。
    test_string.append(" append ");
    
    //Python风格的成员函数，与Python String的行为一致（尽可能一致，部分函数略有区别）会返回一个新的pystring_ext对象
    //不会修改test_string对象本身的内容
    test_string.py_replace("end","start")
    return 0;
    }
 ```

 
