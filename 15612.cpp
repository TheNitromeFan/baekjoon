#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string ternary(long long n){
	if(n == 0){
		return "0";
	}
	string ret = "";
	while(n > 0){
		ret += (char)(n % 3 + '0');
		n /= 3;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		long long vi;
		cin >> vi;
		cout << ternary(vi) << '\n';
	}
	return 0;
}
