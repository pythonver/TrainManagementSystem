#pragma once
#ifndef USERTICKETMANAGEMENT_H_
#define USERTICKETMANAGEMENT_H_

#include"CommonLib.h"
#include"StaticMethod.h"
//用户购票火车票链表节点
struct trainTicket {
    //用户名、车次
    vector<string> ticketInfo;
};

//原初信息库火车链表节点 
struct yuanTrain {
    //车次、始发地、目的地、出发时间、抵达时间、车票数量、价格
    vector<string> inform;
};
// 初始化用户购买库链表
void initTrainTicketLink(forward_list<trainTicket>& );
//初始化原初信息库火车链表
void initYuanTrainLink(forward_list<yuanTrain>& , forward_list<trainTicket>& );
//函数功能：输出用户查询火车界面 
void userFindCon();
//函数功能：用户查找菜单 
void userFind(forward_list<yuanTrain>&);
//函数功能：根据目的地查询火车信息
void toSearch(forward_list<yuanTrain>& );
//函数功能：根据始发地查询火车信息
void fromSearch(forward_list<yuanTrain>&);
//函数功能：根据始发地-目的地查询火车信息
void fromToSearch(forward_list<yuanTrain>&);
//函数功能：输出所有火车票信息
void showAll(forward_list<yuanTrain>& );
// 函数功能：用户购票
void buyTicket(string , forward_list<yuanTrain>& , forward_list<trainTicket>& );
//函数功能：行程查询
void findItinerary(forward_list<trainTicket>& , forward_list<yuanTrain>& , const string& );
//函数功能：用户退票
void deleTicket(forward_list<trainTicket>& , forward_list<yuanTrain>& );
//函数功能:用户改签 
void userChange(forward_list<trainTicket>& , forward_list<yuanTrain>& );
//寻找原初信息库链表对应节点
yuanTrain* findTrainLinkedListNode(forward_list<yuanTrain>&, string);

#endif // !USERTICKETMANAGEMENT_H_
