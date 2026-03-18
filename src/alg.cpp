// Copyright 2026 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
    if (num == 0) return 0;

    uint64_t maxValue = num;
    uint64_t currentN = num;

    while (currentN != 1) {
        if (currentN % 2 == 0) {
            currentN = currentN / 2;
        } else {
            currentN = 3 * currentN + 1;
        }

        if (currentN > maxValue) {
            maxValue = currentN;
        }
    }

    return maxValue;
}

unsigned int collatzLen(uint64_t num) {
    if (num == 0) return 0;
    if (num == 1) return 1;

    unsigned int length = 1;
    uint64_t currentN = num;

    while (currentN != 1) {
        if (currentN % 2 == 0) {
            currentN = currentN / 2;
        } else {
            currentN = 3 * currentN + 1;
        }
        length++;
    }

    return length;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
    if (lbound > rbound || lbound < 2) {
        *maxlen = 0;
        return 0;
    }

    unsigned int topLength = 0;
    unsigned int bestNumber = lbound;

    for (uint64_t num = lbound; num <= rbound; num++) {
        unsigned int currentLength = collatzLen(num);
        if (currentLength > topLength) {
            topLength = currentLength;
            bestNumber = num;
        }
    }

    *maxlen = topLength;

    return bestNumber;
}
