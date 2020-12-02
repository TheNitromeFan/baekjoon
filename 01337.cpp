#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numbers_to_insert(vector<int> &v, int n){
	for(int gap = 5; gap > 0; --gap){
		for(int i = 0, j = gap - 1; j < n; ++i, ++j){
			if(v[j] - v[i] < 5){
				return 5 - gap;
			}
		}
	}
	return 5;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	cout << numbers_to_insert(v, n);
	return 0;
}
