#ifndef UNICODE_CONV_H_
#define UNICODE_CONV_H_

#include <array>
#include <string>

bool ConvChU8ToU16(const std::array<char, 4>& u8Ch,
                   std::array<char16_t, 2>& u16Ch);
bool ConvChU8ToU32(const std::array<char, 4>& u8Ch, char32_t& u32Ch);

bool ConvChU16ToU8(const std::array<char16_t, 2>& u16Ch,
                   std::array<char, 4>& u8Ch);
bool ConvChU16ToU32(const std::array<char16_t, 2>& u16Ch, char32_t& u32Ch);

bool ConvChU32ToU8(const char32_t u32Ch, std::array<char, 4>& u8Ch);
bool ConvChU32ToU16(const char32_t u32Ch, std::array<char16_t, 2>& u16Ch);

bool ConvU8ToU16(const std::string& u8Str, std::u16string& u16Str);
bool ConvU8ToU32(const std::string& u8Str, std::u32string& u32Str);

bool ConvU16ToU8(const std::u16string& u16Str, std::string& u8Str);
bool ConvU16ToU32(const std::u16string& u16Str, std::u32string& u32Str);

bool ConvU32ToU8(const std::u32string& u32Str, std::string& u8Str);
bool ConvU32ToU16(const std::u32string& u32Str, std::u16string& u16Str);

#endif  // UNICODE_CONV_H_
