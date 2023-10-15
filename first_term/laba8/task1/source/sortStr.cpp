
void printStr(flight *&flights, int arraySize);

bool comp1(int a, int b) {
    return a < b + 1;
}

bool comp2(char *a, char *b) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] < b[i])
            return true;
        if (a[i] > b[i])
            return false;
        i++;
    }
    if (a[i] == '\0')
        return true;
    else
        return false;
}

int pivot1(flight a) {
    return a.number;
}

char* pivot2(flight a) {
    return a.typeOfPlane;
}

char* pivot3(flight a) {
    return a.destination;
}

int pivot4(flight a) {
    return a.hours * 60 + a.minutes;
}

template<typename T1>
int partition(flight *&flights, int low, int high, bool (*compare)(T1 a, T1 b), T1 (*pivotF)(flight a)) {

    T1 pivot = pivotF(flights[high]);

    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (compare(pivotF(flights[j]), pivot)) {
            std::swap(flights[j], flights[++i]);
        }
    }

    std::swap(flights[++i], flights[high]);
    return i;
}

template<typename T1>
void quickSort(flight *&flights, int low, int high, bool (*compare)(T1 a, T1 b), T1 (*pivotF)(flight a)) {
    if (low < high) {
        int pi = partition(flights, low, high, compare, pivotF);

        quickSort(flights, pi + 1, high, compare, pivotF);
        quickSort(flights, low, pi - 1, compare, pivotF);
    }
}


void sortStr(flight *&flights, int arraySize) {
    printf("---Сортировка по полю---\n");
    printf("1 - Номер рейса\n");
    printf("2 - Тип самолета\n");
    printf("3 - Пункт назначения\n");
    printf("4 - Время вылета\n");
    int field = inputLLCompare(1, 4, "Введите номер поля: ");
    switch (field) {
        case 1:
            //Сортировка по номеру рейса
            quickSort(flights, 0, arraySize - 1, comp1, pivot1);
            break;
        case 2:
            //Сортировка по типу самолета
            quickSort(flights, 0, arraySize - 1, comp2, pivot2);
            break;
        case 3:
            //Сортировка по пункту назначения
            quickSort(flights, 0, arraySize - 1, comp2, pivot3);
            break;
        case 4:
            //сортировка по времени
            quickSort(flights, 0, arraySize - 1, comp1, pivot4);
            break;
    }
    printStr(flights, arraySize);
}