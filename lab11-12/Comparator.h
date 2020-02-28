#pragma once
#include "Dog.h"

template <typename T>
class Comparator
{
public:
	virtual bool compare(T& e1, T& e2) = 0;
	//Comparator();
	virtual ~Comparator() {};
};

class CompareByName : public Comparator<Dog>
{
	bool compare(Dog& e1, Dog& e2) override { return e1.getName() < e2.getName(); }
};

class CompareByBreed : public Comparator<Dog>
{
	bool compare(Dog& e1, Dog& e2) override { return e1.getBreed() < e2.getBreed(); }
};
