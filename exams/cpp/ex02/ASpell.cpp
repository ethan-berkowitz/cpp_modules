#include "ASpell.hpp"

std::string ASpell::getName() const{
	return this->name;
}
std::string ASpell::getEffects() const{
	return this->effects;
}

ASpell::ASpell(std::string name, std::string effects){
	this->name = name;
	this->effects = effects;
}

ASpell::~ASpell(){}

void ASpell::launch(const ATarget &target){
	target.getHitBySpell(*this);
}

ASpell::ASpell(){}
