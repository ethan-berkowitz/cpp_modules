#pragma once

#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"
#include "SpellBook.hpp"

class Warlock {
	private:
		std::string name;
		std::string title;
		SpellBook spellBook;
	public:
		const std::string& getName() const;
		const std::string& getTitle() const;

		void setTitle(const std::string &title);

		Warlock(std::string name, std::string title);
		~Warlock();

		void introduce() const;

		void learnSpell(ASpell* spell);
		void forgetSpell(std::string spellName);
		void launchSpell(std::string spellName, ATarget& target);
};
