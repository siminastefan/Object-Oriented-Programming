#include "MyGUIByHand.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QMessageBox>



MyGUIByHand::MyGUIByHand(const Service & s): serv{s}
{
	this->initGUI();
	this->populateList();

	QObject::connect(this->sortedButton, &QRadioButton::clicked, this, &MyGUIByHand::sortedHandler);
	QObject::connect(this->shuffledButton, &QRadioButton::clicked, this, &MyGUIByHand::shuffleHandler);
	QObject::connect(this->addButton, &QPushButton::clicked, this, &MyGUIByHand::addHandler);
	QObject::connect(this->removeButton, &QPushButton::clicked, this, &MyGUIByHand::removeHandler);
	QObject::connect(this->updateButton, &QPushButton::clicked, this, &MyGUIByHand::updateHandler);
}

MyGUIByHand::~MyGUIByHand()
{
}

void MyGUIByHand::initGUI()
{
	QHBoxLayout* mainLayout = new QHBoxLayout{ this };

	this->dogsList = new QListWidget{};

	QHBoxLayout* radiobuttonsLayout = new QHBoxLayout{};
	this->sortedButton = new QRadioButton{ "Sorted" };
	this->shuffledButton = new QRadioButton{ "Shuffled" };
	radiobuttonsLayout->addWidget(this->sortedButton);
	radiobuttonsLayout->addWidget(this->shuffledButton);
	radiobuttonsLayout->addWidget(this->dogsList);
	mainLayout->addLayout(radiobuttonsLayout);


	//mainLayout->addWidget(this->dogsList);

	QVBoxLayout* rightLayout = new QVBoxLayout{};

	QFormLayout* dataLayout = new QFormLayout{};
	this->breedEdit = new QLineEdit{};
	this->nameEdit = new QLineEdit{};
	this->ageEdit = new QLineEdit{};
	this->sourceEdit = new QLineEdit{};
	dataLayout->addRow("Breed", this->breedEdit);
	dataLayout->addRow("Name", this->nameEdit);
	dataLayout->addRow("Age", this->ageEdit);
	dataLayout->addRow("Source", this->sourceEdit);

	rightLayout->addLayout(dataLayout);
	mainLayout->addLayout(rightLayout);

	QHBoxLayout* buttonsLayout = new QHBoxLayout{};
	this->addButton = new QPushButton{ "Add" };
	this->removeButton = new QPushButton{ "Remove" };
	this->updateButton = new QPushButton{ "Update" };

	buttonsLayout->addWidget(this->addButton);
	buttonsLayout->addWidget(this->removeButton);
	buttonsLayout->addWidget(this->updateButton);

	rightLayout->addLayout(buttonsLayout);
}

void MyGUIByHand::populateList()
{
	this->dogsList->clear();

	for (auto& s : this->serv.getRepo().getDogs())
	{
		std::string age = std::to_string(s.getAge());
		this->dogsList->addItem(QString::fromStdString(s.getBreed() + ", " + s.getName() + ", " + age /*+ " - " + s.getSource()*/));
	}
}

void MyGUIByHand::sortedHandler()
{
	this->serv.sortServ();
	this->populateList();
}

void MyGUIByHand::shuffleHandler()
{
	this->serv.shuffleServ();
	this->populateList();
}

void MyGUIByHand::addHandler()
{
	std::string name;
	std::string breed;
	std::string source;
	int age;
	name = this->nameEdit->text().toStdString();
	breed = this->breedEdit->text().toStdString();
	source = this->sourceEdit->text().toStdString();
	age = stoi(this->ageEdit->text().toStdString());
	try
	{
		this->serv.addServ(breed, name, age, source);
	}
	catch (std::exception& e)
	{
		QMessageBox* addDog = new QMessageBox();
		addDog->setText(e.what());
		addDog->exec();
	}
	this->populateList();
}

void MyGUIByHand::removeHandler()
{
	std::string name;
	name = this->nameEdit->text().toStdString();
	try
	{
		this->serv.removeServ(name);
	}
	catch (std::exception& e)
	{
		QMessageBox* removeDog = new QMessageBox();
		removeDog->setText(e.what());
		removeDog->exec();
	}
	this->populateList();
}

void MyGUIByHand::updateHandler()
{
	std::string name;
	std::string breed;
	std::string source;
	int age;
	name = this->nameEdit->text().toStdString();
	breed = this->breedEdit->text().toStdString();
	source = this->sourceEdit->text().toStdString();
	age = stoi(this->ageEdit->text().toStdString());
	try
	{
		this->serv.updateServ(breed, name, age, source);
	}
	catch (std::exception& e)
	{
		QMessageBox* updateDog = new QMessageBox();
		updateDog->setText(e.what());
		updateDog->exec();
	}
	this->populateList();
}
