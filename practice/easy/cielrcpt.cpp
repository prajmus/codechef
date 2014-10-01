#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
//#include <unordered_map> // hash map
#include <utility>
#include <vector>

#define DEBUG(x) do { cout << #x << " = " << x << '\n';}while(0)

#define lli long long int
int T, p;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> p;
        int result = 0;
        result += static_cast<int>(p/2048);
        p %= 2048;
        result += static_cast<int>(p/1024);
        p %= 1024;
        result += static_cast<int>(p/512);
        p %= 512;
        result += static_cast<int>(p/256);
        p %= 256;
        result += static_cast<int>(p/128);
        p %= 128;
        result += static_cast<int>(p/64);
        p %= 64;
        result += static_cast<int>(p/32);
        p %= 32;
        result += static_cast<int>(p/16);
        p %= 16;
        result += static_cast<int>(p/8);
        p %= 8;
        result += static_cast<int>(p/4);
        p %= 4;
        result += static_cast<int>(p/2);
        p %= 2;
        result += p;
        cout << result << '\n';
    }

    return 0;
}
