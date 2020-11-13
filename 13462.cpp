#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string monster;
	cin >> monster;
	unsigned i = 0;
	while(i < monster.length()){
		if(i + 2 < monster.length() && monster[i] != monster[i + 1]
		&& monster[i + 1] != monster[i + 2] && monster[i] != monster[i + 2]){
			cout << 'C';
			i += 3;
		}else if(monster[i] == 'R'){
			cout << 'S';
			++i;
		}else if(monster[i] == 'B'){
			cout << 'K';
			++i;
		}else{
			cout << 'H';
			++i;
		}
	}
	return 0;
}
