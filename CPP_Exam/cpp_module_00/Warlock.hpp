#pragma once

#include <iostream>

class Warlock
{
public:
    Warlock(const std::string& name, const std::string& title);
    ~Warlock();

    void introduce() const;

    const std::string& getName() const { return name;}
    const std::string& getTitle() const { return title;}
    void setTitle(const std::string& title) { this->title = title; }

private:
    std::string name;
    std::string title;

    Warlock();
    Warlock(const Warlock& obj);
    Warlock& operator=(const Warlock& obj);
};