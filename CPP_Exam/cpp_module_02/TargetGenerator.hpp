#pragma once
#include <iostream>
#include <map>
#include "ATarget.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"
#include "BrickWall.hpp"

class TargetGenerator
{
public:
    TargetGenerator() {}
    virtual ~TargetGenerator() {}

    void learnTargetType(ATarget* obj);
    void forgetTargetType(const std::string& target_type);
    ATarget* createTarget(const std::string& target_type);

private:
    std::map<std::string, ATarget*> book;

    TargetGenerator(const TargetGenerator& obj);
    TargetGenerator& operator=(const TargetGenerator& obj);
};