void inputStrF(trip *&trips, int arraySize, int startValue, FILE *f)
{
    for (int i = startValue; i < arraySize; i++) {
        trip tmp;
        fread(&tmp, sizeof(trip), 1, f);

        char type[101], destination[101], b_time[6], e_time[6];
        trips[i].un.number = tmp.un.number;

        for (int j = 0; j < 101; j++) {
            trips[i].typeOfPlane[j] = tmp.typeOfPlane[j];
        }

        for (int j = 0; j < 101; j++) {
            trips[i].destination[j] = tmp.destination[j];
        }

        trips[i].b_hours = tmp.b_hours;
        trips[i].b_minutes = tmp.b_minutes;

        for (int j = 0; j < 6; j++) {
            trips[i].b_time[j] = tmp.b_time[j];
        }

        trips[i].e_hours = tmp.e_hours;
        trips[i].e_minutes = tmp.e_minutes;

        for (int j = 0; j < 6; j++) {
            trips[i].e_time[j] = tmp.e_time[j];
        }

        printf("№ рейса: %04d | Тип автобуса: %-6s | Пункт назначения: %-15s | Отъезд: %s | Приезд: %s\n", trips[i].un.number, trips[i].typeOfPlane, trips[i].destination, trips[i].b_time, trips[i].e_time);

    }
}