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

    uint64_t length = 1;
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

unsigned int seqCollatz(uint64_t *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
    if (lbound > rbound || lbound < 2) {
        *maxlen = 0;
        return 0;
    }

    uint64_t topLength = 0;
    uint64_t bestNumber = lbound;

    for (uint64_t num = lbound; num <= rbound; ++num) {
        uint64_t len = collatzLen(num);
        if (len > topLength) {
            topLength = len;
            bestNumber = num;
        }
    }

    *maxlen = topLength;

    return bestNumber;
}
