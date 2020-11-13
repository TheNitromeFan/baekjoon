#include <cstdio>
#include <vector>
#define MAX 30

using std::vector;

void brute_force(int a[MAX], int idx, int n, int c, int sum, vector<int> &v){
	if(sum > c){
		return;
	}
	if(idx == n){
		v.push_back(sum);
		return;
	}
	brute_force(a, idx + 1, n, c, sum, v);
	brute_force(a, idx + 1, n, c, sum + a[idx], v);
}

int main(){
	int n, c;
	scanf("%d %d", &n, &c);
	int a[MAX];
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	vector<int> v1, v2;
	brute_force(a, 0, n / 2, c, 0, v1);
	brute_force(a, n / 2, n, c, 0, v2);
	int ans = 0;
	for(int x : v1){
		for(int y : v2){
			if(x + y <= c){
				++ans;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
