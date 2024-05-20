#ifndef MYLIB_H
#define MYLIB_H

#if defined(_WIN32) || defined(_WIN64)
  #ifdef MYLIB_EXPORTS
    #define MYLIB_API __declspec(dllexport)
  #else
    #define MYLIB_API __declspec(dllimport)
  #endif
#else
  #define MYLIB_API
#endif

MYLIB_API void hello();

#endif // MYLIB_H
