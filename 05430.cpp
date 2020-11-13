#include <cstdio>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		char command[100001];
		scanf("%s", command);
		int n;
		scanf("%d\n%*c", &n);
		deque<int> deck;
		for(int j = 0; j < n; ++j){
			int x;
			scanf("%d%*c", &x);
			deck.push_back(x);
		}
		bool error = false;
		bool reverse = false;
		for(int j = 0; command[j] != '\0'; ++j){
			if(command[j] == 'R'){
				reverse = !reverse;
			}else if(command[j] == 'D'){
				if(deck.empty()){
					error = true;
					break;
				}else if(!reverse){
					deck.pop_front();
				}else if(reverse){
					deck.pop_back();
				}
			}
		}
		if(error){
			printf("error\n");
			continue;
		}
		printf("[");
		if(!deck.empty() && !reverse){
			printf("%d", deck.front());
			deck.pop_front();
	    	while(!deck.empty()){
	    		printf(",%d", deck.front());
	    		deck.pop_front();
			}
	    }else if(!deck.empty() && reverse){
			printf("%d", deck.back());
			deck.pop_back();
	    	while(!deck.empty()){
	    		printf(",%d", deck.back());
	    		deck.pop_back();
			}
		}
		printf("]\n");
		fflush(stdin);
	}
	return 0;
}
