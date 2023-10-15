void resizeStr(trip *&trips, int &arraySize) {
    printf("---Добавление рейсов---\n");
    int newSize = inputLLCompare(1, 100000, "Введите количество рейсов: ");
    printf("\n");
    trip *copy;
    copy = new trip[arraySize + newSize];
    for (int i = 0; i < arraySize; i++) {
        copy[i] = trips[i];
    }
    delete[] trips;

    inputStr(copy, arraySize + newSize, arraySize);
    arraySize += newSize;

    trips = copy;
}