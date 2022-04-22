#include "std_lib_facilities.h"


int main(){
    vector<double> vd;
    ifstream file("datas2.txt");
    double adat;
    while (file>>adat){
        vd.push_back(adat);
    }

    vector<int> vi;
    for(int i=0;i<vd.size();i++){
        vi.push_back(vd[i]);
    }

    for(int i=0;i<vd.size();i++){
        cout << vd[i] << " : " << vi[i]<<endl;
    }

    double sumvd=0;
    int sumvi=0;
    for(int i=0;i<vd.size();i++){
        sumvd+=vd[i];
        
    }
    for(int i=0;i<vi.size();i++){
        sumvi+=vi[i];
    }
    cout << "------------------------------------"<< endl;
    cout << sumvd<< endl;
    cout << sumvi<< endl;
    cout << sumvd-sumvi<< endl;

    reverse(vd.begin(),vd.end());
    cout << "------------------------------------"<< endl;
    for(int i=0;i<vd.size();i++){
        cout << vd[i] << " : " << vi[i]<<endl;
    }

    double atlag=sumvd/vd.size();
    cout << " Átlaga: " << atlag << endl;


    vector<double> vd2;
    for(int i=0;i<vd.size();i++){
        if(vd[i]<atlag){
            vd2.push_back(vd[i]);
        }
    }

    sort(vd2.begin(),vd2.end());
    cout << "------------------------------------"<< endl;
    for(int i=0;i<vd2.size();i++){
        cout<< vd2[i]<<endl;
    }


    return 0;
}