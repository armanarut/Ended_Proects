#include <iostream>
#include <fstream>
#include <string>

std::string  readingFile(std::string filename)
{
    std::string  line;
    char    c;
    std::ifstream infile (filename.c_str());

    if (infile.is_open())
    {
        while (!infile.eof() && infile >> std::noskipws >> c)
            line += c;
        infile.close();
        return (line);
    }
    std::cout << "Can't open file: " << filename << std::endl;
    return ("");
}

int    replaceFile( std::string filename, std::string name, std::string r_name)
{
    int     pos;
    std::string line = readingFile(filename);
    std::ofstream outfile (std::string(filename + ".replace").c_str(), std::ifstream::trunc);

    if (!line.empty() && outfile.is_open())
    {
        for(int i = 0; i < (int)line.size(); i++)
        {
            pos = line.find(name, i);
            if  (pos != -1 && pos == i)
            {
                outfile << r_name;
                i += name.size() - 1;
            }
            else 
                outfile << line[i];
        }
        outfile.close();
        return (0);
    }
    return (1);
}

int main(int argc, char *argv[])
{
    if (argc == 4)
        return (replaceFile(argv[1], argv[2], argv[3]));
    std::cout << "**Please enter 3 arguments**" << std::endl;
    return (0);
}