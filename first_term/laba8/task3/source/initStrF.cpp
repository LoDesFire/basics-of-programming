void initStrF(trip *&trips, int &arraySize, FILE *f) {
    delete[] trips;

    fseek(f, 0, SEEK_SET);
    fread(&arraySize, sizeof(arraySize), 1, f);

    trips = new trip[arraySize];
    inputStrF(trips, arraySize, 0, f);
    fflush(f);
}