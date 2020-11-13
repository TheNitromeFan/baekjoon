#include <iostream>
#include <string>
#define MOD 1000000007

using namespace std;

int main(){
	int n;
	string s;
	cin >> n >> s;
	long long a = 0, c = 0, g = 0, t = 0;
	for(char x : s){
		switch(x){
			case 'A':
				++a;
				break;
			case 'C':
				++c;
				break;
			case 'G':
				++g;
				break;
			case 'T':
				++t;
				break;
		}
	}
	cout << (((a * c) % MOD) * ((g * t) % MOD) % MOD);
	return 0;
}
