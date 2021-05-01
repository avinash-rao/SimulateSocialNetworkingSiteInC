#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// TEXTS -------------------------------------------------------------------------

void textWebsiteName() {
	printf("\n \t\t\t FakeBook");
	printf("\n \t\t\t----------\n\n");
}

void textDevelopers() {
	printf("\n Developers - Avinash, Chetali, Garima, Jeet, Utpal \n");
}

// FUNCTIONS ---------------------------------------------------------------------
												// ALL MENU OPTIONS---------
void menuBar(int login,int signup,int exit,int logout,int back,int editProfile,int chat,int fr) {
	int slno = 1, i;
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
	
	printf("\n");
	for(i=1; i<=slno; i++)
		printf("--------------");
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
	printf("\n \t User Login \n");
	
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
	char *password, *confirmPassword,*name, *age, *location;
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
	system("cls");
	textWebsiteName();
	menuBar(0,0,0,1,0,1,1,1);
	userChoice(4);
}

void settingsPage(char *email) {
	system("cls");
	textWebsiteName();
	menuBar(0,0,0,1,1,0,0,0);
	userSettingsInput();
}

void frndRqstPage(char *email) {
	system("cls");
	textWebsiteName();
	menuBar(0,0,0,1,1,0,0,0);
}

// MAIN -------------------------------------------------------------------------

int main()
{
    landingPage();
}