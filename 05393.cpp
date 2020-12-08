#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		cin >> n;
		int ans = 5 * (n / 6);
		switch(n % 6){
			case 5:
				++ans;
			case 3:
				++ans;
			case 4:
				++ans;
			case 2:
			case 1:
				++ans;
				++ans;
				break;
		}
		cout << ans << '\n';
	}
	return 0;
}
