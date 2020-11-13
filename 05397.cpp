#include <cstdio>
#include <cstdlib>

struct node{
	char c;
	node *prev;
	node *next;
};

using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	for(int a = 0; a < t; ++a){
		char string[1000001];
		scanf("%s", string);
		node *head = (node *)malloc(sizeof(node));
		head->c = ' ';
		node *current = head;
		for(int i = 0; string[i] != '\0'; ++i){
			char c = string[i];
			if(c != '<' && c != '>' && c != '-'){
				node *temp = (node *)malloc(sizeof(node));
				temp->c = c;
				temp->prev = current;
				temp->next = current->next;
				current->next = temp;
				current = current->next;
				if(current->next != NULL){
					current->next->prev = current;
				}
			}else if(c == '<' && current->c != ' '){
				current = current->prev;
			}else if(c == '>' && current->next != NULL){
				current = current->next;
			}else if(c == '-' && current->c != ' '){
				node *temp = current;
				current = current->prev;
				current->next = current->next->next;
				if(current->next != NULL){
					current->next->prev = current;
				}
				free(temp);
			}
			current = head->next;
			while(current != NULL){
				printf("%c", current->c);
				node *temp = current;
				current = current->next;
				free(temp);
			}
			printf("\n");
		}
	}
	return 0;
}
