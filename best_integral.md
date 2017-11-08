# Расчет интеграла Рауфа Баграмовича

```C
// библиотека ввода-вывода cin/cout
#include<iostream>
// библиотека файлового ввода-вывода, ifstream и ofstream
#include<fstream>
// для мат. функций
#include<cmath>
// для отступов
#include<iomanip>
// для работы со строками
#include<cstring>

using namespace std;

// длина столбца
const int LENGTH_COLUMN = 20;
// отступ слева
const int INDENT = 7;
// длина таблицы
const int LENGTH_TABLE = 43;

// компонент функции интегрирования
double fi(double x) {
    return cos(x) * cos(x);
}

// компонент функции интегрирования
double psi(double x) {
    return (1 - x * x) / (1 + x * x);
}

// сама функция интегрирования
double f(double x, double t) {
    return psi(x) * fi(x + t / (1 + x * x));
}

// &f - ссылка на файл
// x - динамический массив длины n
void create(ifstream &f, double *x, int n) {
    // заполняем динамический массив из файла
    for (int i = 0; i < n; i++) {
         f >> x[i];
    }
}
// вывод массива в файл
void show(ofstream &f, double *x, int n) {
    // вывели массив x длины n
    for (int i = 0; i < n; i++) {
        f << x[i] << ' ';
    }
    // перевели вывод на новую строку
    f << endl;
}

// вычисление интеграла в промежутке от a до b с точностью e
// и параметром t
double integral(double a, double b, double e, double t) {
    double h, J1, J2;
    int i, n;
    n = 1;
    // вычисляем шаг интегрирования
    h = (b - a) / n;
    // посчитали для разбиения n = 1
    J2 = h * f(a + h / 2, t);
    do {
        // кидаем в J1 полученное значение J2
        J1 = J2;
        // для нового значения интеграла увеличиваем кол-во разбиений
        n = n * 2;
        // получаем новый шаг
        h = (b - a) / n;
        // J2 пока пустой
        J2 = 0;
        // для нового разбиения считаем сумму полученных прямоугольников
        for (i = 0; i <= n - 1; i++) {
            // каждый раз прибавляем высоту нового прямоугольника,
            // в точке "посередние" нового отрезка
            J2 = J2 + f(a + (2 * i + 1) * h / 2, t);
        }
        // умножаем сумму всех высот на ширину - получим сумму площадей всех прямоугольников
        J2 = J2 * h;
    } 
    // делаем до тех пор, пока разница между результатами разбиения n и 2n 
        // больше e
    while (fabs(J2 - J1) > e);
    return J2;
}

void star(ofstream &f, int n, int m) {
    f.width(n); // начинаем писать в файле с отступа n
    for (int i = 0; i < m; i++) {
        f << '*';
    }
    f << endl;
}

void star1(ofstream &f, int n, int m) {
    f.width(n);
    f << '*';
    for (int i = 0; i < m; i++) {
        f.width(LENGTH_COLUMN + 1);
        f << '*';
    }
    f << endl;
}

// выводим таблицу в файл f с массивом иксов и игреков, и отступом 
// между строками m
void table(ofstream &f, double *x, double *y, int m, char a[2][15]) {
    // начинаем с новой строки
    f << endl;
    // рисуем звездочки
    star(f, INDENT + 1, LENGTH_TABLE);
    // рисуем звездочки
    star1(f, INDENT + 1, 2);
    // задаем отступ для новых звездочек
    f.width(INDENT + 1);
    f << '*';
    // выводим значения строк - названия столбцов интегрирования
    // a[0] - "x[i]"
    // a[1] - "y[i]"
    for (int i = 0; i < 2; i++) {
        // задаем отступ
        f.width(10);
        // печатаем название колонки
        f << a[i];
        // задаем отступ 
        f.width(11);
        // печатаем звездочку
        f << '*';
    }
    f << endl;
    // опять рисуем звездочки .... =(
    star1(f, INDENT + 1, 2);
    star(f, INDENT + 1, LENGTH_TABLE);
    star1(f, INDENT + 1, 2);
    // печатаем резульататы интегрирования
    for (int i = 0; i < m; i++) {
        f.width(INDENT + 1);
        f << '*';
        f.width(LENGTH_COLUMN - 5);
        f << x[i];
        f.width(6);
        f << '*';
        f.width(LENGTH_COLUMN - 5);
        f << y[i];
        f.width(6);
        f << '*';
        f << endl;
        // печатаем звездочки
        star1(f, INDENT + 1, 2);
        star(f, INDENT + 1, LENGTH_TABLE);
        star1(f, INDENT + 1, 2);
    }
}

int main() {
    // ifstream и ofstream - типы (такие как int) для работы с файлами
    // по сути - то же самое что cin cout, только настроено на файлы
    ifstream in("C:\\Users\\admin.WIN-IPM3OA3VQNQ\\ClionProjects\\ParseNumber\\arb.txt");
    ofstream out("C:\\Users\\admin.WIN-IPM3OA3VQNQ\\ClionProjects\\ParseNumber\\trans.txt");
    double a, b, eps;
    int m, i;
    // строка с названием задачи
    char name_task[80];
    // название колонок
    char name_x_y[2][15];
    // считываем название задачи
    in.getline(name_task, 80);

    // считали названия столбцов
    for (int i = 0; i < 2; i++) {
        in >> name_x_y[i];
    }
    // сразу вывели в результирующий файл название задачи
    out << name_task << endl;

    // выводим название столбцов
    for (int i = 0; i < 2; i++) {
        out << name_x_y[i] << ' ';
    }
    out << endl;
    // выводим всю остальную информацию
    in >> a >> b >> eps >> m;
    out << "a= " << a << endl;
    out << "b= " << b << endl;
    out << "eps= " << eps << endl;
    out << "m= " << m << endl;
    // объявляем динамические массивы
    double *t, *y;
    t = new double[m];
    y = new double[m];
    // заполняем массив данными
    create(in, t, m);
    out << "arguments : " << endl;
    // выводим таблицу с аргументами
    show(out, t, m);
    // считаем интеграл
    for (int i = 0; i < m; i++) {
        y[i] = integral(a, b, eps, t[i]);
    }

    out << "value of integeral" << endl;
    show(out, y, m);
    out << endl;

    out << setw(15 + strlen(name_task)) << name_task << endl;
    table(out, t, y, m, name_x_y);

    in.close();
    out.close();
    delete[]t;
    delete[]y;

    return 0;
}
```