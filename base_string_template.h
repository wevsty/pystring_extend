#if defined(_MSC_VER)
#pragma once
#endif

//定义公共定义
#ifndef __PYTHON_STRING_BASE_CLASS_TEMPLATE_H__
#define __PYTHON_STRING_BASE_CLASS_TEMPLATE_H__

#include <initializer_list>
#include <utility> //std::swap
#include <iostream> //ostream
#include <memory>
#include <string>
template <typename BASE_STRING_CLASS, typename BASE_STRING_CHAR_TYPE>
class BASE_STRING_CLASS_EX
{
public:
	//
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
		const size_t n_strlen = size();
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

	//类型转换模板
	operator BASE_STRING_CLASS&()
	{
		return var_container;
	}

	operator const BASE_STRING_CLASS&() const
	{
		return var_container;
	}

protected:
	BASE_STRING_CLASS var_container;
};

typedef BASE_STRING_CLASS_EX<std::u32string, char32_t> u32string_proxy;
typedef BASE_STRING_CLASS_EX<std::string, char> std_string_proxy;
#endif //__PYTHON_STRING_BASE_CLASS_TEMPLATE_H__
