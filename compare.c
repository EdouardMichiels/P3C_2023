#include <stdio.h>

int identite(int x){return x;}
int abs(int x){
    if(x>=0){
        return x;
    }
    else{
        return -x;
    }
}

int compare(int min, int max, int f1(int), int f2(int)){
    int n = 0;
    for(int i = min; i < max + 1; i++){
        printf("%d\n", i);
        if(f1(i) == f2(i)){
            n++;
        }
    }
    return n;
}


int main(int argc, const char *argv[]){
    printf("%d\n", compare(0, 10, identite, abs));
    printf("%d\n", compare(0, 0, identite, abs));
    printf("%d\n", compare(10, 20, identite, abs));
    return 0;
}