#include <cstdio>

void printStr(trip *&trips, int arraySize) {
    printf("Все рейсы: \n");
    for (int i = 0; i < arraySize; i++) {
        printf("%d - № рейса: %04d | Тип автобуса: %-6s | Пункт назначения: %-15s | Отъезд: %s | Приезд: %s\n", i + 1, trips[i].number, trips[i].typeOfPlane, trips[i].destination, trips[i].b_time, trips[i].e_time);
    }
}