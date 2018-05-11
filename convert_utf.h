/*
* Copyright 2001-2004 Unicode, Inc.
*
* Disclaimer
*
* This source code is provided as is by Unicode, Inc. No claims are
* made as to fitness for any particular purpose. No warranties of any
* kind are expressed or implied. The recipient agrees to determine
* applicability of information provided. If this file has been
* purchased on magnetic or optical media from Unicode, Inc., the
* sole remedy for any claim will be exchange of defective media
* within 90 days of receipt.
*
* Limitations on Rights to Redistribute This Code
*
* Unicode, Inc. hereby grants the right to freely use the information
* supplied in this file in the creation of products supporting the
* Unicode Standard, and to make copies of this file in any form
* for internal or external distribution as long as this notice
* remains attached.
*/
/* ---------------------------------------------------------------------
Conversions between UTF32_CHAR, UTF-16, and UTF-8.  Header file.
Several funtions are included here, forming a complete set of
conversions between the three formats.  UTF-7 is not included
here, but is handled in a separate source file.
Each of these routines takes pointers to input buffers and output
buffers.  The input buffers are const.
Each routine converts the text between *source_start and source_end,
putting the result into the buffer between *target_start and
target_end. Note: the end pointers are *after* the last item: e.g.
*(source_end - 1) is the last item.
The return result indicates whether the conversion was successful,
and if not, whether the problem was in the source or target buffers.
(Only the first encountered problem is indicated.)
After the conversion, *source_start and *target_start are both
updated to point to the end of last text successfully converted in
the respective buffers.
Input parameters:
source_start - pointer to a pointer to the source buffer.
The contents of this are modified on return so that
it points at the next thing to be converted.
target_start - similarly, pointer to pointer to the target buffer.
source_end, target_end - respectively pointers to the ends of the
two buffers, for overflow checking only.
These conversion functions take a CONVERSION_FLAGS argument. When this
flag is set to strict, both irregular sequences and isolated surrogates
will cause an error.  When the flag is set to lenient, both irregular
sequences and isolated surrogates are converted.
Whether the flag is strict or lenient, all illegal sequences will cause
an error return. This includes sequences such as: <F4 90 80 80>, <C0 80>,
or <A0> in UTF-8, and values above 0x10FFFF in UTF-32. Conformant code
must check for illegal sequences.
When the flag is set to lenient, characters over 0x10FFFF are converted
to the replacement character; otherwise (when the flag is set to strict)
they constitute an error.
Output parameters:
The value "SOURCE_ILLEGAL" is returned from some routines if the input
sequence is malformed.  When "SOURCE_ILLEGAL" is returned, the source
value will point to the illegal value that caused the problem. E.g.,
in UTF-8 when a sequence is malformed, it points to the start of the
malformed sequence.
Author: Mark E. Davis, 1994.
Rev History: Rick McGowan, fixes & updates May 2001.
Fixes & updates, Sept 2001.
------------------------------------------------------------------------ */
/* ---------------------------------------------------------------------
The following 4 definitions are compiler-specific.
The C standard does not guarantee that wchar_t has at least
16 bits, so wchar_t is no less portable than unsigned short!
All should be unsigned values to avoid sign extension during
bit mask & shift operations.
------------------------------------------------------------------------ */
#if defined(_MSC_VER)
#pragma once
#endif
#ifndef __CONVERT_UTF_CPP__
#define __CONVERT_UTF_CPP__

#include <stdint.h> //define uint8_t
#include <stddef.h> //define size_t

typedef uint32_t UTF32_CHAR;	/* 32 bits */
typedef uint16_t UTF16_CHAR;	/* 16 bits */
typedef uint8_t UTF8_CHAR;	/* 8 bits */
typedef int BOOL_INT; /* 0 or 1 */
					  /* Some fundamental constants */
#define UNI_REPLACEMENT_CHAR (UTF32_CHAR)0x0000FFFD
#define UNI_MAX_BMP (UTF32_CHAR)0x0000FFFF
#define UNI_MAX_UTF16 (UTF32_CHAR)0x0010FFFF
#define UNI_MAX_UTF32 (UTF32_CHAR)0x7FFFFFFF
#define UNI_MAX_LEGAL_UTF32 (UTF32_CHAR)0x0010FFFF
typedef enum {
	CONVERSION_OK, 		/*转换成功 conversion successful */
	SOURCE_EXHAUSTED,	/*源字符串过早结束，可能是数据不完整 partial character in source, but hit end */
	TARGET_EXHAUSTED,	/*目标空间不足 insuff. room in target for conversion */
	SOURCE_ILLEGAL		/* source sequence is illegal/malformed */
} CONVERSION_RESULT;
typedef enum {
	STRICT_CONVERSION = 0,
	LENIENT_CONVERSION
} CONVERSION_FLAGS;
/* This is for C++ and does no harm in C */
#ifdef __cplusplus
extern "C" {
#endif
	CONVERSION_RESULT ConvertUTF8toUTF16(
		const UTF8_CHAR** source_start, const UTF8_CHAR* source_end,
		UTF16_CHAR** target_start, UTF16_CHAR* target_end, CONVERSION_FLAGS flags);
	CONVERSION_RESULT ConvertUTF16toUTF8(
		const UTF16_CHAR** source_start, const UTF16_CHAR* source_end,
		UTF8_CHAR** target_start, UTF8_CHAR* target_end, CONVERSION_FLAGS flags);

	CONVERSION_RESULT ConvertUTF8toUTF32(
		const UTF8_CHAR** source_start, const UTF8_CHAR* source_end,
		UTF32_CHAR** target_start, UTF32_CHAR* target_end, CONVERSION_FLAGS flags);
	CONVERSION_RESULT ConvertUTF32toUTF8(
		const UTF32_CHAR** source_start, const UTF32_CHAR* source_end,
		UTF8_CHAR** target_start, UTF8_CHAR* target_end, CONVERSION_FLAGS flags);

	CONVERSION_RESULT ConvertUTF16toUTF32(
		const UTF16_CHAR** source_start, const UTF16_CHAR* source_end,
		UTF32_CHAR** target_start, UTF32_CHAR* target_end, CONVERSION_FLAGS flags);
	CONVERSION_RESULT ConvertUTF32toUTF16(
		const UTF32_CHAR** source_start, const UTF32_CHAR* source_end,
		UTF16_CHAR** target_start, UTF16_CHAR* target_end, CONVERSION_FLAGS flags);
	BOOL_INT isLegalUTF8Sequence(const UTF8_CHAR *source, const UTF8_CHAR *source_end);

	BOOL_INT isLegalUTF8(const UTF8_CHAR *source, int length);
#ifdef __cplusplus
}
#endif

#endif // !__CONVERT_UTF_CPP__
