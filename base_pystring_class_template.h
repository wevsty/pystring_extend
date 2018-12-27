#if defined(_MSC_VER)
#pragma once
#endif

//定义公共定义
#ifndef __PYTHON_STRING_BASE_CLASS_TEMPLATE_H__
#define __PYTHON_STRING_BASE_CLASS_TEMPLATE_H__

#include "pystring_interface_function.h"
#include "format_function.h"
#include "data_conv.h"
#include <initializer_list>
#include <utility> //std::swap
#include <iostream> //ostream
#include <memory>
#include <string>

//template <typename BASE_STRING_CLASS, typename BASE_STRING_CHAR_TYPE>
template <typename BASE_STRING_CHAR_TYPE>
class BASE_STRING_CLASS_EX
{
public:
	//
	typedef std::basic_string<BASE_STRING_CHAR_TYPE> BASE_STRING_CLASS;
	typedef size_t size_type;
	static const size_t npos = -1;
	typedef typename BASE_STRING_CLASS::iterator iterator;
	typedef typename BASE_STRING_CLASS::const_iterator const_iterator;
	typedef typename BASE_STRING_CLASS::reverse_iterator reverse_iterator;
	typedef typename BASE_STRING_CLASS::const_reverse_iterator const_reverse_iterator;
	typedef typename BASE_STRING_CLASS::allocator_type allocator_type;
	//
	//default constructor
	BASE_STRING_CLASS_EX() : var_container()
	{

	}
	//copy constructor
	BASE_STRING_CLASS_EX(const BASE_STRING_CLASS &str) : var_container(str)
	{

	}

	BASE_STRING_CLASS_EX(const BASE_STRING_CLASS_EX &str) : var_container(str.var_container)
	{

	}
	//substring constructor
	BASE_STRING_CLASS_EX(const BASE_STRING_CLASS &str, size_t pos, size_t len = npos)
		: var_container(str, pos, len)
	{

	}

	BASE_STRING_CLASS_EX(const BASE_STRING_CLASS_EX &str, size_t pos, size_t len = npos)
		: var_container(str.var_container, pos, len)
	{

	}
	//from c-string
	BASE_STRING_CLASS_EX(const BASE_STRING_CHAR_TYPE *s) : var_container(s)
	{

	}
	//from buffer
	BASE_STRING_CLASS_EX(const BASE_STRING_CHAR_TYPE *s, size_t n) : var_container(s, n)
	{

	}
	//fill constructor
	BASE_STRING_CLASS_EX(size_t n, BASE_STRING_CHAR_TYPE c) : var_container(n, c)
	{

	}
	//range constructor
	template <class InputIterator>
	BASE_STRING_CLASS_EX(InputIterator first, InputIterator last) : var_container(first, last)
	{

	}
	//initializer list
	BASE_STRING_CLASS_EX(std::initializer_list<BASE_STRING_CHAR_TYPE> il) : var_container(il)
	{

	}
	//move constructor
	BASE_STRING_CLASS_EX(BASE_STRING_CLASS &&str) noexcept : var_container(str)
	{

	}

	BASE_STRING_CLASS_EX(BASE_STRING_CLASS_EX &&str) noexcept : var_container(str.var_container)
	{

	}
	/*
	BASE_STRING_CLASS_EX(size_t n_buffer_size) :var_base_container()
	{

	}
	*/
	//destructor
	~BASE_STRING_CLASS_EX()
	{

	}
	//operator=
	BASE_STRING_CLASS_EX &operator= (const BASE_STRING_CLASS_EX &str)
	{
		var_container = str.var_container;
		return *this;
	}

	BASE_STRING_CLASS_EX &operator= (const BASE_STRING_CHAR_TYPE *s)
	{
		var_container = s;
		return *this;
	}

	BASE_STRING_CLASS_EX &operator= (BASE_STRING_CHAR_TYPE c)
	{
		var_container = c;
		return *this;
	}

	BASE_STRING_CLASS_EX &operator= (std::initializer_list<char> il)
	{
		var_container = il;
		return *this;
	}

	BASE_STRING_CLASS_EX &operator= (BASE_STRING_CLASS_EX &&str) noexcept
	{
		var_container = str.var_container;
		return *this;
	}

	BASE_STRING_CLASS_EX &operator= (const BASE_STRING_CLASS &str)
	{
		var_container = str;
		return *this;
	}

	BASE_STRING_CLASS_EX &operator= (const BASE_STRING_CLASS &&str)
	{
		var_container = str;
		return *this;
	}

	//iterator
	iterator begin() noexcept
	{
		return var_container.begin();
	}

	const_iterator begin() const noexcept
	{
		return var_container.cbegin();
	}

	iterator end() noexcept
	{
		return var_container.end();
	}

	const_iterator end() const noexcept
	{
		return var_container.cend();
	}

	//reverse_iterator
	reverse_iterator rbegin() noexcept
	{
		return var_container.rbegin();
	}

	const_reverse_iterator rbegin() const noexcept
	{
		return var_container.crbegin();
	}

	reverse_iterator rend() noexcept
	{
		return var_container.rend();
	}

	const_reverse_iterator rend() const noexcept
	{
		return var_container.crend();
	}

	//const_iterator
	const_iterator cbegin() const noexcept
	{
		return var_container.cbegin();
	}

	const_iterator cend() const noexcept
	{
		return var_container.cend();
	}

	const_iterator crbegin() const noexcept
	{
		return var_container.crbegin();
	}

	const_iterator crend() const noexcept
	{
		return var_container.crend();
	}

	size_type size() const noexcept
	{
		return var_container.size();
	}

	size_type length() const noexcept
	{
		return var_container.length();
	}

	size_type max_size() const noexcept
	{
		return var_container.max_size();
	}

	void resize(size_type n)
	{
		var_container.resize(n);
		return;
	}

	void resize(size_type n, BASE_STRING_CHAR_TYPE c)
	{
		var_container.resize(n, c);
		return;
	}

	size_type capacity() const
	{
		return var_container.capacity();
	}

	void reserve(size_type n = 0)
	{
		var_container.reserve(n);
		return;
	}

	void clear() noexcept
	{
		var_container.clear();
		return;
	}

	bool empty() const noexcept
	{
		return var_container.empty();
	}

	//(since C++11)
	void shrink_to_fit()
	{
		var_container.shrink_to_fit();
		return;
	}

	BASE_STRING_CHAR_TYPE &operator[] (size_t pos)
	{
		//return var_base_container.operator[](pos);
		return var_container[pos];
	}

	const BASE_STRING_CHAR_TYPE &operator[] (size_t pos) const
	{
		return var_container[pos];
	}

	BASE_STRING_CHAR_TYPE &at(size_t pos)
	{
		return var_container.at(pos);
	}

	const BASE_STRING_CHAR_TYPE &at(size_t pos) const
	{
		return var_container.at(pos);
	}

	//(since C++11)
	BASE_STRING_CHAR_TYPE &back()
	{
		return var_container.back();
	}

	//(since C++11)
	const BASE_STRING_CHAR_TYPE &back() const
	{
		return var_container.back();
	}

	//(since C++11)
	BASE_STRING_CHAR_TYPE &front()
	{
		return var_container.front();
	}

	//(since C++11)
	const BASE_STRING_CHAR_TYPE &front() const
	{
		return var_container.front();
	}

	BASE_STRING_CLASS_EX &operator+= (const BASE_STRING_CLASS &str)
	{
		var_container += var_container;
		return *this;
	}

	BASE_STRING_CLASS_EX &operator+= (const BASE_STRING_CLASS_EX &str)
	{
		var_container += str.var_container;
		return *this;
	}

	BASE_STRING_CLASS_EX &operator+= (const BASE_STRING_CHAR_TYPE *s)
	{
		var_container += s;
		return *this;
	}

	BASE_STRING_CLASS_EX &operator+= (BASE_STRING_CHAR_TYPE c)
	{
		var_container += c;
		return *this;
	}

	BASE_STRING_CLASS_EX &operator+= (std::initializer_list<BASE_STRING_CHAR_TYPE> il)
	{
		var_container += il;
		return *this;
	}

	BASE_STRING_CLASS_EX &append(const BASE_STRING_CLASS_EX &str)
	{
		var_container.append(str.var_container);
		return *this;
	}

	BASE_STRING_CLASS_EX &append(const BASE_STRING_CLASS &str)
	{
		var_container.append(str);
		return *this;
	}

	BASE_STRING_CLASS_EX &append(const BASE_STRING_CLASS &str, size_t subpos, size_t sublen = npos)
	{
		var_container.append(str, subpos, sublen);
		return *this;
	}

	BASE_STRING_CLASS_EX &append(const BASE_STRING_CHAR_TYPE *s)
	{
		var_container.append(s);
		return *this;
	}

	BASE_STRING_CLASS_EX &append(const BASE_STRING_CHAR_TYPE *s, size_t n)
	{
		var_container.append(s, n);
		return *this;
	}

	BASE_STRING_CLASS_EX &append(size_t n, BASE_STRING_CHAR_TYPE c)
	{
		var_container.append(n, c);
		return *this;
	}

	template <class InputIterator>
	BASE_STRING_CLASS_EX &append(InputIterator first, InputIterator last)
	{
		var_container.append(first, last);
		return *this;
	}

	BASE_STRING_CLASS_EX &append(std::initializer_list<BASE_STRING_CHAR_TYPE> il)
	{
		var_container.append(il);
		return *this;
	}

	void push_back(BASE_STRING_CHAR_TYPE c)
	{
		var_container.push_back(c);
		return;
	}

	BASE_STRING_CLASS_EX &assign(const BASE_STRING_CLASS_EX &str)
	{
		var_container.assign(str.var_container);
		return *this;
	}

	BASE_STRING_CLASS_EX &assign(const BASE_STRING_CLASS &str)
	{
		var_container.assign(str);
		return *this;
	}

	BASE_STRING_CLASS_EX &assign(const BASE_STRING_CLASS_EX &str, size_t subpos, size_t sublen = npos)
	{
		var_container.assign(str, subpos, subpos);
		return *this;
	}

	BASE_STRING_CLASS_EX &assign(const char *s)
	{
		var_container.assign(s);
		return *this;
	}

	BASE_STRING_CLASS_EX &assign(const char *s, size_t n)
	{
		var_container.assign(s, n);
		return *this;
	}

	BASE_STRING_CLASS_EX &assign(size_t n, char c)
	{
		var_container.assign(n, c);
		return *this;
	}

	template <class InputIterator>
	BASE_STRING_CLASS_EX &assign(InputIterator first, InputIterator last)
	{
		var_container.assign(first, last);
		return *this;
	}

	BASE_STRING_CLASS_EX &assign(std::initializer_list<char> il)
	{
		var_container.assign(il);
		return *this;
	}

	BASE_STRING_CLASS_EX &assign(BASE_STRING_CLASS_EX &&str) noexcept
	{
		var_container.assign(str);
		return *this;
	}

	BASE_STRING_CLASS_EX &insert(size_t pos, const BASE_STRING_CLASS_EX &str)
	{
		var_container.insert(pos, str.var_container);
		return *this;
	}

	BASE_STRING_CLASS_EX &insert(size_t pos, const BASE_STRING_CLASS &str)
	{
		var_container.insert(pos, str);
		return *this;
	}

	BASE_STRING_CLASS_EX &insert(size_t pos, const BASE_STRING_CLASS_EX &str, size_t subpos, size_t sublen = npos)
	{
		var_container.insert(pos, str, subpos, sublen);
		return *this;
	}

	BASE_STRING_CLASS_EX &insert(size_t pos, const BASE_STRING_CLASS &str, size_t subpos, size_t sublen = npos)
	{
		var_container.insert(pos, str.var_container, subpos, sublen);
		return *this;
	}

	BASE_STRING_CLASS_EX &insert(size_t pos, const BASE_STRING_CHAR_TYPE *s)
	{
		var_container.insert(pos, s);
		return *this;
	}

	BASE_STRING_CLASS_EX &insert(size_t pos, const BASE_STRING_CHAR_TYPE *s, size_t n)
	{
		var_container.insert(pos, s, n);
		return *this;
	}

	BASE_STRING_CLASS_EX &insert(size_t pos, size_t n, BASE_STRING_CHAR_TYPE c)
	{
		var_container.insert(pos, n, c);
		return *this;
	}

	iterator insert(const_iterator p, size_t n, BASE_STRING_CHAR_TYPE c)
	{
		return var_container.insert(p, n, c);
	}

	iterator insert(const_iterator p, BASE_STRING_CHAR_TYPE c)
	{
		return var_container.insert(p, c);
	}

	template <class InputIterator>
	iterator insert(iterator p, InputIterator first, InputIterator last)
	{
		return var_container.insert(p, first, last);
	}

	BASE_STRING_CLASS_EX &insert(const_iterator p, std::initializer_list<BASE_STRING_CHAR_TYPE> il)
	{
		var_container.insert(p, il);
		return *this;
	}

	BASE_STRING_CLASS_EX &erase(size_t pos = 0, size_t len = npos)
	{
		var_container.erase(pos, len);
		return *this;
	}

	iterator erase(const_iterator p)
	{
		return var_container.erase(p);
	}

	iterator erase(const_iterator first, const_iterator last)
	{
		return var_container.erase(first, last);
	}

	BASE_STRING_CLASS_EX &replace(size_t pos, size_t len, const BASE_STRING_CLASS_EX &str)
	{
		var_container.replace(pos, len, str.var_container);
		return *this;
	}

	BASE_STRING_CLASS_EX &replace(size_t pos, size_t len, const BASE_STRING_CLASS &str)
	{
		var_container.replace(pos, len, str);
		return *this;
	}

	BASE_STRING_CLASS_EX &replace(const_iterator i1, const_iterator i2, const BASE_STRING_CLASS_EX &str)
	{
		var_container.replace(i1, i2, str.var_container);
		return *this;
	}

	BASE_STRING_CLASS_EX &replace(const_iterator i1, const_iterator i2, const BASE_STRING_CLASS &str)
	{
		var_container.replace(i1, i2, str);
		return *this;
	}

	BASE_STRING_CLASS_EX &replace(size_t pos, size_t len, const BASE_STRING_CLASS_EX &str, size_t subpos, size_t sublen = npos)
	{
		var_container.replace(pos, len, str.var_container, subpos, sublen);
		return *this;
	}

	BASE_STRING_CLASS_EX &replace(size_t pos, size_t len, const BASE_STRING_CLASS &str, size_t subpos, size_t sublen = npos)
	{
		var_container.replace(pos, len, str, subpos, sublen);
		return *this;
	}

	BASE_STRING_CLASS_EX &replace(size_t pos, size_t len, const BASE_STRING_CHAR_TYPE *s)
	{
		var_container.replace(pos, len, s);
		return *this;
	}

	BASE_STRING_CLASS_EX &replace(const_iterator i1, const_iterator i2, const BASE_STRING_CHAR_TYPE *s)
	{
		var_container.replace(i1, i2, s);
		return *this;
	}

	BASE_STRING_CLASS_EX &replace(size_t pos, size_t len, const BASE_STRING_CHAR_TYPE *s, size_t n)
	{
		var_container.replace(pos, len, s, n);
		return *this;
	}

	BASE_STRING_CLASS_EX &replace(const_iterator i1, const_iterator i2, const BASE_STRING_CHAR_TYPE *s, size_t n)
	{
		var_container.replace(i1, i2, s, n);
		return *this;
	}

	BASE_STRING_CLASS_EX &replace(size_t pos, size_t len, size_t n, BASE_STRING_CHAR_TYPE c)
	{
		var_container.replace(pos, len, n, c);
		return *this;
	}

	BASE_STRING_CLASS_EX &replace(const_iterator i1, const_iterator i2, size_t n, BASE_STRING_CHAR_TYPE c)
	{
		var_container.replace(i1, i2, n, c);
		return *this;
	}

	template <class InputIterator>
	BASE_STRING_CLASS_EX &replace(const_iterator i1, const_iterator i2,
		InputIterator first, InputIterator last)
	{
		var_container.replace(i1, i2, first, last);
		return *this;
	}

	BASE_STRING_CLASS_EX &replace(const_iterator i1, const_iterator i2, std::initializer_list<BASE_STRING_CHAR_TYPE> il)
	{
		var_container.replace(i1, i2, il);
		return *this;
	}

	void swap(BASE_STRING_CLASS &str)
	{
		var_container.swap(str);
		return;
	}

	void swap(BASE_STRING_CLASS_EX &str)
	{
		var_container.swap(str.var_container);
		return;
	}

	void pop_back()
	{
		var_container.pop_back();
		return;
	}

	const BASE_STRING_CHAR_TYPE *c_str() const noexcept
	{
		return var_container.c_str();
	}

	const BASE_STRING_CHAR_TYPE *data() const noexcept
	{
		return var_container.data();
	}

	allocator_type get_allocator() const noexcept
	{
		return var_container.get_allocator();
	}

	size_t copy(BASE_STRING_CHAR_TYPE *s, size_t len, size_t pos = 0) const
	{
		return var_container.copy(s, len, pos);
	}

	size_t find(const BASE_STRING_CLASS_EX &str, size_t pos = 0) const noexcept
	{
		return var_container.find(str.var_container, pos);
	}

	size_t find(const BASE_STRING_CLASS &str, size_t pos = 0) const noexcept
	{
		return var_container.find(str, pos);
	}

	size_t find(const BASE_STRING_CHAR_TYPE *s, size_t pos = 0) const
	{
		return var_container.find(s, pos);
	}

	size_t find(const BASE_STRING_CHAR_TYPE *s, size_t pos, size_type n) const
	{
		return var_container.find(s, pos, n);
	}

	size_t find(BASE_STRING_CHAR_TYPE c, size_t pos = 0) const noexcept
	{
		return var_container.find(c, pos);
	}

	size_t rfind(const BASE_STRING_CLASS_EX &str, size_t pos = npos) const noexcept
	{
		return var_container.rfind(str.var_container, pos);
	}

	size_t rfind(const BASE_STRING_CLASS &str, size_t pos = npos) const noexcept
	{
		return var_container.rfind(str, pos);
	}

	size_t rfind(const BASE_STRING_CHAR_TYPE *s, size_t pos = npos) const
	{
		return var_container.rfind(s, pos);
	}

	size_t rfind(const BASE_STRING_CHAR_TYPE *s, size_t pos, size_type n) const
	{
		return var_container.rfind(s, pos, n);
	}

	size_t rfind(BASE_STRING_CHAR_TYPE c, size_t pos = npos) const noexcept
	{
		return var_container.rfind(c, pos);
	}

	size_t find_first_of(const BASE_STRING_CLASS_EX &str, size_t pos = 0) const noexcept
	{
		return var_container.find_first_of(str.var_container, pos);
	}

	size_t find_first_of(const BASE_STRING_CLASS &str, size_t pos = 0) const noexcept
	{
		return var_container.find_first_of(str, pos);
	}

	size_t find_first_of(const BASE_STRING_CHAR_TYPE *s, size_t pos = 0) const
	{
		return var_container.find_first_of(s, pos);
	}

	size_t find_first_of(const BASE_STRING_CHAR_TYPE *s, size_t pos, size_type n) const
	{
		return var_container.find_first_of(s, pos, n);
	}

	size_t find_first_of(BASE_STRING_CHAR_TYPE c, size_t pos = 0) const noexcept
	{
		return var_container.find_first_of(c, pos);
	}

	size_t find_last_of(const BASE_STRING_CLASS_EX &str, size_t pos = npos) const noexcept
	{
		return var_container.find_last_of(str.var_container, pos);
	}

	size_t find_last_of(const BASE_STRING_CLASS &str, size_t pos = npos) const noexcept
	{
		return var_container.find_last_of(str, pos);
	}

	size_t find_last_of(const BASE_STRING_CHAR_TYPE *s, size_t pos = npos) const
	{
		return var_container.find_last_of(s, pos);
	}

	size_t find_last_of(const BASE_STRING_CHAR_TYPE *s, size_t pos, size_type n) const
	{
		return var_container.find_last_of(s, pos, n);
	}

	size_t find_last_of(BASE_STRING_CHAR_TYPE c, size_t pos = npos) const noexcept
	{
		return var_container.find_last_of(c, pos);
	}
	size_t find_first_not_of(const BASE_STRING_CLASS_EX &str, size_t pos = 0) const noexcept
	{
		return var_container.find_first_not_of(str.var_container, pos);
	}

	size_t find_first_not_of(const BASE_STRING_CLASS &str, size_t pos = 0) const noexcept
	{
		return var_container.find_first_not_of(str, pos);
	}

	size_t find_first_not_of(const BASE_STRING_CHAR_TYPE *s, size_t pos = 0) const
	{
		return var_container.find_first_not_of(s, pos);
	}

	size_t find_first_not_of(const BASE_STRING_CHAR_TYPE *s, size_t pos, size_type n) const
	{
		return var_container.find_first_not_of(s, pos, n);
	}

	size_t find_first_not_of(BASE_STRING_CHAR_TYPE c, size_t pos = 0) const noexcept
	{
		return var_container.find_first_not_of(c, pos);
	}

	size_t find_last_not_of(const BASE_STRING_CLASS_EX &str, size_t pos = npos) const noexcept
	{
		return var_container.find_last_not_of(str.var_container, pos);
	}

	size_t find_last_not_of(const BASE_STRING_CLASS &str, size_t pos = npos) const noexcept
	{
		return var_container.find_last_not_of(str, pos);
	}

	size_t find_last_not_of(const BASE_STRING_CHAR_TYPE *s, size_t pos = npos) const
	{
		return var_container.find_last_not_of(s, pos);
	}

	size_t find_last_not_of(const BASE_STRING_CHAR_TYPE *s, size_t pos, size_type n) const
	{
		return var_container.find_last_not_of(s, pos, n);
	}

	size_t find_last_not_of(BASE_STRING_CHAR_TYPE c, size_t pos = npos) const noexcept
	{
		return var_container.find_last_not_of(c, pos);
	}

	BASE_STRING_CLASS_EX substr(size_t pos = 0, size_t len = npos) const
	{
		return var_container.substr(pos, len);
	}

	int compare(const BASE_STRING_CLASS_EX &str) const noexcept
	{
		return var_container.compare(str.var_container);
	}

	int compare(const BASE_STRING_CLASS &str) const noexcept
	{
		return var_container.compare(str);
	}

	int compare(size_t pos, size_t len, const BASE_STRING_CLASS_EX &str) const
	{
		return var_container.compare(pos, len, str.var_container);
	}

	int compare(size_t pos, size_t len, const BASE_STRING_CLASS &str) const
	{
		return var_container.compare(pos, len, str);
	}

	int compare(size_t pos, size_t len, const BASE_STRING_CLASS_EX &str,
		size_t subpos, size_t sublen = npos) const
	{
		return var_container.compare(pos, len, str.var_container, subpos, sublen);
	}

	int compare(size_t pos, size_t len, const BASE_STRING_CLASS &str,
		size_t subpos, size_t sublen = npos) const
	{
		return var_container.compare(pos, len, str, subpos, sublen);
	}

	int compare(const BASE_STRING_CHAR_TYPE *s) const
	{
		return var_container.compare(s);
	}

	int compare(size_t pos, size_t len, const BASE_STRING_CHAR_TYPE *s) const
	{
		return var_container.compare(pos, len, s);
	}

	int compare(size_t pos, size_t len, const BASE_STRING_CHAR_TYPE *s, size_t n) const
	{
		return var_container.compare(pos, len, s, n);
	}

	//operator+ Overloaded
	friend BASE_STRING_CLASS_EX operator+ (const BASE_STRING_CLASS_EX &lhs, const BASE_STRING_CLASS &rhs)
	{
		return lhs.var_container + rhs;
	}

	friend BASE_STRING_CLASS_EX operator+ (BASE_STRING_CLASS_EX &&lhs, BASE_STRING_CLASS &&rhs)
	{
		return lhs.var_container + rhs;
	}

	friend BASE_STRING_CLASS_EX operator+ (BASE_STRING_CLASS_EX &&lhs, const BASE_STRING_CLASS &rhs)
	{
		return lhs.var_container + rhs;
	}

	friend BASE_STRING_CLASS_EX operator+ (const BASE_STRING_CLASS_EX &lhs, BASE_STRING_CLASS &&rhs)
	{
		return lhs.var_container + rhs;
	}

	friend BASE_STRING_CLASS_EX operator+ (const BASE_STRING_CLASS &lhs, const BASE_STRING_CLASS_EX &rhs)
	{
		return lhs + rhs.var_container;
	}

	friend BASE_STRING_CLASS_EX operator+ (BASE_STRING_CLASS &&lhs, BASE_STRING_CLASS_EX &&rhs)
	{
		return lhs + rhs.var_container;
	}

	friend BASE_STRING_CLASS_EX operator+ (BASE_STRING_CLASS &&lhs, const BASE_STRING_CLASS_EX &rhs)
	{
		return lhs + rhs.var_container;
	}

	friend BASE_STRING_CLASS_EX operator+ (const BASE_STRING_CLASS &lhs, BASE_STRING_CLASS_EX &&rhs)
	{
		return lhs + rhs.var_container;
	}

	friend BASE_STRING_CLASS_EX operator+ (const BASE_STRING_CLASS_EX &lhs, const BASE_STRING_CLASS_EX &rhs)
	{
		return lhs.var_container + rhs.var_container;
	}

	friend BASE_STRING_CLASS_EX operator+ (BASE_STRING_CLASS_EX &&lhs, BASE_STRING_CLASS_EX &&rhs)
	{
		return lhs.var_container + rhs.var_container;
	}

	friend BASE_STRING_CLASS_EX operator+ (BASE_STRING_CLASS_EX &&lhs, const BASE_STRING_CLASS_EX &rhs)
	{
		return lhs.var_container + rhs.var_container;
	}

	friend BASE_STRING_CLASS_EX operator+ (const BASE_STRING_CLASS_EX &lhs, BASE_STRING_CLASS_EX &&rhs)
	{
		return lhs.var_container + rhs.var_container;
	}

	friend BASE_STRING_CLASS_EX operator+ (const BASE_STRING_CLASS_EX &lhs, const BASE_STRING_CHAR_TYPE *rhs)
	{
		return lhs.var_container + rhs;
	}

	friend BASE_STRING_CLASS_EX operator+ (BASE_STRING_CLASS_EX &&lhs, const BASE_STRING_CHAR_TYPE *rhs)
	{
		return lhs.var_container + rhs;
	}

	friend BASE_STRING_CLASS_EX operator+ (const BASE_STRING_CHAR_TYPE *lhs, const BASE_STRING_CLASS_EX &rhs)
	{
		return lhs + rhs.var_container;
	}

	friend BASE_STRING_CLASS_EX operator+ (const BASE_STRING_CHAR_TYPE *lhs, BASE_STRING_CLASS_EX &&rhs)
	{
		return lhs + rhs.var_container;
	}

	friend BASE_STRING_CLASS_EX operator+ (const BASE_STRING_CLASS_EX &lhs, BASE_STRING_CHAR_TYPE rhs)
	{
		return lhs.var_container + rhs;
	}

	friend BASE_STRING_CLASS_EX operator+ (BASE_STRING_CLASS_EX &&lhs, BASE_STRING_CHAR_TYPE rhs)
	{
		return lhs.var_container + rhs;
	}

	friend BASE_STRING_CLASS_EX operator+ (BASE_STRING_CHAR_TYPE lhs, const BASE_STRING_CLASS_EX &rhs)
	{
		return lhs + rhs.var_container;
	}

	friend BASE_STRING_CLASS_EX operator+ (BASE_STRING_CHAR_TYPE lhs, BASE_STRING_CLASS_EX &&rhs)
	{
		return lhs + rhs.var_container;
	}

	//operator compare Overloaded
	friend bool operator== (const BASE_STRING_CLASS_EX& lhs, const BASE_STRING_CLASS_EX& rhs) noexcept
	{
		return lhs.var_container == rhs.var_container;
	}

	friend bool operator== (const BASE_STRING_CLASS& lhs, const BASE_STRING_CLASS_EX& rhs) noexcept
	{
		return lhs == rhs.var_container;
	}

	friend bool operator== (const BASE_STRING_CLASS_EX& lhs, const BASE_STRING_CLASS& rhs) noexcept
	{
		return lhs.var_container == rhs;
	}

	friend bool operator== (const BASE_STRING_CHAR_TYPE* lhs, const BASE_STRING_CLASS_EX& rhs)
	{
		return lhs == rhs.var_container;
	}

	friend bool operator== (const BASE_STRING_CLASS_EX& lhs, const BASE_STRING_CHAR_TYPE* rhs)
	{
		return lhs.var_container == rhs;
	}

	friend bool operator!= (const BASE_STRING_CLASS_EX& lhs, const BASE_STRING_CLASS_EX& rhs) noexcept
	{
		return lhs.var_container != rhs.var_container;
	}

	friend bool operator!= (const BASE_STRING_CLASS& lhs, const BASE_STRING_CLASS_EX& rhs) noexcept
	{
		return lhs != rhs.var_container;
	}

	friend bool operator!= (const BASE_STRING_CLASS_EX& lhs, const BASE_STRING_CLASS& rhs) noexcept
	{
		return lhs.var_container != rhs;
	}

	friend bool operator!= (const BASE_STRING_CHAR_TYPE* lhs, const BASE_STRING_CLASS_EX& rhs)
	{
		return lhs != rhs.var_container;
	}

	friend bool operator!= (const BASE_STRING_CLASS_EX& lhs, const BASE_STRING_CHAR_TYPE* rhs)
	{
		return lhs.var_container != rhs;
	}

	friend bool operator< (const BASE_STRING_CLASS_EX& lhs, const BASE_STRING_CLASS_EX& rhs) noexcept
	{
		return lhs.var_container < rhs.var_container;
	}

	friend bool operator< (const BASE_STRING_CLASS& lhs, const BASE_STRING_CLASS_EX& rhs) noexcept
	{
		return lhs < rhs.var_container;
	}

	friend bool operator< (const BASE_STRING_CLASS_EX& lhs, const BASE_STRING_CLASS& rhs) noexcept
	{
		return lhs.var_container < rhs;
	}

	friend bool operator< (const BASE_STRING_CHAR_TYPE* lhs, const BASE_STRING_CLASS_EX& rhs)
	{
		return lhs < rhs.var_container;
	}

	friend bool operator< (const BASE_STRING_CLASS_EX& lhs, const BASE_STRING_CHAR_TYPE* rhs)
	{
		return lhs.var_container < rhs;
	}

	friend bool operator<= (const BASE_STRING_CLASS_EX& lhs, const BASE_STRING_CLASS_EX& rhs) noexcept
	{
		return lhs.var_container <= rhs.var_container;
	}

	friend bool operator<= (const BASE_STRING_CLASS& lhs, const BASE_STRING_CLASS_EX& rhs) noexcept
	{
		return lhs <= rhs.var_container;
	}

	friend bool operator<= (const BASE_STRING_CLASS_EX& lhs, const BASE_STRING_CLASS& rhs) noexcept
	{
		return lhs.var_container <= rhs;
	}

	friend bool operator<= (const BASE_STRING_CHAR_TYPE* lhs, const BASE_STRING_CLASS_EX& rhs)
	{
		return lhs <= rhs.var_container;
	}

	friend bool operator<= (const BASE_STRING_CLASS_EX& lhs, const BASE_STRING_CHAR_TYPE* rhs)
	{
		return lhs.var_container <= rhs;
	}

	friend bool operator> (const BASE_STRING_CLASS_EX& lhs, const BASE_STRING_CLASS_EX& rhs) noexcept
	{
		return lhs.var_container > rhs.var_container;
	}

	friend bool operator> (const BASE_STRING_CLASS& lhs, const BASE_STRING_CLASS_EX& rhs) noexcept
	{
		return lhs > rhs.var_container;
	}

	friend bool operator> (const BASE_STRING_CLASS_EX& lhs, const BASE_STRING_CLASS& rhs) noexcept
	{
		return lhs.var_container > rhs;
	}

	friend bool operator> (const BASE_STRING_CHAR_TYPE* lhs, const BASE_STRING_CLASS_EX& rhs)
	{
		return lhs > rhs.var_container;
	}

	friend bool operator> (const BASE_STRING_CLASS_EX& lhs, const BASE_STRING_CHAR_TYPE* rhs)
	{
		return lhs.var_container > rhs;
	}

	friend bool operator>= (const BASE_STRING_CLASS_EX& lhs, const BASE_STRING_CLASS_EX& rhs) noexcept
	{
		return lhs.var_container >= rhs.var_container;
	}

	friend bool operator>= (const BASE_STRING_CLASS& lhs, const BASE_STRING_CLASS_EX& rhs) noexcept
	{
		return lhs >= rhs.var_container;
	}

	friend bool operator>= (const BASE_STRING_CLASS_EX& lhs, const BASE_STRING_CLASS& rhs) noexcept
	{
		return lhs.var_container >= rhs;
	}

	friend bool operator>= (const BASE_STRING_CHAR_TYPE* lhs, const BASE_STRING_CLASS_EX& rhs)
	{
		return lhs >= rhs.var_container;
	}

	friend bool operator>= (const BASE_STRING_CLASS_EX& lhs, const BASE_STRING_CHAR_TYPE* rhs)
	{
		return lhs.var_container >= rhs;
	}

	//swap
	friend void swap(BASE_STRING_CLASS_EX& x, BASE_STRING_CLASS_EX& y)
	{
		std::swap(x.var_container, y.var_container);
		return;
	}

	friend void swap(BASE_STRING_CLASS_EX& x, BASE_STRING_CLASS& y)
	{
		std::swap(x.var_container, y);
		return;
	}

	friend void swap(BASE_STRING_CLASS& x, BASE_STRING_CLASS_EX& y)
	{
		std::swap(x, y.var_container);
		return;
	}

	/*
	//u32string类型本身没有流方面的重载
	//iostream
	friend std::istream& operator>> (std::istream& is, BASE_STRING_CLASS_EX& str)
	{
		is >> str.var_container;
		return is;
	}

	friend std::ostream& operator<< (std::ostream& os, const BASE_STRING_CLASS_EX& str)
	{
		os << str.var_container;
		return os;
	}
	*/

	//extend string
	size_type len() const noexcept
	{
		return var_container.size();
	}

	size_type size_bytes() const noexcept
	{
		return var_container.size() * sizeof(BASE_STRING_CHAR_TYPE);
	}

	size_type length_bytes() const noexcept
	{
		return var_container.length() * sizeof(BASE_STRING_CHAR_TYPE);
	}

	//same as copy.
	size_t copy_to(BASE_STRING_CHAR_TYPE *s, size_t len, size_t pos = 0) const
	{
		return var_container.copy(s, len, pos);
	}

	BASE_STRING_CLASS_EX &append(BASE_STRING_CHAR_TYPE c)
	{
		var_container.push_back(c);
		return *this;
	}

	BASE_STRING_CHAR_TYPE *c_dup() const
	{
		size_t n_copy_array_len = var_container.size();
		size_t n_new_array_len = n_copy_array_len + 1;
		BASE_STRING_CHAR_TYPE *sz_ret = (BASE_STRING_CHAR_TYPE *)new BASE_STRING_CHAR_TYPE[n_new_array_len];
		size_t n_copybytes = var_container.size() * sizeof(BASE_STRING_CHAR_TYPE);
		const BASE_STRING_CHAR_TYPE *sz_copy = var_container.c_str();
		memcpy(sz_ret, sz_copy, n_copybytes);
		sz_ret[n_copy_array_len] = 0;
		return sz_ret;
	}

	//将所有old_str替换为new_str
	BASE_STRING_CLASS_EX& replace(const BASE_STRING_CLASS_EX& old_str, const BASE_STRING_CLASS_EX& new_str)
	{
		if (old_str.empty())
			return *this;
		size_t index;
		while ((index = var_container.find(old_str.var_container)) != npos)
		{
			var_container.replace(
				index,
				old_str.var_container.size(),
				new_str.var_container
			);
		}
		return *this;
	}

	//将所有old_str替换为new_str
	BASE_STRING_CLASS& replace(const BASE_STRING_CLASS& old_str, const BASE_STRING_CLASS& new_str)
	{
		if (old_str.empty())
			return *this;
		size_t index;
		while ((index = var_container.find(old_str)) != npos)
		{
			var_container.replace(index, old_str.size(), new_str);
		}
		return *this;
	}

	void tolower_modify()
	{
		const size_t n_strlen = var_container.size();
		for (size_t i = 0; i < n_strlen; i++)
		{
			BASE_STRING_CHAR_TYPE &ch = var_container.at(i);
			ch = std::tolower(ch);
		}
	}

	void toupper_modify()
	{
		const size_t n_strlen = var_container.size();
		for (size_t i = 0; i < n_strlen; i++)
		{
			BASE_STRING_CHAR_TYPE &ch = var_container.at(i);
			ch = std::toupper(ch);
		}
	}

	BASE_STRING_CLASS_EX tolower() const
	{
		BASE_STRING_CLASS_EX str_ret(var_container);
		const size_t n_strlen = size();
		for (size_t i = 0; i < n_strlen; i++)
		{
			BASE_STRING_CHAR_TYPE &ch = str_ret.at(i);
			ch = std::tolower(ch);
		}
	}

	BASE_STRING_CLASS_EX toupper() const
	{
		BASE_STRING_CLASS_EX str_ret(var_container);
		const size_t n_strlen = size();
		for (size_t i = 0; i < n_strlen; i++)
		{
			BASE_STRING_CHAR_TYPE &ch = str_ret.at(i);
			ch = std::toupper(ch);
		}
	}
	//py系列函数
	//切片方法
	BASE_STRING_CLASS_EX py_slice(int_max_t start, int_max_t end = MAX_INT_MAX_T) const
	{
		return pystring_function::slice(var_container, start, end);
	}

	//返回一个首字母大写其他小写的字符串
	//"this IS string" -> "This is string"
	BASE_STRING_CLASS_EX py_capitalize() const
	{
		return pystring_function::capitalize(var_container);
	}

	//返回一个原字符串居中的新字符串,并使用fillchar(默认空格)填充至长度 width 的新字符串
	//"This is Test." -> "FFFThis is Test.FFFF"
	BASE_STRING_CLASS_EX py_center(size_t width, const BASE_STRING_CHAR_TYPE fillchar = ' ')const
	{
		return pystring_function::center(var_container, width, fillchar);
	}

	//返回字符串中指定字符或者字符串的数目。
	//"this is string" -> "is" -> ret 2
	int_max_t py_count(const BASE_STRING_CLASS &substr,int_max_t start = 0, int_max_t end = MAX_INT_MAX_T) const
	{
		return pystring_function::count(var_container, substr, start, end);
	}

	//判断字符串开头是否等于suffix
	bool py_startswith(const BASE_STRING_CLASS &suffix, int_max_t start = 0, int_max_t end = MAX_INT_MAX_T) const
	{
		return pystring_function::startswith(var_container, suffix, start, end);
	}

	//判断字符串结尾是否等于suffix
	bool py_endswith(const BASE_STRING_CLASS &suffix, int_max_t start = 0, int_max_t end = MAX_INT_MAX_T) const
	{
		return pystring_function::endswith(var_container, suffix, start, end);
	}

	//扩展/t为空格（默认为8个）并保持行末尾对齐
	BASE_STRING_CLASS_EX py_expandtabs(int tabsize = 8) const
	{
		return pystring_function::expandtabs(var_container, tabsize);
	}

	//find() 方法检测字符串中是否包含子字符串 substr
	//如果指定 beg（开始） 和 end（结束） 范围，则检查是否包含在指定范围内
	//如果包含子字符串返回开始的索引值，否则返回 - 1
	int_max_t py_find(const BASE_STRING_CLASS &substr, int_max_t start = 0, int_max_t end = MAX_INT_MAX_T) const
	{
		return pystring_function::find(var_container, substr, start, end);
	}

	//rfind() 方法从右边开始检测字符串中是否包含子字符串 substr
	//如果指定 beg（开始） 和 end（结束） 范围，则检查是否包含在指定范围内
	//如果包含子字符串返回开始的索引值，否则返回 - 1
	int_max_t py_rfind(const BASE_STRING_CLASS &substr, int_max_t start = 0, int_max_t end = MAX_INT_MAX_T) const
	{
		return pystring_function::rfind(var_container, substr, start, end);
	}

	//index() 方法检测字符串中是否包含子字符串 substr
	//如果指定 beg（开始） 和 end（结束） 范围，则检查是否包含在指定范围内
	//如果包含子字符串返回开始的索引值，否则返回 - 1
	int_max_t py_index(const BASE_STRING_CLASS &substr, int_max_t start = 0, int_max_t end = MAX_INT_MAX_T)
	{
		return pystring_function::index(var_container, substr, start, end);
	}

	//rindex() 方法从右边开始检测字符串中是否包含子字符串 substr
	//如果指定 beg（开始） 和 end（结束） 范围，则检查是否包含在指定范围内
	//如果包含子字符串返回开始的索引值，否则返回 - 1
	int_max_t py_rindex(const BASE_STRING_CLASS &substr, int_max_t start = 0, int_max_t end = MAX_INT_MAX_T)
	{
		return pystring_function::rindex(var_container, substr, start, end);
	}

	//如果string至少有一个字符并且所有字符都是字母或数字则返回 true, 否则返回 false
	// "a1"   -> true
	// "a1\n" -> false
	bool py_isalnum() const
	{
		return pystring_function::isalnum(var_container);
	}

	//如果string至少有一个字符并且所有字符都是字母则返回 true, 否则返回 false
	// "a1\n" -> false
	// "abc" -> true
	bool py_isalpha() const
	{
		return pystring_function::isalpha(var_container);
	}

	//如果string至少有一个字符并且所有字符都是数字则返回 true, 否则返回 false
	// "-10" -> false
	// "10" -> true
	bool py_isdigit() const
	{
		return pystring_function::isdigit(var_container);
	}

	//如果string中包含至少一个字母，并且所有字符都是小写，则返回 true，否则返回 false
	//"abc123.0" -> true
	//"A1" -> false
	//"11" -> false
	bool py_islower() const
	{
		return pystring_function::isdigit(var_container);
	}

	//如果string至少有一个字符并且所有字符都是空格（包括\r\n\t\f\v）则返回 true, 否则返回 false
	bool py_isspace() const
	{
		return pystring_function::isspace(var_container);
	}

	//检测字符串中所有的单词拼写首字母是否为大写，且其他字母为小写
	//"this is" -> false
	//"This Is" -> true
	bool py_istitle() const
	{
		return pystring_function::istitle(var_container);
	}

	//如果string中包含至少一个字母，并且所有字符都是大写，则返回 true，否则返回 false
	//"ABC123.0" -> true
	//"a1" -> false
	//"11" -> false
	bool py_isupper() const
	{
		return pystring_function::isupper(var_container);
	}

	//将序列中的元素以指定的字符连接生成一个新的字符串。
	BASE_STRING_CLASS_EX py_join(const BASE_STRING_CLASS &str,std::vector<BASE_STRING_CLASS> &seq) const
	{
		return pystring_algorithm::join(str, seq);
	}

	//将序列中的元素以指定的字符连接生成一个新的字符串。
	BASE_STRING_CLASS_EX py_join(std::vector<BASE_STRING_CLASS> &seq) const
	{
		return pystring_algorithm::join(var_container, seq);
	}

	//将序列中的元素以指定的字符连接生成一个新的字符串。
	BASE_STRING_CLASS_EX py_join(const BASE_STRING_CLASS &str,
		std::vector<BASE_STRING_CLASS_EX> &seq) const
	{
		BASE_STRING_CLASS_EX pystr_ret;
		pystring_algorithm::join(str, seq, pystr_ret);
		return pystr_ret;
	}

	//将序列中的元素以指定的字符连接生成一个新的字符串。
	BASE_STRING_CLASS_EX py_join(std::vector<BASE_STRING_CLASS_EX> &seq) const
	{
		BASE_STRING_CLASS_EX pystr_ret;
		pystring_algorithm::join(var_container, seq, pystr_ret);
		return pystr_ret;
	}

	//返回一个原字符串左对齐,并使用空格填充至长度 width 的新字符串
	BASE_STRING_CLASS_EX py_ljust(int_max_t width,BASE_STRING_CHAR_TYPE fillchar = ' ') const
	{
		return pystring_function::ljust(var_container, width, fillchar);
	}

	//返回一个原字符串右对齐,并使用空格填充至长度 width 的新字符串
	BASE_STRING_CLASS_EX py_rjust(int_max_t width,BASE_STRING_CHAR_TYPE fillchar = ' ') const
	{
		return pystring_function::rjust(var_container, width, fillchar);
	}

	//转换所有字符为小写
	BASE_STRING_CLASS_EX py_lower() const
	{
		return pystring_function::lower(var_container);
	}

	//转换所有字符为大写
	BASE_STRING_CLASS_EX py_upper() const
	{
		return pystring_function::upper(var_container);
	}

	//lstrip() 方法用于截掉字符串左边的空格(包括\t\r\n)或指定字符。
	BASE_STRING_CLASS_EX py_lstrip(const BASE_STRING_CLASS &chars = BASE_STRING_CLASS()) const
	{
		return pystring_function::lstrip(var_container, chars);
	}

	//rstrip() 方法用于截掉字符串左边的空格(包括\t\r\n)或指定字符。
	BASE_STRING_CLASS_EX py_rstrip(const BASE_STRING_CLASS &chars = BASE_STRING_CLASS()) const
	{
		return pystring_function::rstrip(var_container, chars);
	}

	//返回一个3元的元组，第一个为分隔符左边的子串，第二个为分隔符本身，第三个为分隔符右边的子串。
//"https://baidu.com" -> ('https', '://', 'baidu.com')
	std::vector<BASE_STRING_CLASS_EX> py_partition(const BASE_STRING_CLASS &sep)
		const
	{
		std::vector<BASE_STRING_CLASS_EX> vec_ret;
		pystring_algorithm::partition(vec_ret, var_container, sep);
		return vec_ret;
	}

	//从右边开始返回一个3元的元组，第一个为分隔符左边的子串，第二个为分隔符本身，第三个为分隔符右边的子串。
	//"https://baidu.com" -> ('https', '://', 'baidu.com')
	std::vector<BASE_STRING_CLASS_EX> py_rpartition(const BASE_STRING_CLASS &sep)
		const
	{
		std::vector<BASE_STRING_CLASS_EX> vec_ret;
		pystring_algorithm::rpartition(vec_ret, var_container, sep);
		return vec_ret;
	}

	//把 string 中的 str1 替换成 str2, 如果 count 指定，则替换不超过 count 次.
	BASE_STRING_CLASS_EX py_replace(const BASE_STRING_CLASS &oldstr,
		const BASE_STRING_CLASS &newstr, int_max_t count = MAX_INT_MAX_T) const
	{
		return pystring_function::replace(var_container, oldstr, newstr, count);
	}

	//strip() 方法用于截掉字符串两边的空格(包括\t\r\n)或指定字符。
	BASE_STRING_CLASS_EX py_strip(const BASE_STRING_CLASS &chars = BASE_STRING_CLASS()) const
	{
		return pystring_function::strip(var_container, chars);
	}

	//字符串从右分割
	std::vector<BASE_STRING_CLASS_EX> py_rsplit(const BASE_STRING_CLASS &chars
		, int_max_t maxsplit = MAX_INT_MAX_T) const
	{
		std::vector<BASE_STRING_CLASS_EX> vec_tmp;
		pystring_algorithm::rsplit(vec_tmp, var_container, chars, maxsplit);
		return vec_tmp;
	}

	//字符串分割
	std::vector<BASE_STRING_CLASS_EX> py_split(const BASE_STRING_CLASS &chars
		, int_max_t maxsplit = MAX_INT_MAX_T) const
	{
		std::vector<BASE_STRING_CLASS_EX> vec_tmp;
		pystring_algorithm::split(vec_tmp, var_container, chars, maxsplit);
		return vec_tmp;
	}

	//字符串大小写翻转
	BASE_STRING_CLASS_EX py_swapcase() const
	{
		return pystring_function::swapcase(var_container);
	}

	//返回"标题化"的 string,就是说所有单词都是以大写开始，其余字母均为小写
	//"This is.no 123" -> "This Is.No 123"
	BASE_STRING_CLASS_EX py_title() const
	{
		return pystring_function::title(var_container);
	}

	//用于字符映射的转换
	//参数1是被转换的字符串，第2个参数是字符串，表示需要转换的字符，第3个参数是字符串表示转换的目标。
	//两个字符串的长度必须相同，为一一对应的关系。
	//BASE_STRING_CLASS_EX translate("abbc","bc","de") -> "adde"
	BASE_STRING_CLASS_EX py_translate(const BASE_STRING_CLASS &intab,
		const BASE_STRING_CLASS &outtab) const
	{
		return pystring_function::translate(var_container, intab, outtab);
	}

	//从左边开始使用字符0填充至指定长度，返回新字符串使原字符串右对齐。
	//zfill("test",10); -> "000000test"
	BASE_STRING_CLASS_EX py_zfill(size_t width) const
	{
		return pystring_function::zfill(var_container, width);
	}

	bool py_get_middle_of_pos(const BASE_STRING_CLASS &str_start,
		const BASE_STRING_CLASS &str_end,
		size_t &n_start,
		size_t &n_copylen) const
	{
		return pystring_function::get_middle_of_pos(var_container,
			str_start,
			str_end,
			n_start,
			n_copylen);
	}

	//取字符串中两个字符串之间的字符串
	BASE_STRING_CLASS_EX py_get_middle_of(const BASE_STRING_CLASS &str_start,
		const BASE_STRING_CLASS &str_end = BASE_STRING_CLASS()) const
	{
		return pystring_function::get_middle_of(var_container, str_start, str_end);
	}

	//删除字符串中两个字符串中间的字符串
	BASE_STRING_CLASS_EX py_delete_middle_of(const BASE_STRING_CLASS& str_start_flag,
		const BASE_STRING_CLASS& str_end_flag,
		int_max_t n_count = MAX_INT_MAX_T
	) const
	{
		return pystring_function::delete_middle_of(var_container, str_start_flag, str_end_flag, n_count);
	}

	//截断字符串
	BASE_STRING_CLASS_EX py_truncate(const BASE_STRING_CLASS &str_truncate)
	{
		return pystring_function::truncate(var_container, str_truncate);
	}

	//截断字符串中标志的任意字符
	BASE_STRING_CLASS_EX py_truncate_char(const BASE_STRING_CLASS &str_truncate)
	{
		return pystring_function::truncate_char(var_container, str_truncate);
	}

	//format
	BASE_STRING_CLASS_EX argv(const BASE_STRING_CLASS &str_input)
	{
		string_format::format_argv(var_container, str_input);
		return *this;
	}

	BASE_STRING_CLASS_EX argv(const int n_input)
	{
		string_format::format_argv(var_container, n_input);
		return *this;
	}

	BASE_STRING_CLASS_EX argv(const long double f_input,int n_decimal_digits = 2)
	{
		string_format::format_argv(var_container, f_input);
		return *this;
	}

	//数据类型转换模板

	int to_int() const
	{
        return (int)(convert_type::to_int_type(var_container));
	}

    int_max_t to_int_max_t() const
	{
        return (int_max_t)(convert_type::to_int_type(var_container));
	}

	float to_float() const
	{
        return (float)(convert_type::to_float_type(var_container));
	}

	double to_double() const
	{
        return (double)(convert_type::to_float_type(var_container));
	}

    double to_long_double() const
	{
        return (long double)(convert_type::to_float_type(var_container));
	}

	BASE_STRING_CLASS_EX from_int(int n_input)
	{
        var_container = convert_type::int_to_string(n_input);
        return *this;
	}

    BASE_STRING_CLASS_EX from_int_max_t(int_max_t n_input)
	{
        var_container = convert_type::int_to_string(n_input);
        return *this;
	}

    BASE_STRING_CLASS_EX from_float(float n_input,int n_decimal_digits = 2)
	{
        var_container = convert_type::float_to_string(n_input,n_decimal_digits);
        return *this;
	}

    BASE_STRING_CLASS_EX from_double(double n_input,int n_decimal_digits = 2)
	{
        var_container = convert_type::float_to_string(n_input,n_decimal_digits);
        return *this;
	}

    BASE_STRING_CLASS_EX from_long_double(long double n_input,int n_decimal_digits = 2)
	{
        var_container = convert_type::float_to_string(n_input,n_decimal_digits);
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

    static BASE_STRING_CLASS_EX to_pystring(float n_input,int n_decimal_digits = 2)
	{
        return convert_type::float_to_string(n_input,n_decimal_digits);
	}

    static BASE_STRING_CLASS_EX to_pystring(double n_input,int n_decimal_digits = 2)
	{
        return convert_type::float_to_string(n_input,n_decimal_digits);
	}

    static BASE_STRING_CLASS_EX to_pystring(long double n_input,int n_decimal_digits = 2)
	{
        return convert_type::float_to_string(n_input,n_decimal_digits);
	}

	//类型转换模板
	operator BASE_STRING_CLASS&()
	{
		return var_container;
	}

	operator const BASE_STRING_CLASS&() const
	{
		return var_container;
	}

	BASE_STRING_CLASS& to_basic_type()
	{
		return var_container;
	}

	const BASE_STRING_CLASS& to_basic_type() const
	{
		return var_container;
	}

	BASE_STRING_CLASS to_basic_type_copy() const
	{
		return var_container;
	}

protected:
	BASE_STRING_CLASS var_container;
};

typedef BASE_STRING_CLASS_EX<char32_t> std_u32string_proxy;
typedef BASE_STRING_CLASS_EX<char16_t> std_u16string_proxy;
typedef BASE_STRING_CLASS_EX<char> std_string_proxy;
#endif //__PYTHON_STRING_BASE_CLASS_TEMPLATE_H__
