#pragma once

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm {
    public:
    RobotomyRequestForm(std::string const& target);
    RobotomyRequestForm(RobotomyRequestForm const& other);
    RobotomyRequestForm& operator=(RobotomyRequestForm const& other);
    ~RobotomyRequestForm();

    private:
    std::string _target;
    void executeAction() const;

};