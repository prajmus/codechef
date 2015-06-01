#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <cstdio>

#define DEBUG(x) do { cout << #x << " = " << x << '\n';}while(0)

#define lli long long int

using namespace std;

bool prime[31623];

void primes()
{
    for (int i = 0; i< 31623; ++i)
        prime[i] = true;

    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i*i <= 1000000000; ++i)
    {
        if (prime[i] == true)
        {
            for (lli j=i*i;j*j<=1000000000L;j+=i)
                prime[j] = false;
        }
    }
}

int T, N, M;
int main()
{
    vector<int> pri;

    primes();

    for (int i = 0; i < 31623 ; ++i)
    {
        if (prime[i] == true)
            pri.push_back(i);
    }

    const size_t pri_count = pri.size();

    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d", &N, &M);
        for (int i=N;i<=M;i++)
        {
            if (i < 31623)
            {
                if (prime[i] == true)
                    printf("%d\n", i);
            }
            else
            {
                bool is_prime = true;
                for (int j=0;j<pri_count && pri[j] * pri[j] <= i;j++)
                {
                    if (i%pri[j] == 0)
                    {
                        is_prime = false;
                        break;
                    }
                }
                if (is_prime == true)
                    printf("%d\n", i);
            }
        }
        printf("\n");
    }

    return 0;
}
