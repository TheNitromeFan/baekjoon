#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

class Cmp{
	public:
		bool operator()(pair<string, int> a, pair<string, int> b){
			return a.second > b.second;
		}
};

int fire(vector<pair<string, int>> &emp, int d, int k){
	sort(emp.begin(), emp.end(), Cmp());
	int saved = 0;
	for(int i = 0; i < k; ++i){
		saved += emp[i].second;
		if(saved >= d){
			return i + 1;
		}
	}
	return -1;
}

int main(){
	int n, d, k;
	cin >> n >> d >> k;
	vector<pair<string, int>> employees(n);
	for(int i = 0; i < n; ++i){
		cin >> employees[i].first >> employees[i].second;
	}
	int ans = fire(employees, d, k);
	if(ans != -1){
		cout << ans;
		for(int i = 0; i < ans; ++i){
			cout << "\n" << employees[i].first << ", YOU ARE FIRED!";
		}
	}else{
		cout << "impossible";
	}
	return 0;
}
