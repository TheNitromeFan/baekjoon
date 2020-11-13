#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int n;
		cin >> n;
		map<int, int> m1, m2;
		for(int j = 0; j < n; ++j){
			int x;
			cin >> x;
			if(m1.find(x) == m1.end()){
				m1[x] = 1;
			}else{
				++m1[x];
			}
		}
		for(int j = 0; j < n; ++j){
			int x;
			cin >> x;
			if(m2.find(x) == m2.end()){
				m2[x] = 1;
			}else{
				++m2[x];
			}
		}
		vector<int> v1, v2;
		for(auto it = m1.begin(); it != m1.end(); ++it){
			v1.push_back(it->second);
		}
		for(auto it = m2.begin(); it != m2.end(); ++it){
			v2.push_back(it->second);
		}
		if(v1.size() != v2.size()){
			cout << "you've messed up, Cornell\n";
			continue;
		}
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		int flag = true;
		for(int j = 0; j < v1.size(); ++j){
			if(v1[j] != v2[j]){
				cout << "you've messed up, Cornell\n";
				flag = false;
				break;
			}
		}
		if(flag){
			cout << "what a lovely party\n";
		}
	}
	return 0;
}
