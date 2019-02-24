#include<iostream>
#include<string>
#include<regex>
using namespace std;

void password_valid(string password)
{	
	
	//********************************************************************************************************
	regex lowercase_expression{ "[a-z]+" };
	regex uppercase_expression{ "[A-Z]+" };
	regex numeric_expression{ "[0-9]+" };
	regex specialcharacter_expression{ "[*$_#=@]+" };
	regex othercharacter_expression{ "[%!)(]+" };
	//********************************************************************************************************
	
	//********************************************************************************************************
	if(password.length()<6)
	{
		cout<<"\n"<<password<<" Failure Password must be at least 6 characters long.";
	}
	else if(password.length()>12)
	{
		cout<<"\n"<<password<<" Failure Password must be at max 12 characters long.";
	}
	else if(!regex_search(password,lowercase_expression))
	{
		cout<<"\n"<<password<<" Failure Password must contain atleast 1 lowercase character.";
	}
	else if(!regex_search(password,uppercase_expression))
	{
		cout<<"\n"<<password<<" Failure Password must contain atleast 1 uppercase character.";
	}
	else if(!regex_search(password,numeric_expression))
	{
		cout<<"\n"<<password<<" Failure Password must contain atleast 1 numeric character.";
	}
	else if(!regex_search(password,specialcharacter_expression))
	{
		cout<<"\n"<<password<<" Failure Password must contain atleast 1 special character.";
	}
	else if(regex_search(password,othercharacter_expression))
	{
		cout<<"\n"<<password<<" Failure Password  cannot contain %!)(";
	}
	else
	{
		cout<<"\n"<<password<<" Success";
	}
	//********************************************************************************************************
}

int main()
{
	string password;
	cout<<"\n***********************************************\n";
	cout<<"*WELCOME TO THE PASSWORD VALIDATION MODULE..!!*";
	cout<<"\n***********************************************";
	cout<<"\nEnter the password\n";
	getline(cin, password);
	cout<<"\n-----------------------------------------------------------------------------------------------------";
	string temp;
	istringstream passwordStream(password);
	while(getline(passwordStream, temp, ','))
	{
		password_valid(temp);
		cout<<"\n-----------------------------------------------------------------------------------------------------";
	}
	
	cout<<"\n\n\n****************************\n";
	cout<<"*    By Priyank Agarwal    *\n";
	cout<<"*    151349                *\n";
	cout<<"*    JUIT                  *";
	cout<<"\n****************************\n";
	return 0;
}
