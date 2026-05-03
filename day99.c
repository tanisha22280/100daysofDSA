#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int position;
    int speed;
} Car;

int cmp(const void *a, const void *b) {
    return ((Car*)b)->position - ((Car*)a)->position;
}

int main() {
    int n, target;
    scanf("%d %d", &n, &target);

    Car cars[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &cars[i].position);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &cars[i].speed);
    }

    qsort(cars, n, sizeof(Car), cmp);

    int fleets = 0;
    double lastTime = 0.0;

    for (int i = 0; i < n; i++) {
        double time = (double)(target - cars[i].position) / cars[i].speed;

        if (time > lastTime) {
            fleets++;
            lastTime = time;
        }
    }

    printf("%d\n", fleets);

    return 0;
}