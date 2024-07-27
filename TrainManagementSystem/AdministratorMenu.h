#pragma once
#ifndef ADMINTRAINTICKETMANAGEMENT_H_//��ֹͷ�ļ����ظ�����
#define ADMINTRAINTICKETMANAGEMENT_H_
//����Ա��Ʊ����ͷ�ļ�
#include"CommonLib.h"
#include"StaticMethod.h"
using namespace std;
//���º���������3.GuanLiYuanCaiDan.cpp
//������ڵ�
struct trainNode {
    //���Ρ�ʼ���ء�Ŀ�ĵء�����ʱ�䡢�ִ�ʱ�䡢��Ʊ��������Ʊ����
    vector<string> trainInfo;
    //��Ʊ����
    //���캯�������ڵ�
    trainNode(const vector<string>& Info) :trainInfo(Info) {}
};
//���岽�輰����/�������ں�������ʱ����
//��ʼ����������
bool initAdmData(forward_list<trainNode>&, const string&, unordered_map<string, vector<string>>&, const string&);
//����˵�
//int admOperationMenu();
//�˵�ѡ��/����Ա��¼�ɹ������
//void admMenu();
//��ӻ���Ϣ
void inputInfo(vector<string>&, const unordered_map<string, vector<string>>&);
bool addTIF(forward_list<trainNode>&, unordered_map<string, vector<string>>&);
bool appendData(vector<string>, const string&);
//ɾ������Ϣ
bool eraseTIF(forward_list<trainNode>&, unordered_map<string, vector<string>>&);
//���������
bool showOrder(unordered_map<string, vector<string>>&);
//�޸Ļ���Ϣ
bool reSetTIF(forward_list<trainNode>&, unordered_map<string, vector<string>>&);
//����޸Ĳ˵�
int reSetInfs(const string&);
//������л���Ϣ
bool showAll(forward_list<trainNode>&, unordered_map<string, vector<string>>&);
//�޸��ļ�����
bool resetFile(const forward_list<trainNode>&);
void addOrder(const string&, const string&);
void eraseOrder(const string&, const string&);
//��ȡĳ���εĹ�Ʊ����
int getNumOfOrder(unordered_map<string, vector<string>>&, const string&);
#endif // !ADMINTRAINTICKETMANAGEMENT_H_
