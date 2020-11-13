#include <cstdio>
#include <cstring>
#include <vector>
#define LIMIT 42000

using namespace std;

vector<long long> prime_square_sieve(){
	bool prime[LIMIT];
	memset(prime, true, sizeof(prime));
	prime[0] = false;
	prime[1] = false;
	for(int p = 2; p * p < LIMIT; ++p){
		if(!prime[p]){
			continue;
		}
		for(int m = p; m * p < LIMIT; ++m){
			prime[m * p] = false;
		}
	}
	vector<long long> ret;
	for(long long i = 2; i < LIMIT; ++i){
		if(prime[i]){
			ret.push_back(i * i);
		}
	}
	return ret;
}

bool is_divisible_by_square(vector<long long> &squares, int n){
	for(int idx = 0; squares[idx] <= n; ++idx){
		if(n % squares[idx] == 0){
			return true;
		}
	}
	return false;
}

int main(){
	vector<long long> squares = prime_square_sieve();
	long long a;
	scanf("%lld", &a);
	long long low = a, high = a * 2, mid;
	while(low <= high){
		mid = (low + high) / 2;
		long long sum = 0;
		for(int i = 0; squares[i] <= mid; ++i){
			sum += mid / squares[i];
			for(int j = 0; j < i && squares[j] * squares[i] <= mid; ++j){
				sum -= mid / (squares[j] * squares[i]);
				for(int k = 0; k < j && squares[k] * squares[j] * squares[i] <= mid; ++k){
					sum += mid / (squares[k] * squares[j] * squares[i]);
					for(int l = 0; l < k && squares[l] * squares[k] * squares[j] * squares[i] <= mid; ++l){
						sum -= mid / (squares[l] * squares[k] * squares[j] * squares[i]);
						for(int m = 0; m < l && squares[m] * squares[l] * squares[k] * squares[j] * squares[i] <= mid; ++m){
							sum += mid / (squares[m] * squares[l] * squares[k] * squares[j] * squares[i]);
							for(int n = 0; n < m && squares[n] * squares[m] * squares[l] * squares[k] * squares[j] * squares[i] <= mid; ++n){
								sum -= mid / (squares[n] * squares[m] * squares[l] * squares[k] * squares[j] * squares[i]);
							}
						}
					}
				}
			}
		}
		if(mid - sum == a){
			break;
		}else if(mid - sum < a){
			low = mid + 1;
		}else{
			high = mid - 1;
		}
	}
	while(is_divisible_by_square(squares, mid)){
		--mid;
	}
	printf("%lld", mid);
	return 0;
}
