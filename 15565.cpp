#include <iostream>
#include <vector>

using namespace std;

int smallest_window(vector<int> &a, int n, int k, int cnt){
	if(cnt < k){
		return -1;
	}
	int j = 0, i = 0;
	int ans = n + 2;
	int lions = 0;
	while(true){
		if(a[i] == 1){
			++lions;
		}
		if(lions == k){
			break;
		}
		++i;
	}
	while(a[j] == 2){
		++j;
	}
	while(i < n){
		if(ans > i - j + 1){
			ans = i - j + 1;
		}
		do{
			++i;
		}while(i < n && a[i] == 2);
		do{
			++j;
		}while(a[j] == 2);
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> dolls(n);
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		cin >> dolls[i];
		if(dolls[i] == 1){
			++cnt;
		}
	}
	cout << smallest_window(dolls, n, k, cnt);
	return 0;
}
