#include <iostream>
#include <queue>

using namespace std;

long long smallest_x(int n){
	queue<long long> q;
	q.push(1);
	while(!q.empty()){
		long long x = q.front();
		q.pop();
		if(x % n == 0){
			return x;
		}
		q.push(10 * x);
		q.push(10 * x + 1);
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int n;
		cin >> n;
		cout << smallest_x(n) << '\n';
	}
	return 0;
}
