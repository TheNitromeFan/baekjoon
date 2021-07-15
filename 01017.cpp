#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

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

bool bipartite_match(vector<vector<int>> &adj, vector<int> &matched, vector<bool> &visited, int u, int x, int y){
	for(int v : adj[u]){
		if(v == x || v == y){
			continue;
		}
		if(!visited[v]){
			visited[v] = true;
			if(matched[v] == -1 || bipartite_match(adj, matched, visited, matched[v], x, y)){
				matched[v] = u;
				return true;
			}
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unordered_set<int> primes;
	erathosthenes_sieve(primes, 1000 + 1000);
	int n;
	cin >> n;
	vector<int> num(n);
	for(int i = 0; i < n; ++i){
		cin >> num[i];
	}
	vector<vector<int>> adj(n);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < i; ++j){
			if(primes.find(num[j] + num[i]) != primes.end()){
				adj[j].push_back(i);
				adj[i].push_back(j);
			}
		}
	}
	vector<int> ans;
	for(int v : adj[0]){
		vector<int> matched(n, -1);
		matched[0] = v;
		matched[v] = 0;
		int cnt = 0;
		for(int u = 1; u < n; ++u){
			if(u == v){
				continue;
			}
			vector<bool> visited(n);
			if(bipartite_match(adj, matched, visited, u, 0, v)){
				++cnt;
			}
		}
		if(cnt == n - 2){
			ans.push_back(num[v]);
		}
	}
	sort(ans.begin(), ans.end());
	if(!ans.empty()){
		for(int x : ans){
			cout << x << ' ';
		}
	}else{
		cout << -1;
	}
	return 0;
}
