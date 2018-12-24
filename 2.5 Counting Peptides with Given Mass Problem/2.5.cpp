#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    int mass;
    cin >> mass;

    int aminoacidMasses[18] = {57, 71, 87, 97, 99, 101, 103, 113, 114, 115, 128, 129, 131, 137, 147, 156, 163, 186};
    unordered_map<int, uint64_t> count = {{0, 1}};
    count.reserve(mass - 57);

    for (int i = 57; i <= mass; i++)
    {
        count[i] = 0;

        for (int j = 0; j < 18; j++)
        {
            if (count.find(i - aminoacidMasses[j]) != count.end())
            {
                count[i] += count[i - aminoacidMasses[j]];
            }
        }
    }

    cout << count[mass] << endl;

    return 0;
}
