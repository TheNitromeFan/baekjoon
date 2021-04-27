#include <iostream>
#include <unordered_set>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int cnt = 0;
	int n;
	cin >> n;
	unordered_set<int> s;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		if(s.find(x) == s.end()){
			s.insert(x);
		}else{
			++cnt;
		}
	}
	cout << cnt;
	return 0;
}
