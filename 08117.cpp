#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void triangle(vector<int> &v){
	for(unsigned i = 0; i + 2 < v.size(); ++i){
		if(v[i] + v[i + 1] > v[i + 2]){
			cout << v[i] << ' ' << v[i + 1] << ' ' << v[i + 2];
			return;
		}
	}
	cout << "NIE";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> v;
	while(true){
		int x;
		cin >> x;
		if(x == 0){
			break;
		}
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	triangle(v);
	return 0;
}
