#pragma once
#ifndef USERTICKETMANAGEMENT_H_
#define USERTICKETMANAGEMENT_H_

#include"CommonLib.h"
#include"StaticMethod.h"
//�û���Ʊ��Ʊ����ڵ�
struct trainTicket {
    //�û���������
    vector<string> ticketInfo;
};

//ԭ����Ϣ�������ڵ� 
struct yuanTrain {
    //���Ρ�ʼ���ء�Ŀ�ĵء�����ʱ�䡢�ִ�ʱ�䡢��Ʊ�������۸�
    vector<string> inform;
};
// ��ʼ���û����������
void initTrainTicketLink(forward_list<trainTicket>& );
//��ʼ��ԭ����Ϣ�������
void initYuanTrainLink(forward_list<yuanTrain>& , forward_list<trainTicket>& );
//�������ܣ�����û���ѯ�𳵽��� 
void userFindCon();
//�������ܣ��û����Ҳ˵� 
void userFind(forward_list<yuanTrain>&);
//�������ܣ�����Ŀ�ĵز�ѯ����Ϣ
void toSearch(forward_list<yuanTrain>& );
//�������ܣ�����ʼ���ز�ѯ����Ϣ
void fromSearch(forward_list<yuanTrain>&);
//�������ܣ�����ʼ����-Ŀ�ĵز�ѯ����Ϣ
void fromToSearch(forward_list<yuanTrain>&);
//�������ܣ�������л�Ʊ��Ϣ
void showAll(forward_list<yuanTrain>& );
// �������ܣ��û���Ʊ
void buyTicket(string , forward_list<yuanTrain>& , forward_list<trainTicket>& );
//�������ܣ��г̲�ѯ
void findItinerary(forward_list<trainTicket>& , forward_list<yuanTrain>& , const string& );
//�������ܣ��û���Ʊ
void deleTicket(forward_list<trainTicket>& , forward_list<yuanTrain>& );
//��������:�û���ǩ 
void userChange(forward_list<trainTicket>& , forward_list<yuanTrain>& );
//Ѱ��ԭ����Ϣ�������Ӧ�ڵ�
yuanTrain* findTrainLinkedListNode(forward_list<yuanTrain>&, string);

#endif // !USERTICKETMANAGEMENT_H_
