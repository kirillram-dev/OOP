#pragma once
#include "Car.h"
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class CCarMenu
{
public:
	CCarMenu(CCar& car);
	~CCarMenu() = default;

	void GetInfo() const;
	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(int gear);
	bool SetSpeed(size_t speed);
	void RunCommand(std::string& command);

private:
	CCar& m_car;
};