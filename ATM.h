#pragma once

#include <iostream>
#include <ctime>
#include "windows.h"

using namespace std;

class account
{
public:
	account();
	char password[5];
	char user_account[13];
	int money;
	void Open_account();
	void Show_info();
	int& Work_with_money(int n);
	bool Enter_to_your_account();
};

class client
{
public:
	account* New;
	char surname_and_name[30];
	char adress[30];
	client();
	~client();
};

class bank
{
public:
	client* User;
	bank();
	~bank();
	void Menu();
};