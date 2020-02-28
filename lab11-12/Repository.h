#pragma once
#include "Comparator.h"
#include "Dog.h"
#include "Validator.h"
#include <vector>
#include <utility>
#include <iostream>

class Repository {
protected:
	//DynamicArray<Dog> dogs;
	std::vector<Dog> dogs;

public:
	//default constructor
	Repository() {};

	//bool sortByName(const Person &lhs, const Person &rhs) { return lhs.name < rhs.name; }
	bool SortByName(const Dog &e1, const Dog &e2) {
		return true;
	} //e1.getName() < e2.getName(); }

	void sortRepo();
	void shuffleRepo();

	//function to get the size
	int get_size();

	std::vector<Dog> get_all();

	//function to get an element from the given position
	Dog get_elem(int i);

	//function to get the elements
	//DynamicArray<Dog> getAll() const{ return dogs; }

	//function to search for an element by a given name
	Dog search(const std::string& name);

	//function to add an element
	virtual void addDog(Dog d);

	//function to remove an element
	virtual void removeDog(Dog d);

	//function to update an element
	virtual void updateDog(Dog d);

	bool search_name(const std::string& name);

	bool search_breed(const std::string& breed, Dog d);

	bool search_breed_age(const std::string& breed, int age);

	std::vector<Dog> getDogs() const { return dogs; }

	//bool operator==(const Dog& d1, const Dog& d2);
	//destructor
	~Repository();
};

class FileRepository : public Repository
{
private:
	std::string file;
public:
	FileRepository(std::string file);
	bool is_empty(std::ifstream& pFile);
	void readAllFromFile(std::string file);
	void writeAllToFile(std::string file);

	void addDog(Dog d) override;
	void removeDog(Dog d) override;
	void updateDog(Dog d) override;
};