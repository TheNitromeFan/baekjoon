#include <iostream>

using namespace std;

bool is_palindrome(int x){
	int y = 0, z = x;
	while(z > 0){
		y *= 10;
		y += z % 10;
		z /= 10;
	}
	return x == y;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	long long sum = 0;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		if(is_palindrome(x)){
			sum += x;
		}
	}
	cout << sum;
	return 0;
}
