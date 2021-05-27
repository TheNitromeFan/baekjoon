#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool echo(string &s1, string &s2, unsigned k){
	for(unsigned i = 0; i < k; ++i){
		if(s1[s1.length() - k + i] != s2[i]){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s1, s2;
	cin >> s1 >> s2;
	unsigned k = min(s1.length(), s2.length());
	for(; k > 0; --k){
		if(echo(s1, s2, k) || echo(s2, s1, k)){
			break;
		}
	}
	cout << k;
	return 0;
}
