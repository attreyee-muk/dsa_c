#include <stdio.h>
int max(int a ,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
int knapsack(int w,int profit[], int wt[],int n){
    if(n==0|| w==0){
        return 0;
    }
    if(wt[n-1]>w){
        return knapsack(w,profit,wt,n-1);
    }
    else{
        return max(knapsack(w,profit,wt,n-1),(profit[n-1]+knapsack(w-wt[n-1],profit,wt,n-1)));
    }
}
int main(){
    int profit[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int w = 50;
    int n=sizeof(profit)/sizeof(profit[0]);
    printf("%d",knapsack(w,profit,wt,n));
    return 0;
}