#include <fstream>
#include <iostream>

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << "You need to introduce only the output data file as an argument" << std::endl;
        return 1;
    }
    
    std::ofstream outputData(argv[1]);

    outputData.close();
    return 0;
}
