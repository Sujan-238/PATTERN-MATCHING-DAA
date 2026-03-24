#include <iostream>
#include <cstring>
using namespace std;

#define MAX 256

void badCharHeuristic(string str, int size, int badchar[MAX])
{
    for (int i = 0; i < MAX; i++)
        badchar[i] = -1;

    for (int i = 0; i < size; i++)
        badchar[(int)str[i]] = i;
}

void search(string txt, string pat)
{
    int m = pat.length();
    int n = txt.length();

    int badchar[MAX];
    badCharHeuristic(pat, m, badchar);

    int shift = 0;

    while (shift <= (n - m))
    {
        int j = m - 1;

        while (j >= 0 && pat[j] == txt[shift + j])
            j--;

        if (j < 0)
        {
            cout << "Pattern found at index: " << shift << endl;

            shift += (shift + m < n) ? m - badchar[txt[shift + m]] : 1;
        }
        else
        {
            shift += max(1, j - badchar[txt[shift + j]]);
        }
    }
}

int main()
{
    string txt, pat;

    cout << "Enter text: ";
    cin >> txt;

    cout << "Enter pattern: ";
    cin >> pat;

    search(txt, pat);

    return 0;
}