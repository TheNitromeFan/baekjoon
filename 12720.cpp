#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

long long find_parent(unordered_map<long long, long long> &parent, long long x){
	if(parent[x] == x){
		return x;
	}else{
		parent[x] = find_parent(parent, parent[x]);
		return parent[x];
	}
}

void unite(unordered_map<long long, long long> &parent, long long x, long long y){
	long long px = find_parent(parent, x);
	long long py = find_parent(parent, y);
	parent[py] = px;
}

void erathosthenes_sieve(vector<int> &ret, int limit){
	vector<bool> is_prime(limit + 1, true);
	is_prime[0] = false;
	is_prime[1] = false;
	for(int i = 4; i <= limit; i += 2){
		is_prime[i] = false;
	}
	for(int p = 3; p * p <= limit; p += 2){
		for(int i = p * p; i <= limit; i += 2 * p){
			is_prime[i] = false;
		}
	}
	for(int i = 0; i <= limit; ++i){
		if(is_prime[i]){
			ret.push_back(i);
		}
	}
}

unsigned find_index(vector<int> &vec, int val){
	unsigned low = 0, high = vec.size() - 1;
	while(low < high){
		unsigned mid = (low + high) / 2;
		if(vec[mid] >= val){
			high = mid;
		}else{
			low = mid + 1;
		}
	}
	return low;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> primes;
	erathosthenes_sieve(primes, 1000005);
	int t;
	cin >> t;
	for(int a0 = 1; a0 <= t; ++a0){
		long long a, b, p;
		cin >> a >> b >> p;
		unordered_map<long long, long long> parent;
		for(long long x = a; x <= b; ++x){
			parent[x] = x;
		}
		long long comps = b - a + 1;
		unsigned idx1 = find_index(primes, p);
		unsigned idx2 = find_index(primes, b - a + 1);
		for(unsigned idx = idx1; idx <= idx2; ++idx){
			int prime = primes[idx];
			long long start = (a / prime) * prime;
			if(start < a){
				start += prime;
			}
			for(long long i = start + prime; i <= b; i += prime){
				if(find_parent(parent, i) != find_parent(parent, start)){
					unite(parent, i, start);
					--comps;
				}
			}
		}
		cout << "Case #" << a0 << ": " << comps << "\n";
	}
	return 0;
}
