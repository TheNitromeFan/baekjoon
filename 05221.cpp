#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		cin >> n;
		vector<long long> v(n);
		for(int i = 0; i < n; ++i){
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		vector<string> ans;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < i; ++j){
				for(int k = 0; k < j; ++k){
					if(v[k] * v[k] + v[j] * v[j] == v[i] * v[i]){
						ans.push_back("{" + to_string(v[k]) + " " + to_string(v[j]) + " " + to_string(v[i]) + "}");
					}
				}
			}
		}
		sort(ans.begin(), ans.end());
		if(!ans.empty()){
			cout << "Found Pythogorean triples: ";
			for(string s : ans){
				cout << " " << s;
			}
			cout << "\n";
		}else{
			cout << "No Pythogorean triples found in the sequence.\n";
		}
	}
	return 0;
}
