void initStrF(trip *&trips, int &arraySize, std::ifstream &fin) {
    for (int i = 0; i < arraySize; i++) {
        delete[] trips[i].destination;
        delete[] trips[i].typeOfPlane;
        delete[] trips[i].b_time;
        delete[] trips[i].e_time;
    }
    delete[] trips;

    fin.clear();
    fin.seekg(std::ios::beg);

    fin >> arraySize;
    trips = new trip[arraySize];
    inputStrF(trips, arraySize, 0, fin);
}