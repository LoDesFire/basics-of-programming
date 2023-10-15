void inputStr(trip *&trips, int arraySize, int startValue)
{
    for (int i = startValue; i < arraySize; i++) {
        char *type = new char[101], *destination = new char[101], trash, *b_time = new char[6], *e_time = new char[6];
        trips[i].number = inputLLCompare(0, 9999, "Введите номер рейса (0 - 9999): ");

        printf("Введите тип автобуса: ");
        scanf("%99s", type);
        for (int j = 0; type[j] != '\0'; j++) {
            if (type[j] > 'a' - 1 && type[j] < 'z' + 1)
                type[j] -= 32;
        }
        trips[i].typeOfPlane = type;

        printf("Введите пункт назначения: ");
        scanf("%99s", destination);
        for (int j = 0; destination[j] != '\0'; j++) {
            if (destination[j] > 'a' - 1 && destination[j] < 'z' + 1)
                destination[j] -= 32;
        }
        trips[i].destination = destination;

        scanf("%c", &trash);
        printf("Во сколько часов выезд? (0 - 23): ");
        trips[i].b_hours = inputLLCompare(0, 23, "");

        printf("Во сколько минут выезд? (0 - 59): ");
        trips[i].b_minutes = inputLLCompare(0, 59, "");

        b_time[0] = (trips[i].b_hours / 10) % 10 + '0';
        b_time[1] = trips[i].b_hours % 10 + '0';
        b_time[2] = ':';
        b_time[3] = (trips[i].b_minutes / 10) % 10 + '0';
        b_time[4] = trips[i].b_minutes % 10 + '0';
        b_time[5] = '\0';

        trips[i].b_time = b_time;

        trips[i].e_hours = inputLLCompare(0, 23, "Во сколько часов приезд? (0 - 23): ");

        trips[i].e_minutes = inputLLCompare(0, 59, "Во сколько минут приезд? (0 - 59): ");

        e_time[0] = (trips[i].e_hours / 10) % 10 + '0';
        e_time[1] = trips[i].e_hours % 10 + '0';
        e_time[2] = ':';
        e_time[3] = (trips[i].e_minutes / 10) % 10 + '0';
        e_time[4] = trips[i].e_minutes % 10 + '0';
        e_time[5] = '\0';

        trips[i].e_time = e_time;

        printf("№ рейса: %04d | Тип автобуса: %s | Пункт назначения: %s | Отъезд: %s | Приезд: %s\n", trips[i].number, trips[i].typeOfPlane, trips[i].destination, trips[i].b_time, trips[i].e_time);
    }
}