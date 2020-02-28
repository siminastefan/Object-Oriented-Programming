#include "UI.h"
#include <string>
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <exception>

using namespace std;

void UI::printModes()
{
	cout << "\t Modes available: \n";
	cout << "\t [0] Exit \n";
	cout << ("\t [1] Administrator mode \n");
	cout << ("\t [2] User mode \n");
}

void UI::printAdminMenu()
{
	cout << "\n \t Available commands: " << endl;
	cout << "\t [0] Exit " << endl;
	cout << "\t [1] Print the list of dogs " << endl;
	cout << "\t [2] Add a dog " << endl;
	cout << "\t [3] Remove a dog " << endl;
	cout << "\t [4] Update a dog " << endl;
}

void UI::printUserMenu()
{
	cout << "\n \t Available commands: " << endl;
	cout << "\t [0] Exit " << endl;
	cout << "\t [1] See the dogs in the database to adopt one " << endl;
	cout << "\t [2] See adoption list" << endl;
}

void UI::start()
{

	while (true)
	{
		UI::printModes();
		cout << "\n Please insert a command:";
		int  mode;
		cin >> mode;
		cin.ignore();
		if (mode == 1)
		{
			UI::startAdmin();
		}
		else
			if (mode == 2)
			{
				UI::startUser();
			}
			else
				if (mode == 0) { return; }
				else
				{
					cout << "Invalid command given!";
				}
	}
}

void UI::startAdmin()
{
	int cmd = -1;

	while (true) {
		UI::printAdminMenu();
		cout << "\n Please insert a command:";
		cin >> cmd;
		cin.ignore();
		try {
			if (cmd == 2) {
				UI::_ui_addDog();
			}
			else
				if (cmd == 0) {
					cout << "Back to main menu..." << endl;
					ofstream g("data.txt");
					for (size_t i = 0; i < this->serv.get_size_serv(); i++) {
						Dog d = this->serv.get_elem_serv(i);
						g << d.getBreed() << " " << d.getName() << " " << d.getAge() << " " << d.getSource() << endl; //". Link: "<<d.getSource()<<endl;
						//ShellExecuteA(NULL, NULL, "chrome.exe", d.getSource().c_str(), NULL, SW_SHOWMAXIMIZED);
					}

					return;
				}
				else
					if (cmd == 1)
						UI::_ui_printAll();
					else
						if (cmd == 3)
							UI::_ui_removeDog();
						else
							if (cmd == 4)
								UI::_ui_updateDog();
		}
		catch (Validator e) {
			cout << e.what();
		}
		catch (RepoError e)
		{
			cout << e.what();
		}
	}
}

void UI::startUser()
{
	int cmd = -1;
	while (true) {
		UI::printUserMenu();
		cout << "\n Please insert a command:";
		cin >> cmd;
		cin.ignore();
		if (cmd == 0) {
			cout << "Back to main menu..." << endl;
			return;
		}
		else
			if (cmd == 1)
				UI::_ui_seeDogs();
			else
				if (cmd == 2)
					UI::_ui_printAdoption();
	}
}

void UI::_ui_addDog()
{
	std::string breed;
	cout << "Please insert the breed: ";
	getline(cin, breed);
	std::string name;
	cout << "Please insert the name: ";
	getline(cin, name);
	int age;
	cout << "Please insert the age: ";
	cin >> age;
	cin.ignore();
	std::string source;
	cout << "Please insert the source of the photography: ";
	getline(cin, source);
	//this->serv.addServ(breed, name, age, source);
	try {
		this->serv.addServ(breed, name, age, source);
	}
	catch (std::exception e)
	{
		cout << e.what();
	}
}

void UI::_ui_printAll()
{
	if (this->serv.get_size_serv() == 0) {
		cout << "The list of dogs is empty!" << endl;
		return;
	}
	for (size_t i = 0; i < this->serv.get_size_serv(); i++) {
		Dog d = this->serv.get_elem_serv(i);
		cout << d.getName() << " is a " << d.getBreed() << ", age " << d.getAge() << endl; //". Link: "<<d.getSource()<<endl;
		ShellExecuteA(NULL, NULL, "chrome.exe", d.getSource().c_str(), NULL, SW_SHOWMAXIMIZED);
	}
}

void UI::_ui_printAdoption()
{
	if (this->serv.get_adoption_size() == 0) {
		cout << "The adoption list is empty!" << endl;
		return;
	}
	//for (size_t i = 0; i < this->serv.get_adoption_size(); i++) {
	//	Dog d = this->serv.get_dog_adoption(i);
	//	cout << d.getName() << " is a " << d.getBreed() << ", age " << d.getAge() << endl; //". Link: "<<d.getSource()<<endl;
	//	ShellExecuteA(NULL, NULL, "chrome.exe", d.getSource().c_str(), NULL, SW_SHOWMAXIMIZED);
	//}
	this->serv.open();
}

void UI::_ui_seeDogs()
{
	int i = 0, n = 0;
	cout << "Press [1] to see all the dogs and [2] to see the dogs of a given breed: ";
	cin >> n;
	cin.ignore();
	if (n == 1) {
		while (1) {
			Dog d = this->serv.get_elem_serv(i);
			cout << d.getName() << " is a " << d.getBreed() << ", age " << d.getAge() << endl;
			ShellExecuteA(NULL, NULL, "chrome.exe", d.getSource().c_str(), NULL, SW_SHOWMAXIMIZED);
			cout << "Press [1] to Continue or [2] to adopt or [3] to return to exit: ";
			int cmd = -1;
			cin >> cmd;
			if (cmd == 1) { i++; }
			else
				if (cmd == 2) {
					this->serv.addAdoption(d);
					i++;
				}
				else
					if (cmd == 3) { return; }
			if (i == this->serv.get_size_serv()) {
				i = 0;
			}
		}
	}
	else
		if (n == 2) {
			cout << "Please insert the breed: ";
			std::string breed;
			getline(cin, breed);
			cout << "Please insert the age: ";
			int age;
			cin >> age;
			cin.ignore();
			if (this->serv.search_dogs(breed, age) == false) {
				cout << "There are no such dogs in the list!" << endl;
				return;
			}
			while (1) {
				Dog d = this->serv.get_elem_serv(i);
				if (d.getBreed() == breed && d.getAge() <= age) {
					cout << d.getName() << " is a " << d.getBreed() << ", age " << d.getAge() << endl;
					ShellExecuteA(NULL, NULL, "chrome.exe", d.getSource().c_str(), NULL, SW_SHOWMAXIMIZED);
					cout << "Press [1] to Continue or [2] to adopt or [3] to return to exit: ";
					int cmd = -1;
					cin >> cmd;
					if (cmd == 2) {
						this->serv.addAdoption(d);
					}
					else
						if (cmd == 3) { return; }
				}
				i++;
				if (i == this->serv.get_size_serv()) {
					i = 0;
				}
			}
		}
}

void UI::_ui_removeDog()
{
	std::string name;
	cout << "Please insert the name: ";
	getline(cin, name);
	this->serv.removeServ(name);
}

void UI::_ui_updateDog()
{
	std::string name;
	cout << "Please insert the name: ";
	getline(cin, name);
	std::string breed;
	cout << "Please insert the breed: ";
	getline(cin, breed);
	int age;
	cout << "Please insert the age: ";
	cin >> age;
	cin.ignore();
	std::string source;
	cout << "Please insert the source of the photography: ";
	getline(cin, source);
	this->serv.updateServ(breed, name, age, source);
}

void UI::_ui_sortDogs()
{
	cout << "Please insert the breed: ";
	std::string breed;
	getline(cin, breed);

	cout << "Please insert the age";
	int age;
	cin >> age;
	cin.ignore();

	this->serv.sortServ(breed, age);

}

UI::~UI()
{
}
