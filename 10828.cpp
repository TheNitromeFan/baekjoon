#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	vector<int> vec;
	for(int i = 0; i < n; ++i){
		char command[6];
		scanf("%s", command);
		string word(command);
		if(word == "push"){
			int x;
			scanf("%d", &x);
			vec.push_back(x);
		}else if(word == "pop"){
			if(vec.empty()){
				printf("-1\n");
			}else{
				printf("%d\n", vec[vec.size()-1]);
				vec.pop_back();
			}
		}else if(word == "size"){
			printf("%d\n", vec.size());
		}else if(word == "empty"){
			printf("%d\n", vec.empty());
		}else if(word == "top"){
			if(vec.empty()){
				printf("-1\n");
			}else{
			    printf("%d\n", vec[vec.size()-1]);
		    }
		}
	}
	return 0;
}
