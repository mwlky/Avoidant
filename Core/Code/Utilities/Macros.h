#include <iostream>

#ifdef DEBUG
#define LOG(x) std::cout << x << std::endl
#define LOG_ERROR(x) std::cout << x << std::endl
#else
#define LOG(x)
#define LOG_ERROR(x)
#endif