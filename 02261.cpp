#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#define BOUND 10000

using namespace std;

struct pa{
	int x, y;
	pa(){
		
	}
	pa(int x, int y){
		this->x = x, this->y = y;
	}
	bool operator < (const pa &p) const {
		return y < p.y || (y == p.y && x < p.x);
	}
	bool operator == (const pa &p) const {
		return x == p.x && y == p.y;
	}
};

bool cmp(const pa &a, const pa &b){
	return a.x < b.x;
}

int square(int x){
	return x * x;
}

int dist(pa a, pa b){
	return square(a.x - b.x) + square(a.y - b.y);
}

int min_dist(vector<pa> p){
	set<pa> s;
	int ret = dist(p[0], p[1]);
	unsigned start = 0;
	s.insert(p[0]);
	s.insert(p[1]);
	for(unsigned i = 2; i < p.size(); ++i){
		while(start < i && square(p[i].x - p[start].x) > ret){
			s.erase(p[start]);
			++start;
		}
		int d = (int)sqrt(ret);
		auto low = s.lower_bound(pa(-BOUND, p[i].y - d));
		auto high = s.upper_bound(pa(BOUND, p[i].y + d));
		for(auto it = low; it != high; ++it){
			int tmp = dist(p[i], *it);
			if(ret > tmp){
				ret = tmp;
			}
		}
	}
	return ret;
}

int main(){
	unsigned n;
	scanf("%u", &n);
	vector<pa> points;
	for(unsigned i = 0; i < n; ++i){
		int x, y;
		scanf("%d %d", &x, &y);
		points.push_back(pa(x, y));
	}
	sort(points.begin(), points.end(), cmp);
	printf("%d", min_dist(points));
	return 0;
}
