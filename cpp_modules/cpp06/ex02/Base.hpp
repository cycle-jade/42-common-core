#pragma once


//If it dont got the virtual distructor 
// you cant use the dinamic cast on it
//cause it enables runtime polymorphism
class Base
{
public: 
virtual ~Base();
};

