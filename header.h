
#ifndef HEADER_H
#define HEADER_H

#endif //HEADER_H
#include <string>
#include <vector>
#include <set>
struct Student {
    std::string Name;
    std::string GroupName;
    std::vector<unsigned> Ratings;
    std::vector<std::string> Subjects;
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
    // Задание 1
    void SortByName() {
        size_t size_vect{0};

        while (size_vect != list_of_students.size()) {
            size_t min_vect = size_vect;
            for (size_t i{size_vect}; i < list_of_students.size(); i++) {
                if (list_of_students[i].Name < list_of_students[min_vect].Name) {
                    min_vect = i;
                }
            }
            std::swap(list_of_students[min_vect], list_of_students[size_vect]);
            size_vect ++;
        }
    }
    // Задание 2
private:
    static int Arith_mean(const std::vector<unsigned>&vect) {
        unsigned sum{};
        for (size_t i{}; i < vect.size(); i++) {
            sum += vect[i];
        }
        return sum / vect.size();
    }
public:
    void SortByRating() {
        size_t size_vect{0};

        while (size_vect != list_of_students.size()) {
            size_t min_vect = size_vect;
            for (size_t i{size_vect}; i < list_of_students.size(); i++) {
                if (Arith_mean(list_of_students[i].Ratings) < Arith_mean(list_of_students[min_vect].Ratings)) {
                    min_vect = i;
                }
            }

            std::swap(list_of_students[min_vect], list_of_students[size_vect]);
            size_vect ++;
        }
    }
    // Задание 3
    size_t CountTwoness() {
        size_t num{};
        for (size_t i{}; i < list_of_students.size(); i++) {
            for(size_t j{}; j < list_of_students.size(); j++) {
                if (list_of_students[i].Ratings[j] == 2) {
                    num += 1;
                    break;
                }
            }
        }
        return num;
    }
    // Задание 4
    size_t CountExcellent() {
        size_t sum{};
        for (size_t i{}; i < list_of_students.size(); i++) {
            size_t num = 0;
            for(size_t j{}; j < list_of_students[i].Ratings.size(); j++) {
                if (list_of_students[i].Ratings[j] == 5) {
                    num += 1;
                }
                if (num == 5) {
                    sum += 1;
                }
            }
        }
        return sum;
    }
    // Задание 5
    std::vector<Student> VectorMathExcellent() {
        std::vector<Student> Math5;
        size_t index{};

        for (size_t i{}; i < list_of_students.size(); i++) {
            for (size_t j{}; j < list_of_students[i].Subjects.size(); j++) {
                if (list_of_students[i].Subjects[j] == "Math") {
                    index = j;
                    break;
                }
            }
            if (index != 0) {
                if (list_of_students[i].Ratings[index] == 5) {
                    Math5.push_back(list_of_students[i]);
                }
            }
        }
        return Math5;
    }
    // Задание 6
    std::vector<std::string> GroupsId() {
        std::set<std::string> group_set{};
        std::vector<std::string> group_list{};

        for (size_t i{}; i < list_of_students.size(); i++) {
            group_set.insert(list_of_students[i].GroupName);
        }
        for (const std::string& groupId : group_set) {
            group_list.push_back(groupId);
        }
        return group_list;
    }
};