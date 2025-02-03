#include <stdio.h>
#define QUANTITY 100

int top = 0;

struct info {
    int number;
    char name[50];
    int hand;
};

struct info inventory[QUANTITY];

void insert();
void search();
void update();
void print();


int main() {
    char c;

    while (1) {
        printf("Enter operation code : ");
        while ((c = getchar()) == '\n');

        switch (c) {
        case 'i': insert(); break;
        case 's': search(); break;
        case 'u': update(); break;
        case 'p': print(); break;
        case 'q': return 0;
        }
    }
    return 0;
}


void insert() {
    printf("Enter number : ");
    scanf("%d", &inventory[top].number);
    printf("Enter name : ");
    scanf("%s", &inventory[top].name);
    printf("Enter hand : ");
    scanf("%d", &inventory[top].hand);
    top++;
}

void search() {

    int num, idx, in_hand = 0;

    printf("Enter number : ");
    scanf("%d", &num);
    
    for (int i = 0; i < top; i++) {
        if (inventory[i].number == num) {
            in_hand = 1;
            idx = i;
            break;
        }
    }
    
    if (in_hand) {
        printf("Part name : %s\n", inventory[idx].name);
        printf("Quanitity in Hand : %d\n", inventory[idx].hand);
    }
    else
        printf("You don't have the item.\n");
}

void update() {

    int num, idx, in_hand = 0, change;

    printf("Enter number : ");
    scanf("%d", &num);
    
    for (int i = 0; i < top; i++) {
        if (inventory[i].number == num) {
            in_hand = 1;
            idx = i;
            break;
        }
    }

    if (in_hand) {
        printf("Enter change in quantity on hand : ");
        scanf("%d", &change);

        inventory[idx].hand += change;
    }
    else
        printf("You don't have the item.\n");

}

void print() {

    printf("Part number     Part name           Quantity on Hand\n");

    for (int i = 0; i < top; i++) {
        printf("%7d \t%s \t\t\t%7d \n", inventory[i].number, inventory[i].name, inventory[i].hand);
    }
}
