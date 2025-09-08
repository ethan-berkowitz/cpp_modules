#pragma once

#include <iostream>
#include <string>
#include "ATarget.hpp"

class ATarget;

class ASpell {
	protected:
		std::string name;
		std::string effects;
	public:
		std::string getName() const;
		std::string getEffects() const;

		ASpell();
		ASpell(std::string name, std::string effects);
		~ASpell();

		virtual ASpell* clone() const = 0;

		void launch(const ATarget &target);
};
