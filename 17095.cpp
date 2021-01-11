#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n);
	int min = 100001, max = 0;
	int min_pos = -1, max_pos = -1;
	int diff = -100001;
	int ans = n + 2;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		if(a[i] >= max){
			max = a[i];
			max_pos = i;
		}
		if(a[i] <= min){
			min = a[i];
			min_pos = i;
		}
		if(max - min > diff || (max - min == diff && abs(max_pos - min_pos) + 1 < ans)){
			ans = abs(max_pos - min_pos) + 1;
			diff = max - min;
		}
	}
	cout << ans;
	return 0;
}
