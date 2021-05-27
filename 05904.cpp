#include <iostream>

using namespace std;

long long s[31];

char moo(int n){
	if(n == 1){
		return 'm';
	}else if(n <= 3){
		return 'o';
	}
	int idx = 0;
	while(n > s[idx]){
		++idx;
	}
	if(n <= s[idx] - s[idx - 1]){
		if(n == s[idx - 1] + 1){
			return 'm';
		}else{
			return 'o';
		}
	}
	return moo(n - s[idx - 1] - idx - 3);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	s[0] = 3;
	for(int i = 1; i < 31; ++i){
		s[i] = 2 * s[i - 1] + i + 3;
	}
	int n;
	cin >> n;
	cout << moo(n);
	return 0;
}
