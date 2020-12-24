#include <iostream>

using namespace std;

void odd_even_count(long long a, long long b, long long &odd, long long &even){
	while(a <= b && a % 10 != 0){
		if(a % 2 == 0){
			++even;
		}else{
			++odd;
		}
		++a;
	}
	while(a <= b && b % 10 != 0){
		if(b % 2 == 0){
			++even;
		}else{
			++odd;
		}
		--b;
	}
	if(a > b){
		return;
	}
	even += (b - a) / 10 * 4;
	odd += (b - a) / 10 * 5;
	odd_even_count(a / 10, b / 10, odd, even);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long a, b;
	cin >> a >> b;
	long long odd = 0, even = 0;
	odd_even_count(a, b, odd, even);
	cout << odd << ' ' << even;
	return 0;
}
