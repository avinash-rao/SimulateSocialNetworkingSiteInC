// TODO Convert to object oriented program
// TODO Divide code into different files

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "pages.hpp"
#include "validations.hpp"

// FUNCTIONS ---------------------------------------------------------------------


												// CREATING NEW User Account-----
void createNewUserAccount() {
	// STORE VALUE $$$$$$$$$$$$$$$
	printf("acc created");
}


char* setUserEmail() {
	fflush(stdin);
	char *email = malloc(100 * sizeof(char));
	int validEmail=0;
	while(validEmail != 1) {
		printf("\n Enter email: ");
		gets(email);
		if(strlen(email)==1)			//Checking for USER CHOOSING MENU Abruptly
			checkForMenuOption(2, email);
		validEmail = validateInput(1, email);
	}
	return email;
}

char* setUserName() {
	fflush(stdin);
	char *name = malloc(100 * sizeof(char));
	printf("\n Enter your Name: ");
	gets(name);
	if(strlen(name)==1)			//Checking for USER CHOOSING MENU Abruptly
		checkForMenuOption(2, name);
	return name;
}

char* setUserAge() {
	fflush(stdin);
	char *age = malloc(100 * sizeof(char));
	int validAge=0;
	while(validAge != 1) {
		printf("\n Enter you Age: ");
		gets(age);
		if(strlen(age)==1)			//Checking for USER CHOOSING MENU Abruptly
			checkForMenuOption(2, age);
		validAge = validateInput(3, age);
	}
	return age;
}

char* setUserLocation() {
	fflush(stdin);
	char *location = malloc(100 * sizeof(char));
	printf("\n Enter your Location: ");
	gets(location);
	if(strlen(location)==1)			//Checking for USER CHOOSING MENU Abruptly
		checkForMenuOption(2, location);
	return location;
}

char* setUserPassword() {
	fflush(stdin);
	char *password = malloc(100 * sizeof(char));
	int validPassword=0;
	while(validPassword != 1) {
		printf("\n Enter password: ");
		gets(password);
		if(strlen(password)==1)			//Checking for USER CHOOSING MENU Abruptly
			checkForMenuOption(2, password);
		validPassword = validateInput(2, password);
	}
	return password;
}



												// USER SIGNUP------------
void userSignupInput() {
	int validPassword=0;
	char *email, *password, *confirmPassword,*name, *age, *location;
	printf("\n \t User Signup \n");
	
	email = setUserEmail();
	password = setUserPassword();
	name = setUserName();
	age = setUserAge();
	location = setUserLocation();
	
	while(validPassword != 1) {
		confirmPassword = setUserPassword();
		
		if(strcmp(password,confirmPassword)!=0) {
			printf("\n Your Passwords did not match! Please try again.");
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
	printf("\n \t Edit Profile \n");
	printf("\n 3.Change Name \t 4.Change Age \t 5.Change Location \t 6.Reset Password \t 7.Delete Account \n");
	scanf("%d",&userInput);
	
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
			
			if(strcmp(password,confirmPassword)!=0) {
				printf("\n Your Passwords did not match! Please try again.");
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

// MAIN -------------------------------------------------------------------------

int main()
{
    landingPage();
}