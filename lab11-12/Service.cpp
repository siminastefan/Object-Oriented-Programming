#include "Service.h"
#include<iostream>
#include <Windows.h>
#include <string>

using namespace std;

std::vector<Dog> Service::sort(Comparator<Dog>* compare, std::vector<Dog> r)
{
	for (size_t i = 0; i < this->repo->get_size() - 1; i++)
	{
		for (size_t j = i + 1; j < this->repo->get_size(); j++)
		{
			if ((compare->compare(r[i], r[j]))==false) {
				Dog aux;
				aux = r[i];
				r[i] = r[j];
				r[j] = aux;
			}
		}
	}
	return r;
}

void Service::sortServ()
{
	this->repo->sortRepo();
}

void Service::shuffleServ()
{
	this->repo->shuffleRepo();
}

int Service::get_size_serv()
{
	return this->repo->get_size();
}

int Service::get_adoption_size()
{
	return this->adoption->get_size();
}

Dog Service::get_elem_serv(int i)
{
	return this->repo->get_elem(i);
}

Dog Service::get_dog_adoption(int i)
{
	return this->adoption->get_elem(i);
}

Dog Service::search_dog(std::string name)
{
	return this->repo->search(name);
}

//DynamicArray Service::getAll_serv()
//{
//	return this->repo.getAll();
//}

void Service::addServ(const std::string & breed, const std::string & name, int age, const std::string & source)
{
	Dog d{ breed, name, age, source };
	this->valid.validate(d);
	this->repo->addDog(d);
}

void Service::addAdoption(Dog d)
{
	this->adoption->addDog(d);
	//this->RepoAdoptionCSV::add_Dog(d);
}

void Service::open()
{
	//this->adoption.open_browser();
}

void Service::removeServ(const std::string & name)
{
	if (this->repo->search_name(name) == true) {
		Dog d = this->repo->search(name);
		this->repo->removeDog(d);
		return;
	}
	cout << "The given dog doesn't exist!" << endl;
}

void Service::updateServ(const std::string & breed, const std::string & name, int age, const std::string & source)
{
	Dog d{ breed, name, age, source };
	this->repo->updateDog(d);

}

void Service::sortServ(const std::string & breed, int age)
{
	Dog list[100];
	int j = 0;
	if (breed == "") {
		for (size_t i = 0; i < this->repo->get_size(); i++)
		{
			Dog d = this->repo->get_elem(i);
			if (d.getAge() <= age) {
				list[j] = d;
				j++;
			}
		}
	}
	else
	{
		for (size_t i = 0; i < this->repo->get_size(); i++)
		{
			Dog d = this->repo->get_elem(i);
			if (this->repo->search_breed(breed, d) == true && d.getAge() <= age) {
				list[j] = d;
				j++;
			}
		}
	}
	if (j == 0) {
		cout << "There are no dogs of this breed!" << endl;
		return;
	}
	for (size_t i = 0; i < j; i++)
	{
		Dog d = list[i];
		cout << d.getName() << " is a " << d.getBreed() << ", age " << d.getAge() << endl; //". Link: "<<d.getSource()<<endl;
		ShellExecuteA(NULL, NULL, "chrome.exe", d.getSource().c_str(), NULL, SW_SHOWMAXIMIZED);
	}
}

bool Service::search_dogs(const std::string & breed, int age)
{
	if (this->repo->search_breed_age(breed, age) == true)
		return true;
	return false;
}

std::vector<Dog> Service::sort_by_name()
{
	CompareByName* com_by_name = new CompareByName;
	std::vector<Dog> sorted_dogs = this->sort(com_by_name, this->repo->get_all());
	for (size_t i = 0; i < sorted_dogs.size(); i++)
	{
		Dog d = sorted_dogs.at(i);
		cout << d.getName() << " is a " << d.getBreed() << ", age " << d.getAge() << endl; //". Link: "<<d.getSource()<<endl;
		//ShellExecuteA(NULL, NULL, "chrome.exe", d.getSource().c_str(), NULL, SW_SHOWMAXIMIZED);
	}
	delete com_by_name;
	return sorted_dogs;
}

std::vector<Dog> Service::sort_by_breed()
{
	CompareByBreed* com_by_breed = new CompareByBreed;
	std::vector<Dog> sorted_dogs = this->sort(com_by_breed, this->repo->get_all());
	for (size_t i = 0; i < sorted_dogs.size(); i++)
	{
		Dog d = sorted_dogs.at(i);
		cout << d.getName() << " is a " << d.getBreed() << ", age " << d.getAge() << endl; //". Link: "<<d.getSource()<<endl;
		//ShellExecuteA(NULL, NULL, "chrome.exe", d.getSource().c_str(), NULL, SW_SHOWMAXIMIZED);
	}
	delete com_by_breed;
	return sorted_dogs;
}

Service::~Service()
{
}
