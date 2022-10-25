#include <stdio.h>

#include <time.h>

#include <stdlib.h>

int password(int password_length) {

char list[] = "1234567890qwertyuiopasdfghjklzxcvbnm!@#$%^&*()_- +=QWERTYUIOPASDFGHJKLZXCVBNM[]{};':\"<>,.?/\|";

printf("\t");

for(int i = 0; i < password_length; i++) {

    printf("*");

}

printf("\n");

printf("\t");

srand(time(NULL));

for(int i = 0; i < password_length; i++) {

    printf("%c", list[rand() % (sizeof list - 1)]);

}

printf("\n");

printf("\t");

for(int i = 0; i < password_length; i++) {

    printf("*");

}

printf("\n");

}

int main() {

int password_length;

printf("\n\t*********************************\n\n");

printf("\tWelcome to the password generator\n\n");

printf("\t*********************************\n");

printf("\n\tEnter length of the password = ");

scanf("%d", &password_length);

printf("\n");

printf("\n");

password(password_length);

return 0;

}



