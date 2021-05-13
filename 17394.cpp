#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

void erathosthenes_sieve(vector<int> &primes, int n){
	vector<bool> is_prime(n + 1, true);
	is_prime[0] = false;
	is_prime[1] = false;
	for(int i = 4; i <= n; i += 2){
		is_prime[i] = false;
	}
	for(int p = 3; p * p <= n; p += 2){
		for(int i = 3 * p; i <= n; i += p){
			is_prime[i] = false;
		}
	}
	for(int i = 0; i <= n; ++i){
		if(is_prime[i]){
			primes.push_back(i);
		}
	}
}

int snaps(unordered_set<int> &targets, int n){
	queue<int> q;
	unordered_map<int, int> visited;
	q.push(n);
	visited[n] = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		if(targets.find(x) != targets.end()){
			return visited[x];
		}
		if(visited.find(x / 2) == visited.end()){
			q.push(x / 2);
			visited[x / 2] = visited[x] + 1;
		}
		if(visited.find(x / 3) == visited.end()){
			q.push(x / 3);
			visited[x / 3] = visited[x] + 1;
		}
		if(visited.find(x + 1) == visited.end()){
			q.push(x + 1);
			visited[x + 1] = visited[x] + 1;
		}
		if(x > 0 && visited.find(x - 1) == visited.end()){
			q.push(x - 1);
			visited[x - 1] = visited[x] + 1;
		}
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> primes;
	erathosthenes_sieve(primes, 100000);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n, a, b;
		cin >> n >> a >> b;
		unordered_set<int> filtered_primes;
		for(int p : primes){
			if(p > b){
				break;
			}else if(p >= a){
				filtered_primes.insert(p);
			}
		}
		if(filtered_primes.empty()){
			cout << -1 << '\n';
			continue;
		}
		cout << snaps(filtered_primes, n) << '\n';
	}
	return 0;
}
