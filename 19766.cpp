#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, t;
	cin >> n >> k >> t;
	vector<int> z(n), s(n);
	for(int i = 0; i < n; ++i){
		cin >> z[i];
	}
	for(int i = 0; i < n; ++i){
		cin >> s[i];
	}
	int time = 0;
	for(int i = 0; i < n; ++i){
		time += z[i];
		if(time >= s[i]){
			time += t;
		}else if(time + k >= s[i]){
			time = s[i] + t;
		}else{
			time += k;
		}
	}
	cout << time;
	return 0;
}
