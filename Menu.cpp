#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <process.h>
#include <windows.h>
#include <ctype.h>
#define Path "d:\\Work\\Students.txt"

struct FIO {
    char name[50];
    char surname[50];
};

struct Hostel {
    FIO date;
    char numberGruppa[20];
    double averageScore;
    double income;
}students;

void AddNewFile(int kol_stud) {
    system("cls");
    FILE* fp;
    Hostel* students = new Hostel[kol_stud];
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    if ((fp = fopen(Path, "wb")) == NULL) {
        printf("Cannot open file.\n"); exit(1);
    }

    for (int i = 0; i < kol_stud; i++) {
        system("cls");
        printf("Student ¹%d\n", i + 1);
        puts("Enter the last name and first name of the students: ");
        gets_s(students->date.surname);
        gets_s(students->date.name);
        puts("Enter the number group (letter and numbers) of the students: ");
        gets_s(students->numberGruppa);
        puts("Enter average score of the students: ");
        scanf("%lf", &students->averageScore);
        puts("Enter income for one family member: ");
        scanf("%lf", &students->income);
        fwrite(students, sizeof(Hostel), 1, fp);
    }
    fclose(fp);
}

void ViewFile(int kol_stud) {
    FILE* fp;
    Hostel* students = new Hostel[kol_stud];
    system("cls");

    if ((fp = fopen(Path, "rb")) == NULL) {
        printf("Cannot open file.\n"); exit(1);
    }

    int i = 0;

    while (fread(students, sizeof(Hostel), 1, fp) != NULL) {
        printf("\n Last name and First name = %s %s  Number group = %s  Average score = %.1lf  Income for one family member = %.2lf \n", students->date.surname, students->date.name, students->numberGruppa, students->averageScore, students->income);
    }
    fclose(fp);
    _getch();
}

void DeletyEntry(int kol_stud) {
    FILE* fp, * output;
    Hostel* students = new Hostel[kol_stud];
    Hostel* tmpS = new Hostel[kol_stud - 1];


    if ((fp = fopen(Path, "rb")) == NULL) {
        printf("Cannot open file."); exit(1);
    }

    int i = 0;

    while (fread(&students[i], sizeof(Hostel), 1, fp) != NULL) {
        i++;
    }
    fclose(fp);

    int recordNumber;
    system("cls");

    do {
        printf("delete entry: ");
        scanf("%d", &recordNumber);
    } while (!(recordNumber <= kol_stud));


    if ((output = fopen(Path, "wb")) == NULL) {
        printf("Cannot open file."); exit(1);
    }

    int j = 0;

    for (int i = 0; i < kol_stud; i++) {

        if (i == recordNumber) {

            continue;
        }
        else {
            memcpy((tmpS + j)->date.name, (students + i)->date.name, 50);
            memcpy((tmpS + j)->date.surname, (students + i)->date.surname, 50);
            memcpy((tmpS + j)->numberGruppa, (students + i)->numberGruppa, 20);
            (tmpS + j)->averageScore = (students + i)->averageScore;
            (tmpS + j)->income = (students + i)->income;
            j++;
        }
    }

    fwrite(tmpS, sizeof(Hostel), j, output);

    fclose(output);
}


void EditEntry(int kol_stud) {
    FILE* fp, * output;
    Hostel* students = new Hostel[kol_stud];

    if ((fp = fopen(Path, "rb")) == NULL) {
        printf("Cannot open file."); exit(1);
    }

    int i = 0;

    while (fread(&students[i], sizeof(Hostel), 1, fp) != NULL) {
        i++;
    }
    fclose(fp);

    int recordNumber;
    system("cls");

    do {
        printf("edit entry: ");
        scanf("%d", &recordNumber);
    } while (!(recordNumber <= kol_stud));


    if ((output = fopen(Path, "wb")) == NULL) {
        printf("Cannot open file."); exit(1);
    }

    int j = 0;

    for (int i = 0; i < kol_stud; i++) {

        if (i == recordNumber) {
            system("cls");
            puts("Enter the last name and first name of the students: ");
            gets_s((students + i)->date.surname);
            gets_s((students + i)->date.name);
            puts("Enter the number group (letter and numbers) of the students: ");
            gets_s((students + i)->numberGruppa);
            puts("Enter average score of the students: ");
            scanf("%lf", &(students + i)->averageScore);
            puts("Enter income for one family member: ");
            scanf("%lf", &(students + i)->income);
            break;
        }

    }

    fwrite(students, sizeof(Hostel), kol_stud, fp);
    fclose(fp);
}
void AddNewEntry(int kol_stud) {
    FILE* fp, * output;
    Hostel* students = new Hostel[kol_stud];
    Hostel* tmpS = new Hostel[kol_stud + 1];

    if ((fp = fopen(Path, "rb")) == NULL) {
        printf("Cannot open file."); exit(1);
    }

    int i = 0;

    while (fread(&students[i], sizeof(Hostel), 1, fp) != NULL) {
        i++;
    }
    fclose(fp);
    system("cls");

    if ((output = fopen(Path, "ab")) == NULL) {
        printf("Cannot open file."); exit(1);
    }

    int j = 0;

    for (int i = 0; i < kol_stud; i++) {
        system("cls");
        
            system("cls");
            puts("Enter the last name and first name of the students: ");
            gets_s((students + i)->date.surname);
            gets_s((students + i)->date.name);
            puts("Enter the number group (letter and numbers) of the students: ");
            gets_s((students + i)->numberGruppa);
            puts("Enter average score of the students: ");
            scanf("%lf", &(students + i)->averageScore);
            puts("Enter income for one family member: ");
            scanf("%lf", &(students + i)->income);

            memcpy((tmpS + j)->date.name, (students + i)->date.name, 50);
            memcpy((tmpS + j)->date.surname, (students + i)->date.surname, 50);
            memcpy((tmpS + j)->numberGruppa, (students + i)->numberGruppa, 20);
            (tmpS + j)->averageScore = (students + i)->averageScore;
            (tmpS + j)->income = (students + i)->income;
            j++;
            break;      
    }
    fwrite(tmpS, sizeof(Hostel), j, output);
    fclose(output);
}

void Edit(int kol_stud) {
    system("cls");
    int actionNumber;

    do
    {
        printf("1 - delete entry");
        printf("\n2 - edit entry");
        printf("\n3 - add new entry");
        printf("\n4 - exit");

        printf("\n\n Enter action number: ");
        scanf("%d", &actionNumber);
        fflush(stdin);

        if (actionNumber < 1 || actionNumber > 4) {
            printf("Please, enter number ot 1 do 4\n\n");
        }
    } while (actionNumber < 1 || actionNumber > 4);

    switch (actionNumber)
    {
    case 1: {
        DeletyEntry(kol_stud);
        break;
    }
    case 2:
        EditEntry(kol_stud);
        break;
    case 3:
        AddNewEntry(kol_stud);
        break;
    case 4:
        break;
    }
}


void TaskCompletion(int kol_stud) {
    FILE* fp;

    Hostel* students = new Hostel[kol_stud];

    system("cls");

    if ((fp = fopen(Path, "rb")) == NULL) {
        printf("Cannot open file.\n"); exit(1);
    }

    int i = 0;

    while (fread(&students[i], sizeof(Hostel), 1, fp) != NULL) {
        i++;
    }
    fclose(fp);
    system("cls");
    Hostel buf; 

    for (int i = 0; i < kol_stud; i++) 
    {
        for (int j = 0; j < kol_stud - 1; j++) {        
            if (students[i].income > students[j].income) {
                buf = students[j + 1];
                students[j + 1] = students[j];
                students[j] = buf;
            }
        }
    }
    int min_salary = 30; 
    min_salary *= 2; 
    
    bool fl = false;
    while (fl == false)
    {
        fl = true;
        for (int i = 0; i < kol_stud; i++)
        {
            for (int j = 0; j < kol_stud - 1; j++) {
                if (students[i].income > min_salary)
                {
                    if (students[i].income < students[j].income)
                    {
                        buf = students[j + 1];
                        students[j + 1] = students[j];
                        students[j] = buf;
                        fl = false;
                    }
                }
            }
        }
    }


    if ((fp = fopen(Path, "wb")) == NULL) {
        printf("Cannot open file.\n"); exit(1);
    }

    for (int i = 0; i < kol_stud; i++) { 
        printf("\n Last name and First name = %s %s  Number group = %s  Average score = %.1lf  Income for one family member = %.2lf \n", students[i].date.surname, students[i].date.name, students[i].numberGruppa, students[i].averageScore, students[i].income);
        fwrite(students, sizeof(Hostel), 1, fp);
    }
    fclose(fp);
}


int main()
{
    setlocale(LC_CTYPE, "Russian");
    system("cls");
    fflush(stdin);
    int menu = 0;
    int kol_stud;
    while (true) {
        system("cls");
        puts("Select a menu item:");
        puts("1-Create a new file");
        puts("2-View file");
        puts("3-Correction of file entries (change, add new entry, delete entry)");
        puts("4-Completing the task");
        puts("5-Exit");
        scanf_s("%d", &menu);
        switch (menu) {
        case 1: {
            system("cls");
            printf("Enter the number of students: ");
            scanf("%d", &kol_stud);
            AddNewFile(kol_stud);
            break;
        }
        case 2: {
            ViewFile(kol_stud);
            break;
        }
        case 3: {
            Edit(kol_stud);
            break;
        }
        case 4: {
            TaskCompletion(kol_stud);
            _getch();
            break;
        }
        case 5: {
            exit(0);
        }
        default: {
            system("cls");
            fflush(stdin);
            puts("Invalid selection, press any key to return to the menu");
            _getch();
        }
        }
    }
    _getch();
}