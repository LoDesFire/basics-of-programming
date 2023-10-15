void writeEmptyLine();

void writeLine();

void searchStr(flight *&flights, int arraySize) {
    printf("---Поиск рейсов по пункту назначения---\n");
    char trash, *destination;
    int n = 0;
    destination = new char[101];
    printf("Введите пункт назначения: ");
    scanf("%99s", destination);
    scanf("%c", &trash);
    for (int j = 0; destination[j] != '\0'; j++) {
        if (destination[j] > 'a' - 1 && destination[j] < 'z' + 1)
            destination[j] -= 32;
    }
    for (int i = 0; i < arraySize; i++) {
        bool isEqual = true;
        for (int j = 0; (flights[i].destination[j] != '\0' || destination[j] != '\0') && isEqual; j++)
            if (flights[i].destination[j] != destination[j]) isEqual = false;
        if (isEqual) {
            n++;
            printf("№ рейса: %d | Тип самолета: %s | Пункт назначения: %s | Вылет: %s\n", flights[i].number, flights[i].typeOfPlane, flights[i].destination, flights[i].timeOfDeparture);
        }
    }
    delete[] destination;
    if (n == 0) {
        writeEmptyLine();
        writeLine();
        printf("Заданных рейсов нет.\n");
        writeLine();
    }
}