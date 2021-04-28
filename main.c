#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// TEXTS -------------------------------------------------------------------------

void textWebsiteName() {
	printf("\n \t\t\t FakeBook\n");
}

void textDevelopers() {
	printf("\n\n\n ----------------------------------------------------------------- ");
	printf("\n Developers - Avinash, Chetali, Garima, Jeet, Utpal");
}

// FUNCTIONS ---------------------------------------------------------------------
												// ALL MENU OPTIONS---------
void menuBar(int login,int signup,int exit,int logout,int back,int editProfile,int chat,int fr) {
	int slno = 1;
	printf("\n");
	if(login==1) {
		printf(" %d.Login",slno);
		slno++;
	}
	if(signup==1) {
		printf(" \t %d.Signup",slno);
		slno++;
	}
	if(exit==1) {
		printf(" \t %d.Exit",slno);
		slno++;
	}
	if(logout==1) {
		printf(" \t %d.Logout",slno);
		slno++;
	}
	if(back==1) {
		printf(" \t %d.Back",slno);
		slno++;
	}
	if(editProfile==1) {
		printf(" \t %d.Edit Profile",slno);
		slno++;
	}
	if(chat==1) {
		printf(" \t %d.Chat",slno);
		slno++;
	}
	if(fr==1) {
		printf(" \t %d.Friend Request",slno);
		slno++;
	}
}
												// USER SWITCHING b/w PAGES-----
void userChoice(int curntPage) {
	int choice;
	printf("\n Enter your choice: ");
	scanf("%d",&choice);
	
	if(curntPage==1 && choice==1)
		loginPage();
		
	if(curntPage==1 && choice==2)
		signupPage();
		
	if(curntPage==1 && choice==3)
		exit(0);
}
												// USER CHOOSING MENU Abruptly-----
void checkForMenuOption(int curntPage, char *option[]) {
	if(curntPage==2 && strcmp(option,"1")==0)
		exit(0);
		
	if(curntPage==2 && strcmp(option,"2")==0)
		landingPage();
}
												// CREATING NEW User Account-----
void createNewUserAccount() {
	// STORE VALUE $$$$$$$$$$$$$$$
	printf("acc created");
}
												// USER LOGIN Validation-----
void validateUserLogin(char *email[], char *password[]) {
	int validDetails=0;
	
	// READ TXT FILES $$$$$$$$$$$$$$$
	if(validDetails==1)
		userHomePage(email);
	else {
		printf("\n Incorrect Email or Password");
		sleep(1000);
		loginPage();
	}
}
												// USER LOGIN------------
void userLoginInput() {
	char email[40], password[20];
	printf("\n \t User Login");
	
	printf("\n Enter email: ");
	scanf("%s", &email);
	if(strlen(email)==1)			//Checking for USER CHOOSING MENU Abruptly
		checkForMenuOption(2, email);
	
	printf("\n Enter password: ");
	scanf("%s", &password);
	if(strlen(password)==1)			//Checking for USER CHOOSING MENU Abruptly
		checkForMenuOption(2, password);
		
	validateUserLogin(email, password);
}
												// USER SIGNUP Validation-----
int validateInput(int inputType, char *userString) {
	// inputType = 1->Email, 2->Password, 3->Age
	
	// Email Validation
	if(inputType==1) {
		int i, letter, atTheRate=0, dotCom=0, crtPosition=1;
		
		if(userString[0]=='@' || userString[0]=='.')
			crtPosition = 0;
		for(i=0; i<strlen(userString); i++) {
			letter = userString[i];				//Checking for only VALID Email characters
			if((letter>=48 && letter<=57) || (letter>=97 && letter<=122) || letter==46 || letter==64)
			{
				if(userString[i]=='@')
					atTheRate = 1;
				if(userString[i]=='.')
					dotCom = 1;
			}
			else {								//If INVALID Email characters are found
				printf(" Valid characters in Email are Small alphabets, Numbers, @ , .");
				return 0;
			}
		}
		if(atTheRate==1 && dotCom==1 && crtPosition==1)	//Email Validation PASSED
			return 1;
		else {											//Email Validation FAILED
			if(atTheRate==0)
				printf("\n Include @ symbol in the email.");
			if(dotCom==0)
				printf("\n Include .com at the end of the email.");
			if(crtPosition==0)
				printf("\n Do not use @/. at begenning of the email.");
			return 0;
		}
	}
	
	//Password Validation
	if(inputType==2) {
		if(strlen(userString) >= 5)
			return 1;
		else {
			printf("\n Password must be of minimum 6 characters.");
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
				printf("\n Please enter your valid age, 13 years and below can not create their account.");
			return 0;
		}
	}
}
												// USER SIGNUP------------
void userSignupInput() {
	int validEmail=0, validPassword=0, validAge=0;
	char email[100], password[100], confirmPassword[100],name[100], age[100], location[100];
	printf("\n \t User Signup");
	
	while(validEmail != 1) {
		printf("\n Enter email: ");
		scanf("%s", email);
		if(strlen(email)==1)			//Checking for USER CHOOSING MENU Abruptly
			checkForMenuOption(2, email);
		validEmail = validateInput(1, email);
	}
	
	while(validPassword != 1) {
		printf("\n Enter password: ");
		scanf("%s", password);
		if(strlen(password)==1)			//Checking for USER CHOOSING MENU Abruptly
			checkForMenuOption(2, password);
		validPassword = validateInput(2, password);
	}
	
	printf("\n Enter your Name: ");
	scanf("%s", name);
	if(strlen(name)==1)			//Checking for USER CHOOSING MENU Abruptly
		checkForMenuOption(2, name);
		
	while(validAge != 1) {
		printf("\n Enter you Age: ");
		scanf("%s", age);
		if(strlen(age)==1)			//Checking for USER CHOOSING MENU Abruptly
			checkForMenuOption(2, age);
		validAge = validateInput(3, age);
	}
		
	printf("\n Enter your Location: ");
	scanf("%s", location);
	if(strlen(location)==1)			//Checking for USER CHOOSING MENU Abruptly
		checkForMenuOption(2, location);
	
	validPassword = 0;
	while(validPassword != 1) {
		printf("\n Enter password: ");
		scanf("%s", confirmPassword);
		if(strlen(confirmPassword)==1)			//Checking for USER CHOOSING MENU Abruptly
			checkForMenuOption(2, confirmPassword);
		validPassword = validateInput(2, confirmPassword);
		
		if(strcmp(password,confirmPassword)!=0) {
			printf("\n Your Passwords did not match! Please try again.");
			validPassword = 0;
		}
	}
	
	createNewUserAccount();
}

// PAGES ------------------------------------------------------------------------

void landingPage() {
	system("cls");
	textWebsiteName();
	menuBar(1,1,1,0,0,0,0,0);
	textDevelopers();
	userChoice(1);
}

void loginPage() {
	system("cls");
	textWebsiteName();
	menuBar(0,0,1,0,1,0,0,0);
	userLoginInput();
}

void signupPage() {
	system("cls");
	textWebsiteName();
	menuBar(0,0,1,0,1,0,0,0);
	userSignupInput();
}

void userHomePage(char *email) {
	
}

// MAIN -------------------------------------------------------------------------

int main()
{
    landingPage();
}
