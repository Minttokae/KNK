#include <stdbool.h>
#include <stdio.h>
#include <ctype.h> /* toupper, isalpha */

void read_word(int counts[26]);
bool equal_array(int counts1[26], int counts2[26]);

int main(void) {

    int same,
        letters1[26] = {0}, letters2[26] = {0};
    

    printf("Enter first word: ");
    read_word(letters1);
    
    printf("Enter second word: ");
    read_word(letters2);

    if (same == 1){
        printf("YES");
            }
    else {
        printf("NO");
    }
  
    return 0;
}

void read_word(int counts[26]){
    int c;
    while ((c = getchar()) != '\n') {
        if (isalpha(c)) 
            counts[toupper(c) - 'A']++;       
    }
}

bool equal_array(int counts1[26], int counts2[26]){
    for (int i = 0; i < 26; i++){
        if (counts1[i] != counts2[i])
            return 0;
    }
    return 1;
}
