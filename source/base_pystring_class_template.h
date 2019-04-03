#if defined(_MSC_VER)
    #pragma once
#endif

//定义公共定义
#ifndef __PYTHON_STRING_BASE_CLASS_TEMPLATE_H__
#define __PYTHON_STRING_BASE_CLASS_TEMPLATE_H__

#include <initializer_list>
//std::swap
#include <utility>
//ostream
#include <iostream>
#include <memory>
#include <string>
#include <string_view>
//va_start
#include <cstdarg>
//custom
#include "compiler_macros.h"
#include "pystring_define.h"
#include "pystring_function_interface.h"
#include "format_function.h"
#include "convert_data.h"
#include "string_extend_algorithm_template.h"

//template <typename BASE_STRING_CLASS, typename BASE_STRING_CHAR_TYPE>
template <typename BASE_STRING_CHAR_TYPE>
class BASE_STRING_CLASS_EX
{
public:
    //
    typedef std::basic_string_view<BASE_STRING_CHAR_TYPE> BASE_STRING_VIEW_CLASS;
    typedef std::basic_string<BASE_STRING_CHAR_TYPE> BASE_STRING_CLASS;
    typedef size_t size_type;
    static const size_t npos = -1;
    //static const size_t npos = BASE_STRING_CLASS::npos;
    typedef typename BASE_STRING_CLASS::iterator iterator;
    typedef typename BASE_STRING_CLASS::const_iterator const_iterator;
    typedef typename BASE_STRING_CLASS::reverse_iterator reverse_iterator;
    typedef typename BASE_STRING_CLASS::const_reverse_iterator const_reverse_iterator;
    typedef typename BASE_STRING_CLASS::allocator_type allocator_type;
    //
    //default constructor
    BASE_STRING_CLASS_EX() : var_container(), m_var_reference(var_container)
    {

    }
    //copy constructor
    BASE_STRING_CLASS_EX(const BASE_STRING_CLASS &str) : var_container(str), m_var_reference(var_container)
    {

    }

    BASE_STRING_CLASS_EX(const BASE_STRING_CLASS_EX &str) : var_container(str.m_var_reference), m_var_reference(var_container)
    {

    }
    //substring constructor
    BASE_STRING_CLASS_EX(const BASE_STRING_CLASS &str, size_t pos, size_t len = npos)
        : var_container(str, pos, len), m_var_reference(var_container)
    {

    }

    BASE_STRING_CLASS_EX(const BASE_STRING_CLASS_EX &str, size_t pos, size_t len = npos)
        : var_container(str.m_var_reference, pos, len), m_var_reference(var_container)
    {

    }
    //from c-string
    BASE_STRING_CLASS_EX(const BASE_STRING_CHAR_TYPE *s) : var_container(s), m_var_reference(var_container)
    {

    }
    //from buffer
    BASE_STRING_CLASS_EX(const BASE_STRING_CHAR_TYPE *s, size_t n) : var_container(s, n), m_var_reference(var_container)
    {

    }
    //fill constructor
    BASE_STRING_CLASS_EX(size_t n, BASE_STRING_CHAR_TYPE c) : var_container(n, c), m_var_reference(var_container)
    {

    }
    //range constructor
    template <class InputIterator>
    BASE_STRING_CLASS_EX(InputIterator first, InputIterator last) : var_container(first, last), m_var_reference(var_container)
    {

    }
    //initializer list
    BASE_STRING_CLASS_EX(std::initializer_list<BASE_STRING_CHAR_TYPE> il) : var_container(il), m_var_reference(var_container)
    {

    }
    //move constructor
    BASE_STRING_CLASS_EX(BASE_STRING_CLASS &&str) noexcept : var_container(str), m_var_reference(var_container)
    {

    }

    BASE_STRING_CLASS_EX(BASE_STRING_CLASS_EX &&str) noexcept : var_container(str.m_var_reference), m_var_reference(var_container)
    {

    }
    //C++17 syd::string_view support
    BASE_STRING_CLASS_EX(const BASE_STRING_VIEW_CLASS &strv) noexcept : var_container(strv.data(), strv.size()), m_var_reference(var_container)
    {

    }
    //reference constructor
    BASE_STRING_CLASS_EX(BASE_STRING_CLASS &str, bool b_enable_reference) noexcept : var_container(), m_var_reference(str)
    {
        UNUSED(b_enable_reference);
    }

    /*
    BASE_STRING_CLASS_EX(size_t n_buffer_size) :var_container(),m_var_reference(var_container)
    {

    }
    */
    //destructor
    ~BASE_STRING_CLASS_EX()
    {

    }

    //static
    static BASE_STRING_CLASS_EX make_string_reference(BASE_STRING_CLASS &str)
    {
        return BASE_STRING_CLASS_EX(str, true);
    }

    static BASE_STRING_CLASS_EX sprintf(const BASE_STRING_CLASS_EX format, ...)
    {
        va_list arg_ptr;
        va_start(arg_ptr, format);
        BASE_STRING_CLASS_EX ret = string_printf::tsuprintf(format, arg_ptr);
        va_end(arg_ptr);
        return ret;
    }

    //operator=
    BASE_STRING_CLASS_EX &operator= (const BASE_STRING_CLASS_EX &str)
    {
        m_var_reference = str.m_var_reference;
        return *this;
    }

    BASE_STRING_CLASS_EX &operator= (const BASE_STRING_CHAR_TYPE *s)
    {
        m_var_reference = s;
        return *this;
    }

    BASE_STRING_CLASS_EX &operator= (BASE_STRING_CHAR_TYPE c)
    {
        m_var_reference = c;
        return *this;
    }

    BASE_STRING_CLASS_EX &operator= (std::initializer_list<char> il)
    {
        m_var_reference = il;
        return *this;
    }

    BASE_STRING_CLASS_EX &operator= (BASE_STRING_CLASS_EX &str) noexcept
    {
        m_var_reference = str.m_var_reference;
        return *this;
    }

    BASE_STRING_CLASS_EX &operator= (BASE_STRING_CLASS_EX &&str) noexcept
    {
        m_var_reference = std::move(str.m_var_reference);
        return *this;
    }

    BASE_STRING_CLASS_EX &operator= (const BASE_STRING_CLASS &str)
    {
        m_var_reference = str;
        return *this;
    }

    BASE_STRING_CLASS_EX &operator= (const BASE_STRING_CLASS &&str)
    {
        m_var_reference = std::move(str);
        return *this;
    }

    //iterator
    iterator begin() noexcept
    {
        return m_var_reference.begin();
    }

    const_iterator begin() const noexcept
    {
        return m_var_reference.cbegin();
    }

    iterator end() noexcept
    {
        return m_var_reference.end();
    }

    const_iterator end() const noexcept
    {
        return m_var_reference.cend();
    }

    //reverse_iterator
    reverse_iterator rbegin() noexcept
    {
        return m_var_reference.rbegin();
    }

    const_reverse_iterator rbegin() const noexcept
    {
        return m_var_reference.crbegin();
    }

    reverse_iterator rend() noexcept
    {
        return m_var_reference.rend();
    }

    const_reverse_iterator rend() const noexcept
    {
        return m_var_reference.crend();
    }

    //const_iterator
    const_iterator cbegin() const noexcept
    {
        return m_var_reference.cbegin();
    }

    const_iterator cend() const noexcept
    {
        return m_var_reference.cend();
    }

    const_iterator crbegin() const noexcept
    {
        return m_var_reference.crbegin();
    }

    const_iterator crend() const noexcept
    {
        return m_var_reference.crend();
    }

    size_type size() const noexcept
    {
        return m_var_reference.size();
    }

    size_type length() const noexcept
    {
        return m_var_reference.length();
    }

    size_type max_size() const noexcept
    {
        return m_var_reference.max_size();
    }

    void resize(size_type n)
    {
        m_var_reference.resize(n);
        return;
    }

    void resize(size_type n, BASE_STRING_CHAR_TYPE c)
    {
        m_var_reference.resize(n, c);
        return;
    }

    size_type capacity() const
    {
        return m_var_reference.capacity();
    }

    void reserve(size_type n = 0)
    {
        m_var_reference.reserve(n);
        return;
    }

    void clear() noexcept
    {
        m_var_reference.clear();
        return;
    }

    bool empty() const noexcept
    {
        return m_var_reference.empty();
    }

    //(since C++11)
    void shrink_to_fit()
    {
        m_var_reference.shrink_to_fit();
        return;
    }

    BASE_STRING_CHAR_TYPE &operator[] (size_t pos)
    {
        //return var_base_container.operator[](pos);
        return m_var_reference[pos];
    }

    const BASE_STRING_CHAR_TYPE &operator[] (size_t pos) const
    {
        return m_var_reference[pos];
    }

    BASE_STRING_CHAR_TYPE &at(size_t pos)
    {
        return m_var_reference.at(pos);
    }

    const BASE_STRING_CHAR_TYPE &at(size_t pos) const
    {
        return m_var_reference.at(pos);
    }

    //(since C++11)
    BASE_STRING_CHAR_TYPE &back()
    {
        return m_var_reference.back();
    }

    //(since C++11)
    const BASE_STRING_CHAR_TYPE &back() const
    {
        return m_var_reference.back();
    }

    //(since C++11)
    BASE_STRING_CHAR_TYPE &front()
    {
        return m_var_reference.front();
    }

    //(since C++11)
    const BASE_STRING_CHAR_TYPE &front() const
    {
        return m_var_reference.front();
    }

    BASE_STRING_CLASS_EX &operator+= (const BASE_STRING_CLASS &str)
    {
        m_var_reference += m_var_reference;
        return *this;
    }

    BASE_STRING_CLASS_EX &operator+= (const BASE_STRING_CLASS_EX &str)
    {
        m_var_reference += str.m_var_reference;
        return *this;
    }

    BASE_STRING_CLASS_EX &operator+= (const BASE_STRING_CHAR_TYPE *s)
    {
        m_var_reference += s;
        return *this;
    }

    BASE_STRING_CLASS_EX &operator+= (BASE_STRING_CHAR_TYPE c)
    {
        m_var_reference += c;
        return *this;
    }

    BASE_STRING_CLASS_EX &operator+= (std::initializer_list<BASE_STRING_CHAR_TYPE> il)
    {
        m_var_reference += il;
        return *this;
    }

    BASE_STRING_CLASS_EX &append(const BASE_STRING_CLASS_EX &str)
    {
        m_var_reference.append(str.m_var_reference);
        return *this;
    }

    BASE_STRING_CLASS_EX &append(const BASE_STRING_CLASS &str)
    {
        m_var_reference.append(str);
        return *this;
    }

    BASE_STRING_CLASS_EX &append(const BASE_STRING_CLASS_EX &str, size_t subpos, size_t sublen = npos)
    {
        m_var_reference.append(str.m_var_reference, subpos, sublen);
        return *this;
    }

    BASE_STRING_CLASS_EX &append(const BASE_STRING_CLASS &str, size_t subpos, size_t sublen = npos)
    {
        m_var_reference.append(str, subpos, sublen);
        return *this;
    }

    BASE_STRING_CLASS_EX &append(const BASE_STRING_CHAR_TYPE *s)
    {
        m_var_reference.append(s);
        return *this;
    }

    BASE_STRING_CLASS_EX &append(const BASE_STRING_CHAR_TYPE *s, size_t n)
    {
        m_var_reference.append(s, n);
        return *this;
    }

    BASE_STRING_CLASS_EX &append(size_t n, BASE_STRING_CHAR_TYPE c)
    {
        m_var_reference.append(n, c);
        return *this;
    }

    template <class InputIterator>
    BASE_STRING_CLASS_EX &append(InputIterator first, InputIterator last)
    {
        m_var_reference.append(first, last);
        return *this;
    }

    BASE_STRING_CLASS_EX &append(std::initializer_list<BASE_STRING_CHAR_TYPE> il)
    {
        m_var_reference.append(il);
        return *this;
    }

    void push_back(BASE_STRING_CHAR_TYPE c)
    {
        m_var_reference.push_back(c);
        return;
    }

    BASE_STRING_CLASS_EX &assign(const BASE_STRING_CLASS &str)
    {
        m_var_reference.assign(str);
        return *this;
    }

    BASE_STRING_CLASS_EX &assign(const BASE_STRING_CLASS_EX &str)
    {
        m_var_reference.assign(str.m_var_reference);
        return *this;
    }

    BASE_STRING_CLASS_EX &assign(const BASE_STRING_CLASS &str, size_t subpos, size_t sublen = npos)
    {
        m_var_reference.assign(str, subpos, subpos);
        return *this;
    }

    BASE_STRING_CLASS_EX &assign(const BASE_STRING_CLASS_EX &str, size_t subpos, size_t sublen = npos)
    {
        m_var_reference.assign(str.m_var_reference, subpos, subpos);
        return *this;
    }

    BASE_STRING_CLASS_EX &assign(const char *s)
    {
        m_var_reference.assign(s);
        return *this;
    }

    BASE_STRING_CLASS_EX &assign(const char *s, size_t n)
    {
        m_var_reference.assign(s, n);
        return *this;
    }

    BASE_STRING_CLASS_EX &assign(size_t n, char c)
    {
        m_var_reference.assign(n, c);
        return *this;
    }

    template <class InputIterator>
    BASE_STRING_CLASS_EX &assign(InputIterator first, InputIterator last)
    {
        m_var_reference.assign(first, last);
        return *this;
    }

    BASE_STRING_CLASS_EX &assign(std::initializer_list<char> il)
    {
        m_var_reference.assign(il);
        return *this;
    }

    BASE_STRING_CLASS_EX &assign(BASE_STRING_CLASS &&str) noexcept
    {
        m_var_reference.assign(std::move(str));
        return *this;
    }

    BASE_STRING_CLASS_EX &assign(BASE_STRING_CLASS_EX &&str) noexcept
    {
        m_var_reference.assign(std::move(str.m_var_reference));
        return *this;
    }

    BASE_STRING_CLASS_EX &insert(size_t pos, const BASE_STRING_CLASS &str)
    {
        m_var_reference.insert(pos, str);
        return *this;
    }

    BASE_STRING_CLASS_EX &insert(size_t pos, const BASE_STRING_CLASS_EX &str)
    {
        m_var_reference.insert(pos, str.m_var_reference);
        return *this;
    }

    BASE_STRING_CLASS_EX &insert(size_t pos, const BASE_STRING_CLASS &str, size_t subpos, size_t sublen = npos)
    {
        m_var_reference.insert(pos, str, subpos, sublen);
        return *this;
    }

    BASE_STRING_CLASS_EX &insert(size_t pos, const BASE_STRING_CLASS_EX &str, size_t subpos, size_t sublen = npos)
    {
        m_var_reference.insert(pos, str.m_var_reference, subpos, sublen);
        return *this;
    }

    BASE_STRING_CLASS_EX &insert(size_t pos, const BASE_STRING_CHAR_TYPE *s)
    {
        m_var_reference.insert(pos, s);
        return *this;
    }

    BASE_STRING_CLASS_EX &insert(size_t pos, const BASE_STRING_CHAR_TYPE *s, size_t n)
    {
        m_var_reference.insert(pos, s, n);
        return *this;
    }

    BASE_STRING_CLASS_EX &insert(size_t pos, size_t n, BASE_STRING_CHAR_TYPE c)
    {
        m_var_reference.insert(pos, n, c);
        return *this;
    }

    iterator insert(const_iterator p, size_t n, BASE_STRING_CHAR_TYPE c)
    {
        return m_var_reference.insert(p, n, c);
    }

    iterator insert(const_iterator p, BASE_STRING_CHAR_TYPE c)
    {
        return m_var_reference.insert(p, c);
    }

    template <class InputIterator>
    iterator insert(iterator p, InputIterator first, InputIterator last)
    {
        return m_var_reference.insert(p, first, last);
    }

    BASE_STRING_CLASS_EX &insert(const_iterator p, std::initializer_list<BASE_STRING_CHAR_TYPE> il)
    {
        m_var_reference.insert(p, il);
        return *this;
    }

    BASE_STRING_CLASS_EX &erase(size_t pos = 0, size_t len = npos)
    {
        m_var_reference.erase(pos, len);
        return *this;
    }

    iterator erase(const_iterator p)
    {
        return m_var_reference.erase(p);
    }

    iterator erase(const_iterator first, const_iterator last)
    {
        return m_var_reference.erase(first, last);
    }

    BASE_STRING_CLASS_EX &replace(size_t pos, size_t len, const BASE_STRING_CLASS &str)
    {
        m_var_reference.replace(pos, len, str);
        return *this;
    }

    BASE_STRING_CLASS_EX &replace(size_t pos, size_t len, const BASE_STRING_CLASS_EX &str)
    {
        m_var_reference.replace(pos, len, str.m_var_reference);
        return *this;
    }

    BASE_STRING_CLASS_EX &replace(const_iterator i1, const_iterator i2, const BASE_STRING_CLASS &str)
    {
        m_var_reference.replace(i1, i2, str);
        return *this;
    }

    BASE_STRING_CLASS_EX &replace(const_iterator i1, const_iterator i2, const BASE_STRING_CLASS_EX &str)
    {
        m_var_reference.replace(i1, i2, str.m_var_reference);
        return *this;
    }

    BASE_STRING_CLASS_EX &replace(size_t pos, size_t len, const BASE_STRING_CLASS &str, size_t subpos, size_t sublen = npos)
    {
        m_var_reference.replace(pos, len, str, subpos, sublen);
        return *this;
    }

    BASE_STRING_CLASS_EX &replace(size_t pos, size_t len, const BASE_STRING_CLASS_EX &str, size_t subpos, size_t sublen = npos)
    {
        m_var_reference.replace(pos, len, str.m_var_reference, subpos, sublen);
        return *this;
    }

    BASE_STRING_CLASS_EX &replace(size_t pos, size_t len, const BASE_STRING_CHAR_TYPE *s)
    {
        m_var_reference.replace(pos, len, s);
        return *this;
    }

    BASE_STRING_CLASS_EX &replace(const_iterator i1, const_iterator i2, const BASE_STRING_CHAR_TYPE *s)
    {
        m_var_reference.replace(i1, i2, s);
        return *this;
    }

    BASE_STRING_CLASS_EX &replace(size_t pos, size_t len, const BASE_STRING_CHAR_TYPE *s, size_t n)
    {
        m_var_reference.replace(pos, len, s, n);
        return *this;
    }

    BASE_STRING_CLASS_EX &replace(const_iterator i1, const_iterator i2, const BASE_STRING_CHAR_TYPE *s, size_t n)
    {
        m_var_reference.replace(i1, i2, s, n);
        return *this;
    }

    BASE_STRING_CLASS_EX &replace(size_t pos, size_t len, size_t n, BASE_STRING_CHAR_TYPE c)
    {
        m_var_reference.replace(pos, len, n, c);
        return *this;
    }

    BASE_STRING_CLASS_EX &replace(const_iterator i1, const_iterator i2, size_t n, BASE_STRING_CHAR_TYPE c)
    {
        m_var_reference.replace(i1, i2, n, c);
        return *this;
    }

    template <class InputIterator>
    BASE_STRING_CLASS_EX &replace(const_iterator i1, const_iterator i2,
                                  InputIterator first, InputIterator last)
    {
        m_var_reference.replace(i1, i2, first, last);
        return *this;
    }

    BASE_STRING_CLASS_EX &replace(const_iterator i1, const_iterator i2, std::initializer_list<BASE_STRING_CHAR_TYPE> il)
    {
        m_var_reference.replace(i1, i2, il);
        return *this;
    }

    void swap(BASE_STRING_CLASS &str)
    {
        m_var_reference.swap(str);
        return;
    }

    void swap(BASE_STRING_CLASS_EX &str)
    {
        m_var_reference.swap(str.m_var_reference);
        return;
    }

    void pop_back()
    {
        m_var_reference.pop_back();
        return;
    }

    const BASE_STRING_CHAR_TYPE *c_str() const noexcept
    {
        return m_var_reference.c_str();
    }

    const BASE_STRING_CHAR_TYPE *data() const noexcept
    {
        return m_var_reference.data();
    }

    allocator_type get_allocator() const noexcept
    {
        return m_var_reference.get_allocator();
    }

    size_t copy(BASE_STRING_CHAR_TYPE *s, size_t len, size_t pos = 0) const
    {
        return m_var_reference.copy(s, len, pos);
    }

    size_t find(const BASE_STRING_CLASS &str, size_t pos = 0) const noexcept
    {
        return m_var_reference.find(str, pos);
    }

    size_t find(const BASE_STRING_CLASS_EX &str, size_t pos = 0) const noexcept
    {
        return m_var_reference.find(str.m_var_reference, pos);
    }

    size_t find(const BASE_STRING_CHAR_TYPE *s, size_t pos = 0) const
    {
        return m_var_reference.find(s, pos);
    }

    size_t find(const BASE_STRING_CHAR_TYPE *s, size_t pos, size_type n) const
    {
        return m_var_reference.find(s, pos, n);
    }

    size_t find(BASE_STRING_CHAR_TYPE c, size_t pos = 0) const noexcept
    {
        return m_var_reference.find(c, pos);
    }

    size_t rfind(const BASE_STRING_CLASS &str, size_t pos = npos) const noexcept
    {
        return m_var_reference.rfind(str, pos);
    }

    size_t rfind(const BASE_STRING_CLASS_EX &str, size_t pos = npos) const noexcept
    {
        return m_var_reference.rfind(str.m_var_reference, pos);
    }

    size_t rfind(const BASE_STRING_CHAR_TYPE *s, size_t pos = npos) const
    {
        return m_var_reference.rfind(s, pos);
    }

    size_t rfind(const BASE_STRING_CHAR_TYPE *s, size_t pos, size_type n) const
    {
        return m_var_reference.rfind(s, pos, n);
    }

    size_t rfind(BASE_STRING_CHAR_TYPE c, size_t pos = npos) const noexcept
    {
        return m_var_reference.rfind(c, pos);
    }

    size_t find_first_of(const BASE_STRING_CLASS &str, size_t pos = 0) const noexcept
    {
        return m_var_reference.find_first_of(str, pos);
    }

    size_t find_first_of(const BASE_STRING_CLASS_EX &str, size_t pos = 0) const noexcept
    {
        return m_var_reference.find_first_of(str.m_var_reference, pos);
    }

    size_t find_first_of(const BASE_STRING_CHAR_TYPE *s, size_t pos = 0) const
    {
        return m_var_reference.find_first_of(s, pos);
    }

    size_t find_first_of(const BASE_STRING_CHAR_TYPE *s, size_t pos, size_type n) const
    {
        return m_var_reference.find_first_of(s, pos, n);
    }

    size_t find_first_of(BASE_STRING_CHAR_TYPE c, size_t pos = 0) const noexcept
    {
        return m_var_reference.find_first_of(c, pos);
    }

    size_t find_last_of(const BASE_STRING_CLASS &str, size_t pos = npos) const noexcept
    {
        return m_var_reference.find_last_of(str, pos);
    }

    size_t find_last_of(const BASE_STRING_CLASS_EX &str, size_t pos = npos) const noexcept
    {
        return m_var_reference.find_last_of(str.m_var_reference, pos);
    }

    size_t find_last_of(const BASE_STRING_CHAR_TYPE *s, size_t pos = npos) const
    {
        return m_var_reference.find_last_of(s, pos);
    }

    size_t find_last_of(const BASE_STRING_CHAR_TYPE *s, size_t pos, size_type n) const
    {
        return m_var_reference.find_last_of(s, pos, n);
    }

    size_t find_last_of(BASE_STRING_CHAR_TYPE c, size_t pos = npos) const noexcept
    {
        return m_var_reference.find_last_of(c, pos);
    }

    size_t find_first_not_of(const BASE_STRING_CLASS &str, size_t pos = 0) const noexcept
    {
        return m_var_reference.find_first_not_of(str, pos);
    }

    size_t find_first_not_of(const BASE_STRING_CLASS_EX &str, size_t pos = 0) const noexcept
    {
        return m_var_reference.find_first_not_of(str.m_var_reference, pos);
    }

    size_t find_first_not_of(const BASE_STRING_CHAR_TYPE *s, size_t pos = 0) const
    {
        return m_var_reference.find_first_not_of(s, pos);
    }

    size_t find_first_not_of(const BASE_STRING_CHAR_TYPE *s, size_t pos, size_type n) const
    {
        return m_var_reference.find_first_not_of(s, pos, n);
    }

    size_t find_first_not_of(BASE_STRING_CHAR_TYPE c, size_t pos = 0) const noexcept
    {
        return m_var_reference.find_first_not_of(c, pos);
    }

    size_t find_last_not_of(const BASE_STRING_CLASS &str, size_t pos = npos) const noexcept
    {
        return m_var_reference.find_last_not_of(str, pos);
    }

    size_t find_last_not_of(const BASE_STRING_CLASS_EX &str, size_t pos = npos) const noexcept
    {
        return m_var_reference.find_last_not_of(str.m_var_reference, pos);
    }

    size_t find_last_not_of(const BASE_STRING_CHAR_TYPE *s, size_t pos = npos) const
    {
        return m_var_reference.find_last_not_of(s, pos);
    }

    size_t find_last_not_of(const BASE_STRING_CHAR_TYPE *s, size_t pos, size_type n) const
    {
        return m_var_reference.find_last_not_of(s, pos, n);
    }

    size_t find_last_not_of(BASE_STRING_CHAR_TYPE c, size_t pos = npos) const noexcept
    {
        return m_var_reference.find_last_not_of(c, pos);
    }

    BASE_STRING_CLASS_EX substr(size_t pos = 0, size_t len = npos) const
    {
        return m_var_reference.substr(pos, len);
    }

    int compare(const BASE_STRING_CLASS &str) const noexcept
    {
        return m_var_reference.compare(str);
    }

    int compare(const BASE_STRING_CLASS_EX &str) const noexcept
    {
        return m_var_reference.compare(str.m_var_reference);
    }

    int compare(size_t pos, size_t len, const BASE_STRING_CLASS &str) const
    {
        return m_var_reference.compare(pos, len, str);
    }

    int compare(size_t pos, size_t len, const BASE_STRING_CLASS_EX &str) const
    {
        return m_var_reference.compare(pos, len, str.m_var_reference);
    }

    int compare(size_t pos, size_t len, const BASE_STRING_CLASS_EX &str,
                size_t subpos, size_t sublen = npos) const
    {
        return m_var_reference.compare(pos, len, str.m_var_reference, subpos, sublen);
    }

    int compare(size_t pos, size_t len, const BASE_STRING_CLASS &str,
                size_t subpos, size_t sublen = npos) const
    {
        return m_var_reference.compare(pos, len, str, subpos, sublen);
    }

    int compare(const BASE_STRING_CHAR_TYPE *s) const
    {
        return m_var_reference.compare(s);
    }

    int compare(size_t pos, size_t len, const BASE_STRING_CHAR_TYPE *s) const
    {
        return m_var_reference.compare(pos, len, s);
    }

    int compare(size_t pos, size_t len, const BASE_STRING_CHAR_TYPE *s, size_t n) const
    {
        return m_var_reference.compare(pos, len, s, n);
    }

    //since C++20
    bool starts_with(BASE_STRING_VIEW_CLASS x) const noexcept
    {
        BASE_STRING_VIEW_CLASS m_view(m_var_reference.data(), m_var_reference.size());
        return string_extend::starts_with(m_view, x);
    }

    //since C++20
    bool starts_with(BASE_STRING_CHAR_TYPE x) const noexcept
    {
        BASE_STRING_VIEW_CLASS m_view(m_var_reference.data(), m_var_reference.size());
        BASE_STRING_VIEW_CLASS cmp_view(&x, 1);
        return string_extend::starts_with(m_view, cmp_view);
    }

    //since C++20
    bool starts_with(const BASE_STRING_CHAR_TYPE *x) const
    {
        BASE_STRING_VIEW_CLASS m_view(m_var_reference.data(), m_var_reference.size());
        BASE_STRING_VIEW_CLASS cmp_view(x);
        return string_extend::starts_with(m_view, cmp_view);
    }

    //since C++20
    bool ends_with(BASE_STRING_VIEW_CLASS x) const noexcept
    {
        BASE_STRING_VIEW_CLASS m_view(m_var_reference.data(), m_var_reference.size());
        return string_extend::ends_with(m_view, x);
    }

    //since C++20
    bool ends_with(BASE_STRING_CHAR_TYPE x) const noexcept
    {
        BASE_STRING_VIEW_CLASS m_view(m_var_reference.data(), m_var_reference.size());
        BASE_STRING_VIEW_CLASS cmp_view(&x, 1);
        return string_extend::ends_with(m_view, cmp_view);
    }

    //since C++20
    bool ends_with(const BASE_STRING_CHAR_TYPE *x) const
    {
        BASE_STRING_VIEW_CLASS m_view(m_var_reference.data(), m_var_reference.size());
        BASE_STRING_VIEW_CLASS cmp_view(x);
        return string_extend::ends_with(m_view, cmp_view);
    }
    //operator+ Overloaded
    friend BASE_STRING_CLASS_EX operator+ (BASE_STRING_CLASS_EX &&lhs, BASE_STRING_CLASS &&rhs)
    {
        return lhs.m_var_reference + rhs;
    }

    friend BASE_STRING_CLASS_EX operator+ (BASE_STRING_CLASS_EX &&lhs, const BASE_STRING_CLASS &rhs)
    {
        return lhs.m_var_reference + rhs;
    }

    friend BASE_STRING_CLASS_EX operator+ (const BASE_STRING_CLASS_EX &lhs, BASE_STRING_CLASS &&rhs)
    {
        return lhs.m_var_reference + rhs;
    }

    friend BASE_STRING_CLASS_EX operator+ (const BASE_STRING_CLASS_EX &lhs, const BASE_STRING_CLASS &rhs)
    {
        return lhs.m_var_reference + rhs;
    }

    friend BASE_STRING_CLASS_EX operator+ (BASE_STRING_CLASS &&lhs, BASE_STRING_CLASS_EX &&rhs)
    {
        return lhs + rhs.m_var_reference;
    }

    friend BASE_STRING_CLASS_EX operator+ (BASE_STRING_CLASS &&lhs, const BASE_STRING_CLASS_EX &rhs)
    {
        return lhs + rhs.m_var_reference;
    }

    friend BASE_STRING_CLASS_EX operator+ (const BASE_STRING_CLASS &lhs, BASE_STRING_CLASS_EX &&rhs)
    {
        return lhs + rhs.m_var_reference;
    }

    friend BASE_STRING_CLASS_EX operator+ (const BASE_STRING_CLASS &lhs, const BASE_STRING_CLASS_EX &rhs)
    {
        return lhs + rhs.m_var_reference;
    }

    friend BASE_STRING_CLASS_EX operator+ (const BASE_STRING_CLASS_EX &lhs, const BASE_STRING_CLASS_EX &rhs)
    {
        return lhs.m_var_reference + rhs.m_var_reference;
    }

    friend BASE_STRING_CLASS_EX operator+ (const BASE_STRING_CLASS_EX &lhs, BASE_STRING_CLASS_EX &&rhs)
    {
        return lhs.m_var_reference + rhs.m_var_reference;
    }

    friend BASE_STRING_CLASS_EX operator+ (BASE_STRING_CLASS_EX &&lhs, const BASE_STRING_CLASS_EX &rhs)
    {
        return lhs.m_var_reference + rhs.m_var_reference;
    }

    friend BASE_STRING_CLASS_EX operator+ (BASE_STRING_CLASS_EX &&lhs, BASE_STRING_CLASS_EX &&rhs)
    {
        return lhs.m_var_reference + rhs.m_var_reference;
    }

    friend BASE_STRING_CLASS_EX operator+ (const BASE_STRING_CLASS_EX &lhs, const BASE_STRING_CHAR_TYPE *rhs)
    {
        return lhs.m_var_reference + rhs;
    }

    friend BASE_STRING_CLASS_EX operator+ (BASE_STRING_CLASS_EX &&lhs, const BASE_STRING_CHAR_TYPE *rhs)
    {
        return lhs.m_var_reference + rhs;
    }

    friend BASE_STRING_CLASS_EX operator+ (const BASE_STRING_CHAR_TYPE *lhs, const BASE_STRING_CLASS_EX &rhs)
    {
        return lhs + rhs.m_var_reference;
    }

    friend BASE_STRING_CLASS_EX operator+ (const BASE_STRING_CHAR_TYPE *lhs, BASE_STRING_CLASS_EX &&rhs)
    {
        return lhs + rhs.m_var_reference;
    }

    friend BASE_STRING_CLASS_EX operator+ (const BASE_STRING_CLASS_EX &lhs, BASE_STRING_CHAR_TYPE rhs)
    {
        return lhs.m_var_reference + rhs;
    }

    friend BASE_STRING_CLASS_EX operator+ (BASE_STRING_CLASS_EX &&lhs, BASE_STRING_CHAR_TYPE rhs)
    {
        return lhs.m_var_reference + rhs;
    }

    friend BASE_STRING_CLASS_EX operator+ (BASE_STRING_CHAR_TYPE lhs, const BASE_STRING_CLASS_EX &rhs)
    {
        return lhs + rhs.m_var_reference;
    }

    friend BASE_STRING_CLASS_EX operator+ (BASE_STRING_CHAR_TYPE lhs, BASE_STRING_CLASS_EX &&rhs)
    {
        return lhs + rhs.m_var_reference;
    }

    //operator compare Overloaded
    friend bool operator== (const BASE_STRING_CLASS_EX &lhs, const BASE_STRING_CLASS_EX &rhs) noexcept
    {
        return lhs.m_var_reference == rhs.m_var_reference;
    }

    friend bool operator== (const BASE_STRING_CLASS_EX &lhs, const BASE_STRING_CLASS &rhs) noexcept
    {
        return lhs.m_var_reference == rhs;
    }

    friend bool operator== (const BASE_STRING_CLASS &lhs, const BASE_STRING_CLASS_EX &rhs) noexcept
    {
        return lhs == rhs.m_var_reference;
    }

    friend bool operator== (const BASE_STRING_CHAR_TYPE *lhs, const BASE_STRING_CLASS_EX &rhs)
    {
        return lhs == rhs.m_var_reference;
    }

    friend bool operator== (const BASE_STRING_CLASS_EX &lhs, const BASE_STRING_CHAR_TYPE *rhs)
    {
        return lhs.m_var_reference == rhs;
    }

    friend bool operator!= (const BASE_STRING_CLASS_EX &lhs, const BASE_STRING_CLASS_EX &rhs) noexcept
    {
        return lhs.m_var_reference != rhs.m_var_reference;
    }

    friend bool operator!= (const BASE_STRING_CLASS_EX &lhs, const BASE_STRING_CLASS &rhs) noexcept
    {
        return lhs.m_var_reference != rhs;
    }

    friend bool operator!= (const BASE_STRING_CLASS &lhs, const BASE_STRING_CLASS_EX &rhs) noexcept
    {
        return lhs != rhs.m_var_reference;
    }

    friend bool operator!= (const BASE_STRING_CHAR_TYPE *lhs, const BASE_STRING_CLASS_EX &rhs)
    {
        return lhs != rhs.m_var_reference;
    }

    friend bool operator!= (const BASE_STRING_CLASS_EX &lhs, const BASE_STRING_CHAR_TYPE *rhs)
    {
        return lhs.m_var_reference != rhs;
    }

    friend bool operator< (const BASE_STRING_CLASS_EX &lhs, const BASE_STRING_CLASS_EX &rhs) noexcept
    {
        return lhs.m_var_reference < rhs.m_var_reference;
    }

    friend bool operator< (const BASE_STRING_CLASS_EX &lhs, const BASE_STRING_CLASS &rhs) noexcept
    {
        return lhs.m_var_reference < rhs;
    }

    friend bool operator< (const BASE_STRING_CLASS_EX &lhs, const BASE_STRING_CHAR_TYPE *rhs)
    {
        return lhs.m_var_reference < rhs;
    }

    friend bool operator< (const BASE_STRING_CLASS &lhs, const BASE_STRING_CLASS_EX &rhs) noexcept
    {
        return lhs < rhs.m_var_reference;
    }

    friend bool operator< (const BASE_STRING_CHAR_TYPE *lhs, const BASE_STRING_CLASS_EX &rhs)
    {
        return lhs < rhs.m_var_reference;
    }

    friend bool operator<= (const BASE_STRING_CLASS_EX &lhs, const BASE_STRING_CLASS_EX &rhs) noexcept
    {
        return lhs.m_var_reference <= rhs.m_var_reference;
    }

    friend bool operator<= (const BASE_STRING_CLASS &lhs, const BASE_STRING_CLASS_EX &rhs) noexcept
    {
        return lhs <= rhs.m_var_reference;
    }

    friend bool operator<= (const BASE_STRING_CLASS_EX &lhs, const BASE_STRING_CLASS &rhs) noexcept
    {
        return lhs.m_var_reference <= rhs;
    }

    friend bool operator<= (const BASE_STRING_CHAR_TYPE *lhs, const BASE_STRING_CLASS_EX &rhs)
    {
        return lhs <= rhs.m_var_reference;
    }

    friend bool operator<= (const BASE_STRING_CLASS_EX &lhs, const BASE_STRING_CHAR_TYPE *rhs)
    {
        return lhs.m_var_reference <= rhs;
    }

    friend bool operator> (const BASE_STRING_CLASS_EX &lhs, const BASE_STRING_CLASS_EX &rhs) noexcept
    {
        return lhs.m_var_reference > rhs.m_var_reference;
    }

    friend bool operator> (const BASE_STRING_CLASS_EX &lhs, const BASE_STRING_CLASS &rhs) noexcept
    {
        return lhs.m_var_reference > rhs;
    }

    friend bool operator> (const BASE_STRING_CLASS &lhs, const BASE_STRING_CLASS_EX &rhs) noexcept
    {
        return lhs > rhs.m_var_reference;
    }

    friend bool operator> (const BASE_STRING_CHAR_TYPE *lhs, const BASE_STRING_CLASS_EX &rhs)
    {
        return lhs > rhs.m_var_reference;
    }

    friend bool operator> (const BASE_STRING_CLASS_EX &lhs, const BASE_STRING_CHAR_TYPE *rhs)
    {
        return lhs.m_var_reference > rhs;
    }

    friend bool operator>= (const BASE_STRING_CLASS_EX &lhs, const BASE_STRING_CLASS_EX &rhs) noexcept
    {
        return lhs.m_var_reference >= rhs.m_var_reference;
    }

    friend bool operator>= (const BASE_STRING_CLASS_EX &lhs, const BASE_STRING_CLASS &rhs) noexcept
    {
        return lhs.m_var_reference >= rhs;
    }

    friend bool operator>= (const BASE_STRING_CLASS &lhs, const BASE_STRING_CLASS_EX &rhs) noexcept
    {
        return lhs >= rhs.m_var_reference;
    }

    friend bool operator>= (const BASE_STRING_CHAR_TYPE *lhs, const BASE_STRING_CLASS_EX &rhs)
    {
        return lhs >= rhs.m_var_reference;
    }

    friend bool operator>= (const BASE_STRING_CLASS_EX &lhs, const BASE_STRING_CHAR_TYPE *rhs)
    {
        return lhs.m_var_reference >= rhs;
    }

    //swap
    friend void swap(BASE_STRING_CLASS_EX &x, BASE_STRING_CLASS_EX &y)
    {
        std::swap(x.m_var_reference, y.m_var_reference);
        return;
    }

    friend void swap(BASE_STRING_CLASS_EX &x, BASE_STRING_CLASS &y)
    {
        std::swap(x.m_var_reference, y);
        return;
    }

    friend void swap(BASE_STRING_CLASS &x, BASE_STRING_CLASS_EX &y)
    {
        std::swap(x, y.m_var_reference);
        return;
    }

    /*
    //u32string类型本身没有流方面的重载
    //iostream
    friend std::istream& operator>> (std::istream& is, BASE_STRING_CLASS_EX& str)
    {
    	is >> str.m_var_reference;
    	return is;
    }

    friend std::ostream& operator<< (std::ostream& os, const BASE_STRING_CLASS_EX& str)
    {
    	os << str.m_var_reference;
    	return os;
    }
    */

    //extend string
    size_type len() const noexcept
    {
        return m_var_reference.size();
    }

    size_type size_bytes() const noexcept
    {
        return m_var_reference.size() * sizeof(BASE_STRING_CHAR_TYPE);
    }

    size_type length_bytes() const noexcept
    {
        return m_var_reference.length() * sizeof(BASE_STRING_CHAR_TYPE);
    }

    //same as copy.
    size_t copy_to(BASE_STRING_CHAR_TYPE *s, size_t len, size_t pos = 0) const
    {
        return m_var_reference.copy(s, len, pos);
    }

    BASE_STRING_CLASS_EX &append(BASE_STRING_CHAR_TYPE c)
    {
        m_var_reference.push_back(c);
        return *this;
    }

    BASE_STRING_CHAR_TYPE *c_dup() const
    {
        size_t n_copy_array_len = m_var_reference.size();
        size_t n_new_array_len = n_copy_array_len + 1;
        BASE_STRING_CHAR_TYPE *sz_ret = (BASE_STRING_CHAR_TYPE *)new BASE_STRING_CHAR_TYPE[n_new_array_len];
        size_t n_copybytes = m_var_reference.size() * sizeof(BASE_STRING_CHAR_TYPE);
        const BASE_STRING_CHAR_TYPE *sz_copy = m_var_reference.c_str();
        memcpy(sz_ret, sz_copy, n_copybytes);
        sz_ret[n_copy_array_len] = 0;
        return sz_ret;
    }

    //将所有old_str替换为new_str
    BASE_STRING_CLASS_EX &replace(const BASE_STRING_CLASS_EX &old_str, const BASE_STRING_CLASS_EX &new_str)
    {
        string_extend::replace_direct(m_var_reference, old_str.m_var_reference, new_str.m_var_reference);
        return *this;
    }

    //将所有old_str替换为new_str
    BASE_STRING_CLASS_EX &replace(const BASE_STRING_CLASS &old_str, const BASE_STRING_CLASS &new_str)
    {
        string_extend::replace_direct(m_var_reference, old_str, new_str);
        return *this;
    }

    void split(
    const BASE_STRING_CLASS_EX &source,
    const BASE_STRING_CLASS_EX &delim,
    std::vector<BASE_STRING_CLASS_EX> &output,
    size_t n_count = MAX_SIZE_T
    )
    {
        string_extend::split(source.m_var_reference, delim.m_var_reference, output, n_count);
    }


    inline std::vector<BASE_STRING_CLASS_EX> split(
    const BASE_STRING_CLASS_EX &source,
    const BASE_STRING_CLASS_EX &delim,
    size_t n_count = MAX_SIZE_T
    )
    {
        std::vector<BASE_STRING_CLASS_EX> output;
        string_extend::split(source.m_var_reference, delim.m_var_reference, output, n_count);
        return output;
    }

    void tolower_direct()
    {
        string_extend::tolower_direct(m_var_reference);
    }

    void toupper_direct()
    {
        string_extend::toupper_direct(m_var_reference);
    }

    BASE_STRING_CLASS_EX tolower() const
    {
        BASE_STRING_CLASS_EX str_ret(m_var_reference);
        string_extend::tolower_direct(str_ret);
        return str_ret;
    }

    BASE_STRING_CLASS_EX toupper() const
    {
        BASE_STRING_CLASS_EX str_ret(m_var_reference);
        string_extend::toupper_direct(str_ret);
        return str_ret;
    }

    //py系列函数
    //切片方法
    BASE_STRING_CLASS_EX py_slice(int_max_t start, int_max_t end = MAX_INT_MAX_T) const
    {
        return pystring_function::slice(m_var_reference, start, end);
    }

    //返回一个首字母大写其他小写的字符串
    //"this IS string" -> "This is string"
    BASE_STRING_CLASS_EX py_capitalize() const
    {
        return pystring_function::capitalize(m_var_reference);
    }

    //返回一个原字符串居中的新字符串,并使用fillchar(默认空格)填充至长度 width 的新字符串
    //"This is Test." -> "FFFThis is Test.FFFF"
    BASE_STRING_CLASS_EX py_center(size_t width, const BASE_STRING_CHAR_TYPE fillchar = ' ')const
    {
        return pystring_function::center(m_var_reference, width, fillchar);
    }

    //返回字符串中指定字符或者字符串的数目。
    //"this is string" -> "is" -> ret 2
    int_max_t py_count(const BASE_STRING_CLASS_EX &substr, int_max_t start = 0, int_max_t end = MAX_INT_MAX_T) const
    {
        return pystring_function::count(m_var_reference, substr.m_var_reference, start, end);
    }

    //判断字符串开头是否等于suffix
    bool py_startswith(const BASE_STRING_CLASS_EX &suffix, int_max_t start = 0, int_max_t end = MAX_INT_MAX_T) const
    {
        return pystring_function::startswith(m_var_reference, suffix.m_var_reference, start, end);
    }

    //判断字符串结尾是否等于suffix
    bool py_endswith(const BASE_STRING_CLASS_EX &suffix, int_max_t start = 0, int_max_t end = MAX_INT_MAX_T) const
    {
        return pystring_function::endswith(m_var_reference, suffix.m_var_reference, start, end);
    }

    //扩展/t为空格（默认为8个）并保持行末尾对齐
    BASE_STRING_CLASS_EX py_expandtabs(int tabsize = 8) const
    {
        return pystring_function::expandtabs(m_var_reference, tabsize);
    }

    //find() 方法检测字符串中是否包含子字符串 substr
    //如果指定 beg（开始） 和 end（结束） 范围，则检查是否包含在指定范围内
    //如果包含子字符串返回开始的索引值，否则返回 - 1
    int_max_t py_find(const BASE_STRING_CLASS_EX &substr, int_max_t start = 0, int_max_t end = MAX_INT_MAX_T) const
    {
        return pystring_function::find(m_var_reference, substr.m_var_reference, start, end);
    }

    //rfind() 方法从右边开始检测字符串中是否包含子字符串 substr
    //如果指定 beg（开始） 和 end（结束） 范围，则检查是否包含在指定范围内
    //如果包含子字符串返回开始的索引值，否则返回 - 1
    int_max_t py_rfind(const BASE_STRING_CLASS_EX &substr, int_max_t start = 0, int_max_t end = MAX_INT_MAX_T) const
    {
        return pystring_function::rfind(m_var_reference, substr.m_var_reference, start, end);
    }

    //index() 方法检测字符串中是否包含子字符串 substr
    //如果指定 beg（开始） 和 end（结束） 范围，则检查是否包含在指定范围内
    //如果包含子字符串返回开始的索引值，否则返回 - 1
    int_max_t py_index(const BASE_STRING_CLASS_EX &substr, int_max_t start = 0, int_max_t end = MAX_INT_MAX_T)
    {
        return pystring_function::index(m_var_reference, substr.m_var_reference, start, end);
    }

    //rindex() 方法从右边开始检测字符串中是否包含子字符串 substr
    //如果指定 beg（开始） 和 end（结束） 范围，则检查是否包含在指定范围内
    //如果包含子字符串返回开始的索引值，否则返回 - 1
    int_max_t py_rindex(const BASE_STRING_CLASS_EX &substr, int_max_t start = 0, int_max_t end = MAX_INT_MAX_T)
    {
        return pystring_function::rindex(m_var_reference, substr.m_var_reference, start, end);
    }

    //如果string至少有一个字符并且所有字符都是字母或数字则返回 true, 否则返回 false
    // "a1"   -> true
    // "a1\n" -> false
    bool py_isalnum() const
    {
        return pystring_function::isalnum(m_var_reference);
    }

    //如果string至少有一个字符并且所有字符都是字母则返回 true, 否则返回 false
    // "a1\n" -> false
    // "abc" -> true
    bool py_isalpha() const
    {
        return pystring_function::isalpha(m_var_reference);
    }

    //如果string至少有一个字符并且所有字符都是数字则返回 true, 否则返回 false
    // "-10" -> false
    // "10" -> true
    bool py_isdigit() const
    {
        return pystring_function::isdigit(m_var_reference);
    }

    //如果string中包含至少一个字母，并且所有字符都是小写，则返回 true，否则返回 false
    //"abc123.0" -> true
    //"A1" -> false
    //"11" -> false
    bool py_islower() const
    {
        return pystring_function::isdigit(m_var_reference);
    }

    //如果string至少有一个字符并且所有字符都是空格（包括\r\n\t\f\v）则返回 true, 否则返回 false
    bool py_isspace() const
    {
        return pystring_function::isspace(m_var_reference);
    }

    //检测字符串中所有的单词拼写首字母是否为大写，且其他字母为小写
    //"this is" -> false
    //"This Is" -> true
    bool py_istitle() const
    {
        return pystring_function::istitle(m_var_reference);
    }

    //如果string中包含至少一个字母，并且所有字符都是大写，则返回 true，否则返回 false
    //"ABC123.0" -> true
    //"a1" -> false
    //"11" -> false
    bool py_isupper() const
    {
        return pystring_function::isupper(m_var_reference);
    }

    //将序列中的元素以指定的字符连接生成一个新的字符串。
    BASE_STRING_CLASS_EX py_join(const BASE_STRING_CLASS_EX &str, std::vector<BASE_STRING_CLASS_EX> &seq) const
    {
        return pystring_algorithm::join(str.m_var_reference, seq);
    }

    //将序列中的元素以指定的字符连接生成一个新的字符串。
    BASE_STRING_CLASS_EX py_join(std::vector<BASE_STRING_CLASS_EX> &seq) const
    {
        return pystring_algorithm::join(m_var_reference, seq);
    }

    //返回一个原字符串左对齐,并使用空格填充至长度 width 的新字符串
    BASE_STRING_CLASS_EX py_ljust(int_max_t width, BASE_STRING_CHAR_TYPE fillchar = ' ') const
    {
        return pystring_function::ljust(m_var_reference, width, fillchar);
    }

    //返回一个原字符串右对齐,并使用空格填充至长度 width 的新字符串
    BASE_STRING_CLASS_EX py_rjust(int_max_t width, BASE_STRING_CHAR_TYPE fillchar = ' ') const
    {
        return pystring_function::rjust(m_var_reference, width, fillchar);
    }

    //转换所有字符为小写
    BASE_STRING_CLASS_EX py_lower() const
    {
        return pystring_function::lower(m_var_reference);
    }

    //转换所有字符为大写
    BASE_STRING_CLASS_EX py_upper() const
    {
        return pystring_function::upper(m_var_reference);
    }

    //lstrip() 方法用于截掉字符串左边的空格(包括\t\r\n)或指定字符。
    BASE_STRING_CLASS_EX py_lstrip(const BASE_STRING_CLASS_EX &chars = BASE_STRING_CLASS_EX()) const
    {
        return pystring_function::lstrip(m_var_reference, chars.m_var_reference);
    }

    //rstrip() 方法用于截掉字符串左边的空格(包括\t\r\n)或指定字符。
    BASE_STRING_CLASS_EX py_rstrip(const BASE_STRING_CLASS_EX &chars = BASE_STRING_CLASS_EX()) const
    {
        return pystring_function::rstrip(m_var_reference, chars.m_var_reference);
    }

    //返回一个3元的元组，第一个为分隔符左边的子串，第二个为分隔符本身，第三个为分隔符右边的子串。
    //"https://baidu.com" -> ('https', '://', 'baidu.com')
    std::vector<BASE_STRING_CLASS_EX> py_partition(const BASE_STRING_CLASS_EX &sep)
    const
    {
        std::vector<BASE_STRING_CLASS_EX> vec_ret;
        pystring_algorithm::partition(vec_ret, m_var_reference, sep.m_var_reference);
        return vec_ret;
    }

    //从右边开始返回一个3元的元组，第一个为分隔符左边的子串，第二个为分隔符本身，第三个为分隔符右边的子串。
    //"https://baidu.com" -> ('https', '://', 'baidu.com')
    std::vector<BASE_STRING_CLASS_EX> py_rpartition(const BASE_STRING_CLASS_EX &sep)
    const
    {
        std::vector<BASE_STRING_CLASS_EX> vec_ret;
        pystring_algorithm::rpartition(vec_ret, m_var_reference, sep.m_var_reference);
        return vec_ret;
    }

    //把 string 中的 str1 替换成 str2, 如果 count 指定，则替换不超过 count 次.
    BASE_STRING_CLASS_EX py_replace(const BASE_STRING_CLASS_EX &oldstr,
                                    const BASE_STRING_CLASS_EX &newstr, int_max_t count = MAX_INT_MAX_T) const
    {
        return pystring_function::replace(m_var_reference, oldstr.m_var_reference, newstr, count);
    }

    //strip() 方法用于截掉字符串两边的空格(包括\t\r\n)或指定字符。
    BASE_STRING_CLASS_EX py_strip(const BASE_STRING_CLASS_EX &chars = BASE_STRING_CLASS_EX()) const
    {
        return pystring_function::strip(m_var_reference, chars.m_var_reference);
    }

    //字符串从右分割
    std::vector<BASE_STRING_CLASS_EX> py_rsplit(const BASE_STRING_CLASS_EX &chars
            , int_max_t maxsplit = MAX_INT_MAX_T) const
    {
        std::vector<BASE_STRING_CLASS_EX> vec_tmp;
        pystring_algorithm::rsplit(vec_tmp, m_var_reference, chars.m_var_reference, maxsplit);
        return vec_tmp;
    }

    //字符串分割
    std::vector<BASE_STRING_CLASS_EX> py_split(const BASE_STRING_CLASS_EX &chars
            , int_max_t maxsplit = MAX_INT_MAX_T) const
    {
        std::vector<BASE_STRING_CLASS_EX> vec_tmp;
        pystring_algorithm::split(vec_tmp, m_var_reference, chars.m_var_reference, maxsplit);
        return vec_tmp;
    }

    //字符串大小写翻转
    BASE_STRING_CLASS_EX py_swapcase() const
    {
        return pystring_function::swapcase(m_var_reference);
    }

    //返回"标题化"的 string,就是说所有单词都是以大写开始，其余字母均为小写
    //"This is.no 123" -> "This Is.No 123"
    BASE_STRING_CLASS_EX py_title() const
    {
        return pystring_function::title(m_var_reference);
    }

    //用于字符映射的转换
    //参数1是被转换的字符串，第2个参数是字符串，表示需要转换的字符，第3个参数是字符串表示转换的目标。
    //两个字符串的长度必须相同，为一一对应的关系。
    //BASE_STRING_CLASS_EX translate("abbc","bc","de") -> "adde"
    BASE_STRING_CLASS_EX py_translate(const BASE_STRING_CLASS_EX &intab,
                                      const BASE_STRING_CLASS_EX &outtab) const
    {
        return pystring_function::translate(m_var_reference, intab.m_var_reference, outtab.m_var_reference);
    }

    //从左边开始使用字符0填充至指定长度，返回新字符串使原字符串右对齐。
    //zfill("test",10); -> "000000test"
    BASE_STRING_CLASS_EX py_zfill(size_t width) const
    {
        return pystring_function::zfill(m_var_reference, width);
    }

    bool py_get_middle_of_pos(const BASE_STRING_CLASS_EX &str_start,
                              const BASE_STRING_CLASS_EX &str_end,
                              size_t &n_start,
                              size_t &n_copylen) const
    {
        return pystring_function::get_middle_of_pos(m_var_reference,
                str_start.m_var_reference,
                str_end.m_var_reference,
                n_start,
                n_copylen);
    }

    //取字符串中两个字符串之间的字符串
    BASE_STRING_CLASS_EX py_get_middle_of(const BASE_STRING_CLASS_EX &str_start,
                                          const BASE_STRING_CLASS_EX &str_end = BASE_STRING_CLASS_EX()) const
    {
        return pystring_function::get_middle_of(m_var_reference, str_start.m_var_reference, str_end.m_var_reference);
    }

    //删除字符串中两个字符串中间的字符串
    BASE_STRING_CLASS_EX py_delete_middle_of(
    const BASE_STRING_CLASS_EX &str_start_flag,
    const BASE_STRING_CLASS_EX &str_end_flag,
    int_max_t n_count = MAX_INT_MAX_T
    ) const
    {
        return pystring_function::delete_middle_of(m_var_reference, str_start_flag.m_var_reference, str_end_flag.m_var_reference, n_count);
    }

    //截断字符串
    BASE_STRING_CLASS_EX py_truncate(const BASE_STRING_CLASS_EX &str_truncate)
    {
        return pystring_function::truncate(m_var_reference, str_truncate.m_var_reference);
    }

    //截断字符串中标志的任意字符
    BASE_STRING_CLASS_EX py_truncate_char(const BASE_STRING_CLASS_EX &str_truncate)
    {
        return pystring_function::truncate_char(m_var_reference, str_truncate.m_var_reference);
    }

    //format
    BASE_STRING_CLASS_EX argv(const BASE_STRING_CLASS_EX &str_input)
    {
        string_format::format_argv(m_var_reference, str_input.m_var_reference);
        return *this;
    }

    BASE_STRING_CLASS_EX argv(const int n_input)
    {
        string_format::format_argv(m_var_reference, n_input);
        return *this;
    }

    BASE_STRING_CLASS_EX argv(const long double f_input, int n_decimal_digits = 2)
    {
        string_format::format_argv(m_var_reference, f_input);
        return *this;
    }

    //数据类型转换模板
    int to_int() const
    {
        return (int)(convert_type::to_int_max(m_var_reference));
    }

    int_max_t to_int_max_t() const
    {
        return (int_max_t)(convert_type::to_int_max(m_var_reference));
    }

    float to_float() const
    {
        return (float)(convert_type::to_float_max(m_var_reference));
    }

    double to_double() const
    {
        return (double)(convert_type::to_float_max(m_var_reference));
    }

    double to_long_double() const
    {
        return (long double)(convert_type::to_float_max(m_var_reference));
    }
    
    std::string to_std_string() const
    {
        std::string ret;
        uft_conv::convert_utf_string(m_var_reference,ret);
        return ret;
    }
    
    std::wstring to_std_wstring() const
    {
        std::wstring ret;
        uft_conv::convert_utf_string(m_var_reference,ret);
        return ret;
    }
    
    std::u16string to_std_u16string() const
    {
        std::u16string ret;
        uft_conv::convert_utf_string(m_var_reference,ret);
        return ret;
    }
    
    std::u32string to_std_u32string() const
    {
        std::u32string ret;
        uft_conv::convert_utf_string(m_var_reference,ret);
        return ret;
    }
    
    void from_std_string(const std::string &input)
    {
        uft_conv::convert_utf_string(input,m_var_reference);
    }
    
    void from_std_wstring(const std::wstring &input)
    {
        uft_conv::convert_utf_string(input,m_var_reference);
    }
    
    void from_std_u16string(const std::u16string &input)
    {
        uft_conv::convert_utf_string(input,m_var_reference);
    }
    
    void from_std_u32string(const std::u32string &input)
    {
        uft_conv::convert_utf_string(input,m_var_reference);
    }
    
    BASE_STRING_CLASS_EX from_int(int n_input)
    {
        m_var_reference = convert_type::int_to_string(n_input);
        return *this;
    }

    BASE_STRING_CLASS_EX from_int_max_t(int_max_t n_input)
    {
        m_var_reference = convert_type::int_to_string(n_input);
        return *this;
    }

    BASE_STRING_CLASS_EX from_float(float n_input, int n_decimal_digits = 2)
    {
        m_var_reference = convert_type::float_to_string(n_input, n_decimal_digits);
        return *this;
    }

    BASE_STRING_CLASS_EX from_double(double n_input, int n_decimal_digits = 2)
    {
        m_var_reference = convert_type::float_to_string(n_input, n_decimal_digits);
        return *this;
    }

    BASE_STRING_CLASS_EX from_long_double(long double n_input, int n_decimal_digits = 2)
    {
        m_var_reference = convert_type::float_to_string(n_input, n_decimal_digits);
        return *this;
    }

    static BASE_STRING_CLASS_EX to_pystring(int n_input)
    {
        return convert_type::int_to_string(n_input);
    }

    static BASE_STRING_CLASS_EX to_pystring(int_max_t n_input)
    {
        return convert_type::int_to_string(n_input);
    }

    static BASE_STRING_CLASS_EX to_pystring(float n_input, int n_decimal_digits = 2)
    {
        return convert_type::float_to_string(n_input, n_decimal_digits);
    }

    static BASE_STRING_CLASS_EX to_pystring(double n_input, int n_decimal_digits = 2)
    {
        return convert_type::float_to_string(n_input, n_decimal_digits);
    }

    static BASE_STRING_CLASS_EX to_pystring(long double n_input, int n_decimal_digits = 2)
    {
        return convert_type::float_to_string(n_input, n_decimal_digits);
    }

    //类型转换模板
    /*
    operator BASE_STRING_CLASS()
    {
        return m_var_reference;
    }
    */

    operator BASE_STRING_CLASS &()
    {
        return m_var_reference;
    }

    operator const BASE_STRING_CLASS &() const
    {
        return m_var_reference;
    }

    BASE_STRING_CLASS &to_basic_type()
    {
        return m_var_reference;
    }

    const BASE_STRING_CLASS &to_basic_type() const
    {
        return m_var_reference;
    }

    /*
        BASE_STRING_CLASS to_basic_type_copy() const
        {
            return m_var_reference;
        }
    */

protected:
    BASE_STRING_CLASS var_container;
    BASE_STRING_CLASS &m_var_reference;
    /*
    inline BASE_STRING_CLASS& base_string()
    {
        return m_var_reference;
    }

    inline const BASE_STRING_CLASS& base_string() const
    {
        return m_var_reference;
    }
    */
};

typedef BASE_STRING_CLASS_EX<char32_t> std_u32string_proxy;
typedef BASE_STRING_CLASS_EX<char16_t> std_u16string_proxy;
typedef BASE_STRING_CLASS_EX<char> std_string_proxy;
#endif //__PYTHON_STRING_BASE_CLASS_TEMPLATE_H__
