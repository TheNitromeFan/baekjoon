#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
#define MEM_MAX 100000
#define CODE_MAX 4096
#define INPUT_MAX 4096

typedef struct Node{
	int idx1;
	int idx2;
} node;

using namespace std; 

int t;
int memory_num, code_num, input_num;
char memory[MEM_MAX];
char code[CODE_MAX];
node bracket[CODE_MAX];
char input[INPUT_MAX];
stack<node> st;

int main(){
	scanf("%d", &t);
	while(t--){
		node tmp;
		stack<node> stack;
		int cnt = 0;
		int ptr = 0;
		int code_index = 0;
		int input_index = 0;
		int max_index = 0;
		scanf("%d %d %d", &memory_num, &code_num, &input_num);
		for(int i = 0; i < MEM_MAX; ++i){
			memory[i] = 0;
		}
		for(int i = 0; i < CODE_MAX; ++i){
			bracket[i].idx1 = 0;
			bracket[i].idx2 = 0;
			code[i] = 0;
			input[i] = 0;
		}
		scanf("%s %s", code, input);
		for(int i = 0; i < code_num; ++i){
			if(code[i] == '['){
				bracket[i].idx1 = i;
				tmp.idx1 = i;
				stack.push(tmp);
			}else if(code[i] == ']'){
				tmp = stack.top();
				stack.pop();
				bracket[i].idx1 = tmp.idx1;
				bracket[i].idx2 = i;
				bracket[tmp.idx1].idx2 = i;
			}
		}
		while(true){
			switch(code[code_index]){
				case '-':
					memory[ptr] -= 1;
					cnt++;
					code_index++;
					break;
				case '+':
					memory[ptr] += 1;
					cnt++;
					code_index++;
					break;
				case '<':
					if(ptr == 0){
						ptr = memory_num - 1;
					}else{
						ptr--;
					}
					cnt++;
					code_index++;
					break;
				case '>':
					if(ptr == memory_num - 1){
						ptr = 0;
					}else{
						ptr++;
					}
					cnt++;
					code_index++;
					break;
				case '[':
					if(memory[ptr] == 0){
						code_index = bracket[code_index].idx2;
						cnt++;
					}else{
						cnt++;
						code_index++;
					}
					break;
				case ']':
					if(memory[ptr] != 0){
						code_index = bracket[code_index].idx1;
						cnt++;
					}else{
						cnt++;
						code_index++;
					}
					break;
				case '.': 
					cnt++; 
					code_index++;
					break;
				case ',':
					if(input_index == input_num){ 
						memory[ptr] = 255;
					}else{
						memory[ptr] = input[input_index];
						input_index++;
					}
					cnt++;
					code_index++;
					break;
			}
			if(code_index > max_index){
				max_index = code_index;
			}
			if(code_index == code_num){
				printf("Terminates\n");
				break;
			}
			if(cnt > 50000000){
				printf("Loops %d %d\n", bracket[max_index].idx1, bracket[max_index].idx2);
				break;
			}
		}
	}
	return 0;
}

