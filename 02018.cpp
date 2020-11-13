#include <iostream>

using namespace std;

int main(){
	int s;
	cin >> s;
	s *= 2;
	int ans = 0;
	for(int n = 1; n * (n + 1) <= s; ++n){
		if(s % n == 0 && (s / n - n) % 2 == 1){
			++ans;
		}
	}
	cout << ans << endl;
	return 0;
}
