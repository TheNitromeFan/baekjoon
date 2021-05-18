#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

void erathosthenes_sieve(unordered_set<int> &res, int n){
	vector<bool> is_prime(n + 1, true);
	is_prime[0] = false;
	is_prime[1] = false;
	for(int i = 4; i <= n; i += 2){
		is_prime[i] = false;
	}
	for(int p = 3; p * p <= n; ++p){
		for(int i = 3 * p; i <= n; i += p){
			is_prime[i] = false;
		}
	}
	for(int i = 0; i <= n; ++i){
		if(is_prime[i]){
			res.insert(i);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unordered_set<int> primes;
	erathosthenes_sieve(primes, 5000000);
	int n;
	cin >> n;
	long long p1 = 0, p2 = 0;
	unordered_set<int> pr1, pr2;
	priority_queue<int> q1, q2;
	for(int i = 0; i < n; ++i){
		int a;
		cin >> a;
		if(primes.find(a) == primes.end()){
			if(q2.size() >= 3){
				int x = q2.top();
				q2.pop();
				int y = q2.top();
				q2.pop();
				p2 += q2.top();
				q2.push(x);
				q2.push(y);
			}else{
				p2 += 1000;
			}
		}else if(pr1.find(a) != pr1.end() || pr2.find(a) != pr1.end()){
			p1 -= 1000;
		}else{
			pr1.insert(a);
			q1.push(a);
		}
		int b;
		cin >> b;
		if(primes.find(b) == primes.end()){
			if(q1.size() >= 3){
				int x = q1.top();
				q1.pop();
				int y = q1.top();
				q1.pop();
				p1 += q1.top();
				q1.push(x);
				q1.push(y);
			}else{
				p1 += 1000;
			}
		}else if(pr1.find(b) != pr1.end() || pr2.find(b) != pr2.end()){
			p2 -= 1000;
		}else{
			pr2.insert(b);
			q2.push(b);
		}
		// cout << p1 << ' ' << p2 << '\n';
	}
	if(p1 > p2){
		cout << "소수의 신 갓대웅";
	}else if(p1 < p2){
		cout << "소수 마스터 갓규성";
	}else{
		cout << "우열을 가릴 수 없음";
	}
	return 0;
}
