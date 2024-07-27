#pragma once
#ifndef LOGIN_H_
#define LOGIN_H_
#include"AdministratorMenu.h"
#include"UserMenu.h"
struct LoginLink
{
    string Username, Password, Confidential, Grade;
    LoginLink* next;
};
void Insert(LoginLink* head, string username, string password, string confidential, string grade);
void login();
void user(string Username);
void administrator(string Username);
void seniorAdministrator(string Username, LoginLink* head);
#endif // !LOGIN_H_H
