#include <iostream>

using namespace std;

bool read_byte(int &x){
	x = 0;
	for(int i = 0; i < 8; ++i){
		char ch;
		if(!(cin >> ch)){
			return false;
		}
		x = (x << 1) + (ch - '0');
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int pc, accu, mem[32];
	string s;
	while(read_byte(mem[0])){
		for(int i = 1; i < 32; ++i){
			read_byte(mem[i]);
		}
		pc = 0;
		accu = 0;
		bool halt = false;
		while(!halt){
			int instr = mem[pc];
			pc = (pc + 1) % 32;
			switch(instr >> 5){
				case 0:
					mem[instr & 0x1f] = accu;
					break;
				case 1:
					accu = mem[instr & 0x1f];
					break;
				case 2:
					if(accu == 0){
						pc = instr & 0x1f;
					}
					break;
				case 3:
					break;
				case 4:
					accu = (accu + 255) % 256;
					break;
				case 5:
					accu = (accu + 1) % 256;
					break;
				case 6:
					pc = instr & 0x1f;
					break;
				case 7:
					halt = true;
					break;
			}
		}
		for(int b = 7; b >= 0; --b){
			cout << ((accu >> b) & 1);
		}
		cout << '\n';
	}
	return 0;
}
