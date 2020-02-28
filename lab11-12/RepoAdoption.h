#pragma once
#include "Dog.h"
#include <vector>
#include <utility>
#include <iostream>

class RepoAdoption
{
protected:
	//DynamicArray<Dog> adoption;
	std::vector<Dog> adoption;

public:
	RepoAdoption();

	virtual void add_Dog(Dog d);

	Dog get_dog(int i);
	std::vector<Dog> getDogsAdoption() const { return adoption; }

	bool search_name_adoption(const std::string & name);

	int get_size();

	virtual void open_browser();

	~RepoAdoption();
};

class RepoAdoptionCSV : public RepoAdoption
{
private:
	std::string filename;

public:
	RepoAdoptionCSV(std::string filename);
	void WriteToCSV();
	void add_Dog(Dog d) override;
	void open_browser() override;
};

class RepoAdoptionHTML : public RepoAdoption
{
private:
	std::string filename;

public:
	RepoAdoptionHTML(std::string filename);
	void WriteToHTML();
	void add_Dog(Dog d) override;
	void open_browser() override;
};
