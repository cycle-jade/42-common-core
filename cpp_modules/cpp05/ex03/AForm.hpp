#pragma once

#include <iostream>
#include <stdexcept>

class Bureaucrat;

class AForm {
private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;

    virtual void executeAction() const;

public:
    AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class NotSignedException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    void beSigned(const Bureaucrat& b);
    void execute(const Bureaucrat& executor) const;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);