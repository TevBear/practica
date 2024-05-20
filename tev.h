#include <fstream>
#include <iomanip>
#include <cstring>
#ifndef TEV_H_INCLUDED
#define TEV_H_INCLUDED

using namespace std;

struct services{
char name[30];
double price;
int time;
}*t;
int pn;

//importare
void ImportData(char filename[]){
ifstream file;
file.open(filename);
file>>pn;
t=new services[pn];

for(int i=0;i<pn;i++){
    file>>t[i].name>>t[i].price>>t[i].time;
}
file.close();
}
//add data
void AddData() {
    services* newT = new services[pn + 1];

    for (int i=0;i<pn;i++) {
        newT[i]=t[i];
    }
    cout<<"| Add data |\n";
    cout<<"Enter name: ";
    cin>>newT[pn].name;

    cout<<"Enter price: ";
    cin>>newT[pn].price;

    cout<<"Enter time: ";
    cin>>newT[pn].time;
    pn++;
    delete[] t;
    t=newT;
}
//insert data
void InsertData(){
    int id;
    cout<<"| Insert data |\n(id:)\n";
    cin>>id;
    if (id<0||id>pn){
        cout << "Invalid id. Data not inserted."<<endl;
        return;
    }
    services* newT = new services[pn+1];
    for (int i=0;i<id;i++){
        newT[i]=t[i];
    }
    cout<<"Enter name: ";
    cin>>newT[id].name;

    cout<<"Enter price: ";
    cin>>newT[id].price;

    cout<<"Enter time: ";
    cin>>newT[id].time;

    for (int i=id; i<pn;i++){
        newT[i+1]=t[i];
    }
    pn++;
    delete[] t;
    t=newT;
}


//delete data
void DeleteP(){
    int id;
    cin>>id;
    if (id<0||id>=pn) {
        cout << "erroare :(";
    }

    for (int i=id;i<pn-1;i++){
        t[i]=t[i+1];
    }
    pn--;
    services* newT = new services[pn];

    for (int i=0;i<pn;i++){
        newT[i]=t[i];
    }

    delete[] t;
    t = newT;
}
//max
services FindMaxService(bool byPrice){
    if (pn==0){
        cout<<"No services available."<<endl;
        return {};
    }

    services maxService = t[0];
    for (int i=1;i<pn;i++){
        if (byPrice){
            if (t[i].price>maxService.price){
                maxService=t[i];
            }
        } else{
            if (t[i].time>maxService.time){
                maxService=t[i];
            }
        }
    }

    cout<<setw(20)<<"Name"<<setw(15)<<"Price"<<setw(5)<<setw(10)<<"Time"<<endl;
    for(int i=0;i<102;i++)cout<<'_';
    cout<<endl;
        cout<<setw(20)<<maxService.name<<setw(15)<<maxService.price<<setw(10)<<maxService.time<<endl;
}

void UpdateService(){
    int id;
    cin>>id;
    if (id<0||id>=pn){
        cout << "Invalid id. Service not updated." << endl;
        return;
    }



/*
    cout << "Enter new name: ";
    cin>>t[id].name;

    cout<<"Enter new price: ";
    cin>>t[id].price;

    cout<<"Enter new time: ";
    cin>>t[id].time;

    cout<<"Service updated" << endl; getch();*/
    while(true){
    char m7[5]={'<',' ',' '};
    cout<<"| Color change |\n";
    char v7; int i7=0,n7=0;
        while(true){
            system("cls");
            cout<<t[id].name<<' '<<m7[0]<<endl;
            cout<<t[id].price<<' '<<m7[1]<<endl;
            cout<<t[id].time<<' '<<m7[2]<<endl;
            cout<<"Exit "<<m7[3]<<endl<<endl;
            v7=getch();
            if(v7==32){
                if(i7==3){ swap(m7[3],m7[0]); i7=0;}
                else{ swap(m7[i7],m7[i7+1]); i7++;}
            }
            else if(v7==9){
                if(i7==0){ swap(m7[3],m7[0]); i7=3;}
                else{ swap(m7[i7],m7[i7-1]); i7--;}
            }
            else {n7=i7; break;}
        }
        if(n7==3)break;
    switch(n7){
    case 0:
        cin>>t[id].name;
        break;
    case 1:
        cin>>t[id].price;
        break;
    case 2:
        cin>>t[id].time;
        break;
    }
    continue;
    v7=getch();
    if(v7==32){
                if(i7==2){ swap(m7[2],m7[0]); i7=0;}
                else{ swap(m7[i7],m7[i7+1]); i7++;}
            }
            else if(v7==9){
                if(i7==0){ swap(m7[2],m7[0]); i7=2;}
                else{ swap(m7[i7],m7[i7-1]); i7--;}
            }
            else break;
    }
}


//afisarea datelor
void ShowData(){
    system("cls");
    cout<<setw(20)<<"Name"<<setw(15)<<"Price"<<setw(10)<<"Time"<<setw(5)<<"Id"<<endl;
    for(int i=0;i<102;i++)cout<<'_';
    cout<<endl;
    for(int i=0;i<pn;i++){
        cout<<setw(20)<<t[i].name<<setw(15)<<t[i].price<<setw(10)<<t[i].time<<setw(5)<<i<<endl;
    }
    getch();
}

//exportare date in fisier
void ExportData(const char* filename) {
    ofstream file;
    file.open(filename);
    file<<pn<<endl;
    for (int i=0;i<pn;i++) {
        file<<t[i].name<<' '<<t[i].price<<' '<<t[i].time<<endl;
    }
    file.close();
}
//Cosmetica 3 culori
void color(){
    while(true){
    char m7[4]={'<',' ',' '};
    cout<<"| Color change |\n";
    char v7; int i7=0,n7=0;
        while(true){
            system("cls");
            cout<<"Blue "<<m7[0]<<endl;
            cout<<"Yellow "<<m7[1]<<endl;
            cout<<"Red "<<m7[2]<<endl;
            v7=getch();
            if(v7==32){
                if(i7==2){ swap(m7[2],m7[0]); i7=0;}
                else{ swap(m7[i7],m7[i7+1]); i7++;}
            }
            else if(v7==9){
                if(i7==0){ swap(m7[2],m7[0]); i7=2;}
                else{ swap(m7[i7],m7[i7-1]); i7--;}
            }
            else {n7=i7; break;}
        }
    switch(n7){
    case 0: system("color 1"); break;
    case 1: system("color 6"); break;
    case 2: system("color 4"); break;
    }
    v7=getch();
    if(v7==32){
                if(i7==2){ swap(m7[2],m7[0]); i7=0;}
                else{ swap(m7[i7],m7[i7+1]); i7++;}
            }
            else if(v7==9){
                if(i7==0){ swap(m7[2],m7[0]); i7=2;}
                else{ swap(m7[i7],m7[i7-1]); i7--;}
            }
            else break;
    }
}
#endif // TEV_H_INCLUDED
