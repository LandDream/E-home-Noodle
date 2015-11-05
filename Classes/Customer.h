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
	static Customer* createCustomer(Node* customer_node);
	void setWaitTime(float fTime);
	bool spendWaitTime(float fTime);
	bool spendEatTime(float fTime);
	void setCustomer(Node* customer);
	void setStateEating();
	int patientLevel();
	CC_SYNTHESIZE(e_Customer_State, e_customer_state, CustomerState);

private:
	float fAllTime;
	float fWaitTime;
	float fEatTime;
	Sprite* customer_man;
	Node* customer_tip;
	Node* self_customer;

};

