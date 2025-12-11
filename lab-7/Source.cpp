#include <iostream>
#include <string>
#include <ctime>
#include <locale>

using namespace std;

struct BusRoute {
    string number, busType, destination, departure, pribitie;
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
        cout << "прибытие (часы:минуты): "; cin >> routes[i].pribitie;
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
        int pribitieH = stoi(routes[i].pribitie.substr(0, 2));
        int pribitieM = stoi(routes[i].pribitie.substr(3, 2));
        int pribitieMin = pribitieH * 60 + pribitieM;

        if (pribitieMin < pribitieMin) {
            cout << routes[i].number << " | " << routes[i].busType
                << " | " << routes[i].destination << " | "
                << routes[i].departure << "->" << routes[i].pribitie << "\n";
            found = true;
        }
    }

    if (!found) cout << "сори нет рейсов подходящих\n";

    delete[] routes;
    return 0;
}
