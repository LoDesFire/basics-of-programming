void inputStr(flight *&flights, int arraySize, int startValue)
{
    for (int i = startValue; i < arraySize; i++) {
        char *type = new char[101], *destination = new char[101], trash, *time = new char[6];
        flights[i].number = inputLLCompare(0, 9999, "Введите номер рейса (0 - 9999): ");

        printf("Введите тип самолета: ");
        scanf("%99s", type);
        for (int j = 0; type[j] != '\0'; j++) {
            if (type[j] > 'a' - 1 && type[j] < 'z' + 1)
                type[j] -= 32;
        }
        flights[i].typeOfPlane = type;

        printf("Введите пункт назначения: ");
        scanf("%99s", destination);
        for (int j = 0; destination[j] != '\0'; j++) {
            if (destination[j] > 'a' - 1 && destination[j] < 'z' + 1)
                destination[j] -= 32;
        }
        flights[i].destination = destination;

        scanf("%c", &trash);
        printf("Во сколько часов вылет? (0 - 23): ");
        flights[i].hours = inputLLCompare(0, 23, "");

        printf("Во сколько минут вылет? (0 - 59): ");
        flights[i].minutes = inputLLCompare(0, 59, "");

        time[0] = (flights[i].hours / 10) % 10 + '0';
        time[1] = flights[i].hours % 10 + '0';
        time[2] = ':';
        time[3] = (flights[i].minutes / 10) % 10 + '0';
        time[4] = flights[i].minutes % 10 + '0';
        time[5] = '\0';

        flights[i].timeOfDeparture = time;

        printf("%d - № рейса: %d | Тип самолета: %s | Пункт назначения: %s | Вылет: %s\n\n", i + 1, flights[i].number, flights[i].typeOfPlane, flights[i].destination, flights[i].timeOfDeparture);
    }
}