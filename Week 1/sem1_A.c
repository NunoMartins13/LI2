#include <stdio.h>

int main() {
    int x,y,z=1;

    if(scanf("%d",&x) == 1) {
        
        for (int i=2; i<6; i++) {
            
            if(scanf("%d",&y) == 1){
                
                if (x<y){
                    x=y; z=i;
                }
            }
        }
        printf("%d\n",z);
    }
    return 0;
}