#include <iostream>
#include <string>

using namespace std;

int main()
{
    int k;
    string text;
    string out;

    int count = 0;
    int maxCount = -1;

    cin >> text;
    cin >> k;

    for (int i = 0; i < text.length() - k + 1; i++)
    {
        count = 0;
        for (int j = i + 1; j < text.length() - k + 1; j++)
        {
            if (text.substr(i, k) == text.substr(j, k))
            {
                count++;
            }
        }

        if (count > maxCount)
        {
            out = text.substr(i, k);
            maxCount = count;
        }
        else if (count == maxCount)
        {
            out += " " + text.substr(i, k);
        }
    }

    cout << out;

    return 0;
}
