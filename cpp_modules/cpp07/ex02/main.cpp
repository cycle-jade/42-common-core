#include "Array.hpp"
#include <iostream>
#include <string>
 
int main(void)
{
 
    std::cout << "=== Test 1: empty array ===" << std::endl;
 
    Array<int> empty;
    std::cout << "size: " << empty.size() << std::endl;  
 
    try
    {
        empty[0];
    }
    catch (std::exception& e)
    {
        std::cout << "empty[0] threw: " << e.what() << std::endl;
    }
 
 
 
    std::cout << "\n=== Test 2: sized int array ===" << std::endl;
 
    Array<int> ints(5);
    std::cout << "size: " << ints.size() << std::endl;
 
    for (unsigned int i = 0; i < ints.size(); i++)
    {
        ints[i] = static_cast<int>(i * 10);
        std::cout << "ints[" << i << "] = " << ints[i] << std::endl;
    }
 

    std::cout << "\n=== Test 3: deep copy ===" << std::endl;
 
    Array<int> original(3);
    original[0] = 1;
    original[1] = 2;
    original[2] = 3;
 
    Array<int> copy(original);       
    Array<int> assigned;
    assigned = original;             
 

    copy[0]     = 99;
    assigned[0] = 77;
 
    std::cout << "original[0]: " << original[0] << " (expected 1)" << std::endl;
    std::cout << "copy[0]:     " << copy[0]     << " (expected 99)"  << std::endl;
    std::cout << "assigned[0]: " << assigned[0] << " (expected 77)"  << std::endl;
 

    std::cout << "\n=== Test 4: out-of-bounds ===" << std::endl;
 
    Array<int> arr(3);
 
    try
    {
        arr[3];
    }
    catch (std::exception& e)
    {
        std::cout << "arr[3] threw: " << e.what() << std::endl;
    }

    try
    {
        arr[100];
    }
    catch (std::exception& e)
    {
        std::cout << "arr[100] threw: " << e.what() << std::endl;
    }
 
 
 
    std::cout << "\n=== Test 5: string array ===" << std::endl;
 
    Array<std::string> words(3);
    words[0] = "hello";
    words[1] = "world";
    words[2] = "array";
 
    for (unsigned int i = 0; i < words.size(); i++)
        std::cout << "words[" << i << "] = " << words[i] << std::endl;
 
    Array<std::string> wordsCopy(words);
    wordsCopy[0] = "modified";
 
    std::cout << "original words[0]: " << words[0]     << " (expected hello)"    << std::endl;
    std::cout << "copy words[0]:     " << wordsCopy[0] << " (expected modified)" << std::endl;
 
 
 
    std::cout << "\n=== Test 6: const Array ===" << std::endl;
 
    Array<int> const constArr(ints);  
 
    std::cout << "constArr.size(): " << constArr.size() << std::endl;
    std::cout << "constArr[0]: "     << constArr[0]     << std::endl;
 
    try
    {
        constArr[99]; 
    }
    catch (std::exception& e)
    {
        std::cout << "constArr[99] threw: " << e.what() << std::endl;
    }
 
    return 0;
}