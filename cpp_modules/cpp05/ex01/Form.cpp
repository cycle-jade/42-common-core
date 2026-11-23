#include "Form.hpp"

Form::Form(std::string const& name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (_gradeToSign < 1 || _gradeToExecute < 1)   throw GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExecute > 150) throw GradeTooLowException();
}

Form::Form(Form const& other)
    : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}   

Form& Form::operator=(Form const& other) {
    if (this != &other)
        _isSigned = other._isSigned;
    return *this;
}

Form::~Form() {}

std::string Form::getName() const { return _name; }
bool Form::getIsSigned() const { return _isSigned; }
int Form::getGradeToSign() const { return _gradeToSign; }
int Form::getGradeToExecute() const { return _gradeToExecute; }

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade too high (minimum is 1)";
} 
const char* Form::GradeTooLowException::what() const throw() {
    return "Grade too low (maximum is 150)";
}

void Form::beSigned(Bureaucrat const& b) {
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}


std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << "Form " << f.getName() << ", signed: " << (f.getIsSigned() ? "yes" : "no")
       << ", grade required to sign: " << f.getGradeToSign()
       << ", grade required to execute: " << f.getGradeToExecute();
    return os;
}