
#include"UserMenu.h"

//�������ܣ���ʼ���û����������
//�û������"9theUserBuysTheLibrary.txt"
void initTrainTicketLink(forward_list<trainTicket>& trainTicketList) {
	ifstream fin;

	fin.open("TheUserBuysTheLibrary.txt", ios::in);

	//����vector��string��ʱ�������洢�û������Ĺ�Ʊ��Ϣ 
	vector<string> Infor(2);

	/*����whileѭ�������û�������еĹ�Ʊ��Ϣ�洢����ʱ���飬��ֵ����ʱ�ڵ�tempticketain
	  ��forward_list��ͷ�庯�����뵽trainticket�����дﵽ��ʼ��trainticket����Ŀ��*/
	while (fin >> Infor[0] >> Infor[1]) {

		//Trainticket������ʱ���� 
		trainTicket tempTictke;
		tempTictke.ticketInfo.push_back(Infor[0]);
		tempTictke.ticketInfo.push_back(Infor[1]);

		trainTicketList.push_front(tempTictke);
	}

	fin.close();
}

//�������ܣ���ʼ��ԭ����Ϣ������� 
//ԭ����Ϣ�� "8primordialInformationBase.txt" 
void initYuanTrainLink(forward_list<yuanTrain>& yuanTrainList, forward_list<trainTicket>& trainTicketList) {
	//���ļ�
	ifstream fin;

	fin.open("PrimordialInformationBase.txt", ios::in);

	//����vector��string��ʱ�������洢ԭ����Ϣ��Ļ���Ϣ 
	vector<string> Inform(6);

	//ͳ�ƶ�Ӧ���λ𳵵Ļ�Ʊ�ѹ�����
	int	ticketCount;
	//������Ʊ��������Ϊ��ͳ�ƶ�Ӧ����ʣ��Ʊ��
	forward_list<trainTicket>::iterator itBegin = trainTicketList.begin();
	forward_list<trainTicket>::iterator itEnd = trainTicketList.end();

	/*����whileѭ������ԭ����Ϣ���еĻ���Ϣ�洢����ʱ���飬��ֵ����ʱ�ڵ�tempTrain
	  ��forward_list��ͷ�庯�����뵽yuanTrain�����дﵽ��ʼ��yuanTrain����Ŀ��*/
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

		//��ΪInform[5]��string���ͣ���stoi����ת��Ϊint��ticketCount���,
		//�����ֵ��temp����м�������ٽ�tempתΪstring���¸�ֵ��Inofrm[5]
		int temp;
		temp = stoi(Inform[5]) - ticketCount;
		Inform[5] = to_string(temp);
		//YuanTrain������ʱ���� 
		yuanTrain tempTrainInfo;
		tempTrainInfo.inform = Inform;

		yuanTrainList.push_front(tempTrainInfo);
	}
	fin.close();
}

//�������ܣ�����û���ѯ�𳵽��� 
void userFindCon() {
	cout << "�����桷��¼����ѯ����" << endl << endl;
	cout << "��ѡ����ҷ�ʽ" << endl << "1.ͨ��Ŀ�ĵز���" << endl
		<< "2.ͨ��ʼ���ز���" << endl << "3.ͨ��ʼ���ء�Ŀ�ĵ��ض�����"
		<< endl << "4.��ѯȫ����Ʊ��Ϣ" << endl << "0.�˳�����";
	cout << endl << endl << "��ѡ����ҷ�ʽ:";
}

//�������ܣ��û����Ҳ˵� 
void userFind(forward_list<yuanTrain>& yuanTrainList) {
	while (true) {
		system("cls");
		//�û����һ𳵲���ѡ����� 
		int userFind;
		userFindCon();

		//�û����Ҳ���ѡ�� 
		//cin >> userfind;

		//�������ּ����ƣ�����û��Ƿ���ȷ�������֣��������û���������
		userFind = getSelectDigit();

		if (userFind == -1) {
			system("pause");
			continue;
		}

		{
			switch (userFind) {
				//1.ͨ��Ŀ�ĵز��� 
			case 1:
				toSearch(yuanTrainList);
				break;
				//2.ͨ��ʼ���ز��� 
			case 2:
				fromSearch(yuanTrainList);
				break;
				//3.ͨ��ʼ���ء�Ŀ�ĵ��ض�����
			case 3:
				fromToSearch(yuanTrainList);
				break;
				//4.��ѯȫ����Ʊ��Ϣ
			case 4:
				showAll(yuanTrainList);
				break;
				//0.�˳����� 
			case 0:
				return;
			default://��������ѡ�񣬻ص��û����һ𳵹��ܲ˵�
				cout << "->���������<-" << endl;
				cout << "����ȷ��������ѡ��" << endl;
				system("pause");
				break;
			}
		}
	}
}

//�������ܣ�����Ŀ�ĵز�ѯ����Ϣ
/*forword_list ������Ʊ����
������ʱ��������ȡĿ�ĵأ������Ա������������Ϣ*/
//ԭ����Ϣ�� "8primordialInformationBase.txt" 
void toSearch(forward_list<yuanTrain>& yuanTrainList) {
	system("cls");
	cout << "�����桷��¼����ѯ���Ρ�ͨ��Ŀ�ĵز���" << endl << endl;
	cout << "������Ŀ�ĵأ�";

	//����bool���ͱ������ж��Ƿ����û���Ҫ��Ŀ�ĵصĳ���
	bool judgment = true;
	//�ٴζ���bool���ͱ������ж��Ƿ�Ҫ��whileѭ�������ÿͻ��ٴ�����Ŀ�ĵ�
	bool Judgment = false;
	//�����û������Ŀ�ĵصı���
	string destination;

	//�����İ���Ŀ�ĵز��Ҳ˵�ѭ���߼�
	while (true) {
		//����û�������Ŀ�ĵ�Ѱ�Ҳ���ʱѡ���ٴβ��ң����������û�����
		if (Judgment) {
			system("cls");
			cout << "�����桷��¼����ѯ���Ρ�ͨ��Ŀ�ĵز���" << endl << endl;
			cout << "���������Ŀ�ĵأ�";
		}


		//���û��һ��û�пո�����룬������û��Ƿ�����ո�
		while (true) {
			destination = getInputStringLine();
			if (destination == "") {
				system("pause");
				cout << endl << "����������:";
				continue;
			}
			break;
		}

		forward_list<yuanTrain>::iterator itBegin = yuanTrainList.begin();
		forward_list<yuanTrain>::iterator itEnd = yuanTrainList.end();

		int count = 0;
		// ����ÿ���ֶεĿ��Ϊ 10�������
		const int fieldWidth = 15;
		//ʹ��forward_list�ĵ�������������ʼ���õ�ԭ��������������ԵĻ���Ϣ 
		while (itBegin != itEnd) {
			//���ԭ���𳵿��ж�ӦĿ�ĵصĳ��Σ��������Ӧ�ĳ�����Ϣ
			if (itBegin->inform[2] == destination) {

				if (count == 0) {
					system("cls");
					cout << "Ŀ�ĵ�Ϊ " << destination << " �Ļ��У�" << endl;

					// �����ͷ�������������
					cout << left << setw(fieldWidth) << "����"
						<< left << setw(fieldWidth) << "ʼ����"
						<< left << setw(fieldWidth) << "Ŀ�ĵ�"
						<< left << setw(fieldWidth) << "����ʱ��"
						<< left << setw(fieldWidth) << "�ִ�ʱ��"
						<< left << setw(fieldWidth) << "��Ʊ����" << endl;

				}
				// ��������� inform Ԫ��
				cout << left << setw(fieldWidth) << (*itBegin).inform[0]
					<< left << setw(fieldWidth) << (*itBegin).inform[1]
					<< left << setw(fieldWidth) << (*itBegin).inform[2]
					<< left << setw(fieldWidth) << (*itBegin).inform[3]
					<< left << setw(fieldWidth) << (*itBegin).inform[4]
					<< left << setw(fieldWidth) << (*itBegin).inform[5] << endl;
				//�ж�Ӧ���Σ������������ʾ��Ϣ
				judgment = false;
				count++;
			}
			itBegin++;

		}

		cout << endl << "����0�ص��û����Ҳ˵����棺";
		//�û�����0���ɷ��ص���һ�������������Ҳ˵�����
		int returnSeletion;
		while (true) {
			returnSeletion = getSelectDigit();
			if (returnSeletion == -1) {
				system("pause");
				cout << endl << "�������µ�ѡ�";
				continue;
			}
			break;
		}
		if (returnSeletion == 0) {
			return;
		}

		//����û�������Ŀ�ĵز��Ҳ���ʱ�����û��ٴ�ѡ����һ��Ƿ��ص���һ�����������û����Ҳ˵�
		if (judgment) {
			system("cls");
			cout << "�����桷��¼����ѯ���Ρ�ͨ��Ŀ�ĵز���" << endl << endl;
			cout << "��Ŀ�ĵز����ڣ�����1�ص��û��˵�������2��������Ŀ�ĵأ�";

			//�û������Ŀ�ĵز����ڣ��ٴ�ѡ����˻�����������
			int desSeletion;
			while (true) {
				desSeletion = getSelectDigit();
				if (desSeletion == -1) {
					system("pause");
					cout << endl << "�������µ�ѡ�";
					continue;
				}
				break;
			}

			//�û�ѡ����Ų��һ��ǻص��û����Ҳ˵�
			switch (desSeletion) {
				//���ص��û����Ҳ˵������˻ص���һ�����øú����ĺ���
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

//�������ܣ�����ʼ���ز�ѯ����Ϣ
/*forword_list ������Ʊ����
������ʱ��������ȡʼ���أ������Ա������������Ϣ*/
//ԭ����Ϣ�� "8primordialInformationBase.txt" 
void fromSearch(forward_list<yuanTrain>& yuanTrainList) {
	system("cls");
	cout << "�����桷��¼����ѯ���Ρ�ͨ��ʼ���ز���" << endl << endl;
	cout << "������ʼ���أ�";

	//����bool���ͱ������ж��Ƿ����û���Ҫ��ʼ���صĳ���
	bool judgment = true;
	//�ٴζ���bool���ͱ������ж��Ƿ�Ҫ��whileѭ�������ÿͻ��ٴ�����ʼ����
	bool Judgment = false;

	while (true) {
		//����û�������ʼ����Ѱ�Ҳ���ʱѡ���ٴβ��ң����������û�����
		if (Judgment) {
			system("cls");
			cout << "�����桷��¼����ѯ���Ρ�ͨ��ʼ���ز���" << endl << endl;
			cout << "���������ʼ���أ�";
		}

		//�����û������ʼ���صı���
		string origin;
		//���û��һ��û�пո�����룬������û��Ƿ�����ո�
		while (true) {
			origin = getInputStringLine();
			if (origin == "") {
				system("pause");
				cout << endl << "����������:";
				continue;
			}
			break;
		}

		forward_list<yuanTrain>::iterator itBegin = yuanTrainList.begin();
		forward_list<yuanTrain>::iterator itEnd = yuanTrainList.end();

		int count = 0;
		// ����ÿ���ֶεĿ��Ϊ 10�������
		const int fieldWidth = 15;
		//ʹ��forward_list�ĵ�������������ʼ���õ�ԭ��������������ԵĻ���Ϣ 
		while (itBegin != itEnd) {

			//���ԭ���𳵿��ж�Ӧʼ���صĳ��Σ��������Ӧ�ĳ�����Ϣ
			if ((*itBegin).inform[1] == origin) {
				if (count == 0) {
					// ���ʼ����
					cout << "ʼ����Ϊ " << origin << " �Ļ��У�" << endl;
					// �����ͷ�������������
					cout << left << setw(fieldWidth) << "����"
						<< left << setw(fieldWidth) << "ʼ����"
						<< left << setw(fieldWidth) << "Ŀ�ĵ�"
						<< left << setw(fieldWidth) << "����ʱ��"
						<< left << setw(fieldWidth) << "�ִ�ʱ��"
						<< left << setw(fieldWidth) << "��Ʊ����" << endl;
				}
				// ��������� inform Ԫ��
				cout << left << setw(fieldWidth) << (*itBegin).inform[0]
					<< left << setw(fieldWidth) << (*itBegin).inform[1]
					<< left << setw(fieldWidth) << (*itBegin).inform[2]
					<< left << setw(fieldWidth) << (*itBegin).inform[3]
					<< left << setw(fieldWidth) << (*itBegin).inform[4]
					<< left << setw(fieldWidth) << (*itBegin).inform[5] << endl;
				//�ж�Ӧ���Σ������������ʾ��Ϣ
				judgment = false;

				count++;
			}
			itBegin++;
		}

		cout << endl << "����0�ص��û����Ҳ˵����棺";
		//�û�����0���ɷ��ص���һ�������������Ҳ˵�����
		int returnSeletion;
		while (true) {
			returnSeletion = getSelectDigit();
			if (returnSeletion == -1) {
				system("pause");
				cout << endl << "�������µ�ѡ�";
				continue;
			}
			break;
		}
		if (returnSeletion == 0) {
			return;
		}

		//����û�������ʼ���ز��Ҳ���ʱ�����û��ٴ�ѡ����һ��Ƿ��ص���һ�����������û����Ҳ˵�
		if (judgment) {
			system("cls");
			cout << "�����桷��¼����ѯ���Ρ�ͨ��ʼ���ز���" << endl << endl;
			cout << "��Ŀ�ĵز����ڣ�����1�ص��û��˵�������2��������ʼ���أ�";

			//�û������ʼ���ز����ڣ��ٴ�ѡ����˻�����������
			int desSeletion;
			while (true) {
				desSeletion = getSelectDigit();
				if (desSeletion == -1) {
					system("pause");
					cout << endl << "����������:";
					continue;
				}
				break;
			}

			//�û�ѡ����Ų��һ��ǻص��û����Ҳ˵�
			switch (desSeletion) {
				//���ص��û����Ҳ˵������˻ص���һ�����øú����ĺ���
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

//�������ܣ�����ʼ����-Ŀ�ĵز�ѯ����Ϣ
/*forword_list ������Ʊ����
������ʱ��������ȡʼ����-Ŀ�ĵأ������Ա������������Ϣ*/
//ԭ����Ϣ�� "8primordialInformationBase.txt" 
void fromToSearch(forward_list<yuanTrain>& yuanTrainList) {
	system("cls");
	cout << "�����桷��¼����ѯ���Ρ�ͨ��ʼ���ء�Ŀ�ĵ��ض�����" << endl << endl;
	cout << "������ʼ���أ�";

	//����bool���ͱ������ж��Ƿ����û���Ҫ��ʼ���ء�Ŀ�ĵصĳ���
	bool judgment = true;
	//�ඨ��bool���ͱ������ж��Ƿ�Ҫ���û��ٴμ�������Ŀ�ĵ�
	bool Judgment = false;

	//�ඨ��bool���ͱ������ж��Ƿ�Ҫ���û��״ν�������ʼ����
	bool judge = true;


	while (true) {


		//����û�������ʼ���ء�Ŀ�ĵ�Ѱ�Ҳ���ʱѡ���ٴβ��ң����ٴ����û���������ʼ����
		if (judgment) {
			system("cls");
			cout << "�����桷��¼����ѯ���Ρ�ͨ��ʼ���ء�Ŀ�ĵ��ض�����" << endl << endl;
			cout << "���������ʼ���أ�";
		}

		//�����û������ʼ���صı���
		string origin;
		while (true) {
			origin = getInputStringLine();
			if (origin == "") {
				system("pause");
				cout << endl << "����������:";
				continue;
			}
			break;
		}

		//�״λ������ʾ�������û���������Ŀ�ĵ�
		if (judge) {
			system("cls");
			cout << "�����桷��¼����ѯ���Ρ�ͨ��ʼ���ء�Ŀ�ĵ��ض�����" << endl << endl;
			cout << "������Ŀ�ĵأ�";
		}

		//����û�������ʼ���ء�Ŀ�ĵ�Ѱ�Ҳ���ʱѡ���ٴβ��ң����ٴ����û���������ʼ����
		if (Judgment) {
			system("cls");
			cout << "�����桷��¼����ѯ���Ρ�ͨ��ʼ���ء�Ŀ�ĵ��ض�����" << endl << endl;
			cout << "���������Ŀ�ĵأ�";
		}

		//�����û������Ŀ�ĵصı���
		string destination;
		while (true) {
			destination = getInputStringLine();
			if (destination == "") {
				system("pause");
				cout << endl << "����������:";
				continue;
			}
			break;
		}

		forward_list<yuanTrain>::iterator itBegin = yuanTrainList.begin();
		forward_list<yuanTrain>::iterator itEnd = yuanTrainList.end();

		// ����ÿ���ֶεĿ��Ϊ 10�������
		const int fieldWidth = 15;
		int count = 0;
		//ʹ��forward_list�ĵ�������������ʼ���õ�ԭ��������������ԵĻ���Ϣ 
		while (itBegin != itEnd) {

			//���ԭ���𳵿��ж�Ӧʼ���ء�Ŀ�ĵصĳ��Σ��������Ӧ�ĳ�����Ϣ
			if ((*itBegin).inform[1] == origin && (*itBegin).inform[2] == destination) {
				if (count == 0) {
					system("cls");
					cout << origin << "��" << destination << "�ĳ����У�" << endl;
					// �����ͷ�������������
					cout << left << setw(fieldWidth) << "����"
						<< left << setw(fieldWidth) << "ʼ����"
						<< left << setw(fieldWidth) << "Ŀ�ĵ�"
						<< left << setw(fieldWidth) << "����ʱ��"
						<< left << setw(fieldWidth) << "�ִ�ʱ��"
						<< left << setw(fieldWidth) << "��Ʊ����" << endl;
				}
				// ��������� inform Ԫ�أ�ÿ���ֶο��Ϊ 10
				cout << left << setw(fieldWidth) << (*itBegin).inform[0]
					<< left << setw(fieldWidth) << (*itBegin).inform[1]
					<< left << setw(fieldWidth) << (*itBegin).inform[2]
					<< left << setw(fieldWidth) << (*itBegin).inform[3]
					<< left << setw(fieldWidth) << (*itBegin).inform[4]
					<< left << setw(fieldWidth) << (*itBegin).inform[5] << endl;
				//�ж�Ӧ���Σ������������ʾ��Ϣ
				judgment = true;
				Judgment = true;

				count++;
			}
			itBegin++;

		}

		cout << endl << "����0�ص��û����Ҳ˵����棺";
		//�û�����0���ɷ��ص���һ�������������Ҳ˵�����
		int returnSeletion;
		while (true) {
			returnSeletion = getSelectDigit();
			if (returnSeletion == -1) {
				system("pause");
				cout << endl << "�������µ�ѡ�";
				continue;
			}
			break;
		}
		if (returnSeletion == 0) {
			return;
		}

		//����û�������ʼ���ء�Ŀ�ĵز��Ҳ���ʱ�����û��ٴ�ѡ����һ��Ƿ��ص���һ�����������û����Ҳ˵�
		if (judgment) {

			system("cls");
			cout << "�����桷��¼����ѯ���Ρ�ͨ��ʼ���ء�Ŀ�ĵ��ض�����" << endl << endl;
			cout << "��ʼ���ء�Ŀ�ĵز����ڣ�����1�ص��û��˵�������2��������ʼ���أ�";

			//�û������ʼ���ء�Ŀ�ĵز����ڣ��ٴ�ѡ����˻�����������
			int desSeletion;
			while (true) {
				desSeletion = getSelectDigit();
				if (desSeletion == -1) {
					system("pause");
					cout << endl << "�������µ�ѡ�";
					continue;
				}
				break;
			}

			//�û�ѡ����Ų��һ��ǻص��û����Ҳ˵�
			switch (desSeletion) {
				//���ص��û����Ҳ˵������˻ص���һ�����øú����ĺ���
			case 1:
				return;
				//���²���
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

//�������ܣ�������л�Ʊ��Ϣ
/*forword_list ���������Ʊ����
ԭ����Ϣ�� "8primordialInformationBase.txt" */
void showAll(forward_list<yuanTrain>& yuanTrainList) {
	system("cls");
	cout << "�����桷��¼����ѯȫ��������Ϣ" << endl << endl;
	cout << "����Ϊȫ��������Ϣ��" << endl;

	// ����ÿ���ֶεĿ��Ϊ 10�������
	const int fieldWidth = 15;

	// �����ͷ�������������
	cout << left << setw(fieldWidth) << "����"
		<< left << setw(fieldWidth) << "ʼ����"
		<< left << setw(fieldWidth) << "Ŀ�ĵ�"
		<< left << setw(fieldWidth) << "����ʱ��"
		<< left << setw(fieldWidth) << "�ִ�ʱ��"
		<< left << setw(fieldWidth) << "��Ʊ����" << endl;

	forward_list<yuanTrain>::iterator itBegin = yuanTrainList.begin();
	forward_list<yuanTrain>::iterator itEnd = yuanTrainList.end();

	//ʹ��forward_list�ĵ�������������ʼ���õ�ԭ��������������ԵĻ���Ϣ 
	while (itBegin != itEnd) {
		// ��������� inform Ԫ�أ�ÿ���ֶο��Ϊ 10
		cout << left << setw(fieldWidth) << (*itBegin).inform[0]
			<< left << setw(fieldWidth) << (*itBegin).inform[1]
			<< left << setw(fieldWidth) << (*itBegin).inform[2]
			<< left << setw(fieldWidth) << (*itBegin).inform[3]
			<< left << setw(fieldWidth) << (*itBegin).inform[4]
			<< left << setw(fieldWidth) << (*itBegin).inform[5] << endl;
		itBegin++;
	}

	while (true) {
		cout << endl << "����0���ɷ��ز��ҽ���:";
		int reTurn;
		while (true) {
			reTurn = getSelectDigit();
			if (reTurn == -1) {
				system("pause");
				cout << endl << "�������µ�ѡ�";
				continue;
			}
			break;
		}
		if (reTurn == 0)
			return;
	}
}

// �������ܣ��û���Ʊ
// ͨ�����ι���
/* ��ԭ����Ϣ�� "8primordialInformationBase.txt" �����Ƿ��ж�Ӧ����
�о�¼���û������ "9theUserBuysTheLibrary.txt" */
void buyTicket(string username, forward_list<yuanTrain>& yuanTrainList, forward_list<trainTicket>& trainTicketList) {
	bool judgment = true; // �жϵ�һ�����뻹�Ƕ������
	bool judge = false;   // �ж��Ƿ����û�Ҫ����ĳ���

	while (true) {
		if (judgment) {
			system("cls");
			cout << "�����桷��¼������Ʊ" << endl << endl;
			cout << "��������Ҫ����ĳ�Ʊ�ĳ��Σ�";
			judgment = false;
		}
		else {
			system("cls");
			cout << "�����桷�û�����¼����¼�ɹ����û��˵�������Ʊ" << endl << endl;
			cout << "��������복�Σ�";
		}

		string trip;
		while (true) {
			trip = getInputStringLine();
			if (trip == "") {
				system("pause");
				cout << endl << "����������:";
				continue;
			}
			break;
		}

		//����û���Ҫ����ĳ�Ʊ����Ϊ0���򲻿ɹ���
		// ���Ҷ�Ӧ���εĻ𳵽ڵ�
		yuanTrain* foundTrain = findTrainLinkedListNode(yuanTrainList, trip);

		if (foundTrain != nullptr) {
			// �ҵ���ƥ��Ļ���Ϣ
			int ticketCount = stoi(foundTrain->inform[5]); // ��ȡ��ǰ��Ʊ������ת��Ϊ����

			if (ticketCount > 0) {
				// ��Ʊ��������0�����Թ���
			}
			else {
				int isconfirm;
				cout << "��Ʊ����Ϊ0���޷���������0����" << endl << "�����룺";
				while (true) {
					isconfirm = getSelectDigit();
					if (isconfirm == -1) {
						system("pause");
						cout << endl << "�������µ�ѡ�";
						continue;
					}
					break;
				}
				if (isconfirm == 0) {
					return;
				}
				cout << "��������ȷ��ѡ�" << endl;
			}
		}

		//�û��Ƿ�ȷ�Ϲ���
		while (true) {
			int isconfirm;
			cout << "��ȷ���Ƿ�Ҫ���򳵴�Ϊ '" << trip << "' �ĳ�Ʊ" << endl;
			cout << "����1��ʾȷ�ϣ�����0����" << endl;
			cout << "������:";
			while (true) {
				isconfirm = getSelectDigit();
				if (isconfirm == -1) {
					system("pause");
					cout << endl << "�������µ�ѡ�";
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
			cout << "��������ȷ��ѡ�" << endl;
		}

		vector<string> tempinfor(2);

		forward_list<yuanTrain>::iterator itBegin = yuanTrainList.begin();
		forward_list<yuanTrain>::iterator itEnd = yuanTrainList.end();

		while (itBegin != itEnd) {
			if (trip == (*itBegin).inform[0]) { // �˴���Ϊ�Ƚϳ�����Ϣ
				tempinfor[0] = username;
				tempinfor[1] = trip;
				judge = true;

				// ���»�Ʊ����
				trainTicket newTicket;
				newTicket.ticketInfo = tempinfor;
				trainTicketList.push_front(newTicket);

				//�����˳�Ʊ����Ӧ���εĳ�Ʊ������һ 
				int temp = stoi((*itBegin).inform[5]) - 1;
				(*itBegin).inform[5] = to_string(temp);

				//�����˳�Ʊ �������Ա���� ��10ticketBuyersDatabase.txt��д��
				ifstream infile("TicketBuyersDatabase.txt"); // ���ļ��Զ�ȡ����
				vector<string> tempfor;
				string line;
				string trainNumber;
				while (getline(infile, line)) {
					istringstream iss(line);//���ļ���ȡ��һ��ת����������
					iss >> trainNumber;//���복��
					// ��������Դ����ȡ��ÿһ������
					if (trainNumber == (*itBegin).inform[0]) {
						// ��������Ը�����Ҫ�Զ�ȡ�����ݽ��д���
						line += username;
						line += ' ';
						tempfor.push_back(line);
						continue;
					}
					tempfor.push_back(line);
				}
				// �ر��ļ�
				infile.close();

				ofstream fout("TicketBuyersDatabase.txt", ios::out); // 0���ļ���д��������
				// �� tempfor �е�����д���ļ�
				for (const string& line : tempfor) {
					fout << line << endl;
				}
				// �ر��ļ�
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
			cout << "�����桷��¼������Ʊ" << endl << endl;
			cout << "����ɹ�������0�����û��˵���";
			int reTurn;
			while (true) {
				reTurn = getSelectDigit();
				if (reTurn == -1) {
					system("pause");
					cout << endl << "�������µ�ѡ�";
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
			cout << "�����桷��¼������Ʊ" << endl << endl;
			cout << "�ó��β����ڣ�����1�����û��˵�������2�������복�Σ�";
			int seletion;
			while (true) {
				seletion = getSelectDigit();
				if (seletion == -1) {
					system("pause");
					cout << endl << "�������µ�ѡ�";
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

//�������ܣ��г̲�ѯ
//ͨ���û�����ѯ
//�û������ "8primordialInformationBase.txt" 
void findItinerary(forward_list<trainTicket>& trainTicketList, forward_list<yuanTrain>& yuanTrainList, const string& username) {
	// �����洢�û�����ĳ�����Ϣ������
	vector<string> purchasedTrains;

	// �û����������ĵ�����
	forward_list<trainTicket>::iterator itBegin = trainTicketList.begin();
	forward_list<trainTicket>::iterator itEnd = trainTicketList.end();

	// �ڱ����û������ʱ����¼�û�����ĳ�����Ϣ
	while (itBegin != itEnd) {
		if (username == (*itBegin).ticketInfo[0]) {
			purchasedTrains.push_back((*itBegin).ticketInfo[1]); // ��ƥ��ĳ�����Ϣ�洢����
		}
		itBegin++;
	}

	// ����г���Ϣ
	if (!purchasedTrains.empty()) {
		system("cls");
		cout << "�����桷��¼���г̲�ѯ" << endl << endl;
		cout << "�����г����£�" << endl;

		// ����ÿ���ֶεĿ��Ϊ 10�������
		const int fieldWidth = 15;

		// �����ͷ�������������
		cout << left << setw(fieldWidth) << "����"
			<< left << setw(fieldWidth) << "ʼ����"
			<< left << setw(fieldWidth) << "Ŀ�ĵ�"
			<< left << setw(fieldWidth) << "����ʱ��"
			<< left << setw(fieldWidth) << "�ִ�ʱ��" << endl;

		// �����洢�ĳ�����Ϣ���������Ӧ���г���Ϣ
		for (auto trainIter = purchasedTrains.begin(); trainIter != purchasedTrains.end(); ++trainIter) {
			// ��ԭ����Ϣ���в��Ҷ�Ӧ�ĳ�����Ϣ
			for (auto infoIter = yuanTrainList.begin(); infoIter != yuanTrainList.end(); ++infoIter) {
				if (*trainIter == (*infoIter).inform[0]) {
					// ��������� inform Ԫ�أ�ÿ���ֶο��Ϊ 10
					cout << left << setw(fieldWidth) << (*infoIter).inform[0]
						<< left << setw(fieldWidth) << (*infoIter).inform[1]
						<< left << setw(fieldWidth) << (*infoIter).inform[2]
						<< left << setw(fieldWidth) << (*infoIter).inform[3]
						<< left << setw(fieldWidth) << (*infoIter).inform[4] << endl;
					break;
				}
			}
		}

		// �û��˳��г̲�ѯѡ��
		/*cout << endl << "����1������һ����:";
		int selection;
		while (true) {
			selection = getSelectDigit();
			if (selection == -1) {
				system("pause");
				cout << endl << "�������µ�ѡ�";
				continue;
			}
			break;
		}
		if (selection == 1)
			return;*/
		system("pause");
	}
	else {
		// ����û�û�й���Ʊ���������ʾ��Ϣ
		system("cls");
		cout << "�����桷��¼���г̲�ѯ" << endl << endl;
		cout << "��Ŀǰû���κ��г�" << endl;
		/*int selection;
		while (true) {
			selection = getSelectDigit();
			if (selection == -1) {
				system("pause");
				cout << endl << "�������µ�ѡ�";
				continue;
			}
			break;
		}
		if (selection == 1)
			return;*/
		system("pause");
	}
}

//�������ܣ��û���Ʊ
void deleTicket(forward_list<trainTicket>& trainTicketList, forward_list<yuanTrain>& yuanTrainList) {
	while (true) {
		//�ж��û����״�������Ƕ������ 
		bool judge = true;
		//�ж��Ƿ����û�Ҫ�˵���Ʊ
		bool judgeMent = true;

		if (judge) {
			system("cls");
			cout << "�����桷��¼����Ʊ" << endl << endl;
			cout << "��������Ҫ��Ʊ�ĳ��Σ�";
		}
		else {
			system("cls");
			cout << "�����桷��¼����Ʊ" << endl << endl;
			cout << "���������Ҫ��Ʊ�ĳ��Σ�";
		}

		//��¼�û�ɾ���ĳ��� ���� 
		string trip;
		while (true) {
			trip = getInputStringLine();
			if (trip == "") {
				system("pause");
				cout << endl << "����������:";
				continue;
			}
			break;
		}

		//�û��Ƿ�ȷ����Ʊ
		while (true) {
			int isconfirm;
			cout << "��ȷ���Ƿ�Ҫ�˵�����Ϊ '" << trip << "' �ĳ�Ʊ" << endl;
			cout << "����1��ʾȷ�ϣ�����0����" << endl;
			cout << "������:";
			while (true) {
				isconfirm = getSelectDigit();
				if (isconfirm == -1) {
					system("pause");
					cout << endl << "�������µ�ѡ�";
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
			cout << "��������ȷ��ѡ�" << endl;
		}

		//�û����������ĵ�����
		//�û����������ĵ�һ��Ԫ�صĵ����� 
		forward_list<trainTicket>::iterator itBegin = trainTicketList.begin();
		/*ָ���û����������ĵ�һ��Ԫ�ص�ǰһ��λ�ã�������¼ͷ��������ǰһ��λ�ã�
		��������ʹ��erase_afterɾ���ҵ���Ҫɾ���Ľڵ� */
		forward_list<trainTicket>::iterator itbegin = trainTicketList.before_begin();
		forward_list<trainTicket>::iterator itEnd = trainTicketList.end();

		while (itBegin != itEnd) {
			if (trip == (*itBegin).ticketInfo[1]) {

				//�˳�Ʊ����Ӧ���ε�������һ
				yuanTrain* foundTrain = findTrainLinkedListNode(yuanTrainList, trip);
				if (foundTrain != nullptr) {
					// �ҵ���ƥ��Ļ���Ϣ������Ʊ������һ
					int ticketCount = stoi(foundTrain->inform[5]); // ��ȡ��ǰ��Ʊ������ת��Ϊ����
					ticketCount++; // ���ٳ�Ʊ����
					foundTrain->inform[5] = to_string(ticketCount); // ���³�Ʊ����
				}

				//�˳�Ʊ �������Ա���� ����Ӧ��10ticketBuyersDatabase.txt��ɾ��
				ifstream infile("TicketBuyersDatabase.txt"); // ���ļ��Զ�ȡ����
				vector<string> tempfor;
				string line;
				string trainNumber;
				while (getline(infile, line)) {
					istringstream iss(line);//���ļ���ȡ��һ��ת����������
					iss >> trainNumber;//���복��
					// ��������Դ����ȡ��ÿһ������
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
				// �ر��ļ�
				infile.close();

				ofstream ofout("TicketBuyersDatabase.txt", ios::out); // ���ļ���д��������
				// �� tempfor �е�����д���ļ�
				for (const string& line : tempfor) {
					ofout << line << endl;
				}
				// �ر��ļ�
				ofout.close();

				//ɾ���û���Ʊ�Ľڵ� 
				trainTicketList.erase_after(itbegin);

				//���ô��ļ���ʽ����ļ��е�������Ϣ
				// ���ļ�ʱָ�� ios::trunc ��־������ļ�����
				ofstream fout("TheUserBuysTheLibrary.txt", ios::out | ios::trunc);
				itBegin = trainTicketList.begin();
				itEnd = trainTicketList.end();
				//��ɾ������������¶����ļ�
				while (itBegin != itEnd) {
					fout << (*itBegin).ticketInfo[0] << " " << (*itBegin).ticketInfo[1] << endl;
					itBegin++;
				}
				fout.close();

				judgeMent = false;
				cout << endl << "��Ʊ�ɹ�������1�����û��˵���";
				int selection;
				while (true) {
					selection = getSelectDigit();
					if (selection == -1) {
						system("pause");
						cout << endl << "�������µ�ѡ�";
						continue;
					}
					break;
				}
				if (selection == 1)
					return;

				//δ�ҵ��û�Ҫ��Ʊ�ĳ��� 
			}
			// ���µ�����λ��
			itbegin = itBegin;
			++itBegin;
		}
		if (judgeMent) {
			//�û�ѡ��ص��û��˵����Ǽ�������Ҫ��Ʊ�ĳ��� 
			system("cls");
			cout << "�����桷��¼����Ʊ"
				<< endl << endl << "��δ����ó��εĳ�Ʊ������1�ص��û��˵�������2��������Ҫ��Ʊ�ĳ��Σ�";
			int selection;
			while (true) {
				selection = getSelectDigit();
				if (selection == -1) {
					system("pause");
					cout << endl << "�������µ�ѡ�";
					continue;
				}
				break;
			}
			if (selection == 1) {
				return;
			}
			else if (selection == 2) {
				//�ٴ�ѡ�����룬�û���ʾ��仯 
				judge = false;
				break;
			}
		}
	}
}

//��������:�û���ǩ 
void userChange(forward_list<trainTicket>& trainTicketList, forward_list<yuanTrain>& yuanTrainList) {
	//�Ƿ����û�Ҫ��ǩ����
	bool judegement = true;
	
	while (true) {
		system("cls");
		cout << "�����桷��¼����ǩ" << endl << endl;
		cout << "��������Ҫ��ǩ�ĳ��Σ�";
		//��ǩ���α��� 
		string origtrip;
		while (true) {
			origtrip = getInputStringLine();
			if (origtrip == "") {
				system("pause");
				cout << endl << "����������:";
				continue;
			}
			break;
		}

		//�û��Ƿ�ȷ�ϸ�ǩ
		while (true) {
			int isconfirm;
			cout << "��ȷ���Ƿ�Ҫ��ǩ����Ϊ '" << origtrip << "' �ĳ�Ʊ" << endl;
			cout << "����1��ʾȷ�ϣ�����0����" << endl;
			cout << "������:";
			while (true) {
				isconfirm = getSelectDigit();
				if (isconfirm == -1) {
					system("pause");
					cout << endl << "�������µ�ѡ�";
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
			cout << "��������ȷ��ѡ�" << endl;
		}

		/*ʹ�õ����������û����������
		�Աȸ�ǩ���Σ��ҵ���ɾ���ڵ㣬Ȼ������½ڵ㣬
		���ļ���ʽΪ����ļ�������¼���µ��û�������Ϣ */
		//��Ҫʹ��������������һ��ָ��ͷԪ�أ���һ��ָ��ͷԪ�ص�ǰһ��λ�� 
		forward_list<trainTicket>::iterator itBegin = trainTicketList.begin();
		forward_list<trainTicket>::iterator itBeforeBegin = trainTicketList.before_begin();
		forward_list<trainTicket>::iterator itEnd = trainTicketList.end();

		while (itBegin != itEnd) {
			if ((*itBegin).ticketInfo[1] == origtrip) {
				judegement = true;

				//�ж��û���һ�������³��λ��Ƕ�������³��� 
				bool judgement = true;

				if (judgement) {
					system("cls");
					cout << "�����桷��¼����ǩ��������ԭ������" << endl << endl;
					cout << "�������³��Σ�";
				}
				else {
					system("cls");
					cout << "�����桷��¼����ǩ��������ԭ������" << endl << endl;
					cout << "����������³��Σ�";
				}

				//�³��α��� 
				string newtrip;
				while (true) {
					newtrip = getInputStringLine();
					if (newtrip == "") {
						system("pause");
						cout << endl << "����������:";
						continue;
					}
					break;
				}

				//�û��Ƿ�ȷ�ϸ�ǩ
				while (true) {
					int isconfirm;
					cout << "��ȷ���Ƿ�Ҫ������Ϊ '" << origtrip << "' �ĳ�Ʊ��ǩΪ ��" << newtrip << "' " << endl;
					cout << "����1��ʾȷ�ϣ�����0����" << endl;
					cout << "������:";
					while (true) {
						isconfirm = getSelectDigit();
						if (isconfirm == -1) {
							system("pause");
							cout << endl << "�������µ�ѡ�";
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
					cout << "��������ȷ��ѡ�" << endl;
				}

				//�ж��Ƿ����û���Ҫ���³���bool���� 
				bool Judge = true;

				//�ж��³���ԭ����Ϣ���Ƿ����
				//��YuanChuXinXiKu.txt�� 
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
					cout << "�����桷��¼����ǩ" << endl << endl;
					cout << "���³��β����ڣ�����0������һ���棬����1���������³���";
					int selection;
					while (true) {
						selection = getSelectDigit();
						if (selection == -1) {
							system("pause");
							cout << endl << "�������µ�ѡ�";
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
					//��¼��ǩ���û����Լ��µĳ�����Ϣ 
					vector<string> Info(2);
					//��Ҫɾ���Ľڵ���û�����ֵ���µ��ݴ�ڵ� 
					Info[0] = (*itBegin).ticketInfo[0];
					Info[1] = newtrip;

					//��ʱ�ڵ� 
					trainTicket tempticket;
					//������Ϣ������ʱ�ڵ� 
					for (int i = 0; i < 2; i++) {
						tempticket.ticketInfo.push_back(Info[i]);
					}


					//�û���ǩ������ǩǰ�ĳ��γ�Ʊ����+1���³��γ�Ʊ����-1
					// ����ԭʼ���κ��³��εĻ𳵽ڵ�
					yuanTrain* oldTrain = findTrainLinkedListNode(yuanTrainList, origtrip);
					yuanTrain* newTrain = findTrainLinkedListNode(yuanTrainList, newtrip);

					if (oldTrain != nullptr && newTrain != nullptr) {
						// �ҵ���ԭʼ���κ��³��ε�ƥ����Ϣ
						int oldTicketCount = stoi(oldTrain->inform[5]); // ��ȡԭʼ���εĳ�Ʊ������ת��Ϊ����
						int newTicketCount = stoi(newTrain->inform[5]); // ��ȡ�³��εĳ�Ʊ������ת��Ϊ����

						if (newTicketCount > 0) {
							// �³������㹻�ĳ�Ʊ���������Խ��и�ǩ
							oldTicketCount++; // ԭʼ���εĳ�Ʊ������1
							newTicketCount--; // �³��εĳ�Ʊ������1
							oldTrain->inform[5] = to_string(oldTicketCount); // ����ԭʼ���εĳ�Ʊ����
							newTrain->inform[5] = to_string(newTicketCount); // �����³��εĳ�Ʊ����
							// ��ǩ�ɹ�
						}
						else {
							// ��ǩʧ�ܣ��³�������Ϊ0���޷���ǩ
							int isconfirm;
							cout << "��ǩ�³�������Ϊ0���޷���ǩ������0����" << endl << "������:";
							while (true) {
								isconfirm = getSelectDigit();
								if (isconfirm == -1) {
									system("pause");
									cout << endl << "�������µ�ѡ�";
									continue;
								}
								break;
							}
							if (isconfirm == 0) {
								return;
							}
							cout << "��������ȷ��ѡ�" << endl;
						}
					}
					//��ǩ �������Ա���� ����Ӧ��10ticketBuyersDatabase.txt������
					ifstream infile("TicketBuyersDatabase.txt"); // ���ļ��Զ�ȡ����
					vector<string> tempfor;
					string line;
					string trainNumber;
					while (getline(infile, line)) {
						istringstream iss(line);//���ļ���ȡ��һ��ת����������
						iss >> trainNumber;//���복��
						// ��������Դ����ȡ��ÿһ������
						//��ǩ��ԭ���ν��û�ɾȥ
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
						//��ǩ�ٴ��³��μ����û�
						if (trainNumber == Info[1]) {
							// ��������Ը�����Ҫ�Զ�ȡ�����ݽ��д���
							line += Info[0];
							line += ' ';
							tempfor.push_back(line);
							continue;
						}
						tempfor.push_back(line);
					}
					// �ر��ļ�
					infile.close();

					ofstream ofout("TicketBuyersDatabase.txt", ios::out); // ���ļ���д��������
					// �� tempfor �е�����д���ļ�
					for (const string& line : tempfor) {
						ofout << line << endl;
					}
					// �ر��ļ�
					ofout.close();


					//��ɾ��������� 
					trainTicketList.erase_after(itBeforeBegin);
					trainTicketList.insert_after(itBeforeBegin, tempticket);

					//�����������ɺ�������ļ��������ݵ���ʽ���ļ�����������Ϣ¼���ļ����ر�
					// ���ļ�ʱָ�� ios::trunc ��־������ļ�����
					ofstream fout("TheUserBuysTheLibrary.txt", ios::out | ios::trunc);
					itBegin = trainTicketList.begin();
					itBeforeBegin = trainTicketList.before_begin();
					while (itBegin != itEnd) {
						fout << (*itBegin).ticketInfo[0] << " " << (*itBegin).ticketInfo[1] << endl;
						itBegin++;
					}
					fout.close();
					system("cls");
					cout << "�����桷��¼����ǩ��������ԭ������" << endl << endl;
					cout << "��ǩ�ɹ�������1������һ���棺";
					int selereturn = 1;
					while (true) {
						selereturn = getSelectDigit();
						if (selereturn == -1) {
							system("pause");
							cout << endl << "�������µ�ѡ�";
							continue;
						}
						break;
					}
					if (selereturn == 1) {
						return;
					}
				}
			}
			// ���µ�����λ��
			itBeforeBegin = itBegin;
			++itBegin;
		}
		if (judegement) {
			system("cls");
			cout << "�����桷��¼����ǩ" << endl << endl;
			cout << "��δ����ó��εĳ�Ʊ���޷���ǩ������1������һ���棺";
			int selection;
			while (true) {
				selection = getSelectDigit();
				if (selection == -1) {
					system("pause");
					cout << endl << "�������µ�ѡ�";
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

// Ѱ��ԭ����Ϣ�������Ӧ�ڵ�
// ͨ������yuanTrain��������Ҫ���ҵĳ�����Ϣ���գ����ҳɹ��򷵻�
yuanTrain* findTrainLinkedListNode(forward_list<yuanTrain>& yuanTrain, string Trips) {
	for (auto& train : yuanTrain) {
		if (!train.inform.empty() && train.inform[0] == Trips) {
			// �ҵ�ƥ��ĳ�����Ϣ������ָ��ýڵ��ָ��
			return &train;
		}
	}
	// û���ҵ�ƥ��ĳ�����Ϣ�����ؿ�ָ���ʾδ�ҵ�
	return nullptr;
}