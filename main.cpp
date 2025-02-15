#include "header.h"
#include <cassert>
int main() {
    Student student4 = {"Vasya", "iu9-54", {3, 5, 4, 5, 5, 4}};
    Student student5 = {"Alice", "iu9-54", {5, 5, 4, 3, 5, 4}};

    Group group;
    group.add(student4);
    group.add(student5);
    group.sort();
    assert(group.remove("Vasya") == student4.Name);
    assert(group.remove("Alice") == student5.Name);
    return 0;
}
