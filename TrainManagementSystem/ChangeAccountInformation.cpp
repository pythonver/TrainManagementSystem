
#include"ChangeAccountInformation.h"

/*
�˻���Ϣ�޸Ľ���
�����û���������û����Ƿ����
����ѡ����벻ͬ����
*/

void modifyInformation()
{
	//�����û���������û����Ƿ����
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
			cout << "�����桷�޸����롢�ܱ�" << endl << endl;
			cout << "**����Q����������**" << endl;
			cout << "�������û�����";
		}
		else
		{
			system("cls");
			cout << "�����桷�޸����롢�ܱ�" << endl << endl;
			cout << "**����Q����������**" << endl;
			cout << "�û��������ڣ���������������û�����";
		}
		cin >> modifyInformationUsername;
		if (modifyInformationUsername == "Q" || modifyInformationUsername == "q")
		{
			return;
		}
		//����û����Ƿ��ظ�
		//��ȡ��������

		ifstream ifs;
		ifs.open("AcountLibrary.txt", ios::in);
		string username, password, confidential, grade;
		while (ifs >> username >> password >> confidential >> grade)
		{
			Insert(head1, username, password, confidential, grade);
		}
		ifs.close();

		current = head1->next;
		while (current != NULL)//����û����治����
		{
			if (current->Username == modifyInformationUsername)
			{
				break;
			}
			current = current->next;
		}
		if (current == NULL)//������
		{
			counter++;
		}
		else//����
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
			cout << "�����桷�޸����롢�ܱ�" << endl << endl;
			cout << "**����Q����������**" << endl;
			cout << "��ǰ�û���" << modifyInformationUsername << endl;
			cout << "1 �޸�����" << endl;
			cout << "2 �޸��ܱ�" << endl;
			cout << "���������ѡ��" << endl;
		}
		else
		{
			system("cls");
			cout << "�����桷�޸����롢�ܱ�" << endl << endl;
			cout << "**����Q����������**" << endl;
			cout << "��ǰ�û���" << modifyInformationUsername << endl;
			cout << "1 �޸�����" << endl;
			cout << "2 �޸��ܱ�" << endl;
			cout << "###�����ѡ����������ѡ������ѡ��###" << endl;
			cout << "���������ѡ��" << endl;
		}
		cin >> modifyInformationUsernameSelect;
		if (modifyInformationUsernameSelect == 'Q' || modifyInformationUsernameSelect == 'q')
		{
			return;
		}
		switch (modifyInformationUsernameSelect)//����ѡ����벻ͬ����
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

void passwordChange(string modifyInformationUsername, LoginLink* current, LoginLink* head1)//�޸�����
{
	int counter = 0;
	while (1)
	{
		if (counter == 0)
		{
			system("cls");
			cout << "�����桷�޸����롢�ܱ����޸�����" << endl << endl;
			cout << "**����Q������һ����**" << endl;
			cout << "��ǰ�û���" << modifyInformationUsername << endl;
			cout << "1 ��ԭ�����޸�����" << endl;
			cout << "2 ���ܱ��޸�����" << endl;
			cout << "���������ѡ��";
		}
		else
		{
			system("cls");
			cout << "�����桷�޸����롢�ܱ����޸�����" << endl << endl;
			cout << "**����Q������һ����**" << endl;
			cout << "��ǰ�û���" << modifyInformationUsername << endl;
			cout << "1 ��ԭ�����޸�����" << endl;
			cout << "2 ���ܱ��޸�����" << endl;
			cout << "###�����ѡ����������ѡ������ѡ��###" << endl;
			cout << "���������ѡ��";
		}
		char passwordChangeSelect;
		cin >> passwordChangeSelect;
		if (passwordChangeSelect == 'Q' || passwordChangeSelect == 'q')
		{
			return;
		}
		switch (passwordChangeSelect)//����ѡ����벻ͬ����
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

void confidentialChange(string modifyInformationUsername, LoginLink* current, LoginLink* head1)//�޸��ܱ�
{
	int counter = 0;
	while (1)
	{
		if (counter == 0)
		{
			system("cls");
			cout << "�����桷�޸����롢�ܱ����޸��ܱ�" << endl << endl;
			cout << "**����Q������һ����**" << endl;
			cout << "��ǰ�û���" << modifyInformationUsername << endl;
			cout << "1 ��ԭ�����޸��ܱ�" << endl;
			cout << "2 ���ܱ��޸��ܱ�" << endl;
			cout << "���������ѡ��";
		}
		else
		{
			system("cls");
			cout << "�����桷�޸����롢�ܱ����޸��ܱ�" << endl << endl;
			cout << "**����Q������һ����**" << endl;
			cout << "��ǰ�û���" << modifyInformationUsername << endl;
			cout << "1 ��ԭ�����޸��ܱ�" << endl;
			cout << "2 ���ܱ��޸��ܱ�" << endl;
			cout << "###�����ѡ����������ѡ������ѡ��###" << endl;
			cout << "���������ѡ��";
		}
		char confidentialChangeSelect;
		cin >> confidentialChangeSelect;
		if (confidentialChangeSelect == 'Q' || confidentialChangeSelect == 'q')
		{
			return;
		}
		switch (confidentialChangeSelect)//����ѡ����벻ͬ����
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

void passwordPassword(string modifyInformationUsername, LoginLink* current, LoginLink* head1)//ͨ��ԭ�����޸�����
{
	int counter = 0;
	while (1)
	{
		if (counter == 0)
		{
			system("cls");
			cout << "�����桷�޸����롢�ܱ����޸����롷ͨ��ԭ�����޸�����" << endl << endl;
			cout << "**����Q������һ����**" << endl;
			cout << "��ǰ�û���" << modifyInformationUsername << endl;
			cout << "���������ԭ���룺";
		}
		else
		{
			system("cls");
			cout << "�����桷�޸����롢�ܱ����޸����롷ͨ��ԭ�����޸�����" << endl << endl;
			cout << "**����Q������һ����**" << endl;
			cout << "��ǰ�û���" << modifyInformationUsername << endl;
			cout << "ԭ����������ٴ��������ԭ���룺";
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

void confidentialPassword(string modifyInformationUsername, LoginLink* current, LoginLink* head1)//ͨ���ܱ��޸�����
{
	int counter = 0;
	while (1)
	{
		if (counter == 0)
		{
			system("cls");
			cout << "�����桷�޸����롢�ܱ����޸����롷ͨ���ܱ��޸�����" << endl << endl;
			cout << "**����Q������һ����**" << endl;
			cout << "��ǰ�û���" << modifyInformationUsername << endl;
			cout << "����������ܱ���";
		}
		else
		{
			system("cls");
			cout << "�����桷�޸����롢�ܱ����޸����롷ͨ���ܱ��޸�����" << endl << endl;
			cout << "**����Q������һ����**" << endl;
			cout << "��ǰ�û���" << modifyInformationUsername << endl;
			cout << "�ܱ��������ٴ���������ܱ���";
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

void passwordConfidential(string modifyInformationUsername, LoginLink* current, LoginLink* head1)//ͨ��ԭ�����޸��ܱ�
{
	int counter = 0;
	while (1)
	{
		if (counter == 0)
		{
			system("cls");
			cout << "�����桷�޸����롢�ܱ����޸��ܱ���ͨ��ԭ�����޸��ܱ�" << endl << endl;
			cout << "**����Q������һ����**" << endl;
			cout << "��ǰ�û���" << modifyInformationUsername << endl;
			cout << "���������ԭ���룺";
		}
		else
		{
			system("cls");
			cout << "�����桷�޸����롢�ܱ����޸��ܱ���ͨ��ԭ�����޸��ܱ�" << endl << endl;
			cout << "**����Q������һ����**" << endl;
			cout << "��ǰ�û���" << modifyInformationUsername << endl;
			cout << "ԭ����������ٴ��������ԭ���룺";
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

void confidentialConfidential(string modifyInformationUsername, LoginLink* current, LoginLink* head1)//ͨ���ܱ��޸��ܱ�
{
	int counter = 0;
	while (1)
	{
		if (counter == 0)
		{
			system("cls");
			cout << "�����桷�޸����롢�ܱ����޸��ܱ���ͨ���ܱ��޸��ܱ�" << endl << endl;
			cout << "**����Q������һ����**" << endl;
			cout << "��ǰ�û���" << modifyInformationUsername << endl;
			cout << "����������ܱ���";
		}
		else
		{
			system("cls");
			cout << "�����桷�޸����롢�ܱ����޸��ܱ���ͨ���ܱ��޸��ܱ�" << endl << endl;
			cout << "**����Q������һ����**" << endl;
			cout << "��ǰ�û���" << modifyInformationUsername << endl;
			cout << "�ܱ��������ٴ���������ܱ���";
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

//����ԭ������ԭ�����Ƿ���ȷ
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

//�����ܱ�������ܱ��Ƿ���ȷ
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

//����������
void newPassword(string modifyInformationUsername, LoginLink* current, LoginLink* head1)
{
	string Confidentiall, SecondPassword, Trash;
	//��������
	system("cls");
	cout << "�����桷�޸����롢�ܱ����޸����롷����������" << endl << endl;
	cout << "**����Q������һ��**" << endl;
	cout << "��ǰ�û���" << modifyInformationUsername << endl;
	cout << "��������������룺";
	getline(cin, Trash);
	getline(cin, Confidentiall);
	if (Confidentiall == "Q" || Confidentiall == "q")
	{
		return;
	}
	while (1)//��������Ƿ��пո�
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
			cout << "�����桷�޸����롢�ܱ����޸����롷����������" << endl << endl;
			cout << "**����Q������һ��**" << endl;
			cout << "��ǰ�û���" << modifyInformationUsername << endl;
			cout << "���벻�ܺ��пո����������룺";
			//cin >> Password;
			getline(cin, Confidentiall);
			if (Confidentiall == "Q" || Confidentiall == "q")
			{
				return;
			}
		}
		else//û�пո�����������whileѭ��
		{
			break;
		}
	}

	//������������
	system("cls");
	cout << "�����桷�޸����롢�ܱ����޸����롷����������" << endl << endl;
	cout << "**����Q������һ��**" << endl;
	cout << "��ǰ�û���" << modifyInformationUsername << endl;
	cout << "���ٴ��������룺";
	getline(cin, SecondPassword);
	if (SecondPassword == "Q" || SecondPassword == "q")
	{
		return;
	}
	while (1)//��������Ƿ�һ��
	{
		if (SecondPassword == Confidentiall)
		{
			break;
		}
		else
		{
			system("cls");
			cout << "�����桷�޸����롢�ܱ����޸����롷����������" << endl << endl;
			cout << "**����Q������һ��**" << endl;
			cout << "��ǰ�û���" << modifyInformationUsername << endl;
			cout << "�������һ�β�һ�£����������룺";
			getline(cin, SecondPassword);
			if (SecondPassword == "Q" || SecondPassword == "q")
			{
				return;
			}
		}
	}

	//�����ļ�
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
	cout << "�����桷�޸����롢�ܱ����޸����롷����������" << endl << endl;
	cout << "**����Q������һ��**" << endl;
	cout << "��ǰ�û���" << modifyInformationUsername << endl << endl;;
	cout << "�������޸�Ϊ " << SecondPassword << endl;
	system("pause");
	return;
}

//�������ܱ�
void newConfidential(string modifyInformationUsername, LoginLink* current, LoginLink* head1)
{
	string Password, SecondConfidential, Trash;
	//�����ܱ�
	system("cls");
	cout << "�����桷�޸����롢�ܱ����޸��ܱ����������ܱ�" << endl << endl;
	cout << "**����Q������һ��**" << endl;
	cout << "��ǰ�û���" << modifyInformationUsername << endl;
	cout << "������������ܱ���";
	getline(cin, Trash);
	getline(cin, Password);
	if (Password == "Q" || Password == "q")
	{
		return;
	}
	while (1)//��������Ƿ��пո�
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
			cout << "�����桷�޸����롢�ܱ����޸��ܱ����������ܱ�" << endl << endl;
			cout << "**����Q������һ��**" << endl;
			cout << "��ǰ�û���" << modifyInformationUsername << endl;
			cout << "�ܱ����ܺ��пո����������룺";
			//cin >> Password;
			getline(cin, Password);
			if (Password == "Q" || Password == "q")
			{
				return;
			}
		}
		else//û�пո�����������whileѭ��
		{
			break;
		}
	}

	//������������
	system("cls");
	cout << "�����桷�޸����롢�ܱ����޸��ܱ����������ܱ�" << endl << endl;
	cout << "**����Q������һ��**" << endl;
	cout << "��ǰ�û���" << modifyInformationUsername << endl;
	cout << "���ٴ������ܱ���";
	getline(cin, SecondConfidential);
	if (SecondConfidential == "Q" || SecondConfidential == "q")
	{
		return;
	}
	while (1)//��������Ƿ�һ��
	{
		if (SecondConfidential == Password)
		{
			break;
		}
		else
		{
			system("cls");
			cout << "�����桷�޸����롢�ܱ����޸��ܱ����������ܱ�" << endl << endl;
			cout << "**����Q������һ��**" << endl;
			cout << "��ǰ�û���" << modifyInformationUsername << endl;
			cout << "�ܱ����һ�β�һ�£����������룺";
			getline(cin, SecondConfidential);
			if (SecondConfidential == "Q" || SecondConfidential == "q")
			{
				return;
			}
		}
	}

	//�����ļ�
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
	cout << "�����桷�޸����롢�ܱ����޸��ܱ����������ܱ�" << endl << endl;
	cout << "**����Q������һ��**" << endl;
	cout << "��ǰ�û���" << modifyInformationUsername << endl << endl;;
	cout << "�ܱ����޸�Ϊ " << SecondConfidential << endl;
	system("pause");
	return;
}