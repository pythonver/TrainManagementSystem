
#include"UserMenu.h"

//函数功能：初始化用户购买库链表
//用户购买库"9theUserBuysTheLibrary.txt"
void initTrainTicketLink(forward_list<trainTicket>& trainTicketList) {
	ifstream fin;

	fin.open("TheUserBuysTheLibrary.txt", ios::in);

	//创建vector的string临时数组来存储用户购买库的购票信息 
	vector<string> Infor(2);

	/*利用while循环来将用户购买库中的购票信息存储到临时数组，赋值给临时节点tempticketain
	  用forward_list的头插函数插入到trainticket链表中达到初始化trainticket链表目的*/
	while (fin >> Infor[0] >> Infor[1]) {

		//Trainticket类型临时变量 
		trainTicket tempTictke;
		tempTictke.ticketInfo.push_back(Infor[0]);
		tempTictke.ticketInfo.push_back(Infor[1]);

		trainTicketList.push_front(tempTictke);
	}

	fin.close();
}

//函数功能：初始化原初信息库火车链表 
//原初信息库 "8primordialInformationBase.txt" 
void initYuanTrainLink(forward_list<yuanTrain>& yuanTrainList, forward_list<trainTicket>& trainTicketList) {
	//读文件
	ifstream fin;

	fin.open("PrimordialInformationBase.txt", ios::in);

	//创建vector的string临时数组来存储原初信息库的火车信息 
	vector<string> Inform(6);

	//统计对应车次火车的火车票已购人数
	int	ticketCount;
	//遍历火车票购买链表，为了统计对应车次剩余票数
	forward_list<trainTicket>::iterator itBegin = trainTicketList.begin();
	forward_list<trainTicket>::iterator itEnd = trainTicketList.end();

	/*利用while循环来将原初信息库中的火车信息存储到临时数组，赋值给临时节点tempTrain
	  用forward_list的头插函数插入到yuanTrain链表中达到初始化yuanTrain链表目的*/
	while (fin >> Inform[0] >> Inform[1] >> Inform[2] >> Inform[3] >> Inform[4] >> Inform[5]) {

		itBegin = trainTicketList.begin();
		ticketCount = 0;

		while (itBegin != itEnd) {
			if (Inform[0] == (*itBegin).ticketInfo[1]) {
				ticketCount++;
				cout << "-------" << ticketCount << "--------" << endl;
			}
			itBegin++;
		}

		//因为Inform[5]是string类型，用stoi将其转化为int与ticketCount相减,
		//结果赋值给temp这个中间变量，再将temp转为string重新赋值给Inofrm[5]
		int temp;
		temp = stoi(Inform[5]) - ticketCount;
		Inform[5] = to_string(temp);
		//YuanTrain类型临时变量 
		yuanTrain tempTrainInfo;
		tempTrainInfo.inform = Inform;

		yuanTrainList.push_front(tempTrainInfo);
	}
	fin.close();
}

//函数功能：输出用户查询火车界面 
void userFindCon() {
	cout << "主界面》登录》查询车次" << endl << endl;
	cout << "请选择查找方式" << endl << "1.通过目的地查找" << endl
		<< "2.通过始发地查找" << endl << "3.通过始发地→目的地特定查找"
		<< endl << "4.查询全部车票信息" << endl << "0.退出查找";
	cout << endl << endl << "请选择查找方式:";
}

//函数功能：用户查找菜单 
void userFind(forward_list<yuanTrain>& yuanTrainList) {
	while (true) {
		system("cls");
		//用户查找火车操作选择变量 
		int userFind;
		userFindCon();

		//用户查找操作选择 
		//cin >> userfind;

		//调用数字检测机制，检测用户是否正确输入数字，否则让用户重新输入
		userFind = getSelectDigit();

		if (userFind == -1) {
			system("pause");
			continue;
		}

		{
			switch (userFind) {
				//1.通过目的地查找 
			case 1:
				toSearch(yuanTrainList);
				break;
				//2.通过始发地查找 
			case 2:
				fromSearch(yuanTrainList);
				break;
				//3.通过始发地→目的地特定查找
			case 3:
				fromToSearch(yuanTrainList);
				break;
				//4.查询全部车票信息
			case 4:
				showAll(yuanTrainList);
				break;
				//0.退出查找 
			case 0:
				return;
			default://若是其他选择，回到用户查找火车功能菜单
				cout << "->错误的输入<-" << endl;
				cout << "请正确输入数字选项" << endl;
				system("pause");
				break;
			}
		}
	}
}

//函数功能：根据目的地查询火车信息
/*forword_list 遍历火车票链表，
存入临时变量，提取目的地，条件对比输出完整火车信息*/
//原初信息库 "8primordialInformationBase.txt" 
void toSearch(forward_list<yuanTrain>& yuanTrainList) {
	system("cls");
	cout << "主界面》登录》查询车次》通过目的地查找" << endl << endl;
	cout << "请输入目的地：";

	//定义bool类型变量来判断是否有用户需要的目的地的车次
	bool judgment = true;
	//再次定义bool类型变量来判断是否要在while循环里面让客户再次输入目的地
	bool Judgment = false;
	//保存用户输入的目的地的变量
	string destination;

	//真正的按照目的地查找菜单循环逻辑
	while (true) {
		//如果用户在输入目的地寻找不到时选择再次查找，则重新让用户输入
		if (Judgment) {
			system("cls");
			cout << "主界面》登录》查询车次》通过目的地查找" << endl << endl;
			cout << "请继续输入目的地：";
		}


		//调用获得一行没有空格的输入，来检查用户是否输入空格
		while (true) {
			destination = getInputStringLine();
			if (destination == "") {
				system("pause");
				cout << endl << "请重新输入:";
				continue;
			}
			break;
		}

		forward_list<yuanTrain>::iterator itBegin = yuanTrainList.begin();
		forward_list<yuanTrain>::iterator itEnd = yuanTrainList.end();

		int count = 0;
		// 设置每个字段的宽度为 10，左对齐
		const int fieldWidth = 15;
		//使用forward_list的迭代器来遍历初始化好的原初火车链表，输出所以的火车信息 
		while (itBegin != itEnd) {
			//如果原初火车库有对应目的地的车次，则输出对应的车次信息
			if (itBegin->inform[2] == destination) {

				if (count == 0) {
					system("cls");
					cout << "目的地为 " << destination << " 的火车有：" << endl;

					// 输出表头，并设置左对齐
					cout << left << setw(fieldWidth) << "车次"
						<< left << setw(fieldWidth) << "始发地"
						<< left << setw(fieldWidth) << "目的地"
						<< left << setw(fieldWidth) << "出发时间"
						<< left << setw(fieldWidth) << "抵达时间"
						<< left << setw(fieldWidth) << "车票数量" << endl;

				}
				// 输出左对齐的 inform 元素
				cout << left << setw(fieldWidth) << (*itBegin).inform[0]
					<< left << setw(fieldWidth) << (*itBegin).inform[1]
					<< left << setw(fieldWidth) << (*itBegin).inform[2]
					<< left << setw(fieldWidth) << (*itBegin).inform[3]
					<< left << setw(fieldWidth) << (*itBegin).inform[4]
					<< left << setw(fieldWidth) << (*itBegin).inform[5] << endl;
				//有对应车次，则不输出错误提示信息
				judgment = false;
				count++;
			}
			itBegin++;

		}

		cout << endl << "输入0回到用户查找菜单界面：";
		//用户输入0即可返回到上一个函数，即查找菜单函数
		int returnSeletion;
		while (true) {
			returnSeletion = getSelectDigit();
			if (returnSeletion == -1) {
				system("pause");
				cout << endl << "请输入新的选项：";
				continue;
			}
			break;
		}
		if (returnSeletion == 0) {
			return;
		}

		//如果用户在输入目的地查找不到时会让用户再次选择查找还是返回到上一个函数，即用户查找菜单
		if (judgment) {
			system("cls");
			cout << "主界面》登录》查询车次》通过目的地查找" << endl << endl;
			cout << "该目的地不存在，输入1回到用户菜单，输入2继续输入目的地：";

			//用户输入的目的地不存在，再次选择回退还是重新输入
			int desSeletion;
			while (true) {
				desSeletion = getSelectDigit();
				if (desSeletion == -1) {
					system("pause");
					cout << endl << "请输入新的选项：";
					continue;
				}
				break;
			}

			//用户选择接着查找还是回到用户查找菜单
			switch (desSeletion) {
				//返回到用户查找菜单，即退回到上一个调用该函数的函数
			case 1:
				return;
				break;
			case 2:
				Judgment = true;
				break;
			default:
				break;
			}
		}
	}
}

//函数功能：根据始发地查询火车信息
/*forword_list 遍历火车票链表，
存入临时变量，提取始发地，条件对比输出完整火车信息*/
//原初信息库 "8primordialInformationBase.txt" 
void fromSearch(forward_list<yuanTrain>& yuanTrainList) {
	system("cls");
	cout << "主界面》登录》查询车次》通过始发地查找" << endl << endl;
	cout << "请输入始发地：";

	//定义bool类型变量来判断是否有用户需要的始发地的车次
	bool judgment = true;
	//再次定义bool类型变量来判断是否要在while循环里面让客户再次输入始发地
	bool Judgment = false;

	while (true) {
		//如果用户在输入始发地寻找不到时选择再次查找，则重新让用户输入
		if (Judgment) {
			system("cls");
			cout << "主界面》登录》查询车次》通过始发地查找" << endl << endl;
			cout << "请继续输入始发地：";
		}

		//保存用户输入的始发地的变量
		string origin;
		//调用获得一行没有空格的输入，来检查用户是否输入空格
		while (true) {
			origin = getInputStringLine();
			if (origin == "") {
				system("pause");
				cout << endl << "请重新输入:";
				continue;
			}
			break;
		}

		forward_list<yuanTrain>::iterator itBegin = yuanTrainList.begin();
		forward_list<yuanTrain>::iterator itEnd = yuanTrainList.end();

		int count = 0;
		// 设置每个字段的宽度为 10，左对齐
		const int fieldWidth = 15;
		//使用forward_list的迭代器来遍历初始化好的原初火车链表，输出所以的火车信息 
		while (itBegin != itEnd) {

			//如果原初火车库有对应始发地的车次，则输出对应的车次信息
			if ((*itBegin).inform[1] == origin) {
				if (count == 0) {
					// 输出始发地
					cout << "始发地为 " << origin << " 的火车有：" << endl;
					// 输出表头，并设置左对齐
					cout << left << setw(fieldWidth) << "车次"
						<< left << setw(fieldWidth) << "始发地"
						<< left << setw(fieldWidth) << "目的地"
						<< left << setw(fieldWidth) << "出发时间"
						<< left << setw(fieldWidth) << "抵达时间"
						<< left << setw(fieldWidth) << "车票数量" << endl;
				}
				// 输出左对齐的 inform 元素
				cout << left << setw(fieldWidth) << (*itBegin).inform[0]
					<< left << setw(fieldWidth) << (*itBegin).inform[1]
					<< left << setw(fieldWidth) << (*itBegin).inform[2]
					<< left << setw(fieldWidth) << (*itBegin).inform[3]
					<< left << setw(fieldWidth) << (*itBegin).inform[4]
					<< left << setw(fieldWidth) << (*itBegin).inform[5] << endl;
				//有对应车次，则不输出错误提示信息
				judgment = false;

				count++;
			}
			itBegin++;
		}

		cout << endl << "输入0回到用户查找菜单界面：";
		//用户输入0即可返回到上一个函数，即查找菜单函数
		int returnSeletion;
		while (true) {
			returnSeletion = getSelectDigit();
			if (returnSeletion == -1) {
				system("pause");
				cout << endl << "请输入新的选项：";
				continue;
			}
			break;
		}
		if (returnSeletion == 0) {
			return;
		}

		//如果用户在输入始发地查找不到时会让用户再次选择查找还是返回到上一个函数，即用户查找菜单
		if (judgment) {
			system("cls");
			cout << "主界面》登录》查询车次》通过始发地查找" << endl << endl;
			cout << "该目的地不存在，输入1回到用户菜单，输入2继续输入始发地：";

			//用户输入的始发地不存在，再次选择回退还是重新输入
			int desSeletion;
			while (true) {
				desSeletion = getSelectDigit();
				if (desSeletion == -1) {
					system("pause");
					cout << endl << "请重新输入:";
					continue;
				}
				break;
			}

			//用户选择接着查找还是回到用户查找菜单
			switch (desSeletion) {
				//返回到用户查找菜单，即退回到上一个调用该函数的函数
			case 1:
				return;
				break;
			case 2:
				Judgment = true;
				break;
			default:
				break;
			}
		}

	}
}

//函数功能：根据始发地-目的地查询火车信息
/*forword_list 遍历火车票链表，
存入临时变量，提取始发地-目的地，条件对比输出完整火车信息*/
//原初信息库 "8primordialInformationBase.txt" 
void fromToSearch(forward_list<yuanTrain>& yuanTrainList) {
	system("cls");
	cout << "主界面》登录》查询车次》通过始发地→目的地特定查找" << endl << endl;
	cout << "请输入始发地：";

	//定义bool类型变量来判断是否有用户需要的始发地→目的地的车次
	bool judgment = true;
	//多定义bool类型变量来判断是否要让用户再次继续输入目的地
	bool Judgment = false;

	//多定义bool类型变量来判断是否要让用户首次接着输入始发地
	bool judge = true;


	while (true) {


		//如果用户在输入始发地→目的地寻找不到时选择再次查找，则再次让用户继续输入始发地
		if (judgment) {
			system("cls");
			cout << "主界面》登录》查询车次》通过始发地→目的地特定查找" << endl << endl;
			cout << "请继续输入始发地：";
		}

		//保存用户输入的始发地的变量
		string origin;
		while (true) {
			origin = getInputStringLine();
			if (origin == "") {
				system("pause");
				cout << endl << "请重新输入:";
				continue;
			}
			break;
		}

		//首次会输出提示语提醒用户接着输入目的地
		if (judge) {
			system("cls");
			cout << "主界面》登录》查询车次》通过始发地→目的地特定查找" << endl << endl;
			cout << "请输入目的地：";
		}

		//如果用户在输入始发地→目的地寻找不到时选择再次查找，则再次让用户继续输入始发地
		if (Judgment) {
			system("cls");
			cout << "主界面》登录》查询车次》通过始发地→目的地特定查找" << endl << endl;
			cout << "请继续输入目的地：";
		}

		//保存用户输入的目的地的变量
		string destination;
		while (true) {
			destination = getInputStringLine();
			if (destination == "") {
				system("pause");
				cout << endl << "请重新输入:";
				continue;
			}
			break;
		}

		forward_list<yuanTrain>::iterator itBegin = yuanTrainList.begin();
		forward_list<yuanTrain>::iterator itEnd = yuanTrainList.end();

		// 设置每个字段的宽度为 10，左对齐
		const int fieldWidth = 15;
		int count = 0;
		//使用forward_list的迭代器来遍历初始化好的原初火车链表，输出所以的火车信息 
		while (itBegin != itEnd) {

			//如果原初火车库有对应始发地→目的地的车次，则输出对应的车次信息
			if ((*itBegin).inform[1] == origin && (*itBegin).inform[2] == destination) {
				if (count == 0) {
					system("cls");
					cout << origin << "→" << destination << "的车次有：" << endl;
					// 输出表头，并设置左对齐
					cout << left << setw(fieldWidth) << "车次"
						<< left << setw(fieldWidth) << "始发地"
						<< left << setw(fieldWidth) << "目的地"
						<< left << setw(fieldWidth) << "出发时间"
						<< left << setw(fieldWidth) << "抵达时间"
						<< left << setw(fieldWidth) << "车票数量" << endl;
				}
				// 输出左对齐的 inform 元素，每个字段宽度为 10
				cout << left << setw(fieldWidth) << (*itBegin).inform[0]
					<< left << setw(fieldWidth) << (*itBegin).inform[1]
					<< left << setw(fieldWidth) << (*itBegin).inform[2]
					<< left << setw(fieldWidth) << (*itBegin).inform[3]
					<< left << setw(fieldWidth) << (*itBegin).inform[4]
					<< left << setw(fieldWidth) << (*itBegin).inform[5] << endl;
				//有对应车次，则不输出错误提示信息
				judgment = true;
				Judgment = true;

				count++;
			}
			itBegin++;

		}

		cout << endl << "输入0回到用户查找菜单界面：";
		//用户输入0即可返回到上一个函数，即查找菜单函数
		int returnSeletion;
		while (true) {
			returnSeletion = getSelectDigit();
			if (returnSeletion == -1) {
				system("pause");
				cout << endl << "请输入新的选项：";
				continue;
			}
			break;
		}
		if (returnSeletion == 0) {
			return;
		}

		//如果用户在输入始发地→目的地查找不到时会让用户再次选择查找还是返回到上一个函数，即用户查找菜单
		if (judgment) {

			system("cls");
			cout << "主界面》登录》查询车次》通过始发地→目的地特定查找" << endl << endl;
			cout << "该始发地→目的地不存在，输入1回到用户菜单，输入2继续输入始发地：";

			//用户输入的始发地→目的地不存在，再次选择回退还是重新输入
			int desSeletion;
			while (true) {
				desSeletion = getSelectDigit();
				if (desSeletion == -1) {
					system("pause");
					cout << endl << "请输入新的选项：";
					continue;
				}
				break;
			}

			//用户选择接着查找还是回到用户查找菜单
			switch (desSeletion) {
				//返回到用户查找菜单，即退回到上一个调用该函数的函数
			case 1:
				return;
				//重新查找
			case 2:
				Judgment = true;
				judgment = true;
				break;
			default:
				break;
			}
		}
	}
}

//函数功能：输出所有火车票信息
/*forword_list 遍历输出火车票链表
原初信息库 "8primordialInformationBase.txt" */
void showAll(forward_list<yuanTrain>& yuanTrainList) {
	system("cls");
	cout << "主界面》登录》查询全部车次信息" << endl << endl;
	cout << "以下为全部车次信息：" << endl;

	// 设置每个字段的宽度为 10，左对齐
	const int fieldWidth = 15;

	// 输出表头，并设置左对齐
	cout << left << setw(fieldWidth) << "车次"
		<< left << setw(fieldWidth) << "始发地"
		<< left << setw(fieldWidth) << "目的地"
		<< left << setw(fieldWidth) << "出发时间"
		<< left << setw(fieldWidth) << "抵达时间"
		<< left << setw(fieldWidth) << "车票数量" << endl;

	forward_list<yuanTrain>::iterator itBegin = yuanTrainList.begin();
	forward_list<yuanTrain>::iterator itEnd = yuanTrainList.end();

	//使用forward_list的迭代器来遍历初始化好的原初火车链表，输出所以的火车信息 
	while (itBegin != itEnd) {
		// 输出左对齐的 inform 元素，每个字段宽度为 10
		cout << left << setw(fieldWidth) << (*itBegin).inform[0]
			<< left << setw(fieldWidth) << (*itBegin).inform[1]
			<< left << setw(fieldWidth) << (*itBegin).inform[2]
			<< left << setw(fieldWidth) << (*itBegin).inform[3]
			<< left << setw(fieldWidth) << (*itBegin).inform[4]
			<< left << setw(fieldWidth) << (*itBegin).inform[5] << endl;
		itBegin++;
	}

	while (true) {
		cout << endl << "输入0即可返回查找界面:";
		int reTurn;
		while (true) {
			reTurn = getSelectDigit();
			if (reTurn == -1) {
				system("pause");
				cout << endl << "请输入新的选项：";
				continue;
			}
			break;
		}
		if (reTurn == 0)
			return;
	}
}

// 函数功能：用户购票
// 通过车次购买
/* 从原初信息库 "8primordialInformationBase.txt" 查找是否有对应车次
有就录入用户购买库 "9theUserBuysTheLibrary.txt" */
void buyTicket(string username, forward_list<yuanTrain>& yuanTrainList, forward_list<trainTicket>& trainTicketList) {
	bool judgment = true; // 判断第一次输入还是多次输入
	bool judge = false;   // 判断是否有用户要购买的车次

	while (true) {
		if (judgment) {
			system("cls");
			cout << "主界面》登录》购买车票" << endl << endl;
			cout << "请输入你要购买的车票的车次：";
			judgment = false;
		}
		else {
			system("cls");
			cout << "主界面》用户》登录》登录成功》用户菜单》购买车票" << endl << endl;
			cout << "请继续输入车次：";
		}

		string trip;
		while (true) {
			trip = getInputStringLine();
			if (trip == "") {
				system("pause");
				cout << endl << "请重新输入:";
				continue;
			}
			break;
		}

		//如果用户想要购买的车票数量为0，则不可购买
		// 查找对应车次的火车节点
		yuanTrain* foundTrain = findTrainLinkedListNode(yuanTrainList, trip);

		if (foundTrain != nullptr) {
			// 找到了匹配的火车信息
			int ticketCount = stoi(foundTrain->inform[5]); // 获取当前车票数量并转换为整数

			if (ticketCount > 0) {
				// 车票数量大于0，可以购买
			}
			else {
				int isconfirm;
				cout << "车票数量为0，无法购买，输入0返回" << endl << "请输入：";
				while (true) {
					isconfirm = getSelectDigit();
					if (isconfirm == -1) {
						system("pause");
						cout << endl << "请输入新的选项：";
						continue;
					}
					break;
				}
				if (isconfirm == 0) {
					return;
				}
				cout << "请输入正确的选项：" << endl;
			}
		}

		//用户是否确认购买
		while (true) {
			int isconfirm;
			cout << "请确认是否要购买车次为 '" << trip << "' 的车票" << endl;
			cout << "输入1表示确认，输入0返回" << endl;
			cout << "请输入:";
			while (true) {
				isconfirm = getSelectDigit();
				if (isconfirm == -1) {
					system("pause");
					cout << endl << "请输入新的选项：";
					continue;
				}
				break;
			}
			if (isconfirm == 1) {
				break;
			}
			if (isconfirm == 0) {
				return;
			}
			cout << "请输入正确的选项：" << endl;
		}

		vector<string> tempinfor(2);

		forward_list<yuanTrain>::iterator itBegin = yuanTrainList.begin();
		forward_list<yuanTrain>::iterator itEnd = yuanTrainList.end();

		while (itBegin != itEnd) {
			if (trip == (*itBegin).inform[0]) { // 此处改为比较车次信息
				tempinfor[0] = username;
				tempinfor[1] = trip;
				judge = true;

				// 更新火车票链表
				trainTicket newTicket;
				newTicket.ticketInfo = tempinfor;
				trainTicketList.push_front(newTicket);

				//购买了车票，对应车次的车票数量减一 
				int temp = stoi((*itBegin).inform[5]) - 1;
				(*itBegin).inform[5] = to_string(temp);

				//购买了车票 方便管理员管理 向“10ticketBuyersDatabase.txt”写入
				ifstream infile("TicketBuyersDatabase.txt"); // 打开文件以读取内容
				vector<string> tempfor;
				string line;
				string trainNumber;
				while (getline(infile, line)) {
					istringstream iss(line);//从文件读取的一行转换成输入流
					iss >> trainNumber;//输入车次
					// 在这里可以处理读取的每一行数据
					if (trainNumber == (*itBegin).inform[0]) {
						// 在这里可以根据需要对读取的数据进行处理
						line += username;
						line += ' ';
						tempfor.push_back(line);
						continue;
					}
					tempfor.push_back(line);
				}
				// 关闭文件
				infile.close();

				ofstream fout("TicketBuyersDatabase.txt", ios::out); // 0打开文件以写入新内容
				// 将 tempfor 中的内容写入文件
				for (const string& line : tempfor) {
					fout << line << endl;
				}
				// 关闭文件
				fout.close();

				break;
			}
			itBegin++;
		}

		if (judge) {
			ofstream fout;
			fout.open("TheUserBuysTheLibrary.txt", ios::app);
			for (int k = 0; k < 2; k++) {
				fout << tempinfor[k] << " ";
			}
			fout << endl;
			fout.close();

			system("cls");
			cout << "主界面》登录》购买车票" << endl << endl;
			cout << "购买成功，输入0返回用户菜单：";
			int reTurn;
			while (true) {
				reTurn = getSelectDigit();
				if (reTurn == -1) {
					system("pause");
					cout << endl << "请输入新的选项：";
					continue;
				}
				break;
			}
			if (reTurn == 0) {
				return;
			}
		}
		else {
			system("cls");
			cout << "主界面》登录》购买车票" << endl << endl;
			cout << "该车次不存在，输入1返回用户菜单，输入2继续输入车次：";
			int seletion;
			while (true) {
				seletion = getSelectDigit();
				if (seletion == -1) {
					system("pause");
					cout << endl << "请输入新的选项：";
					continue;
				}
				break;
			}
			if (seletion == 1) {
				return;
			}
		}
	}
}

//函数功能：行程查询
//通过用户名查询
//用户购买库 "8primordialInformationBase.txt" 
void findItinerary(forward_list<trainTicket>& trainTicketList, forward_list<yuanTrain>& yuanTrainList, const string& username) {
	// 创建存储用户购买的车次信息的向量
	vector<string> purchasedTrains;

	// 用户购买库链表的迭代器
	forward_list<trainTicket>::iterator itBegin = trainTicketList.begin();
	forward_list<trainTicket>::iterator itEnd = trainTicketList.end();

	// 在遍历用户购买库时，记录用户购买的车次信息
	while (itBegin != itEnd) {
		if (username == (*itBegin).ticketInfo[0]) {
			purchasedTrains.push_back((*itBegin).ticketInfo[1]); // 将匹配的车次信息存储起来
		}
		itBegin++;
	}

	// 输出行程信息
	if (!purchasedTrains.empty()) {
		system("cls");
		cout << "主界面》登录》行程查询" << endl << endl;
		cout << "您的行程如下：" << endl;

		// 设置每个字段的宽度为 10，左对齐
		const int fieldWidth = 15;

		// 输出表头，并设置左对齐
		cout << left << setw(fieldWidth) << "车次"
			<< left << setw(fieldWidth) << "始发地"
			<< left << setw(fieldWidth) << "目的地"
			<< left << setw(fieldWidth) << "出发时间"
			<< left << setw(fieldWidth) << "抵达时间" << endl;

		// 遍历存储的车次信息，并输出对应的行程信息
		for (auto trainIter = purchasedTrains.begin(); trainIter != purchasedTrains.end(); ++trainIter) {
			// 在原初信息库中查找对应的车次信息
			for (auto infoIter = yuanTrainList.begin(); infoIter != yuanTrainList.end(); ++infoIter) {
				if (*trainIter == (*infoIter).inform[0]) {
					// 输出左对齐的 inform 元素，每个字段宽度为 10
					cout << left << setw(fieldWidth) << (*infoIter).inform[0]
						<< left << setw(fieldWidth) << (*infoIter).inform[1]
						<< left << setw(fieldWidth) << (*infoIter).inform[2]
						<< left << setw(fieldWidth) << (*infoIter).inform[3]
						<< left << setw(fieldWidth) << (*infoIter).inform[4] << endl;
					break;
				}
			}
		}

		// 用户退出行程查询选择
		/*cout << endl << "输入1返回上一界面:";
		int selection;
		while (true) {
			selection = getSelectDigit();
			if (selection == -1) {
				system("pause");
				cout << endl << "请输入新的选项：";
				continue;
			}
			break;
		}
		if (selection == 1)
			return;*/
		system("pause");
	}
	else {
		// 如果用户没有购买车票，则输出提示信息
		system("cls");
		cout << "主界面》登录》行程查询" << endl << endl;
		cout << "您目前没有任何行程" << endl;
		/*int selection;
		while (true) {
			selection = getSelectDigit();
			if (selection == -1) {
				system("pause");
				cout << endl << "请输入新的选项：";
				continue;
			}
			break;
		}
		if (selection == 1)
			return;*/
		system("pause");
	}
}

//函数功能：用户退票
void deleTicket(forward_list<trainTicket>& trainTicketList, forward_list<yuanTrain>& yuanTrainList) {
	while (true) {
		//判断用户是首次输出还是多次输入 
		bool judge = true;
		//判断是否有用户要退掉的票
		bool judgeMent = true;

		if (judge) {
			system("cls");
			cout << "主界面》登录》退票" << endl << endl;
			cout << "请输入您要退票的车次：";
		}
		else {
			system("cls");
			cout << "主界面》登录》退票" << endl << endl;
			cout << "请继续输入要退票的车次：";
		}

		//记录用户删除的车次 变量 
		string trip;
		while (true) {
			trip = getInputStringLine();
			if (trip == "") {
				system("pause");
				cout << endl << "请重新输入:";
				continue;
			}
			break;
		}

		//用户是否确认退票
		while (true) {
			int isconfirm;
			cout << "请确认是否要退掉车次为 '" << trip << "' 的车票" << endl;
			cout << "输入1表示确认，输入0返回" << endl;
			cout << "请输入:";
			while (true) {
				isconfirm = getSelectDigit();
				if (isconfirm == -1) {
					system("pause");
					cout << endl << "请输入新的选项：";
					continue;
				}
				break;
			}
			if (isconfirm == 1) {
				break;
			}
			if (isconfirm == 0) {
				return;
			}
			cout << "请输入正确的选项：" << endl;
		}

		//用户购买库链表的迭代器
		//用户购买库链表的第一个元素的迭代器 
		forward_list<trainTicket>::iterator itBegin = trainTicketList.begin();
		/*指向用户购买库链表的第一个元素的前一个位置，拿来记录头迭代器的前一个位置，
		方便下面使用erase_after删除找到的要删除的节点 */
		forward_list<trainTicket>::iterator itbegin = trainTicketList.before_begin();
		forward_list<trainTicket>::iterator itEnd = trainTicketList.end();

		while (itBegin != itEnd) {
			if (trip == (*itBegin).ticketInfo[1]) {

				//退车票，对应车次的数量加一
				yuanTrain* foundTrain = findTrainLinkedListNode(yuanTrainList, trip);
				if (foundTrain != nullptr) {
					// 找到了匹配的火车信息，将车票数量加一
					int ticketCount = stoi(foundTrain->inform[5]); // 获取当前车票数量并转换为整数
					ticketCount++; // 减少车票数量
					foundTrain->inform[5] = to_string(ticketCount); // 更新车票数量
				}

				//退车票 方便管理员管理 将对应“10ticketBuyersDatabase.txt”删除
				ifstream infile("TicketBuyersDatabase.txt"); // 打开文件以读取内容
				vector<string> tempfor;
				string line;
				string trainNumber;
				while (getline(infile, line)) {
					istringstream iss(line);//从文件读取的一行转换成输入流
					iss >> trainNumber;//输入车次
					// 在这里可以处理读取的每一行数据
					if (trainNumber == (*itBegin).ticketInfo[1]) {
						tempfor.push_back(trainNumber + " ");
						string username;
						while (iss >> username) {
							if (username != (*itBegin).ticketInfo[0]) {
								tempfor.back() = tempfor.back() + username + " ";
							}
						}
						continue;
					}
					tempfor.push_back(line);
				}
				// 关闭文件
				infile.close();

				ofstream ofout("TicketBuyersDatabase.txt", ios::out); // 打开文件以写入新内容
				// 将 tempfor 中的内容写入文件
				for (const string& line : tempfor) {
					ofout << line << endl;
				}
				// 关闭文件
				ofout.close();

				//删除用户退票的节点 
				trainTicketList.erase_after(itbegin);

				//设置打开文件方式清楚文件中的所以信息
				// 打开文件时指定 ios::trunc 标志，清空文件内容
				ofstream fout("TheUserBuysTheLibrary.txt", ios::out | ios::trunc);
				itBegin = trainTicketList.begin();
				itEnd = trainTicketList.end();
				//将删除后的链表重新读入文件
				while (itBegin != itEnd) {
					fout << (*itBegin).ticketInfo[0] << " " << (*itBegin).ticketInfo[1] << endl;
					itBegin++;
				}
				fout.close();

				judgeMent = false;
				cout << endl << "退票成功，输入1返回用户菜单：";
				int selection;
				while (true) {
					selection = getSelectDigit();
					if (selection == -1) {
						system("pause");
						cout << endl << "请输入新的选项：";
						continue;
					}
					break;
				}
				if (selection == 1)
					return;

				//未找到用户要退票的车次 
			}
			// 更新迭代器位置
			itbegin = itBegin;
			++itBegin;
		}
		if (judgeMent) {
			//用户选择回到用户菜单还是继续输入要退票的车次 
			system("cls");
			cout << "主界面》登录》退票"
				<< endl << endl << "您未购买该车次的车票，输入1回到用户菜单，输入2继续输入要退票的车次：";
			int selection;
			while (true) {
				selection = getSelectDigit();
				if (selection == -1) {
					system("pause");
					cout << endl << "请输入新的选项：";
					continue;
				}
				break;
			}
			if (selection == 1) {
				return;
			}
			else if (selection == 2) {
				//再次选择输入，用户提示语变化 
				judge = false;
				break;
			}
		}
	}
}

//函数功能:用户改签 
void userChange(forward_list<trainTicket>& trainTicketList, forward_list<yuanTrain>& yuanTrainList) {
	//是否有用户要改签车次
	bool judegement = true;
	
	while (true) {
		system("cls");
		cout << "主界面》登录》改签" << endl << endl;
		cout << "请输入你要改签的车次：";
		//改签车次变量 
		string origtrip;
		while (true) {
			origtrip = getInputStringLine();
			if (origtrip == "") {
				system("pause");
				cout << endl << "请重新输入:";
				continue;
			}
			break;
		}

		//用户是否确认改签
		while (true) {
			int isconfirm;
			cout << "请确认是否要改签车次为 '" << origtrip << "' 的车票" << endl;
			cout << "输入1表示确认，输入0返回" << endl;
			cout << "请输入:";
			while (true) {
				isconfirm = getSelectDigit();
				if (isconfirm == -1) {
					system("pause");
					cout << endl << "请输入新的选项：";
					continue;
				}
				break;
			}
			if (isconfirm == 1) {
				break;
			}
			if (isconfirm == 0) {
				return;
			}
			cout << "请输入正确的选项：" << endl;
		}

		/*使用迭代器遍历用户购买库链表，
		对比改签车次，找到则删除节点，然后添加新节点，
		打开文件方式为清空文件，便于录入新的用户购买信息 */
		//需要使用两个迭代器，一个指向头元素，另一个指向头元素的前一个位置 
		forward_list<trainTicket>::iterator itBegin = trainTicketList.begin();
		forward_list<trainTicket>::iterator itBeforeBegin = trainTicketList.before_begin();
		forward_list<trainTicket>::iterator itEnd = trainTicketList.end();

		while (itBegin != itEnd) {
			if ((*itBegin).ticketInfo[1] == origtrip) {
				judegement = true;

				//判断用户第一次输入新车次还是多次输入新车次 
				bool judgement = true;

				if (judgement) {
					system("cls");
					cout << "主界面》登录》改签》已输入原来车次" << endl << endl;
					cout << "请输入新车次：";
				}
				else {
					system("cls");
					cout << "主界面》登录》改签》已输入原来车次" << endl << endl;
					cout << "请继续输入新车次：";
				}

				//新车次变量 
				string newtrip;
				while (true) {
					newtrip = getInputStringLine();
					if (newtrip == "") {
						system("pause");
						cout << endl << "请重新输入:";
						continue;
					}
					break;
				}

				//用户是否确认改签
				while (true) {
					int isconfirm;
					cout << "请确认是否要将车次为 '" << origtrip << "' 的车票改签为 ‘" << newtrip << "' " << endl;
					cout << "输入1表示确认，输入0返回" << endl;
					cout << "请输入:";
					while (true) {
						isconfirm = getSelectDigit();
						if (isconfirm == -1) {
							system("pause");
							cout << endl << "请输入新的选项：";
							continue;
						}
						break;
					}
					if (isconfirm == 1) {
						break;
					}
					if (isconfirm == 0) {
						return;
					}
					cout << "请输入正确的选项：" << endl;
				}

				//判断是否有用户需要的新车次bool变量 
				bool Judge = true;

				//判断新车次原初信息库是否存在
				//“YuanChuXinXiKu.txt” 
				forward_list<yuanTrain>::iterator Begin = yuanTrainList.begin();
				forward_list<yuanTrain>::iterator End = yuanTrainList.end();
				while (Begin != End) {
					if ((*Begin).inform[0] == newtrip) {
						Judge = false;
						break;
					}
					Begin++;
				}

				if (Judge) {
					system("cls");
					cout << "主界面》登录》改签" << endl << endl;
					cout << "该新车次不存在，输入0返回上一界面，输入1继续输入新车次";
					int selection;
					while (true) {
						selection = getSelectDigit();
						if (selection == -1) {
							system("pause");
							cout << endl << "请输入新的选项：";
							continue;
						}
						break;
					}
					if (selection == 0) {
						return;
					}
					else if (selection == 1) {

						judgement = false;

						continue;
					}
				}
				else {
					//记录改签的用户名以及新的车次信息 
					vector<string> Info(2);
					//将要删除的节点的用户名赋值给新的暂存节点 
					Info[0] = (*itBegin).ticketInfo[0];
					Info[1] = newtrip;

					//临时节点 
					trainTicket tempticket;
					//将新信息存入临时节点 
					for (int i = 0; i < 2; i++) {
						tempticket.ticketInfo.push_back(Info[i]);
					}


					//用户改签，将改签前的车次车票数量+1，新车次车票数量-1
					// 查找原始车次和新车次的火车节点
					yuanTrain* oldTrain = findTrainLinkedListNode(yuanTrainList, origtrip);
					yuanTrain* newTrain = findTrainLinkedListNode(yuanTrainList, newtrip);

					if (oldTrain != nullptr && newTrain != nullptr) {
						// 找到了原始车次和新车次的匹配信息
						int oldTicketCount = stoi(oldTrain->inform[5]); // 获取原始车次的车票数量并转换为整数
						int newTicketCount = stoi(newTrain->inform[5]); // 获取新车次的车票数量并转换为整数

						if (newTicketCount > 0) {
							// 新车次有足够的车票数量，可以进行改签
							oldTicketCount++; // 原始车次的车票数量加1
							newTicketCount--; // 新车次的车票数量减1
							oldTrain->inform[5] = to_string(oldTicketCount); // 更新原始车次的车票数量
							newTrain->inform[5] = to_string(newTicketCount); // 更新新车次的车票数量
							// 改签成功
						}
						else {
							// 改签失败，新车次数量为0，无法改签
							int isconfirm;
							cout << "改签新车次数量为0，无法改签，输入0返回" << endl << "请输入:";
							while (true) {
								isconfirm = getSelectDigit();
								if (isconfirm == -1) {
									system("pause");
									cout << endl << "请输入新的选项：";
									continue;
								}
								break;
							}
							if (isconfirm == 0) {
								return;
							}
							cout << "请输入正确的选项：" << endl;
						}
					}
					//改签 方便管理员管理 将对应“10ticketBuyersDatabase.txt”更改
					ifstream infile("TicketBuyersDatabase.txt"); // 打开文件以读取内容
					vector<string> tempfor;
					string line;
					string trainNumber;
					while (getline(infile, line)) {
						istringstream iss(line);//从文件读取的一行转换成输入流
						iss >> trainNumber;//输入车次
						// 在这里可以处理读取的每一行数据
						//改签从原车次将用户删去
						if (trainNumber == (*itBegin).ticketInfo[1]) {
							tempfor.push_back(trainNumber + " ");
							string username;
							while (iss >> username) {
								if (username != (*itBegin).ticketInfo[0]) {
									tempfor.back() = tempfor.back() + username + " ";
								}
							}
							continue;
						}
						//改签再从新车次加上用户
						if (trainNumber == Info[1]) {
							// 在这里可以根据需要对读取的数据进行处理
							line += Info[0];
							line += ' ';
							tempfor.push_back(line);
							continue;
						}
						tempfor.push_back(line);
					}
					// 关闭文件
					infile.close();

					ofstream ofout("TicketBuyersDatabase.txt", ios::out); // 打开文件以写入新内容
					// 将 tempfor 中的内容写入文件
					for (const string& line : tempfor) {
						ofout << line << endl;
					}
					// 关闭文件
					ofout.close();


					//先删除，后插入 
					trainTicketList.erase_after(itBeforeBegin);
					trainTicketList.insert_after(itBeforeBegin, tempticket);

					//对链表操作完成后，以清除文件所有内容的形式打开文件，将所有信息录入文件，关闭
					// 打开文件时指定 ios::trunc 标志，清空文件内容
					ofstream fout("TheUserBuysTheLibrary.txt", ios::out | ios::trunc);
					itBegin = trainTicketList.begin();
					itBeforeBegin = trainTicketList.before_begin();
					while (itBegin != itEnd) {
						fout << (*itBegin).ticketInfo[0] << " " << (*itBegin).ticketInfo[1] << endl;
						itBegin++;
					}
					fout.close();
					system("cls");
					cout << "主界面》登录》改签》已输入原来车次" << endl << endl;
					cout << "改签成功，输入1返回上一界面：";
					int selereturn = 1;
					while (true) {
						selereturn = getSelectDigit();
						if (selereturn == -1) {
							system("pause");
							cout << endl << "请输入新的选项：";
							continue;
						}
						break;
					}
					if (selereturn == 1) {
						return;
					}
				}
			}
			// 更新迭代器位置
			itBeforeBegin = itBegin;
			++itBegin;
		}
		if (judegement) {
			system("cls");
			cout << "主界面》登录》改签" << endl << endl;
			cout << "您未购买该车次的车票，无法改签，输入1返回上一界面：";
			int selection;
			while (true) {
				selection = getSelectDigit();
				if (selection == -1) {
					system("pause");
					cout << endl << "请输入新的选项：";
					continue;
				}
				break;
			}
			if (selection == 1) {
				return;
			}
		}
	}
}

// 寻找原初信息库链表对应节点
// 通过遍历yuanTrain链表，将需要查找的车次信息对照，查找成功则返回
yuanTrain* findTrainLinkedListNode(forward_list<yuanTrain>& yuanTrain, string Trips) {
	for (auto& train : yuanTrain) {
		if (!train.inform.empty() && train.inform[0] == Trips) {
			// 找到匹配的车次信息，返回指向该节点的指针
			return &train;
		}
	}
	// 没有找到匹配的车次信息，返回空指针表示未找到
	return nullptr;
}