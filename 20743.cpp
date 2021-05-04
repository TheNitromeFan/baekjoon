#include <iostream>

using namespace std;

int sum_of_two_cubes(int n){
	int ret = 0;
	for(int a = 1; a * a * a < n; ++a){
		for(int b = a; a * a * a + b * b * b <= n; ++b){
			if(a * a * a + b * b * b == n){
				++ret;
			}
		}
	}
	return ret;
}

bool bus(int n){
	return sum_of_two_cubes(n) >= 2;
}

bool maximum_bus(int m, int &n){
	for(n = m; n >= 1; --n){
		if(bus(n)){
			return true;
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m;
	cin >> m;
	int n;
	if(maximum_bus(m, n)){
		cout << n;
	}else{
		cout << "none";
	}
	return 0;
}
