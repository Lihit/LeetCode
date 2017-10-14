#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class person
{
public:
    string name;
    int age;
    string tel;
    double salary;
};
void main1() {
    person p1, p2, p3, p4, p5;
    p1.name = "王1";
    p1.age = 31;
    p2.name = "王2";
    p2.age = 32;
    p3.name = "王3";
    p3.age = 33;
    p4.name = "王4";
    p4.age = 4;
    p5.name = "王5";
    p5.age = 35;
    multimap<string, person> map1;
    map1.insert(make_pair("sale",p1));
    map1.insert(make_pair("sale",p2));
    map1.insert(make_pair("development",p3));
    map1.insert(make_pair("development",p4));
    map1.insert(make_pair("Financial",p5));
/*    map1[(string)"sale"] = p1;
    map1[(string)"sale"] = p2;
    map1[(string)"development"] = p3;
    map1[(string)"development"] = p4;
    map1[(string)"Financial"] = p5;*/
    for (multimap<string, person>::iterator it = map1.begin(); it != map1.end(); it++) {
        cout << it->first << "\t" << it->second.name << endl;
    }

    cout<<"开发部人数："<<map1.count("development")<<endl;
    multimap<string, person>::iterator it=map1.find("development");
    int count=0;
    while(it!=map1.end() && count<map1.count("development")){
        cout << it->first << "\t" << it->second.name << endl;
        it++;
        count++;
    }
}

void main2(){
    person p1, p2, p3, p4, p5;
    p1.name = "王1";
    p1.age = 31;
    p2.name = "王2";
    p2.age = 32;
    p3.name = "王3";
    p3.age = 33;
    p4.name = "王4";
    p4.age = 4;
    p5.name = "王5";
    p5.age = 35;
    multimap<string, person> map1;
    map1.insert(make_pair("sale",p1));
    map1.insert(make_pair("sale",p2));
    map1.insert(make_pair("development",p3));
    map1.insert(make_pair("development",p4));
    map1.insert(make_pair("Financial",p5));
    for (multimap<string, person>::iterator it = map1.begin(); it != map1.end(); it++) {
        if(it->second.age==32){
            it->second.name="name32";
        }
        cout << it->first << "\t" << it->second.name << endl;

    }  

}
int main(int argc, char const *argv[])
{
    main2();
    return 0;
}