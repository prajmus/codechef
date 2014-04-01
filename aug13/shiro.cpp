#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <iomanip>
#define PMAX 101

using std::vector;
using std::cout;
using std::cin;

class Map {
private:
    double props[30000];
    bool exists[30000];
    int links[30000];
    int index;
public:
    class iterator {
        Map *t;
        int ind;
    public:
        iterator(); 
        iterator(Map *t, int k);
        int first;
        double second;
        iterator operator++(int j) { if(ind<=t->index){ind++; first=t->links[ind];second=t->props[t->links[ind]];}return *this;}
        bool operator==(const iterator& it) { return this->ind == it.ind ? true : false ;}
        bool operator!=(const iterator& it) { return this->ind != it.ind ? true : false ;}
        iterator operator=(const iterator& it) { this->ind=it.ind; this->first=it.first; this->second=it.second;}
    };
public:
    Map(); 
    double& operator[](int key);
    iterator begin() { return iterator(this, 0);}
    iterator end() { return iterator(this, index);}
    void clear() { for(int i=0;i<30000;++i) { index=0;exists[i] = false; props[i]=0.0;}}
};

Map::iterator::iterator()
{
    ind = 0;
    first = 0;
    second = 0.0;
}

Map::iterator::iterator(Map *map, int k)
{
    t = map;
    ind = k;
    first = t->links[k];
    second = t->props[t->links[k]];
}

Map::Map() 
{
    for(int i=0;i<30000;++i)
        exists[i] = false;
    index = 0;
}


double& Map::operator[](int key)
{
    if(exists[key]) {
        return props[key];
    }
    else {
        exists[key] = true;
        props[key] = 0.0; links[index] = key; ++index;
    }
    return props[key];
}

int T, P, sum;
double res;

typedef Map::iterator Mit;

int flags[PMAX];
int probs[PMAX];
Map dyn[PMAX];


int main()
{
  std::ios_base::sync_with_stdio(0);
	cin >> T;
	while(T--){
		sum = 0;
		res = 0;
		for(int i = 0; i < PMAX; ++i) dyn[i].clear();
		cin >> P;
		for(int i = 0; i < P; ++i){
			cin >> flags[i];
			sum += flags[i];
		}
		sum = (sum >> 1) + (sum & 1);
		for(int i = 0; i < P; ++i) cin >> probs[i];
		dyn[0][0] = 1.0;
		for(int i = 0, p; i < P; ++i){
			p = i + 1;
			for(Mit it = dyn[i].begin(); it != dyn[i].end(); it++){
        double noadd = it.second * (-0.01 * probs[i] + 1);
				double add = it.second * (0.01 * probs[i]);
				if(noadd) {dyn[p][it.first] += noadd; }
				if(add) {dyn[p][it.first + flags[i]] += add; }
			}
		}
			
		for(Mit it = dyn[P].begin(); it != dyn[P].end(); it++){
			if(it.first >= sum) res += it.second;
		}
		cout << res << '\n';
	}
	return 0;
}
