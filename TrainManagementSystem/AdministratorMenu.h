#pragma once
#ifndef ADMINTRAINTICKETMANAGEMENT_H_//防止头文件被重复包含
#define ADMINTRAINTICKETMANAGEMENT_H_
//管理员火车票管理头文件
#include"CommonLib.h"
#include"StaticMethod.h"
using namespace std;
//以下函数出现在3.GuanLiYuanCaiDan.cpp
//火车链表节点
struct trainNode {
    //车次、始发地、目的地、出发时间、抵达时间、车票数量、车票单价
    vector<string> trainInfo;
    //车票数量
    //构造函数创建节点
    trainNode(const vector<string>& Info) :trainInfo(Info) {}
};
//具体步骤及变量/参数名在函数定义时给出
//初始化函数链表
bool initAdmData(forward_list<trainNode>&, const string&, unordered_map<string, vector<string>>&, const string&);
//输出菜单
//int admOperationMenu();
//菜单选项/管理员登录成功的入口
//void admMenu();
//添加火车信息
void inputInfo(vector<string>&, const unordered_map<string, vector<string>>&);
bool addTIF(forward_list<trainNode>&, unordered_map<string, vector<string>>&);
bool appendData(vector<string>, const string&);
//删除火车信息
bool eraseTIF(forward_list<trainNode>&, unordered_map<string, vector<string>>&);
//输出购买者
bool showOrder(unordered_map<string, vector<string>>&);
//修改火车信息
bool reSetTIF(forward_list<trainNode>&, unordered_map<string, vector<string>>&);
//输出修改菜单
int reSetInfs(const string&);
//输出所有火车信息
bool showAll(forward_list<trainNode>&, unordered_map<string, vector<string>>&);
//修改文件函数
bool resetFile(const forward_list<trainNode>&);
void addOrder(const string&, const string&);
void eraseOrder(const string&, const string&);
//获取某车次的购票数量
int getNumOfOrder(unordered_map<string, vector<string>>&, const string&);
#endif // !ADMINTRAINTICKETMANAGEMENT_H_
