
#ifndef HEADER_H
#define HEADER_H

#endif //HEADER_H
#include <string>
#include <vector>
struct Student {
    std::string Name;
    std::string LastName;
    std::vector<unsigned> Ratings;
};
class Group {
    std::vector<Student> list_of_students;

public:
    Group(){
        list_of_students = {};
    }

    void add(const Student& student){
        list_of_students.push_back(student);
    }
    std::string remove(const std::string& name){
        for (auto start{list_of_students.begin()}; start !=list_of_students.end(); ++start ){
            if (start->Name == name) {
                list_of_students.erase(start);
                return name;
            }
        }
        return name;
    }
    void sort() {
        int size_vect{0};

        while (size_vect != list_of_students.size()) {
            int min_vect = size_vect;
            for (int i{size_vect}; i < list_of_students.size(); i++) {
                if (list_of_students[i].Name < list_of_students[min_vect].Name) {
                    min_vect = i;
                }
            }

            std::swap(list_of_students[min_vect], list_of_students[size_vect]);
            size_vect ++;
        }
    }
};