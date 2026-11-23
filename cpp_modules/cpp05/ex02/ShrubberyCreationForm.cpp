#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <stdexcept>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
: AForm("Shrubbery Creation", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& other)
: AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& other)
{
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction() const
{
	std::string filename = _target + "_shrubbery";
	std::ofstream file(filename.c_str());
	if (!file)
		throw std::runtime_error("Failed to open file: " + filename);
	file << "        *        \n"
		 << "       ***       \n"
		 << "      *****      \n"
		 << "     *******     \n"
		 << "    *********    \n"
		 << "   ***********   \n"
		 << "        |        \n"
		 << "        |        \n"
		 << "                 \n"
		 << "     *     *     \n"
		 << "    ***   ***    \n"
		 << "   *****.*****   \n"
		 << "  *****.*..*****  \n"
		 << "        |        \n"
		 << "        |        \n";

	file.close();
	std::cout << "Shrubbery created at " << filename << std::endl;
}