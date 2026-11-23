#pragma once

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm {

public:
    ShrubberyCreationForm(std::string const& target);
    ShrubberyCreationForm(ShrubberyCreationForm const& other);
    ShrubberyCreationForm& operator=(ShrubberyCreationForm const& other);
    ~ShrubberyCreationForm();
private:
    void executeAction() const;
    std::string _target;

};