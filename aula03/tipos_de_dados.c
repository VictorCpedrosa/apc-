#include <stdio.h>

int main() {
// char 'A' , 'a'
// int -125, 0, 125654
// float -9.123456, 0.0, 0.665666f
// double -9.123456789012345, 5.0123456789554654
// void sem tipo

printf("O tipo 'char' ocupa %i bytes e vai de %i a %i\n", sizeof(char), -127,128);
printf("O tipo 'int' ocupa %i bytes e vai de %i a %i\n", sizeof(int), -214748648, 2147483647);
printf("O tipo 'float' ocupa %i bytes e vai de %i a %i\n", sizeof(float), -3.4E+38, 3.4+38);
printf("O tipo 'double' ocupa %i bytes e vai de %i a %i\n", sizeof(double), -1.8E+300, 1.8E+300);
printf("O tipo 'void' ocupa %i bytes\n", sizeof(void));

return 0;
    }