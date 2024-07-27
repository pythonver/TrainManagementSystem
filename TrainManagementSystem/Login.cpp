#include"Login.h"
#include"ChangeAccountInformation.h"
//��ֹѭ������
/*
��ȡ��������
�����û���
����û����Ƿ����
��������
��������Ƿ���ȷ
���ݵȼ�ѡ����
*/

void Insert(LoginLink* head, string username, string password, string confidential, string grade)
{
	LoginLink* newNode = new LoginLink();
	newNode->Username = username;
	newNode->Password = password;
	newNode->Confidential = confidential;
	newNode->Grade = grade;
	newNode->next = NULL;
	if (head->next == NULL)
	{
		head->next = newNode;
	}
	else
	{
		LoginLink* current = head->next;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = newNode;
	}
}

void login()
{
	//��ȡ��������
	LoginLink* head = new LoginLink();
	head->next = NULL;
	ifstream ifs;
	ifs.open("AcountLibrary.txt", ios::in);
	string userName, password, confidential, grade;
	while (ifs >> userName >> password >> confidential >> grade)
	{
		Insert(head, userName, password, confidential, grade);
	}
	ifs.close();

	//�����û���
	//string userName, password;
	LoginLink* current;
	int counter = 0;
	while (1)
	{
		system("cls");
		cout << "�����桷��¼" << endl << endl;
		cout << "**����Q����������**" << endl;
		if (counter == 0)
		{
			cout << "����������û�����";
		}
		else
		{
			cout << "�û��������ڣ���������������û�����";
		}
		
		//cin >> userName;
		userName = getInputStringLine();
		if (userName == "Q" || userName == "q")//�����Q���Ǿͷ�����һ�㺯��
		{
			return;
		}
		current = head->next;
		while (current != NULL)//����û����治����
		{
			if (current->Username == userName)
			{
				break;
			}
			current = current->next;
		}
		if (current == NULL)
		{
			counter++;
		}
		else
		{
			break;
		}
	}

	//��������
	int counter1 = 0;
	while (1)
	{
		if (counter1 == 0)
		{
			system("cls");
			cout << "�����桷��¼" << endl << endl;
			cout << "**����Q����������**" << endl;
			cout << "������������룺";
		}
		else
		{
			system("cls");
			cout << "�����桷��¼" << endl << endl;
			cout << "**����Q����������**" << endl;
			cout << "��������������������룺";
		}
		//cin >> password;
		password = getLoginPassword();
		if (password == current->Password)//��������Ƿ���ȷ
		{
			if (current->Grade == "3")
			{
				user(userName);
			}
			else if (current->Grade == "2")
			{
				administrator(userName);
			}
			else if (current->Grade == "1")
			{
				seniorAdministrator(userName, head);
			}
			break;
		}
		else
		{
			counter1++;
		}
	}
}

void user(string userName)
{

	// �����û���Ʊ����
	forward_list<trainTicket> trainTicketList;
	//������Ʊ����
	forward_list<yuanTrain> yuanTrainList;

	// ��ʼ���û����������
	initTrainTicketLink(trainTicketList);
	//��ʼ��ԭ����Ϣ������� 
	initYuanTrainLink(yuanTrainList, trainTicketList);

	int counter = 0;
	while (1)
	{
		system("cls");
		cout << "�����桷��¼����ͨ�û�" << endl << endl;
		cout << "**����Q����������**" << endl;
		cout << "1 �鳵��" << endl;
		cout << "2 ��Ʊ" << endl;
		cout << "3 ��Ʊ" << endl;
		cout << "4 ��ǩ" << endl;
		cout << "5 �г̲�ѯ" << endl;
		if (counter != 0)
		{
			cout << "###�����ѡ����������ѡ������ѡ��###" << endl;
		}
		cout << "���������ѡ��";
		char userSelect;
		cin >> userSelect;
		switch (userSelect)
		{
		case '1':
			userFind(yuanTrainList);
			counter = 0;
			break;
		case '2':
			buyTicket(userName, yuanTrainList, trainTicketList);
			counter = 0;
			break;
		case '3':
			deleTicket(trainTicketList, yuanTrainList);
			counter = 0;
			break;
		case '4':
			userChange(trainTicketList, yuanTrainList);
			counter = 0;
			break;
		case '5':
			findItinerary(trainTicketList, yuanTrainList, userName);
			counter = 0;
			break;
		case 'Q':
		case 'q':
			return;
		default:
			counter++;
			break;
		}
	}
}

void administrator(string userName)
{
	forward_list<trainNode> trainList;//����Ϣ����
	unordered_map<string, vector<string>> orderMap;//������Ⱥ��
	string trainFile = "PrimordialInformationBase.txt";//����Ϣ�ļ�
	string orderFile = "TicketBuyersDatabase.txt";//�������ļ�
	if (!initAdmData(trainList, trainFile, orderMap, orderFile)) {
		cout << "�ļ�����ʧ�ܣ�������һ��" << endl;
		system("pause");
		return;
	}

	// �����û���Ʊ����
	forward_list<trainTicket> trainTicketList;
	//������Ʊ����
	forward_list<yuanTrain> yuanTrainList;

	// ��ʼ���û����������
	initTrainTicketLink(trainTicketList);
	//��ʼ��ԭ����Ϣ������� 
	initYuanTrainLink(yuanTrainList, trainTicketList);

	int counter = 0;
	while (1)
	{
		system("cls");
		cout << "�����桷��¼����ͨ����Ա" << endl << endl;
		cout << "**����Q����������**" << endl;
		cout << "1 ��ӳ��μ�������Ϣ" << endl;
		cout << "2 ɾ������" << endl;
		cout << "3 ��ѯ���г���" << endl;
		cout << "4 ��ѯĳ���εĳ˿��б�" << endl;
		cout << "5 �޸ĳ�����Ϣ" << endl;
		cout << "6 �鳵��" << endl;
		cout << "7 ��Ʊ" << endl;
		cout << "8 ��Ʊ" << endl;
		cout << "9 ��ǩ" << endl;
		cout << "w �г̲�ѯ" << endl;
		if (counter != 0)
		{
			cout << "###�����ѡ����������ѡ������ѡ��###" << endl;
			//cout << "���������ѡ��";
		}
		cout << "���������ѡ��";
		char administratorSelect;
		//cin >> administratorSelect;
		administratorSelect = getInputChar();
		switch (administratorSelect)
		{
		case '1':
			if (!addTIF(trainList, orderMap))
				cout << "���ʧ��" << endl;
			counter = 0;
			break;
		case '2':
			eraseTIF(trainList, orderMap);
			counter = 0;
			break;
		case '3':
			showAll(trainList, orderMap);
			counter = 0;
			break;
		case '4':
			showOrder(orderMap);
			counter = 0;
			break;
		case '5':
			reSetTIF(trainList, orderMap);
			counter = 0;
			break;
		case '6':
			userFind(yuanTrainList);
			counter = 0;
			break;
		case '7':
			buyTicket(userName, yuanTrainList, trainTicketList);
			counter = 0;
			break;
		case '8':
			deleTicket(trainTicketList, yuanTrainList);
			counter = 0;
			break;
		case '9':
			userChange(trainTicketList, yuanTrainList);
			counter = 0;
			break;
		case 'w':
			findItinerary(trainTicketList, yuanTrainList, userName);
			counter = 0;
			break;
		case 'Q':
			return;
			break;
		case 'q':
			return;
			break;
		default:
			counter++;
			break;
		}
	}
}

void seniorAdministrator(string userName, LoginLink* head)
{
	forward_list<trainNode> trainList;//����Ϣ����
	unordered_map<string, vector<string>> orderMap;//������Ⱥ��
	string trainFile = "PrimordialInformationBase.txt";//����Ϣ�ļ�
	string orderFile = "TicketBuyersDatabase.txt";//�������ļ�
	if (!initAdmData(trainList, trainFile, orderMap, orderFile)) {
		cout << "�ļ�����ʧ�ܣ�������һ��" << endl;
		system("pause");
		return;
	}

	// �����û���Ʊ����
	forward_list<trainTicket> trainTicketList;
	//������Ʊ����
	forward_list<yuanTrain> yuanTrainList;

	// ��ʼ���û����������
	initTrainTicketLink(trainTicketList);
	//��ʼ��ԭ����Ϣ������� 
	initYuanTrainLink(yuanTrainList, trainTicketList);

	int counter = 0;
	while (1)
	{
		system("cls");
		cout << "�����桷��¼���߼�����Ա" << endl << endl;
		cout << "**����Q����������**" << endl;
		cout << "1 ��ӳ��μ�������Ϣ" << endl;
		cout << "2 ɾ������" << endl;
		cout << "3 ��ѯ���г���" << endl;
		cout << "4 ��ѯĳ���εĳ˿��б�" << endl;
		cout << "5 �޸ĳ�����Ϣ" << endl;
		cout << "6 �鳵��" << endl;
		cout << "7 ��Ʊ" << endl;
		cout << "8 ��Ʊ" << endl;
		cout << "9 ��ǩ" << endl;
		cout << "w �г̲�ѯ" << endl;
		cout << "e ��ͨ����Ա������" << endl;
		if (counter != 0)
		{
			cout << "###�����ѡ����������ѡ������ѡ��###" << endl;
			//cout << "���������ѡ��";
		}
		cout << "���������ѡ��";
		char administratorSelect;
		//cin >> administratorSelect;
 		administratorSelect = getInputChar();
		switch (administratorSelect)
		{
		case '1':
			if (!addTIF(trainList, orderMap))
				cout << "���ʧ��" << endl;
			counter = 0;
			break;
		case '2':
			eraseTIF(trainList, orderMap);
			counter = 0;
			break;
		case '3':
			showAll(trainList, orderMap);
			counter = 0;
			break;
		case '4':
			showOrder(orderMap);
			counter = 0;
			break;
		case '5':
			reSetTIF(trainList, orderMap);
			counter = 0;
			break;
		case '6':
			userFind(yuanTrainList);
			counter = 0;
			break;
		case '7':
			buyTicket(userName, yuanTrainList, trainTicketList);
			counter = 0;
			break;
		case '8':
			deleTicket(trainTicketList, yuanTrainList);
			counter = 0;
			break;
		case '9':
			userChange(trainTicketList, yuanTrainList);
			counter = 0;
			break;
		case 'w':
			findItinerary(trainTicketList, yuanTrainList, userName);
			counter = 0;
			break;
		case 'e':
			addAdministrators(head);
			counter = 0;
			break;
		case 'Q':
		case 'q':
			return;
		default:
			counter++;
			break;
		}
	}
}

void addAdministrators(LoginLink* head)
{
	int counter = 0;
	while (1)
	{
		system("cls");
		cout << "�����桷��¼���߼�����Ա����ͨ����Ա������" << endl << endl;
		cout << "**����Q������һ����**" << endl;
		cout << "1 ��ʾ������ͨ����Ա" << endl;
		cout << "2 ������ͨ����Ա" << endl;
		cout << "3 �����ͨ����Ա" << endl;
		if (counter != 0)
		{
			cout << "###�����ѡ����������ѡ������ѡ��###";
			//cout << "���������ѡ��";
		}
			
		cout << "���������ѡ��";
		char addAdministratorsSelect;
		//cin >> addAdministratorsSelect;
		addAdministratorsSelect = getInputChar();
		if (addAdministratorsSelect == 'Q' || addAdministratorsSelect == 'q')
		{
			return;
		}
		switch (addAdministratorsSelect)
		{
		case '1':
			displayAdministrators(head);
			counter = 0;
			break;
		case '2':
			appointmentAdministrators(head);
			counter = 0;
			break;
		case '3':
			deleteAdministrators(head);
			counter = 0;
			break;
		default:
			counter++;
			break;
		}
	}
}

void displayAdministrators(LoginLink* head)
{
	system("cls");
	cout << "�����桷��¼���߼�����Ա����ͨ����Ա�����⡷��ʾ������ͨ����Ա" << endl << endl;
	cout << "������ͨ����Ա���£�" << endl;
	int num = 0;
	LoginLink* now = head->next;
	while (now != NULL)
	{
		if (now->Grade == "2")
		{
			num++;
			cout << now->Username << endl;
		}
		now = now->next;
	}
	if (num == 0)
	{
		cout << "Ŀǰû���κ���ͨ����Ա" << endl;
	}
	system("pause");
	return;
}

void appointmentAdministrators(LoginLink* head)
{
	string appointmentAdministratorsUsername;
	LoginLink* current;
	int counter = 0;
	while (1)
	{
		system("cls");
		cout << "�����桷��¼���߼�����Ա����ͨ����Ա�����⡷������ͨ����Ա" << endl << endl;
		cout << "**����Q����������**" << endl;
		if (counter == 0)
		{
			cout << "�������û�����";
		}
		else
		{
			cout << "�û��������ڣ������������û�����";
		}
		//cin >> appointmentAdministratorsUsername;
		appointmentAdministratorsUsername = getInputStringLine();
		if (appointmentAdministratorsUsername == "Q" || appointmentAdministratorsUsername == "q")
		{
			return;
		}
		current = head->next;
		while (current != NULL)//����û����治����
		{
			if (current->Username == appointmentAdministratorsUsername)
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

	cout << endl;
	cout << "��ȷ��Ҫ��" << appointmentAdministratorsUsername << "����Ϊ��ͨ����Ա��" << endl;
	cout << "�������ȷ�ϣ�����Qȡ��������������һ���棺";
	char Confirm;
	//cin >> Confirm;
	Confirm = getInputChar();
	if (Confirm == 'Q' || Confirm == 'q')
	{
		return;
	}

	current->Grade = "2";
	//��д�ļ�
	ofstream ofs;
	ofs.open("AcountLibrary.txt", ios::out);
	LoginLink* now = head->next;
	while (now != NULL)
	{
		ofs << now->Username << " " << now->Password << " " << now->Confidential << " " << now->Grade << endl;
		now = now->next;
	}
	ofs.close();

	cout << "�ѽ�" << appointmentAdministratorsUsername << "����Ϊ��ͨ����Ա" << endl;
	system("pause");
	return;
}

void deleteAdministrators(LoginLink* head)
{
	string deleteAdministratorsUsername;
	LoginLink* current;
	int counter = 0;
	while (1)
	{
		system("cls");
		cout << "�����桷��¼���߼�����Ա����ͨ����Ա�����⡷�����ͨ����Ա" << endl << endl;
		cout << "**����Q����������**" << endl;
		if (counter == 0)
		{
			cout << "�������û�����";
		}
		else
		{

			cout << "�û��������ڣ������������û�����";
		}
		//cin >> deleteAdministratorsUsername;
		deleteAdministratorsUsername = getInputStringLine();
		if (deleteAdministratorsUsername == "Q" || deleteAdministratorsUsername == "q")
		{
			return;
		}
		current = head->next;
		while (current != NULL)//����û����治����
		{
			if (current->Username == deleteAdministratorsUsername)
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

	if (current->Grade != "2")
	{
		cout << "�û�" << deleteAdministratorsUsername << "������ͨ����Ա" << endl;
		system("pause");
		return;
	}

	cout << endl;
	cout << "��ȷ��Ҫȡ��" << deleteAdministratorsUsername << "����ͨ����Ա�����" << endl;
	cout << "�������ȷ�ϣ�����Qȡ����������һ���棺";
	char confirm;
	//cin >> Confirm;
	confirm = getInputChar();
	if (confirm == 'Q' || confirm == 'q')
	{
		return;
	}

	current->Grade = "3";
	//��д�ļ�
	ofstream ofs;
	ofs.open("AcountLibrary.txt", ios::out);
	LoginLink* now = head->next;
	while (now != NULL)
	{
		ofs << now->Username << " " << now->Password << " " << now->Confidential << " " << now->Grade << endl;
		now = now->next;
	}
	ofs.close();

	cout << "��ȡ��" << deleteAdministratorsUsername << "����ͨ����Ա���" << endl;
	system("pause");
	return;
}