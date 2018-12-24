#include <iostream>
#include <string>

using namespace std;

int main()
{
    string directPattern, reservePattern;
    cin >> directPattern;

    for (int i = 0; i < directPattern.length(); i++)
    {
        switch (directPattern[i])
        {
        case 'A':
            reservePattern = 'T' + reservePattern;
            break;
        case 'C':
            reservePattern = 'G' + reservePattern;
            break;
        case 'G':
            reservePattern = 'C' + reservePattern;
            break;
        case 'T':
            reservePattern = 'A' + reservePattern;
            break;
        }
    }

    cout << reservePattern << endl;

    return 0;
}
