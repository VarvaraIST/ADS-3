// Copyright 2026 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
    if (num == 0) return 0;

    uint64_t maxValue = num;
    while (num != 1) {
        if (num % 2 == 0) {
            num = num / 2;
        } else {
            num = 3 * num + 1;
        }

        if (num > maxValue) {
            maxValue = num;
        }
    }

    return maxValue;
}

unsigned int collatzLen(uint64_t num) {
    if (num == 0) return 0;
    if (num == 1) return 1;

    uint64_t length = 1;

    while (num != 1) {
        if (num % 2 == 0) {
            num = num / 2;
        } else {
            num = 3 * num + 1;
        }
        length++;
    }

    return length;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
    unsigned int maxiLength = 0;
    unsigned int bestNumber = lbound;

    for (uint64_t num = lbound; num <= rbound; num++) {
        unsigned int len = collatzLen(num);

        if (len > maxiLength) {
            maxiLength = len;
            bestNumber = num;
        }
    }

    if (maxlen != nullptr) {
        *maxlen = maxiLength;
    }
    return bestNumber;
}
