void resizeStr(flight *&flights, int &arraySize) {
    printf("---Дополнение списка---\n");
    int newSize = inputLLCompare(1, 100000, "Введите количество рейсов: ");
    printf("\n");
    flight *copy;
    copy = new flight[arraySize + newSize];
    for (int i = 0; i < arraySize; i++) {
        copy[i] = flights[i];
    }
    delete[] flights;

    inputStr(copy, arraySize + newSize, arraySize);
    arraySize += newSize;

    flights = copy;
}