void initStr(flight *&flights, int &arraySize) {
    for (int i = 0; i < arraySize; i++) {
        delete[] flights[i].timeOfDeparture;
        delete[] flights[i].destination;
        delete[] flights[i].typeOfPlane;
    }
    delete[] flights;

    arraySize = inputLLCompare(1, 100000, "Введите количество рейсов: ");
    printf("\n");
    flights = new flight[arraySize];
    inputStr(flights, arraySize, 0);
}