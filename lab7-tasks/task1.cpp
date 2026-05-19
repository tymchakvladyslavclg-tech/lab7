#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

struct User {
    string name;
    string role;
    string password;
};

class AuthSystem {
public:
    void registerUser() {
        User u;
        cin.ignore();

        cout << "Прізвище Ім'я: ";
        getline(cin, u.name);

        cout << "1 - Учень, 2 - Викладач: ";
        int r;
        cin >> r;
        u.role = (r == 1) ? "student" : "teacher";

        cout << "Пароль: ";
        cin >> u.password;

        ofstream file("users.txt", ios::app);
        file << u.name << "|" << u.role << "|" << u.password << endl;

        cout << "Зареєстровано!\n";
    }

    bool login(User &loggedUser) {
        string name, pass;
        cin.ignore();

        cout << "Прізвище Ім'я: ";
        getline(cin, name);

        cout << "Пароль: ";
        cin >> pass;

        ifstream file("users.txt");
        string n, r, p;

        while (getline(file, n, '|') &&
               getline(file, r, '|') &&
               getline(file, p)) {

            if (n == name && p == pass) {
                loggedUser.name = n;
                loggedUser.role = r;
                loggedUser.password = p;
                return true;
            }
        }

        return false;
    }
};

class TestSystem {
public:

    void showTests() {
        ifstream file("testsQuasiton.txt");
        string subject, test, question, correct, a1, a2;

        int i = 1;
        while (getline(file, subject, '|') &&
               getline(file, test, '|') &&
               getline(file, question, '|') &&
               getline(file, correct, '|') &&
               getline(file, a1, '|') &&
               getline(file, a2)) {

            cout << i++ << ". " << subject << " - " << test << endl;
        }
    }

    void takeTest(string username) {
        ifstream file("testsQuasiton.txt");

        vector<vector<string>> tests;
        string line;

        while (getline(file, line)) {
            vector<string> parts;
            string temp;

            for (char c : line) {
                if (c == '|') {
                    parts.push_back(temp);
                    temp = "";
                } else {
                    temp += c;
                }
            }
            parts.push_back(temp);

            if (parts.size() == 6)
                tests.push_back(parts);
        }

        if (tests.empty()) {
            cout << "Нема тестів!\n";
            return;
        }

        cout << "Оберіть предмет:\n";
        cout << "1. Математика\n2. Фізика\n3. Українська\n";
        int subjectChoice;
        cin >> subjectChoice;

        string subject;
        if (subjectChoice == 1) subject = "Математика";
        if (subjectChoice == 2) subject = "Фізика";
        if (subjectChoice == 3) subject = "Українська";

        vector<vector<string>> selected;

        for (auto &t : tests) {
            if (t[0] == subject)
                selected.push_back(t);
        }

        if (selected.empty()) {
            cout << "Нема питань\n";
            return;
        }

        ofstream out("results.txt", ios::app);

        cout << "\n=== Вступний іспит: " << subject << " ===\n";

        for (int i = 0; i < selected.size(); i++) {
            auto &t = selected[i];

            cout << "\nПитання " << i + 1 << ": " << t[2] << endl;
            cout << "1. " << t[3] << endl;
            cout << "2. " << t[4] << endl;
            cout << "3. " << t[5] << endl;

            int answer;
            cout << "Відповідь: ";
            cin >> answer;

            string answerText;
            if (answer == 1) answerText = t[3];
            else if (answer == 2) answerText = t[4];
            else if (answer == 3) answerText = t[5];
            else answerText = "невірний варіант";

            out << username << "|"
                << subject << "|"
                << t[2] << "|"
                << answerText << endl;
        }

        cout << "\nІспит завершено. Очікуйте перевірку.\n";
    }
};

void createDefaultTests() {
    ifstream check("testsQuasiton.txt");
    if (check.good()) return;

    ofstream file("testsQuasiton.txt");

    file << "Математика|Вступний іспит|6*4=?|12|24|18\n";
    file << "Математика|Вступний іспит|10+15=?|20|25|30\n";
    file << "Математика|Вступний іспит|9*3=?|27|21|24\n";

    file << "Фізика|Вступний іспит|Одиниця сили?|Ньютон|Паскаль|Джоуль\n";
    file << "Фізика|Вступний іспит|Швидкість світла?|150000|300000|100000\n";
    file << "Фізика|Вступний іспит|Символ напруги?|U|I|R\n";

    file << "Українська|Вступний іспит|Скільки букв?|32|33|34\n";
    file << "Українська|Вступний іспит|Правильне слово?|Книга|Кныга|Книґа\n";
    file << "Українська|Вступний іспит|Частина мови 'бігти'?|дієслово|іменник|прикметник\n";

    file.close();
}

class StudentMenu {
public:
    void show(string name) {
        TestSystem ts;

        int c;
        do {
            cout << "\n1. Пройти тест\n2. Мої оцінки\n3. Вихід\n";
            cin >> c;

            if (c == 1) {
                ts.takeTest(name);
            }

            if (c == 2) {
                ifstream file("grades.txt");
                string n, g;

                while (getline(file, n, '|') && getline(file, g)) {
                    if (n == name) {
                        cout << "Оцінка: " << g << endl;
                    }
                }
            }

        } while (c != 3);
    }
};

class TeacherMenu {
public:
    void showStudents() {
        ifstream file("users.txt");
        string n, r, p;

        while (getline(file, n, '|') &&
               getline(file, r, '|') &&
               getline(file, p)) {

            if (r == "student") {
                cout << n << endl;
            }
        }
    }

    void showGrades() {
        ifstream file("grades.txt");
        string n, s, p;

        while (getline(file, n, '|') &&
               getline(file, s, '|') &&
               getline(file, p)) {

            cout << n + " " + " " + s + " " + p << endl;
        }
    }

    void grade() {
        ifstream file("results.txt");
        vector<string> students;
        string line;

        // 1. список студентів
        while (getline(file, line)) {
            string name = line.substr(0, line.find("|"));

            bool exists = false;
            for (auto &s : students) {
                if (s == name) {
                    exists = true;
                    break;
                }
            }

            if (!exists)
                students.push_back(name);
        }

        if (students.empty()) {
            cout << "Нема результатів\n";
            return;
        }

        cout << "\n=== Студенти ===\n";
        for (int i = 0; i < students.size(); i++) {
            cout << i + 1 << ". " << students[i] << endl;
        }

        int sChoice;
        cout << "Обери студента: ";
        cin >> sChoice;

        if (sChoice < 1 || sChoice > students.size()) return;

        string student = students[sChoice - 1];

        ifstream file2("results.txt");
        vector<string> subjects;

        while (getline(file2, line)) {
            if (line.find(student) == 0) {
                size_t pos1 = line.find("|");
                size_t pos2 = line.find("|", pos1 + 1);

                string subject = line.substr(pos1 + 1, pos2 - pos1 - 1);

                bool exists = false;
                for (auto &s : subjects) {
                    if (s == subject) {
                        exists = true;
                        break;
                    }
                }

                if (!exists)
                    subjects.push_back(subject);
            }
        }

        cout << "\n=== Предмети ===\n";
        for (int i = 0; i < subjects.size(); i++) {
            cout << i + 1 << ". " << subjects[i] << endl;
        }

        int subChoice;
        cout << "Обери предмет: ";
        cin >> subChoice;

        if (subChoice < 1 || subChoice > subjects.size()) return;

        string selectedSubject = subjects[subChoice - 1];

        // 3. показ відповідей
        ifstream file3("results.txt");

        cout << "\n=== Відповіді: " << student << " (" << selectedSubject << ") ===\n";

        while (getline(file3, line)) {
            if (line.find(student) == 0 && line.find(selectedSubject) != string::npos) {

                // розбір
                size_t p1 = line.find("|");
                size_t p2 = line.find("|", p1 + 1);
                size_t p3 = line.find("|", p2 + 1);

                string question = line.substr(p2 + 1, p3 - p2 - 1);
                string answer = line.substr(p3 + 1);

                cout << "- " << question << " -> " << answer << endl;
            }
        }

        // 4. оцінка
        int grade;
        cout << "\nВведіть оцінку: ";
        cin >> grade;

        ofstream out("grades.txt", ios::app);
        out << student << "|" << selectedSubject << "|" << grade << endl;

        cout << "Оцінку збережено!\n";
    }

    void menu() {
        int c;
        do {
            cout << "\n1. Список учнів\n2. Виставити оцінку\n3. Переглянути оцінки\n4. Вихід\n";
            cin >> c;

            if (c == 1) showStudents();
            if (c == 2) grade();
            if(c == 3) showGrades();

        } while (c != 4);
    }
};

int main() {
    createDefaultTests();
    AuthSystem auth;
    User user;

    int choice;

    do {
        cout << "\n1. Вхід\n2. Реєстрація\n3. Вихід\n";
        cin >> choice;

        if (choice == 2) {
            auth.registerUser();
        }

        if (choice == 1) {
            if (auth.login(user)) {
                cout << "Успішний вхід!\n";

                if (user.role == "student") {
                    StudentMenu sm;
                    sm.show(user.name);
                } else {
                    TeacherMenu tm;
                    tm.menu();
                }
            } else {
                cout << "Невірні дані\n";
            }
        }

    } while (choice != 3);

    return 0;
}