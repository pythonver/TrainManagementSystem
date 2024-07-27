
#include"AdministratorMenu.h"

//�������ܣ���ʼ������Ϣ���˻���Ϣ
/*
* ʵ�ֲ��裺
* 1.���ļ�
* 2.ѭ��д��ڵ�
* 3.�ײ嵽����linked
* ����/��������
* Tlinked-����Ϣ����Phash-������Ⱥ��ϣ��,fileName-ԭ����Ϣ��,Filename��Ʊ������Ⱥ��
*/
bool initAdmData(forward_list<trainNode>& trainList, const string& trainFile, unordered_map<string, vector<string>>& orderMap, const string& orderFile) {
    ifstream inFile(trainFile);
    //��ʼ������Ϣ����
    if (!inFile.is_open()) return false;
    vector<string> tempTrainInfo(6);//����Ϣ����
    while (inFile >> tempTrainInfo[0] >> tempTrainInfo[1] >> tempTrainInfo[2] >> tempTrainInfo[3] >> tempTrainInfo[4] >> tempTrainInfo[5]) {
        trainNode tempT = trainNode(tempTrainInfo);//����һ����ʱ�ڵ�
        trainList.push_front(tempT);//����ʱ�ڵ���뵽����
    }
    inFile.close();
    //��ʼ��������Ⱥ��
    inFile.open(orderFile);
    if (!inFile.is_open()) return false;
    string line;
    while (getline(inFile, line)) {
        string trainNumber;//��ϣ���key�������ݴ泵��
        string order;//�û��������ݴ�ÿһ���û�
        vector<string> orderArray;//��ϣ���value, �����ݴ�ĳ���ε������û�

        istringstream iss(line);//���ļ���ȡ��һ��ת����������
        iss >> trainNumber;//���복��
        while (iss >> order)//����������Ⱥ
            orderArray.push_back(order);
        orderMap[trainNumber] = orderArray;
    }
    inFile.close();
    return true;//ȫ����ʼ�����
}
//�������ܣ���ӻ���Ϣ 
/*
* ʵ�ֲ��裺
* 1.ѭ����ȡ��������ݲ������ڽṹ��
* 2.���뵽����
* 3.����д���ļ��������������ݸ���Դ�ļ�
* ����/��������Tlinked-ԭ����Ϣ����
*/
void inputInfo(vector<string>& tempTrainInfo, const unordered_map<string, vector<string>>& orderMap) {
    vector<string> tips = { "����", "������" , "Ŀ�ĵ�", "����ʱ��", "�ִ�ʱ��" };
    for (int i = 0; i < tips.size(); i++) {
        cout << "������" << tips[i] << ':';
        while (true) {
            tempTrainInfo[i] = getInputStringLine();
            if (tempTrainInfo[i] == "")
                cout << "��������" << tips[i] << ':';
            else {
                if (i == 0 && orderMap.find(tempTrainInfo[0]) != orderMap.end()) {
                    tempTrainInfo[0] = "";
                    cout << "�����Ѵ���,�����޸���ǰ���޸�" << endl;
                    cout << "1.������� 0.�˳����" << endl;
                    int select = 1;
                    while (select) {
                        select = getSelectDigit();
                        if (select == -1)
                            cout << "��������ѡ��:";
                        else if (!select)
                            return;
                        else {
                            cout << "���복��:";
                            break;
                        }
                    }
                    continue;
                }
                break;
            }
        }
    }
}
bool addTIF(forward_list<trainNode>& trainList, unordered_map<string, vector<string>>& orderMap) {
    system("cls");
    cout << "�����桷��¼���߼�����Ա����ӳ��μ�������Ϣ" << endl << endl;
    vector<string> tempTraingInfo(6);//�ݴ�������Ϣ
    inputInfo(tempTraingInfo, orderMap);//�������������Ϣ
    if (tempTraingInfo[0] == "")
        return 0;
    //��Ʊ��������ӣ�����Ϊ���ڵ���0������
    cout << "���복Ʊ����:";
    int votes;
    while (1) {
        votes = getSelectDigit();
        if (votes == -1)
            cout << "��Ʊ��������Ϊ��Ч������,�ٴ����룺";
        else
            break;
    }
    tempTraingInfo[5] = to_string(votes);
    //��Ʊ���۵���ӣ�ֻ���Ǵ��ڵ���0������
    int select;
    cout << "�������Ļ���Ϣ��" << endl;
    cout << "����:" << tempTraingInfo[0] << " ʼ����:" << tempTraingInfo[1] << " Ŀ�ĵ�:" << tempTraingInfo[2]
        << " ����ʱ��:" << tempTraingInfo[3] << " �ִ�ʱ��:" << tempTraingInfo[4] << " ��Ʊ����:" << tempTraingInfo[5] << endl;
    cout << "1.ȷ����� 0.ȡ�����";
    cout << "����ѡ��:";
    while (1) {
        select = getSelectDigit();
        if (select == -1)
            cout << "�ٴ�����:";
        else if (select == 1)
            break;
        else if (select == 0)
            return false;
        else
            cout << "����������Чѡ��,�ٴ�����:";
    }
    if (!appendData(tempTraingInfo, "PrimordialInformationBase.txt"))
        return false;
    //��ӵ���Ϣ����
    trainList.push_front(trainNode(tempTraingInfo));
    orderMap[tempTraingInfo[0]] = vector<string>{};
    if (!appendData(vector<string>{tempTraingInfo[0]}, "TicketBuyersDatabase.txt"))
        return false;
    cout << "��ӳɹ�" << endl;
    system("pause");
    return true;//д�����
}
//�������ܣ�׷����ʽд���ļ�
bool appendData(vector<string> writingData, const string& fileName) {
    ofstream outFile(fileName, ios::app);
    if (!outFile.is_open())
        return false;
    for (const string& data : writingData)
        outFile << data << " ";
    outFile << endl;
    return true;
}
//�������ܣ�ɾ������Ϣ
/*
* ʵ�ֲ��裺
* 1.��ȡ�������ɾ���ĳ��νڵ�
* 2.���û�ҵ�������false�����������һ��
* 3.ɾ�����ϵĽڵ�
* 4.����д���ļ��������������ݸ���Դ�ļ�
* ����/��������Tlinked-ԭ����Ϣ����filename-д��/�����ļ���
*/
void eraseTrainInOrder(string eraseTrain) {
    ifstream ifile("TheUserBuysTheLibrary.txt");
    if (!ifile.is_open()) {
        return;
    }
    string line;
    vector<string> res;
    while (getline(ifile, line)) {
        istringstream iss(line);
        string user;
        string train;
        string result;

        iss >> user;
        result = result + user + " ";
        while (iss >> train) {
            if (train != eraseTrain) {
                result = result + train + " ";
            }
        }
        if (result.length() != user.length() + 1)
            res.push_back(result);
    }
    ifile.close();
    ofstream ofile("TheUserBuysTheLibrary.txt", ios::out);
    for (string it : res)
    {
        ofile << it << endl;
    }
    ofile.close();
}
bool eraseTIF(forward_list<trainNode>& trainList, unordered_map<string, vector<string>>& orderMap) {
    system("cls");
    //��������л���Ϣ
    if (!orderMap.size()) {
        cout << "��ǰ���޿�ɾ����";
        system("pause");
        return 0;
    }
    while (1) {
        showAll(trainList, orderMap);
        string Tnum;
        cout << "�����ϱ�����ɾ���Ļ𳵳���" << endl;
        int select = 1;
        while (select) {
            cout << "���복��:";
            Tnum = getInputStringLine();
            if (Tnum == "") {
                cout << "��������ȷ�Ļ𳵳���";
            }
            else if (orderMap.find(Tnum) == orderMap.end()) {
                cout << "�����ڸó���" << endl << "����0�˳�ɾ��,�����������ּ���ɾ��";
                while (1) {
                    select = getSelectDigit();
                    if (select == -1)
                        cout << "�ٴ����룺";
                    else if (select == 0)
                        return false;
                    else
                        break;
                }
            }
            else if (orderMap.find(Tnum) != orderMap.end())
                break;
        }
        auto it = trainList.before_begin();
        auto iq = trainList.begin();
        for (; iq != trainList.end(); it++, iq++) {
            if (iq->trainInfo[0] == Tnum)
                break;
        }
        cout << "��ɾ�� �� ��Ϣ����:" << endl;
        cout << "      " << setw(15) << left << "����" << setw(15) << left << "ʼ����" << setw(15) << left << "Ŀ�ĵ�"
            << setw(15) << left << "����ʱ��" << setw(15) << left << "�ִ�ʱ��"
            << setw(15) << left << "��Ʊ����" << setw(15) << left << "�ѹ�����" << endl;
        cout << "      ";
        for (const string& iq : iq->trainInfo)
            cout << setw(15) << left << iq;
        cout << setw(15) << getNumOfOrder(orderMap, iq->trainInfo[0]);
        cout << endl;

        cout << "��ȷ���Ƿ�ɾ������ " << Tnum << " ����Ϣ(�𳵻�����Ϣ��������Ⱥ)" << endl;
        cout << "���� 0 �˳�ɾ���� ������������ɾ������Ϣ:" << endl;
        while (1) {
            select = getSelectDigit();
            if (select == -1) {
                cout << "����������:";
            }
            else if (!select) {
                cout << "�˳�ɾ��";
                return 0;
            }
            else
                break;
        }
        trainList.erase_after(it);
        resetFile(trainList);
        //���ò�ɾ���û������
        vector<string> Orders = orderMap[Tnum];
        ofstream file("TicketBuyersDatabase.txt", ios::out);
        orderMap.erase(Tnum);
        for (const auto& Key : orderMap) {
            file << Key.first << " ";
            for (const string& order : Key.second)
                file << order << " ";
            file << endl;
        }
        file.close();
        eraseTrainInOrder(Tnum);//���ݳ���
        cout << "ɾ�����" << endl;
        system("pause");
        return 1;
    }
    return 1;
}

//�������ܣ����������Ⱥ
/*
* 1.��ȡ�����
* 2.�ӹ����߹�ϣ���в�ѯ���εĹ�����Ⱥ�͹�������
* ����/��������Phash-������Ⱥ��ϣ�����ڲ�ѯĳ�����Ƿ���ڲ���ѯ�����û��͹�������
*/
bool showOrder(unordered_map<string, vector<string>>& orderMap) {
    system("cls");
    cout << "�����桷��¼������Ա����ѯĳ���εĳ˿��б�" << endl << endl;
    if (orderMap.empty()) {
        cout << "��ǰ���޻𳵣���ǰ�����" << endl;
        system("pause");
        return 0;
    }
    string trainNumber;
    int select = 1;
    while (select) {
        cout << "�������ѯ����" << endl;
        //cin >> trainNumber;
        trainNumber = getInputStringLine();
        if (orderMap.find(trainNumber) != orderMap.end()) {//���ҳ����Ƿ����
            if (!orderMap[trainNumber].size())
                cout << "�ó��������û�����" << endl;
            else {
                cout << "���Σ� " << trainNumber << " �ѹ���" << orderMap[trainNumber].size() << endl;
                cout << "�����û��� " << endl;
                int endlCount = 1;
                for (string& it : orderMap[trainNumber]) {
                    if (endlCount % 8 == 0) {
                        cout << endl << "  ";
                        endlCount = 1;
                    }
                    cout << it << "  " << endl;
                }
            }
        }
        else
            cout << "���β�����" << endl;
        cout << endl;
        cout << "����1�������ҹ����û�, ����0�˳���ѯ" << endl;
        //cin >> select;
        select = getSelectDigit();
    }
    system("pause");
    return 0;
}
//�������ܣ��޸Ļ���Ϣ(�����ɹ�Ʊ����) --��������
/*
* ʵ�ֲ��裺
* 1.��ȡ��������޸ĵĳ��νڵ�
* 2.���û�ҵ�������false�����������һ��
* 3.�޸ķ��ϵĽڵ�����
* 4.����д���ļ���������������ݸ���ԭ�ļ�
* ����/��������Tlinked-ԭ����Ϣ����filename-д��/�����ļ���
*/
int reSetInfs(const string& Tnum) {
    system("cls");
    int select;
    cout << "�����桷����Ա����¼����¼�ɹ�������Ա�˵����޸Ļ���Ϣ" << endl;
    cout << "��ѡ�񳵴� " << Tnum << " ���޸ĵ���Ϣ��" << endl
        << "1.ʼ����" << endl
        << "2.Ŀ�ĵ�" << endl
        << "3.����ʱ��" << endl
        << "4.�ִ�ʱ��" << endl
        << "5.��Ʊ����" << endl
        << "0.�˳��޸�" << endl
        << "����ѡ�";
    while (1) {
        select = getSelectDigit();
        if (select == -1)
            cout << "�ٴ����룺";
        else
            break;
    }
    //system("pause");
    return select;
}
bool reSetTIF(forward_list<trainNode>& trainList, unordered_map<string, vector<string>>& orderMap) {
    system("cls");
    string trainNum;
    int mainSelect = 1;
    while (mainSelect) {
        system("cls");
        cout << "�����桷��¼������Ա���޸ĳ�����Ϣ" << endl << endl;
        cout << "���복��: ";
        cin >> trainNum;
        if (orderMap.find(trainNum) == orderMap.end()) {
            cout << "���β����ڣ����������ǰ����ӻ���Ϣ" << endl;
            cout << "����1�����޸Ļ���Ϣ������0�˳��޸Ĳ����ع���Ա�˵�";
            while (true) {
                mainSelect = getSelectDigit();
                if (mainSelect == -1)
                    cout << "�ٴ�����:";
                else
                    break;
            }
        }
        else {
            forward_list<trainNode>::iterator it = trainList.begin();
            while (it->trainInfo[0] != trainNum && it != trainList.end()) it++;
            vector<string>tempInfs = it->trainInfo;
            int votes = 0, ticketPrice = 0;
            int tempSelect = 1;
            bool hasSet = 0;
            while (tempSelect) {

                switch (tempSelect = reSetInfs(trainNum)) {
                case 1:
                    while (true) {
                        cout << "������ʼ���أ�";
                        tempInfs[1] = getInputStringLine();
                        if (tempInfs[1] == "")
                            cout << "�ٴ�����:";
                        else
                            break;

                    }
                    hasSet = 1;
                    break;
                case 2:
                    while (true) {
                        cout << "������Ŀ�ĵأ�";
                        tempInfs[2] = getInputStringLine();
                        if (tempInfs[2] == "")
                            cout << "�ٴ�����:";
                        else
                            break;
                    }
                    hasSet = 1;
                    break;
                case 3:
                    while (true) {
                        cout << "�����³���ʱ�䣺";
                        tempInfs[3] = getInputStringLine();
                        if (tempInfs[3] == "")
                            cout << "�ٴ�����:";
                        else
                            break;
                    }
                    hasSet = 1;
                    break;
                case 4:
                    while (true) {
                        cout << "�����µִ�ʱ�䣺";
                        tempInfs[4] = getInputStringLine();
                        if (tempInfs[4] == "")
                            cout << "�ٴ�����:";
                        else
                            break;
                    }
                    hasSet = 1;
                    break;
                case 5:
                    while (true) {
                        cout << "�����³�Ʊ������";
                        int votes = getSelectDigit();
                        if (votes == -1)
                            cout << "�ٴ�����:";
                        else {
                            tempInfs[5] = to_string(votes);
                            break;
                        }
                    }
                    hasSet = 1;
                    break;
                case 0:
                    mainSelect = 0;
                    tempSelect = 0;
                    break;
                default:
                    cout << "��������ȷ��ѡ��";
                    break;
                }
            }
            if (hasSet) {
                cout << "��:";
                for (int i = 0; i < 6; i++)
                    cout << it->trainInfo[i] << ' ';
                cout << endl;
                cout << "��:";
                for (string iq : tempInfs)
                    cout << iq << ' ';
                cout << endl;
                cout << "1.ȷ���޸Ļ���Ϣ 0.ȡ���޸Ļ���Ϣ" << endl;
                int confirm = 1;
                while (confirm) {
                    confirm = getSelectDigit();
                    if (!confirm) {
                        cout << "ȷ��ȡ���޸ģ����ع���Ա�˵�";
                        break;
                    }
                    else if (confirm == 1) {
                        it->trainInfo = tempInfs;
                        if (!resetFile(trainList)) {
                            cout << "д��ʧ�ܣ����ز˵�";
                            return 0;
                        }
                        cout << "����Ϣ�޸����!";
                        break;
                    }
                    else
                        cout << "�ٴ�����:";
                }
            }
        }

    }
    system("pause");
    return 1;
}

//�������ܣ�������л���Ϣ
/*
* �����������
* ����/��������Tlinked-ԭ����Ϣ����
*/
bool showAll(forward_list<trainNode>& trainList, unordered_map<string, vector<string>>& orderMap) {
    system("cls");
    cout << "�����桷��¼����ʾ���г�Ʊ��Ϣ" << endl << endl;
    if (!orderMap.size()) {
        cout << "��ǰ���޻���Ϣ!" << endl;
        system("pause");
        return 0;
    }
    cout << "Ŀǰ���е�ȫ����Ʊ��Ϣ���£�" << endl;

    cout << "     " << setw(15) << left << "����" << setw(15) << left << "ʼ����" << setw(15) << left << "Ŀ�ĵ�"
        << setw(15) << left << "����ʱ��" << setw(15) << left << "�ִ�ʱ��"
        << setw(15) << left << "��Ʊ����" << setw(15) << left << "�ѹ�����" << endl;
    int tip = 0;
    for (const trainNode& it : trainList) {
        cout << "     ";
        for (const string& iq : it.trainInfo)
            cout << setw(15) << left << iq;
        cout << setw(15) << getNumOfOrder(orderMap, it.trainInfo[0]);
        cout << endl;
    }
    system("pause");
    return 1;
}
//�������ܣ��޸Ļ���Ϣ�ļ�
/*
* Linked-��д�������, fileName-д����ļ�
*/
bool resetFile(const forward_list<trainNode>& trainList) {
    ofstream inFile("PrimordialInformationBase.txt", ios::out);
    if (!inFile.is_open()) return 0;//�ļ���ʧ��
    for (const trainNode& it : trainList) {
        for (const string& iq : it.trainInfo)
            inFile << iq << " ";
        inFile << endl;
    }
    inFile.close();
    return 1;
}
//�������ܣ������ѹ���Ʊ����
/*
*
*/
int getNumOfOrder(unordered_map<string, vector<string>>& orderMap, const string& trainNumber) {
    if (orderMap.find(trainNumber) == orderMap.end()) return 0;//���β�����ʱ����0
    return orderMap[trainNumber].size();//�����ѹ�Ʊ��
}


