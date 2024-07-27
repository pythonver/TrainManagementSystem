
#include"Registered.h"

/*
�����û���
����û����Ƿ��пո�
����û����Ƿ��ظ�
��������
��������Ƿ��пո�
������������
��������Ƿ�һ��
�����ܱ�
����ܱ��Ƿ��пո�
������ĵ�
�ص���һ��
*/
//�ж��Ƿ��Ѵ����˺���
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
	while (current != NULL)//����û����治����
	{
		if (current->Username == accountName)
		{
			cout << "�û����Ѵ���,";
			return true;
		}
		current = current->next;
	}
	
	return false;
}
//��ȡע���û���
string getAccountName() {
	system("cls");
	cout << "�����桷ע��" << endl << endl;
	cout << "**����Q����������**" << endl;
	cout << "����������û���:";
	string userName;
	while (true) {
		userName = getInputStringLine();
		if (userName.length() == 1 && (userName[0] == 'q' || userName[0] == 'Q'))
			break;
		if (userName != "" && !hasAccountName(userName))
			break;
		cout << "���������û���:";
	}
	//��ѯ�Ƿ����
	return userName;
}
string getAccountPassword() {
	system("cls");
	cout << "�����桷ע��" << endl << endl;
	cout << "**����Q����������**" << endl;
	cout << "������������룺";
	string password;
	while (true){
		password = getInputStringLine();
		if (password.length() == 1 && (password[0] == 'q' || password[0] == 'Q'))
			break;
		if (password != "")
			break;
		cout << "��������������:";
	}
	return password;
}
bool passwordMatching(string originalPassword) {
	string secondaryPassword;
	system("cls");
	cout << "�����桷ע��" << endl << endl;
	cout << "**����Q����������**" << endl;
	cout << "���ٴ��������룺";
	while (true) {
		getline(cin, secondaryPassword);
		cout << secondaryPassword.length() << " " << secondaryPassword;
		if (secondaryPassword.length() == 1 && (secondaryPassword[0] == 'q' || secondaryPassword[1] == 'Q'))
			break;
		if (secondaryPassword != "" && secondaryPassword == originalPassword)
			return true;
		cout << "�������벻һ��,��������������:";
	}
	return false;//
}
string getAccountSecurity() {
	system("cls");
	cout << "�����桷ע��" << endl << endl;
	cout << "**����Q����������**" << endl;
	cout << "����������ܱ�:";
	string security;
	while (true){
		security = getInputStringLine();
		if (security.length() == 1 && (security[0] == 'q' || security[1] == 'Q'))
			break;
		if (security != "")
			break;
		cout << "�����������ܱ�:";
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

	//�����ı�
	//������ĵ�
	ofstream ofs;
	ofs.open("AcountLibrary.txt", ios::app);
	ofs << userName << " " << password << " " << security << " " << "3" << endl;//�û��������롢�ܱ���Ĭ�ϵȼ�3
	ofs.close();

	system("cls");
	cout << "�����桷ע��" << endl << endl;
	cout << "ע��ɹ���";
	system("pause");
}