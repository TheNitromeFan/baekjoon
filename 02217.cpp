#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int arr[100001];
	for(int i = 1; i <= n; ++i){
		scanf("%d", &arr[i]);
	}
	sort(arr+1, arr+n+1, greater<int>());
	int mx = 0;
	for(int i = 1; i <= n; ++i){
		if(i * arr[i] > mx){
			mx = i * arr[i];
		}
	}
	printf("%d", mx);
	return 0;
}
