#include "Warlock.hpp"

const std::string& Warlock::getName() const{
	return this->name;
}
const std::string& Warlock::getTitle() const{
	return this->title;
}
void Warlock::setTitle (const std::string &title){
	this->title = title;
}
Warlock::Warlock(std::string name, std::string title){
	this->name = name;
	this->title = title;
	std::cout << name << ": This looks like another boring day." << std::endl;
}
Warlock::~Warlock(){
	std::cout << name << ": My job here is done!" << std::endl;
}
void Warlock::introduce() const{
	std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}

//SPELLS

void Warlock::learnSpell(ASpell *spell){
	spellBook.learnSpell(spell);
}

void Warlock::forgetSpell(std::string name){
	spellBook.forgetSpell(name);
}

void Warlock::launchSpell(std::string spellName, ATarget &target){
	if (spellBook.createSpell(spellName) != NULL)
		spellBook.createSpell(spellName)->launch(target);
}
