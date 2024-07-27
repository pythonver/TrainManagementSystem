
#include"AdministratorMenu.h"

//函数功能：初始化火车信息和账户信息
/*
* 实现步骤：
* 1.读文件
* 2.循环写入节点
* 3.首插到链表linked
* 参数/变量名：
* Tlinked-火车信息链表，Phash-购买人群哈希表,fileName-原初信息库,Filename车票购买人群库
*/
bool initAdmData(forward_list<trainNode>& trainList, const string& trainFile, unordered_map<string, vector<string>>& orderMap, const string& orderFile) {
    ifstream inFile(trainFile);
    //初始化火车信息链表
    if (!inFile.is_open()) return false;
    vector<string> tempTrainInfo(6);//火车信息数组
    while (inFile >> tempTrainInfo[0] >> tempTrainInfo[1] >> tempTrainInfo[2] >> tempTrainInfo[3] >> tempTrainInfo[4] >> tempTrainInfo[5]) {
        trainNode tempT = trainNode(tempTrainInfo);//建立一个临时节点
        trainList.push_front(tempT);//将临时节点插入到链表
    }
    inFile.close();
    //初始化购买人群库
    inFile.open(orderFile);
    if (!inFile.is_open()) return false;
    string line;
    while (getline(inFile, line)) {
        string trainNumber;//哈希表的key，用于暂存车次
        string order;//用户，用于暂存每一个用户
        vector<string> orderArray;//哈希表的value, 用于暂存某车次的所有用户

        istringstream iss(line);//从文件读取的一行转换成输入流
        iss >> trainNumber;//输入车次
        while (iss >> order)//依次输入人群
            orderArray.push_back(order);
        orderMap[trainNumber] = orderArray;
    }
    inFile.close();
    return true;//全部初始化完成
}
//函数功能：添加火车信息 
/*
* 实现步骤：
* 1.循环获取输入的数据并保存在结构体
* 2.插入到链表
* 3.调用写入文件函数将链表数据覆盖源文件
* 变量/参数名：Tlinked-原火车信息链表，
*/
void inputInfo(vector<string>& tempTrainInfo, const unordered_map<string, vector<string>>& orderMap) {
    vector<string> tips = { "车次", "出发地" , "目的地", "出发时间", "抵达时间" };
    for (int i = 0; i < tips.size(); i++) {
        cout << "请输入" << tips[i] << ':';
        while (true) {
            tempTrainInfo[i] = getInputStringLine();
            if (tempTrainInfo[i] == "")
                cout << "重新输入" << tips[i] << ':';
            else {
                if (i == 0 && orderMap.find(tempTrainInfo[0]) != orderMap.end()) {
                    tempTrainInfo[0] = "";
                    cout << "车次已存在,如需修改请前往修改" << endl;
                    cout << "1.继续添加 0.退出添加" << endl;
                    int select = 1;
                    while (select) {
                        select = getSelectDigit();
                        if (select == -1)
                            cout << "重新输入选项:";
                        else if (!select)
                            return;
                        else {
                            cout << "输入车次:";
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
    cout << "主界面》登录》高级管理员》添加车次及车次信息" << endl << endl;
    vector<string> tempTraingInfo(6);//暂存新增信息
    inputInfo(tempTraingInfo, orderMap);//输入五个基本信息
    if (tempTraingInfo[0] == "")
        return 0;
    //车票数量的添加，必须为大于等于0的整数
    cout << "输入车票数量:";
    int votes;
    while (1) {
        votes = getSelectDigit();
        if (votes == -1)
            cout << "车票数量必须为有效正整数,再次输入：";
        else
            break;
    }
    tempTraingInfo[5] = to_string(votes);
    //车票单价的添加，只考虑大于等于0的整数
    int select;
    cout << "待新增的火车信息：" << endl;
    cout << "车次:" << tempTraingInfo[0] << " 始发地:" << tempTraingInfo[1] << " 目的地:" << tempTraingInfo[2]
        << " 出发时间:" << tempTraingInfo[3] << " 抵达时间:" << tempTraingInfo[4] << " 车票数量:" << tempTraingInfo[5] << endl;
    cout << "1.确认添加 0.取消添加";
    cout << "输入选项:";
    while (1) {
        select = getSelectDigit();
        if (select == -1)
            cout << "再次输入:";
        else if (select == 1)
            break;
        else if (select == 0)
            return false;
        else
            cout << "必须输入有效选项,再次输入:";
    }
    if (!appendData(tempTraingInfo, "PrimordialInformationBase.txt"))
        return false;
    //添加到信息链表
    trainList.push_front(trainNode(tempTraingInfo));
    orderMap[tempTraingInfo[0]] = vector<string>{};
    if (!appendData(vector<string>{tempTraingInfo[0]}, "TicketBuyersDatabase.txt"))
        return false;
    cout << "添加成功" << endl;
    system("pause");
    return true;//写入完成
}
//函数功能：追加形式写入文件
bool appendData(vector<string> writingData, const string& fileName) {
    ofstream outFile(fileName, ios::app);
    if (!outFile.is_open())
        return false;
    for (const string& data : writingData)
        outFile << data << " ";
    outFile << endl;
    return true;
}
//函数功能：删除火车信息
/*
* 实现步骤：
* 1.读取链表查找删除的车次节点
* 2.如果没找到，返回false；否则进行下一步
* 3.删除符合的节点
* 4.调用写入文件函数将链表数据覆盖源文件
* 变量/参数名：Tlinked-原火车信息链表，filename-写入/读出文件名
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
    //先输出所有火车信息
    if (!orderMap.size()) {
        cout << "当前暂无可删除火车";
        system("pause");
        return 0;
    }
    while (1) {
        showAll(trainList, orderMap);
        string Tnum;
        cout << "根据上表输入删除的火车车次" << endl;
        int select = 1;
        while (select) {
            cout << "输入车次:";
            Tnum = getInputStringLine();
            if (Tnum == "") {
                cout << "请输入正确的火车车次";
            }
            else if (orderMap.find(Tnum) == orderMap.end()) {
                cout << "不存在该车次" << endl << "输入0退出删除,输入其他数字继续删除";
                while (1) {
                    select = getSelectDigit();
                    if (select == -1)
                        cout << "再次输入：";
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
        cout << "待删除 火车 信息如下:" << endl;
        cout << "      " << setw(15) << left << "车次" << setw(15) << left << "始发地" << setw(15) << left << "目的地"
            << setw(15) << left << "出发时间" << setw(15) << left << "抵达时间"
            << setw(15) << left << "车票数量" << setw(15) << left << "已购数量" << endl;
        cout << "      ";
        for (const string& iq : iq->trainInfo)
            cout << setw(15) << left << iq;
        cout << setw(15) << getNumOfOrder(orderMap, iq->trainInfo[0]);
        cout << endl;

        cout << "请确认是否删除车次 " << Tnum << " 的信息(火车基本信息及购买人群)" << endl;
        cout << "输入 0 退出删除， 输入其他数字删除火车信息:" << endl;
        while (1) {
            select = getSelectDigit();
            if (select == -1) {
                cout << "请重新输入:";
            }
            else if (!select) {
                cout << "退出删除";
                return 0;
            }
            else
                break;
        }
        trainList.erase_after(it);
        resetFile(trainList);
        //调用并删除用户购买库
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
        eraseTrainInOrder(Tnum);//传递车次
        cout << "删除完成" << endl;
        system("pause");
        return 1;
    }
    return 1;
}

//函数功能：输出购买人群
/*
* 1.读取购买库
* 2.从购买者哈希表中查询车次的购买人群和购买人数
* 变量/参数名：Phash-购买人群哈希表，用于查询某车次是否存在并查询购买用户和购买人数
*/
bool showOrder(unordered_map<string, vector<string>>& orderMap) {
    system("cls");
    cout << "主界面》登录》管理员》查询某车次的乘客列表" << endl << endl;
    if (orderMap.empty()) {
        cout << "当前暂无火车，请前往添加" << endl;
        system("pause");
        return 0;
    }
    string trainNumber;
    int select = 1;
    while (select) {
        cout << "输入待查询车次" << endl;
        //cin >> trainNumber;
        trainNumber = getInputStringLine();
        if (orderMap.find(trainNumber) != orderMap.end()) {//查找车次是否存在
            if (!orderMap[trainNumber].size())
                cout << "该车次暂无用户购买" << endl;
            else {
                cout << "车次： " << trainNumber << " 已购：" << orderMap[trainNumber].size() << endl;
                cout << "购买用户： " << endl;
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
            cout << "车次不存在" << endl;
        cout << endl;
        cout << "输入1继续查找购买用户, 输入0退出查询" << endl;
        //cin >> select;
        select = getSelectDigit();
    }
    system("pause");
    return 0;
}
//函数功能：修改火车信息(包含可购票数量) --公开函数
/*
* 实现步骤：
* 1.读取链表查找修改的车次节点
* 2.如果没找到，返回false；否则进行下一步
* 3.修改符合的节点内容
* 4.调用写入文件函数将链表的数据覆盖原文件
* 变量/参数名：Tlinked-原火车信息链表，filename-写入/读出文件名
*/
int reSetInfs(const string& Tnum) {
    system("cls");
    int select;
    cout << "主界面》管理员》登录》登录成功》管理员菜单》修改火车信息" << endl;
    cout << "请选择车次 " << Tnum << " 待修改的信息：" << endl
        << "1.始发地" << endl
        << "2.目的地" << endl
        << "3.出发时间" << endl
        << "4.抵达时间" << endl
        << "5.车票数量" << endl
        << "0.退出修改" << endl
        << "输入选项：";
    while (1) {
        select = getSelectDigit();
        if (select == -1)
            cout << "再次输入：";
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
        cout << "主界面》登录》管理员》修改车次信息" << endl << endl;
        cout << "输入车次: ";
        cin >> trainNum;
        if (orderMap.find(trainNum) == orderMap.end()) {
            cout << "车次不存在，如需添加请前往添加火车信息" << endl;
            cout << "输入1继续修改火车信息，输入0退出修改并返回管理员菜单";
            while (true) {
                mainSelect = getSelectDigit();
                if (mainSelect == -1)
                    cout << "再次输入:";
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
                        cout << "输入新始发地：";
                        tempInfs[1] = getInputStringLine();
                        if (tempInfs[1] == "")
                            cout << "再次输入:";
                        else
                            break;

                    }
                    hasSet = 1;
                    break;
                case 2:
                    while (true) {
                        cout << "输入新目的地：";
                        tempInfs[2] = getInputStringLine();
                        if (tempInfs[2] == "")
                            cout << "再次输入:";
                        else
                            break;
                    }
                    hasSet = 1;
                    break;
                case 3:
                    while (true) {
                        cout << "输入新出发时间：";
                        tempInfs[3] = getInputStringLine();
                        if (tempInfs[3] == "")
                            cout << "再次输入:";
                        else
                            break;
                    }
                    hasSet = 1;
                    break;
                case 4:
                    while (true) {
                        cout << "输入新抵达时间：";
                        tempInfs[4] = getInputStringLine();
                        if (tempInfs[4] == "")
                            cout << "再次输入:";
                        else
                            break;
                    }
                    hasSet = 1;
                    break;
                case 5:
                    while (true) {
                        cout << "输入新车票数量：";
                        int votes = getSelectDigit();
                        if (votes == -1)
                            cout << "再次输入:";
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
                    cout << "需输入正确的选项";
                    break;
                }
            }
            if (hasSet) {
                cout << "旧:";
                for (int i = 0; i < 6; i++)
                    cout << it->trainInfo[i] << ' ';
                cout << endl;
                cout << "新:";
                for (string iq : tempInfs)
                    cout << iq << ' ';
                cout << endl;
                cout << "1.确认修改火车信息 0.取消修改火车信息" << endl;
                int confirm = 1;
                while (confirm) {
                    confirm = getSelectDigit();
                    if (!confirm) {
                        cout << "确认取消修改，返回管理员菜单";
                        break;
                    }
                    else if (confirm == 1) {
                        it->trainInfo = tempInfs;
                        if (!resetFile(trainList)) {
                            cout << "写入失败，返回菜单";
                            return 0;
                        }
                        cout << "火车信息修改完成!";
                        break;
                    }
                    else
                        cout << "再次输入:";
                }
            }
        }

    }
    system("pause");
    return 1;
}

//函数功能：输出所有火车信息
/*
* 遍历输出链表
* 变量/参数名：Tlinked-原火车信息链表
*/
bool showAll(forward_list<trainNode>& trainList, unordered_map<string, vector<string>>& orderMap) {
    system("cls");
    cout << "主界面》登录》显示所有车票信息" << endl << endl;
    if (!orderMap.size()) {
        cout << "当前暂无火车信息!" << endl;
        system("pause");
        return 0;
    }
    cout << "目前已有的全部火车票信息如下：" << endl;

    cout << "     " << setw(15) << left << "车次" << setw(15) << left << "始发地" << setw(15) << left << "目的地"
        << setw(15) << left << "出发时间" << setw(15) << left << "抵达时间"
        << setw(15) << left << "车票数量" << setw(15) << left << "已购数量" << endl;
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
//函数功能：修改火车信息文件
/*
* Linked-待写入的链表, fileName-写入的文件
*/
bool resetFile(const forward_list<trainNode>& trainList) {
    ofstream inFile("PrimordialInformationBase.txt", ios::out);
    if (!inFile.is_open()) return 0;//文件打开失败
    for (const trainNode& it : trainList) {
        for (const string& iq : it.trainInfo)
            inFile << iq << " ";
        inFile << endl;
    }
    inFile.close();
    return 1;
}
//函数功能：返回已购车票数量
/*
*
*/
int getNumOfOrder(unordered_map<string, vector<string>>& orderMap, const string& trainNumber) {
    if (orderMap.find(trainNumber) == orderMap.end()) return 0;//车次不存在时返回0
    return orderMap[trainNumber].size();//返回已购票数
}


