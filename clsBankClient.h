#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "clsPerson.h"
#include "Global.h"
class clsBankClient:public clsPerson
{
private: 
	enum enMode {EmptyMode=0,UpdateMode=1,AddNewMode=2};

	enMode _Mode;
	string _AcountNumber;
	string _PinCode;
	float _AcountBalance;
	bool _MarkForDelete = false;

	static clsBankClient _ConvertLineToClientObject(string line,string delimiter="#//#")
	{
		vector <string> StringVec;
		string S1;

		short pos;
		while ((pos = line.find(delimiter)) != std::string::npos)
		{
			S1 = line.substr(0, pos);
			StringVec.push_back(S1);
			line.erase(0, pos + delimiter.size());

		}
		if (line != "")
			StringVec.push_back(line);

		if (StringVec.size() < 7)
		{
			// Return an empty client instead of crashing
			return _GetEmptyClientObject();
		}
		return clsBankClient(enMode::UpdateMode, StringVec[0], StringVec[1], StringVec[2], StringVec[3],
			StringVec[4], StringVec[5], stof(StringVec[6]));
	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	 }

	static vector <clsBankClient> _LoadClientDataFromFile()
	{
		vector <clsBankClient> vClients;
		string line;
		fstream file;
		file.open("Clients.txt", ios::in);
		if (file.is_open())
		{
			while (getline(file, line))
			{
				clsBankClient Client = _ConvertLineToClientObject(line);
				vClients.push_back(Client);
			}
			file.close();

		}
		return vClients;
	}

	string _ConvertClientObjectToLine(clsBankClient client,string del="#//#")
	{
		string s1;
	      s1 =  client.FirstName() + del + client.LastName() + del + client.Email() + del + client.Phone()
			+ del + client.AcountNumber() + del + client.PinCode() + del + to_string(client.AcountBalance());
		return s1;
			
	}

	void _SaveClientDataToFile(vector<clsBankClient> vClients)
	{
		fstream file;
		file.open("Clients.txt", ios::out);
		if (file.is_open())
		{
			for (clsBankClient& c : vClients)
			{
				if (c._MarkForDelete == false)
				{
					string line = _ConvertClientObjectToLine(c);
					file << line << endl;
				}
		    }
			file.close();
		}
	}
	
	void _Update()
	{
		vector<clsBankClient> vClients = _LoadClientDataFromFile();

		for (clsBankClient& c : vClients)
		{
			if (c.AcountNumber() == AcountNumber())
			{
				c = *this; //change c object data(the old data) to the current object(the new data) (*this)
				break;
			}
			}
		_SaveClientDataToFile(vClients);
	}

	void _SaveNewClient()
	{
		vector <clsBankClient> vClients = _LoadClientDataFromFile();
		vClients.push_back(*this);
		_SaveClientDataToFile(vClients);
	}


public:
	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone
		, string AcountNumber, string PinCode, float AcountBalance) :clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AcountNumber = AcountNumber;
		_PinCode = PinCode;
		_AcountBalance = AcountBalance;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string AcountNumber()
	{
		return _AcountNumber;
	}

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}
	string PinCode()
	{
		return _PinCode;
	}

	void SetAcountBalance(float AcountBalance)
	{
		_AcountBalance = AcountBalance;
	}
	float AcountBalance()
	{
		return _AcountBalance;
	}

	static clsBankClient Find(string AcountNumber)
	{
		fstream file;
		string line;
		file.open("Clients.txt", ios::in);
		if (file.is_open())
		{
			while (getline(file, line))
			{
				clsBankClient Client= _ConvertLineToClientObject(line);
				if (Client.AcountNumber() == AcountNumber)
				{
					file.close();
					return Client;
				}
			}
			file.close();
		}
		return _GetEmptyClientObject();

	}

	static clsBankClient Find(string AcountNumber, string PinCode)
	{
		fstream file;
		string line;
		file.open("Clients.txt", ios::in);
		if (file.is_open())
		{
			while (getline(file, line))
			{
				clsBankClient Client = _ConvertLineToClientObject(line);
				if (Client.AcountNumber() == AcountNumber && Client.PinCode()==PinCode)
				{
					file.close();
					return Client;
				}
			}
			file.close();
		}
		return _GetEmptyClientObject();

	}

	static bool IsClientExist(string AcountNumber)
	{
		clsBankClient Client = clsBankClient::Find(AcountNumber);
		return (!Client.IsEmpty());
	}

	enum enSave{Failed=0,Succeded=1,AcountNumberExist=2};

	enSave SaveMode()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
			return enSave::Failed;

		case enMode::UpdateMode:
			_Update();
			return enSave::Succeded;
		
		case enMode::AddNewMode:
			if (clsBankClient::IsClientExist(_AcountNumber))
				return enSave::AcountNumberExist;
			else
			{
				_Mode = enMode::UpdateMode;
				_SaveNewClient();
				return enSave::Succeded;
			}
		
		}

	}

    static	clsBankClient CreateNewClient(string AcountNumber)
	{
	return clsBankClient(enMode::AddNewMode, "", "", "", "", AcountNumber, "", 0);
	}
    
    bool Delete()
{
	vector <clsBankClient> vClients = _LoadClientDataFromFile();
	for (clsBankClient& c : vClients)
	{
		if (c.AcountNumber() == _AcountNumber)
		{
			c._MarkForDelete = true;
	       _SaveClientDataToFile(vClients);
	       *this = _GetEmptyClientObject();
	       return  true;
		}

	}
	return false;

}
    
    static vector<clsBankClient> GetClientsList()
{
	return _LoadClientDataFromFile();
}
    
	static double TotalBalances()
	{
		vector<clsBankClient>vClients = _LoadClientDataFromFile();
		double total = 0;
		for (clsBankClient& c : vClients)
		{
			total += c.AcountBalance();
		}
		return total;

	}

	 void Deposit(double Amount)
	{
		_AcountBalance += Amount;
		SaveMode();
	}

	 bool Withdraw(double Amount)
	 {
		 if (Amount > _AcountBalance)
			 return false;
		 
		 else
		 {
			 _AcountBalance -= Amount;
			 SaveMode();
			 return true;
		 }

	 }

	 bool Transfer(double Amount, clsBankClient & Destination)
	 {
		 if (Amount > _AcountBalance)
			 return false;

		 Withdraw(Amount);
		 Destination.Deposit(Amount);
		 return true;
	 }

	 void SaveTransferInfo(clsBankClient Destination, double Amount , string del = "#//#")
	 {
		 fstream file;
		 file.open("TransferLog.txt", ios::out | ios::app);
		 if (file.is_open())
		 {
			 file << clsDate::GetSystemDate() << del << _AcountNumber<< del <<_AcountBalance << del <<
				 Destination.AcountNumber() << del <<Destination.AcountBalance() << del << Amount
				 <<del<<CurrentUser.UserName()<< endl;
			 file.close();
		 }


	 }


};

