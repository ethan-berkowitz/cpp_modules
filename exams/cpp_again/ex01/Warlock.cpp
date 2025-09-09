#include "Warlock.hpp"

const std::string& Warlock::getName() const{
	return this->name;
}
const std::string& Warlock::getTitle() const{
	return this->title;
}

void Warlock::setTitle(const std::string &title){
	this->title = title;
}

Warlock::Warlock(std::string name, std::string title){
	this->name = name;
	this->title = title;
	std::cout << this->name << ": This looks like another boring day." << std::endl;
}
Warlock::~Warlock(){
	std::cout << this->name << ": My job here is done!" << std::endl;
}

void Warlock::introduce() const{
	std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell* spell){
	this->spellMap[spell->getName()] = spell;
}
void Warlock::forgetSpell(std::string spellName){
	if (this->spellMap.find(spellName) != this->spellMap.end())
		this->spellMap.erase(spellName);
}
void Warlock::launchSpell(std::string spellName, ATarget& target){
	if (this->spellMap.find(spellName) != this->spellMap.end())
		target.getHitBySpell(*this->spellMap[spellName]);
}