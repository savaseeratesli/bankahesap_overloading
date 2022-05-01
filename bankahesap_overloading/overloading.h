#include <iostream>

using namespace std;

class bankAccount
{
private:
	float accountBalance;
	string personName, personSurname, personPhone;

	friend ostream& operator <<(ostream&, const bankAccount&);


public:
	bankAccount(string name, string surname, float balance = 0, string phone_number = "");
	bankAccount(const bankAccount& oth);
	~bankAccount();

	bool controlNameSurname(string nameOrSurname);
	bool controlPhoneNumber(string phoneNumber);
	//void displayProfile();//<<
	//void credit(float);//+
	void operator +(float);

	//void withdraw(float);//-
	void operator -(float);

	void sendMoney(bankAccount& othAccount, float amount);
	void setPersonName(string name);
	void setPersonSurname(string surname);
	void setPersonPhone(string phone);
	void setPersonBalance(float balance = 0);
	int getPersonBalance() const
	{
		return accountBalance;
	};
	string getPersonName()const
	{
		return personName;
	}
	string getPersonSurname()const
	{
		return personSurname;
	}
	string getPersonPhone()const
	{
		return personPhone;
	}


};


void bankAccount::setPersonName(string name)
{
	//Kullanýcý doðru girene kadar ismi al
	while (!controlNameSurname(name))
	{
		cout << "Gecersiz Isim!!" << endl;
		cin >> name;
	}
	personName = name;
}

void bankAccount::setPersonSurname(string surname)
{
	//Kullanýcý doðru girene kadar ismi al
	while (!controlNameSurname(surname))
	{
		cout << "Gecersiz Soyisim!!" << endl;
		cin >> surname;
	}
	personSurname = surname;
}

void bankAccount::setPersonPhone(string phone)
{
	//Kullanýcý doðru girene kadar ismi al
	while (!controlPhoneNumber(phone))
	{
		cout << "Gecersiz Telefon Numarasi!!" << endl;
		cin >> phone;
	}
	personPhone = phone;
}

void bankAccount::setPersonBalance(float balance)
{
	if (balance < 0)
	{
		accountBalance = 0;
		cout << "Hatali Bakiye!!" << endl;
	}
	else
	{
		accountBalance = balance;
	}
}

bankAccount::bankAccount(string name, string surname, float balance, string phoneNumber)
{
	setPersonName(name);
	setPersonSurname(surname);
	setPersonPhone(phoneNumber);
	setPersonBalance(balance);

	cout << "Hesap Olusturuldu." << endl;
}

bankAccount::~bankAccount()
{
	cout << "Hesap Kapatildi." << endl;
}

bankAccount::bankAccount(const bankAccount& othAccount)
{
	personName = othAccount.personName;
	personSurname = othAccount.personSurname;
	personPhone = othAccount.personPhone;
	accountBalance = othAccount.accountBalance;

	cout << "Hesap Kopyalandi." << endl;

}

bool bankAccount::controlNameSurname(string nameOrSurname)
{
	for (unsigned i = 0; i < nameOrSurname.length(); i++)
	{
		//at-> indexteki karaktere eriþmek için
		if (!((nameOrSurname.at(i) >= 'A' && nameOrSurname.at(i) <= 'Z') || (nameOrSurname.at(i) >= 'a' && nameOrSurname.at(i) <= 'z')))
		{
			return false;//a-z arasýnda deðilse false
		}

	}
	return true;
}

bool bankAccount::controlPhoneNumber(string phoneNumber)
{
	if (phoneNumber.empty())
	{
		return true;
	}

	if (phoneNumber.length() != 11)
	{
		return false;
	}

	for (unsigned i = 0; i < phoneNumber.length(); i++)
	{
		if (!(phoneNumber.at(i) >= '0' && phoneNumber.at(i) <= '9'))
		{
			return false;
		}
	}
	return true;
}

void bankAccount::operator+(float amount)
{
	while (amount <= 0)
	{
		cout << "Gecersiz Miktar!!" << endl;
		cin >> amount;
	}
	accountBalance += amount;
}

void bankAccount::operator-(float amount)
{
	while (amount <= 0 || amount > accountBalance)
	{
		cout << "Gecersiz Miktar!!" << endl;
		cin >> amount;
	}
	accountBalance -= amount;
}

ostream& operator<<(ostream& osObject, const bankAccount& bankAccountObj)
{
	osObject << "--------------------------" << endl
		<< "Ad: " << bankAccountObj.personName << endl
		<< "Soyad: " << bankAccountObj.personSurname << endl
		<< "Tel: " << bankAccountObj.personPhone << endl
		<< "Hesap: " << bankAccountObj.accountBalance << endl;

	return osObject;
}

void bankAccount::sendMoney(bankAccount& othAccount, float amount)
{
	while (amount <= 0 || amount > accountBalance)
	{
		cout << "Gecersiz Miktar!!" << endl;
		cin >> amount;
	}

	accountBalance -= amount;//Gönderen
	othAccount.accountBalance += amount;//Alýcý
}










