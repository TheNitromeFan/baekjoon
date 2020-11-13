#include <iostream>
#include <string>
#define MOD 26

using namespace std;

long long pow(long long a, long long b){
	if(a == 0){
		return 0;
	}
	if(b == 0){
		return 1;
	}else if(b % 2 == 0){
		long long x = pow(a, b / 2);
		return x * x % MOD;
	}else{
		long long x = pow(a, b / 2);
		return x * x * a % MOD;
	}
}

int main(){
	int n;
	long long a, b;
	cin >> n >> a >> b;
	a %= MOD;
	b = (b - 1) % 12 + 1;
	int p = (int)pow(a, b);
	string line;
	getline(cin, line);
	getline(cin, line);
	for(char &c : line){
		if(c >= 'A' && c <= 'Z'){
			c -= p;
			if(c < 'A'){
				c += MOD;
			}
		}
	}
	cout << line;
	return 0;
}
