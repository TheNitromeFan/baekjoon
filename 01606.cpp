#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

int loop(pair<int, int> a){
	int x = a.first, y = a.second;
	if(x >= 0 && y >= 0){
		return x + y;
	}else if(x >= 0){
		return max(x, -y);
	}else if(y >= 0){
		return max(-x, y);
	}else{
		return -x - y;
	}
}

void next_pair(pair<int, int> &a, long long &cur){
	int &x = a.first, &y = a.second;
	if(x == 0 && y == 0){
		y = 1;
	}else if(x <= 0 && y > -x){
		--x;
	}else if(x < 0 && y > 0){
		--y;
	}else if(x < 0 && y <= 0){
		++x;
		--y;
	}else if(x >= 0 && y < -x){
		++x;
	}else if(x > 0 && y < 1){
		++y;
	}else{
		--x;
		++y;
	}
	++cur;
	// printf("%d %d\n", x, y);
}



int main(){
	pair<int, int> p;
	scanf("%d %d", &p.first, &p.second);
	if(p.first == 0 && p.second == 0){
		printf("1");
		return 0;
	}
	long long n = 2, summand = 6;
	pair<int, int> q = make_pair(0, 1);
	int l = loop(p);
	while(q.first + 1 < l){
		++q.first;
		n += summand;
		summand += 6;
	}
	while(p != q){
		next_pair(q, n);
	}
	printf("%lld", n);
	return 0;
}
