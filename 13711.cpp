#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100010

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int a[MAX], b[MAX];
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	for(int i = 1; i <= n; ++i){
		cin >> b[i];
	}
	int order[MAX];
	for(int i = 1; i <= n; ++i){
		order[b[i]] = i;
	}
	for(int i = 1; i <= n; ++i){
		a[i] = order[a[i]];
	}
	vector<int> v = {-1};
	for(int i = 1; i <= n; ++i){
		if(v.back() < a[i]){
			v.push_back(a[i]);
		}else{
			vector<int>::iterator it = lower_bound(v.begin(), v.end(), a[i]);
			*it = a[i];
		}
	}
	cout << v.size() - 1;
	return 0;
}
