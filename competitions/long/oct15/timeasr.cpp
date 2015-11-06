#include <algorithm>
#include <iostream>
#include <iomanip>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <unordered_map> // hash map
#include <utility>
#include <vector>

#define DEBUG(x) do { cout << #x << " = " << x << '\n';}while(0)

#define lli long long int

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        float d;
        float range = 1.0/120.0;
        cin >> d;
        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {
                float angle = abs(0.5 * (60.0 * h - 11.0 * m));
                if (angle > 180.0)
                    angle = 360 - angle;
                if (d >= angle - range && d <= angle + range)
                    cout << setfill('0') << setw(2) << h << ':' << setw(2) << m << '\n';
            }
        }
    }
    return 0;
}
