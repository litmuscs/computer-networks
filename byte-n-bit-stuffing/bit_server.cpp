#include <iostream>
#include <string>
using namespace std;
#define GUARD_SEQUENCE "01111110"

int main()
{
    string input, output;
    int oneCounter = 0;
    cout << "Enter encoded bit sequence: ";
    getline(cin, input);
    int sizeOfInput = input.length();
    for (int i = 8; i < sizeOfInput - 8; i++)
    {
        char c = input[i];
        if (c == '1')
        {
            output += c;
            oneCounter++;
        }
        else if (c == '0')
        {
            if (oneCounter == 5)
            {
                continue;
            }
            else
            {
                output += c;
                oneCounter = 0;
            }
        }
    }
    cout << "Decoded output: " << output << endl;
}