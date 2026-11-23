*This project has been created as part of the 42 curriculum by `<glicciar>`.*

# cpp_modules

> Ten C++98 modules (00 to 09) introducing object-oriented programming and the C++ standard library.

## Description

The C++ modules are a series of exercises that build up the main ideas of C++ one step at a time, from classes and memory management to templates and the standard containers. All code follows the C++98 standard and is compiled with `c++ -Wall -Wextra -Werror -std=c++98`.

| Module | Topic | Exercises |
|---|---|---|
| **00** | Namespaces, classes, member functions, streams, initialization lists, `static` and `const` | Megaphone, a PhoneBook, and an Account log recreation |
| **01** | Memory allocation, pointers and references, pointers to members, `switch` | Zombie, zombie horde, pointer vs reference, Weapon with HumanA/HumanB, a file replacer, Harl |
| **02** | Ad-hoc polymorphism, operator overloading, orthodox canonical form | A fixed-point number class, and BSP (point inside a triangle) |
| **03** | Inheritance | ClapTrap, ScavTrap, FragTrap and DiamondTrap |
| **04** | Subtype polymorphism, abstract classes, interfaces | Animal, Dog and Cat with a Brain (deep copy), an abstract class, and an interface-based Materia system |
| **05** | Exceptions (`try` / `catch`) | Bureaucrat, Forms, concrete forms, and an Intern |
| **06** | The C++ casts | Scalar type conversion, serialization, identifying a real type |
| **07** | Templates | Function templates, `iter`, and a templated `Array` |
| **08** | Templated containers, iterators, algorithms | `easyfind`, `Span`, and `MutantStack` |
| **09** | Standard containers (STL) | A Bitcoin exchange calculator, a Reverse Polish Notation calculator, and PmergeMe (Ford-Johnson merge-insertion sort) |


## Instructions

**Requirements:** a C++ compiler (`c++`) and `make`.

Each exercise has its own folder and Makefile:
```bash
cd cpp_modules/cpp05/ex00
make
./bureaucrat
make fclean
```


## Resources
- [cppreference.com](https://en.cppreference.com/)
- [cplusplus.com reference](https://cplusplus.com/reference/)
- [C++ FAQ](https://isocpp.org/faq)

**Use of AI**
- Code assistence and debugging
