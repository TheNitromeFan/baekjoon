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
	long long a, b;
	cin >> a >> b;
	if(a > b){
		swap(a, b);
	}
	cout << (win(a, b) ? "win" : "lose") << '\n';
	return 0;
}
