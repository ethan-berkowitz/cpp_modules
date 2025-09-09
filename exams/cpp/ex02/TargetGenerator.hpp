#include <iostream>
#include <string>
#include <map>
#include "ATarget.hpp"

class TargetGenerator {
	private:
		std::map<std::string,ATarget*> targetMap;
	public:
		TargetGenerator();
		~TargetGenerator();

		void learnTargetType(ATarget *target);

		void forgetTargetType(const std::string name);

		ATarget* createTarget(const std::string &targetName);
};
