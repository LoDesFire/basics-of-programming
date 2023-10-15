#include <cstdio>

void changeStr(trip *&trips, int arraySize) {
    printf("---Изменение рейса---\n\n");
    printStr(trips, arraySize);
    int ptr = inputLLCompare(1, arraySize, "\nВведите номер строки в списке для изменения поля: ");
    ptr--;
    printf("№ рейса: %04d | Тип автобуса: %s | Пункт назначения: %s | Отъезд: %s | Приезд: %s\n", trips[ptr].number, trips[ptr].typeOfPlane, trips[ptr].destination, trips[ptr].b_time, trips[ptr].e_time);
    printf("1 - Номер рейса\n");
    printf("2 - Тип автобуса\n");
    printf("3 - Пункт назначения\n");
    printf("4 - Время отъезда\n");
    printf("5 - Время приезда\n");
    int field = inputLLCompare(1, 5, "Введите номер поля: ");
    char *type, trash, *destination;
    switch (field) {
        case 1:
            trips[ptr].number = inputLLCompare(0, 9999, "Введите номер рейса (0 - 9999): ");

            break;
        case 2:
            type = new char[101];
            printf("Введите тип автобуса: ");
            scanf("%99s", type);
            scanf("%c", &trash);
            for (int j = 0; type[j] != '\0'; j++) {
                if (type[j] > 'a' - 1 && type[j] < 'z' + 1)
                    type[j] -= 32;
            }
            delete[] trips[ptr].typeOfPlane;
            trips[ptr].typeOfPlane = type;
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

            delete[] trips[ptr].destination;
            trips[ptr].destination = destination;
            break;
        case 4:
            trips[ptr].b_hours = inputLLCompare(0, 23, "Во сколько часов отъезд? (0 - 23): ");
            trips[ptr].b_minutes = inputLLCompare(0, 59, "Во сколько минут отъезд? (0 - 59): ");

            trips[ptr].b_time[0] = (trips[ptr].b_hours / 10) % 10 + '0';
            trips[ptr].b_time[1] = trips[ptr].b_hours % 10 + '0';
            trips[ptr].b_time[2] = ':';
            trips[ptr].b_time[3] = (trips[ptr].b_minutes / 10) % 10 + '0';
            trips[ptr].b_time[4] = trips[ptr].b_minutes % 10 + '0';
            trips[ptr].b_time[5] = '\0';

            break;
        case 5:
            trips[ptr].e_hours = inputLLCompare(0, 23, "Во сколько часов приезд? (0 - 23): ");
            trips[ptr].e_minutes = inputLLCompare(0, 59, "Во сколько минут приезд? (0 - 59): ");

            trips[ptr].e_time[0] = (trips[ptr].e_hours / 10) % 10 + '0';
            trips[ptr].e_time[1] = trips[ptr].e_hours % 10 + '0';
            trips[ptr].e_time[2] = ':';
            trips[ptr].e_time[3] = (trips[ptr].e_minutes / 10) % 10 + '0';
            trips[ptr].e_time[4] = trips[ptr].e_minutes % 10 + '0';
            trips[ptr].e_time[5] = '\0';

            break;
        default:
            break;
    }
}