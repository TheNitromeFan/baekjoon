#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> employee_count(n);
	vector<long long> max_salary(n);
	long long max = 0;
	for(int i = 0; i < n; ++i){
		cin >> employee_count[i];
		for(int j = 0; j < employee_count[i]; ++j){
			long long x;
			cin >> x;
			if(max_salary[i] < x){
				max_salary[i] = x;
			}
		}
		if(max < max_salary[i]){
			max = max_salary[i];
		}
	}
	long long ans = 0;
	for(int i = 0; i < n; ++i){
		ans += employee_count[i] * (max - max_salary[i]);
	}
	cout << ans;
	return 0;
}
