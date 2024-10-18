#include <stdio.h>

//1 corresponde a cima(X, Y - 1), 2 a baixo(X, Y + 1), 3 a esquerda(X - 1, Y) e 4 a direita(X + 1, Y). 

int main() {

    int n,x=0,y=0,z;

    if(scanf("%d",&n) == 1) {

        for (int i=0; i<n; i++) {
            
            if(scanf("%d",&z) == 1){
                
                switch (z%4) {

                    case 0 : x+=1; break;
                    case 1 : y-=1; break;
                    case 2 : y+=1; break;
                    case 3 : x-=1; break;
                }
            }
        }
        printf("%d %d\n",x,y);
    }
    return 0;
}