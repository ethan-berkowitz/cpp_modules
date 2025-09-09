#pragma once

#include <string>
#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget {
	protected:
		std::string type;
	public:
		const std::string& getType() const;

		virtual ATarget* clone() const = 0;

		ATarget(std::string type);
		~ATarget();

		void getHitBySpell(const ASpell& spell) const;
};