#include <cstdio>
#include <algorithm>

using std::min;

int folds(int start, int target){
	int ret = 0;
	while(start < target){
		start *= 2;
		++ret;
	}
	return ret;
}

int total_folds(int w, int h, int w1, int h1){
	int ret = 2100000000;
	if(w1 <= w && h1 <= h){
		ret = min(ret, folds(w1, w) + folds(h1, h));
	}
	if(w1 <= h && h1 <= w){
		ret = min(ret, folds(w1, h) + folds(h1, w));
	}
	return ret != 2100000000 ? ret : -1;
}

int main(){
	int w, h, w1, h1;
	scanf("%d %d %d %d", &w, &h, &w1, &h1);
	printf("%d", total_folds(w, h, w1, h1));
	return 0;
}
