#include <iostream>
#include <algorithm>

using namespace std;

struct point{
	int x;
	int y;
} p[100000];

bool cmpX(struct point a, struct point b){
	return a.x < b.x;
}

bool cmpY(struct point a, struct point b){
	return a.y < b.y;
}

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> p[i].x >> p[i].y;
	}
	sort(p, p+n, cmpX);
	long long ans = 0;
	bool distinct;
	distinct = true;
	for(int i = 1; i < n; ++i){
		if(p[i-1].x == p[i].x){
			if(distinct){
				distinct = false;
				++ans;
			}
		}else{
			distinct = true;
		}
	}
	sort(p, p+n, cmpY);
	distinct = true;
	for(int i = 1; i < n; ++i){
		if(p[i-1].y == p[i].y){
			if(distinct){
				distinct = false;
				++ans;
			}
		}else{
			distinct = true;
		}
	}
	cout << ans;
	return 0;
}
