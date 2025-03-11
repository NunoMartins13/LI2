#include <stdio.h>
/*
Jogada 	Inzel CMD
Pedra 	  @    *
Papel 	  |    -
Tesoura   X    +

Input:
->Uma linha com o número de jogadas N
->N linhas tendo cada uma dois carateres, a jogada do robot Inzel seguida da jogada do robot CMD

Output:
Imprimir uma linha com o nº de jogadas ganhas pelo robot Inzel, um espaço, o nº de jogadas ganhas pelo robot CMD, um espaço e o nº de empates

*/

int main() {

    int n,inzel=0,cmd=0,tie=0;

    if(scanf("%d",&n) == 1) {

        for (int i=0; i<n; i++) {

            char play[2*n+1]; //Strings como o ultimo elemnto do array é \0 temos de adicionar 1

            if(scanf("%2s",&play[2*i]) == 1) {

               if (play[2*i]=='@' && play[2*i+1]=='*') tie+=1;

               else if (play[2*i]=='@' && play[2*i+1]=='-') cmd+=1;

               else if (play[2*i]=='@' && play[2*i+1]=='+') inzel+=1;

               else if (play[2*i]=='|' && play[2*i+1]=='*') inzel+=1;

               else if (play[2*i]=='|' && play[2*i+1]=='-') tie+=1;

               else if (play[2*i]=='|' && play[2*i+1]=='+') cmd+=1;

               else if (play[2*i]=='X' && play[2*i+1]=='*') cmd+=1;

               else if (play[2*i]=='X' && play[2*i+1]=='-') inzel+=1;

               else tie+=1;
            }
        }
        printf("%d %d %d\n",inzel,cmd,tie);
    }
    return 0;
} 