void resizeStr(trip *&trips, int &arraySize, FILE *f) {
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

    fseek(f, 0, SEEK_SET);
    fwrite(&arraySize, sizeof(arraySize), 1, f);

    fseek(f, sizeof(trip) * (arraySize - newSize), SEEK_CUR);
    for (int i = arraySize - newSize; i < arraySize; i++) {
        fwrite(&trips[i], sizeof(trips[i]), 1, f);
    }
    fflush(f);
}