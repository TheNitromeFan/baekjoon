#include <iostream>
#include <vector>
#define MAX 100

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int positive[MAX];
	int a[MAX][101];
	for(int i = 0; i < m; ++i){
		for(int j = 1; j <= n; ++j){
			cin >> a[i][j];
		}
		cin >> positive[i];
	}
	vector<int> ans1, ans2;
	for(int j = 1; j <= n; ++j){
		bool cannot = false;
		for(int i = 0; i < m; ++i){
			if((a[i][j] && !positive[i]) || (!a[i][j] && positive[i])){
				cannot = true;
			}
		}
		if(cannot){
			ans1.push_back(j);
		}else{
			ans2.push_back(j);
		}
	}
	if(ans2.empty()){
		bool any_infected = false;
		for(int i = 0; i < m; ++i){
			if(positive[i]){
				any_infected = true;
				break;
			}
		}
		if(any_infected){
			cout << "Incorrect";
		}else{
			cout << n;
			for(int x : ans1){
				cout << ' ' << x;
			}
			cout << '\n' << 0 << '\n' << 0;
		}
	}else if(ans2.size() == 1){
		cout << n - 1;
		for(int x : ans1){
			cout << ' ' << x;
		}
		cout << '\n' << 1 << ' ' << ans2[0] << '\n' << 0;
	}else{
		cout << ans1.size();
		for(int x : ans1){
			cout << ' ' << x;
		}
		cout << '\n' << 0 << '\n' << ans2.size();
		for(int x : ans2){
			cout << ' ' << x;
		}
	}
	return 0;
}
