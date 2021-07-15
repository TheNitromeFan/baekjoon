#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 1; a0 <= t; ++a0){
		int n, m;
		cin >> n >> m;
		vector<tuple<int, int, int>> v(n + m);
		int free0 = 720, free1 = 720;
		for(int i = 0; i < n; ++i){
			int start, end;
			cin >> start >> end;
			free0 -= end - start;
			v[i] = make_tuple(start, end, 0);
		}
		for(int i = n; i < n + m; ++i){
			int start, end;
			cin >> start >> end;
			free1 -= end - start;
			v[i] = make_tuple(start, end, 1);
		}
		sort(v.begin(), v.end());
		unsigned alternate = 0;
		vector<int> a, b;
		for(int i = 0; i < n + m; ++i){
			int j = (i + 1) % (n + m);
			if(get<2>(v[i]) != get<2>(v[j])){
				++alternate;
			}else if(get<2>(v[i]) == 0){
				a.push_back((get<0>(v[j]) + 1440 - get<1>(v[i])) % 1440);
			}else{
				b.push_back((get<0>(v[j]) + 1440 - get<1>(v[i])) % 1440);
			}
		}
		sort(a.begin(), a.end(), greater<int>());
		sort(b.begin(), b.end(), greater<int>());
		while(!a.empty() && a.back() <= free0){
			free0 -= a.back();
			a.pop_back();
		}
		while(!b.empty() && b.back() <= free1){
			free1 -= b.back();
			b.pop_back();
		}
		unsigned ans = alternate + 2 * max(a.size(), b.size());
		cout << "Case #" << a0 << ": " << ans << "\n";
	}
	return 0;
}
