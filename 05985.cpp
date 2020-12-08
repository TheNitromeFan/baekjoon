#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int skewed_sort(vector<int> &cows, int start, int end){
	if(end - start == 1){
		return 0;
	}
	int mid = (start + end) / 2;
	int ret = skewed_sort(cows, start, mid) + skewed_sort(cows, mid, end);
	if(cows[start] > cows[mid]){
		ret += (end - start) * (mid - start);
		for(int i = start, j = mid; i < mid; ++i, ++j){
			swap(cows[i], cows[j]);
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int m = 1 << n;
	vector<int> cows(m);
	for(int i = 0; i < m; ++i){
		cin >> cows[i];
	}
	cout << skewed_sort(cows, 0, m);
	for(int cow : cows){
		cout << "\n" << cow;
	}
	return 0;
}
