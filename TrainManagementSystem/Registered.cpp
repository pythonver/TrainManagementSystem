
#include"Registered.h"

/*
输入用户名
检测用户名是否有空格
检测用户名是否重复
输入密码
检测密码是否有空格
二次输入密码
检测密码是否一致
输入密保
检测密保是否有空格
保存进文档
回到上一层
*/
//判断是否已存在账号名
bool hasAccountName(string accountName) {
	string userName;
	LoginLink* head = new LoginLink();
	head->next = NULL;
	ifstream ifs;
	ifs.open("AcountLibrary.txt", ios::in);
	string username, password, confidential, grade;
	while (ifs >> username >> password >> confidential >> grade)
	{
		Insert(head, username, password, confidential, grade);
	}
	ifs.close();

	LoginLink* current;
	current = head->next;
	while (current != NULL)//检测用户名存不存在
	{
		if (current->Username == accountName)
		{
			cout << "用户名已存在,";
			return true;
		}
		current = current->next;
	}
	
	return false;
}
//获取注册用户名
string getAccountName() {
	system("cls");
	cout << "主界面》注册" << endl << endl;
	cout << "**输入Q返回主界面**" << endl;
	cout << "请输入你的用户名:";
	string userName;
	while (true) {
		userName = getInputStringLine();
		if (userName.length() == 1 && (userName[0] == 'q' || userName[0] == 'Q'))
			break;
		if (userName != "" && !hasAccountName(userName))
			break;
		cout << "重新输入用户名:";
	}
	//查询是否存在
	return userName;
}
string getAccountPassword() {
	system("cls");
	cout << "主界面》注册" << endl << endl;
	cout << "**输入Q返回主界面**" << endl;
	cout << "请输入你的密码：";
	string password;
	while (true){
		password = getInputStringLine();
		if (password.length() == 1 && (password[0] == 'q' || password[0] == 'Q'))
			break;
		if (password != "")
			break;
		cout << "请重新输入密码:";
	}
	return password;
}
bool passwordMatching(string originalPassword) {
	string secondaryPassword;
	system("cls");
	cout << "主界面》注册" << endl << endl;
	cout << "**输入Q返回主界面**" << endl;
	cout << "请再次输入密码：";
	while (true) {
		getline(cin, secondaryPassword);
		cout << secondaryPassword.length() << " " << secondaryPassword;
		if (secondaryPassword.length() == 1 && (secondaryPassword[0] == 'q' || secondaryPassword[1] == 'Q'))
			break;
		if (secondaryPassword != "" && secondaryPassword == originalPassword)
			return true;
		cout << "两次密码不一致,请重新输入密码:";
	}
	return false;//
}
string getAccountSecurity() {
	system("cls");
	cout << "主界面》注册" << endl << endl;
	cout << "**输入Q返回主界面**" << endl;
	cout << "请输入你的密保:";
	string security;
	while (true){
		security = getInputStringLine();
		if (security.length() == 1 && (security[0] == 'q' || security[1] == 'Q'))
			break;
		if (security != "")
			break;
		cout << "请重新输入密保:";
	}
	return security;
}
void registered()
{
	string userName, password, security;
	int Counter = 0;
	int count = 1;
	userName = getAccountName();
	if (userName == "Q" || userName == "q")
		return;

	password = getAccountPassword();
	if (password == "Q" || password == "q")
		return;

	if (!passwordMatching(password))
		return;
	
	security = getAccountSecurity();
	if (security == "Q" || security == "q")
		return;

	//存入文本
	//保存进文档
	ofstream ofs;
	ofs.open("AcountLibrary.txt", ios::app);
	ofs << userName << " " << password << " " << security << " " << "3" << endl;//用户名、密码、密保、默认等级3
	ofs.close();

	system("cls");
	cout << "主界面》注册" << endl << endl;
	cout << "注册成功。";
	system("pause");
}