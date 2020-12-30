#include <iostream>

using namespace std;

bool win(long long n){
	long long p = 1;
	while(p * 18 <= n){
		p *= 18;
	}
	return n > p && n <= p * 9;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	while(cin >> n){
		cout << (win(n) ? "Baekjoon" : "Donghyuk") << " wins.\n";
	}
	return 0;
}
