#include"Login.h"
#include"ChangeAccountInformation.h"
//防止循环导入
/*
读取到链表里
输入用户名
检测用户名是否存在
输入密码
检测密码是否正确
根据等级选界面
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
	//读取到链表里
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

	//输入用户名
	//string userName, password;
	LoginLink* current;
	int counter = 0;
	while (1)
	{
		system("cls");
		cout << "主界面》登录" << endl << endl;
		cout << "**输入Q返回主界面**" << endl;
		if (counter == 0)
		{
			cout << "请输入你的用户名：";
		}
		else
		{
			cout << "用户名不存在，请重新输入你的用户名：";
		}
		
		//cin >> userName;
		userName = getInputStringLine();
		if (userName == "Q" || userName == "q")//如果是Q，那就返回上一层函数
		{
			return;
		}
		current = head->next;
		while (current != NULL)//检测用户名存不存在
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

	//输入密码
	int counter1 = 0;
	while (1)
	{
		if (counter1 == 0)
		{
			system("cls");
			cout << "主界面》登录" << endl << endl;
			cout << "**输入Q返回主界面**" << endl;
			cout << "请输入你的密码：";
		}
		else
		{
			system("cls");
			cout << "主界面》登录" << endl << endl;
			cout << "**输入Q返回主界面**" << endl;
			cout << "密码错误，请重新输入密码：";
		}
		//cin >> password;
		password = getLoginPassword();
		if (password == current->Password)//检测密码是否正确
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

	// 创建用户火车票链表
	forward_list<trainTicket> trainTicketList;
	//创建火车票链表
	forward_list<yuanTrain> yuanTrainList;

	// 初始化用户购买库链表
	initTrainTicketLink(trainTicketList);
	//初始化原初信息库火车链表 
	initYuanTrainLink(yuanTrainList, trainTicketList);

	int counter = 0;
	while (1)
	{
		system("cls");
		cout << "主界面》登录》普通用户" << endl << endl;
		cout << "**输入Q返回主界面**" << endl;
		cout << "1 查车次" << endl;
		cout << "2 购票" << endl;
		cout << "3 退票" << endl;
		cout << "4 改签" << endl;
		cout << "5 行程查询" << endl;
		if (counter != 0)
		{
			cout << "###错误的选项，请根据以上选项输入选择###" << endl;
		}
		cout << "请输入你的选择：";
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
	forward_list<trainNode> trainList;//火车信息链表
	unordered_map<string, vector<string>> orderMap;//购买人群表
	string trainFile = "PrimordialInformationBase.txt";//火车信息文件
	string orderFile = "TicketBuyersDatabase.txt";//购买者文件
	if (!initAdmData(trainList, trainFile, orderMap, orderFile)) {
		cout << "文件读入失败，返回上一级" << endl;
		system("pause");
		return;
	}

	// 创建用户火车票链表
	forward_list<trainTicket> trainTicketList;
	//创建火车票链表
	forward_list<yuanTrain> yuanTrainList;

	// 初始化用户购买库链表
	initTrainTicketLink(trainTicketList);
	//初始化原初信息库火车链表 
	initYuanTrainLink(yuanTrainList, trainTicketList);

	int counter = 0;
	while (1)
	{
		system("cls");
		cout << "主界面》登录》普通管理员" << endl << endl;
		cout << "**输入Q返回主界面**" << endl;
		cout << "1 添加车次及车次信息" << endl;
		cout << "2 删除车次" << endl;
		cout << "3 查询所有车次" << endl;
		cout << "4 查询某车次的乘客列表" << endl;
		cout << "5 修改车次信息" << endl;
		cout << "6 查车次" << endl;
		cout << "7 购票" << endl;
		cout << "8 退票" << endl;
		cout << "9 改签" << endl;
		cout << "w 行程查询" << endl;
		if (counter != 0)
		{
			cout << "###错误的选项，请根据以上选项输入选择###" << endl;
			//cout << "请输入你的选择：";
		}
		cout << "请输入你的选择：";
		char administratorSelect;
		//cin >> administratorSelect;
		administratorSelect = getInputChar();
		switch (administratorSelect)
		{
		case '1':
			if (!addTIF(trainList, orderMap))
				cout << "添加失败" << endl;
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
	forward_list<trainNode> trainList;//火车信息链表
	unordered_map<string, vector<string>> orderMap;//购买人群表
	string trainFile = "PrimordialInformationBase.txt";//火车信息文件
	string orderFile = "TicketBuyersDatabase.txt";//购买者文件
	if (!initAdmData(trainList, trainFile, orderMap, orderFile)) {
		cout << "文件读入失败，返回上一级" << endl;
		system("pause");
		return;
	}

	// 创建用户火车票链表
	forward_list<trainTicket> trainTicketList;
	//创建火车票链表
	forward_list<yuanTrain> yuanTrainList;

	// 初始化用户购买库链表
	initTrainTicketLink(trainTicketList);
	//初始化原初信息库火车链表 
	initYuanTrainLink(yuanTrainList, trainTicketList);

	int counter = 0;
	while (1)
	{
		system("cls");
		cout << "主界面》登录》高级管理员" << endl << endl;
		cout << "**输入Q返回主界面**" << endl;
		cout << "1 添加车次及车次信息" << endl;
		cout << "2 删除车次" << endl;
		cout << "3 查询所有车次" << endl;
		cout << "4 查询某车次的乘客列表" << endl;
		cout << "5 修改车次信息" << endl;
		cout << "6 查车次" << endl;
		cout << "7 购票" << endl;
		cout << "8 退票" << endl;
		cout << "9 改签" << endl;
		cout << "w 行程查询" << endl;
		cout << "e 普通管理员的任免" << endl;
		if (counter != 0)
		{
			cout << "###错误的选项，请根据以上选项输入选择###" << endl;
			//cout << "请输入你的选择：";
		}
		cout << "请输入你的选择：";
		char administratorSelect;
		//cin >> administratorSelect;
 		administratorSelect = getInputChar();
		switch (administratorSelect)
		{
		case '1':
			if (!addTIF(trainList, orderMap))
				cout << "添加失败" << endl;
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
		cout << "主界面》登录》高级管理员》普通管理员的任免" << endl << endl;
		cout << "**输入Q返回上一界面**" << endl;
		cout << "1 显示所有普通管理员" << endl;
		cout << "2 任用普通管理员" << endl;
		cout << "3 免除普通管理员" << endl;
		if (counter != 0)
		{
			cout << "###错误的选项，请根据以上选项输入选择###";
			//cout << "请输入你的选择：";
		}
			
		cout << "请输入你的选择：";
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
	cout << "主界面》登录》高级管理员》普通管理员的任免》显示所有普通管理员" << endl << endl;
	cout << "所有普通管理员如下：" << endl;
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
		cout << "目前没有任何普通管理员" << endl;
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
		cout << "主界面》登录》高级管理员》普通管理员的任免》任用普通管理员" << endl << endl;
		cout << "**输入Q返回主界面**" << endl;
		if (counter == 0)
		{
			cout << "请输入用户名：";
		}
		else
		{
			cout << "用户名不存在，请重新输入用户名：";
		}
		//cin >> appointmentAdministratorsUsername;
		appointmentAdministratorsUsername = getInputStringLine();
		if (appointmentAdministratorsUsername == "Q" || appointmentAdministratorsUsername == "q")
		{
			return;
		}
		current = head->next;
		while (current != NULL)//检测用户名存不存在
		{
			if (current->Username == appointmentAdministratorsUsername)
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

	cout << endl;
	cout << "您确定要把" << appointmentAdministratorsUsername << "任命为普通管理员吗？" << endl;
	cout << "按任意键确认，输入Q取消任命并返回上一界面：";
	char Confirm;
	//cin >> Confirm;
	Confirm = getInputChar();
	if (Confirm == 'Q' || Confirm == 'q')
	{
		return;
	}

	current->Grade = "2";
	//重写文件
	ofstream ofs;
	ofs.open("AcountLibrary.txt", ios::out);
	LoginLink* now = head->next;
	while (now != NULL)
	{
		ofs << now->Username << " " << now->Password << " " << now->Confidential << " " << now->Grade << endl;
		now = now->next;
	}
	ofs.close();

	cout << "已将" << appointmentAdministratorsUsername << "任命为普通管理员" << endl;
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
		cout << "主界面》登录》高级管理员》普通管理员的任免》免除普通管理员" << endl << endl;
		cout << "**输入Q返回主界面**" << endl;
		if (counter == 0)
		{
			cout << "请输入用户名：";
		}
		else
		{

			cout << "用户名不存在，请重新输入用户名：";
		}
		//cin >> deleteAdministratorsUsername;
		deleteAdministratorsUsername = getInputStringLine();
		if (deleteAdministratorsUsername == "Q" || deleteAdministratorsUsername == "q")
		{
			return;
		}
		current = head->next;
		while (current != NULL)//检测用户名存不存在
		{
			if (current->Username == deleteAdministratorsUsername)
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

	if (current->Grade != "2")
	{
		cout << "用户" << deleteAdministratorsUsername << "不是普通管理员" << endl;
		system("pause");
		return;
	}

	cout << endl;
	cout << "您确定要取消" << deleteAdministratorsUsername << "的普通管理员身份吗？" << endl;
	cout << "按任意键确认，输入Q取消并返回上一界面：";
	char confirm;
	//cin >> Confirm;
	confirm = getInputChar();
	if (confirm == 'Q' || confirm == 'q')
	{
		return;
	}

	current->Grade = "3";
	//重写文件
	ofstream ofs;
	ofs.open("AcountLibrary.txt", ios::out);
	LoginLink* now = head->next;
	while (now != NULL)
	{
		ofs << now->Username << " " << now->Password << " " << now->Confidential << " " << now->Grade << endl;
		now = now->next;
	}
	ofs.close();

	cout << "已取消" << deleteAdministratorsUsername << "的普通管理员身份" << endl;
	system("pause");
	return;
}