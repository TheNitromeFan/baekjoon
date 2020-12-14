#include <iostream>
#define MAX 3000001

using namespace std;

bool simulate(int len, int ml, int mk, int cammo){
	int map[MAX];
	bool bomber[MAX] = {};
	int start = -ml + 1, end = 0;
	int blast = ml - 1;
	int total_damage = ml * mk;
	for(; end < len; ++start, ++end){
		cin >> map[end];
		int fire = total_damage - blast * mk;
		if(fire < map[end]){
			--cammo;
			if(cammo < 0){
				return false;
			}
			++blast;
			bomber[end] = true;
		}
		if(start < 0 || bomber[start]){
			--blast;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int len;
	cin >> len;
	int ml, mk;
	cin >> ml >> mk;
	int cammo;
	cin >> cammo;
	cout << (simulate(len, ml, mk, cammo) ? "YES" : "NO");
	return 0;
}
