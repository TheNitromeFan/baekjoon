#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<string> v(20);
	v[0] = "{}";
	for(int n = 1; n < 20; ++n){
		v[n] += "{{}";
		for(int i = 1; i < n; ++i){
			v[n] += "," + v[i];
		}
		v[n] += "}";
	}
	int t;
	cin >> t;
	for(int j = 0; j < t; ++j){
		string s1, s2;
		cin >> s1 >> s2;
		vector<string>::iterator it1 = find(v.begin(), v.end(), s1), it2 = find(v.begin(), v.end(), s2);
		cout << *(v.begin() + (it1 - v.begin()) + (it2 - v.begin())) << "\n";
	}
	return 0;
}
