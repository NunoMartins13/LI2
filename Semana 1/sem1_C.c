#include <stdio.h>

int main() {
    int aux,x,y,z;
    if (scanf("%d %d %d",&x,&y,&z) == 3) {
                
    	if (x>=y && x>z) { 
    		aux=x; x=z; z=aux;
    		
    		if(x>y) { aux=x; x=y; y=aux; }
    	}
		
		else if (y>x && y>z) {
			aux=y; y=z; z=aux;
			
			if(x>y) { aux=x; x=y; y=aux; }
		}
		
		else if (x>y) { aux=x; x=y; y=aux; }
		
		printf("%d %d %d\n",x,y,z);
    }
    return 0;
}