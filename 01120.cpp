#include <iostream>
#include <string>

using namespace std;

int main(){
	string a, b;
	cin >> a >> b;
	int ans = 50;
	for(int delta = 0; a.length() + delta <= b.length(); ++delta){
		int cnt = 0;
		for(int i = 0; i < a.length(); ++i){
			if(a[i] != b[i + delta]){
				++cnt;
			}
		}
		if(cnt < ans){
			ans = cnt;
		}
	}
	cout << ans;
	return 0;
}
