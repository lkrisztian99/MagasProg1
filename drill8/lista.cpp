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


ostream& operator<<(ostream& os,const list<Item>& Mlist){
    for(auto i=Mlist.begin(); i!=Mlist.end(); ++i){
        os << (*i).name << " " << (*i).iid << " " << (*i).value << endl;
    }
    return os;
}
struct myNames{
    bool operator()(const Item& i, const Item& j){
    return i.name<j.name;
    }
};



struct myIds{
    bool operator()(const Item& i, const Item& j){
    return i.iid<j.iid;
    }
};


struct myValues{
    bool operator()(const Item& i, const Item& j){
        return i.value<j.value;
    }
};

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
    list<Item> vi;

    Item item;
    ifstream datas_file("datas.txt");    //file beolvasás
    while(datas_file >> item){
        vi.push_back(item);
    }
       cout << "Name id  value"<< endl;
    for(auto i=vi.begin(); i!= vi.end();i++ ){
        cout << (*i).name << " " <<  (*i).iid << " "<< (*i).value << endl;
    }
    
    
    
   
   cout << " ---------------Sorted By Name--------------- "<< endl;
   cout << "Name id  value"<< endl;

    vi.sort(myNames());

    for(auto i=vi.begin(); i!= vi.end();i++ ){
        cout << (*i).name << " " <<  (*i).iid << " "<< (*i).value << endl;
    }

    cout << " ---------------Sorted By Id--------------- "<< endl;
    cout << "Name id  value"<< endl;

   vi.sort(myIds());

    for(auto i=vi.begin(); i!= vi.end();i++ ){
        cout << (*i).name << " " <<  (*i).iid << " "<< (*i).value << endl;
    }


    cout << " ---------------Sorted By Value--------------- "<< endl;
    cout << "Name id  value"<< endl;

   vi.sort(myValues());

    for(auto i=vi.begin(); i!= vi.end();i++ ){
        cout << (*i).name << " " <<  (*i).iid << " "<< (*i).value << endl;
    }

cout << " ---------------Two Items Inserted--------------- "<< endl;
   cout << "Name id  value"<< endl;
    // Insert (5)
    vi.insert(vi.end(),Item("horse shoe",99,12.34));
    vi.insert(vi.end(),Item("Canon S400",9988,499.95));

    for(auto i=vi.begin(); i!= vi.end();i++ ){
        cout << (*i).name << " " <<  (*i).iid << " "<< (*i).value << endl;
    }
    cout << vi.size();
   cout << " ---------------Two Items Erased--------------- "<< endl;
   cout << "Name id  value"<< endl;
   
    
    list<Item> ::iterator iterated;
   

    iterated=find_if(vi.begin(),vi.end(),nevKeres("Akos"));
    vi.erase(iterated);
    iterated=find_if(vi.begin(),vi.end(),nevKeres("Fu"));
    vi.erase(iterated);
    iterated=find_if(vi.begin(),vi.end(),idKeres(38));
    vi.erase(iterated);
    iterated=find_if(vi.begin(),vi.end(),idKeres(24));
    vi.erase(iterated);

    for(auto i=vi.begin(); i!= vi.end();i++ ){
        cout << (*i).name << " " <<  (*i).iid << " "<< (*i).value << endl;
    }

    return 0;
}