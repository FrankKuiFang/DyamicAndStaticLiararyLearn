#pragma once
#include <iostream>

using namespace std;

 //静态库就只有一个lib文件，没有dll文件，不存在导出一说。


class Solution{

public:
    Solution() {
    }

    virtual ~Solution() {}

    double Add(const double a, const double b);
	
    double Subtraction(const double a, const double b);

};