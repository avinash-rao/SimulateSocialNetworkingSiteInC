#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//----------------------------------- TEXTS ---------------------------------------

void textWebsiteName() {
	printf("\n \t\t\t FakeBook");
	printf("\n \t\t\t----------\n\n");
}

void textDevelopers() {
	printf("\n Developers - Avinash, Chetali, Garima, Jeet, Utpal \n");
}


//--------------------------------- USER SWITCHING b/w PAGES---------------------------
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
//--------------------------- USER CHOOSING MENU Abruptly------------------------
void checkForMenuOption(int curntPage, char *option[]) {
	if(curntPage==2 && strcmp(option,"1")==0)
		exit(0);
		
	if(curntPage==2 && strcmp(option,"2")==0)
		landingPage();
}

//------------------------------ ALL MENU OPTIONS------------------------
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


//---------------------------------- PAGES ----------------------------------------

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

// TODO: navigate to landing page after account creation
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
