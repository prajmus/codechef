#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <string>

#define lli long long int

using namespace std;

string s;
lli result;
vector<pair<int, int>> state;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    int a, b;
    a = b = 0;
    state.push_back(make_pair(a, b));
    for (size_t i = 0; i < s.length(); ++i)
    {
        if (s[i] == 'A')
            ++a;
        else if (s[i] == 'B')
            ++b;
        else {
            --a;
            --b;
        }
        state.push_back(make_pair(a, b));
    }
    sort(state.begin(), state.end());

    for (size_t i = 0; i<=s.length(); ++i)
    {
        lli position = i;
        while (state[position] == state[i] && position <= s.length())
            ++position;

        lli dist = (lli)position - (lli)i;
        result += (dist*(dist-1))/2;
        i = position - 1;
    }
    cout << result << '\n';
    return 0;
}
