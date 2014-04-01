#include <cstdio>

int main()
{
  unsigned n,k;
  unsigned l;
  unsigned result=0;
  scanf("%d %d", &n, &k);
  while(n--) {
    scanf("%d", &l);
    if(l%k == 0)
      ++result;
  }
  printf("%d\n", result);
  return 0;
}
