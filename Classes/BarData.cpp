#pragma once

#include "BarData.h"

BarData::BarData() :m_Level(0), m_time(0),m_money(0),m_smile(0),m_angry(0)
{
	CCLOG("[********** BarData *********]");
}

BarData::~BarData()
{
	CCLOG("[********** ~BarData *********]");
	m_Level = 0;
	m_time = 0;
	m_money = 0;
	m_smile = 0;
	m_angry = 0;
}
