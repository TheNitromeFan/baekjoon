#include <iostream>
#include <algorithm>

using namespace std;

bool win(long long a, long long b){
	if(b % a == 0 || b > 2 * a){
		return true;
	}
	return !win(b % a, a);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		long long a, b;
		cin >> a >> b;
		if(a == 0 && b == 0){
			break;
		}
		if(a > b){
			swap(a, b);
		}
		cout << (win(a, b) ? 'A' : 'B') << " wins\n";
	}
	return 0;
}
