#pragma once
#pragma once
#ifndef REGISTERED_H_
#define REGISTERED_H_
#include"Login.h"
//×¢²áÇý¶¯º¯Êý
void registered();

string getAccountName();
string getAccountPassword();
bool passwordMatching(string originalPassword);
string getAccountSecurity();
void registered();
#endif // !REGISTERED_H_