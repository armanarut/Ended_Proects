#include "TargetGenerator.hpp"

void TargetGenerator::learnTargetType(ATarget* obj)
{
    if (obj)
        book.insert(std::pair<std::string, ATarget*>(obj->getType(), obj->clone()));
}
void TargetGenerator::forgetTargetType(const std::string& target_type)
{
    std::map<std::string, ATarget*>::iterator it;
    it = book.find(target_type);
    if (it != book.end())
    {
        delete it->second;
        book.erase(target_type);
    }
}
ATarget* TargetGenerator::createTarget(const std::string& target_type)
{
    ATarget* spell = book[target_type];
    if (spell)
        return spell->clone();
    return NULL;
}