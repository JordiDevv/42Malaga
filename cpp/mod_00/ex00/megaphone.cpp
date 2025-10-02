#include <iostream>
#include <string.h>
#include <cctype>
using namespace std;
#define DEF_MSG "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

char *capitalize(char *str)
{
    for (int i = 0; str[i]; i++) str[i] = toupper(str[i]);
    return (str);
}

int main(int argc, char **argv)
{
    string text = DEF_MSG;

    if (argc == 1) cout.write(text.c_str(), text.length());

    for (int i = 1; i < argc; i++)
    {
        text = capitalize(argv[i]);
        cout.write(text.c_str(), text.length());
    }

    cout.put('\n');
    return (0);
}
