#include <stdio.h>

struct fraction {int numerator; int denominator};

int gcd(int u, int v) {
    int t;
    while (u > 0) {
        if (u < v) {
            t = u; u = v; v = t % u;
        }
        u = u - v;
    }
    return v;
}

struct fraction reduce(struct fraction toReduce) {
    int divisor = gcd(toReduce.numerator, toReduce.denominator);
    toReduce.numerator /= divisor;
    toReduce.denominator /= divisor;
    return toReduce;
}

main() {
    struct fraction toReduce;
    while (scanf("%d %d", &toReduce.numerator, &toReduce.denominator) != EOF) {
        if (toReduce.numerator > 0 && toReduce.denominator > 0) {
            toReduce = reduce(toReduce);
            printf("%d %d\n", toReduce.numerator, toReduce.denominator);
        }
    }
}