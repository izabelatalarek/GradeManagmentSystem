#include "DatabaseManager.h"


void DatabaseManager::add_entry(std::string student_name, int newGrade) {

    std::pair<std::string, int> student1("Rafalek", 5);
    std::pair<std::string, int> student2("Iza", 2);
    std::pair<std::string, int> student3("Kuba", 6);
    schoolDiary.insert(student1);
    schoolDiary.insert(student2);
    schoolDiary.insert(student3);
    schoolDiary.insert({ student_name, newGrade});
}

void DatabaseManager::remove_entry(std::string nameToRemove)
{
    if (schoolDiary.erase(nameToRemove) == 1)
        std::cout << "Student " << nameToRemove << " was removed.\n";
    else
        std::cout << "Student " << nameToRemove << " is not exist.\n";
}

void DatabaseManager::modify_entry(std::string student_name, int newGrade) {

    schoolDiary[student_name] = newGrade;

}

std::vector <DatabaseManager::student> DatabaseManager::get_entries()
{
    std::vector <student> studentsList(schoolDiary.size());
    std::transform(schoolDiary.begin(), schoolDiary.end(), studentsList.begin(),
        [](auto a) {return student{a.first, a.second};});

    return studentsList;
}

void DatabaseManager::menu() {


    int choice;

    do {
        menu_list();

        std::cin >> choice;
        switch (choice) {

        case 1:
        {
            std::string newStudent;
            int newGrade;
            std::cout << "Enter name: ";
            std::cin >> newStudent;
            std::cout << "Enter grade: ";
            std::cin >> newGrade;

            add_entry(newStudent, newGrade);

            break;

        }
        case 2:
        {
            std::string nameToRemove;
            std::cout << "Enter student's name to remove: ";
            std::cin >> nameToRemove;
            remove_entry(nameToRemove);
            break;
        }
        case 3:
        {
            std::string newStudent;
            std::cout << "Enter name: ";
            std::cin >> newStudent;
            auto search = schoolDiary.find(newStudent);
            if (search != end(schoolDiary)) {
                int newGrade;
                std::cout << "Enter new grade: ";
                std::cin >> newGrade;
                modify_entry(newStudent, newGrade);

            }
            else {
                std::cout << "This student is unevailable ;) Try later...\n";
            }


            break;
        }
        case 4:

            /* auto it = begin(schoolDiary);
            for (it; it != end(schoolDiary); it++) {
                std::cout << "\t Name: " << it->first << "\t Grade: " << it->second << std::endl;
            }

            break;
            */

            
            auto a = get_entries();
            std::cout << "xd";
            break;
        }

    } while (choice != 5);

}

void DatabaseManager::menu_list()
{
    std::cout << "1. Add student \n";
    std::cout << "2. Remove student \n";
    std::cout << "3. Modify student \n";
    std::cout << "4. Get students \n";
    std::cout << "5. Exit \n";
}