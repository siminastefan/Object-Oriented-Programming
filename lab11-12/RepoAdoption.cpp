#include "RepoAdoption.h"
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

RepoAdoption::RepoAdoption()
{
}

void RepoAdoption::add_Dog(Dog d)
{
	if (search_name_adoption(d.getName()) == false) {
		this->adoption.push_back(d);
		cout << "The given dog was added!" << endl;
		return;
	}
	cout << "The given dog is already in the list!" << endl;
}

Dog RepoAdoption::get_dog(int i)
{
	return this->adoption.at(i);
}

bool RepoAdoption::search_name_adoption(const std::string & name)
{
	for (size_t i = 0; i < this->adoption.size(); i++)
	{
		Dog d = this->adoption.at(i);
		if (d.getName() == name)
			return true;
	}
	return false;
}

int RepoAdoption::get_size()
{
	return this->adoption.size();
}

void RepoAdoption::open_browser()
{
}


RepoAdoption::~RepoAdoption()
{
}

RepoAdoptionCSV::RepoAdoptionCSV(std::string filename)
{
	this->filename = filename;
}

void RepoAdoptionCSV::WriteToCSV()
{
	ofstream f;
	f.open(this->filename);
	auto it = this->adoption.begin();
	for (; it < this->adoption.end() - 1; it++)
	{
		Dog d = *it;
		f << d.getBreed() << "," << d.getName() << "," << d.getAge() << "," << d.getSource() << endl;

	}
	Dog d = *it;
	f << d.getBreed() << "," << d.getName() << "," << d.getAge() << "," << d.getSource();
	f.close();
}

void RepoAdoptionCSV::add_Dog(Dog d)
{
	this->RepoAdoption::add_Dog(d);
	this->WriteToCSV();
}

void RepoAdoptionCSV::open_browser()
{
	ShellExecuteA(NULL, NULL, "excel.exe", "dogs.csv", NULL, SW_SHOWMAXIMIZED);
}

RepoAdoptionHTML::RepoAdoptionHTML(std::string filename)
{
	this->filename = filename;
}

void RepoAdoptionHTML::WriteToHTML()
{
	ofstream f;
	f.open(this->filename);
	f << "<!DOCTYPE html>" << endl;
	f << "<html>" << endl;
	f << "<head>" << endl;
	f << "<title>Adoption</title>" << endl;
	f << "</head>" << endl;
	f << "<body>" << endl;
	f << "<table border=\"1\">" << endl;
	f << "<tr>" << endl;
	f << "<th>Breed</th>" << endl;
	f << "<th>Name</th>" << endl;
	f << "<th>Age</th>" << endl;
	f << "<th>Photography Link</th>" << endl;
	f << "</tr>" << endl;
	auto it = this->adoption.begin();
	for (; it < this->adoption.end() - 1; it++)
	{
		f << "<tr>" << endl;
		f << "<td>";
		Dog d = *it;
		f << d.getBreed(); /*<< "," << d.getName() << "," << d.getAge() << "," << d.getSource() << endl;*/
		f << "</td>" << endl;

		f << "<td>";
		f << d.getName();
		f << "</td>" << endl;

		f << "<td>";
		f << d.getAge();
		f << "</td>" << endl;

		f << "<td><a target=\"_blank\" href=";
		f << d.getSource();
		f << ">See Dog</a></td>" << endl;
	}
	Dog d = *it;
	f << "<tr>" << endl;
	f << "<td>";
	f << d.getBreed(); /*<< "," << d.getName() << "," << d.getAge() << "," << d.getSource() << endl;*/
	f << "</td>" << endl;

	f << "<td>";
	f << d.getName();
	f << "</td>" << endl;

	f << "<td>";
	f << d.getAge();
	f << "</td>" << endl;

	f << "<td><a target=\"_blank\" href=";
	f << d.getSource();
	f << ">See Dog</a></td>" << endl;
	//f << d.getBreed() << "," << d.getName() << "," << d.getAge() << "," << d.getSource();
	f.close();
}

void RepoAdoptionHTML::add_Dog(Dog d)
{
	this->RepoAdoption::add_Dog(d);
	this->WriteToHTML();
}

void RepoAdoptionHTML::open_browser()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", "dogs.html", NULL, SW_SHOWMAXIMIZED);
}
