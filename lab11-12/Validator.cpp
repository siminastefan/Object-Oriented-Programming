#include "Validator.h"
#include "Dog.h"

Validator::Validator(std::string _message)
{
	this->message = _message;
}
const char* Validator::what() const noexcept
{
	return this->message.c_str();

}

void DogValidator::validate(const Dog & s)
{
	std::string error;
	if (s.getAge() < 0 && s.getAge() > 30)
		error += "The age can not be smaller than 0 or greater then 30!\n";
	if (s.getBreed().size() < 1)
		error += "The breed must be non empty!\n";
	if (s.getName().size() < 1)
		error += "The name must be non empty!\n";
	if (error.size() > 0)
		throw Validator(error);
}

RepoError::RepoError(std::string _message)
{
	message = _message;
}

const char * RepoError::what() const noexcept
{
	return this->message.c_str();
}
