#include <iostream>
#include <set>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, r;
	cin >> n >> r;
	set<int> s;
	for(int i = 0; i < r; ++i){
		int x;
		cin >> x;
		s.insert(x);
	}
	for(int j = 1; j <= n; ++j){
		if(s.find(j) == s.end()){
			cout << j << " ";
		}
	}
	if(n == r){
		cout << "*";
	}
	return 0;
}
