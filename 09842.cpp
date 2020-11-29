#include <iostream>
#include <vector>

using namespace std;

vector<int> sieve(int limit){
	vector<bool> nums(limit, true);
	nums[0] = false;
	nums[1] = false;
	for(int j = 2 * 2; j < limit; j += 2){
		nums[j] = false;
	}
	for(int p = 3; p * p < limit; p += 2){
		for(int j = p * p; j < limit; j += 2 * p){
			nums[j] = false;
		}
	}
	vector<int> ret;
	for(int i = 0; i < limit; ++i){
		if(nums[i]){
			ret.push_back(i);
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> primes = sieve(200000);
	int n;
	cin >> n;
	cout << primes[n - 1];
	return 0;
}
