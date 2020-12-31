#include <iostream>
#include <vector>
#define MAX 50002

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int mines[MAX] = {};
	for(int i = 1; i <= n; ++i){
		cin >> mines[i];
	}
	vector<int> ans;
	for(int i = 1; i <= n; ++i){
		if(mines[i] >= mines[i - 1] && mines[i] >= mines[i + 1]){
			ans.push_back(i);
		}
	}
	for(int x : ans){
		cout << x << '\n';
	}
	return 0;
}
