#include <cstdio>
#include <algorithm>

bool can_place(int h[200000], int n, int c, int dist){
	int last = 0;
	int cnt = 1;
	for(int i = 1; i < n; ++i){
		if(h[i] - h[last] >= dist){
			last = i;
			++cnt;
		}
		if(cnt >= c){
			return true;
		}
	}
	return false;
}

int search(int h[200000], int n, int c, int start, int end){
	if(start > end){
		return end;
	}
	long long middle = (start + end) / 2;
	if(can_place(h, n, c, middle)){
		return search(h, n, c, middle+1, end);
	}else{
		return search(h, n, c, start, middle-1);
	}
}

int main(){
	int n, c;
	scanf("%d %d", &n, &c);
	int houses[200000];
	for(int i = 0; i < n; ++i){
		scanf("%d", &houses[i]);
	}
	std::sort(houses, houses+n);
	printf("%d", search(houses, n, c, 0, houses[n-1] - houses[0] + 1));
	return 0;
}
