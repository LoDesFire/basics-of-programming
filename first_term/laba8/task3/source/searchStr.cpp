void searchStr(trip *&trips, int arraySize) {
    printf("---Выполнение задания---\n");
    char trash, *destination;
    int n = 0;

    printf("Введите пункт назначения: ");
    destination = new char[101];
    scanf("%99s", destination);
    scanf("%c", &trash);
    for (int j = 0; destination[j] != '\0'; j++) {
        if (destination[j] > 'a' - 1 && destination[j] < 'z' + 1)
            destination[j] -= 32;
    }

    int hours = inputLLCompare(0, 23, "До скольки часов вам нужно быть на месте? (0 - 23): "),
    minutes = inputLLCompare(0, 59, "До скольки минут вам нужно быть на месте? (0 - 59): ");


    for (int i = 0; i < arraySize; i++) {
        bool isEqual = true;
        for (int j = 0; (trips[i].destination[j] != '\0' || destination[j] != '\0') && isEqual; j++)
            if (trips[i].destination[j] != destination[j]) isEqual = false;
        if (isEqual && trips[i].e_hours * 60 + trips[i].e_minutes <= hours * 60 + minutes) {
            n++;
            printf("№ рейса: %04d | Тип автобуса: %s | Пункт назначения: %s | Отъезд: %s | Приезд: %s\n", trips[i].un.number, trips[i].typeOfPlane, trips[i].destination, trips[i].b_time, trips[i].e_time);
        }
    }
    delete[] destination;
    if (n == 0) {
        writeEmptyLine();
        writeLine();
        printf("Необходимых рейсов нет.\n");
        writeLine();
    }
}