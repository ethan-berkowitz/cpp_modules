#pragma once

#include <string>
#include <map>
#include "ASpell.hpp"

class SpellBook {
	private:
		std::map<std::string, ASpell*> spellMap;
	public:
		SpellBook();
		~SpellBook();

		void learnSpell(ASpell* spell);
		void forgetSpell(const std::string &spellName);
		ASpell *createSpell(const std::string &spellName);
};