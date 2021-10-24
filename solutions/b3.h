#pragma once

int MultiplicativePersistence(int64_t num) {
    if (num < 10) {
        return 0;
    }
    int64_t result = 1;
    while (num) {
        result *= num % 10;
        num /= 10;
    }
    return MultiplicativePersistence(result) + 1;
}