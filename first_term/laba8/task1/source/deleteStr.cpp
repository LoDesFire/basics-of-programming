void deleteStr(flight *&flights, int &arraySize) {
    printf("---Удаление рейса---\n\n");
    printStr(flights, arraySize);
    int delElement = inputLLCompare(1, arraySize, "\nВведите номер строки в списке: ");
    delElement--;
    flight *copy;
    copy = new flight[arraySize - 1];
    bool skipElement = false;
    for (int i = 0; i < arraySize - 1; i++) {
        if (i == delElement) {
            delete[] flights[i].destination;
            delete[] flights[i].typeOfPlane;
            delete[] flights[i].timeOfDeparture;
            skipElement = true;
        }
        copy[i] = flights[i + skipElement];
    }
    delete[] flights;
    arraySize--;
    flights = copy;
}