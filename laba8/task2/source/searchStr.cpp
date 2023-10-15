void writeEmptyLine();

void writeLine();

void searchStr(trip *&trips, int arraySize, std::ofstream &fout) {
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

    fout << "--Поиск рейсов в " << destination << " заканчивающихся раньше " << std::setfill('0') << std::setw(2) << hours << ":" << std::setw(2) << minutes << "--\n";

    for (int i = 0; i < arraySize; i++) {
        bool isEqual = true;
        for (int j = 0; (trips[i].destination[j] != '\0' || destination[j] != '\0') && isEqual; j++)
            if (trips[i].destination[j] != destination[j]) isEqual = false;
        if (isEqual && trips[i].e_hours * 60 + trips[i].e_minutes <= hours * 60 + minutes) {
            n++;
            fout << "№ рейса: " << std::setfill('0') << std::setw(4) << std::right << trips[i].number << std::setfill(' ') << " | Тип автобуса: " << std::setw(6) << std::left << trips[i].typeOfPlane << " | Пункт назначения: " << std::setw(15) << std::left << trips[i].destination << " | Отъезд: " << trips[i].b_time << " | Приезд: " << trips[i].e_time << "\n";
            printf("№ рейса: %04d | Тип автобуса: %s | Пункт назначения: %s | Отъезд: %s | Приезд: %s\n", trips[i].number, trips[i].typeOfPlane, trips[i].destination, trips[i].b_time, trips[i].e_time);
        }
    }
    delete[] destination;
    if (n == 0) {
        writeEmptyLine();
        writeLine();
        fout << "Необходимые рейсы не найдены\n";
        printf("Необходимых рейсов нет.\n");
        writeLine();
    }
    fout << "\n";
}