#include <iostream>

using namespace std;

int total_xor(int n){
	switch(n % 4){
		case 0:
			return n;
		case 1:
			return 1;
		case 2:
			return n + 1;
		case 3:
			return 0;
	}
	return -1;
}

int interval_xor(int s, int f){
	int n1 = total_xor(s - 1), n2 = total_xor(f);
	return n1 ^ n2;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int s, f;
		cin >> s >> f;
		cout << interval_xor(s, f) << '\n';
	}
	return 0;
}
