#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, d;
	cin >> n >> d;
	vector<int> desk(n);
	for(int i = 0; i < n; ++i){
		cin >> desk[i];
	}
	int start = 0;
	while(desk[start] == 0){
		++start;
	}
	while(desk.back() == 0){
		desk.pop_back();
		--n;
	}
	int phones = 0;
	int dist = 0;
	for(int i = start + 1; i < n; ++i){
		++dist;
		if(desk[i]){
			dist = 0;
		}else if(dist == d){
			++phones;
			dist = 0;
		}
	}
	cout << phones;
	return 0;
}
