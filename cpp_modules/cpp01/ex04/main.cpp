#include <iostream>
#include <string>
#include <fstream>

const std::string customReplace(const std::string& line, const std::string& s1, const std::string& s2)
{
    std::string result;
    size_t pos = 0;

    while (pos < line.length())
    {
        size_t found = line.find(s1, pos);
        if (found != std::string::npos)
        {
            result.append(line, pos, found - pos);
            result += s2;
            pos = found + s1.length();
        }
        else
        {
            result.append(line, pos, line.length() - pos);
            break;
        }
        
    }
    return result;
}

int main(int argc, char** argv)
{
    std::string line;
    if(argc != 4)
    {
        std::cout << "There must be 3 arguments" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    if(s1.empty() || s2.empty())
    {
        std::cout << "Strings must not be empty" << std::endl;
        return 1;
    }
    std::ifstream in(filename.c_str());
    std::ofstream out((filename + ".replace").c_str());
    if (!in) {
        std::cout << "Error opening file: " << filename << std::endl;
        return 1;
    }
    while (std::getline(in, line))
    {
        std::string replaced = customReplace(line, s1, s2);
        out << replaced;
        if (!in.eof())
        out << '\n'; 
    }
    in.close();
    out.close();
    return 0;
}