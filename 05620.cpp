#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;
struct P{
    int x,y;
    P(){}
    P(int x, int y): x(x), y(y){}
    bool operator < (const P & p) const{
        if(y == p.y) return x < p.x;
        return y < p.y;
    }
    bool operator == (const P & p) const {
        return x == p.x && y == p.y;
    }
};
bool compare(const P & a, const P & b){
    return a.x < b.x;
}
inline int pow2(int n){return n * n;}
inline int dist(P a, P b){return pow2(a.x - b.x) + pow2(a.y - b.y);}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<P> p;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        p.push_back(P(x, y));
	}
	sort(p.begin(), p.end(), compare);
	set<P> S;
	int result = dist(p[0], p[1]), start = 0;
	S.insert(p[0]);
	S.insert(p[1]);
	for(int i=2; i<n; i++){
		while(start < i){
			if(pow2(p[i].x - p[start].x) > result) S.erase(p[start++]);
			else break;
		}
		int d = (int)sqrt(result);
		auto lo = S.lower_bound(P(-10000, p[i].y-d));
		auto hi = S.upper_bound(P(10000, p[i].y+d));
		for(auto iter=lo; iter!=hi; iter++){
			result = min(result, dist(p[i], *iter));
		}
		S.insert(p[i]);
	}
	cout << result <<'\n';
	return 0;
}
