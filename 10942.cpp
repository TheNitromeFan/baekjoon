#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int arr[2001];
	for(int i = 1; i <= n; ++i){
		scanf("%d", &arr[i]);
	}
	static bool palindrome[2001][2001];
	for(int i = 1; i <= n; ++i){
		palindrome[i][i] = true;
	}
	for(int i = 1; i < n; ++i){
		if(arr[i] == arr[i+1]){
			palindrome[i][i+1] = true;
		}
	}
	for(int len = 3; len <= n; ++len){
		for(int i = 1; i <= n - len + 1; ++i){
			int j = len - 1 + i;
			if(palindrome[i+1][j-1] && arr[i] == arr[j]){
				palindrome[i][j] = true;
			}
		}
	}
	int m;
	scanf("%d", &m);
	for(int t = 0; t < m; ++t){
		int start, end;
		scanf("%d %d", &start, &end);
		printf("%d\n", palindrome[start][end]);
	}
	return 0;
}
