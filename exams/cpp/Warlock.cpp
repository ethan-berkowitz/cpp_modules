#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title) {
	this->name = name;
	this->title = title;
	std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
	std::cout << this->name << ": My job here is done!" << std::endl;
};

void Warlock::introduce() const {
	std::cout << this->name << ": I am " << this->name << ", " << this->title << "!\n";
}

std::string Warlock::getName() const{
	return this->name;
}

std::string Warlock::getTitle() const{
	return this->title;
}

void Warlock::setTitle(const std::string &str) {
	this->title = str;
}
