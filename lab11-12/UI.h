#pragma once
#include "Service.h"
#include "Validator.h"

class UI
{
private:
	Service serv;

public:
	UI(const Service& s) : serv(s) {}

	void printModes();

	void printAdminMenu();

	void printUserMenu();

	void start();

	void startAdmin();

	void startUser();

	void _ui_addDog();

	void _ui_printAll();

	void _ui_printAdoption();

	void _ui_seeDogs();

	void _ui_removeDog();

	void _ui_updateDog();

	void _ui_sortDogs();

	~UI();
};

