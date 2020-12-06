#include "ATM.h"

void account::Open_account()
{
	int temp;
	srand(time(0));
	for (int i = 0; i < 12; i++)
	{
		user_account[i] = rand() % 10 + 48;
	}
	user_account[12] = '\0';
	cout << "Your account number: " << user_account << endl;

	temp = rand() % 10000;
	_itoa_s(temp, password, 10);
	password[4] = '\0';
	cout << "Password from your account: " << password << endl;

	cout << "How much money would you like to add to your account balance?" << endl;
	cin >> money;

}

void account::Show_info()
{
	cout << "Your account number: " << user_account << endl;
	cout << "Password from your account: " << money << endl;
}

int& account::Work_with_money(int n = 0)
{
	money -= n;
	return money;
}

account::account()
{
	cout << "Congratulations on registering a new account!" << endl;

}

bool account::Enter_to_your_account()
{
	char tries[5];
	int times = 0;
	cout << "Enter your password to continue working" << endl;

	while (times < 3)
	{
		cin >> tries;

		if (strcmp(tries, password) == 0)
		{
			cout << "Welcome in your account" << endl;
			return 1;
		}
		else
			cout << "Error, try again, please" << endl;
		times++;
	}

	if (times == 3)
		cout << "Error, you try to enter your password 3 times, your account if blocked" << endl;
	return 0;
}

client::client()
{
	New = new account;
	cout << "Enter your Surname and Name: " << endl;
	cin.getline(surname_and_name, 30);
	cout << "Enter your adress: " << endl;
	cin.getline(adress, 30);
}

client::~client()
{
	delete New;
}

bank::bank()
{
	User = new client;
	User->New->Open_account();
}

bank:: ~bank()
{
	delete User;
}

void bank::Menu()
{
	Sleep(1000);
	int key;

	while (1)
	{
		bool check = 1;
		system("CLS");
		cout << "Choose what you want to do" << endl;
		cout << "1: Show the balance" << endl << "2: To put money to your account" << endl << "3: To draw money from your account" << endl << "4: Exit;" << endl;
		cin >> key;
		while ((key < 0) || (key >= 5))
		{
			cin >> key;
		}

		switch (key)
		{
		case 1:

			system("CLS");
			User->New->Show_info();
			cout << "Do you want to back to menu? \t 1: Yes;\t2: No" << endl;
			while (check)
			{
				cin >> key;
				if (key == 1) {
					check = 0;
					continue;
				}
				else if (key == 2)
				{
					cout << "Thank you for choosing our bank, have a nice time of day" << endl;
					exit(0);
				}
				else
					cout << "Error, try again, please" << endl;
			}
			break;
		case 2:
			cout << "How much money you want to put? " << endl;
			cin >> key;
			User->New->Work_with_money(-key);
			cout << "Now you have  " << User->New->Work_with_money() << "  on the balance of your account" << endl;
			cout << "Do you want to back to menu? \t 1: Yes;\t2: No" << endl;
			while (check)
			{
				cin >> key;

				if (key == 1) {
					check = 0;
					continue;
				}
				else if (key == 2)
				{
					cout << "Thank you for choosing our bank, have a nice time of day" << endl;
					exit(0);
				}
				else
					cout << "Error, try again, please" << endl;
			}
			break;
		case 3:
			cout << "How much money you want to draw? " << endl;
			cin >> key;
			if (User->New->Work_with_money() < key)
			{
				cout << "You don't have enough money to draw it" << endl;
				Sleep(1000);
				continue;
			}
			else User->New->Work_with_money(key);
			cout << "Now you have  " << User->New->Work_with_money() << "  on the balance of your account" << endl;
			cout << "Do you want to back to menu? \t 1: Yes;\t2: No" << endl;
			while (check)
			{
				cin >> key;
				if (key == 1) {
					check = 0;
					continue;
				}
				else if (key == 2)
				{
					cout << "Thank you for choosing our bank, have a nice time of day" << endl;
					exit(0);
				}
				else
					cout << "Error, try again, please" << endl;
			}
			break;
		case 4:
			cout << "Thank you for choosing our bank, have a nice time of day" << endl;
			exit(0);
			break;
		}
	}
}