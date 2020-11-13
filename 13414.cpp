#include <iostream>
#include <map>
#include <string>
#define MAX 500000

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k, len;
	cin >> k >> len;
	static string reg[MAX];
	bool bad_pos[MAX] = {};
	map<string, int> pos;
	for(int i = 0; i < len; ++i){
		cin >> reg[i];
		if(pos.find(reg[i]) != pos.end()){
			bad_pos[pos[reg[i]]] = true;
		}
		pos[reg[i]] = i;
	}
	int cnt = 0, idx = 0;
	while(cnt < k && idx < len){
		if(!bad_pos[idx]){
			cout << reg[idx] << '\n';
			++cnt;
		}
		++idx;
	}
	return 0;
}
