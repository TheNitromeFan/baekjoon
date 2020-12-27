#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int boxes = 0;
	int cur = 0;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		if(cur + x > m){
			++boxes;
			cur = x;
		}else{
			cur += x;
		}
	}
	if(cur > 0){
		++boxes;
	}
	cout << boxes;
	return 0;
}
