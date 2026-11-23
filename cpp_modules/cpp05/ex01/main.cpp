#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

static void printSeparator(std::string const& title)
{
	std::cout << "\n--- " << title << " ---" << std::endl;
}

int main()
{
	// ── 1. Bureaucrat construction guards  ──────────────────────
	printSeparator("Bureaucrat bounds");
	try
	{
		Bureaucrat bad("Ghost", 0);
		(void)bad;
	}
	catch (std::exception& e)
	{
		std::cout << "Grade 0 bureaucrat: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bad("Ghost", 151);
		(void)bad;
	}
	catch (std::exception& e)
	{
		std::cout << "Grade 151 bureaucrat: " << e.what() << std::endl;
	}

	// ── 2. Form construction guards ────────────────────────────────────────
	printSeparator("Form bounds - grade too high (0)");
	try
	{
		Form bad("TaxForm", 0, 50);
		(void)bad;
	}
	catch (std::exception& e)
	{
		std::cout << "Form(gradeToSign=0): " << e.what() << std::endl;
	}

	try
	{
		Form bad("TaxForm", 50, 0);
		(void)bad;
	}
	catch (std::exception& e)
	{
		std::cout << "Form(gradeToExecute=0): " << e.what() << std::endl;
	}

	printSeparator("Form bounds - grade too low (151)");
	try
	{
		Form bad("TaxForm", 151, 50);
		(void)bad;
	}
	catch (std::exception& e)
	{
		std::cout << "Form(gradeToSign=151): " << e.what() << std::endl;
	}

	try
	{
		Form bad("TaxForm", 50, 151);
		(void)bad;
	}
	catch (std::exception& e)
	{
		std::cout << "Form(gradeToExecute=151): " << e.what() << std::endl;
	}

	// ── 3. Successful signing ──────────────────────────────────────────────
	printSeparator("Successful signing");
	{
		Bureaucrat senior("Alice", 10);
		Form        permit("PresidentialPardon", 50, 25);

		std::cout << senior << std::endl;
		std::cout << permit << std::endl;

		senior.signForm(permit);

		std::cout << permit << std::endl;   
	}

	// ── 4. Failed signing (bureaucrat grade too low) ───────────────────────
	printSeparator("Failed signing - grade too low");
	{
		Bureaucrat junior("Bob", 100);
		Form        form("RoboticsLicense", 30, 60);

		std::cout << junior << std::endl;
		std::cout << form   << std::endl;

		junior.signForm(form);              

		std::cout << form << std::endl;     
	}

	// ── 5. Edge cases: exact grade match ──────────────────────────────────
	printSeparator("Exact grade match - should succeed");
	{
		Bureaucrat exact("Charlie", 42);
		Form        form("ExactForm", 42, 100);

		exact.signForm(form);
		std::cout << form << std::endl;
	}

	// ── 6. One above required - should fail ───────────────────────────────
	printSeparator("One grade below authority - should fail");
	{
		Bureaucrat close("Dave", 43);
		Form        form("CloseCall", 42, 100);

		close.signForm(form);
		std::cout << form << std::endl;
	}

	// ── 7. Bureaucrat increment / decrement ───────────────────────────────
	printSeparator("Bureaucrat increment / decrement");
	{
		Bureaucrat b("Eve", 75);
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << "After increment: " << b << std::endl;
		b.decrementGrade();
		b.decrementGrade();
		std::cout << "After two decrements: " << b << std::endl;
	}

	printSeparator("Increment past 1");
	{
		Bureaucrat top("Top", 1);
		try { top.incrementGrade(); }
		catch (std::exception& e) { std::cout << e.what() << std::endl; }
	}

	printSeparator("Decrement past 150");
	{
		Bureaucrat bot("Bot", 150);
		try { bot.decrementGrade(); }
		catch (std::exception& e) { std::cout << e.what() << std::endl; }
	}

	return 0;
}