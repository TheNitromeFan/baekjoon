#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		string s;
		cin >> s;
		int n = 0;
		for(char c : s){
			if(c == '.'){
				continue;
			}
			n = n * 10 + (c - '0');
		}
		int ans = 100000;
		for(int i = 1; i <= n; ++i){
			int left = 0, right = i;
			while(left < right){
				int middle = (left + right) / 2;
				double cmp = (double)middle / i * 100000 + 0.5;
				if(n <= (int)cmp){
					right = middle;
				}else{
					left = middle + 1;
				}
			}
			double cmp = (double)left / i * 100000 + 0.5;
			if(n == (int)cmp){
				ans = i;
				break;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
