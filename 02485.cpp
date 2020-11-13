#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	vector<int> a(n, 0);
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	sort(a.begin(), a.end());
	int dist = a[1] - a[0];
	for(int i = 2; i < n; ++i){
		dist = gcd(dist, a[i] - a[i - 1]);
	}
	printf("%d", (a[n - 1] - a[0]) / dist - n + 1);
	return 0;
}
