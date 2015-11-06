#pragma once

#include "cocos2d.h"
#include "EnmuResource.h"
USING_NS_CC;
class Customer : public Node
{
public:
    virtual bool init();
	CREATE_FUNC(Customer);
	Customer();
	~Customer();
	static Customer* createCustomer(Node* customer_node, struct_MAN* struct_man);
	void setCustomer(Node* customer_node, struct_MAN* struct_man);
	void setWaitTime(float fTime);
	bool spendTime(float fTime);
	bool spendWaitTime(float fTime);
	bool spendEatTime(float fTime);
	void setStateEating();
	int patientLevel();
	void reductionAll();
	bool isAbelEat();
	CC_SYNTHESIZE(e_Customer_State, e_customer_state, CustomerState);

private:
	int customer_id;
	int noodle_id;
	float fAllTime;
	float fWaitTime;
	float fEatTime;
	Sprite* customer_man;
	Node* customer_tip;
	Node* self_customer;
};

