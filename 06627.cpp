#include <iostream>

using namespace std;

int sum_of_digits(long long x){
	int ret = 0;
	while(x > 0){
		ret += x % 10;
		x /= 10;
	}
	return ret;
}

long long p(int n){
	long long ret = 11;
	int cmp = sum_of_digits(n);
	while(sum_of_digits(ret * n) != cmp){
		++ret;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int n;
		cin >> n;
		if(n == 0){
			break;
		}
		cout << p(n) << '\n';
	}
	return 0;
}
