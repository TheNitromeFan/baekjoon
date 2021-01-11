#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int smallest_difference(int n, vector<int> &ns){
	int cand = ns[0] * ns[0] * ns[0];
	for(unsigned i = 0; i < ns.size(); ++i){
		int x = ns[i];
		for(unsigned j = i; j < ns.size(); ++j){
			int y = ns[j];
			for(unsigned k = j; k < ns.size(); ++k){
				int z = ns[k];
				if(abs(n - x * y * z) < abs(n - cand)){
					cand = x * y * z;
				}
				if(x * y * z > n){
					break;
				}
			}
		}
	}
	return abs(n - cand);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<bool> s(1201);
	for(int i = 0; i < m; ++i){
		int x;
		cin >> x;
		s[x] = true;
	}
	vector<int> ns;
	for(int j = 1; j <= 1200; ++j){
		if(!s[j]){
			ns.push_back(j);
		}
	}
	cout << smallest_difference(n, ns);
	return 0;
}
