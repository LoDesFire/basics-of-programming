#include <cstdio>

void printStr(flight *&flights, int arraySize) {
    printf("Все рейсы: \n");
    for (int i = 0; i < arraySize; i++) {
        printf("%d - № рейса: %d | Тип самолета: %s | Пункт назначения: %s | Вылет: %s\n", i + 1, flights[i].number, flights[i].typeOfPlane, flights[i].destination, flights[i].timeOfDeparture);
    }
}