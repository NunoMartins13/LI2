#include <stdio.h>

int main() {
    int x,y,z;
    if(scanf("%d %d %d",&x,&y,&z) == 3) {
                
    	if ((x<=y && y<=z) || (x>=y && y>=z)) { printf("OK\n"); }
		
		else printf("NAO\n");
    }
    return 0;
}