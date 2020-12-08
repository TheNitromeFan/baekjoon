#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unsigned n;
	cin >> n;
	string beads;
	cin >> beads;
	unsigned i = 0;
	unsigned maxLen = 1;
	while(i < n){
		if(beads[i] == 'V'){
			++i;
			continue;
		}
		if(i == n){
			break;
		}
		unsigned start = i;
		++i;
		while(i < n && beads[i] != 'V' && beads[i] != beads[i - 1]){
			++i;
		}
		unsigned len = i - start;
		if(maxLen < len){
			maxLen = len;
		}
	}
	cout << maxLen;
	return 0;
}
