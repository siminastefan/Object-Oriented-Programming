#include "MyGUIWithCreator.h"

//MyGUIWithCreator::MyGUIWithCreator(Service& s, QWidget *parent)
//	: QWidget(parent), serv{s}
//{
//	ui.setupUi(this);
//	this->ui.dogList->setSelectionMode(QAbstractItemView::SingleSelection);
//	this->populateDogs();
//	this->populateAdoption();
//	QObject::connect(this->ui.addAdoptionButton, &QPushButton::clicked, this, &MyGUIWithCreator::addToAdoption);
//}

MyGUIWithCreator::MyGUIWithCreator(Service & serv, MyModel * m1, MyModel * m2, QWidget * parent) : serv{ serv }, mRepo{m1},mAdopt{m2}, QWidget{parent}
{
	ui.setupUi(this);
	this->ui.dogList->setModel(mRepo);
	this->ui.adoptionList->setModel(mAdopt);
	this->ui.dogList->setSelectionMode(QAbstractItemView::SingleSelection);
	QObject::connect(this->ui.addAdoptionButton, &QPushButton::clicked, this, &MyGUIWithCreator::addToAdoption);

}

MyGUIWithCreator::~MyGUIWithCreator()
{
}

void MyGUIWithCreator::populateDogs()
{
	//this->ui.dogList->clear();

	//for (auto& s : this->serv.getRepo().getDogs())
	//{
	//	std::string age = std::to_string(s.getAge());
	//	this->ui.dogList->addItem(QString::fromStdString(s.getBreed() + ", " + s.getName() + ", " + age /*+ " - " + s.getSource()*/));
	//}
}

void MyGUIWithCreator::populateAdoption()
{
	//this->ui.adoptionList->clear();

	//for (auto& s : this->serv.getRepoAdoption().getDogsAdoption())
	//{
	//	std::string age = std::to_string(s.getAge());
	//	this->ui.adoptionList->addItem(QString::fromStdString(s.getBreed() + ", " + s.getName() + ", " + age /*+ " - " + s.getSource()*/));
	//}
}

void MyGUIWithCreator::addToAdoption()
{
	/*int row = this->ui.dogList->currentRow();
	QListWidgetItem *t = this->ui.dogList->takeItem(row);
	this->ui.adoptionList->addItem(t);
	std::string info;
	info = ((*t).text()).toStdString();
	std::string name;
	std::size_t found = info.find_first_of(",");
	std::size_t found2 = info.find_first_of(",", found + 1);
	name.assign(info, found + 2, found2 - found - 2);
	Dog d = this->serv.search_dog(name);
	this->serv.addAdoption(d);*/

	//this->ui.dogList->currentIndex();
	QModelIndex index = this->ui.dogList->currentIndex();
	Dog d = this->mRepo->adopt(index);
	this->mRepo->removeRow(index.row());
	this->mAdopt->addto(d);
	this->mAdopt->insertRow(this->serv.get_size_serv());
}
