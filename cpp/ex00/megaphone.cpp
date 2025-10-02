#include <iostream>
#include <string.h>
using namespace std;
#define DEF_MSG "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int main(int argc, char **argv)
{
    string text = DEF_MSG;

    if (argc == 1) cout.write(text.c_str(), text.length());

    for (int i = 1; i < argc; i++)
    {
        text = argv[i];
        cout.write(text.c_str(), text.length());
    }

    cout.put('\n');
    return (0);
}
