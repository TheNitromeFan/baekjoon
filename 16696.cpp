#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int relocations(int b, long long start){
	queue<long long> q;
	unordered_map<long long, int> m;
	q.push(start);
	m[start] = 0;
	while(!q.empty()){
		long long x = q.front();
		q.pop();
		cout << x << '\n';
		if(x == (1LL << b) - 1){
			return m[x];
		}
		for(int k = 1; k < b; ++k){
			long long nx = x | (x >> k);
			if(m.find(nx) == m.end()){
				q.push(nx);
				m[nx] = m[x] + 1;
			}
		}
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long x = 0;
	char c;
	int b = 0;
	while(cin >> c){
		x <<= 1;
		x += c - '0';
		++b;
	}
	cout << relocations(b, x);
	return 0;
}
