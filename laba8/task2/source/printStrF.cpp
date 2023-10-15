#include <cstdio>

void printStrF(trip *&trips, int arraySize, std::ofstream &fout) {
    for (int i = 0; i < arraySize; i++) {
        fout << "№ рейса: " << std::setfill('0') << std::setw(4) << std::right << trips[i].number << std::setfill(' ') << " | Тип автобуса: " << std::setw(6) << std::left << trips[i].typeOfPlane << " | Пункт назначения: " << std::setw(15) << std::left << trips[i].destination << " | Отъезд: " << trips[i].b_time << " | Приезд: " << trips[i].e_time << "\n";
    }
}