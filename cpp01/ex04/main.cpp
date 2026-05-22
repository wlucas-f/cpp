#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: ./replace filename s1 s2" << std::endl;
        return (1);
    }

    std::string filename(argv[1]);
    std::string s1(argv[2]);
    std::string s2(argv[3]);
    std::string line;
    std::ifstream file(filename);
    std::ofstream fileout(filename + ".replace");
    if(!fileout.is_open())
    {
        std::cerr << "Error: Failed to create output file!" << std::endl;
        return (1);
    }
    if (file.is_open())
    {
        while (getline(file, line))
        {
            int pos = line.find(s1);
            if (pos == std::string::npos)
            {
                fileout << line << std::endl;
                continue ;
            }
            while (pos != std::string::npos)
            {
                fileout << line.substr(0, pos) << s2 << (pos == line.rfind(s1) ? (line.substr(pos + s1.length())) : "" );
                line = line.substr(pos + s1.length());
                pos = line.find(s1);
            }
            fileout << std::endl;
        }
        file.close();
    }
    else
    {
        std::cerr << "Error: Failed to open input file!" << std::endl;
        return (1);
    }
}