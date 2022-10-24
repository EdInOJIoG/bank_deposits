    #include <iostream> 
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;

//Описание структуры
struct Vkladik {
    int nomer;
    string familia;
    string imya;
    string otchestvo;
    string nazvanie;
    int month_perc;
    int itog;
    int summa;
};

const int N = 10;
Vkladik vklad[N];

//Функция вызова контекстного меню
void text() {
    cout << "\nТАБЛИЦА ВКЛАДОВ\n"
        "------------------------------------------------\n"
        "Полная информация -> нажмите 1;\n"
        "По типам вклада -> нажмите 2;\n"
        "Поиск по средней сумме выплаты -> нажмите 3;\n"
        "Выход из меню -> нажмите 4;\n";
}

//Функция для заполнения 2-х последних столбцов таблицы исходя из названия вклада
int sort_perc() {
    for (int i = 0; i < N; i++)
    {
        if (vklad[i].nazvanie == "Срочный")
            vklad[i].month_perc = vklad[i].summa * 0.02;
        else if (vklad[i].nazvanie == "Пенсионный")
            vklad[i].month_perc = vklad[i].summa * 0.01;
        else
            vklad[i].month_perc = vklad[i].summa * 0.025;

        if (vklad[i].nazvanie == "Срочный")
            vklad[i].itog = vklad[i].summa * 1.24;
        else if (vklad[i].nazvanie == "Пенсионный")
            vklad[i].itog = vklad[i].summa * 1.12;
        else
            vklad[i].itog = vklad[i].summa * 1.3;
    }
    return 0;
}

//Функция сортировки по фамилии и вывода на экран таблицы
int data() {
    
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
        {
            if (strcmp(vklad[i].familia.c_str(), vklad[j].familia.c_str()) > 0)
                swap(vklad[i], vklad[j]);
        }
    
    cout << setiosflags(ios::left);
    cout << "Номер  счета \t\t     " << "ФИО\t\t   " << "Вид вклада\t" << " Сумма вклада (в руб.)    " << "Годовой %\t" << "Сумма по % за месяц\t" << "Сумма к выплате" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < N; ++i)
    {   
        cout << "    ";
        printf("%04d", vklad[i].nomer);
        cout << "        ";
        cout << setw(10) << vklad[i].familia;
        cout << setw(10) << vklad[i].imya;
        cout << setw(15) << vklad[i].otchestvo;
        cout << setw(21) << vklad[i].nazvanie;
        cout << setw(21) << vklad[i].summa;
        if (vklad[i].nazvanie == "Срочный")
            cout << setw(19) << "24%";
        else if (vklad[i].nazvanie == "Пенсионный")
            cout << setw(19) << "12%";
        else
            cout << setw(19) << "30%";
        cout << setw(22) << vklad[i].month_perc;
        cout << vklad[i].itog;
        cout << endl;
    }
    return 0;
}

//Функция выбора вида вклада, сортировки таблицы по сумме вклада и вывода таблицы на экран
int sort_nazvanie() {
    string vid;
    int k = 0;
    int choose{ 0 };

    n:
    cout << "Введите 1, если хотите увидеть записи по вкладу 'Пенсионный' " << endl;
    cout << "Введите 2, если хотите увидеть записи по вкладу 'Срочный' " << endl;
    cout << "Введите 3, если хотите увидеть записи по вкладу 'Депозит' " << endl;

    //Функция проверки правильности ввода
    cin >> choose;
    if (cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << "Это не цифра" << endl;
        goto n;
    }
    else if (choose <= 0 || choose >= 4) {
        cout << "Необходимо ввести число в заданном диапазоне" << endl;
        goto n;
    }

    //Функция сортировки по сумме вклада
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
        {
            if (vklad[i].summa > vklad[j].summa)
                swap(vklad[i], vklad[j]);
        }

    cout << setiosflags(ios::left);
    cout << "Номер  счета \t\t     " << "ФИО\t\t   " << "Вид вклада\t" << " Сумма вклада (в руб.)    " << "Годовой %\t" << "Сумма по % за месяц\t" << "Сумма к выплате" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < N; i++) {
        if (choose == 1 && vklad[i].nazvanie == "Пенсионный")
        {
            cout << "    ";
            printf("%04d", vklad[i].nomer);
            cout << "        ";
            cout << setw(10) << vklad[i].familia;
            cout << setw(10) << vklad[i].imya;
            cout << setw(15) << vklad[i].otchestvo;
            cout << setw(21) << vklad[i].nazvanie;
            cout << setw(21) << vklad[i].summa;
            if (vklad[i].nazvanie == "Срочный")
                cout << setw(19) << "24%";
            else if (vklad[i].nazvanie == "Пенсионный")
                cout << setw(19) << "12%";
            else
                cout << setw(19) << "30%";
            cout << setw(22) << vklad[i].month_perc;
            cout << vklad[i].itog;
            cout << endl;
            k++;
        }
        if (choose == 2 && vklad[i].nazvanie == "Срочный")
        {
            cout << "    ";
            printf("%04d", vklad[i].nomer);
            cout << "        ";
            cout << setw(10) << vklad[i].familia;
            cout << setw(10) << vklad[i].imya;
            cout << setw(15) << vklad[i].otchestvo;
            cout << setw(21) << vklad[i].nazvanie;
            cout << setw(21) << vklad[i].summa;
            if (vklad[i].nazvanie == "Срочный")
                cout << setw(19) << "24%";
            else if (vklad[i].nazvanie == "Пенсионный")
                cout << setw(19) << "12%";
            else
                cout << setw(19) << "30%";
            cout << setw(22) << vklad[i].month_perc;
            cout << vklad[i].itog;
            cout << endl;
            k++;
        }
        if (choose == 3 && vklad[i].nazvanie == "Депозит")
        {
            cout << "    ";
            printf("%04d", vklad[i].nomer);
            cout << "        ";
            cout << setw(10) << vklad[i].familia;
            cout << setw(10) << vklad[i].imya;
            cout << setw(15) << vklad[i].otchestvo;
            cout << setw(21) << vklad[i].nazvanie;
            cout << setw(21) << vklad[i].summa;
            if (vklad[i].nazvanie == "Срочный")
                cout << setw(19) << "24%";
            else if (vklad[i].nazvanie == "Пенсионный")
                cout << setw(19) << "12%";
            else
                cout << setw(19) << "30%";
            cout << setw(22) << vklad[i].month_perc;
            cout << vklad[i].itog;
            cout << endl;
            k++;
        }
    }
    if (k == 0)
        cout << "Данного вида вклада не существует." << endl;
    return 0;
}

//Функция выбора сумма выплаты, сортировки таблицы по сумме выплаты и вывода таблицы на экран
int sort_sredn() {
    int s = 0, sredn;
    int choose{ 0 };

    c:
    cout << "Введите 1, если хотите увидеть записи по вкладам, сумма выплат которых больше средней суммы выплаты " << endl;
    cout << "Введите 2, если хотите увидеть записи по вкладам, сумма выплат которых больше меньше суммы выплаты " << endl;

    //Функция проверки правильности ввода
    cin >> choose;
    if (cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << "Это не цифра" << std::endl;
        goto c;
    }
    else if (choose <= 0 || choose >= 3) {
        cout << "Необходимо ввести число в заданном диапазоне" << endl;
        goto c;
    }

    //Функция сортировки по сумме выплат
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
        {
            if (vklad[i].itog < vklad[j].itog)
                swap(vklad[i], vklad[j]);
        }

    //Функция подсчета среднего значения итоговых выплат
    for (int i = 0; i < N; i++)
    {
        s += vklad[i].itog;
    }

    sredn = s / N;

    cout << setiosflags(ios::left);
    cout << "Номер  счета \t\t     " << "ФИО\t\t   " << "Вид вклада\t" << " Сумма вклада (в руб.)    " << "Годовой %\t" << "Сумма по % за месяц\t" << "Сумма к выплате" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < N; i++)
    {
        if (choose == 1 && vklad[i].itog >= sredn)
        {
            cout << "    ";
            printf("%04d", vklad[i].nomer);
            cout << "        ";
            cout << setw(10) << vklad[i].familia;
            cout << setw(10) << vklad[i].imya;
            cout << setw(15) << vklad[i].otchestvo;
            cout << setw(21) << vklad[i].nazvanie;
            cout << setw(21) << vklad[i].summa;
            if (vklad[i].nazvanie == "Срочный")
                cout << setw(19) << "24%";
            else if (vklad[i].nazvanie == "Пенсионный")
                cout << setw(19) << "12%";
            else
                cout << setw(19) << "30%";
            cout << setw(22) << vklad[i].month_perc;
            cout << vklad[i].itog;
            cout << endl;
        }
        if (choose == 2 && vklad[i].itog <= sredn)
        {
            cout << "    ";
            printf("%04d", vklad[i].nomer);
            cout << "        ";
            cout << setw(10) << vklad[i].familia;
            cout << setw(10) << vklad[i].imya;
            cout << setw(15) << vklad[i].otchestvo;
            cout << setw(21) << vklad[i].nazvanie;
            cout << setw(21) << vklad[i].summa;
            if (vklad[i].nazvanie == "Срочный")
                cout << setw(19) << "24%";
            else if (vklad[i].nazvanie == "Пенсионный")
                cout << setw(19) << "12%";
            else
                cout << setw(19) << "30%";
            cout << setw(22) << vklad[i].month_perc;
            cout << vklad[i].itog;
            cout << endl;
        }
    }
    return 0;
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    int a, choose;
    ifstream F("vklad.txt");
    
    //Считываем информацию из файла .txt
    if (!F)
    {
        cout << "Error opening file!" << endl;
        system("pause");
        return 0;
    }
    
    //Запись информации из файла в структуру vklad
    for (int i = 0; i < N; i++)
        F >> vklad[i].nomer >> vklad[i].familia >> vklad[i].imya >> vklad[i].otchestvo >> vklad[i].nazvanie >> vklad[i].summa;
        
    F.close();
    sort_perc();

    //Вызов контекстного меню
    t: text();

    //Функция проверки правильности ввода
    cin >> choose;
    if (cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << "Это не цифра" << std::endl;
        goto t;
    }
    else if (choose <= 0 || choose >= 5) {
        cout << "Необходимо ввести число в заданном диапазоне" << endl;
        goto t;
    }

    //Функция выбора 1 из пунктов контекстного меню
    switch (choose) {
    case 1:
        data();
        goto t;
    case 2: 
        sort_nazvanie();
        goto t;
    case 3:
        sort_sredn();
        goto t;
    case 4:
        cout << "Спасибо. Всего доброго!\n";
        system("pause");
        return 0;
    }
}