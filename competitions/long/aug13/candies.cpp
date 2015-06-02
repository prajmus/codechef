#include <cstdio>

int main()
{
    int T;
    long long int N, K;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld %lld", &N, &K);
        long long int kids, teacher;
        if (N == 0) {
            kids = teacher = 0;
        }
        else if (K==0) {
            kids = 0;
            teacher = N;
        }
        else {
            teacher = N%K;
            N-=teacher;
            kids = N/K;
        }
        printf("%lld %lld\n", kids, teacher);
    }
    return 0;
}
