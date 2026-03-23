#include <stdio.h>

// Recursive function to compute a^b
int power(int a, int b) {
    if (b == 0)
        return 1;        // base case

    return a * power(a, b - 1);
}

int main() {
    int a, b;

    // Input
    scanf("%d %d", &a, &b);

    // Output
    printf("%d", power(a, b));

    return 0;
}