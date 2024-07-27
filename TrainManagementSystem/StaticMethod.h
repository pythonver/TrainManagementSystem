#pragma once
#ifndef StaticMethod_H_
#define StaticMethod_H_
#include"CommonLib.h"
//获得有效的数字选项输入
int getSelectDigit();
//获得有效的一行多数据输入
vector<string> getInputLine();
//获得一行一个数据的输入
string getInputStringLine();
//隐藏输入的密码
string getLoginPassword();
//获得单个字符
char getInputChar();

#endif // !StaticMethod
