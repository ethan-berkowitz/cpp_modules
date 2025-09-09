#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(){}
TargetGenerator::~TargetGenerator(){}

void TargetGenerator::learnTargetType(ATarget *target){
	this->targetMap[target->getType()] = target;
}

void TargetGenerator::forgetTargetType(const std::string name){
	this->targetMap.erase(name);
}

ATarget* TargetGenerator::createTarget(const std::string &targetName){
	if (this->targetMap.find(targetName) != this->targetMap.end()) {
		return this->targetMap[targetName];
	}
	return NULL;
}
