#include <iostream>

using namespace std;

long long index(long long p, long long q){
	if(p == 1 && q == 1){
		return 0;
	}else if(p < q){
		return 2 * index(p, q - p) + 1;
	}else{
		return 2 * index(p - q, q) + 2;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		long long p, q;
		char c;
		cin >> p >> c >> q;
		cout << index(p, q) + 1 << '\n';
	}
	return 0;
}
