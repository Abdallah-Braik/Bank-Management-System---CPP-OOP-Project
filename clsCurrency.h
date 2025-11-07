#pragma once
#include <iostream>
#include<vector>
#include<fstream>
#include <string>
#include"clsString.h"

using namespace std;
class clsCurrency
{
private:
	enum enMode { enEmptyMode = 0, enUpdateMode = 1 };

	enMode _Mode;
	string _CountryName;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static vector <string> _ConvertLineVector(string line, string del="#//#")
	{
		vector<string> V;
		short pos;
		while ( (pos = line.find(del)) != std::string::npos)
		{
			string part = line.substr(0, pos);
			V.push_back(part);
			line.erase(0, pos + del.size());
		}
		if (line != "")
			V.push_back(line);

		return V;
	}

	static clsCurrency  _ConvertVectorToObject(vector<string> V)
	{
		if (V.size() != 4)
		{
			return _GetEmptyObject();
		}

		return clsCurrency(enMode::enUpdateMode, V[0], V[1], V[2], stof(V[3]));
	}

	static string _ConvertObjectToLine(clsCurrency& C,string del="#//#")
	{
		string line = C.CountryName() + del + C.CurrencyCode() + del + C.CurrencyName()+ del + to_string(C.Rate());
		return line;
	}

	static vector <clsCurrency> _LoadCurrencyDataFromFile()
	{
		vector <clsCurrency> vC;
		string line;
		fstream file;
		file.open("Currency.txt", ios::in);
		if (file.is_open())
		{
			while (getline(file, line))
			{
				clsCurrency Ob = _ConvertVectorToObject(_ConvertLineVector(line));
				vC.push_back(Ob);
			}

			file.close();
		}

		return vC;
	}

	static clsCurrency _GetEmptyObject()
	{
		return clsCurrency(enMode::enEmptyMode, "", "", "", 0);
	}

	static void _SaveCurrenciesDateToFile(vector<clsCurrency> & vC)
	{
		fstream file;
		file.open("Currency.txt", ios::out);
		if (file.is_open())
		{
			for (clsCurrency& C : vC)
			{
				file << _ConvertObjectToLine(C) << endl;
			}
			file.close();
		}
	}

public:

	clsCurrency(enMode Mode, string CountryName, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_CountryName = CountryName;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	string CountryName()
	{
		return _CountryName;
	}

	string CurrencyCode()
	{
		return _CurrencyCode;
	}

	string CurrencyName()
	{
		return _CurrencyName;
	}

	void SetRate(float Rate)
	{
		_Rate = Rate;
	}

	float Rate()
	{
		return _Rate;
	}

	enMode Mode()
	{
		return _Mode;
	}

	static clsCurrency FindByCountry(string Country)
	{
		vector <clsCurrency> vC = _LoadCurrencyDataFromFile();
		Country = clsString::UpperAllString (Country);
		for (clsCurrency& c : vC)
		{
			if (clsString::UpperAllString(c.CountryName()) == Country)
				return c;
		}
		return _GetEmptyObject();

	}

	static clsCurrency FindByCode(string Code)
	{
		Code = clsString::UpperAllString(Code);
		vector <clsCurrency> vC = _LoadCurrencyDataFromFile();
		for (clsCurrency& c : vC)
		{
			if (clsString::UpperAllString(c.CurrencyCode()) == Code)
				return c;
		}
		return _GetEmptyObject();

	}

	bool IsEmpty()
	{
		return (_Mode == enMode::enEmptyMode);
	}

	static bool IsCurrencyExistCode(string CurrencyCode)
	{
		clsCurrency C = FindByCode(CurrencyCode);
		return(! C.IsEmpty());
	}

	static bool IsCurrencyExistCountry(string CountryName)
	{
		clsCurrency C = FindByCountry(CountryName);
		return(!C.IsEmpty());
	}

	static vector<clsCurrency> GetCurrencyList()
	{
		return _LoadCurrencyDataFromFile();
	}

	void Save()
	{
		vector <clsCurrency> cV = _LoadCurrencyDataFromFile();
		for (clsCurrency& C : cV)
		{
			if (_CountryName == C.CountryName())
			{
				C = *this;
				_SaveCurrenciesDateToFile(cV);
			}

		}

	}






};

