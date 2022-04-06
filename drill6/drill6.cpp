#include "std_lib_facilities.h"
template< typename T> struct S{
    private:
    T val;
    public:
    S():val(T()){}; //Egy üres konstruktor 
    S(T d):val(d){};
    
    
    T& get();
const T& get() const;
void set(const T& d); //átállít/set-eli az adott elemet
T& operator=(const T&);    

};
template<typename T>T& S<T>::get(){
    return val;
}
template<typename T>void S<T>::set(const T& d){
    val=d;
}
template<typename T> T& S<T>::operator=(const T& d){
    val = d;
    return val;
}
template<typename T> const T& S<T>::get()const
{
    return val;
}
template<class T> ostream& operator<<(ostream& os, const vector<T>& d){
    os << "{ ";
    for(int i = 0; i<d.size();++i){
        os << d[i];
        if(i<d.size()-1){
            os << ',';
        }
        os << ' ';
    }
    os << "}";
    return os;
}

template<typename T> void read_value(T& v){
    cin >> v;
}
template<typename T> istream& operator >> (istream& is,S<T>& tt)
{
    T v;
    cin >> v;
    if(!is){
        return is;
    }
    tt=v;
    return is;

}

template<class T> istream& operator>> (istream& is, vector<T>& d){
        char n1;
        char n2;
        T temp;
        vector<T> v_temp;
        is>>n1;
        if(!is){
            return is;
        }
        if(n1!='{'){
            is.clear();
            error("{ expected.");
            return is;
        }

    while(cin>>temp>>n2 && n2==','){
        v_temp.push_back(temp);
    }
    if(n2!='}'){
        is.clear();
        error("} excpected.");
        return is;
    }
    v_temp.push_back(temp);
    d=v_temp;
};


int main(){
    
S<int> tint(2);
S<double> tdouble(2.5);
S<char> tchar('!');
S<string> tstring("teszt");
S<vector<int>> tvector({2,3,4,5,8,7});

cout << tchar.get()<< endl;
cout << tint.get()<< endl;
cout << tdouble.get()<< endl;
cout << tstring.get()<< endl;
cout << tvector.get()<< endl;

//in2
cout << "Set data:"<<endl;
tint.set(15);
tchar.set('%');
tstring.set("settelve");
tvector.set({5,35,2,1});
tdouble.set(88.32);

cout << tchar.get()<< endl;
cout << tint.get()<< endl;
cout << tdouble.get()<< endl;
cout << tstring.get()<< endl;
cout << tvector.get()<< endl;

//in3
cout << "mar nem a settes"<<endl;
tint=17;
tchar='@';
tdouble=92.4;
tstring="Eznemsettesváltoztatás";
tvector={7,77,777,888};

cout << tchar.get()<< endl;
cout << tint.get()<< endl;
cout << tdouble.get()<< endl;
cout << tstring.get()<< endl;
cout << tvector.get()<< endl;


cout << "tint: ";
read_value(tint);
cout << "tchar: ";
read_value(tchar);
cout << "tdouble: ";
read_value(tdouble);
cout << "tstring: ";
read_value(tstring);
cout << "tvector: ";
read_value(tvector);

cout << tchar.get()<< endl;
cout << tint.get()<< endl;
cout << tdouble.get()<< endl;
cout << tstring.get()<< endl;
cout << tvector.get()<< endl;

}