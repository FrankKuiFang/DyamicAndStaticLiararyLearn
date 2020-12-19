#pragma once
#include <iostream>

using namespace std;


	#ifdef BUILD_Solution_DLL
		#if defined(WIN32) || defined(_WIN32)
			#define BUILD_Solution_API __declspec(dllexport)
		#elif defined(__linux__) || defined(__linux)
			#define BUILD_Solution_API //LINUX下不需要显示地声明导出符号
		#endif
	#else
		#define BUILD_Solution_API __declspec(dllimport)
	#endif


class Solution{

public:
    Solution() {
    }

    virtual ~Solution() {}

    BUILD_Solution_API double Add(const double a, const double b);
	
    BUILD_Solution_API double Subtraction(const double a, const double b);

};