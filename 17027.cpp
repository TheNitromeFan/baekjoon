#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int s[4] = {0, 1, 2, 3};
	int p[4] = {0, 0, 0, 0};
	for(int i = 0; i < n; ++i){
		int a, b, g;
		scanf("%d %d %d", &a, &b, &g);
		swap(s[a], s[b]);
		++p[s[g]];
	}
	printf("%d", max(max(p[1], p[2]), p[3]));
	return 0;
}
