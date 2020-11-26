#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k;
	cin >> k;
	for(int a0 = 1; a0 <= k; ++a0){
		int n, m;
		cin >> n >> m;
		map<string, int> values;
		for(int i = 0; i < n; ++i){
			string prop;
			int val;
			cin >> prop >> val;
			values[prop] = val;
		}
		int price = 0;
		int amb = 0;
		for(int j = 0; j < m; ++j){
			string prop;
			cin >> prop;
			if(prop != "?"){
				price += values[prop];
				values.erase(values.find(prop));
			}else{
				++amb;
			}
		}
		vector<int> remain;
		for(auto it = values.begin(); it != values.end(); ++it){
			remain.push_back(it->second);
		}
		sort(remain.begin(), remain.end());
		int minPrice = price;
		for(int i = 0; i < amb; ++i){
			minPrice += remain[i];
		}
		int maxPrice = price;
		for(int i = (int)remain.size() - 1; i >= (int)remain.size() - amb; --i){
			maxPrice += remain[i];
		}
		cout << "Data Set " << a0 << ":\n" << minPrice << " " << maxPrice << "\n\n";
	}
	return 0;
}
