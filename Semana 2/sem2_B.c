#include <stdio.h>

int main() {

    int c,a,n,z;

    if(scanf("%d %d %d",&c, &a, &n) == 3) {

        for (int i=0; i<n; i++) {
            
            if(scanf("%d",&z) == 1) {

                if (c+z>=0 && c+z<=a) c+=z;
            }
        }
        printf("%d\n",c);
    }
    return 0;
}