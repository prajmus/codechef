#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0);
    long long int T, n, a;
    std::cin >> T;
    while(T--)
    {
        std::cin >> n;
        for(int i=0;i<n;i++)
        {
            std::cin >> a;
        }
        std::cout << (n*(n-1))/2 << '\n';
    }
}
