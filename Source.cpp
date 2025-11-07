#include <iostream>
#include "clsLoginScreen.h"

using namespace std;

int main()
{

	while (true)
	{
		
		if (!clsLoginScreen::LoginScreen())
			break;

	}

	//fstream file;
	//file.open("Users.txt", ios::out);
	//if (file.is_open())
	//{
	//	file << "Abdallah#//#1313#//#Abdallah#//#Braik#//#Abdallah@mail.com#//#01272018640#//#-1\n";
 //    
	//}
		


	return 0;
}