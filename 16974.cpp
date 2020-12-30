#include <iostream>

using namespace std;

long long patties(int n, long long x){
	if(x <= 0){
		return 0;
	}
	if(n == 0){
		return 1;
	}
	long long ret = 0;
	--x;
	if(x < (1LL << (n + 1)) - 3){
		return patties(n - 1, x);
	}
	ret += (1LL << n) - 1;
	x -= (1LL << (n + 1)) - 3;
	if(x == 0){
		return ret;
	}
	++ret;
	--x;
	ret += patties(n - 1, x);
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	long long x;
	cin >> n >> x;
	cout << patties(n, x);
	return 0;
}
