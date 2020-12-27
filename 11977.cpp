#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int explosions(vector<int> &bales, int n, int i){
	int left = i, right = i, radius;
	radius = 1;
	while(true){
		int new_left = left - 1;
		if(new_left < 0 || bales[new_left] < bales[left] - radius){
			break;
		}
		while(new_left > 0 && bales[new_left - 1] >= bales[left] - radius){
			--new_left;
		}
		left = new_left;
		++radius;
	}
	radius = 1;
	while(true){
		int new_right = right + 1;
		if(new_right >= n || bales[new_right] > bales[right] + radius){
			break;
		}
		while(new_right < n - 1 && bales[new_right + 1] <= bales[right] + radius){
			++new_right;
		}
		right = new_right;
		++radius;
	}
	return right - left + 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> bales(n);
	for(int i = 0; i < n; ++i){
		cin >> bales[i];
	}
	sort(bales.begin(), bales.end());
	int ans = 0;
	for(int i = 0; i < n; ++i){
		int cmp = explosions(bales, n, i);
		ans = max(ans, cmp);
	}
	cout << ans;
	return 0;
}
