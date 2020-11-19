#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int a[20];
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	sort(a, a + n, greater<int>());
	int alice = 0, bob = 0;
	for(int i = 0; i < n; ++i){
		if(i % 2 == 0){
			alice += a[i];
		}else{
			bob += a[i];
		}
	}
	cout << alice << ' ' << bob;
	return 0;
}
