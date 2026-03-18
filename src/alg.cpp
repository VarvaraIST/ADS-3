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
        }
        else {
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

    unsigned int length = 1;
    uint64_t currentNum = num;

    while (currentNum != 1) {
        if (currentNum % 2 == 0) {
            currentNum = currentNum / 2;
        }
        else {
            currentNum = 3 * currentNum + 1;
        }
        length++;
    }
    return length;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
    if (lbound > rbound || lbound < 2) return 0;

    unsigned int bestLength = 0;
    uint64_t bestNumber = 0;

    for (uint64_t num = lbound; num <= rbound; num++) {
        unsigned int currentLength = collatzLen(num);

        if (currentLength > bestLength) {
            bestLength = currentLength;
            bestNumber = num;
        }
    }

    if (maxlen != nullptr) {
        *maxlen = bestLength;
    }
    return bestNumber;
}
