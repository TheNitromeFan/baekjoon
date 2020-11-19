#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n, x;
	cin >> n >> x;
	int a[100000];
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	sort(a, a + n);
	int cnt = 1;
	for(int i = 0; i + 1 < n; ++i){
		if(a[i] + a[i + 1] > x){
			break;
		}
		++cnt;
	}
	cout << cnt;
	return 0;
}
