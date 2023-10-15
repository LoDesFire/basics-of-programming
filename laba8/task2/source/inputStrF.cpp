void inputStrF(trip *&trips, int arraySize, int startValue, std::ifstream &fin)
{
    for (int i = startValue; i < arraySize; i++) {
        char *type = new char[101], *destination = new char[101], *b_time = new char[6], *e_time = new char[6];
        fin >> trips[i].number;
        fin >> type;
        for (int j = 0; type[j] != '\0'; j++) {
            if (type[j] > 'a' - 1 && type[j] < 'z' + 1)
                type[j] -= 32;
        }
        trips[i].typeOfPlane = type;

        fin >> destination;
        for (int j = 0; destination[j] != '\0'; j++) {
            if (destination[j] > 'a' - 1 && destination[j] < 'z' + 1)
                destination[j] -= 32;
        }
        trips[i].destination = destination;

        fin >> trips[i].b_hours;
        fin >> trips[i].b_minutes;

        b_time[0] = (trips[i].b_hours / 10) % 10 + '0';
        b_time[1] = trips[i].b_hours % 10 + '0';
        b_time[2] = ':';
        b_time[3] = (trips[i].b_minutes / 10) % 10 + '0';
        b_time[4] = trips[i].b_minutes % 10 + '0';
        b_time[5] = '\0';

        trips[i].b_time = b_time;

        fin >> trips[i].e_hours;
        fin >> trips[i].e_minutes;

        e_time[0] = (trips[i].e_hours / 10) % 10 + '0';
        e_time[1] = trips[i].e_hours % 10 + '0';
        e_time[2] = ':';
        e_time[3] = (trips[i].e_minutes / 10) % 10 + '0';
        e_time[4] = trips[i].e_minutes % 10 + '0';
        e_time[5] = '\0';

        trips[i].e_time = e_time;

        printf("№ рейса: %04d | Тип автобуса: %-6s | Пункт назначения: %-15s | Отъезд: %s | Приезд: %s\n", trips[i].number, trips[i].typeOfPlane, trips[i].destination, trips[i].b_time, trips[i].e_time);

    }
}