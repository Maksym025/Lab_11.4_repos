#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;

void AnalyzeFile(const char* fName, const char* resultFile, char targetChar);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char targetChar;
    cout << "Введіть символ для пошуку рядків, що починаються і закінчуються цим символом: ";
    cin >> targetChar;

    AnalyzeFile("t.txt", "result.txt", targetChar);

    return 0;
}

void AnalyzeFile(const char* fName, const char* resultFile, char targetChar) {
    ifstream file(fName);
    if (!file.is_open()) {
        cerr << "Помилка відкриття файлу для читання: " << fName << endl;
        return;
    }

    ofstream result(resultFile);
    if (!result.is_open()) {
        cerr << "Помилка відкриття файлу для запису: " << resultFile << endl;
        return;
    }

    int lineCount = 0;            
    int maxLength = 0;            
    int emptyLines = 0;          
    string specialLine = "";    
    string line;

    while (getline(file, line)) {
        lineCount++;

        
        if (line.empty()) {
            emptyLines++;
            continue;
        }

        
        if (line.length() > maxLength) {
            maxLength = line.length();
        }

        
        if (line.front() == targetChar && line.back() == targetChar) {
            specialLine = line;
        }
    }

    file.close();

  
    cout << "Кількість рядків: " << lineCount << endl;
    cout << "Максимальна довжина рядка: " << maxLength << endl;
    cout << "Кількість порожніх рядків: " << emptyLines << endl;

    if (!specialLine.empty()) {
        cout << "Рядок, що починається і закінчується символом '" << targetChar << "': " << specialLine << endl;
    }
    else {
        cout << "Немає рядків, що починаються і закінчуються символом '" << targetChar << "'." << endl;
    }

   
    result << "Кількість рядків: " << lineCount << endl;
    result << "Максимальна довжина рядка: " << maxLength << endl;
    result << "Кількість порожніх рядків: " << emptyLines << endl;

    if (!specialLine.empty()) {
        result << "Рядок, що починається і закінчується символом '" << targetChar << "': " << specialLine << endl;
    }
    else {
        result << "Немає рядків, що починаються і закінчуються символом '" << targetChar << "'." << endl;
    }

    result.close();
}
