#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>

using namespace std;

enum Specialty { KN, INF, ME, PI, TD };

string specialtyStr[] = { "Комп'ютерні науки", "Інформатика", "Математика та екноміка", " Фізика та інформатика", "Трудове навчання" };

struct Student {
    string prizv;
    unsigned kurs;
    Specialty specialty;
    unsigned gradePhys;
    int gradeMath;
    union {
        unsigned gradeProg;
        unsigned gradeMetod;
        unsigned gradePed;
    };
};

void Create(Student* s, const int k);
void Print(Student* s, const int k);
void physStat(Student* s, const int k, int& threeCount, int& fourCount, int& fiveCount);
int goodMathPhys(Student* s, const int k);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int k;
    cout << "Кількість студентів: "; cin >> k;
    int threeCount = 0, fourCount = 0, fiveCount = 0;

    Student* s = new Student[k];

    Create(s, k);
    Print(s, k);
    physStat(s, k, threeCount, fourCount, fiveCount);

    cout << "Кількість 3 за фізику: " << threeCount << endl;
    cout << "Кількість 4 за фізику: " << fourCount << endl;
    cout << "Кількість 5 за фізику: " << fiveCount << endl;

    cout << "Кількість студентів, які підпадають під заданий критерій: " << goodMathPhys(s, k) << endl;


    system("pause");
    cin.get();
    return 0;
}

void Create(Student* s, const int k) {
    int specialty;
    for (int i = 0; i < k; i++) {
        cout << "Студент №: " << i + 1 << ": " << endl;
        cin.ignore();
        cout << "Прізвище: ";
        getline(cin, s[i].prizv);
        cout << "Курс: "; cin >> s[i].kurs;
        cout << "Спеціальність (0 - Комп'ютерні науки, 1 - Інформатика, 2 - Математика та екноміка, 3 - Фізика та інформатика, 4 - Трудове навчання): ";
        cin >> specialty;
        s[i].specialty = (Specialty)specialty;
        cout << "Оцінка з фізики: "; cin >> s[i].gradePhys;
        cout << "Оцінка з математики: "; cin >> s[i].gradeMath;
        switch (s[i].specialty) {
        case KN:
            cout << "Оцінка з програмування: "; cin >> s[i].gradeProg;
            break;
        case INF:
            cout << "Оцінка з чисельних методоів: "; cin >> s[i].gradeMetod;
            break;
        default:
            cout << "Оцінка педагогіки: "; cin >> s[i].gradePed;
            break;
        }

        cout << endl;
    }

}

void Print(Student* s, const int k) {
    cout << "====================================================================================================================================================================================================" << endl;
    cout << "|  No  |    Прізвище    |  Курс  |      Спеціальність      |   Оцінка з фізкики   |   Оцінка з математики   |   Оцінка з програмування   |   Оцінка з чисельних методоів   |   Оцінка педагогіки   |" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < k; i++) {
        cout << "| " << setw(3) << right << i + 1 << "  ";
        cout << "| " << setw(15) << left << s[i].prizv
            << "|   " << setw(3) << right << s[i].kurs << "  "
            << "| " << setw(24) << left << specialtyStr[s[i].specialty]
            << "| " << setw(20) << right << s[i].gradePhys << " "
            << "| " << setw(23) << right << s[i].gradeMath << " ";
        switch (s[i].specialty) {
        case KN:
            cout << "| " << setw(26) << fixed << right << s[i].gradeProg
                 << " |" << setw(34) << "|" << setw(24) << "|" << endl;
            break;
        case INF:
            cout << "|" << setw(30)
                 << "| " << right << fixed << setw(31) << s[i].gradeMetod << " |" << setw(24) << "|" << endl;
            break;
        default:
            cout << "|" << setw(29)
                 << "|" << setw(35) << "| " << setw(21) << s[i].gradePed << " |" << endl;
            break;
        }
            
    }
    cout << "====================================================================================================================================================================================================" << endl;
    cout << endl;

}

void physStat(Student* s, const int k, int& threeCount, int& fourCount, int& fiveCount) {
    for (int i = 0; i < k; i++) {
        if (s[i].gradePhys == 3) {
            threeCount++;
        }
        else if (s[i].gradePhys == 4) {
            fourCount++;
        }
        else if (s[i].gradePhys == 5) {
            fiveCount++;
        }
    }
}


int goodMathPhys(Student* s, const int k) {
    int n = 0;
    for (int i = 0; i < k; i++) {
        if ((s[i].gradeMath == 4 || s[i].gradeMath == 5) && (s[i].gradePhys == 4 || s[i].gradePhys == 5))
            n++;
    }
    return n;
}
