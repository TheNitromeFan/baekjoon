#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> a(n), b(m);
	for(int i = 0; i < n; ++i){
		cin >> a[i].first >> a[i].second;
		if(i > 0){
			a[i].second += a[i - 1].second;
		}
	}
	for(int j = 0; j < m; ++j){
		cin >> b[j].first >> b[j].second;
		if(j > 0){
			b[j].second += b[j - 1].second;
		}
	}
	int time = 0;
	int i = 0, j = 0;
	int x = 0, y = 0;
	int lead = 0;
	int cnt = 0;
	while(i < n && j < m){
		++time;
		x += a[i].first;
		y += b[j].first;
		if(x > y){
			if(lead == 2){
				++cnt;
			}
			lead = 1;
		}else if(x < y){
			if(lead == 1){
				++cnt;
			}
			lead = 2;
		}
		if(time == a[i].second){
			++i;
		}
		if(time == b[j].second){
			++j;
		}
	}
	cout << cnt << '\n';
	return 0;
}
