#include "ATM.h"

int main()
{
	bank Belarusbank;

	if (Belarusbank.User->New->Enter_to_your_account())
	{
		Belarusbank.Menu();
	}

	return 0;
}
