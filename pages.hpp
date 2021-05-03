#include <iostream>
using namespace std;
// #ifndef VALIDATIONS_HPP
// #define VALIDATIONS_HPP
#include "validations.hpp"
//----------------------------------- TEXTS ---------------------------------------
class Pages{
	public:
	void textWebsiteName() {
	cout << "Hello World!";
	cout<<"\n \t\t\t FakeBook";
	cout<<"\n \t\t\t----------\n\n";
	}

	void textDevelopers() {
		cout<<"\n Developers - Avinash, Chetali, Garima, Jeet, Utpal \n";
	}


 //--------------------------------- USER SWITCHING b/w PAGES---------------------------
	void userChoice(int curntPage) {
		int choice;
		cout<<"\n Enter your choice: ";
		cin >> choice;
	
		if(curntPage==1 && choice==1)
			loginPage();
		
		if(curntPage==1 && choice==2)
			signupPage();
		
		if(curntPage==1 && choice==3)
			exit(0);
	}
 //--------------------------- USER CHOOSING MENU Abruptly------------------------
	void checkForMenuOption(int curntPage, string option) {
		if(curntPage==2 && strcmp(option,"1")==0)
			exit(0);
		
		if(curntPage==2 && strcmp(option,"2")==0)
			landingPage();
	}

 //------------------------------ ALL MENU OPTIONS------------------------
	void menuBar(int login,int signup,int exit,int logout,int back,int editProfile,int chat,int fr) {
		int slno = 1, i;
		cout<<("\n");
		if(login==1) {
			cout<<(" %d.Login",slno);
			slno++;
		}
		if(signup==1) {
			cout<<(" \t %d.Signup",slno);
			slno++;
		}
		if(exit==1) {
			cout<<(" \t %d.Exit",slno);
			slno++;
		}
		if(logout==1) {
			cout<<(" \t %d.Logout",slno);
			slno++;
		}
		if(back==1) {
			cout<<(" \t %d.Back",slno);
			slno++;
		}
		if(editProfile==1) {
			cout<<(" \t %d.Edit Profile",slno);
			slno++;
		}
		if(chat==1) {
			cout<<(" \t %d.Chat",slno);
			slno++;
		}
		if(fr==1) {
			cout<<(" \t %d.Friend Request",slno);
			slno++;
		}
	
		cout<<("\n");
		for(i=1; i<=slno; i++)
		cout<<("--------------");
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
		userLoginInput();//
	}

 // TODO: navigate to landing page after account creation
	static void signupPage() {
		system("cls");
		textWebsiteName();
		menuBar(0,0,1,0,1,0,0,0);
		userSignupInput();//
	}

	void userHomePage(string email) {
		system("cls");
		textWebsiteName();
		menuBar(0,0,0,1,0,1,1,1);
		userChoice(4);
	}

	void settingsPage(string email) {
		system("cls");
		textWebsiteName();
		menuBar(0,0,0,1,1,0,0,0);
		userSettingsInput();//
	}

	void frndRqstPage(string email) {
		system("cls");
		textWebsiteName();
		menuBar(0,0,0,1,1,0,0,0);
	}
};
// #endif
