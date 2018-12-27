#include "pystring_interface_function.h"
#include "pystring_class.h"
#include <stdexcept>
#include <iostream>

//测试模板
template <typename T1, typename T2>
void check_equal(T1 chk1, T2 chk2)
{
	if (chk1 != chk2)
	{
		throw std::runtime_error("Exceptional results");
	}
}

void testcase_slice()
{
	//切片 slice
	check_equal(pystring_function::slice(std::string()), "");
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
	//切片utf32版本
	check_equal(pystring_function::slice(U"abcdef", 1), U"bcdef");
	check_equal(pystring_function::slice(U"string", -3, -1), U"in");
	//切片utf16版本
	check_equal(pystring_function::slice(u"abcdef", 1), u"bcdef");
	check_equal(pystring_function::slice(u"string", -3, -1), u"in");
}

void testcase_find()
{
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
}

void testcase_rfind()
{
	//rfind()
	check_equal(pystring_function::rfind("", ""), 0);
	check_equal(pystring_function::rfind("", "a"), -1);
	check_equal(pystring_function::rfind("a", ""), 1);
	check_equal(pystring_function::rfind("ab", ""), 2);
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
	check_equal(pystring_function::rfind("abcabcabc", "", 0, 9), 9);
}

void testcase_replace()
{
	//replace
	check_equal(pystring_function::replace("abcdef", "foo", "bar"), "abcdef");
	check_equal(pystring_function::replace("abcdef", "ab", "cd"), "cdcdef");
	check_equal(pystring_function::replace("abcdef", "ab", ""), "cdef");
	check_equal(pystring_function::replace("abcabc", "ab", ""), "cc");
	check_equal(pystring_function::replace("abcdef", "", ""), "abcdef");
	check_equal(pystring_function::replace("abcdef", "", "."), ".a.b.c.d.e.f.");
}

void testcase_split()
{
	//split_whitespace
	check_equal(pystring_function::split_whitespace("  11   22   33   44   55  ").size(), (size_t)5);
	check_equal(pystring_function::split_whitespace("11 22 33 44 55",1).size(), (size_t)2);
	check_equal(pystring_function::split_whitespace("11 22 33 44 55", 0).size(), (size_t)1);
	check_equal(pystring_function::split_whitespace("\n\t11\n\t22\n\t33\n\t44\n\t55\n\t").size(), (size_t)5);

	//split
	//',,,,'.split(',', -1) -> ['', '', '', '', '']
	check_equal(pystring_function::split(",,,,", ",",-1), std::vector<std::string> {"", "", "", "", ""});
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
	check_equal(pystring_function::rsplit(" ", "", 1).size(), (size_t)0);
	check_equal(pystring_function::rsplit("  ", "", 1).size(), (size_t)0);
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
	check_equal(pystring_function::rsplit("a,,b,,c", ",,"), std::vector<std::string> {"a", "b", "c"});
}

void testcase_join()
{
	//join
	std::vector<std::string> vec_join{ "a", "b", "c", "d" };
	check_equal(pystring_function::join("-", vec_join), "a-b-c-d");
	vec_join.clear();
	vec_join.push_back("a");
	check_equal(pystring_function::join("-", vec_join), "a");
	vec_join.clear();
	check_equal(pystring_function::join("-", vec_join), "");
}

void testcase_partition()
{
	//"https://baidu.com" -> ('https', '://', 'baidu.com')
	check_equal(pystring_function::partition("https://baidu.com", "://"), std::vector<std::string> {"https", "://", "baidu.com"});
	check_equal(pystring_function::rpartition("https://baidu.com", "://"), std::vector<std::string> {"https", "://", "baidu.com"});
}

void testcase_splitlines()
{
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
}

void testcase_strip()
{
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
}

void testcase_swapcase()
{
	check_equal(pystring_function::swapcase("AbCdEf"), "aBcDeF");
	check_equal(pystring_function::swapcase("aa"), "AA");
	check_equal(pystring_function::swapcase("AA"), "aa");
}

void testcase_capitalize()
{
	check_equal(pystring_function::capitalize("this IS String"), "This is string");
}

void testcase_center()
{
	check_equal(pystring_function::center("IS",6), "  IS  ");
	check_equal(pystring_function::center("IS", 6,'F'), "FFISFF");
}

void testcase_count()
{
	check_equal(pystring_function::count("this","is"), 1);
	check_equal(pystring_function::count("this", "isa"), 0);
	check_equal(pystring_function::count("0xffff", "f"), 4);
	check_equal(pystring_function::count("0xffff", "f",3), 3);
}

void testcase_endswith()
{
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
}

void testcase_startswith()
{
	check_equal(pystring_function::startswith("", ""), true);
	check_equal(pystring_function::startswith("", "a"), false);
	check_equal(pystring_function::startswith("a", ""), true);
	check_equal(pystring_function::startswith("abc", "ab"), true);
	check_equal(pystring_function::startswith("abc", "abc"), true);
	check_equal(pystring_function::startswith("abc", "abcd"), false);
	check_equal(pystring_function::startswith("abcdef", "abc"), true);
	check_equal(pystring_function::startswith("abcdef", "abc", 1), false);
	check_equal(pystring_function::startswith("abcdef", "bc", 1), true);
}

void testcase_expandtabs()
{
	//expandtabs
	check_equal(pystring_function::expandtabs("\thello\t\r\n", 4), "    hello   \r\n");
	check_equal(pystring_function::expandtabs("hel\tlo\t\r\n", 8), "hel     lo      \r\n");
}

void testcase_is_series()
{
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
}

void testcase_title()
{
	//title
	check_equal(pystring_function::title(""), "");
	check_equal(pystring_function::title("this 1 is str1in\ng"), "This 1 Is Str1In\nG");
	check_equal(pystring_function::title("this"), "This");
}

void testcase_lower()
{
	//lower
	check_equal(pystring_function::lower("ThIs"), "this");
}

void testcase_upper()
{
	//upper
	check_equal(pystring_function::upper("ThIs"), "THIS");
}

void testcase_zfill()
{
	//zfill
	check_equal(pystring_function::zfill("-0.01", 6), "-00.01");
	check_equal(pystring_function::zfill("-100", 10), "-000000100");
	check_equal(pystring_function::zfill("+0.01", 6), "+00.01");
	check_equal(pystring_function::zfill("+100", 10), "+000000100");
}

void testcase_translate()
{
	//zfill
	check_equal(pystring_function::translate("01234", "012","abc"), "abc34");
}

void testcase_get_middle_of()
{
	//get_middle_of 并非python函数
	check_equal(pystring_function::get_middle_of("test@example.com", "@"), "example.com");
	check_equal(pystring_function::get_middle_of("From: test <test@example.com>", "<", ">"), "test@example.com");
}

void testcase_delete_middle_of()
{
	check_equal(pystring_function::delete_middle_of("test@example.com", "@"), "test");
	check_equal(pystring_function::delete_middle_of("From: test <test@example.com>", "<", ">"), "From: test ");
}

void testcase_truncate()
{
	check_equal(pystring_function::truncate("https://www.google.com/", "//"), "https:");
	check_equal(pystring_function::truncate_char("https://www.google.com/", "moc"), "https://www.g");
}

void test_pystring_function()
{
	//测试切片函数
	testcase_slice();
	//测试查找函数
	testcase_find();
	testcase_rfind();
	//测试替换函数
	testcase_replace();
	testcase_split();
	testcase_join();
	testcase_partition();
	testcase_splitlines();
	testcase_strip();
	testcase_swapcase();
	testcase_capitalize();
	testcase_center();
	testcase_count();
	testcase_endswith();
	testcase_startswith();
	testcase_expandtabs();
	//is系列函数
	testcase_is_series();
	testcase_title();
	testcase_lower();
	testcase_upper();
	testcase_zfill();
	testcase_translate();
	testcase_get_middle_of();
	testcase_delete_middle_of();
	testcase_truncate();
}

void test_pystring_class()
{
    //test format
    check_equal(pystring_ext("number : %d").argv(100),"number : 100");
    check_equal(pystring_ext("number : %f").argv(100.0122,2),"number : 100.01");
    check_equal(pystring_ext("number : %s%s").argv("10").argv("0"),"number : 100");
}

int main()
{
	test_pystring_function();
	std::cout << "test pystring function all pass" << std::endl;
	test_pystring_class();
	std::cout << "testcase all pass" << std::endl;
	return 0;
}
