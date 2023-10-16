#include<iostream>
using namespace std;

class Stud{
    public:

    void name(){
        cout<<"college name is IITN \n";
    }

    void branch(){
        cout<<"college branch is CSH \n";
    }
};

class student : public Stud{
    public:
    void roll(){
        cout<<"My roll number is BT22CSH023 \n";
    }
};

int main(){
    student s1;
    s1.name();
    s1.branch();
    s1.roll();
}