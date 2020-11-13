#include <cstdio>
#define MAX 5000
#define MAX_SUM (400000 + 1)

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int a[MAX];
	bool sums[MAX_SUM] = {};
	int ans = 0;
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
		for(int j = 0; j < i; ++j){
			if(sums[a[i] - a[j] + 200000]){
				++ans;
				break;
			}
		}
		for(int j = 0; j <= i; ++j){
			sums[a[i] + a[j] + 200000] = true;
		}
	}
	printf("%d", ans);
	return 0;
}
