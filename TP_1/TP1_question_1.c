#include <stdio.h>


void parfait(int n){
    int x = 0;
    for (int i=1;i<=n;i++){
        x=0;
        for (int j=1;j<i;j++){
            if (i%j==0){
                x+=j;
            };
        };
        if(x==i){
            printf("%d \n", i);
        };
    }
};

int main(void){
    int i;
    scanf("%d", &i);
    parfait(i);
}; 