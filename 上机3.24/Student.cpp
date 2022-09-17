#include<bits/stdc++.h>
using namespace std;

class Student{
    int no;string name;bool sex;int age;
public:
    Student(int a,string b,char c,int d):no(a),name(b),sex(c),age(d){}
    void show(){
        cout<<"--学生信息--\n"<<"编号："<<no<<"\n姓名："<<name<<
        "\n性别："<<(sex?"男":"女")<<"\n年龄："<<age<<"岁\n";
    }
};

class Lesson{
    int cno;string cname;int chour;
public:
    Lesson(int a,string b,int c):cno(a),cname(b),chour(c){}
    void show(){
        cout<<"--课程信息--\n"<<"编号："<<cno<<"\n名称："<<cname<<
        "\n时长："<<chour<<"小时\n";
    }
};

class SL:public Student,public Lesson{
    int score;
public:
    SL(int a,string b,char c,int d,int e,string f,int g,int s)
        :Student(a,b,c,d),Lesson(e,f,g),score(s){}
    void show(){
        Student::show();
        Lesson::show();
        cout<<"--选课信息--\n得分："<<score<<"分\n";
    }
};

int main(){
    SL sl(1,"张再筵",1,19,1,"数学",8,100);
    sl.show();

    return 0;
}