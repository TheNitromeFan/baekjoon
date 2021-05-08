#include <iostream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<long long> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	stack<pair<long long, long long>> s;
	long long ans = 0;
	for(int i = 0; i < n; ++i){
		long long cnt = 1;
		while(!s.empty() && s.top().first <= v[i]){
			if(s.top().first == v[i]){
				ans += s.top().second;
				cnt = s.top().second + 1;
				s.pop();
			}else{
				ans += s.top().second;
				s.pop();
				cnt = 1;
			}
		}
		if(!s.empty()){
			++ans;
		}
		s.push(make_pair(v[i], cnt));
	}
	cout << ans;
	return 0;
}
