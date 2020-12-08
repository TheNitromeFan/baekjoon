#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> t(n + 1);
	for(int i = 1; i <= n; ++i){
		cin >> t[i];
	}
	int day = 0, minTemp = 100;
	for(int i = 1; i + 2 <= n; ++i){
		int temp = max(t[i], t[i + 2]);
		if(minTemp > temp){
			minTemp = temp;
			day = i;
		}
	}
	cout << day << ' ' << minTemp;
	return 0;
}
