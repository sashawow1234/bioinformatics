#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<char, int> aminoacidMassTable = {{'G', 57},
                                     {'A', 71},
                                     {'S', 87},
                                     {'P', 97},
                                     {'V', 99},
                                     {'T', 101},
                                     {'C', 103},
                                     {'I', 113},
                                     {'L', 113},
                                     {'N', 114},
                                     {'D', 115},
                                     {'K', 128},
                                     {'Q', 128},
                                     {'E', 129},
                                     {'M', 131},
                                     {'H', 137},
                                     {'F', 147},
                                     {'R', 156},
                                     {'Y', 163},
                                     {'W', 186}};

int getMass(string pattern)
{
    int mass = 0;
    for (int i = 0; i < pattern.length(); i++)
    {
        mass += aminoacidMassTable.at(pattern[i]);
    }

    return mass;
}

int main()
{
    string peptide;
    cin >> peptide;

    string buf = peptide;
    for (int i = 0; i < peptide.length(); i++)
    {
        buf.push_back(peptide[i]);
    }

    vector<int> masses = {0};
    for (int i = 1; i < peptide.length(); i++)
    {
        for (int j = 0; j < peptide.length(); j++)
        {
            masses.push_back(getMass(buf.substr(j, i)));
        }
    }

    masses.push_back(getMass(peptide));

    sort(masses.begin(), masses.end());

    for (int i = 0; i < masses.size(); i++)
    {
        cout << masses[i] << " ";
    }
    cout << endl;

    return 0;
}
