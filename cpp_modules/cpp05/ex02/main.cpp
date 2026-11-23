#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void sep(std::string const& title)
{
	std::cout << "\n--- " << title << " ---" << std::endl;
}

int main()
{
	sep("Execute unsigned form");
	{
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm form("garden");

		boss.executeForm(form);
	}

	sep("Sign with insufficient grade");
	{
		Bureaucrat weak("Weak", 100);
		PresidentialPardonForm form("Arthur Dent");

		weak.signForm(form);
		std::cout << form << std::endl;
	}

	sep("Execute with insufficient grade");
	{
		Bureaucrat signer("Signer", 40);
		Bureaucrat weakExec("WeakExec", 60);

		RobotomyRequestForm form("Trillian");
		signer.signForm(form);
		weakExec.executeForm(form);
	}

	sep("ShrubberyCreationForm happy path");
	{
		Bureaucrat gardener("Gardener", 100);
		ShrubberyCreationForm form("home");

		std::cout << form << std::endl;
		gardener.signForm(form);
		gardener.executeForm(form);
	}

	sep("RobotomyRequestForm x5 (observe 50/50)");
	{
		Bureaucrat surgeon("Surgeon", 1);
		RobotomyRequestForm form("Marvin");

		surgeon.signForm(form);
		for (int i = 0; i < 5; ++i)
			surgeon.executeForm(form);
	}

	sep("PresidentialPardonForm happy path");
	{
		Bureaucrat president("Zaphod", 1);
		PresidentialPardonForm form("Ford Prefect");

		president.signForm(form);
		president.executeForm(form);
	}

	sep("Exact grade boundary (grade == required)");
	{
		Bureaucrat exact("Exact", 145);
		ShrubberyCreationForm form("boundary");

		exact.signForm(form);
		Bureaucrat execExact("ExecExact", 137);
		execExact.executeForm(form);
	}

	sep("One grade too weak for execution");
	{
		Bureaucrat signer("Signer", 145);
		Bureaucrat tooWeak("TooWeak", 138);

		ShrubberyCreationForm form("edge");
		signer.signForm(form);
		tooWeak.executeForm(form);
	}

	sep("Polymorphism through AForm pointer");
	{
		Bureaucrat b("Poly", 1);

		AForm* forms[3];
		forms[0] = new ShrubberyCreationForm("poly");
		forms[1] = new RobotomyRequestForm("Robot");
		forms[2] = new PresidentialPardonForm("Zem");

		for (int i = 0; i < 3; ++i)
		{
			b.signForm(*forms[i]);
			b.executeForm(*forms[i]);
		}

		for (int i = 0; i < 3; ++i)
			delete forms[i];
	}

	return 0;
}