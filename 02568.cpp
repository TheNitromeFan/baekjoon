#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100005

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end());
	int len = 0;
	int pos[MAX], a[MAX], min[MAX], pred[MAX];
	for(int i = 0; i < n; ++i){
		pos[i] = v[i].first;
		a[i] = v[i].second;
		int low = 1, high = len;
		while(low <= high){
			int mid = (low + high + 1) / 2;
			if(a[min[mid]] < a[i]){
				low = mid + 1;
			}else{
				high = mid - 1;
			}
		}
		int new_len = low;
		pred[i] = min[new_len - 1];
		min[new_len] = i;
		if(new_len > len){
			len = new_len;
		}
	}
	cout << n - len << '\n';
	int k = min[len];
	vector<int> cut(n, true);
	for(int i = len - 1; i >= 0; --i){
		cut[k] = false;
		k = pred[k];
	}
	for(int i = 0; i < n; ++i){
		if(cut[i]){
			cout << pos[i] << '\n';
		}
	}
	return 0;
}
