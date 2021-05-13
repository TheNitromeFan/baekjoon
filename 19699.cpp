#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool is_prime(int x){
	if(x == 1){
		return false;
	}
	for(int p = 2; p * p <= x; ++p){
		if(x % p == 0){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> cows(n);
	for(int i = 0; i < n; ++i){
		cin >> cows[i];
	}
	vector<int> bitmask(m, 1);
	bitmask.resize(n);
	set<int> primes;
	do{
		int sum = 0;
		for(int i = 0; i < n; ++i){
			if(bitmask[i]){
				sum += cows[i];
			}
		}
		if(is_prime(sum)){
			primes.insert(sum);
		}
	}while(prev_permutation(bitmask.begin(), bitmask.end()));
	if(!primes.empty()){
		for(int prime : primes){
			cout << prime << ' ';
		}
	}else{
		cout << -1;
	}
	return 0;
}
