#include <cstdio>

void changeStr(flight *&flights, int arraySize) {
    printf("---Изменение рейса---\n\n");
    printStr(flights, arraySize);
    int ptr = inputLLCompare(1, arraySize, "\nВведите номер строки в списке для изменения поля: ");
    ptr--;
    printf("№ рейса: %d | Тип самолета: %s | Пункт назначения: %s | Вылет: %s\n", flights[ptr].number, flights[ptr].typeOfPlane, flights[ptr].destination, flights[ptr].timeOfDeparture);
    printf("1 - Номер рейса\n");
    printf("2 - Тип самолета\n");
    printf("3 - Пункт назначения\n");
    printf("4 - Время вылета\n");
    int field = inputLLCompare(1, 4, "Введите номер поля: ");
    char *type, trash, *destination;
    switch (field) {
        case 1:
            flights[ptr].number = inputLLCompare(0, 9999, "Введите номер рейса (0 - 9999): ");

            break;
        case 2:
            type = new char[101];
            printf("Введите тип самолета: ");
            scanf("%99s", type);
            scanf("%c", &trash);
            for (int j = 0; type[j] != '\0'; j++) {
                if (type[j] > 'a' - 1 && type[j] < 'z' + 1)
                    type[j] -= 32;
            }
            delete[] flights[ptr].typeOfPlane;
            flights[ptr].typeOfPlane = type;
            break;
        case 3:
            destination = new char[101];
            printf("Введите пункт назначения: ");
            scanf("%99s", destination);
            scanf("%c", &trash);
            for (int j = 0; destination[j] != '\0'; j++) {
                if (destination[j] > 'a' - 1 && destination[j] < 'z' + 1)
                    destination[j] -= 32;
            }

            delete[] flights[ptr].destination;
            flights[ptr].destination = destination;
            break;
        case 4:
            flights[ptr].hours = inputLLCompare(0, 23, "Во сколько часов вылет? (0 - 23): ");
            flights[ptr].minutes = inputLLCompare(0, 59, "Во сколько минут вылет? (0 - 59): ");

            flights[ptr].timeOfDeparture[0] = (flights[ptr].hours / 10) % 10 + '0';
            flights[ptr].timeOfDeparture[1] = flights[ptr].hours % 10 + '0';
            flights[ptr].timeOfDeparture[2] = ':';
            flights[ptr].timeOfDeparture[3] = (flights[ptr].minutes / 10) % 10 + '0';
            flights[ptr].timeOfDeparture[4] = flights[ptr].minutes % 10 + '0';
            flights[ptr].timeOfDeparture[5] = '\0';

            break;
        default:
            break;
    }
}