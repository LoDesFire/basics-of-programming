void deleteStr(trip *&trips, int &arraySize, FILE *f) {
    printf("---Удаление рейса---\n\n");
    printStr(trips, arraySize);
    int delElement = inputLLCompare(1, arraySize, "\nВведите номер строки в списке: ");
    delElement--;
    trip *copy;
    copy = new trip[arraySize - 1];
    bool skipElement = false;
    for (int i = 0; i < arraySize - 1; i++) {
        if (i == delElement) {
            skipElement = true;
        }
        copy[i] = trips[i + skipElement];
    }
    delete[] trips;
    arraySize--;
    trips = copy;

    fseek(f, 0, SEEK_SET);
    fwrite(&arraySize, sizeof(arraySize), 1, f);

    fseek(f, sizeof(trip) * (delElement - 1), SEEK_CUR);
    for (int i = delElement; i < arraySize; i++) {
        fwrite(&trips[i], sizeof(trips[i]), 1, f);
    }
    fflush(f);
}