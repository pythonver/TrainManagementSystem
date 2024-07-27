#pragma once
#ifndef CHANGEACCOUNTINFORMATION_H_
#define CHANGEACCOUNTINFORMATION_H_
#include"Login.h"

void modifyInformation();

void addAdministrators(LoginLink* );

void displayAdministrators(LoginLink* );

void appointmentAdministrators(LoginLink* );

void deleteAdministrators(LoginLink* );

void passwordChange(string, LoginLink* , LoginLink* );

void confidentialChange(string, LoginLink* , LoginLink* );

void passwordPassword(string , LoginLink* , LoginLink* );

void confidentialPassword(string , LoginLink* , LoginLink* );

void passwordConfidential(string , LoginLink* , LoginLink* );

void confidentialConfidential(string , LoginLink* , LoginLink* );

int detectPassword(string , LoginLink* , string , LoginLink* );

int detectConfidential(string , LoginLink* , string , LoginLink* );

void newPassword(string , LoginLink* , LoginLink* );

void newConfidential(string , LoginLink* , LoginLink*);

#endif // !CHANGEACCOUNTINFORMATION_H_
