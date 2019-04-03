#if defined(_MSC_VER)
    #pragma once
#endif


#ifndef __COMPILER_MACROS_H__
#define __COMPILER_MACROS_H__

template <typename... Args>
inline void unused(Args &&...)
{
    // Do nothing
}

#define UNUSED(x) unused(x)

#endif