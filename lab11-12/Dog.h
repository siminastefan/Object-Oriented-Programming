#pragma once

#ifndef DOG_H
#define DOG_H

#include <stdexcept>
#include <iostream>

class Dog
{
private:
	std::string breed;
	std::string name;
	int age;
	std::string source;

public:
	//default constructor for a dog
	Dog();

	//constructor with parameters
	Dog(std::string breed, std::string name, int age, std::string source);

	//destructor
	~Dog();


	//Dog(const std::string& breed, const std::string& name, const int& age, const std::string& source);

	//function to get breed
	std::string getBreed() const { return breed; }

	//function to get name
	std::string getName() const { return name; }

	//function to get age
	int getAge() const { return age; }

	//function to get source
	std::string getSource()const { return source; }

	bool operator==(const Dog& d);

	/*void setBreed(const std::string b) const { this->breed=b; }
	void setAge() const { return age; }
	void setSource()const { return source; }*/
	friend std::ofstream& operator <<(std::ofstream& f, const Dog& dog);
	friend std::ifstream& operator >>(std::ifstream& f, Dog& dog);


	//default destructor for a dog
};
#endif