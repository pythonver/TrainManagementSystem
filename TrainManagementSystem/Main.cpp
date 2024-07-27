
#include"Login.h"
#include"Registered.h"
#include"ChangeAccountInformation.h"

void mainInterface();
int main()
{
	mainInterface();
	return 0;
}

void mainInterface()
{
	int counter = 0;
	while (1)
	{
		system("cls");
		cout << "主界面" << endl << endl;
		cout << "1 注册" << endl;
		cout << "2 登录" << endl;
		cout << "3 修改密码、密保" << endl;
		cout << "Q 退出软件" << endl;
		if (counter != 0)
		{
			//cout << "请输入你的选择：";
			cout << "###错误的选项，请根据以上选项输入选择###" << endl;
		}
		cout << "请输入你的选择：";
		char MIchoice;
		//cin >> MIchoice;
		MIchoice = getInputChar();
		switch (MIchoice)
		{
		case '1':
			registered();
			counter = 0;
			break;
		case '2':
			login();
			counter = 0;
			break;
		case '3':
			modifyInformation();
			counter = 0;
			break;
		case 'Q':
		case 'q':
			return;
			break;
		default:
			counter++;
			break;
		}
	}
}