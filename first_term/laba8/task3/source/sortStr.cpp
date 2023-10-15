
void printStr(trip *&trips, int arraySize);

bool comp(int a, int b) {
    return a + 1 > b;
}

int pivot1(trip a) {
    return a.un.number;
}

int pivot2(trip a) {
    return (int)a.typeOfPlane[0];
}

int pivot3(trip a) {
    return (int)a.destination[0];
}

int pivot4(trip a) {
    return a.b_hours * 60 + a.b_minutes;
}

int pivot5(trip a) {
    return a.e_hours * 60 + a.e_minutes;
}

template<typename T1>
void sort(trip *&trips, int arraySize, bool (*compare)(T1 a, T1 b), T1 (*pivotF)(trip a)) {
    for (int i = 0; i < arraySize - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < arraySize; j++)
        {
            if (compare(pivotF(trips[j]), pivotF(trips[min_index])))
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            std::swap(trips[i], trips[min_index]);
        }
    }
}

void sortStr(trip *&trips, int arraySize, FILE *f) {
    printf("---Сортировка по полю---\n");
    printf("1 - Номер рейса\n");
    printf("2 - Тип автобуса\n");
    printf("3 - Пункт назначения\n");
    printf("4 - Время отъезда\n");
    printf("5 - Время приезда\n");
    int field = inputLLCompare(1, 5, "Введите номер поля: ");
    switch (field) {
        case 1:
            //Сортировка по номеру рейса
            sort(trips, arraySize, comp, pivot1);
            break;
        case 2:
            //Сортировка по типу самолета
            sort(trips, arraySize, comp, pivot2);
            break;
        case 3:
            //Сортировка по пункту назначения
            sort(trips, arraySize, comp, pivot3);
            break;
        case 4:
            //сортировка по времени
            sort(trips, arraySize, comp, pivot4);
            break;
        case 5:
            //сортировка по времени
            sort(trips, arraySize, comp, pivot5);
            break;
    }
    printStr(trips, arraySize);

    fseek(f, sizeof(int), SEEK_SET);
    for (int i = 0; i < arraySize; i++) {
        fwrite(&trips[i], sizeof(trips[i]), 1, f);
    }
    fflush(f);
}