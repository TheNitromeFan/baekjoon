#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

int hailstone(map<int, int> &largest, int n){
	if(largest.find(n) != largest.end()){
		return largest[n];
	}
	int next;
	if(n % 2 == 0){
		next = n / 2;
	}else{
		next = n * 3 + 1;
	}
	int ret = hailstone(largest, next);
	largest[n] = max(n, ret);
	return largest[n];
}

int main(){
	int p;
	scanf("%d", &p);
	map<int, int> largest;
	largest[1] = 1;
	for(int i = 0; i < p; ++i){
		int n;
		scanf("%d", &n);
		printf("%d\n", hailstone(largest, n));
	}
	return 0;
}
