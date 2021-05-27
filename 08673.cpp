#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, w;
	cin >> n >> w;
	vector<int> t;
	int sum = 0;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		if(x > 0){
			t.push_back(x);
			sum += x;
		}
	}
	n = (int)t.size();
	sort(t.begin(), t.end());
	for(int i = 0; i < n; ++i){
		if(sum >= w * (n - i)){
			cout << i;
			return 0;
		}
		sum -= t[i];
	}
	cout << "NIE";
	return 0;
}
