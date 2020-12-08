#include <iostream>
#include <set>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	set<int> trash;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		trash.insert(x);
	}
	cout << trash.size();
	return 0;
}
