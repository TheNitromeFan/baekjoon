#include <iostream>

using namespace std;

int frobenius(int a, int b, int c, int d, int &cnt){
	bool comb[1111111] = {};
	comb[0] = true;
	for(int i = 1; i < 1111111; ++i){
		if((i >= a && comb[i - a]) || (i >= b && comb[i - b]) || (i >= c && comb[i - c]) || (i >= d && comb[i - d])){
			comb[i] = true;
		}
	}
	int ans = 1;
	for(int i = 0; i <= 1000000; ++i){
		if(!comb[i]){
			++cnt;
			ans = i;
		}
	}
	for(int i = 1000001; i < 1111111; ++i){
		if(!comb[i]){
			return -1;
		}
	}
	return ans;
}

int main(){
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int cnt = 0;
		int f = frobenius(a, b, c, d, cnt);
		cout << cnt << '\n' << f << '\n';
	}
	return 0;
}
