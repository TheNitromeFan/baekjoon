#include <cstdio>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main(){
	int k, n;
	scanf("%d %d", &k, &n);
	vector<int> primes(k);
	for(int i = 0; i < k; ++i){
		scanf("%d", &primes[i]);
	}
	priority_queue<long long, vector<long long>, greater<long long>> pq;
	pq.push(1);
	for(int j = 0; j < n; ++j){
		long long x = pq.top();
		pq.pop();
		for(int prime : primes){
			long long nx = x * prime;
			pq.push(nx);
			if(x % prime == 0){
				break;
			}
		}
	}
	printf("%lld", pq.top());
	return 0;
}
