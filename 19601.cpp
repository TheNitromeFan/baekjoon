#include <iostream>
#include <algorithm>

using namespace std;

long long bi(long long n){
	if(n == 1){
		return 0;
	}else{
		return bi(n / 2) + 1;
	}
}

long long ti(long long n){
	if(n == 1){
		return 0;
	}else if(n == 2){
		return 1;
	}else{
		return ti(n / 3) + 2;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	cin >> q;
	for(int i = 0; i < q; ++i){
		long long n;
		cin >> n;
		cout << bi(n) << ' ' << ti(n) << '\n';
	}
	return 0;
}
