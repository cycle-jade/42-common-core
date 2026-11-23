#pragma once
#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm {
    public:
    PresidentialPardonForm(std::string const& target);
    PresidentialPardonForm(PresidentialPardonForm const& other);
    PresidentialPardonForm& operator=(PresidentialPardonForm const& other);
    ~PresidentialPardonForm();

    private:
    std::string _target;
    void executeAction() const;
};