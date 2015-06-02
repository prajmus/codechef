#include <iostream>
#include <cstdio>
#include <vector>

#define MOD 1000000

using namespace std;

int main()
{
    int T, N, a, b, c;
    long long int d;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d %d %d %lld", &N, &a, &b, &c, &d);
        long long int max = d;
        vector<long long int> set(1000000, 0);
        ++set[d];
        for (int i = 1; i<N; ++i)
        {
            d = (a*d*d + b*d + c)%MOD;
            if (d > max)
                max = d;
            ++set[d];
        }
        long long int result = 0;
        int sign = 1;

        for (int i=0;i<=max;i++)
        {
            if (set[i]%2==1)
            {
                result += (sign)*i;
                sign = -sign;
                //cout << set[i] << ' ' << result << '\n';
            }
        }
        cout << (result > 0 ? result : -result) << '\n';
    }
    return 0;
}
