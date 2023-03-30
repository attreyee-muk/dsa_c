#include <stdio.h>

int main(){
    int p[]={ 5,10,15,7,8,9,4};
    int w[]={ 1,3,5,4,1,3,2};
    int ratio[7]={0,0,0,0,0,0,0};
    int W=15;
    int weight=0;
    int profit=0;
    for(int i=0;i<7;i++){
        if (weight+w[i]<=W){
            ratio[i]=1;
            profit+=p[i];
            weight=weight+w[i];
        }
        else{
            ratio[i]=(W-weight)/w[i];
            profit+=p[i];
            break;
        }

    }
    for(int i=0;i<7;i++){
        printf("%d",ratio[i]);
        
    }
    printf("\n");
    printf("%d",profit);
    printf("\n");
    return 0;
}