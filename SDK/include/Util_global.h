#ifndef UTIL_GLOBAL_H
#define UTIL_GLOBAL_H


#ifdef UTIL_LIB
# define UTIL_EXPORT __declspec(dllexport)
#else
# define UTIL_EXPORT __declspec(dllimport)
#endif

#endif // CURRENCYTOOLS_GLOBAL_H
