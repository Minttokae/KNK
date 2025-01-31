#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll();
bool play();

int main() {
    char again = 0;
  
    srand((unsigned) time(NULL));
  
    do {
        if (play()) printf("You win!\n");
        else printf("You lose.\n");

        printf("Play again? ");
        scanf(" %c", &again); 
      // "%c"의 앞에 공백이 없으면 첫 반복후 값을 입력할 때 \n이 다음 scanf로 들어가게 되어서 반복이 종료됨.
      // " %c"처럼 앞에 공백을 입력하여 공백을 무시하도록 설정.

    } while (toupper(again) == 'Y');

    return 0;
}

int roll() {
    int dice1, dice2, sum = 0;
  
    /*srand를 main함수 이외에서 선언하면 호출할때마다 같거나 비슷한 값이 나오게 됨!
    그래서 메인 함수에서 한 번 호출해주고 시작하면 됨*/
  
    dice1 = rand() % 6 + 1;
    dice2 = rand() % 6 + 1;
    sum = dice1 + dice2;
   
    return sum;
}

bool play() {
    int val;
    int point = roll();

    printf("You rolled : %d\n", point);
    
    if (point == 7 || point == 11) return 1;
    else if (point == 2 || point == 3 || point == 12) return 0;

    printf("Your point is %d\n", point);
  
    for (;;) {
        val = roll();
        printf("You rolled : %d\n", val);
        if (val == point) return 1;
        else if (val == 7) return 0;
    }
}
