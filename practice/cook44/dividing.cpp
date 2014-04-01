#include <iostream>

#define ll long long int
#define DEBUG(x) do { cout << #x << " = " << x << '\n'; }while(0)

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    ll N;
    ll c, sum1, sum2;
    cin >> N;
    sum1 = (ll)(N*(N+1))/2;
    //DEBUG(sum1);
    sum2 = 0;
    while(N--)
    {
        cin >> c;
        sum2 += c;
    }
    if (sum2 == sum1)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
