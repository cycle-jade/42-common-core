#include "Contact.hpp"

void Contact::setname(std::string str) { name = str; }
void Contact::setlastname(std::string str) { lastname = str; }
void Contact::setnickname(std::string str) { nickname = str; }
void Contact::setphonenumber(std::string str) { phonenumber = str; }
void Contact::setdarkestsecret(std::string str) { darkestsecret = str; }
std::string Contact::getname() { return name; }
std::string Contact::getlastname() { return lastname; }
std::string Contact::getnickname() { return nickname; }
std::string Contact::getphonenumber() { return phonenumber; }
std::string Contact::getdarkestsecret() { return darkestsecret; }
Contact::~Contact() {std::cout << "Contact destroyed." << std::endl;};
Contact::Contact() { std::cout << "Contact created." << std::endl; }