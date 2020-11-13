#include <cstdio>
#include <deque>
#include <string>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	deque<int> deck;
	for(int i = 0; i < n; ++i){
		char command[6];
		scanf("%s", command);
		string word(command);
		if(word == "push"){
			int x;
			scanf("%d", &x);
			deck.push_back(x);
		}else if(word == "pop"){
			if(deck.empty()){
				printf("-1\n");
			}else{
				printf("%d\n", deck[0]);
				deck.pop_front();
			}
		}else if(word == "size"){
			printf("%d\n", deck.size());
		}else if(word == "empty"){
			printf("%d\n", deck.empty());
		}else if(word == "front"){
			if(deck.empty()){
				printf("-1\n");
			}else{
			    printf("%d\n", deck[0]);
		    }
		}else if(word == "back"){
			if(deck.empty()){
				printf("-1\n");
			}else{
			    printf("%d\n", deck[deck.size()-1]);
		    }
		}
	}
	return 0;
}
