#include "pystring_function.h"
#include "pystring_utf32_function.h"
#include "pystring_class.h"

#include <iostream>
//#include <string>
#include <stdexcept>
#include "data_conv.h"
#include <windows.h>
#include "base_string_template.h"
//
//#pragma comment(lib, "pystring_extend.lib")
///*
//测试模板
template <typename T1, typename T2>
void check_equal(T1 chk1, T2 chk2)
{
	if (chk1 != chk2)
	{
		throw std::runtime_error("Exceptional results");
	}
}

bool test_pystring()
{
	//切片 slice
	check_equal(pystring_function::slice(""), "");
	check_equal(pystring_function::slice("", 1), "");
	check_equal(pystring_function::slice("", -1), "");
	check_equal(pystring_function::slice("", -1, 2), "");
	check_equal(pystring_function::slice("abcdef"), "abcdef");
	check_equal(pystring_function::slice("abcdef", 0), "abcdef");
	check_equal(pystring_function::slice("abcdef", 1), "bcdef");
	check_equal(pystring_function::slice("abcdef", 2), "cdef");
	check_equal(pystring_function::slice("abcdef", 2, 2), "");
	check_equal(pystring_function::slice("abcdef", 2, 3), "c");
	check_equal(pystring_function::slice("abcdef", 2, 1), "");
	check_equal(pystring_function::slice("abcdef", 2, -1), "cde");
	check_equal(pystring_function::slice("abcdef", 2, -2), "cd");
	check_equal(pystring_function::slice("abcdef", 2, -3), "c");
	check_equal(pystring_function::slice("abcdef", 2, -4), "");
	check_equal(pystring_function::slice("abcdef", 2, -5), "");
	check_equal(pystring_function::slice("abcdef", -1), "f");
	check_equal(pystring_function::slice("abcdef", -2), "ef");
	check_equal(pystring_function::slice("abcdef", -99), "abcdef");
	check_equal(pystring_function::slice("abcdef", -99, -98), "");
	check_equal(pystring_function::slice("abcdef", -2, 3), "");
	check_equal(pystring_function::slice("abcdef", -2, 10), "ef");
	check_equal(pystring_function::slice("abcdef", -1), "f");
	check_equal(pystring_function::slice("abcdef", 0, -1), "abcde");
	check_equal(pystring_function::slice("string", -3, -1), "in");
	//
	//find()
	check_equal(pystring_function::find("", ""), 0);
	check_equal(pystring_function::find("", "a"), -1);
	check_equal(pystring_function::find("a", ""), 0);
	check_equal(pystring_function::find("a", "a"), 0);
	check_equal(pystring_function::find("abcdef", ""), 0);
	check_equal(pystring_function::find("abcdef", "", -1), 5);
	check_equal(pystring_function::find("abcdef", "", -2), 4);
	check_equal(pystring_function::find("abcdef", "", -5), 1);
	check_equal(pystring_function::find("abcdef", "", -6), 0);
	check_equal(pystring_function::find("abcdef", "", -7), 0);
	check_equal(pystring_function::find("abcdef", "def"), 3);
	check_equal(pystring_function::find("abcdef", "def", 3), 3);
	check_equal(pystring_function::find("abcdef", "def", 4), -1);
	check_equal(pystring_function::find("abcdef", "def", -5), 3);
	check_equal(pystring_function::find("abcdef", "def", -1), -1);
	check_equal(pystring_function::find("abcabcabc", "bc", -2), 7);
	check_equal(pystring_function::find("abcabcabc", "bc", -1), -1);
	check_equal(pystring_function::find("abcabcabc", "bc", 0), 1);
	check_equal(pystring_function::find("abcabcabc", "bc", 1), 1);
	check_equal(pystring_function::find("abcabcabc", "bc", 2), 4);
	check_equal(pystring_function::find("abcabcabc", "bc", 4), 4);
	check_equal(pystring_function::find("abcabcabc", "bc", 7), 7);
	check_equal(pystring_function::find("abcabcabc", "bc", 4, 3), -1);
	check_equal(pystring_function::find("abcabcabc", "bc", 4, 4), -1);
	check_equal(pystring_function::find("abcabcabc", "bc", 4, 5), -1);
	check_equal(pystring_function::find("abcabcabc", "bc", 4, -1), 4);
	check_equal(pystring_function::find("abcabcabc", "bc", 4, 6), 4);
	check_equal(pystring_function::find("abcabcabc", "bc", 0, 0), -1);
	check_equal(pystring_function::find("abcabcabc", "", 0, 0), 0);
	check_equal(pystring_function::find("abcabcabc", "", 1, 0), -1);
	//rfind()
	check_equal(pystring_function::rfind("", ""), 0);
	check_equal(pystring_function::rfind("", "a"), -1);
	check_equal(pystring_function::rfind("a", ""), 1);
	check_equal(pystring_function::rfind("a", "a"), 0);
	check_equal(pystring_function::rfind("abcdef", ""), 6);
	check_equal(pystring_function::rfind("abcdef", "", 0, 1), 1);
	check_equal(pystring_function::rfind("abcdef", "", 0, 5), 5);
	check_equal(pystring_function::rfind("abcdef", "", 0, -1), 5);
	check_equal(pystring_function::rfind("abcdef", "", 0, -3), 3);
	check_equal(pystring_function::rfind("abcdef", "def"), 3);
	check_equal(pystring_function::rfind("abcdef", "def", 3), 3);
	check_equal(pystring_function::rfind("abcdef", "def", 4), -1);
	check_equal(pystring_function::rfind("abcdef", "def", -5), 3);
	check_equal(pystring_function::rfind("abcdef", "def", -1), -1);
	check_equal(pystring_function::rfind("abcabcabc", "bc", -2), 7);
	check_equal(pystring_function::rfind("abcabcabc", "bc", -1), -1);
	check_equal(pystring_function::rfind("abcabcabc", "bc", 0), 7);
	check_equal(pystring_function::rfind("abcabcabc", "bc", 1), 7);
	check_equal(pystring_function::rfind("abcabcabc", "bc", 4), 7);
	check_equal(pystring_function::rfind("abcabcabc", "bc", 7), 7);
	check_equal(pystring_function::rfind("abcabcabc", "bc", 4, -5), -1);
	check_equal(pystring_function::rfind("abcabcabc", "bc", 4, -10), -1);
	check_equal(pystring_function::rfind("abcabcabc", "bc", 4, 20), 7);
	check_equal(pystring_function::rfind("abcabcabc", "abc", 6, 8), -1);
	//replace
	check_equal(pystring_function::replace("abcdef", "foo", "bar"), "abcdef");
	check_equal(pystring_function::replace("abcdef", "ab", "cd"), "cdcdef");
	check_equal(pystring_function::replace("abcdef", "ab", ""), "cdef");
	check_equal(pystring_function::replace("abcabc", "ab", ""), "cc");
	check_equal(pystring_function::replace("abcdef", "", ""), "abcdef");
	check_equal(pystring_function::replace("abcdef", "", "."), ".a.b.c.d.e.f.");
	//join
	std::vector<std::string> vec_join{ "a", "b", "c", "d" };
	check_equal(pystring_function::join("-", vec_join), "a-b-c-d");
	vec_join.clear();
	vec_join.push_back("a");
	check_equal(pystring_function::join("-", vec_join), "a");
	vec_join.clear();
	check_equal(pystring_function::join("-", vec_join), "");
	//capitalize()
	check_equal(pystring_function::capitalize("this IS time test."), "This is time test.");
	//center()
	check_equal(pystring_function::center("this", 11, '-'), "----this---");
	check_equal(pystring_function::center("hello", 20, '-'), "-------hello--------");
	//count()
	check_equal(pystring_function::count("this is string", "is"), 2);
	//endswith()
	check_equal(pystring_function::endswith("test.exe", "exe"), true);
	check_equal(pystring_function::endswith("test.exe", "exe", 1, 4), false);
	check_equal(pystring_function::endswith("", ""), true);
	check_equal(pystring_function::endswith("", "a"), false);
	check_equal(pystring_function::endswith("a", ""), true);
	check_equal(pystring_function::endswith("", ".mesh"), false);
	check_equal(pystring_function::endswith("help", ".mesh"), false);
	check_equal(pystring_function::endswith("help", ".mesh", 0), false);
	check_equal(pystring_function::endswith("help", ".mesh", 1), false);
	check_equal(pystring_function::endswith("help", ".mesh", 1, 2), false);
	check_equal(pystring_function::endswith("help", ".mesh", 1, 1), false);
	check_equal(pystring_function::endswith("help", ".mesh", 1, -1), false);
	check_equal(pystring_function::endswith("help", ".mesh", -1), false);
	check_equal(pystring_function::endswith(".mesh", ".mesh"), true);
	check_equal(pystring_function::endswith("a.mesh", ".mesh"), true);
	check_equal(pystring_function::endswith("a.", "."), true);
	check_equal(pystring_function::endswith("abcdef", "ef"), true);
	check_equal(pystring_function::endswith("abcdef", "cdef"), true);
	check_equal(pystring_function::endswith("abcdef", "cdef", 2), true);
	check_equal(pystring_function::endswith("abcdef", "cdef", 3), false);
	check_equal(pystring_function::endswith("abcdef", "cdef", 2, 3), false);
	check_equal(pystring_function::endswith("abcdef", "cdef", -10), true);
	//startswith
	check_equal(pystring_function::startswith("", ""), true);
	check_equal(pystring_function::startswith("", "a"), false);
	check_equal(pystring_function::startswith("a", ""), true);
	check_equal(pystring_function::startswith("abc", "ab"), true);
	check_equal(pystring_function::startswith("abc", "abc"), true);
	check_equal(pystring_function::startswith("abc", "abcd"), false);
	check_equal(pystring_function::startswith("abcdef", "abc"), true);
	check_equal(pystring_function::startswith("abcdef", "abc", 1), false);
	check_equal(pystring_function::startswith("abcdef", "bc", 1), true);
	//expandtabs
	check_equal(pystring_function::expandtabs("\thello\t\r\n", 4), "    hello   \r\n");
	check_equal(pystring_function::expandtabs("hel\tlo\t\r\n", 8), "hel     lo      \r\n");
	//isalnum
	check_equal(pystring_function::isalnum("a1"), true);
	check_equal(pystring_function::isalnum("a1\n"), false);
	check_equal(pystring_function::isalnum(""), false);
	//isalpha
	check_equal(pystring_function::isalpha("aabc"), true);
	check_equal(pystring_function::isalpha("a12\n"), false);
	check_equal(pystring_function::isalpha(""), false);
	//isdigit
	check_equal(pystring_function::isdigit("11"), true);
	check_equal(pystring_function::isdigit("-11"), false);
	check_equal(pystring_function::isdigit(""), false);
	//islower
	check_equal(pystring_function::islower(""), false);
	check_equal(pystring_function::islower("11"), false);
	check_equal(pystring_function::islower("a11"), true);
	//check_equal(pystring_function::islower_s("a11"), true);
	//isupper
	check_equal(pystring_function::isupper(""), false);
	check_equal(pystring_function::isupper("11"), false);
	check_equal(pystring_function::isupper("a11"), false);
	check_equal(pystring_function::isupper("A11"), true);
	//isspace
	check_equal(pystring_function::isspace(" \r\n\t\f\v"), true);
	check_equal(pystring_function::isspace(" a \r\n\t\f\v"), false);
	check_equal(pystring_function::isspace(""), false);
	//istitle
	check_equal(pystring_function::istitle(""), false);
	check_equal(pystring_function::istitle("This 1 Is Str1In\nG"), true);
	check_equal(pystring_function::istitle("this"), false);
	//title
	check_equal(pystring_function::title(""), "");
	check_equal(pystring_function::title("this 1 is str1in\ng"), "This 1 Is Str1In\nG");
	check_equal(pystring_function::title("this"), "This");
	//lower
	check_equal(pystring_function::lower("ThIs"), "this");
	//upper
	check_equal(pystring_function::upper("ThIs"), "THIS");
	//zfill
	check_equal(pystring_function::zfill("-0.01", 6), "-00.01");
	check_equal(pystring_function::zfill("+0.01", 6), "+00.01");
	//strip
	check_equal(pystring_function::strip("abccab", "ab"), "cc");
	check_equal(pystring_function::strip(""), "");
	check_equal(pystring_function::strip("a"), "a");
	check_equal(pystring_function::strip("a "), "a");
	check_equal(pystring_function::strip(" a"), "a");
	check_equal(pystring_function::strip("\n a "), "a");
	check_equal(pystring_function::strip("\r\n a \r\n"), "a");
	check_equal(pystring_function::strip("\r\n a \r\n\t"), "a");
	//lstrip
	check_equal(pystring_function::lstrip(""), "");
	check_equal(pystring_function::lstrip("a"), "a");
	check_equal(pystring_function::lstrip("a "), "a ");
	check_equal(pystring_function::lstrip(" a"), "a");
	//rstrip
	check_equal(pystring_function::rstrip(""), "");
	check_equal(pystring_function::rstrip("a"), "a");
	check_equal(pystring_function::rstrip("a "), "a");
	check_equal(pystring_function::rstrip(" a"), " a");
	//splitlines
	std::vector<std::string> vec_line;
	check_equal(pystring_function::splitlines("1\n2\n3\n", false), std::vector<std::string> {"1", "2", "3"});
	check_equal(pystring_function::splitlines("1\n2\n3\n", true), std::vector<std::string> { "1\n", "2\n", "3\n" });
	check_equal(pystring_function::splitlines("1\r\n2\r\n3\r\n", false),
		std::vector<std::string> {"1", "2", "3"});
	check_equal(pystring_function::splitlines("1\r\n2\r\n3\r\n", true),
		std::vector<std::string> { "1\r\n", "2\r\n", "3\r\n" });
	check_equal(pystring_function::splitlines("\r1\r2\r3", false), std::vector<std::string> {"", "1", "2", "3"});
	check_equal(pystring_function::splitlines("\r1\r2\r3\r", true), std::vector<std::string> { "\r", "1\r", "2\r", "3\r" });
	//split
	check_equal(pystring_function::split("a,,b,,c", ",,"), std::vector<std::string> {"a", "b", "c"});
	check_equal(pystring_function::split("\nab c\r"), std::vector<std::string> {"ab", "c"});
	check_equal(pystring_function::split("", "/", 1), std::vector<std::string> {""});
	check_equal(pystring_function::split(" ", " ", 1), std::vector<std::string> {"", ""});
	check_equal(pystring_function::split("a  ", " ", 1), std::vector<std::string> {"a", " "});
	check_equal(pystring_function::split("/", "/", 1), std::vector<std::string> {"", ""});
	check_equal(pystring_function::split(" /", "/", 1), std::vector<std::string> {" ", ""});
	check_equal(pystring_function::split(" //", "/", 1), std::vector<std::string> {" ", "/"});
	check_equal(pystring_function::split("//as//rew//gdf", "//"), std::vector<std::string> {"", "as", "rew", "gdf"});
	check_equal(pystring_function::split("/root/world", "/", 0), std::vector<std::string> {"/root/world"});
	check_equal(pystring_function::split("/root/world", "/", 1), std::vector<std::string> {"", "root/world"});
	check_equal(pystring_function::split("/root/world", "/", 2), std::vector<std::string> {"", "root", "world"});
	check_equal(pystring_function::split("/root/world", "/", -1), std::vector<std::string> {"", "root", "world"});
	//rsplit
	// "".rsplit(None, 1)
	check_equal(pystring_function::split("", "/", 1), std::vector<std::string> {""});
	// " ".rsplit(None, 1)
	check_equal(pystring_function::rsplit(" ", "", 1).size(), 0);
	check_equal(pystring_function::rsplit("  ", "", 1).size(), 0);
	check_equal(pystring_function::rsplit(" /", "/", 1), std::vector<std::string> {" ", ""});
	check_equal(pystring_function::rsplit(" //", "/", 1), std::vector<std::string> {" /", ""});
	check_equal(pystring_function::rsplit("/root", "/", 1), std::vector<std::string> {"", "root"});
	check_equal(pystring_function::rsplit("/root", "/", 0), std::vector<std::string> {"/root"});
	check_equal(pystring_function::rsplit("/root/world", "/", 1), std::vector<std::string> {"/root", "world"});
	check_equal(pystring_function::rsplit("/root/world", "/", 2), std::vector<std::string> {"", "root", "world"});
	check_equal(pystring_function::rsplit("/root/world", "/", -1), std::vector<std::string> {"", "root", "world"});
	// " root world".rsplit(None, 0)
	check_equal(pystring_function::rsplit(" root world"), std::vector<std::string> {"root", "world"});
	check_equal(pystring_function::rsplit(" root world", " ", 0), std::vector<std::string> {" root world"});
	check_equal(pystring_function::rsplit(" root world", " ", 1), std::vector<std::string> {" root", "world"});
	check_equal(pystring_function::rsplit(" root world", " ", 2), std::vector<std::string> {"", "root", "world"});
	//format
	check_equal(pystring_function::format("{} + {} = {}", std::vector<std::string>{"1", "2", "3"}), "1 + 2 = 3");
	check_equal(pystring_function::format("{2} + {1} = {0}", std::vector<std::string>{"5", "2", "3"}), "3 + 2 = 5");
	//between_start_and_end_string 并非python函数
	check_equal(pystring_function::between_start_and_end_string("test@example.com", "@"), "example.com");
	check_equal(pystring_function::between_start_and_end_string("From: test <test@example.com>", "<", ">"), "test@example.com");
	return true;
}



bool test_pystring_utf32()
{
	//切片 slice
	check_equal(pystring_utf32_function::slice(U""), U"");
	check_equal(pystring_utf32_function::slice(U"", 1), U"");
	check_equal(pystring_utf32_function::slice(U"", -1), U"");
	check_equal(pystring_utf32_function::slice(U"", -1, 2), U"");
	check_equal(pystring_utf32_function::slice(U"abcdef"), U"abcdef");
	check_equal(pystring_utf32_function::slice(U"abcdef", 0), U"abcdef");
	check_equal(pystring_utf32_function::slice(U"abcdef", 1), U"bcdef");
	check_equal(pystring_utf32_function::slice(U"abcdef", 2), U"cdef");
	check_equal(pystring_utf32_function::slice(U"abcdef", 2, 2), U"");
	check_equal(pystring_utf32_function::slice(U"abcdef", 2, 3), U"c");
	check_equal(pystring_utf32_function::slice(U"abcdef", 2, 1), U"");
	check_equal(pystring_utf32_function::slice(U"abcdef", 2, -1), U"cde");
	check_equal(pystring_utf32_function::slice(U"abcdef", 2, -2), U"cd");
	check_equal(pystring_utf32_function::slice(U"abcdef", 2, -3), U"c");
	check_equal(pystring_utf32_function::slice(U"abcdef", 2, -4), U"");
	check_equal(pystring_utf32_function::slice(U"abcdef", 2, -5), U"");
	check_equal(pystring_utf32_function::slice(U"abcdef", -1), U"f");
	check_equal(pystring_utf32_function::slice(U"abcdef", -2), U"ef");
	check_equal(pystring_utf32_function::slice(U"abcdef", -99), U"abcdef");
	check_equal(pystring_utf32_function::slice(U"abcdef", -99, -98), U"");
	check_equal(pystring_utf32_function::slice(U"abcdef", -2, 3), U"");
	check_equal(pystring_utf32_function::slice(U"abcdef", -2, 10), U"ef");
	check_equal(pystring_utf32_function::slice(U"abcdef", -1), U"f");
	check_equal(pystring_utf32_function::slice(U"abcdef", 0, -1), U"abcde");
	check_equal(pystring_utf32_function::slice(U"string", -3, -1), U"in");
	//
	//find()
	check_equal(pystring_utf32_function::find(U"", U""), 0);
	check_equal(pystring_utf32_function::find(U"", U"a"), -1);
	check_equal(pystring_utf32_function::find(U"a", U""), 0);
	check_equal(pystring_utf32_function::find(U"a", U"a"), 0);
	check_equal(pystring_utf32_function::find(U"abcdef", U""), 0);
	check_equal(pystring_utf32_function::find(U"abcdef", U"", -1), 5);
	check_equal(pystring_utf32_function::find(U"abcdef", U"", -2), 4);
	check_equal(pystring_utf32_function::find(U"abcdef", U"", -5), 1);
	check_equal(pystring_utf32_function::find(U"abcdef", U"", -6), 0);
	check_equal(pystring_utf32_function::find(U"abcdef", U"", -7), 0);
	check_equal(pystring_utf32_function::find(U"abcdef", U"def"), 3);
	check_equal(pystring_utf32_function::find(U"abcdef", U"def", 3), 3);
	check_equal(pystring_utf32_function::find(U"abcdef", U"def", 4), -1);
	check_equal(pystring_utf32_function::find(U"abcdef", U"def", -5), 3);
	check_equal(pystring_utf32_function::find(U"abcdef", U"def", -1), -1);
	check_equal(pystring_utf32_function::find(U"abcabcabc", U"bc", -2), 7);
	check_equal(pystring_utf32_function::find(U"abcabcabc", U"bc", -1), -1);
	check_equal(pystring_utf32_function::find(U"abcabcabc", U"bc", 0), 1);
	check_equal(pystring_utf32_function::find(U"abcabcabc", U"bc", 1), 1);
	check_equal(pystring_utf32_function::find(U"abcabcabc", U"bc", 2), 4);
	check_equal(pystring_utf32_function::find(U"abcabcabc", U"bc", 4), 4);
	check_equal(pystring_utf32_function::find(U"abcabcabc", U"bc", 7), 7);
	check_equal(pystring_utf32_function::find(U"abcabcabc", U"bc", 4, 3), -1);
	check_equal(pystring_utf32_function::find(U"abcabcabc", U"bc", 4, 4), -1);
	check_equal(pystring_utf32_function::find(U"abcabcabc", U"bc", 4, 5), -1);
	check_equal(pystring_utf32_function::find(U"abcabcabc", U"bc", 4, -1), 4);
	check_equal(pystring_utf32_function::find(U"abcabcabc", U"bc", 4, 6), 4);
	check_equal(pystring_utf32_function::find(U"abcabcabc", U"bc", 0, 0), -1);
	check_equal(pystring_utf32_function::find(U"abcabcabc", U"", 0, 0), 0);
	check_equal(pystring_utf32_function::find(U"abcabcabc", U"", 1, 0), -1);
	//rfind()
	check_equal(pystring_utf32_function::rfind(U"", U""), 0);
	check_equal(pystring_utf32_function::rfind(U"", U"a"), -1);
	check_equal(pystring_utf32_function::rfind(U"a", U""), 1);
	check_equal(pystring_utf32_function::rfind(U"a", U"a"), 0);
	check_equal(pystring_utf32_function::rfind(U"abcdef", U""), 6);
	check_equal(pystring_utf32_function::rfind(U"abcdef", U"", 0, 1), 1);
	check_equal(pystring_utf32_function::rfind(U"abcdef", U"", 0, 5), 5);
	check_equal(pystring_utf32_function::rfind(U"abcdef", U"", 0, -1), 5);
	check_equal(pystring_utf32_function::rfind(U"abcdef", U"", 0, -3), 3);
	check_equal(pystring_utf32_function::rfind(U"abcdef", U"def"), 3);
	check_equal(pystring_utf32_function::rfind(U"abcdef", U"def", 3), 3);
	check_equal(pystring_utf32_function::rfind(U"abcdef", U"def", 4), -1);
	check_equal(pystring_utf32_function::rfind(U"abcdef", U"def", -5), 3);
	check_equal(pystring_utf32_function::rfind(U"abcdef", U"def", -1), -1);
	check_equal(pystring_utf32_function::rfind(U"abcabcabc", U"bc", -2), 7);
	check_equal(pystring_utf32_function::rfind(U"abcabcabc", U"bc", -1), -1);
	check_equal(pystring_utf32_function::rfind(U"abcabcabc", U"bc", 0), 7);
	check_equal(pystring_utf32_function::rfind(U"abcabcabc", U"bc", 1), 7);
	check_equal(pystring_utf32_function::rfind(U"abcabcabc", U"bc", 4), 7);
	check_equal(pystring_utf32_function::rfind(U"abcabcabc", U"bc", 7), 7);
	check_equal(pystring_utf32_function::rfind(U"abcabcabc", U"bc", 4, -5), -1);
	check_equal(pystring_utf32_function::rfind(U"abcabcabc", U"bc", 4, -10), -1);
	check_equal(pystring_utf32_function::rfind(U"abcabcabc", U"bc", 4, 20), 7);
	check_equal(pystring_utf32_function::rfind(U"abcabcabc", U"abc", 6, 8), -1);
	//replace
	check_equal(pystring_utf32_function::replace(U"abcdef", U"foo", U"bar"), U"abcdef");
	check_equal(pystring_utf32_function::replace(U"abcdef", U"ab", U"cd"), U"cdcdef");
	check_equal(pystring_utf32_function::replace(U"abcdef", U"ab", U""), U"cdef");
	check_equal(pystring_utf32_function::replace(U"abcabc", U"ab", U""), U"cc");
	check_equal(pystring_utf32_function::replace(U"abcdef", U"", U""), U"abcdef");
	check_equal(pystring_utf32_function::replace(U"abcdef", U"", U"."), U".a.b.c.d.e.f.");
	//join
	std::vector<std::u32string> vec_join{ U"a", U"b", U"c", U"d" };
	check_equal(pystring_utf32_function::join(U"-", vec_join), U"a-b-c-d");
	vec_join.clear();
	vec_join.push_back(U"a");
	check_equal(pystring_utf32_function::join(U"-", vec_join), U"a");
	vec_join.clear();
	check_equal(pystring_utf32_function::join(U"-", vec_join), U"");
	//capitalize()
	check_equal(pystring_utf32_function::capitalize(U"this IS time test."), U"This is time test.");
	//center()
	check_equal(pystring_utf32_function::center(U"this", 11, '-'), U"----this---");
	check_equal(pystring_utf32_function::center(U"hello", 20, '-'), U"-------hello--------");
	//count()
	check_equal(pystring_utf32_function::count(U"this is string", U"is"), 2);
	//endswith()
	check_equal(pystring_utf32_function::endswith(U"test.exe", U"exe"), true);
	check_equal(pystring_utf32_function::endswith(U"test.exe", U"exe", 1, 4), false);
	check_equal(pystring_utf32_function::endswith(U"", U""), true);
	check_equal(pystring_utf32_function::endswith(U"", U"a"), false);
	check_equal(pystring_utf32_function::endswith(U"a", U""), true);
	check_equal(pystring_utf32_function::endswith(U"", U".mesh"), false);
	check_equal(pystring_utf32_function::endswith(U"help", U".mesh"), false);
	check_equal(pystring_utf32_function::endswith(U"help", U".mesh", 0), false);
	check_equal(pystring_utf32_function::endswith(U"help", U".mesh", 1), false);
	check_equal(pystring_utf32_function::endswith(U"help", U".mesh", 1, 2), false);
	check_equal(pystring_utf32_function::endswith(U"help", U".mesh", 1, 1), false);
	check_equal(pystring_utf32_function::endswith(U"help", U".mesh", 1, -1), false);
	check_equal(pystring_utf32_function::endswith(U"help", U".mesh", -1), false);
	check_equal(pystring_utf32_function::endswith(U".mesh", U".mesh"), true);
	check_equal(pystring_utf32_function::endswith(U"a.mesh", U".mesh"), true);
	check_equal(pystring_utf32_function::endswith(U"a.", U"."), true);
	check_equal(pystring_utf32_function::endswith(U"abcdef", U"ef"), true);
	check_equal(pystring_utf32_function::endswith(U"abcdef", U"cdef"), true);
	check_equal(pystring_utf32_function::endswith(U"abcdef", U"cdef", 2), true);
	check_equal(pystring_utf32_function::endswith(U"abcdef", U"cdef", 3), false);
	check_equal(pystring_utf32_function::endswith(U"abcdef", U"cdef", 2, 3), false);
	check_equal(pystring_utf32_function::endswith(U"abcdef", U"cdef", -10), true);
	//startswith
	check_equal(pystring_utf32_function::startswith(U"", U""), true);
	check_equal(pystring_utf32_function::startswith(U"", U"a"), false);
	check_equal(pystring_utf32_function::startswith(U"a", U""), true);
	check_equal(pystring_utf32_function::startswith(U"abc", U"ab"), true);
	check_equal(pystring_utf32_function::startswith(U"abc", U"abc"), true);
	check_equal(pystring_utf32_function::startswith(U"abc", U"abcd"), false);
	check_equal(pystring_utf32_function::startswith(U"abcdef", U"abc"), true);
	check_equal(pystring_utf32_function::startswith(U"abcdef", U"abc", 1), false);
	check_equal(pystring_utf32_function::startswith(U"abcdef", U"bc", 1), true);
	//expandtabs
	check_equal(pystring_utf32_function::expandtabs(U"\thello\t\r\n", 4),
		U"    hello   \r\n");
	check_equal(pystring_utf32_function::expandtabs(U"hel\tlo\t\r\n", 8),
		U"hel     lo      \r\n");
	//isalnum
	check_equal(pystring_utf32_function::isalnum(U"a1"), true);
	check_equal(pystring_utf32_function::isalnum(U"a1\n"), false);
	check_equal(pystring_utf32_function::isalnum(U""), false);
	//isalpha
	check_equal(pystring_utf32_function::isalpha(U"aabc"), true);
	check_equal(pystring_utf32_function::isalpha(U"a12\n"), false);
	check_equal(pystring_utf32_function::isalpha(U""), false);
	//isdigit
	check_equal(pystring_utf32_function::isdigit(U"11"), true);
	check_equal(pystring_utf32_function::isdigit(U"-11"), false);
	check_equal(pystring_utf32_function::isdigit(U""), false);
	//islower
	check_equal(pystring_utf32_function::islower(U""), false);
	check_equal(pystring_utf32_function::islower(U"11"), false);
	check_equal(pystring_utf32_function::islower(U"a11"), true);
	//check_equal(pystring_utf32_function::islower_s(U"a11"), true);
	//isupper
	check_equal(pystring_utf32_function::isupper(U""), false);
	check_equal(pystring_utf32_function::isupper(U"11"), false);
	check_equal(pystring_utf32_function::isupper(U"a11"), false);
	check_equal(pystring_utf32_function::isupper(U"A11"), true);
	//isspace
	check_equal(pystring_utf32_function::isspace(U" \r\n\t\f\v"), true);
	check_equal(pystring_utf32_function::isspace(U" a \r\n\t\f\v"), false);
	check_equal(pystring_utf32_function::isspace(U""), false);
	//istitle
	check_equal(pystring_utf32_function::istitle(U""), false);
	check_equal(pystring_utf32_function::istitle(U"This 1 Is Str1In\nG"), true);
	check_equal(pystring_utf32_function::istitle(U"this"), false);
	//title
	check_equal(pystring_utf32_function::title(U""), U"");
	check_equal(pystring_utf32_function::title(U"this 1 is str1in\ng"), U"This 1 Is Str1In\nG");
	check_equal(pystring_utf32_function::title(U"this"), U"This");
	//lower
	check_equal(pystring_utf32_function::lower(U"ThIs"), U"this");
	//upper
	check_equal(pystring_utf32_function::upper(U"ThIs"), U"THIS");
	//zfill
	check_equal(pystring_utf32_function::zfill(U"-0.01", 6), U"-00.01");
	check_equal(pystring_utf32_function::zfill(U"+0.01", 6), U"+00.01");
	//strip
	check_equal(pystring_utf32_function::strip(U"abccab", U"ab"), U"cc");
	check_equal(pystring_utf32_function::strip(U""), U"");
	check_equal(pystring_utf32_function::strip(U"a"), U"a");
	check_equal(pystring_utf32_function::strip(U"a "), U"a");
	check_equal(pystring_utf32_function::strip(U" a"), U"a");
	check_equal(pystring_utf32_function::strip(U"\n a "), U"a");
	check_equal(pystring_utf32_function::strip(U"\r\n a \r\n"), U"a");
	check_equal(pystring_utf32_function::strip(U"\r\n a \r\n\t"), U"a");
	//lstrip
	check_equal(pystring_utf32_function::lstrip(U""), U"");
	check_equal(pystring_utf32_function::lstrip(U"a"), U"a");
	check_equal(pystring_utf32_function::lstrip(U"a "), U"a ");
	check_equal(pystring_utf32_function::lstrip(U" a"), U"a");
	//rstrip
	check_equal(pystring_utf32_function::rstrip(U""), U"");
	check_equal(pystring_utf32_function::rstrip(U"a"), U"a");
	check_equal(pystring_utf32_function::rstrip(U"a "), U"a");
	check_equal(pystring_utf32_function::rstrip(U" a"), U" a");
	//splitlines
	std::vector<std::u32string> vec_line;
	check_equal(pystring_utf32_function::splitlines(U"1\n2\n3\n", false),
		std::vector<std::u32string> {U"1", U"2", U"3"});
	check_equal(pystring_utf32_function::splitlines(U"1\n2\n3\n", true),
		std::vector<std::u32string> { U"1\n", U"2\n", U"3\n" });
	check_equal(pystring_utf32_function::splitlines(U"1\r\n2\r\n3\r\n", false),
		std::vector<std::u32string> {U"1", U"2", U"3"});
	check_equal(pystring_utf32_function::splitlines(U"1\r\n2\r\n3\r\n", true),
		std::vector<std::u32string> { U"1\r\n", U"2\r\n", U"3\r\n" });
	check_equal(pystring_utf32_function::splitlines(U"\r1\r2\r3", false),
		std::vector<std::u32string> {U"", U"1", U"2", U"3"});
	check_equal(pystring_utf32_function::splitlines(U"\r1\r2\r3\r", true),
		std::vector<std::u32string> { U"\r", U"1\r", U"2\r", U"3\r" });
	//split
	check_equal(pystring_utf32_function::split(U"a,,b,,c", U",,"),
		std::vector<std::u32string> {U"a", U"b", U"c"});
	check_equal(pystring_utf32_function::split(U"\nab c\r"), std::vector<std::u32string> {U"ab", U"c"});
	check_equal(pystring_utf32_function::split(U"", U"/", 1), std::vector<std::u32string> {U""});
	check_equal(pystring_utf32_function::split(U" ", U" ", 1), std::vector<std::u32string> {U"", U""});
	check_equal(pystring_utf32_function::split(U"a ", U" ", 1),
		std::vector<std::u32string> {U"a", U""});
	check_equal(pystring_utf32_function::split(U"/", U"/", 1), std::vector<std::u32string> {U"", U""});
	check_equal(pystring_utf32_function::split(U" /", U"/", 1), std::vector<std::u32string> {U" ", U""});
	check_equal(pystring_utf32_function::split(U" //", U"/", 1), std::vector<std::u32string> {U" ", U"/"});
	check_equal(pystring_utf32_function::split(U"//as//rew//gdf", U"//"),
		std::vector<std::u32string> {U"", U"as", U"rew", U"gdf"});
	check_equal(pystring_utf32_function::split(U"/root/world", U"/", 0),
		std::vector<std::u32string> {U"/root/world"});
	check_equal(pystring_utf32_function::split(U"/root/world", U"/", 1),
		std::vector<std::u32string> {U"", U"root/world"});
	check_equal(pystring_utf32_function::split(U"/root/world", U"/", 2),
		std::vector<std::u32string> {U"", U"root", U"world"});
	check_equal(pystring_utf32_function::split(U"/root/world", U"/", -1),
		std::vector<std::u32string> {U"", U"root", U"world"});
	//rsplit
	// U"".rsplit(None, 1)
	check_equal(pystring_utf32_function::split(U"", U"/", 1), std::vector<std::u32string> {U""});
	// U" ".rsplit(None, 1)
	check_equal(pystring_utf32_function::rsplit(U" ", U"", 1).size(), 0);
	check_equal(pystring_utf32_function::rsplit(U"  ", U"", 1).size(), 0);
	check_equal(pystring_utf32_function::rsplit(U" /", U"/", 1), std::vector<std::u32string> {U" ", U""});
	check_equal(pystring_utf32_function::rsplit(U" //", U"/", 1),
		std::vector<std::u32string> {U" /", U""});
	check_equal(pystring_utf32_function::rsplit(U"/root", U"/", 1),
		std::vector<std::u32string> {U"", U"root"});
	check_equal(pystring_utf32_function::rsplit(U"/root", U"/", 0),
		std::vector<std::u32string> {U"/root"});
	check_equal(pystring_utf32_function::rsplit(U"/root/world", U"/", 1),
		std::vector<std::u32string> {U"/root", U"world"});
	check_equal(pystring_utf32_function::rsplit(U"/root/world", U"/", 2),
		std::vector<std::u32string> {U"", U"root", U"world"});
	check_equal(pystring_utf32_function::rsplit(U"/root/world", U"/", -1),
		std::vector<std::u32string> {U"", U"root", U"world"});
	// U" root world".rsplit(None, 0)
	check_equal(pystring_utf32_function::rsplit(U" root world"), std::vector<std::u32string> {U"root", U"world"});
	check_equal(pystring_utf32_function::rsplit(U" root world", U" ", 0),
		std::vector<std::u32string> {U" root world"});
	check_equal(pystring_utf32_function::rsplit(U" root world", U" ", 1),
		std::vector<std::u32string> {U" root", U"world"});
	check_equal(pystring_utf32_function::rsplit(U" root world", U" ", 2),
		std::vector<std::u32string> {U"", U"root", U"world"});
	//format
	check_equal(pystring_utf32_function::format(U"{} + {} = {}", std::vector<std::u32string>{U"1", U"2", U"3"}), U"1 + 2 = 3");
	check_equal(pystring_utf32_function::format(U"{2} + {1} = {0}", std::vector<std::u32string>{U"5", U"2", U"3"}), U"3 + 2 = 5");
	//between_start_and_end_string 并非python函数
	check_equal(pystring_utf32_function::between_start_and_end_string(U"test@example.com", U"@"), U"example.com");
	check_equal(pystring_utf32_function::between_start_and_end_string(U"From: test <test@example.com>", U"<", U">"), U"test@example.com");

	return true;
}
void test_utfpystring_class()
{
	//检查c_string到UTF-32
	pystring_utf32_class utf_str_from_cstr(u8"中文UTF32");
	check_equal(utf_str_from_cstr, U"中文UTF32");
	pystring_utf32_class utf_str_from_u16str(u"中文UTF32");
	check_equal(utf_str_from_u16str, U"中文UTF32");
	pystring_utf32_class utf_str(U"中文UTF32");
	check_equal(utf_str[0], U'中');
	utf_str[0] = U'英';
	utf_str.append(U"测试");
	check_equal(utf_str, U"英文UTF32测试");
	char32_t* sz_dup = utf_str.c_dup();
	delete[] sz_dup;
}
//*/
int main()
{
	std::cout << sizeof(pystring_utf32_class) << std::endl;
	std::cout << sizeof(std::u32string) << std::endl;
	pystring_utf32_class base_test(U"aaaa");
	for (pystring_utf32_class::const_iterator it = base_test.begin(); it != base_test.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	base_test.append(pystring_utf32_class(U"123"));
	base_test += U"add";
	base_test = base_test + std::u32string(U"add");
	base_test = std::u32string(U"add") + base_test;
	if (base_test == U"1")
	{

	}
	test_pystring();
	test_pystring_utf32();
	test_utfpystring_class();
	return 0;
}