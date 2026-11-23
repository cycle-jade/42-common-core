#pragma once 
#include <iostream>
#include "Bureaucrat.hpp"

class Form {
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;

        public:

        Form(std::string const& name, int gradeToSign, int gradeToExecute);
	    Form(Form const& other);
	    Form& operator=(Form const& other);
	    ~Form();

        //Getters
        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        //Exceptions
        class GradeTooHighException : public std::exception {
            public: 
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        //Member functions
        void beSigned(Bureaucrat const& b);        
    };

std::ostream& operator<<(std::ostream& os, const Form& f);