#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<tuple<int, int, int>> v(n);
	for(int i = 0; i < n; ++i){
		string ramp;
		int a, b;
		cin >> ramp >> a >> b;
		if(ramp == "none"){
			v[i] = make_tuple(0, a, b);
		}else if(ramp == "on"){
			v[i] = make_tuple(1, a, b);
		}else{
			v[i] = make_tuple(-1, a, b);
		}
	}
	int min_t = 0, max_t = 0;
	min_t = -999999999;
	max_t = 999999999;
	for(int i = n - 1; i >= 0; --i){
		int t = get<0>(v[i]), a = get<1>(v[i]), b = get<2>(v[i]);
		if(t == 0){
			min_t = max(min_t, a);
			max_t = min(max_t, b);
		}else if(t == 1){
			min_t -= b;
			max_t -= a;
			min_t = max(0, min_t);
		}else{
			min_t += a;
			max_t += b;
		}
	}
	cout << min_t << ' ' << max_t << '\n';
	min_t = -999999999;
	max_t = 999999999;
	for(int i = 0; i < n; ++i){
		int t = get<0>(v[i]), a = get<1>(v[i]), b = get<2>(v[i]);
		if(t == 0){
			min_t = max(min_t, a);
			max_t = min(max_t, b);
		}else if(t == -1){
			min_t -= b;
			max_t -= a;
			min_t = max(0, min_t);
		}else{
			min_t += a;
			max_t += b;
		}
	}
	cout << min_t << ' ' << max_t << '\n';
	return 0;
}
