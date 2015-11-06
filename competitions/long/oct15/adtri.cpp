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

int T, N;

bool check(int m) {
    double p = (m%2==0) ? m : m+1;
    double q = (m%2==0) ? m : m-1;
    int d = 2;
    while (p-d != 0 && q+d != 2*N) {
        double s = sqrt((double)N*N - (double)(p-d)*(p-d)/4);
        //cout << "S1 " << p-d << ' ' <<  s << '\n';
        if (s == floor(s)) {
            return true;
        }
        s = sqrt((double)N*N - (double)(q+d)*(q+d)/4);
        //cout << "S2 " << q+d << ' ' << s << '\n';
        if (s == floor(s)) {
            return true;
        }
        d += 2;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> N;
        if (check(N))
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }

    return 0;
}
