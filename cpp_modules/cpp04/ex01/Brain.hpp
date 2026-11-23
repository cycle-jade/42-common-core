#pragma once
#include <string>
#include <iostream>

class Brain
{
    protected:
        std::string ideas[100];
public:
    Brain();
    Brain(const Brain& other);
    Brain& operator=(const Brain& other);
    ~Brain();
    std::string getIdea(int index) const;
    void setIdea(int index, const std::string& idea);
};