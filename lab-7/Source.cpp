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
        cout << "рейс " << i + 1 << ":\n";
        cout << "номер: "; cin >> routes[i].number;
        cout << "тип: "; cin >> routes[i].busType;
        cout << "пункт: "; cin >> routes[i].destination;
        cout << "отправление (часы:минуты): "; cin >> routes[i].departure;
        cout << "прибытие (часы:минуты): "; cin >> routes[i].arrival;
    }

    string target;
    cout << "нужно прибыть до (часы:минуты): ";
    cin >> target;

    // це разбитие времени на часы и минутес
    int targetH = stoi(target.substr(0, 2));
    int targetM = stoi(target.substr(3, 2));
    int targetMin = targetH * 60 + targetM;

    cout << "\n подходящие рейсы:\n";
    bool found = false;

    for (int i = 0; i < n; i++) {
        // разбиваем время прибытия рейса на часес энд минутес
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

    if (!found) cout << "сори нет рейсов подходящих\n";

    delete[] routes;
    return 0;
}
