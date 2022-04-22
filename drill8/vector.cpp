#include "std_lib_facilities.h"

    /*++ vector.cpp -o vector & ./vector */

struct Item {
string name;
int iid;
double value;

Item():name(),iid(),value(){}

    Item(string n,int id,double val){       // értéket adok a változóimnak
        name=n;
        iid=id;
        value=val;
    }
};


istream& operator>>(istream& is,Item& data){
    is>> data.name;
    is>> data.iid;
    is>> data.value;
    return is;
}


ostream& operator<<(ostream& os,const vector<Item>& MVector){
    for(int i=0; i<MVector.size();++i){
        os << MVector[i].name << " " << MVector[i].iid << " " << MVector[i].value << endl;
    }
    return os;
}




bool myNames(const Item& i, const Item& j){
return i.name<j.name;
}

bool myIds(const Item& i, const Item& j){
    return i.iid<j.iid;
}

bool myValues(const Item& i, const Item& j){
    return i.value<j.value;
}



struct nevKeres{
    string name;
    nevKeres(const string& n):name(n){}
    bool operator()(const Item& a){
        return a.name==name;
    }
};
struct idKeres{
    int id;
    idKeres(const int& n):id(n){}
    bool operator()(const Item& a){
        return a.iid==id;
    }
};





int main(){
    vector<Item> vi;

    Item item;
    ifstream datas_file("datas.txt");    //file beolvasás
    while(datas_file >> item){
        vi.push_back(item);
    }
        cout << "Name id  value"<< endl;
    for(int i=0; i<vi.size();i++){
        cout << vi[i].name << " " << vi[i].iid << " " << vi[i].value << endl; 
    }

   cout << " ---------------Sorted By Name--------------- "<< endl;
   cout << "Name id  value"<< endl;

    sort(vi.begin(),vi.end(),myNames);

    for(int i=0; i<vi.size();i++){
        cout << vi[i].name << " " << vi[i].iid << " " << vi[i].value << endl; 
    }

    cout << " ---------------Sorted By Id--------------- "<< endl;
    cout << "Name id  value"<< endl;

   sort(vi.begin(),vi.end(),myIds);

    for(int i=0; i<vi.size();i++){
        cout << vi[i].name << " " << vi[i].iid << " " << vi[i].value << endl; 
    }


    cout << " ---------------Sorted By Value--------------- "<< endl;
    cout << "Name id  value"<< endl;

   sort(vi.begin(),vi.end(),myValues);

    for(int i=0; i<vi.size();i++){
        cout << vi[i].name << " " << vi[i].iid << " " << vi[i].value << endl; 
    }

cout << " ---------------Two Items Inserted--------------- "<< endl;
   cout << "Name id  value"<< endl;
    // Insert (5)
    vi.insert(vi.end(),Item("horse shoe",99,12.34));
    vi.insert(vi.end(),Item("Canon S400",9988,499.95));

    for(int i=0; i<vi.size();i++){
        cout << vi[i].name << " " << vi[i].iid << " " << vi[i].value << endl; 
    }
    cout << vi.size();
   cout << " ---------------Two Items Erased--------------- "<< endl;
   cout << "Name id  value"<< endl;
    string nameerase="Akos";
    string nameerase2="Fu";
    int id1=38; //kutya
    int id2=24; //Bela
    int torolve=0;
    vector<Item> ::iterator iterated;
   /*   for(int i=0; i<vi.size();i++){
        if(vi[i].name==nameerase || vi[i].name==nameerase2){
            cout << vi[i].name << " Törölve"<< endl;
            vi.erase(vi.begin()+i);
            torolve++;
            }       
    }


    for(int i=0; i<vi.size();i++){
        if(vi[i].iid==id1 || vi[i].iid==id2){
            cout << vi[i].iid << " Törölve"<< endl;
           torolve++;
            vi.erase(vi.begin()+i); // itt még nem jó a törlés!!!
        }
    }
    cout << "Törölve: "<< torolve  <<endl;
for(int i=0; i<vi.size();i++){
        cout << vi[i].name << " " << vi[i].iid << " " << vi[i].value << endl; 
    }
    cout << vi.size(); */

    iterated=find_if(vi.begin(),vi.end(),nevKeres("Akos"));
    vi.erase(iterated);
    iterated=find_if(vi.begin(),vi.end(),nevKeres("Fu"));
    vi.erase(iterated);
    iterated=find_if(vi.begin(),vi.end(),idKeres(38));
    vi.erase(iterated);
    iterated=find_if(vi.begin(),vi.end(),idKeres(24));
    vi.erase(iterated);

    for(int i=0; i<vi.size();i++){
        cout << vi[i].name << " " << vi[i].iid << " " << vi[i].value << endl; 
    }



    cout << "-------------------------"<< endl;

    cout << vi;

    return 0;
}