#include "AForm.hpp"

#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other)
        _isSigned = other._isSigned;
    return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const { return _name; }
bool AForm::getIsSigned() const { return _isSigned; }
int AForm::getGradeToSign() const { return _gradeToSign; }
int AForm::getGradeToExecute() const { return _gradeToExecute; }

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade too high (minimum is 1)";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade too low (maximum is 150)";
}

const char* AForm::NotSignedException::what() const throw() {
    return "Form is not signed";
}

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

void AForm::executeAction() const {}

void AForm::execute(const Bureaucrat& executor) const {
    if (!_isSigned)
        throw NotSignedException();
    if (executor.getGrade() > _gradeToExecute)
        throw GradeTooLowException();
    executeAction();
}

std::ostream& operator<<(std::ostream& os, AForm const& f)
{
	os << "AForm: "          << f.getName()
	   << " | signed: "     << (f.getIsSigned() ? "yes" : "no")
	   << " | sign grade: " << f.getGradeToSign()
	   << " | exec grade: " << f.getGradeToExecute();
	return os;
}

