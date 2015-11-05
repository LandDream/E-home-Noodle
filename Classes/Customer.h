#pragma once

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "EnmuResource.h"
USING_NS_CC;
using namespace cocostudio::timeline;
using namespace ui;
class Customer : public Node
{
public:
    virtual bool init();
	CREATE_FUNC(Customer);
	Customer();
	~Customer();
	static Customer* createCustomer(Node* customer_node);
	void setWaitTime(float fTime);
	bool spendTime(float fTime);
	void setCustomer(Node* customer);
	int patientLevel();
	int nNum;
	float fAllTime;
	float fNowTime;
	Node* customer_man;
	Node* customer_tip;
	Node* self_customer;
};

