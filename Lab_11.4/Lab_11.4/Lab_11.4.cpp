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
    cout << "������ ������ ��� ������ �����, �� ����������� � ����������� ��� ��������: ";
    cin >> targetChar;

    AnalyzeFile("t.txt", "result.txt", targetChar);

    return 0;
}

void AnalyzeFile(const char* fName, const char* resultFile, char targetChar) {
    ifstream file(fName);
    if (!file.is_open()) {
        cerr << "������� �������� ����� ��� �������: " << fName << endl;
        return;
    }

    ofstream result(resultFile);
    if (!result.is_open()) {
        cerr << "������� �������� ����� ��� ������: " << resultFile << endl;
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

  
    cout << "ʳ������ �����: " << lineCount << endl;
    cout << "����������� ������� �����: " << maxLength << endl;
    cout << "ʳ������ ������� �����: " << emptyLines << endl;

    if (!specialLine.empty()) {
        cout << "�����, �� ���������� � ���������� �������� '" << targetChar << "': " << specialLine << endl;
    }
    else {
        cout << "���� �����, �� ����������� � ����������� �������� '" << targetChar << "'." << endl;
    }

   
    result << "ʳ������ �����: " << lineCount << endl;
    result << "����������� ������� �����: " << maxLength << endl;
    result << "ʳ������ ������� �����: " << emptyLines << endl;

    if (!specialLine.empty()) {
        result << "�����, �� ���������� � ���������� �������� '" << targetChar << "': " << specialLine << endl;
    }
    else {
        result << "���� �����, �� ����������� � ����������� �������� '" << targetChar << "'." << endl;
    }

    result.close();
}
