#include <iostream>

using namespace std;

int main(){
	int n, a, d;
	cin >> n >> a >> d;
	int ans = 0;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		if(x == a){
			++ans;
			a += d;
		}
	}
	cout << ans;
	return 0;
}
