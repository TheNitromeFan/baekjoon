#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#define MAX 1000000

using namespace std;

void generate_primes(unordered_set<long long> &primes, long long limit){
	vector<bool> is_prime(limit + 1, true);
	is_prime[0] = false;
	is_prime[1] = false;
	for(long long i = 4; i <= limit; i += 2){
		is_prime[i] = false;
	}
	for(long long p = 3; p * p <= limit; p += 2){
		for(long long i = p * p; i <= limit; i += 2 * p){
			is_prime[i] = false;
		}
	}
	for(long long i = 0; i <= limit; ++i){
		if(is_prime[i]){
			primes.insert(i);
		}
	}
}

void generate_squares(unordered_set<long long> &squares, long long limit){
	for(long long i = 1; i * i <= limit; ++i){
		squares.insert(i * i);
	}
}

void generate_cubes(unordered_set<long long> &cubes, long long limit){
	for(int i = 1; i * i * i <= limit; ++i){
		cubes.insert(i * i * i);
	}
}

void generate_quads(unordered_set<long long> &quads, long long limit){
	for(int i = 1; i * i * i * i <= limit; ++i){
		quads.insert(i * i * i * i);
	}
}

int sum_of_digits(long long n){
	int ret = 0;
	while(n){
		ret += n % 10;
		n /= 10;
	}
	return ret;
}

int product_of_digits(long long n){
	int ret = 1;
	while(n){
		ret *= n % 10;
		n /= 10;
	}
	return ret;
}

void solve(vector<long long> &v, int n, unordered_set<long long> &primes, unordered_set<long long> &squares, unordered_set<long long> &cubes, unordered_set<long long> &quads){
	vector<int> sums_of_digits(n), products_of_digits(n);
	for(int i = 0; i < n; ++i){
		sums_of_digits[i] = sum_of_digits(v[i]);
		products_of_digits[i] = product_of_digits(v[i]);
	}
	vector<int> attr(n);
	for(int i = 0; i < n; ++i){
		if(primes.find(v[i]) != primes.end()){
			// cout << 1 << ' ';
			++attr[i];
		}
		if(squares.find(v[i]) != squares.end()){
			// cout << 2 << ' ';
			++attr[i];
		}
		if(cubes.find(v[i]) != cubes.end()){
			// cout << 3 << ' ';
			++attr[i];
		}
		if(quads.find(v[i]) != quads.end()){
			// cout << 4 << ' ';
			++attr[i];
		}
		if(v[i] % sums_of_digits[i] == 0){
			// cout << 5 << ' ';
			++attr[i];
		}
		if(products_of_digits[i] != 0 && v[i] % products_of_digits[i] == 0){
			// cout << 6 << ' ';
			++attr[i];
		}
		for(int j = 0; j < n; ++j){
			if(j != i && v[j] % v[i] == 0){
				// cout << 7 << ' ';
				++attr[i];
				break;
			}
		}
		for(int j = 0; j < n; ++j){
			if(j != i && v[i] % v[j] == 0){
				// cout << 8 << ' ';
				++attr[i];
				break;
			}
		}
		for(int j = 0; j < n; ++j){
			if(j != i && v[i] == v[j] * v[j]){
				// cout << 9 << ' ';
				++attr[i];
				break;
			}
		}
		for(int j = 0; j < n; ++j){
			if(j != i && v[i] == v[j] * v[j] * v[j]){
				// cout << 10 << ' ';
				++attr[i];
				break;
			}
		}
		for(int j = 0; j < n; ++j){
			if(j != i && v[i] == v[j] * v[j] * v[j] * v[j]){
				// cout << 11 << ' ';
				++attr[i];
				break;
			}
		}
		for(int j = 0; j < n; ++j){
			if(j != i && v[i] % sums_of_digits[j] == 0){
				// cout << 12 << ' ';
				++attr[i];
				break;
			}
		}
		for(int j = 0; j < n; ++j){
			if(j != i && products_of_digits[j] != 0 && v[i] % products_of_digits[j] == 0){
				// cout << 13 << ' ';
				++attr[i];
				break;
			}
		}
		// cout << attr[i] << '\n';
	}
	vector<int> indices(n);
	for(int i = 0; i < n; ++i){
		indices[i] = i;
	}
	sort(indices.begin(), indices.end(), [&v, &attr](int a, int b){
		return attr[a] > attr[b]
		|| (attr[a] == attr[b] && v[a] < v[b]);
	});
	int idx = 0;
	while(idx < n && attr[indices[idx]] == attr[indices[0]]){
		cout << v[indices[idx]] << '\n';
		++idx;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unordered_set<long long> primes, squares, cubes, quads;
	generate_primes(primes, MAX);
	generate_squares(squares, MAX);
	generate_cubes(cubes, MAX);
	generate_quads(quads, MAX);
	int n;
	cin >> n;
	for(int t = 1; t <= n; ++t){
		int m;
		cin >> m;
		vector<long long> v(m);
		for(int i = 0; i < m; ++i){
			cin >> v[i];
		}
		cout << "DATA SET #" << t << "\n";
		solve(v, m, primes, squares, cubes, quads);
	}
	return 0;
}
