#include <iostream>
#include <string>

using namespace std;

struct Train {
    string dest;    // пункт назначения
    int num;        // номер поезда
    string time;    // время отправления
};

int main() {
    // ввод информации о поездах
    Train arr[5];
    cout << "[ENTERING INFORMATION ABOUT TRAINS]" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "---Train #" << i + 1 << "---" << endl;
        cout << "Destination: ";
        cin >> arr[i].dest;
        cout << "Train number: ";
        cin >> arr[i].num;
        cout << "Departure time: ";
        cin >> arr[i].time;
    }
    cout << endl;
    // сортировка по номерам поездов
    Train temp;
    for (int i = 0; i < 5 - 1; i++) {
        for (int j = 0; j < 5 - i - 1; j++) {
            if (arr[j].num > arr[j + 1].num) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    // просмотр информации о поезде
    int flag, _num = 0; // flag - для проверки существования поезда в списке, _num - введённый номер 
    cout << "[TRAIN INFORMATION]" << endl;
    cout << "---To view information about the train, enter it's number" << endl;
    cout << "---To exit the menu, enter 0---" << endl;
    while (1) {
        cout << "Train number: ";
        cin >> _num;
        if (_num == 0) {
            break;
        }
        flag = 0;
        for (int i = 0; i < 5; i++) {
            if (arr[i].num == _num) {
                cout << "Destination: ";
                cout << arr[i].dest << endl;
                cout << "Departure time: ";
                cout << arr[i].time << endl << endl;
                flag = 1;
            }
        }
        if (flag == 0) {
            cout << "There is no train with this number!" << endl;
        }
    }
}
