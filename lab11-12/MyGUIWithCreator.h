#pragma once
#include "Service.h"
#include <QWidget>
#include "ui_MyGUIWithCreator.h"
#include "MyGUIByHand.h"
#include "MyModel.h"

class MyGUIWithCreator : public QWidget
{
	Q_OBJECT
private:
	Service &serv;
	MyModel* mRepo;
	MyModel* mAdopt;

public:
	MyGUIWithCreator(Service& serv, MyModel* m1, MyModel* m2, QWidget *parent = Q_NULLPTR);
	~MyGUIWithCreator();

private:
	Ui::MyGUIWithCreator ui;
	void populateDogs();
	void populateAdoption();
	void addToAdoption();
};
