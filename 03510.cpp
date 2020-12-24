#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <iomanip>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	int sum = 0;
	for(int i = 0; i < n; ++i){
		cin >> a[i].first;
		sum += a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end());
	vector<vector<int>> faces(n);
	double expect = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < a[i].first; ++j){
			faces[a[i].second].push_back(sum);
			--sum;
		}
		expect += (faces[a[i].second].front() + faces[a[i].second].back()) / 2.0;
	}
	cout << setprecision(7) << fixed << expect << '\n';
	for(int i = 0; i < n; ++i){
		for(int face : faces[i]){
			cout << face << ' ';
		}
		cout << '\n';
	}
	return 0;
}
