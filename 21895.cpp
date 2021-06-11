#include <iostream>
#include <string>

using namespace std;

char beat(char c){
	char ret = ' ';
	switch(c){
		case 'S':
			ret = 'R';
			break;
		case 'P':
			ret = 'S';
			break;
		case 'R':
			ret = 'P';
			break;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string::size_type n = 0;
	cin >> n;
	string robot1, robot2;
	cin >> robot1 >> robot2;
	string ans;
	for(string::size_type i = 0; i < n; ++i){
		if(robot1[i] == robot2[i]){
			ans += beat(robot1[i]);
		}else if(robot1[i] == beat(robot2[i])){
			ans += robot1[i];
		}else{
			ans += robot2[i];
		}
	}
	cout << ans;
	return 0;
}
