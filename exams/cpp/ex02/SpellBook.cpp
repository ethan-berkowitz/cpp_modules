#include "SpellBook.hpp"

SpellBook::SpellBook(){}
SpellBook::~SpellBook(){}

void SpellBook::learnSpell(ASpell *spell){
	this->spellMap[spell->getName()] = spell;
}

void SpellBook::forgetSpell(const std::string name){
	this->spellMap.erase(name);
}

ASpell* SpellBook::createSpell(const std::string &spellName){
	if (this->spellMap.find(spellName) != this->spellMap.end()) {
		return this->spellMap[spellName];
	}
	return NULL;
}
