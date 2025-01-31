#include <stdio.h>

int poly(int x);
int power(int x, int n);

int main() {
    printf("%d", poly(2));
    return 0;
}

int poly(int x){
    return 3*power(x,5) + 2*power(x,4) - 5*power(x,3) - power(x,2) + 7*x - 6;
}

int power(int x, int n) {
    int res = 1;
    
    for (int i = 0; i < n; i++){
        res *= x;
    }

    return res;
}
