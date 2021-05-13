#include <iostream>
#include <algorithm>

using namespace std;

bool unique_digits(int a, int b){
	bool used[10] = {};
	while(a > 0){
		if(used[a % 10]){
			return false;
		}
		used[a % 10] = true;
		a /= 10;
	}
	while(b > 0){
		if(used[b % 10]){
			return false;
		}
		used[b % 10] = true;
		b /= 10;
	}
	return true;
}

bool stickers(int n, int &a, int &b){
	int limit = min(87654, n / 2);
	for(a = 1; a <= limit; ++a){
		b = n - a;
		if(unique_digits(a, b)){
			return true;
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int a, b;
	if(stickers(n, a, b)){
		cout << a << " + " << b;
	}else{
		cout << -1;
	}
	return 0;
}
