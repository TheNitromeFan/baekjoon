#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int points[31] = {0, 100, 75, 60, 50, 45, 40, 36, 32, 29,
	26, 24, 22, 20, 18, 16, 15, 14, 13, 12,
	11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int n;
	cin >> n;
	vector<tuple<int, int, int, int, int>> v(n);
	for(int i = 0; i < n; ++i){
		int s, p, f, o;
		cin >> s >> p >> f >> o;
		v[i] = make_tuple(i, s, p, f, o);
	}
	sort(v.begin(), v.end(), [](tuple<int, int, int, int, int> a, tuple<int, int, int, int, int> b){
		return get<1>(a) > get<1>(b)
		|| (get<1>(a) == get<1>(b) && get<2>(a) < get<2>(b))
		|| (get<1>(a) == get<1>(b) && get<2>(a) == get<2>(b) && get<3>(a) < get<3>(b));
	});
	int idx = 0;
	int rank = 1;
	vector<tuple<int, int>> scores(n);
	while(idx < n){
		int start = idx;
		int sum = 0;
		int cnt = 0;
		while(idx < n && get<1>(v[idx]) == get<1>(v[start])
		&& get<2>(v[idx]) == get<2>(v[start]) && get<3>(v[idx]) == get<3>(v[start])){
			++cnt;
			if(rank <= 30){
				sum += points[rank];
			}
			++rank;
			++idx;
		}
		int avg = (sum % cnt == 0) ? sum / cnt : sum / cnt + 1;
		for(int x = start; x < idx; ++x){
			scores[x] = make_tuple(get<0>(v[x]), avg + get<4>(v[x]));
		}
	}
	sort(scores.begin(), scores.end());
	for(tuple<int, int> t : scores){
		cout << get<1>(t) << '\n';
	}
	return 0;
}
