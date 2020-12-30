#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int x;
	cin >> x;
	int ans = 1;
	for(int i = 0; i < n - 1; ++i){
		cin >> x;
		if(x == 0){
			++ans;
			++ans;
			continue;
		}
		++ans;
		while(x > 0){
			++ans;
			x /= 10;
		}
		++ans;
		++ans;
	}
	cin >> x;
	if(x > 0){
		++ans;
	}
	while(x > 0){
		++ans;
		x /= 10;
	}
	++ans;
	cout << ans;
	return 0;
}
