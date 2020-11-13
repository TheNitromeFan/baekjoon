#include <cstdio>
#include <vector>

using namespace std;

bool turnabout(vector<int> &j, vector<int> &s){
	bool was_winning = false;
	int running_j = 0, running_s = 0;
	for(int i = 0; i < 9; ++i){
		running_j += j[i];
		if(running_j > running_s){
			was_winning = true;
		}
		running_s += s[i];
		if(was_winning && running_j < running_s){
			return true;
		}
	}
	return false;
}

int main(){
	vector<int> j(9, 0), s(9, 0);
	for(int i = 0; i < 9; ++i){
		scanf("%d", &j[i]);
	}
	for(int i = 0; i < 9; ++i){
		scanf("%d", &s[i]);
	}
	if(turnabout(j, s)){
		printf("Yes");
	}else{
		printf("No");
	}
	return 0;
}
