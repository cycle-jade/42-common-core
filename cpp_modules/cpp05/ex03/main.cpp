#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

static void sep(std::string const& title)
{
	std::cout << "\n--- " << title << " ---" << std::endl;
}

int main()
{
	Intern  intern;
	AForm*  form = NULL;

	sep("Shrubbery creation via Intern");
	{
		form = intern.makeForm("shrubbery creation", "front_yard");
		if (form)
		{
			Bureaucrat b("Gardener", 100);
			b.signForm(*form);
			b.executeForm(*form);
			delete form;
			form = NULL;
		}
	}

	sep("Robotomy request via Intern");
	{
		form = intern.makeForm("robotomy request", "Bender");
		if (form)
		{
			Bureaucrat b("Surgeon", 1);
			b.signForm(*form);
			b.executeForm(*form);
			b.executeForm(*form);
			delete form;
			form = NULL;
		}
	}

	sep("Presidential pardon via Intern");
	{
		form = intern.makeForm("presidential pardon", "Arthur Dent");
		if (form)
		{
			Bureaucrat b("Zaphod", 1);
			b.signForm(*form);
			b.executeForm(*form);
			delete form;
			form = NULL;
		}
	}

	sep("Unknown form name");
	{
		form = intern.makeForm("coffee request", "Marvin");

		if (form == NULL)
			std::cout << "(correctly returned NULL)" << std::endl;
		else
		{
			std::cout << "BUG: should have returned NULL" << std::endl;
			delete form;
		}
	}
	sep("Array of Intern-created forms (polymorphism)");
	{
		const std::string formNames[3] = {
			"shrubbery creation",
			"robotomy request",
			"presidential pardon"
		};
		const std::string targets[3] = { "backyard", "C3PO", "Ford Prefect" };

		AForm* forms[3] = { NULL, NULL, NULL };
		Bureaucrat boss("Boss", 1);

		for (int i = 0; i < 3; ++i)
			forms[i] = intern.makeForm(formNames[i], targets[i]);

		for (int i = 0; i < 3; ++i)
		{
			if (forms[i])
			{
				boss.signForm(*forms[i]);
				boss.executeForm(*forms[i]);
			}
		}
		for (int i = 0; i < 3; ++i)
			delete forms[i];
	}

	return 0;
}