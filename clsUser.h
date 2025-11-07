#pragma once
#include<iostream>
#include <vector>
#include <string>
#include <fstream>
#include"clsPerson.h"
#include "clsDate.h"


using namespace std;
class clsUser :public clsPerson
{
private :
	enum enMode{EmptyMode=0,UpdateMode=1,AddMode=3};
	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permission;
	bool _MarkForDelete = false;

	static clsUser _ConvertLineToUserObject(string line, string del="#//#")
	{
		vector <string> S;
		string Part;
		short pos;
		while ((pos = line.find(del)) != std::string::npos)
		{
			Part = line.substr(0, pos);
			line.erase(0, pos + del.size());
			S.push_back(Part);
		}
		if (line != "")
			S.push_back(line);
		
		if (S.size() < 7)
			return _GetEmptyUser();
		
		else 
		return clsUser (enMode::UpdateMode, S[0], _DecryptPassword(S[1]), S[2], S[3], S[4], S[5], stoi(S[6]));

	}

	string _ConvertUserObjectToLine(clsUser User, string del = "#//#")
	{
		string s1;
		s1 = User.UserName() + del 
			+ _EncryptPassword(User.Password())+ del 
			+ User.FirstName() + del
			+ User.LastName()+ del 
			+ User.Email() + del
			+ User.Phone() + del
			+ to_string(User._Permission);
		return s1;
	}

	static clsUser _GetEmptyUser()
	{
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static vector <clsUser> _LoadUserDataFromFile()
	{
		vector <clsUser> vUsers;
		string line;

		fstream file;
		file.open("Users.txt", ios::in);
		if (file.is_open())
		{
			while (getline(file, line))
			{
				clsUser User = _ConvertLineToUserObject(line);
				vUsers.push_back(User);
			}

			file.close();
		}
		return vUsers;

	}

	void _SaveUsersDataToFile(vector<clsUser>vUsers)
	{
		string s1;
		fstream file;
		file.open("Users.txt", ios::out);
		if (file.is_open())
		{
			for (clsUser & C : vUsers)
			{
				if (C._MarkForDelete == true)
					continue;
				
				else
				{
					s1 = _ConvertUserObjectToLine(C);
					file << s1 << endl;
				}
			}
			file.close();
		}
	}

	 void _AddNewUser()
	 {
		 vector<clsUser> vUsers = _LoadUserDataFromFile();
		 vUsers.push_back(*this);
		 _SaveUsersDataToFile(vUsers);
	 }

	 void _UpdateUser()
	 {
		 vector<clsUser> vUsers = _LoadUserDataFromFile();
		 for (clsUser& c : vUsers)
		 {
			 if (c.UserName() == _UserName)
				 c = *this;
			 break;
		 }
		 _SaveUsersDataToFile(vUsers);
	 }

	


public :
	static string _EncryptPassword(string s)
	{
		for (int i = 0;i < s.length();i++)
		{
			s[i] = char((int)s[i] + 5);
		}
		return s;
	}

	static string _DecryptPassword(string s)
	{

		for (int i = 0;i < s.length();i++)
		{
			s[i] = char((int)s[i] - 5);
		}
		return s;
	}

	enum enPermission {All=-1,ShowClientssList=1,AddClient=2,DeleteClient=4,
		UpdateClient=8,FindClient=16,Transaction=32,ManageUsers=64,LogIn=128};

	clsUser(enMode Mode, string UserName, string Password, string FirstName, string LastName,
		string Email, string Phone,int Permission) :
		clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_Permission = Permission;
		_UserName = UserName;
		_Password = Password;
	}

	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}
	string UserName()
	{
		return _UserName;
	}

	void SetPassword(string Password)
	{
		_Password = Password;
	}
	string  Password()
	{
		return _Password;
	}

	void SetPermission(int Permission)
	{
		_Permission = Permission;
	}
	int Permission()
	{
		return _Permission;
	}

	bool IsEmpty()
	{
		return(_Mode == enMode::EmptyMode);
	}

	static bool IsUserExist(string UserName)
	 {
		 clsUser user = Find(UserName);
		 return (!user.IsEmpty());
	 }

	static clsUser Find(string UserName)
	{
		vector<clsUser>vUser = _LoadUserDataFromFile();
		for (clsUser& C : vUser)
		{
			if (C.UserName() == UserName)
				return C;
		}
		return _GetEmptyUser();
	}

	static clsUser Find(string UserName, string Password)
	{
		vector<clsUser> vUser = _LoadUserDataFromFile();
		for (clsUser& C : vUser)
		{
			if (C.UserName() == UserName && C.Password() == Password)
				return C;

		}
		return _GetEmptyUser();

	}

	static vector <clsUser> GetUsersList()
	{
		return _LoadUserDataFromFile();
	}

	enum ensucced {succeded=0,failed=2};

	 ensucced Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
			return ensucced::failed;

		case enMode::AddMode:
			_Mode = enMode::UpdateMode;
			_AddNewUser();
			return ensucced::succeded;

		case enMode::UpdateMode:
			_UpdateUser();
			return ensucced::succeded;

		}

	}

	 static	clsUser AddNewUser(string UserName)
	 {
		 return clsUser(enMode::AddMode, UserName,"", "", "", "", "", 0);
	 }

	 bool Delete()
	 {
		 vector<clsUser> vUser = _LoadUserDataFromFile();
		 for (clsUser& C : vUser)
		 {
			 if (C.UserName() == _UserName)
			 {
				 C._MarkForDelete = true;
				 _SaveUsersDataToFile(vUser);
				 *this = _GetEmptyUser();
				 return true;
			 }
			 
		 }
		 return false;
	 }

	 bool CheckAccess(enPermission Access)
	 {

		 if (this->_Permission == enPermission::All)
			 return true;
		

			 if ((Access & this->_Permission) == Access)
				 return true;

			 else
				 return false;

	 }

	 void SaveLogInInfo(string del = "#//#")
	 {
		 fstream file;
		 file.open("Login.txt", ios::out | ios::app);
		 if (file.is_open())
		 {
			 file << clsDate::GetSystemDate() << del << _UserName << del << _EncryptPassword(_Password) 
				 << del <<_Permission << endl;
			 file.close();
		 }


	 }


};

