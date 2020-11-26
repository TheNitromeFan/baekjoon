#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool prime(int x){
	for(int i = 2; i * i <= x; ++i){
		if(x % i == 0){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, c;
	while(cin >> n >> c){
		vector<int> primes;
		for(int i = 1; i <= n; ++i){
			if(prime(i)){
				primes.push_back(i);
			}
		}
		cout << n << " " << c << ":";
		if(primes.size() % 2 == 1){
			int mid = (int)primes.size() / 2;
			for(int j = max(mid - c + 1, 0); j <= min(mid + c - 1, (int)primes.size() - 1); ++j){
				cout << " " << primes[j];
			}
		}else{
			int mid = (int)primes.size() / 2;
			for(int j = max(mid - c, 0); j <= min(mid + c - 1, (int)primes.size() - 1); ++j){
				cout << " " << primes[j];
			}
		}
		cout << "\n\n";
	}
	return 0;
}
