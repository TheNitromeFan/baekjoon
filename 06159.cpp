#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, len;
	cin >> n >> len;
	int a[20000];
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < i; ++j){
			if(a[j] + a[i] <= len){
				++cnt;
			}
		}
	}
	cout << cnt;
	return 0;
}
