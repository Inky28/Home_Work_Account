/*
Написати клас "Банківський рахунок" (Account), який містить:
	Номер рахунку
	Розмір коштів на рахунку
	Назва валюти рахунку (долари, гривні, євро тощо), для позначення якої можна скористатись одним символом:
	G, E, $ чи значенням перелічувального типу тощо.
Забезпечити можливість:
	Відкривати рахунок та первинно вносити гроші на рахунок(за замовчуванням рахунок відкривати у гривнях)
	Знімати гроші з рахунку
	Докладати гроші на рахунок

ПРИМІТКА! На 12 балів реалізувати також можливість здійснювати переказ грошей з одного рахунку на другий.
Візьміть до уваги, що рахунки можуть бути у різних грошових одиницях.

*/
#include <iostream>
#include <ctime>

using namespace std;

class Account
{
private:
	const size_t numberAccount = rand() % (10000 - 1000) + 1000;  // рандомний НОМЕР рахунку ВВАЖАЄМО ЩО НОМЕР РАХУНКУ ВІЧНИЙ І ЗМІНИТИСЬ НЕ МОЖЕ
	float funds;				// Розмір коштів на рахунку
public:

	int index = 0;
	string currency[3] = { " UAH", " USD"," EUR" };

	Account()
	{
		this->funds = 0;
	}

	Account(float funds)
	{
		SetFunds(funds);
	}

	void SetIndex(int t_index)
	{
		this->index = t_index;
	}

	int GetIndex()
	{
		return this->index;
	}

	void SetCurrency(int number)
	{
		SetIndex(number);
		this->currency[GetIndex()];
	}

	string GetCurrency()
	{
		return this->currency[GetIndex()];
	}

	size_t GetNumberAccount() const			// повертаємо значення  numberAccount
	{
		return this->numberAccount;
	}

	void SetFunds(const float& MethodFunds)	// задаємо значення funds
	{
		this->funds = MethodFunds;
	}

	float GetFunds() const					// повертаємо значення  funds
	{
		return this->funds;
	}

	void PlusFunds(float plusFunds)		// перевіряємо на від'ємність
	{
		if (plusFunds >= 0 && this->index == 0)
		{
			this->funds += plusFunds;
		}
		else
			cout << "Error. Incorrect value\n";
	}

	void MinusFunds(float minusFunds)		// перевіряємо на від'ємність
	{
		if (minusFunds >= 0 && minusFunds <= this->funds && this->index == 0)
		{
			this->funds -= minusFunds;
		}
		else
			cout << "Error. Incorrect value\n";

	}

	void ShowMenuConvertMoney()
	{
		cout << "Convert ALL money\n";
		cout << "1 - UAH to USD (1 USD = 20 UAH)\n";
		cout << "2 - UAH to EUR (1 EUR = 30 UAH)\n";
		cout << "Other choice to exit\n";
	}

	void ConvertUAH_to_USD()
	{
		if (GetIndex() == 0)
		{
			SetIndex(1);
			cout << "convert money uah to usd (1 usd = 20 uah):\n";
			float newfunds = GetFunds() / 20;
			SetFunds(newfunds);
		}
		else
			cout << "error\n\n";

	}

	void ConvertUAH_to_EUR()
	{
		if (GetIndex() == 0)
		{
			SetIndex(2);
			cout << "Convert money UAH to EUR (1 EUR = 30 UAH):\n";
			float newFunds = GetFunds() / 30;
			SetFunds(newFunds);
		}
		else
			cout << "ERROR\n\n";

	}

	void ConvertMoney()
	{
		ShowMenuConvertMoney();

		int index;
		cin >> index;

		switch (index)
		{
		case 1:
		{
			SetIndex(index);
			cout << "Convert money UAH to USD (1 USD = 20 UAH):\n";
			float newFunds = GetFunds() / 20;
			SetFunds(newFunds);
			break;
		}
		case 2:
		{
			SetIndex(index);
			cout << "Convert money UAH to EUR (1 EUR = 30 UAH):\n";
			float newFunds = GetFunds() / 30;
			SetFunds(newFunds);
			break;
		}
		default:
			break;
		}

	}

	void Print()
	{
		cout << "Your account number: " << GetNumberAccount() << endl;
		cout << "Your funds: " << GetFunds() << GetCurrency() << endl; // по дефолту 0 валюти і валюта UAH (0)
	}

	void TransferBetweenAccount(Account& YourAccount, Account& OtherAccount, float value)
	{
		if (YourAccount.GetIndex() == this->index && OtherAccount.GetIndex() == this->index)
		{
			if (YourAccount.GetFunds() >= value)
			{
				YourAccount.MinusFunds(value);
				OtherAccount.PlusFunds(value);
			}
			else
				cout << "Error. Incorrect value\n";

			YourAccount.Print();
			OtherAccount.Print();
		}
		else
		{
			cout << "Error. Incorrect value\n";
			cout << "Currencies must match each other\n";
		}
	}
};


int main()
{
	srand(time(nullptr));

	Account test; // рахунок з 0 на рахунку
	test.Print();

	test.PlusFunds(1550); // Додаємо певну суму до акаунта
	test.Print();

	test.MinusFunds(400); // Відмнімаємо певну суму з рахунку
	test.Print();

	cout << "??????????????????????????????????????????????\n";
	//test.ConvertUAH_to_USD();
//test.ConvertUAH_to_EUR();
	test.Print();

	//cout << "??????????????????????????????????????????????\n";

	//test.ConvertMoney();
	//test.Print();

	//cout << "??????????????????????????????????????????????\n";

	//test.MinusFunds(400); // Відмнімаємо певну суму з рахунку
	//test.Print();

	//cout << "??????????????????????????????????????????????\n";

	cout << "\n\n\tNew Account\n\n";

	Account newTest(200);	// рахунок з певною сумою на рахунку
	newTest.Print();
	newTest.PlusFunds(500);	// додаємо певну суму довже існуючого
	newTest.Print();

	newTest.MinusFunds(400); // Відмнімаємо певну суму з рахунку
	newTest.Print();

	newTest.MinusFunds(301); // Відмнімаємо певну суму з рахунку ЯКЩО СУМА ЯКУ ЗНІМАЄМО БІЛЬША ТО ПОМИЛКА (СУМА ЗАЛИШАЄТЬСЯ СТАЛОЮ)
	newTest.Print();

	cout << "\n\t\tTEST TRANSFER\n\n";
	newTest.TransferBetweenAccount(newTest, test, 100);

	return 0;
}