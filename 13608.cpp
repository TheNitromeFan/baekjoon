#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int n;
		cin >> n;
		if(n == 0){
			break;
		}
		int ans = 0;
		bool leftover = false;
		for(int i = 0; i < n; ++i){
			int c, m;
			cin >> c >> m;
			ans += m / 4;
			m %= 4;
			if(m >= 2){
				if(leftover){
					++ans;
					leftover = false;
				}else{
					leftover = true;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
