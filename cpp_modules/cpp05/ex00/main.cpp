#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

static void printSection(const std::string& title)
{
	std::cout << "\n=== " << title << " ===" << std::endl;
}

int main()
{

	printSection("Valid construction and basic use");
	try
	{
		Bureaucrat alice("Alice", 42);
		std::cout << alice << std::endl;

		alice.incrementGrade();
		std::cout << "After increment: " << alice << std::endl;

		alice.decrementGrade();
		std::cout << "After decrement: " << alice << std::endl;
	}
	catch (const std::exception& e)
	{

		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}


	printSection("Copy and assignment");
	try
	{
		Bureaucrat original("Original", 10);
		Bureaucrat copied(original);
		Bureaucrat assigned("Assigned", 100);

		assigned = original;

		std::cout << "original: " << original << std::endl;
		std::cout << "copied:   " << copied << std::endl;
		std::cout << "assigned: " << assigned << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}

	printSection("Constructor boundaries");
	try
	{

		Bureaucrat tooHigh("TooHigh", 0);
		std::cout << tooHigh << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat tooLow("TooLow", 151);
		std::cout << tooLow << std::endl;
	}
	catch (const std::exception& e)
	{

		std::cout << "Caught exception: " << e.what() << std::endl;
	}


	printSection("Grade limits");
	try
	{

		Bureaucrat top("Top", 1);
		std::cout << top << std::endl;
		top.incrementGrade();
		std::cout << top << std::endl;
	}
	catch (const std::exception& e)
	{

		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bottom("Bottom", 150);
		std::cout << bottom << std::endl;
		bottom.decrementGrade();
		std::cout << bottom << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	return 0;
}
