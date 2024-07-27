
#include"StaticMethod.h"

//�����Ǵ������������
//�������ܣ������ȷ������ѡ������
int getSelectDigit() {
    string input;
    //������һ�εĴ�������
    if (cin.rdbuf()->in_avail() > 0) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    getline(cin, input);//��ȡһ��
    if (input.size() == 0) {
        cout << "����Ϊ��" << endl;
        cout << "����ȷ��������ѡ��" << endl;
        return -1;
    }
    //�����ּ��
    for (char& it : input) {
        if (!isdigit(it)) {
            cout << "->���������<-" << endl;
            cout << "����ȷ��������ѡ��" << endl;
            return -1;
        }
    }
    return stoi(input);
}
//�������ܣ������ȷ���������ʽ
/*
* count��һ������Ӧ���е��ַ�������
*/
vector<string> getInputLine() {
    string input;
    if (cin.rdbuf()->in_avail() > 0) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    getline(cin, input);//��ȡһ��
    //ת��������
    istringstream iss(input);
    string temp;
    vector<string> res;
    while (iss >> temp) {
        res.push_back(temp);
    }
    return res;
}
//�������ܣ����һ��û�пո������
string getInputStringLine() {
    string input;
    if (cin.rdbuf()->in_avail() > 0) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    getline(cin, input);//��ȡһ��
    for (char& it : input) {
        if (it == ' ') {
            cout << "###���������,���벻���пո�##" << endl;
            return "";
        }
    }
    return input;
}
//��õ�¼����
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
//���һ���ַ�
char getInputChar() {
    string input;
    if (cin.rdbuf()->in_avail() > 0) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    getline(cin, input);//��ȡһ��
    if (input.length() == 1)
    {
        return input[0];
    }
    return ' ';
}