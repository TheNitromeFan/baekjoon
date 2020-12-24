#include <iostream>
#include <queue>
#include <map>
#include <string>

using namespace std;

void bfs(long long s, long long t, map<long long, long long> &prev){
	queue<long long> q;
	q.push(s);
	prev[s] = 0;
	while(!q.empty()){
		long long x = q.front();
		q.pop();
		if(x == t){
			return;
		}
		if(x > 2000000000LL){
			continue;
		}
		if(prev.find(x * x) == prev.end()){
			q.push(x * x);
			prev[x * x] = x;
		}
		if(prev.find(x + x) == prev.end()){
			q.push(x + x);
			prev[x + x] = x;
		}
		if(prev.find(x - x) == prev.end()){
			q.push(x - x);
			prev[x - x] = x;
		}
		if(x != 0 && prev.find(x / x) == prev.end()){
			q.push(x / x);
			prev[x / x] = x;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long s, t;
	cin >> s >> t;
	map<long long, long long> prev;
	bfs(s, t, prev);
	if(prev.find(t) != prev.end()){
		string ans = "";
		while(t != s){
			long long v = prev[t];
			if(v * v == t){
				ans = "*" + ans;
			}else if(v + v == t){
				ans = "+" + ans;
			}else if(v - v == t){
				ans = "-" + ans;
			}else if(v != 0 && v / v == t){
				ans = "/" + ans;
			}
			t = v;
		}
		if(ans == ""){
			ans = "0";
		}
		cout << ans;
	}else{
		cout << "-1";
	}
	return 0;
}
