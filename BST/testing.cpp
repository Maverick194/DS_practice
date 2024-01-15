#include <iostream>
using namespace std;

class Emp{
public:
    int id;
    string name;
    double salary;
    Emp* left;
    Emp* right;

    Emp(int i, string n, double s): id(i), name(n), salary(s) {}
};

class Employee{
private:
    Emp* root;
public:
    Employee(): root(NULL){}

    void insert(int id, string name, double salary){
        root = 
    }
}
int main(){
    
    return 0;
}