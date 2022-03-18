#include "std_lib_facilities.h"

struct Person
{
    private:
        string First_Name;
        string Second_name;
        int Age;


    public:
        Person(){
            First_Name=" ";
            Second_name=" ";
            Age=0;
        };


        Person (string fN, string sN,int a){
            string Denied=";:\"'[]*&^%$#@!";

            for(int i=0;i<fN.size();i++){

                for(int j=0; j<Denied.size();j++){
                    if(fN[i]==Denied[j]){
                        error("Denied character in the First_Name");
                    }
                }
            }

            for(int i=0;i<sN.size();i++){

                for(int j=0; j<Denied.size();j++){
                    if(sN[i]==Denied[j]){
                        error("Denied character in the Second_Name");
                    }
                }
            }
            if(!(a>0 && a <150)){
                error("Age is not valid.");
            }

            First_Name=fN;
            Second_name=sN;
            Age=a;



        };

        string name()const{
            return First_Name+" "+Second_name;
        }
        int age() const{
            return Age;
        }

};

ostream& operator<<(ostream& out,Person& PersoN){
    out<< PersoN.name()<< " " << PersoN.age() << endl;
    return out; 
}
istream& operator>>(istream& in, Person& PersoN){
    string FirstName;
    string SecondName;
    int Age;
    in >> FirstName >> SecondName >> Age;
    PersoN=Person(FirstName,SecondName,Age); //overwrite datas
    return in;
}



int main(){
    Person person1("Clarke","Griffin",34);
    cout << person1;

    Person person2;
    cout << "Number of People: ";
    int counting =0;
    cin >> counting;
    int counting2=0;
    vector<Person> people;
    while(cin>>person2){
        people.push_back(person2);
        counting2++;
        if(counting2==counting)break;
    }

    cout << endl;
    for(int i=0; i< people.size();i++){
        cout << people[i];
    }

    return 0;
}