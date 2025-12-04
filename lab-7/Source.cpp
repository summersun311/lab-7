#include <iostream>
#include <string>
#include <ctime>
#include <locale>

using namespace std;

struct BusRoute {
    string number, busType, destination, departure, arrival;
};

int main() {
    setlocale(LC_ALL, "ru");
    int n;
    cout << "Количество рейсов: ";
    cin >> n;

    BusRoute* routes = new BusRoute[n];

    for (int i = 0; i < n; i++) {
        cout << "Рейс " << i + 1 << ":\n";
        cout << "Номер: "; cin >> routes[i].number;
        cout << "Тип: "; cin >> routes[i].busType;
        cout << "Пункт: "; cin >> routes[i].destination;
        cout << "Отправление (ЧЧ:ММ): "; cin >> routes[i].departure;
        cout << "Прибытие (ЧЧ:ММ): "; cin >> routes[i].arrival;
    }

    string target;
    cout << "Прибыть до (ЧЧ:ММ): ";
    cin >> target;

    // Разбиваем время на часы и минуты
    int targetH = stoi(target.substr(0, 2));
    int targetM = stoi(target.substr(3, 2));
    int targetMin = targetH * 60 + targetM;

    cout << "\nПодходящие рейсы:\n";
    bool found = false;

    for (int i = 0; i < n; i++) {
        // Аналогично разбираем время прибытия рейса
        int arrivalH = stoi(routes[i].arrival.substr(0, 2));
        int arrivalM = stoi(routes[i].arrival.substr(3, 2));
        int arrivalMin = arrivalH * 60 + arrivalM;

        if (arrivalMin < targetMin) {
            cout << routes[i].number << " | " << routes[i].busType
                << " | " << routes[i].destination << " | "
                << routes[i].departure << "->" << routes[i].arrival << "\n";
            found = true;
        }
    }

    if (!found) cout << "Нет подходящих рейсов\n";

    delete[] routes;
    return 0;
}