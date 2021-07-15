#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <complex>
#include <unordered_set>
#include <iomanip>
#define MAX 100005
#define PI acos(-1)

using namespace std;

void erathosthenes_sieve(unordered_set<int> &primes, int limit){
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
			primes.insert(i);
		}
	}
}

void fft(vector<complex<double>> &f, complex<double> w){
	vector<complex<double>>::size_type n = f.size();
	if(n == 1){
		return;
	}
	vector<complex<double>> even(n / 2), odd(n / 2);
	for(vector<complex<double>>::size_type i = 0; i < n; ++i){
		if(i % 2 == 1){
			odd[i / 2] = f[i];
		}else{
			even[i / 2] = f[i];
		}
	}
	fft(even, w * w);
	fft(odd, w * w);
	complex<double> wp(1, 0);
	for(vector<complex<double>>::size_type i = 0; i < n / 2; ++i){
		f[i] = even[i] + wp * odd[i];
		f[i + n / 2] = even[i] - wp * odd[i];
		wp *= w;
	}
}

void multiply(vector<complex<double>> &a, vector<complex<double>> &b, vector<complex<double>> &c){
	vector<complex<double>>::size_type n = 1;
	while(n <= a.size() || n <= b.size()){
		n *= 2;
	}
	n *= 2;
	a.resize(n);
	b.resize(n);
	c.resize(n);
	complex<double> w(cos(2 * PI / n), sin(2 * PI / n));
	fft(a, w);
	fft(b, w);
	for(vector<complex<double>>::size_type i = 0; i < n; ++i){
		c[i] = a[i] * b[i];
	}
	fft(c, complex<double>(1, 0) / w);
	for(vector<complex<double>>::size_type i = 0; i < n; ++i){
		c[i] /= complex<double>(n, 0);
		c[i] = complex<double>(llround(c[i].real()), llround(c[i].imag()));
	}
}

int get_size(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &sz, int u, int p){
	sz[u] = 1;
	for(int v : adj[u]){
		if(v != p && !visited[v]){
			sz[u] += get_size(adj, visited, sz, v, u);
		}
	}
	return sz[u];
}

int get_centroid(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &sz, int u, int p, int s){
	for(int v : adj[u]){
		if(v != p && !visited[v] && sz[v] > s / 2){
			return get_centroid(adj, visited, sz, v, u, s);
		}
	}
	return u;
}

void update_sub(vector<vector<int>> &adj, vector<bool> &visited, vector<long long> &subtree, int u, int p, int d, int &depth){
	depth = max(depth, d);
	++subtree[d];
	for(int v : adj[u]){
		if(v != p && !visited[v]){
			update_sub(adj, visited, subtree, v, u, d + 1, depth);
		}
	}
}

void calc(vector<long long> &cnt, vector<long long> &subtree, vector<long long> &acc){
	vector<complex<double>> a, b, c;
	for(long long x : subtree){
		a.push_back(complex<double>(x, 0));
	}
	for(long long y : acc){
		b.push_back(complex<double>(y, 0));
	}
	multiply(a, b, c);
	for(unsigned i = 1; i < MAX && i < c.size(); ++i){
		cnt[i] += llround(c[i].real());
	}
}

void solve(vector<vector<int>> &adj, vector<long long> &cnt, vector<bool> &visited, vector<int> &sz, vector<long long> &subtree, vector<long long> &acc, int u){
	int centroid = get_centroid(adj, visited, sz, u, -1, get_size(adj, visited, sz, u, -1));
	get_size(adj, visited, sz, centroid, -1);
	visited[centroid] = true;
	acc.resize(1);
	acc.reserve(sz[centroid] + 1);
	acc[0] = 1;
	sort(adj[centroid].begin(), adj[centroid].end(), [&sz](int a, int b){
		return sz[a] < sz[b];
	});
	for(int v : adj[centroid]){
		if(!visited[v]){
			int depth = 0;
			subtree.clear();
			subtree.resize(sz[v] + 1);
			update_sub(adj, visited, subtree, u, centroid, 1, depth);
			calc(cnt, subtree, acc);
			if(acc.size() <= depth){
				acc.resize(depth + 1);
			}
			for(int j = 0; j <= depth; ++j){
				acc[j] += subtree[j];
			}
		}
	}
	for(int v : adj[centroid]){
		if(!visited[v]){
			solve(adj, cnt, visited, sz, subtree, acc, v);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unordered_set<int> primes;
	erathosthenes_sieve(primes, MAX);
	long long n;
	cin >> n;
	vector<vector<int>> adj(n + 1);
	for(long long i = 0; i < n - 1; ++i){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<long long> cnt(MAX);
	vector<bool> visited(MAX);
	vector<int> sz(MAX);
	vector<long long> subtree, acc;
	solve(adj, cnt, visited, sz, subtree, acc, 1);
	long long sum = 0;
	for(long long i = 1; i <= n; ++i){
		if(primes.find(i) != primes.end()){
			sum += cnt[i];
		}
	}
	cout << fixed << setprecision(10) << sum / (double)(n * (n - 1) / 2);
	return 0;
}
