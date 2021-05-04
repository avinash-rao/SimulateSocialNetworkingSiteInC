#include <iostream>
using namespace std;
#include <cstring>
#include <stdlib.h>
#include <ctype.h>
#ifndef VALIDATIONS_HPP
#define VALIDATIONS_HPP
#include "pages.hpp"
// USER LOGIN Validation-----
class Validation{
	public:
	void validateUserLogin(string email, string password) {
	int validDetails=0;
	
	// READ TXT FILES $$$$$$$$$$$$$$$
	if(validDetails==1)
		userHomePage(email);
	else {
		cout <<"\n Incorrect Email or Password";
		sleep(1000);
		loginPage();
	}
}
												// USER LOGIN------------
void userLoginInput() {
	string email, password;
	cout <<"\n \t User Login \n";
	
	cout <<"\n Enter email: ";
	cin >> email;
	if(email.length()==1)			//Checking for USER CHOOSING MENU Abruptly
		checkForMenuOption(2, email);
	
	cout <<"\n Enter password: ";
	cin >> password;
	if(password.length()==1)			//Checking for USER CHOOSING MENU Abruptly
		checkForMenuOption(2, password);
		
	validateUserLogin(email, password);
}
	// USER SIGNUP Validation-----
int validateInput(int inputType, string userString) {
	// inputType = 1->Email, 2->Password, 3->Age
	
	// Email Validation
	if(inputType==1) {
		int i, letter, atTheRate=0, dotCom=0, crtPosition=1;
		
		if(userString[0]=='@' || userString[0]=='.')
			crtPosition = 0;
		for(i=0; i<userString.length(); i++) {
			letter = userString.at(i);				//Checking for only VALID Email characters
			if((letter>=48 && letter<=57) || (letter>=97 && letter<=122) || letter==46 || letter==64)
			{
				if(userString.at(i)=='@')
					atTheRate = 1;
				if(userString.at(i)=='.')
					dotCom = 1;
			}
			else {								//If INVALID Email characters are found
				cout <<" Valid characters in Email are Small alphabets, Numbers, @ , .";
				return 0;
			}
		}
		if(atTheRate==1 && dotCom==1 && crtPosition==1)	//Email Validation PASSED
			return 1;
		else {											//Email Validation FAILED
			if(atTheRate==0)
				cout <<"\n Include @ symbol in the email.";
			if(dotCom==0)
				cout <<"\n Include .com at the end of the email.";
			if(crtPosition==0)
				cout <<"\n Do not use @/. at begenning of the email.";
			return 0;
		}
	}
	
	//Password Validation
	if(inputType==2) {
		if(strlen(userString) >= 5)
			return 1;
		else {
			cout <<"\n Password must be of minimum 6 characters.";
			return 0;
		}
	}
	
	//Age Validation
	if(inputType==3) {
		int age = atoi(userString);
		if(age>=14 && age<=99)
			return 1;
		else {
			if(age<=13)
				cout <<"\n Please enter your valid age, 13 years and below can not create their account.";
			return 0;
		}
	}
}
void userSignupInput() {
	int validPassword=0;
	string email, password, confirmPassword, name, age, location;
	cout <<("\n \t User Signup \n");
	
	email = setUserEmail();
	password = setUserPassword();
	name = setUserName();
	age = setUserAge();
	location = setUserLocation();
	
	while(validPassword != 1) {
		confirmPassword = setUserPassword();
		
		if(password.compare(confirmPassword))!=0) {
			cout <<("\n Your Passwords did not match! Please try again.");
			validPassword = 0;
		}
		else
			validPassword = 1;
	}
	
	createNewUserAccount();
	//free(email,password,name,age,location,confirmPassword);
}
												// USER EDIT PROFILE (SETTINGS)------------
void userSettingsInput() {
	int userInput;
	string password, confirmPassword,name, age, location;
	cout <<"\n \t Edit Profile \n";
	cout <<"\n 3.Change Name \t 4.Change Age \t 5.Change Location \t 6.Reset Password \t 7.Delete Account \n";
	cin>>userInput;
	
	if(userInput==3) {
		name = setUserName();
		// Update name $$$$$$$$$$$$$$$$$$$$$$$$$
	}
	
	if(userInput==4) {
		age = setUserAge();
		// Update age $$$$$$$$$$$$$$$$$$$$$$$$$
	}
	
	if(userInput==5) {
		location = setUserLocation();
		// Update location $$$$$$$$$$$$$$$$$$$$$$$$$
	}
	
	if(userInput==6) {
		int validPassword=0;
		password = setUserPassword();
		
		while(validPassword != 1) {
			confirmPassword = setUserPassword();
			
			if(password.compare(confirmPassword)!=0) {
				cout <<"\n Your Passwords did not match! Please try again.";
				validPassword = 0;
			}
			else
				validPassword = 1;
		}
		// Update password $$$$$$$$$$$$$$$$$$$$$$$$$
	}
	
	if(userInput==7) {
		// Delete Account $$$$$$$$$$$$$$$$$$$$$$$$$
	}
}
};
#endif