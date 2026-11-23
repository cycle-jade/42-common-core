#pragma once
#include <string>
#include <iostream>

class Contact
{
    private:
    std::string name;
    std::string lastname;
    std::string nickname;
    std::string phonenumber;
    std::string darkestsecret;
    public:
    Contact();
    ~Contact();
    void    setname(std::string str);
    void    setlastname(std::string str);
    void    setnickname(std::string str);
    void    setphonenumber(std::string str);
    void    setdarkestsecret(std::string str);
    std::string    getname();
    std::string    getlastname();
    std::string    getnickname();
    std::string    getphonenumber();
    std::string    getdarkestsecret();
};