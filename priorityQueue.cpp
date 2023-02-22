#include <iostream>
#include <queue>
#include <functional>

using namespace std;

struct Student
{
    int id;
    int math, eng;
    Student(int num, int m, int e) : id(num), math(m), eng(e) {}

    bool operator<(const Student s) const
    {
        return this->id > s.id;
    }
};

int main(int argc, char const *argv[])
{
    priority_queue<Student> pq;

    pq.push(Student(3, 100, 50));
    pq.push(Student(1, 60, 50));
    pq.push(Student(2, 80, 50));
    pq.push(Student(4, 90, 50));
    pq.push(Student(5, 70, 40));

    while (!pq.empty())
    {

        Student ts = pq.top();
        pq.pop();
        cout << "(학번, 수학, 영어)" << ts.id << ' ' << ts.math << ' ' << ts.eng << endl;
    }

    return 0;
}
