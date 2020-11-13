#include <cstdio>
#include <algorithm>

using std::max;

int main(){
	int n;
	scanf("%d", &n);
	int minEnd = 100001, maxStart = -1;
	for(int i = 0; i < n; ++i){
		int start, end;
		scanf("%d %d", &start, &end);
		if(start > maxStart){
			maxStart = start;
		}
		if(end < minEnd){
			minEnd = end;
		}
	}
	printf("%d", max(maxStart - minEnd, 0));
	return 0;
}
