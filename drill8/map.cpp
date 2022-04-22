#include "std_lib_facilities.h"



template<typename T,typename N>
ostream& operator<<(ostream& os,const map<T,N>& Mmap){
    for(const auto& i:Mmap){
        cout << i.first << " " << i.second << endl;
    }
};

void Insert(map<string,int>& Mmap){
    string szoveg;
    int szam;

    cin >> szoveg >> szam;
    Mmap.insert(pair<string,int>(szoveg, szam));
};

/*
void print_map(std::string_view comment, const std::map<std::string, int>& m)
{
    std::cout << comment ;
    for (const auto& [key, value] : m) {
        std::cout << '[' << key << "] = " << value << "; ";
    }
    std::cout << '\n';
}*/

int main(){
    
    map<string,int> msi={
        {"kacsa",10},{"zoli",7},{"napszemcsi",66},{"gumikacsa",24365},{"miez",213},{"heh",33},{"tttttt",199},{"ab",3321},{"wtf",34},{"uze",12112}
    };

    cout << msi;

    map<string,int>::iterator it;
    cout << "------------------"<< endl;

    it=msi.find("zoli");
    msi.erase(it);
    cout << msi;
    cout << "------------------"<< endl;

    for(int i=0;i<10;i++){
        Insert(msi);
    }

    cout << msi;

    int sum=0;
    for(auto i: msi){
        sum+=i.second;
    }
    cout <<"idk összege: "<<  sum<< endl;

    map<int,string> mis;

    for(auto i:msi){
        mis.insert(pair<int,string>(i.second,i.first));
    }

    cout <<" ----- mis ------"<< endl;
    cout << mis;

    return 0;
}