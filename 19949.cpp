#include <iostream>
#include <vector>

using namespace std;

void guess(vector<int> &v, int pos, int points, int &ways, int prev, int prevprev){
	if(pos == 10){
		if(points >= 5){
			++ways;
		}
		return;
	}
	for(int i = 1; i <= 5; ++i){
		if(i == prev && i == prevprev){
			continue;
		}
		if(v[pos] == i){
			++points;
			guess(v, pos + 1, points, ways, i, prev);
			--points;
		}else{
			guess(v, pos + 1, points, ways, i, prev);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> v(10);
	for(int i = 0; i < 10; ++i){
		cin >> v[i];
	}
	int ans = 0;
	guess(v, 0, 0, ans, 0, 0);
	cout << ans;
	return 0;
}
