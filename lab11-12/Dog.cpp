#include "Dog.h"
#include <Windows.h>
#include <shellapi.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//Dog::Dog() : breed(""), name(""), age(0), source("") {}

Dog::Dog()
{
	this->breed = "";
	this->name = "";
	this->age = 0;
	this->source = "";
}

Dog::Dog(std::string breed, std::string name, int age, std::string source)
{
	this->breed = breed;
	this->name = name;
	this->age = age;
	this->source = source;
}

Dog::~Dog()
{
}

bool Dog::operator==(const Dog & d)
{
	return this->age == d.getAge() && this->breed == d.getBreed() && this->name == d.getName() && this->source == d.getSource();
}

//Dog(const std::string & breed, const std::string& name, const int& age, const std::string& source) {
//
//}
std::ofstream& operator<<(std::ofstream& f, const Dog& dog)
{
	f << dog.getBreed() << " " << dog.getName() << " " << dog.getAge() << " " << dog.getSource();
	return f;
}

std::ifstream & operator>>(std::ifstream & f, Dog & dog)
{
	std::string breed;
	std::string name;
	int age;
	std::string source;
	std::string line;
	std::getline(f, breed, ' ');
	std::getline(f, name, ' ');
	f >> age;
	std::getline(f, source, '\n');
	//dog.setBreed(breed);
	dog.breed = breed;
	//dog.setAge(age);
	dog.age = age;
	//dog.setName(name);
	dog.name = name;
	//dog.setPhoto(photo);
	dog.source = source;
	return f;
}
