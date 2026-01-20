#include <stdio.h>

int main() {
    int n = 20;
    int i;

    for (i = 1; i <= n; i = i + 1) {
        if (i % 15 == 0) {
            printf("FizzBuzz\n");
        } else if (i % 3 == 0) {
            printf("Fizz\n");
        } else if (i % 5 == 0) {
            printf("Buzz\n");
        } else {
            printf("Number\n");
        }
    }

    return 0;
}
