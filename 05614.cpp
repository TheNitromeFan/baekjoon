#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<string> keys;
	unordered_map<string, int> orders;
	for(int i = 0; i < n; ++i){
		string product;
		int cnt;
		cin >> product >> cnt;
		if(orders[product] == 0){
			keys.push_back(product);
		}
		orders[product] += cnt;
	}
	sort(keys.begin(), keys.end(), [](string key1, string key2){
		return key1.length() < key2.length() || (key1.length() == key2.length() && key1 < key2);
	});
	for(string key : keys){
		cout << key << ' ' << orders[key] << '\n';
	}
	return 0;
}
