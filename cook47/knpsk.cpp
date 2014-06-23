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

int N, W, C, M;
vector<lli> ones;
vector<lli> twos;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int n=0;n<N;n++)
    {
        cin >> W >> C;
        M += W;
        if (W == 1)
            ones.push_back(C);
        else
            twos.push_back(C);
    }
    sort(ones.begin(), ones.end(), greater<lli>());
    sort(twos.begin(), twos.end(), greater<lli>());
    vector<lli> answ(M+1, 0);

    lli result = 0;
    int on=0, tw=0;
    for (int w=2;w<=M; w += 2)
    {
        if (on <= static_cast<int>(ones.size()-2) && tw <= static_cast<int>(twos.size()-1) && ones[on]+ones[on+1] > twos[tw])
        {
            result += ones[on]+ones[on+1];
            on += 2;
            answ[w] = result;
        }
        else if (on <= static_cast<int>(ones.size()-2) && tw <= static_cast<int>(twos.size()-1) && ones[on]+ones[on+1] <= twos[tw])
        {
            result += twos[tw];
            ++tw;
            answ[w] = result;
        }
        else if (on <= static_cast<int>(ones.size()-2))
        {
            result += ones[on]+ones[on+1];
            on += 2;
            answ[w] = result;
        }
        else if (on <= static_cast<int>(ones.size()-1) && tw <= static_cast<int>(twos.size()-1) && ones[on] > twos[tw])
        {
            result += ones[on];
            on += 1;
            answ[w] = result;
        }
        else if (tw <= static_cast<int>(twos.size()-1))
        {
            result += twos[tw];
            ++tw;
            answ[w] = result;
        }
    }

    result = 0;
    on = tw = 0;

    if (ones.size() > 0)
    {
        result = ones[on];
        on++;
        answ[1] = result;
    }
    for (int w = 3; w<=M;w += 2)
    {
        if (on <= static_cast<int>(ones.size()-2) && tw <= static_cast<int>(twos.size()-1) && ones[on]+ones[on+1] > twos[tw])
        {
            result += ones[on]+ones[on+1];
            on += 2;
            answ[w] = result;
        }
        else if (on <= static_cast<int>(ones.size()-2) && tw <= static_cast<int>(twos.size()-1) && ones[on]+ones[on+1] <= twos[tw])
        {
            result += twos[tw];
            ++tw;
            answ[w] = result;
        }
        else if (on <= static_cast<int>(ones.size()-2))
        {
            result += ones[on]+ones[on+1];
            on += 2;
            answ[w] = result;
        }
        else if (on <= static_cast<int>(ones.size()-1) && tw <= static_cast<int>(twos.size()-1) && ones[on] > twos[tw])
        {
            result += ones[on];
            on += 1;
            answ[w] = result;
        }
        else if (tw <= static_cast<int>(twos.size()-1))
        {
            result += twos[tw];
            ++tw;
            answ[w] = result;
        }
    }


    for (int i=1;i<=M;i++)
    {
        cout << answ[i] <<  ' ';
    }

    return 0;
}
