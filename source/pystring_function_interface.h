#if defined(_MSC_VER)
#pragma once
#endif
#ifndef __PYTHON_GEN_STRING_FUNCTION_OVERLOAD_H__
#define __PYTHON_GEN_STRING_FUNCTION_OVERLOAD_H__

#include "pystring_define.h"
#include "pystring_algorithm_template.h"

namespace pystring_function
{
/***********************************************************/
//slice
inline std::string slice(const std::string &str_input,
                         int_max_t n_start = 0,
                         int_max_t n_end = MAX_INT_MAX_T)
{
    return pystring_algorithm::slice<std::string>(str_input, n_start, n_end);
}

inline std::u16string slice(const std::u16string &str_input,
                            int_max_t n_start = 0,
                            int_max_t n_end = MAX_INT_MAX_T)
{
    return pystring_algorithm::slice<std::u16string>(str_input, n_start, n_end);
}

inline std::u32string slice(const std::u32string &str_input, int_max_t n_start = 0,
                            int_max_t n_end = MAX_INT_MAX_T)
{
    return pystring_algorithm::slice<std::u32string>(str_input, n_start, n_end);
}

/***********************************************************/
//find
inline int_max_t find(const std::string &str_input,
                      const std::string &str_substr,
                      int_max_t n_start = 0,
                      int_max_t n_end = MAX_INT_MAX_T
                     )
{
    return pystring_algorithm::find<std::string>(str_input, str_substr, n_start, n_end);
}

inline int_max_t find(const std::u16string &str_input,
                      const std::u16string &str_substr,
                      int_max_t n_start = 0,
                      int_max_t n_end = MAX_INT_MAX_T
                     )
{
    return pystring_algorithm::find<std::u16string>(str_input, str_substr, n_start, n_end);
}

inline int_max_t find(const std::u32string &str_input,
                      const std::u32string &str_substr,
                      int_max_t n_start = 0,
                      int_max_t n_end = MAX_INT_MAX_T
                     )
{
    return pystring_algorithm::find<std::u32string>(str_input, str_substr, n_start, n_end);
}

/***********************************************************/
//index
inline int_max_t index(const std::string &str_input,
                       const std::string &str_substr,
                       int_max_t n_start = 0,
                       int_max_t n_end = MAX_INT_MAX_T
                      )
{
    return pystring_algorithm::find<std::string>(str_input, str_substr, n_start, n_end);
}

inline int_max_t index(const std::u16string &str_input,
                       const std::u16string &str_substr,
                       int_max_t n_start = 0,
                       int_max_t n_end = MAX_INT_MAX_T
                      )
{
    return pystring_algorithm::find<std::u16string>(str_input, str_substr, n_start, n_end);
}

inline int_max_t index(const std::u32string &str_input,
                       const std::u32string &str_substr,
                       int_max_t n_start = 0,
                       int_max_t n_end = MAX_INT_MAX_T
                      )
{
    return pystring_algorithm::find<std::u32string>(str_input, str_substr, n_start, n_end);
}

/***********************************************************/
//rfind
inline int_max_t rfind(const std::string &str_input,
                       const std::string &str_substr,
                       int_max_t n_start = 0,
                       int_max_t n_end = MAX_INT_MAX_T
                      )
{
    return pystring_algorithm::rfind<std::string>(str_input, str_substr, n_start, n_end);
}

inline int_max_t rfind(const std::u16string &str_input,
                       const std::u16string &str_substr,
                       int_max_t n_start = 0,
                       int_max_t n_end = MAX_INT_MAX_T
                      )
{
    return pystring_algorithm::rfind<std::u16string>(str_input, str_substr, n_start, n_end);
}

inline int_max_t rfind(const std::u32string &str_input,
                       const std::u32string &str_substr,
                       int_max_t n_start = 0,
                       int_max_t n_end = MAX_INT_MAX_T
                      )
{
    return pystring_algorithm::rfind<std::u32string>(str_input, str_substr, n_start, n_end);
}

/***********************************************************/
//rindex
inline int_max_t rindex(const std::string &str_input,
                        const std::string &str_substr,
                        int_max_t n_start = 0,
                        int_max_t n_end = MAX_INT_MAX_T
                       )
{
    return pystring_algorithm::rfind<std::string>(str_input, str_substr, n_start, n_end);
}

inline int_max_t rindex(const std::u16string &str_input,
                        const std::u16string &str_substr,
                        int_max_t n_start = 0,
                        int_max_t n_end = MAX_INT_MAX_T
                       )
{
    return pystring_algorithm::rfind<std::u16string>(str_input, str_substr, n_start, n_end);
}

inline int_max_t rindex(const std::u32string &str_input,
                        const std::u32string &str_substr,
                        int_max_t n_start = 0,
                        int_max_t n_end = MAX_INT_MAX_T
                       )
{
    return pystring_algorithm::rfind<std::u32string>(str_input, str_substr, n_start, n_end);
}

/***********************************************************/
//replace
inline std::string replace(const std::string &str,
                           const std::string &oldstr,
                           const std::string &newstr,
                           int_max_t n_count = MAX_INT_MAX_T
                          )
{
    return pystring_algorithm::replace<std::string>(str, oldstr, newstr, n_count);
}

inline std::u16string replace(const std::u16string &str,
                              const std::u16string &oldstr,
                              const std::u16string &newstr,
                              int_max_t n_count = MAX_INT_MAX_T
                             )
{
    return pystring_algorithm::replace<std::u16string>(str, oldstr, newstr, n_count);
}

inline std::u32string replace(const std::u32string &str,
                              const std::u32string &oldstr,
                              const std::u32string &newstr,
                              int_max_t n_count = MAX_INT_MAX_T
                             )
{
    return pystring_algorithm::replace<std::u32string>(str, oldstr, newstr, n_count);
}

/***********************************************************/
//split_whitespace
inline std::vector<std::string> split_whitespace(const std::string &str_input,
        int_max_t maxsplit = MAX_INT_MAX_T
                                                )
{
    std::vector<std::string> vec_ret;
    pystring_algorithm::split_whitespace(vec_ret, str_input, maxsplit);
    return vec_ret;
}

inline std::vector<std::u16string> split_whitespace(const std::u16string &str_input,
        int_max_t maxsplit = MAX_INT_MAX_T
                                                   )
{
    std::vector<std::u16string> vec_ret;
    pystring_algorithm::split_whitespace(vec_ret, str_input, maxsplit);
    return vec_ret;
}

inline std::vector<std::u32string> split_whitespace(const std::u32string &str_input,
        int_max_t maxsplit = MAX_INT_MAX_T
                                                   )
{
    std::vector<std::u32string> vec_ret;
    pystring_algorithm::split_whitespace(vec_ret, str_input, maxsplit);
    return vec_ret;
}

inline void split_whitespace(std::vector<std::string> &vec_input,
                             const std::string &str_input,
                             int_max_t maxsplit = MAX_INT_MAX_T
                            )
{
    pystring_algorithm::split_whitespace(vec_input, str_input, maxsplit);
}

inline void split_whitespace(std::vector<std::u16string> &vec_input,
                             const std::u16string &str_input,
                             int_max_t maxsplit = MAX_INT_MAX_T
                            )
{
    pystring_algorithm::split_whitespace(vec_input, str_input, maxsplit);
}

inline void split_whitespace(std::vector<std::u32string> &vec_input,
                             const std::u32string &str_input,
                             int_max_t maxsplit = MAX_INT_MAX_T
                            )
{
    pystring_algorithm::split_whitespace(vec_input, str_input, maxsplit);
}

/***********************************************************/
//split
inline std::vector<std::string> split(const std::string &str_input,
                                      const std::string &str_sep = EMPTYE_C_STRING,
                                      int_max_t maxsplit = MAX_INT_MAX_T
                                     )
{
    std::vector<std::string> vec_ret;
    pystring_algorithm::split(vec_ret, str_input, str_sep, maxsplit);
    return vec_ret;
}

inline std::vector<std::u16string> split(const std::u16string &str_input,
        const std::u16string &str_sep = EMPTYE_C_U16STRING,
        int_max_t maxsplit = MAX_INT_MAX_T
                                        )
{
    std::vector<std::u16string> vec_ret;
    pystring_algorithm::split(vec_ret, str_input, str_sep, maxsplit);
    return vec_ret;
}

inline std::vector<std::u32string> split(const std::u32string &str_input,
        const std::u32string &str_sep = EMPTYE_C_U32STRING,
        int_max_t maxsplit = MAX_INT_MAX_T
                                        )
{
    std::vector<std::u32string> vec_ret;
    pystring_algorithm::split(vec_ret, str_input, str_sep, maxsplit);
    return vec_ret;
}

inline void split(std::vector<std::string> &vec_input,
                  const std::string &str_input,
                  const std::string &str_sep = EMPTYE_C_STRING,
                  int_max_t maxsplit = MAX_INT_MAX_T
                 )
{
    pystring_algorithm::split(vec_input, str_input, str_sep, maxsplit);
}

inline void split(std::vector<std::u16string> &vec_input,
                  const std::u16string &str_input,
                  const std::u16string &str_sep = EMPTYE_C_U16STRING,
                  int_max_t maxsplit = MAX_INT_MAX_T
                 )
{
    pystring_algorithm::split(vec_input, str_input, str_sep, maxsplit);
}

inline void split(std::vector<std::u32string> &vec_input,
                  const std::u32string &str_input,
                  const std::u32string &str_sep = EMPTYE_C_U32STRING,
                  int_max_t maxsplit = MAX_INT_MAX_T
                 )
{
    pystring_algorithm::split(vec_input, str_input, str_sep, maxsplit);
}

/***********************************************************/
//rsplit_whitespace
inline std::vector<std::string> rsplit_whitespace(const std::string &str_input,
        int_max_t maxsplit = MAX_INT_MAX_T
                                                 )
{
    std::vector<std::string> vec_ret;
    pystring_algorithm::rsplit_whitespace(vec_ret, str_input, maxsplit);
    return vec_ret;
}

inline std::vector<std::u16string> rsplit_whitespace(const std::u16string &str_input,
        int_max_t maxsplit = MAX_INT_MAX_T
                                                    )
{
    std::vector<std::u16string> vec_ret;
    pystring_algorithm::rsplit_whitespace(vec_ret, str_input, maxsplit);
    return vec_ret;
}

inline std::vector<std::u32string> rsplit_whitespace(const std::u32string &str_input,
        int_max_t maxsplit = MAX_INT_MAX_T
                                                    )
{
    std::vector<std::u32string> vec_ret;
    pystring_algorithm::rsplit_whitespace(vec_ret, str_input, maxsplit);
    return vec_ret;
}

inline void rsplit_whitespace(std::vector<std::string> &vec_input,
                              const std::string &str_input,
                              int_max_t maxsplit = MAX_INT_MAX_T
                             )
{
    pystring_algorithm::rsplit_whitespace(vec_input, str_input, maxsplit);
}

inline void rsplit_whitespace(std::vector<std::u16string> &vec_input,
                              const std::u16string &str_input,
                              int_max_t maxsplit = MAX_INT_MAX_T
                             )
{
    pystring_algorithm::rsplit_whitespace(vec_input, str_input, maxsplit);
}

inline void rsplit_whitespace(std::vector<std::u32string> &vec_input,
                              const std::u32string &str_input,
                              int_max_t maxsplit = MAX_INT_MAX_T
                             )
{
    pystring_algorithm::rsplit_whitespace(vec_input, str_input, maxsplit);
}

/***********************************************************/
//rsplit
inline std::vector<std::string> rsplit(const std::string &str_input,
                                       const std::string &str_sep = EMPTYE_C_STRING,
                                       int_max_t maxrsplit = MAX_INT_MAX_T
                                      )
{
    std::vector<std::string> vec_ret;
    pystring_algorithm::rsplit(vec_ret, str_input, str_sep, maxrsplit);
    return vec_ret;
}

inline std::vector<std::u16string> rsplit(const std::u16string &str_input,
        const std::u16string &str_sep = EMPTYE_C_U16STRING,
        int_max_t maxrsplit = MAX_INT_MAX_T
                                         )
{
    std::vector<std::u16string> vec_ret;
    pystring_algorithm::rsplit(vec_ret, str_input, str_sep, maxrsplit);
    return vec_ret;
}

inline std::vector<std::u32string> rsplit(const std::u32string &str_input,
        const std::u32string &str_sep = EMPTYE_C_U32STRING,
        int_max_t maxrsplit = MAX_INT_MAX_T
                                         )
{
    std::vector<std::u32string> vec_ret;
    pystring_algorithm::rsplit(vec_ret, str_input, str_sep, maxrsplit);
    return vec_ret;
}

inline void rsplit(std::vector<std::string> &vec_input,
                   const std::string &str_input,
                   const std::string &str_sep = EMPTYE_C_STRING,
                   int_max_t maxrsplit = MAX_INT_MAX_T
                  )
{
    pystring_algorithm::rsplit(vec_input, str_input, str_sep, maxrsplit);
}

inline void rsplit(std::vector<std::u16string> &vec_input,
                   const std::u16string &str_input,
                   const std::u16string &str_sep = EMPTYE_C_U16STRING,
                   int_max_t maxrsplit = MAX_INT_MAX_T
                  )
{
    pystring_algorithm::rsplit(vec_input, str_input, str_sep, maxrsplit);
}

inline void rsplit(std::vector<std::u32string> &vec_input,
                   const std::u32string &str_input,
                   const std::u32string &str_sep = EMPTYE_C_U32STRING,
                   int_max_t maxrsplit = MAX_INT_MAX_T
                  )
{
    pystring_algorithm::rsplit(vec_input, str_input, str_sep, maxrsplit);
}

/***********************************************************/
//join
inline std::string join(
    const std::string &str_input,
    const std::vector<std::string> &seq
)
{
    std::string ret_str;
    pystring_algorithm::join(str_input, seq, ret_str);
    return ret_str;
}

inline std::u16string join(
    const std::u16string &str_input,
    const std::vector<std::u16string> &seq
)
{
    std::u16string ret_str;
    pystring_algorithm::join(str_input, seq, ret_str);
    return ret_str;
}

inline std::u32string join(
    const std::u32string &str_input,
    const std::vector<std::u32string> &seq
)
{
    std::u32string ret_str;
    pystring_algorithm::join(str_input, seq, ret_str);
    return ret_str;
}

inline void join(const std::string &str,
                 const std::vector<std::string> &seq,
                 std::string &str_output
                )
{
    pystring_algorithm::join(str, seq, str_output);
}

inline void join(const std::u16string &str,
                 const std::vector<std::u16string> &seq,
                 std::u16string &str_output
                )
{
    pystring_algorithm::join(str, seq, str_output);
}

inline void join(const std::u32string &str,
                 const std::vector<std::u32string> &seq,
                 std::u32string &str_output
                )
{
    pystring_algorithm::join(str, seq, str_output);
}

/***********************************************************/
//partition
inline std::vector<std::string> partition(
    const std::string &str,
    const std::string &sep
)
{
    std::vector<std::string> vec_out_result;
    pystring_algorithm::partition(vec_out_result, str, sep);
    return vec_out_result;
}

inline std::vector<std::u16string> partition(
    const std::u16string &str,
    const std::u16string &sep
)
{
    std::vector<std::u16string> vec_out_result;
    pystring_algorithm::partition(vec_out_result, str, sep);
    return vec_out_result;
}

inline std::vector<std::u32string> partition(
    const std::u32string &str,
    const std::u32string &sep
)
{
    std::vector<std::u32string> vec_out_result;
    pystring_algorithm::partition(vec_out_result, str, sep);
    return vec_out_result;
}

inline void partition(
    std::vector<std::string> &vec_out_result,
    const std::string &str,
    const std::string &sep
)
{
    pystring_algorithm::partition(vec_out_result, str, sep);
}

inline void partition(
    std::vector<std::u16string> &vec_out_result,
    const std::u16string &str,
    const std::u16string &sep
)
{
    pystring_algorithm::partition(vec_out_result, str, sep);
}

inline void partition(
    std::vector<std::u32string> &vec_out_result,
    const std::u32string &str,
    const std::u32string &sep
)
{
    pystring_algorithm::partition(vec_out_result, str, sep);
}

/***********************************************************/
//partition
inline std::vector<std::string> rpartition(
    const std::string &str,
    const std::string &sep
)
{
    std::vector<std::string> vec_out_result;
    pystring_algorithm::rpartition(vec_out_result, str, sep);
    return vec_out_result;
}

inline std::vector<std::u16string> rpartition(
    const std::u16string &str,
    const std::u16string &sep
)
{
    std::vector<std::u16string> vec_out_result;
    pystring_algorithm::rpartition(vec_out_result, str, sep);
    return vec_out_result;
}

inline std::vector<std::u32string> rpartition(
    const std::u32string &str,
    const std::u32string &sep
)
{
    std::vector<std::u32string> vec_out_result;
    pystring_algorithm::rpartition(vec_out_result, str, sep);
    return vec_out_result;
}

inline void rpartition(
    std::vector<std::string> &vec_out_result,
    const std::string &str,
    const std::string &sep
)
{
    pystring_algorithm::rpartition(vec_out_result, str, sep);
}

inline void rpartition(
    std::vector<std::u16string> &vec_out_result,
    const std::u16string &str,
    const std::u16string &sep
)
{
    pystring_algorithm::rpartition(vec_out_result, str, sep);
}

inline void rpartition(
    std::vector<std::u32string> &vec_out_result,
    const std::u32string &str,
    const std::u32string &sep
)
{
    pystring_algorithm::rpartition(vec_out_result, str, sep);
}

/***********************************************************/
//splitlines
inline std::vector<std::string> splitlines(
    const std::string &str_data,
    bool b_keepends = false
)
{
    std::vector<std::string> vec_out_split_str;
    pystring_algorithm::splitlines(vec_out_split_str, str_data, b_keepends);
    return vec_out_split_str;
}

inline std::vector<std::u16string> splitlines(
    const std::u16string &str_data,
    bool b_keepends = false
)
{
    std::vector<std::u16string> vec_out_split_str;
    pystring_algorithm::splitlines(vec_out_split_str, str_data, b_keepends);
    return vec_out_split_str;
}

inline std::vector<std::u32string> splitlines(
    const std::u32string &str_data,
    bool b_keepends = false
)
{
    std::vector<std::u32string> vec_out_split_str;
    pystring_algorithm::splitlines(vec_out_split_str, str_data, b_keepends);
    return vec_out_split_str;
}

inline void splitlines(
    std::vector<std::string> &vec_out_split_str,
    const std::string &str_data,
    bool b_keepends = false
)
{
    pystring_algorithm::splitlines(vec_out_split_str, str_data, b_keepends);
}

inline void splitlines(
    std::vector<std::u16string> &vec_out_split_str,
    const std::u16string &str_data,
    bool b_keepends = false
)
{
    pystring_algorithm::splitlines(vec_out_split_str, str_data, b_keepends);
}

inline void splitlines(
    std::vector<std::u32string> &vec_out_split_str,
    const std::u32string &str_data,
    bool b_keepends = false
)
{
    pystring_algorithm::splitlines(vec_out_split_str, str_data, b_keepends);
}

/***********************************************************/
//lstrip
inline std::string lstrip(const std::string &str_input, const std::string &chars = EMPTYE_C_STRING)
{
    return pystring_algorithm::lstrip(str_input, chars);
}

inline std::u16string lstrip(const std::u16string &str_input, const std::u16string &chars = EMPTYE_C_U16STRING)
{
    return pystring_algorithm::lstrip(str_input, chars);
}

inline std::u32string lstrip(const std::u32string &str_input, const std::u32string &chars = EMPTYE_C_U32STRING)
{
    return pystring_algorithm::lstrip(str_input, chars);
}

/***********************************************************/
//rstrip
inline std::string rstrip(const std::string &str_input, const std::string &chars = EMPTYE_C_STRING)
{
    return pystring_algorithm::rstrip(str_input, chars);
}

inline std::u16string rstrip(const std::u16string &str_input, const std::u16string &chars = EMPTYE_C_U16STRING)
{
    return pystring_algorithm::rstrip(str_input, chars);
}

inline std::u32string rstrip(const std::u32string &str_input, const std::u32string &chars = EMPTYE_C_U32STRING)
{
    return pystring_algorithm::rstrip(str_input, chars);
}

/***********************************************************/
//strip
inline std::string strip(const std::string &str_input, const std::string &chars = EMPTYE_C_STRING)
{
    return pystring_algorithm::strip(str_input, chars);
}

inline std::u16string strip(const std::u16string &str_input, const std::u16string &chars = EMPTYE_C_U16STRING)
{
    return pystring_algorithm::strip(str_input, chars);
}

inline std::u32string strip(const std::u32string &str_input, const std::u32string &chars = EMPTYE_C_U32STRING)
{
    return pystring_algorithm::strip(str_input, chars);
}

/***********************************************************/
//swapcase
inline std::string swapcase(const std::string &str_input)
{
    return pystring_algorithm::swapcase(str_input);
}

inline std::u16string swapcase(const std::u16string &str_input)
{
    return pystring_algorithm::swapcase(str_input);
}

inline std::u32string swapcase(const std::u32string &str_input)
{
    return pystring_algorithm::swapcase(str_input);
}

/***********************************************************/
//capitalize
inline std::string capitalize(const std::string &oldstr)
{
    return pystring_algorithm::capitalize(oldstr);
}

inline std::u16string capitalize(const std::u16string &oldstr)
{
    return pystring_algorithm::capitalize(oldstr);
}

inline std::u32string capitalize(const std::u32string &oldstr)
{
    return pystring_algorithm::capitalize(oldstr);
}

/***********************************************************/
//center
inline std::string center(const std::string &str_input, size_t width, const char fillchar = SPACE_C_CHAR)
{
    return pystring_algorithm::center(str_input, width, fillchar);
}

inline std::u16string center(const std::u16string &str_input, size_t width, const char16_t fillchar = SPACE_C_U16CHAR)
{
    return pystring_algorithm::center(str_input, width, fillchar);
}

inline std::u32string center(const std::u32string &str_input, size_t width, const char32_t fillchar = SPACE_C_U32CHAR)
{
    return pystring_algorithm::center(str_input, width, fillchar);
}

/***********************************************************/
//count
inline int_max_t count(const std::string &str_input,
                       const std::string &substr,
                       int_max_t start = 0,
                       int_max_t end = MAX_INT_MAX_T
                      )
{
    return pystring_algorithm::count(str_input, substr, start, end);
}

inline int_max_t count(const std::u16string &str_input,
                       const std::u16string &substr,
                       int_max_t start = 0,
                       int_max_t end = MAX_INT_MAX_T
                      )
{
    return pystring_algorithm::count(str_input, substr, start, end);
}

inline int_max_t count(const std::u32string &str_input,
                       const std::u32string &substr,
                       int_max_t start = 0,
                       int_max_t end = MAX_INT_MAX_T
                      )
{
    return pystring_algorithm::count(str_input, substr, start, end);
}

/***********************************************************/
//endswith
inline bool endswith(const std::string &str_input,
                     const std::string &suffix,
                     int_max_t start = 0,
                     int_max_t end = MAX_INT_MAX_T
                    )
{
    return pystring_algorithm::endswith(str_input, suffix, start, end);
}

inline bool endswith(const std::u16string &str_input,
                     const std::u16string &suffix,
                     int_max_t start = 0,
                     int_max_t end = MAX_INT_MAX_T
                    )
{
    return pystring_algorithm::endswith(str_input, suffix, start, end);
}

inline bool endswith(const std::u32string &str_input,
                     const std::u32string &suffix,
                     int_max_t start = 0,
                     int_max_t end = MAX_INT_MAX_T
                    )
{
    return pystring_algorithm::endswith(str_input, suffix, start, end);
}

/***********************************************************/
//startswith
inline bool startswith(const std::string &str_input,
                       const std::string &prefix,
                       int_max_t start = 0,
                       int_max_t end = MAX_INT_MAX_T
                      )
{
    return pystring_algorithm::startswith(str_input, prefix, start, end);
}

inline bool startswith(const std::u16string &str_input,
                       const std::u16string &prefix,
                       int_max_t start = 0,
                       int_max_t end = MAX_INT_MAX_T
                      )
{
    return pystring_algorithm::startswith(str_input, prefix, start, end);
}

inline bool startswith(const std::u32string &str_input,
                       const std::u32string &prefix,
                       int_max_t start = 0,
                       int_max_t end = MAX_INT_MAX_T
                      )
{
    return pystring_algorithm::startswith(str_input, prefix, start, end);
}

/***********************************************************/
//expandtabs
inline std::string expandtabs(const std::string &str_input, int tabsize = 8)
{
    return pystring_algorithm::expandtabs(str_input, tabsize);
}

inline std::u16string expandtabs(const std::u16string &str_input, int tabsize = 8)
{
    return pystring_algorithm::expandtabs(str_input, tabsize);
}

inline std::u32string expandtabs(const std::u32string &str_input, int tabsize = 8)
{
    return pystring_algorithm::expandtabs(str_input, tabsize);
}

/***********************************************************/
//isalnum
inline bool isalnum(const std::string &str_input)
{
    return pystring_algorithm::isalnum(str_input);
}

inline bool isalnum(const std::u16string &str_input)
{
    return pystring_algorithm::isalnum(str_input);
}

inline bool isalnum(const std::u32string &str_input)
{
    return pystring_algorithm::isalnum(str_input);
}

/***********************************************************/
//isalpha
inline bool isalpha(const std::string &str_input)
{
    return pystring_algorithm::isalpha(str_input);
}

inline bool isalpha(const std::u16string &str_input)
{
    return pystring_algorithm::isalpha(str_input);
}

inline bool isalpha(const std::u32string &str_input)
{
    return pystring_algorithm::isalpha(str_input);
}

/***********************************************************/
//isdigit
inline bool isdigit(const std::string &str_input)
{
    return pystring_algorithm::isdigit(str_input);
}

inline bool isdigit(const std::u16string &str_input)
{
    return pystring_algorithm::isdigit(str_input);
}

inline bool isdigit(const std::u32string &str_input)
{
    return pystring_algorithm::isdigit(str_input);
}

/***********************************************************/
//isspace
inline bool isspace(const std::string &str_input)
{
    return pystring_algorithm::isspace(str_input);
}

inline bool isspace(const std::u16string &str_input)
{
    return pystring_algorithm::isspace(str_input);
}

inline bool isspace(const std::u32string &str_input)
{
    return pystring_algorithm::isspace(str_input);
}

/***********************************************************/
//istitle
inline bool istitle(const std::string &str_input)
{
    return pystring_algorithm::istitle(str_input);
}

inline bool istitle(const std::u16string &str_input)
{
    return pystring_algorithm::istitle(str_input);
}

inline bool istitle(const std::u32string &str_input)
{
    return pystring_algorithm::istitle(str_input);
}

/***********************************************************/
//islower
inline bool islower(const std::string &str_input)
{
    return pystring_algorithm::islower(str_input);
}

inline bool islower(const std::u16string &str_input)
{
    return pystring_algorithm::islower(str_input);
}

inline bool islower(const std::u32string &str_input)
{
    return pystring_algorithm::islower(str_input);
}

/***********************************************************/
//isupper
inline bool isupper(const std::string &str_input)
{
    return pystring_algorithm::isupper(str_input);
}

inline bool isupper(const std::u16string &str_input)
{
    return pystring_algorithm::isupper(str_input);
}

inline bool isupper(const std::u32string &str_input)
{
    return pystring_algorithm::isupper(str_input);
}

/***********************************************************/
//lower
inline std::string lower(const std::string &str_input)
{
    return pystring_algorithm::lower(str_input);
}

inline std::u16string lower(const std::u16string &str_input)
{
    return pystring_algorithm::lower(str_input);
}

inline std::u32string lower(const std::u32string &str_input)
{
    return pystring_algorithm::lower(str_input);
}

/***********************************************************/
//upper
inline std::string upper(const std::string &str_input)
{
    return pystring_algorithm::upper(str_input);
}

inline std::u16string upper(const std::u16string &str_input)
{
    return pystring_algorithm::upper(str_input);
}

inline std::u32string upper(const std::u32string &str_input)
{
    return pystring_algorithm::upper(str_input);
}

/***********************************************************/
//ljust
inline std::string ljust(const std::string &str_input, int_max_t width, char fillchar = SPACE_C_CHAR)
{
    return pystring_algorithm::ljust(str_input, width, fillchar);
}

inline std::u16string ljust(const std::u16string &str_input, int_max_t width, char16_t fillchar = SPACE_C_U16CHAR)
{
    return pystring_algorithm::ljust(str_input, width, fillchar);
}

inline std::u32string ljust(const std::u32string &str_input, int_max_t width, char32_t fillchar = SPACE_C_U32CHAR)
{
    return pystring_algorithm::ljust(str_input, width, fillchar);
}

/***********************************************************/
//rjust
inline std::string rjust(const std::string &str_input, int_max_t width, char fillchar = SPACE_C_CHAR)
{
    return pystring_algorithm::rjust(str_input, width, fillchar);
}

inline std::u16string rjust(const std::u16string &str_input, int_max_t width, char16_t fillchar = SPACE_C_U16CHAR)
{
    return pystring_algorithm::rjust(str_input, width, fillchar);
}

inline std::u32string rjust(const std::u32string &str_input, int_max_t width, char32_t fillchar = SPACE_C_U32CHAR)
{
    return pystring_algorithm::rjust(str_input, width, fillchar);
}

/***********************************************************/
//title
inline std::string title(const std::string &str_input)
{
    return pystring_algorithm::title(str_input);
}

inline std::u16string title(const std::u16string &str_input)
{
    return pystring_algorithm::title(str_input);
}

inline std::u32string title(const std::u32string &str_input)
{
    return pystring_algorithm::title(str_input);
}

/***********************************************************/
//zfill
inline std::string zfill(const std::string &str_input, size_t width)
{
    return pystring_algorithm::zfill(str_input, width);
}

inline std::u16string zfill(const std::u16string &str_input, size_t width)
{
    return pystring_algorithm::zfill(str_input, width);
}

inline std::u32string zfill(const std::u32string &str_input, size_t width)
{
    return pystring_algorithm::zfill(str_input, width);
}

/***********************************************************/
//translate
inline std::string translate(const std::string &old_str, const std::string &intab,
                             const std::string &outtab)
{
    return pystring_algorithm::translate(old_str,intab,outtab);
}

inline std::u16string translate(const std::u16string &old_str, const std::u16string &intab,
                             const std::u16string &outtab)
{
    return pystring_algorithm::translate(old_str,intab,outtab);
}

inline std::u32string translate(const std::u32string &old_str, const std::u32string &intab,
                             const std::u32string &outtab)
{
    return pystring_algorithm::translate(old_str,intab,outtab);
}

/***********************************************************/
//get_middle_of_pos
inline bool get_middle_of_pos(const std::string &str_data,
                       const std::string &str_start,
                       const std::string &str_end,
                       size_t &n_start,
                       size_t &n_copylen)
{
    return pystring_algorithm::get_middle_of_pos(str_data, str_start, str_end, n_start, n_copylen);
}

inline bool get_middle_of_pos(const std::u16string &str_data,
                       const std::u16string &str_start,
                       const std::u16string &str_end,
                       size_t &n_start,
                       size_t &n_copylen)
{
    return pystring_algorithm::get_middle_of_pos(str_data, str_start, str_end, n_start, n_copylen);
}

inline bool get_middle_of_pos(const std::u32string &str_data,
                       const std::u32string &str_start,
                       const std::u32string &str_end,
                       size_t &n_start,
                       size_t &n_copylen)
{
    return pystring_algorithm::get_middle_of_pos(str_data, str_start, str_end, n_start, n_copylen);
}

/***********************************************************/
//get_middle_of
inline std::string get_middle_of(const std::string &str_data,
                          const std::string &str_start,
                          const std::string &str_end = EMPTYE_C_STRING
                         )
{
    return pystring_algorithm::get_middle_of(str_data, str_start, str_end);
}

inline std::u16string get_middle_of(const std::u16string &str_data,
                             const std::u16string &str_start,
                             const std::u16string &str_end = EMPTYE_C_U16STRING
                            )
{
    return pystring_algorithm::get_middle_of(str_data, str_start, str_end);
}

inline std::u32string get_middle_of(const std::u32string &str_data,
                             const std::u32string &str_start,
                             const std::u32string &str_end = EMPTYE_C_U32STRING
                            )
{
    return pystring_algorithm::get_middle_of(str_data, str_start, str_end);
}

/***********************************************************/
//delete_middle_of
inline std::string delete_middle_of(const std::string& str_input_text,
                                    const std::string& str_start_flag,
                                    const std::string& str_end_flag = EMPTYE_C_STRING,
                                    int_max_t n_count = MAX_INT_MAX_T
                                   )
{
    return pystring_algorithm::delete_middle_of(str_input_text, str_start_flag, str_end_flag, n_count);
}

inline std::u16string delete_middle_of(const std::u16string& str_input_text,
                                       const std::u16string& str_start_flag,
                                       const std::u16string& str_end_flag = EMPTYE_C_U16STRING,
                                       int_max_t n_count = MAX_INT_MAX_T
                                      )
{
    return pystring_algorithm::delete_middle_of(str_input_text, str_start_flag, str_end_flag, n_count);
}

inline std::u32string delete_middle_of(const std::u32string& str_input_text,
                                       const std::u32string& str_start_flag,
                                       const std::u32string& str_end_flag = EMPTYE_C_U32STRING,
                                       int_max_t n_count = MAX_INT_MAX_T
                                      )
{
    return pystring_algorithm::delete_middle_of(str_input_text, str_start_flag, str_end_flag, n_count);
}

/***********************************************************/
//truncate
inline std::string truncate(const std::string &str_input, const std::string &str_truncate)
{
    return pystring_algorithm::truncate(str_input, str_truncate);
}

inline std::u16string truncate(const std::u16string &str_input, const std::u16string &str_truncate)
{
    return pystring_algorithm::truncate(str_input, str_truncate);
}

inline std::u32string truncate(const std::u32string &str_input, const std::u32string &str_truncate)
{
    return pystring_algorithm::truncate(str_input, str_truncate);
}

/***********************************************************/
//truncate_char
inline std::string truncate_char(const std::string &str_input, const std::string &str_truncate_char)
{
    return pystring_algorithm::truncate_char(str_input, str_truncate_char);
}

inline std::u16string truncate_char(const std::u16string &str_input, const std::u16string &str_truncate_char)
{
    return pystring_algorithm::truncate_char(str_input, str_truncate_char);
}

inline std::u32string truncate_char(const std::u32string &str_input, const std::u32string &str_truncate_char)
{
    return pystring_algorithm::truncate_char(str_input, str_truncate_char);
}
}

#endif //__PYTHON_GEN_STRING_FUNCTION_OVERLOAD_H__
