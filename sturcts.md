# Разбор задачи со структурами

```C
#include<iostream>
#include<iomanip>

using namespace std;

// константы

// длина имени
const int K = 80;
const int N = 5;

// перечисление - пользовательский тип,
// который может иметь экземпляры
// каждый экземпляр может принимать значения
enum status {
    Boss = 1,
    Accountant,
    Secretary,
    It,
    Office
};
// структура, пользовательский тип
// описывает одного сотрудника
// структура может иметь экземпляры
// каждый экземпляр которого описывает
// определенного сотрудника
struct Employee {
    // идентификатор
    int Id;
    // имя
    char Name[K];
    // зарплата
    double Salary;
    // статус
    status Status;
};

void main() {
    // emp - массив типа Empoyee
    // то есть его элементами
    // являются сотрудники
    Employee emp[N];
    // идем по всем сотрудникам
    for (int i = 0; i < N; i++) {
        // присваиваем i-сотруднику
        // идентификатор
        emp[i].Id = i + 1;
        // просим ввести имя i-го сотрудника
        cout << "enter name " << emp[i].Id << " of employee: ";
        // считываем имя сорудника
        cin.getline(emp[i].Name, 80);
        // просим ввести зарплату
        cout << " enter salary " << emp[i].Name << " : ";
        // вводим зарплату
        cin >> emp[i].Salary;
        // просим ввести статус как число
        int st;
        do {
            cout << "enter status of employee (1..5) st= ";
            cin >> st;

        } while (st < 1 || st > 5);

        // кладем статус i-ому сотруднику
        // преобразовав число в конкретное
        // значение статуса
        emp[i].Status = (status) st;
        cin.get();// снимает с потока символ «новая строка»
    }
    // выводим информацию
    cout << setw(10) << "Id" << setw(10) << "Name" << setw(10) << "Salary" << setw(15) << "Status" << endl;
    for (int i = 0; i < N; i++) {
        cout << setw(10) << emp[i].Id << setw(10) << emp[i].Name
             << setw(10) << emp[i].Salary << setw(15);

        // у нас есть status как перечисление
        // но сразу вывести его на экран не получиться
        // нужно вывести вручную как строку

        // swtich-case - синтаксическое
        // упрощение над if-else

        // проверяем статус i-го сотрудника
        // в зависимости от значения статуса
        // выводим необходимое наименование статуса
//        switch (emp[i].Status) {
//            case Boss:
//                cout << "Boss" << endl;
////              // завершает выполнение
//                break;
//            case Accountant:
//                cout << "Accountant" << endl;
//                break;
//            case Secretary:
//                cout << "Secretary" << endl;
//                break;
//            case It:
//                cout << "It" << endl;
//                break;
//            case Office:
//                cout << "Office" << endl;
//                break;
//            default:;
//                break;
//        }

        if (emp[i].Status == Boss) {
            cout << "Boss" << endl;
        } else if (emp[i].Status == Accountant) {
            cout << "Accountant" << endl;
        } else if (emp[i].Status == Secretary) {
            cout << "Secretary" << endl;
        } else if (emp[i].Status == It) {
            cout << "It" << endl;
        } else if (emp[i].Status == Office) {
            cout << "Office" << endl;
        }
    }
}
```
