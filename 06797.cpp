#include <iostream>
#include <vector>

using namespace std;

bool matches(vector<int> &vec, vector<int> &pattern){
	for(unsigned i = 0; i + 1 < vec.size(); ++i){
		if(vec[i + 1] - vec[i] != pattern[i % pattern.size()]){
			return false;
		}
	}
	return true;
}

int shortest_pattern(vector<int> &v, int n){
	if(n == 1){
		return 0;
	}
	int i = 1;
	vector<int> p;
	for(; i < n; ++i){
		p.push_back(v[i] - v[i - 1]);
		if(matches(v, p)){
			return i;
		}
	}
	return i;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int n;
		cin >> n;
		if(n == 0){
			break;
		}
		vector<int> v(n);
		for(int i = 0; i < n; ++i){
			cin >> v[i];
		}
		cout << shortest_pattern(v, n) << '\n';
	}
	return 0;
}
