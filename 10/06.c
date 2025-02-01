#include <stdio.h>
#include <stdlib.h> //exit(0)

#define MAX 50

int top = 0;
char arr[MAX];

void push(char val);
char pop();
int is_empty();
int is_full();
char calc(char n1, char n2, char oper);
char read();

int main() {
    char val;
    while (1) {
    //입력값 읽기
        read();
    //입력값 != q --> 계산
        printf("%c\n", arr[0]);
    }
    return 0;
}

void push(char val) {
    if (is_full())
        arr[++top] = val;
}

char pop() {

    return is_empty() ? arr[top] : arr[top--];
}

int is_empty() {
    return top == 0;
}

int is_full() {
    return top == MAX;
}

char calc(char n1, char n2, char oper) {
    int res = 0;
    n1 -= '0'; n2 -= '0';

    switch (oper)
    {
    case '+': res = n1 + n2; break;
    case '-': res = n1 - n2; break;
    case '*': res = n1 * n2; break;
    case '/': res = n1 / n2; break;
    }

    return res + '0';
}
char read() {
    char ch;
    int i;

    while ((ch = getchar()) != '\n') {

        if (ch == ' ') continue;

        push(ch);
        
        if (ch == '=') break;
        else if (ch == 'q') exit(0);
    }
    //숫자 마지막 부분을 top으로 잡는다.
    for (i = 0; arr[i] >= '0' && arr[i] <= '9'; i++) top++;

    for (; arr[i] != '='; i++) {
        arr[top] = calc(pop(), arr[top], arr[i]);
    }

    return arr[0];
}
