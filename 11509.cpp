#include <iostream>
#define MAXH (1000000 + 1)

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int arrow[MAXH] = {};
	int ans = 0;
	for(int i = 0; i < n; ++i){
		int h;
		cin >> h;
		if(arrow[h + 1] == 0){
			++ans;
		}else{
			--arrow[h + 1];
		}
		++arrow[h];
	}
	cout << ans;
	return 0;
}
