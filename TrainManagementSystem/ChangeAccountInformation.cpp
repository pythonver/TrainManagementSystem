
#include"ChangeAccountInformation.h"

/*
账户信息修改界面
输入用户名并检测用户名是否存在
根据选择进入不同界面
*/

void modifyInformation()
{
	//输入用户名并检测用户名是否存在
	LoginLink* head1 = new LoginLink();
	head1->next = NULL;
	LoginLink* current;
	string modifyInformationUsername;
	int counter = 0;
	while (1)
	{
		if (counter == 0)
		{
			system("cls");
			cout << "主界面》修改密码、密保" << endl << endl;
			cout << "**输入Q返回主界面**" << endl;
			cout << "请输入用户名：";
		}
		else
		{
			system("cls");
			cout << "主界面》修改密码、密保" << endl << endl;
			cout << "**输入Q返回主界面**" << endl;
			cout << "用户名不存在，请重新输入你的用户名：";
		}
		cin >> modifyInformationUsername;
		if (modifyInformationUsername == "Q" || modifyInformationUsername == "q")
		{
			return;
		}
		//检测用户名是否重复
		//读取到链表里

		ifstream ifs;
		ifs.open("AcountLibrary.txt", ios::in);
		string username, password, confidential, grade;
		while (ifs >> username >> password >> confidential >> grade)
		{
			Insert(head1, username, password, confidential, grade);
		}
		ifs.close();

		current = head1->next;
		while (current != NULL)//检测用户名存不存在
		{
			if (current->Username == modifyInformationUsername)
			{
				break;
			}
			current = current->next;
		}
		if (current == NULL)//不存在
		{
			counter++;
		}
		else//存在
		{
			break;
		}
	}

	int counter1 = 0;
	char modifyInformationUsernameSelect;
	while (1)
	{
		if (counter1 == 0)
		{
			system("cls");
			cout << "主界面》修改密码、密保" << endl << endl;
			cout << "**输入Q返回主界面**" << endl;
			cout << "当前用户：" << modifyInformationUsername << endl;
			cout << "1 修改密码" << endl;
			cout << "2 修改密保" << endl;
			cout << "请输入你的选择：" << endl;
		}
		else
		{
			system("cls");
			cout << "主界面》修改密码、密保" << endl << endl;
			cout << "**输入Q返回主界面**" << endl;
			cout << "当前用户：" << modifyInformationUsername << endl;
			cout << "1 修改密码" << endl;
			cout << "2 修改密保" << endl;
			cout << "###错误的选项，请根据以上选项输入选择###" << endl;
			cout << "请输入你的选择：" << endl;
		}
		cin >> modifyInformationUsernameSelect;
		if (modifyInformationUsernameSelect == 'Q' || modifyInformationUsernameSelect == 'q')
		{
			return;
		}
		switch (modifyInformationUsernameSelect)//根据选择进入不同界面
		{
		case '1':
			passwordChange(modifyInformationUsername, current, head1);
			counter1 = 0;
			break;
		case '2':
			confidentialChange(modifyInformationUsername, current, head1);
			counter1 = 0;
			break;
		default:
			counter1++;
			break;
		}
	}
}

void passwordChange(string modifyInformationUsername, LoginLink* current, LoginLink* head1)//修改密码
{
	int counter = 0;
	while (1)
	{
		if (counter == 0)
		{
			system("cls");
			cout << "主界面》修改密码、密保》修改密码" << endl << endl;
			cout << "**输入Q返回上一界面**" << endl;
			cout << "当前用户：" << modifyInformationUsername << endl;
			cout << "1 用原密码修改密码" << endl;
			cout << "2 用密保修改密码" << endl;
			cout << "请输入你的选择：";
		}
		else
		{
			system("cls");
			cout << "主界面》修改密码、密保》修改密码" << endl << endl;
			cout << "**输入Q返回上一界面**" << endl;
			cout << "当前用户：" << modifyInformationUsername << endl;
			cout << "1 用原密码修改密码" << endl;
			cout << "2 用密保修改密码" << endl;
			cout << "###错误的选项，请根据以上选项输入选择###" << endl;
			cout << "请输入你的选择：";
		}
		char passwordChangeSelect;
		cin >> passwordChangeSelect;
		if (passwordChangeSelect == 'Q' || passwordChangeSelect == 'q')
		{
			return;
		}
		switch (passwordChangeSelect)//根据选择进入不同界面
		{
		case '1':
			passwordPassword(modifyInformationUsername, current, head1);
			counter = 0;
			break;
		case '2':
			confidentialPassword(modifyInformationUsername, current, head1);
			counter = 0;
			break;
		default:
			counter++;
			break;
		}
	}
}

void confidentialChange(string modifyInformationUsername, LoginLink* current, LoginLink* head1)//修改密保
{
	int counter = 0;
	while (1)
	{
		if (counter == 0)
		{
			system("cls");
			cout << "主界面》修改密码、密保》修改密保" << endl << endl;
			cout << "**输入Q返回上一界面**" << endl;
			cout << "当前用户：" << modifyInformationUsername << endl;
			cout << "1 用原密码修改密保" << endl;
			cout << "2 用密保修改密保" << endl;
			cout << "请输入你的选择：";
		}
		else
		{
			system("cls");
			cout << "主界面》修改密码、密保》修改密保" << endl << endl;
			cout << "**输入Q返回上一界面**" << endl;
			cout << "当前用户：" << modifyInformationUsername << endl;
			cout << "1 用原密码修改密保" << endl;
			cout << "2 用密保修改密保" << endl;
			cout << "###错误的选项，请根据以上选项输入选择###" << endl;
			cout << "请输入你的选择：";
		}
		char confidentialChangeSelect;
		cin >> confidentialChangeSelect;
		if (confidentialChangeSelect == 'Q' || confidentialChangeSelect == 'q')
		{
			return;
		}
		switch (confidentialChangeSelect)//根据选择进入不同界面
		{
		case '1':
			passwordConfidential(modifyInformationUsername, current, head1);
			counter = 0;
			break;
		case '2':
			confidentialConfidential(modifyInformationUsername, current, head1);
			counter = 0;
			break;
		default:
			counter++;
			break;
		}
	}
}

void passwordPassword(string modifyInformationUsername, LoginLink* current, LoginLink* head1)//通过原密码修改密码
{
	int counter = 0;
	while (1)
	{
		if (counter == 0)
		{
			system("cls");
			cout << "主界面》修改密码、密保》修改密码》通过原密码修改密码" << endl << endl;
			cout << "**输入Q返回上一界面**" << endl;
			cout << "当前用户：" << modifyInformationUsername << endl;
			cout << "请输入你的原密码：";
		}
		else
		{
			system("cls");
			cout << "主界面》修改密码、密保》修改密码》通过原密码修改密码" << endl << endl;
			cout << "**输入Q返回上一界面**" << endl;
			cout << "当前用户：" << modifyInformationUsername << endl;
			cout << "原密码错误，请再次输入你的原密码：";
		}
		string originalPassword;
		cin >> originalPassword;
		if (originalPassword == "Q" || originalPassword == "q")
		{
			return;
		}
		if (detectPassword(modifyInformationUsername, current, originalPassword, head1))
		{
			newPassword(modifyInformationUsername, current, head1);
			return;
		}
		else
		{
			counter++;
		}
	}
}

void confidentialPassword(string modifyInformationUsername, LoginLink* current, LoginLink* head1)//通过密保修改密码
{
	int counter = 0;
	while (1)
	{
		if (counter == 0)
		{
			system("cls");
			cout << "主界面》修改密码、密保》修改密码》通过密保修改密码" << endl << endl;
			cout << "**输入Q返回上一界面**" << endl;
			cout << "当前用户：" << modifyInformationUsername << endl;
			cout << "请输入你的密保：";
		}
		else
		{
			system("cls");
			cout << "主界面》修改密码、密保》修改密码》通过密保修改密码" << endl << endl;
			cout << "**输入Q返回上一界面**" << endl;
			cout << "当前用户：" << modifyInformationUsername << endl;
			cout << "密保错误，请再次输入你的密保：";
		}
		string originalConfidential;
		cin >> originalConfidential;
		if (originalConfidential == "Q" || originalConfidential == "q")
		{
			return;
		}
		if (detectConfidential(modifyInformationUsername, current, originalConfidential, head1))
		{
			newPassword(modifyInformationUsername, current, head1);
			return;
		}
		else
		{
			counter++;
		}
	}
}

void passwordConfidential(string modifyInformationUsername, LoginLink* current, LoginLink* head1)//通过原密码修改密保
{
	int counter = 0;
	while (1)
	{
		if (counter == 0)
		{
			system("cls");
			cout << "主界面》修改密码、密保》修改密保》通过原密码修改密保" << endl << endl;
			cout << "**输入Q返回上一界面**" << endl;
			cout << "当前用户：" << modifyInformationUsername << endl;
			cout << "请输入你的原密码：";
		}
		else
		{
			system("cls");
			cout << "主界面》修改密码、密保》修改密保》通过原密码修改密保" << endl << endl;
			cout << "**输入Q返回上一界面**" << endl;
			cout << "当前用户：" << modifyInformationUsername << endl;
			cout << "原密码错误，请再次输入你的原密码：";
		}
		string originalPassword;
		cin >> originalPassword;
		if (originalPassword == "Q" || originalPassword == "q")
		{
			return;
		}
		if (detectPassword(modifyInformationUsername, current, originalPassword, head1))
		{
			newConfidential(modifyInformationUsername, current, head1);
			return;
		}
		else
		{
			counter++;
		}
	}
}

void confidentialConfidential(string modifyInformationUsername, LoginLink* current, LoginLink* head1)//通过密保修改密保
{
	int counter = 0;
	while (1)
	{
		if (counter == 0)
		{
			system("cls");
			cout << "主界面》修改密码、密保》修改密保》通过密保修改密保" << endl << endl;
			cout << "**输入Q返回上一界面**" << endl;
			cout << "当前用户：" << modifyInformationUsername << endl;
			cout << "请输入你的密保：";
		}
		else
		{
			system("cls");
			cout << "主界面》修改密码、密保》修改密保》通过密保修改密保" << endl << endl;
			cout << "**输入Q返回上一界面**" << endl;
			cout << "当前用户：" << modifyInformationUsername << endl;
			cout << "密保错误，请再次输入你的密保：";
		}
		string originalConfidential;
		cin >> originalConfidential;
		if (originalConfidential == "Q" || originalConfidential == "q")
		{
			return;
		}
		if (detectConfidential(modifyInformationUsername, current, originalConfidential, head1))
		{
			newConfidential(modifyInformationUsername, current, head1);
			return;
		}
		else
		{
			counter++;
		}
	}
}

//输入原密码检测原密码是否正确
int detectPassword(string modifyInformationUsername, LoginLink* current, string originalPassword, LoginLink* head1)
{
	if (originalPassword == current->Password)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//输入密保并检测密保是否正确
int detectConfidential(string modifyInformationUsername, LoginLink* current, string originalConfidential, LoginLink* head1)
{
	if (originalConfidential == current->Confidential)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//输入新密码
void newPassword(string modifyInformationUsername, LoginLink* current, LoginLink* head1)
{
	string Confidentiall, SecondPassword, Trash;
	//输入密码
	system("cls");
	cout << "主界面》修改密码、密保》修改密码》输入新密码" << endl << endl;
	cout << "**输入Q返回上一层**" << endl;
	cout << "当前用户：" << modifyInformationUsername << endl;
	cout << "请输入你的新密码：";
	getline(cin, Trash);
	getline(cin, Confidentiall);
	if (Confidentiall == "Q" || Confidentiall == "q")
	{
		return;
	}
	while (1)//检测密码是否有空格
	{
		int counter2 = 0;
		for (char detection : Confidentiall)
		{
			if (detection == ' ')
			{
				counter2++;
			}
		}
		if (counter2 != 0)
		{
			system("cls");
			cout << "主界面》修改密码、密保》修改密码》输入新密码" << endl << endl;
			cout << "**输入Q返回上一层**" << endl;
			cout << "当前用户：" << modifyInformationUsername << endl;
			cout << "密码不能含有空格，请重新输入：";
			//cin >> Password;
			getline(cin, Confidentiall);
			if (Confidentiall == "Q" || Confidentiall == "q")
			{
				return;
			}
		}
		else//没有空格的情况，跳出while循环
		{
			break;
		}
	}

	//二次输入密码
	system("cls");
	cout << "主界面》修改密码、密保》修改密码》输入新密码" << endl << endl;
	cout << "**输入Q返回上一层**" << endl;
	cout << "当前用户：" << modifyInformationUsername << endl;
	cout << "请再次输入密码：";
	getline(cin, SecondPassword);
	if (SecondPassword == "Q" || SecondPassword == "q")
	{
		return;
	}
	while (1)//检测密码是否一致
	{
		if (SecondPassword == Confidentiall)
		{
			break;
		}
		else
		{
			system("cls");
			cout << "主界面》修改密码、密保》修改密码》输入新密码" << endl << endl;
			cout << "**输入Q返回上一层**" << endl;
			cout << "当前用户：" << modifyInformationUsername << endl;
			cout << "密码与第一次不一致，请重新输入：";
			getline(cin, SecondPassword);
			if (SecondPassword == "Q" || SecondPassword == "q")
			{
				return;
			}
		}
	}

	//存入文件
	current->Password = SecondPassword;
	ofstream ofs;
	ofs.open("AcountLibrary.txt", ios::out);
	LoginLink* now = head1->next;
	while (now != NULL)
	{
		ofs << now->Username << " " << now->Password << " " << now->Confidential << " " << now->Grade << endl;
		now = now->next;
	}
	ofs.close();

	system("cls");
	cout << "主界面》修改密码、密保》修改密码》输入新密码" << endl << endl;
	cout << "**输入Q返回上一层**" << endl;
	cout << "当前用户：" << modifyInformationUsername << endl << endl;;
	cout << "密码已修改为 " << SecondPassword << endl;
	system("pause");
	return;
}

//输入新密保
void newConfidential(string modifyInformationUsername, LoginLink* current, LoginLink* head1)
{
	string Password, SecondConfidential, Trash;
	//输入密保
	system("cls");
	cout << "主界面》修改密码、密保》修改密保》输入新密保" << endl << endl;
	cout << "**输入Q返回上一层**" << endl;
	cout << "当前用户：" << modifyInformationUsername << endl;
	cout << "请输入你的新密保：";
	getline(cin, Trash);
	getline(cin, Password);
	if (Password == "Q" || Password == "q")
	{
		return;
	}
	while (1)//检测密码是否有空格
	{
		int counter2 = 0;
		for (char detection : Password)
		{
			if (detection == ' ')
			{
				counter2++;
			}
		}
		if (counter2 != 0)
		{
			system("cls");
			cout << "主界面》修改密码、密保》修改密保》输入新密保" << endl << endl;
			cout << "**输入Q返回上一层**" << endl;
			cout << "当前用户：" << modifyInformationUsername << endl;
			cout << "密保不能含有空格，请重新输入：";
			//cin >> Password;
			getline(cin, Password);
			if (Password == "Q" || Password == "q")
			{
				return;
			}
		}
		else//没有空格的情况，跳出while循环
		{
			break;
		}
	}

	//二次输入密码
	system("cls");
	cout << "主界面》修改密码、密保》修改密保》输入新密保" << endl << endl;
	cout << "**输入Q返回上一层**" << endl;
	cout << "当前用户：" << modifyInformationUsername << endl;
	cout << "请再次输入密保：";
	getline(cin, SecondConfidential);
	if (SecondConfidential == "Q" || SecondConfidential == "q")
	{
		return;
	}
	while (1)//检测密码是否一致
	{
		if (SecondConfidential == Password)
		{
			break;
		}
		else
		{
			system("cls");
			cout << "主界面》修改密码、密保》修改密保》输入新密保" << endl << endl;
			cout << "**输入Q返回上一层**" << endl;
			cout << "当前用户：" << modifyInformationUsername << endl;
			cout << "密保与第一次不一致，请重新输入：";
			getline(cin, SecondConfidential);
			if (SecondConfidential == "Q" || SecondConfidential == "q")
			{
				return;
			}
		}
	}

	//存入文件
	current->Confidential = SecondConfidential;
	ofstream ofs;
	ofs.open("AcountLibrary.txt", ios::out);
	LoginLink* now = head1->next;
	while (now != NULL)
	{
		ofs << now->Username << " " << now->Password << " " << now->Confidential << " " << now->Grade << endl;
		now = now->next;
	}
	ofs.close();

	system("cls");
	cout << "主界面》修改密码、密保》修改密保》输入新密保" << endl << endl;
	cout << "**输入Q返回上一层**" << endl;
	cout << "当前用户：" << modifyInformationUsername << endl << endl;;
	cout << "密保已修改为 " << SecondConfidential << endl;
	system("pause");
	return;
}