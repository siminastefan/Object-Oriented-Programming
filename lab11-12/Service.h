#pragma once
#include "Repository.h"
#include "RepoAdoption.h"
#include "Comparator.h"
#include "Validator.h"
class Service
{
private:
	Repository* repo;
	Repository* adoption;
	DogValidator& valid;
	std::vector<Dog> sort(Comparator<Dog>* compare, std::vector<Dog> r);

public:
	//default constructor
	Service(Repository* r, Repository* adop, DogValidator& _valid) : repo{ r }, adoption{ adop }, valid{ _valid } {};

	Repository getRepo() const { return *repo; }
	Repository getRepoAdoption() const { return *adoption; }

	void sortServ();
	void shuffleServ();

	//function to get the size
	int get_size_serv();

	int get_adoption_size();

	//function to get an element from a given position
	Dog get_elem_serv(int i);

	Dog get_dog_adoption(int i);

	Dog search_dog(std::string name);

	//function to get all the elements
	//DynamicArray getAll_serv();

	//function to add an element
	void addServ(const std::string& breed, const std::string& name, int age, const std::string& source);

	void addAdoption(Dog d);

	void open();

	//function to remove an element
	void removeServ(const std::string& name);

	//function to update an element
	void updateServ(const std::string& breed, const std::string& name, int age, const std::string& source);

	void sortServ(const std::string& breed, int age);

	bool search_dogs(const std::string& breed, int age);

	std::vector<Dog> sort_by_name();

	std::vector<Dog> sort_by_breed();

	~Service();
};

