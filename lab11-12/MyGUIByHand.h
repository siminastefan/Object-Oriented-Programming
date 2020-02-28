#pragma once
#include "Service.h"
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qradiobutton.h>
#include <qlistwidget.h>

class MyGUIByHand :
	public QWidget
{
private:
	Service serv;

	QLineEdit* breedEdit, *nameEdit, *ageEdit, *sourceEdit;
	QPushButton* addButton, *removeButton, *updateButton;
	QRadioButton *sortedButton, *shuffledButton;
	QListWidget* dogsList;
public:
	MyGUIByHand(const Service& s);
	~MyGUIByHand();
private:
	void initGUI();
	void populateList();

	void sortedHandler();
	void shuffleHandler();
	void addHandler();
	void removeHandler();
	void updateHandler();
};

