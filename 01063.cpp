#include <cstdio>

int main(){
	char king[5], rock[5];
	int n;
	scanf("%s %s %d", king, rock, &n);
	int kx = king[0] - 'A' + 1, ky = king[1] - '0', rx = rock[0] - 'A' + 1, ry = rock[1] - '0';
	for(int i = 0; i < n; ++i){
		char move[5] = {};
		scanf("%s", move);
		if(move[0] == 'R' && move[1] == 'T'){
			int nx = kx + 1, ny = ky + 1;
			if(nx < 1 || nx > 8 || ny < 1 || ny > 8){
				continue;
			}
			if(nx == rx && ny == ry){
				int nnx = rx + 1, nny = ry + 1;
				if(nnx < 1 || nnx > 8 || nny < 1 || nny > 8){
					continue;
				}
				rx = nnx;
				ry = nny;
			}
			kx = nx;
			ky = ny;
		}else if(move[0] == 'L' && move[1] == 'T'){
			int nx = kx - 1, ny = ky + 1;
			if(nx < 1 || nx > 8 || ny < 1 || ny > 8){
				continue;
			}
			if(nx == rx && ny == ry){
				int nnx = rx - 1, nny = ry + 1;
				if(nnx < 1 || nnx > 8 || nny < 1 || nny > 8){
					continue;
				}
				rx = nnx;
				ry = nny;
			}
			kx = nx;
			ky = ny;	
		}else if(move[0] == 'R' && move[1] == 'B'){
			int nx = kx + 1, ny = ky - 1;
			if(nx < 1 || nx > 8 || ny < 1 || ny > 8){
				continue;
			}
			if(nx == rx && ny == ry){
				int nnx = rx + 1, nny = ry - 1;
				if(nnx < 1 || nnx > 8 || nny < 1 || nny > 8){
					continue;
				}
				rx = nnx;
				ry = nny;
			}
			kx = nx;
			ky = ny;
		}else if(move[0] == 'L' && move[1] == 'B'){
			int nx = kx - 1, ny = ky - 1;
			if(nx < 1 || nx > 8 || ny < 1 || ny > 8){
				continue;
			}
			if(nx == rx && ny == ry){
				int nnx = rx - 1, nny = ry - 1;
				if(nnx < 1 || nnx > 8 || nny < 1 || nny > 8){
					continue;
				}
				rx = nnx;
				ry = nny;
			}
			kx = nx;
			ky = ny;
		}else if(move[0] == 'R'){
			int nx = kx + 1, ny = ky;
			if(nx < 1 || nx > 8 || ny < 1 || ny > 8){
				continue;
			}
			if(nx == rx && ny == ry){
				int nnx = rx + 1, nny = ry;
				if(nnx < 1 || nnx > 8 || nny < 1 || nny > 8){
					continue;
				}
				rx = nnx;
				ry = nny;
			}
			kx = nx;
			ky = ny;
		}else if(move[0] == 'L'){
			int nx = kx - 1, ny = ky;
			if(nx < 1 || nx > 8 || ny < 1 || ny > 8){
				continue;
			}
			if(nx == rx && ny == ry){
				int nnx = rx - 1, nny = ry;
				if(nnx < 1 || nnx > 8 || nny < 1 || nny > 8){
					continue;
				}
				rx = nnx;
				ry = nny;
			}
			kx = nx;
			ky = ny;			
		}else if(move[0] == 'B'){
			int nx = kx, ny = ky - 1;
			if(nx < 1 || nx > 8 || ny < 1 || ny > 8){
				continue;
			}
			if(nx == rx && ny == ry){
				int nnx = rx, nny = ry - 1;
				if(nnx < 1 || nnx > 8 || nny < 1 || nny > 8){
					continue;
				}
				rx = nnx;
				ry = nny;
			}
			kx = nx;
			ky = ny;
		}else if(move[0] == 'T'){
			int nx = kx, ny = ky + 1;
			if(nx < 1 || nx > 8 || ny < 1 || ny > 8){
				continue;
			}
			if(nx == rx && ny == ry){
				int nnx = rx, nny = ry + 1;
				if(nnx < 1 || nnx > 8 || nny < 1 || nny > 8){
					continue;
				}
				rx = nnx;
				ry = nny;
			}
			kx = nx;
			ky = ny;			
		}
	}
	printf("%c%d\n%c%d", kx - 1 + 'A', ky, rx - 1 + 'A', ry);
	return 0;
}
