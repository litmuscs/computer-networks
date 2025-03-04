#include <iostream>
#include <string>
using namespace std;
#define GUARD_SEQUENCE "01111110"
int main()
{
    string input, output = GUARD_SEQUENCE;
    int oneCounter = 0, foundZero = 0;
    cout << "Enter your input in binary: ";
    getline(cin, input);
    for (char c : input)
    {
        if (c == '1')
        {
            if (oneCounter == 5)
            {
                output += '0';
                oneCounter = 0;
            }
            output += c;
            if (foundZero)
                oneCounter++;
        }
        else if (c == '0')
        {
            foundZero = 1;
            output += c;
            oneCounter = 0;
        }
        else
        {
            cerr << "Invalid character '" << c << "' encountered, exiting." << endl;
            exit(-1);
        }
    }
    output += GUARD_SEQUENCE;
    cout << "Formatted bit sequence: " << output << endl;
    return 0;
}