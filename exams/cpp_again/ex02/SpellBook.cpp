#include "SpellBook.hpp"

void SpellBook::learnSpell(ASpell* spell){
	this->spellMap[spell->getName()] = spell;
}
void SpellBook::forgetSpell(const std::string &spellName){
	if (this->spellMap.find(spellName) != this->spellMap.end())
		this->spellMap.erase(spellName);
}
ASpell* SpellBook::createSpell(const std::string &spellName){
	if (this->spellMap.find(spellName) != this->spellMap.end())
		return this->spellMap[spellName]->clone();
}
