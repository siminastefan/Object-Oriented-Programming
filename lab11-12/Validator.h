#pragma once
#include <exception>
#include <string>
#include "Dog.h"

class Validator : public std::exception
{
private:
	std::string message;
public:
	Validator(std::string _message);
	const char* what() const noexcept override;
};

class DogValidator
{
public:
	static void validate(const Dog& s);
};

class RepoError : public std::exception
{
private:
	std::string message;
public:
	RepoError(std::string _message);
	const char* what() const noexcept override;
};
