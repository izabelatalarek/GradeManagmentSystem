#pragma once
#include <string>
#include <unordered_map>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>


class DatabaseManager
{
public:
    DatabaseManager() = default;
    ~DatabaseManager() = default;

    struct student {
        std::string student_name;
        int grade;
    };


    std::unordered_map <std::string, int> schoolDiary;

    void add_entry(std::string student_name, int newGrade);
    void remove_entry(std::string student_name);
    void modify_entry(std::string name, int newGrade);

    std::vector <student> get_entries();

    //friend std::ostream& operator<<(std::ostream&, const databaseManager&);
    //friend std::ostream& operator>>(std::ostream&, const databaseManager&);

    void menu();
    void menu_list();
};
