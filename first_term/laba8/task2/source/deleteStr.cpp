void deleteStr(trip *&trips, int &arraySize) {
    printf("---Удаление рейса---\n\n");
    printStr(trips, arraySize);
    int delElement = inputLLCompare(1, arraySize, "\nВведите номер строки в списке: ");
    delElement--;
    trip *copy;
    copy = new trip[arraySize - 1];
    bool skipElement = false;
    for (int i = 0; i < arraySize - 1; i++) {
        if (i == delElement) {
            delete[] trips[i].destination;
            delete[] trips[i].typeOfPlane;
            delete[] trips[i].b_time;
            delete[] trips[i].e_time;
            skipElement = true;
        }

        copy[i] = trips[i + skipElement];
    }
    delete[] trips;
    arraySize--;
    trips = copy;
}