#include <iostream>
#include <set>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	set<int> trees;
	for(int i = 0; i < n; ++i){
		int g, r;
		cin >> g >> r;
		trees.insert(r);
	}
	cout << trees.size();
	return 0;
}
