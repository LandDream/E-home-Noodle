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
	void setState(e_Customer_State eState);
	int patientLevel();
	void reductionAll();
	void addDelayTime();
	bool eatNoodle(int noodleID);
	CC_SYNTHESIZE(e_Customer_State, e_customer_state, CustomerState);
	float getRefleshTime();
private:
	int customer_id;
	int noodle_id;
	int patient_level;
	float fDelayTime;
	float fAllTime;
	float fWaitTime;
	float fEatTime;
	float fReflesh_time;
	float fPunish_time;
	int nHappy_bonus;
	std::string str_name;
	Sprite* customer_man;
	Node* customer_tip;
	Node* self_customer;
};

