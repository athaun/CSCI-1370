#pragma once

inline void _test(const char* expression, const char* file, int line);
#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))

void run_tests ();