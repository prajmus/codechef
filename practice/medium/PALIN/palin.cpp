#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map> // hash map
#include <utility>
#include <vector>

#define DEBUG(x) do { cout << #x << " = " << x << '\n';}while(0)

#define lli long long int

using namespace std;

void mirror(string &s)
{
    unsigned int size = s.length();
    for (int i = 0; i < size/2; ++i)
    {
        s[size-i-1] = s[i];
    }
}

void generate(string &s, int l, int r)
{
    if (l < 0)
    {
        s[s.length()-1] = '1';
        s.insert(s.begin(), '1');
        return;
    }
    else if (s[l] < '9')
    {
        s[l] = s[r] = s[l] + 1;
        return;
    }
    else
    {
        s[l] = s[r] = '0';
        generate(s, l-1, r+1);
        return;
    }
}

bool comp(const string &a, const string &b)
{
    if (a.length() != b.length())
    {
        return a.length() < b.length();
    }
    else
    {
        for (int i = 0; i < a.length(); ++i)
        {
            if (a[i] != b[i])
                return a[i] < b[i];
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string in;
    int T;
    cin >> T;
    while (T--)
    {
        cin >> in;
        string out = in;
        mirror(out);
        if (comp(in, out))
        {
            cout << out << '\n';
        }
        else
        {
            if (out.length() % 2 == 0)
                generate(out, out.length()/2-1, out.length()/2);
            else
                generate(out, out.length()/2, out.length()/2);
            cout << out << '\n';
        }
    }
    return 0;
}
