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

#define lli long long int

using namespace std;

int find_palindrome(const string &s, int &len)
{
    int length = s.size();

    int p[2*length+1];
    p[0] = 0;
    p[1] = 1;

    int center = 1;
    int right = 2;

    for(int p2=2; p2 < 2*length+1; p2++) {
        int p1 = center - (p2-center);

        while(p1 < 0) {
            center++;
            right = p[center] + center;
            p1 = center - (p2-center);

        }
        if(p[p1] < right - p2) {
            p[p2] = p[p1];
        } else {
            center = p2;
            int k = right - p2;
            if(k<0) k = 0;
            while(1) {
                if((p2+k+1) & 1) {
                    if(p2+k+1 < 2*length+1 && p2-k-1 >=0 && s[(p2+k)/2] == s[(p2-k-2)/2])
                        k++;
                    else
                        break;
                } else {
                    if(p2+k+1 < 2*length+1 && p2-k-1 >=0)
                        k++;
                    else
                        break;
                }
            }
            right = p2+k;
            p[p2] = k;
        }
    }

    int maxLen = 0;
    int centerIndexOrigin = 0;
    for(int i=1;i<2*length+1;i++) {
        if (p[i] > maxLen) {
            maxLen = p[i];
            centerIndexOrigin = i;
        }
    }

    len = maxLen;
    return (centerIndexOrigin-maxLen)/2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    return 0;
}
