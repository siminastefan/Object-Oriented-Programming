#include "Repository.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

void Repository::sortRepo()
{
	sort(this->dogs.begin(), this->dogs.end(),
		[](const Dog &d1, const Dog &d2) -> bool
	{
		return d1.getName() < d2.getName();
	}
		);
}

void Repository::shuffleRepo()
{
	random_shuffle(this->dogs.begin(), this->dogs.end());
}

int Repository::get_size()
{
	return dogs.size();
}

std::vector<Dog> Repository::get_all()
{
	return this->dogs;
}

Dog Repository::get_elem(int i)
{
	return this->dogs.at(i);
}

Dog Repository::search(const std::string & name)
{
	/*for (size_t i = 0; i < this->get_size(); i++)
	{
		Dog d = this->get_elem(i);
		if (d.getName() == name)
			return d;

	}*/
	auto it = std::find_if(this->dogs.begin(), this->dogs.end(), [&name](const Dog& d) {return d.getName() == name;});
	if (it != this->dogs.end()) {
		auto index = std::distance(this->dogs.begin(), it);
		return this->dogs.at(index);
	}
}

void Repository::addDog(Dog d)
{
	/*Dog new_dog = this->search(d.getName());
	if (new_dog.getName() != "") {
		this->dogs.add(d);
		cout << "The dog was added!" << endl;
		cout << "The given dog is already in the list!" << endl;
	}*/
	/*for (size_t i = 0; i < this->dogs.getSize(); i++)
	{
		Dog dog = this->search(d.getName());
		if (dog.getName() == d.getName()) {
			cout << "The given dog is already in the list!" << endl;
			return;
		}

	}*/
	if (search_name(d.getName()) == false) {
		this->dogs.push_back(d);
		cout << "The given dog was added!" << endl;
		return;
	}
	else {
		throw RepoError("The given dog is already in the list!\n");
	}
}

void Repository::removeDog(Dog d)
{
	if (search_name(d.getName()) == true) {
		this->dogs.erase(std::remove(this->dogs.begin(), this->dogs.end(), d), this->dogs.end());
		cout << "The dog was removed!" << endl;
		return;
	}
	else {
		throw RepoError("The given dog is not in the list!\n");
	}
}

void Repository::updateDog(Dog d)
{
	//if ((search_name(d.getName()) == true)) {
	//	for (size_t i = 0; i < this->dogs.size(); i++)
	//	{
	//		Dog dd = this->dogs.at(i);
	//		if (d.getName() == dd.getName()) {
	//			//this->dogs.set_elem(i, d);
	//			this->dogs.erase(std::remove(this->dogs.begin(), this->dogs.end(), d), this->dogs.end());
	//			this->dogs.push_back(dd);
	//			cout << "The dog was updated!" << endl;
	//			return;
	//		}
	//	}
	//}
	//else {
	//	throw RepoError("The given dog is not in the list!\n");
	//}
	auto dd = find_if(this->dogs.begin(), this->dogs.end(), [&](Dog d1) { return d1.getName() == d.getName(); });
	if (dd == this->dogs.end())
	{
		throw RepoError("The dog wasn't in the list!\n");
	}
	else
	{
		*dd = d;
		return;
	}
}

bool Repository::search_name(const std::string & name)
{
	/*for (size_t i = 0; i < this->dogs.getSize(); i++)
	{
		Dog d = this->dogs.get_elem(i);
		if (d.getName() == name)
			return true;
	}
	return false;*/
	auto it = find_if(this->dogs.begin(), this->dogs.end(), [&name](const Dog& d) {return d.getName() == name;});
	if (it != this->dogs.end()) {
		return true;
	}
	return false;
}

bool Repository::search_breed(const std::string & breed, Dog d)
{
	if (d.getBreed() == breed) {
		return true;
	}
	return false;
}

bool Repository::search_breed_age(const std::string & breed, int age)
{
	/*for (size_t i = 0; i < this->dogs.getSize(); i++)
	{
		Dog d = this->dogs.get_elem(i);
		if (d.getBreed() == breed && d.getAge() <= age)
			return true;
	}
	return false;*/
	auto it = find_if(this->dogs.begin(), this->dogs.end(), [&breed, age](const Dog& d) {return d.getBreed() == breed && d.getAge() == age;});
	if (it != this->dogs.end()) {
		return true;
	}
	return false;
}


Repository::~Repository()
{
}

FileRepository::FileRepository(std::string file)
{
	this->file = file;
	this->readAllFromFile(this->file);

}

bool FileRepository::is_empty(std::ifstream& pFile)
{
	return pFile.peek() == std::ifstream::traits_type::eof();
}

void FileRepository::readAllFromFile(std::string file)
{
	ifstream f;
	f.open(file);
	std::string breed;
	std::string name;
	int age;
	std::string photo;
	std::string line;
	while (!is_empty(f))
	{
		Dog d{};
		f >> d;
		this->dogs.push_back(d);
	}
	f.close();
}

void FileRepository::writeAllToFile(std::string file)
{
	ofstream f;
	f.open(file);
	auto it = this->dogs.begin();
	for (; it < this->dogs.end() - 1; it++)
	{
		Dog d = *it;
		f << d << "\n";

	}
	Dog d = *it;
	f << d;
	f.close();
}

void FileRepository::addDog(Dog d)
{
	this->Repository::addDog(d);
	this->writeAllToFile(this->file);
}

void FileRepository::removeDog(Dog d)
{
	this->Repository::removeDog(d);
	this->writeAllToFile(this->file);
}

void FileRepository::updateDog(Dog d)
{
	this->Repository::updateDog(d);
	this->writeAllToFile(this->file);
}
