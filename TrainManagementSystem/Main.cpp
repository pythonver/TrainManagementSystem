
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
		cout << "������" << endl << endl;
		cout << "1 ע��" << endl;
		cout << "2 ��¼" << endl;
		cout << "3 �޸����롢�ܱ�" << endl;
		cout << "Q �˳����" << endl;
		if (counter != 0)
		{
			//cout << "���������ѡ��";
			cout << "###�����ѡ����������ѡ������ѡ��###" << endl;
		}
		cout << "���������ѡ��";
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