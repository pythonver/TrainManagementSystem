
#include"StaticMethod.h"

//以下是错误输入检测机制
//函数功能：获得正确的数字选项输入
int getSelectDigit() {
    string input;
    //忽略上一次的错误输入
    if (cin.rdbuf()->in_avail() > 0) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    getline(cin, input);//读取一行
    if (input.size() == 0) {
        cout << "输入为空" << endl;
        cout << "请正确输入数字选项" << endl;
        return -1;
    }
    //非数字检测
    for (char& it : input) {
        if (!isdigit(it)) {
            cout << "->错误的输入<-" << endl;
            cout << "请正确输入数字选项" << endl;
            return -1;
        }
    }
    return stoi(input);
}
//函数功能，获得正确的行输入格式
/*
* count：一行输入应该有的字符串个数
*/
vector<string> getInputLine() {
    string input;
    if (cin.rdbuf()->in_avail() > 0) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    getline(cin, input);//读取一行
    //转换输入流
    istringstream iss(input);
    string temp;
    vector<string> res;
    while (iss >> temp) {
        res.push_back(temp);
    }
    return res;
}
//函数功能：获得一行没有空格的输入
string getInputStringLine() {
    string input;
    if (cin.rdbuf()->in_avail() > 0) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    getline(cin, input);//读取一行
    for (char& it : input) {
        if (it == ' ') {
            cout << "###错误的输入,输入不能有空格##" << endl;
            return "";
        }
    }
    return input;
}
//获得登录密码
string getLoginPassword() {
    string pwd;
    char c;
    while ((c = _getch()) != 13) {
        if (c == 8) {
            cout << '\b';
            cout << " ";
            cout << '\b';
            if (pwd.length() > 0)
                pwd = pwd.substr(0, pwd.length() - 1);
        }
        else{
            pwd += c;
            putchar('*');
        }
    }
    return pwd;
}
//获得一个字符
char getInputChar() {
    string input;
    if (cin.rdbuf()->in_avail() > 0) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    getline(cin, input);//读取一行
    if (input.length() == 1)
    {
        return input[0];
    }
    return ' ';
}