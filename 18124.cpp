#include <iostream>

using namespace std;

long long power_of_two(long long x){
	long long ret = 1;
	while(ret <= x){
		ret *= 2;
	}
	return ret / 2;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long x;
	cin >> x;
	long long y = power_of_two(x);
	if(x == y){
		cout << x - 1;
	}else{
		cout << y - 1 + (x + 1) / 2;
	}
	return 0;
}
