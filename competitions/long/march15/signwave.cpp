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

int T, S, C, K;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--)
    {
        cin >> S >> C >> K;

        if (K == 1)
        {
            if (C >= S)
            {
                unsigned lli score = 0;
                for (int i = 0; i<C; i++)
                {
                    score |= 1;
                    score <<= 1;
                }
                if (S != 0)
                    score += 3;
                cout << score << '\n';
            }
            else
            {
                unsigned lli score = 1;
                for (int i = 0; i<S; i++)
                {
                    score <<= 1;
                }
                cout << score+1 <<  '\n';
            }
        }
        else
        {
            unsigned lli score = 0;
            if (S+1-K > 0)
            {
                score = 1;
                for (int i=0;i<S+1-K;i++)
                {
                    score <<= 1;
                }
                score |= 1;
            }
            unsigned lli multiplier = 2;
            for (int i=1;i<=C;i++)
            {
                if (S-i >= K - 1 && i+K > S)
                {
                    score += multiplier;
                }
                multiplier <<= 1;
            }
            cout << score << '\n';
        }
    }
    return 0;
}
