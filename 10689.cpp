#include <iostream>
#include <set>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 1; a0 <= t; ++a0){
		int n;
		cin >> n;
		set<int> cats;
		unsigned sz = 0;
		int ans = 0;
		for(int i = 1; i <= n; ++i){
			int x;
			cin >> x;
			cats.insert(x);
			if(cats.size() > sz){
				sz = cats.size();
				ans = i;
			}
		}
		cout << "Case " << a0 << ": " << ans << "\n";
	}
	return 0;
}
