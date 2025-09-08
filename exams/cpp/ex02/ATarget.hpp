#pragma once

#include <iostream>
#include <string>
#include "ASpell.hpp"

class ASpell;

class ATarget {
	protected:
		std::string type;
	public:
		const std::string& getType() const;
		virtual ATarget* clone() const = 0;

		ATarget();
		ATarget(std::string type);

		void getHitBySpell(const ASpell &spell) const;
};
