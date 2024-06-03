#include <fstream>
#include <iomanip>
#include <cstring>
#include <string>
#ifndef TEV_H_INCLUDED
#define TEV_H_INCLUDED

using namespace std;

struct product{
char name[30];
double price, airflow, power;
int time;
string vtype;
}*t;
int pn;

//importare
void ImportData(char filename[]){
ifstream file;
file.open(filename);
file>>pn;
t=new product[pn];

for(int i=0;i<pn;i++){
    file>>t[i].name>>t[i].price>>t[i].time>>t[i].airflow>>t[i].power;
    getline(file,t[i].vtype);
    if(t[i].vtype[0]==' ') t[i].vtype.erase(0, 1);
}
file.close();
}
//add data
void AddData() {
    product* newT = new product[pn + 1];

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

    cout<<"Enter airflow: ";
    cin>>newT[pn].airflow;

    cout<<"Enter power: ";
    cin>>newT[pn].power;

    cout<<"Enter vtype: ";
    cin.ignore();
    getline(cin,newT[pn].vtype);

    pn++;
    delete[] t;
    t=newT;
}
//insert data
void InsertData(){
    //
    while(true){
    cout<<"| Insert data |\n";
    int id,v,i2=0;
    int menusize=pn+1;
    char m[menusize];
    for(int i=1;i<menusize;i++) m[i]=' ';
    m[0]='<';
    system("cls");
    while(true){
            system("cls");
    cout<<setw(20)<<"Name"<<setw(15)<<"Price"<<setw(10)<<"Time"<<setw(10)<<"Airflow"<<setw(10)<<"power"<<setw(20)<<"Vtype"<<endl;
    for(int i=0;i<102;i++)cout<<'_';

    cout<<endl;
    for(int i=0;i<pn;i++){
        cout<<setw(20)<<t[i].name<<setw(15)<<t[i].price<<setw(10)<<t[i].time<<setw(10)<<t[i].airflow<<setw(10)<<t[i].power<<setw(20)<<t[i].vtype<<setw(2)<<m[i]<<endl;
    }
    cout<<"Exit"<<m[menusize-1];
    v=getch();

    if(v==32){
        if(i2==menusize-1){ swap(m[menusize-1],m[0]); i2=0;}
        else{ swap(m[i2],m[i2+1]);i2++;}
    }
    else if(v==9){
        if(i2==0){ swap(m[menusize-1],m[0]); i2=menusize-1;}
        else{ swap(m[i2],m[i2-1]);i2--;}
    }
    else {id=i2; break;}

    }
    if (id>=pn) {
        break;
    }
    //

    system("cls");
    product* newT = new product[pn+1];
    for (int i=0;i<id;i++){
        newT[i]=t[i];
    }
    cout<<"Enter name: ";
    cin>>newT[id].name;

    cout<<"Enter price: ";
    cin>>newT[id].price;

    cout<<"Enter time: ";
    cin>>newT[id].time;

    cout<<"Enter airflow: ";
    cin>>newT[id].airflow;

    cout<<"Enter power: ";
    cin>>newT[id].power;

    cout<<"Enter vtype: ";
    cin.ignore();
    getline(cin, newT[id].vtype);

    for (int i=id; i<pn;i++){
        newT[i+1]=t[i];
    }
    pn++;
    delete[] t;
    t=newT;
}}


//delete data
void DeleteP(){

    while(true){
    int id,v,i2=0;
    int menusize=pn+1;
    char m[menusize];
    for(int i=1;i<menusize;i++) m[i]=' ';
    m[0]='<';
    system("cls");
    while(true){
            system("cls");
    cout<<setw(20)<<"Name"<<setw(15)<<"Price"<<setw(10)<<"Time"<<setw(10)<<"Airflow"<<setw(10)<<"power"<<setw(20)<<"Vtype"<<endl;
    for(int i=0;i<102;i++)cout<<'_';

    cout<<endl;
    for(int i=0;i<pn;i++){
        cout<<setw(20)<<t[i].name<<setw(15)<<t[i].price<<setw(10)<<t[i].time<<setw(10)<<t[i].airflow<<setw(10)<<t[i].power<<setw(20)<<t[i].vtype<<setw(2)<<m[i]<<endl;
    }
    cout<<"Exit"<<m[menusize-1];
    v=getch();

    if(v==32){
        if(i2==menusize-1){ swap(m[menusize-1],m[0]); i2=0;}
        else{ swap(m[i2],m[i2+1]);i2++;}
    }
    else if(v==9){
        if(i2==0){ swap(m[menusize-1],m[0]); i2=menusize-1;}
        else{ swap(m[i2],m[i2-1]);i2--;}
    }
    else {id=i2; break;}

    }
    if (id>=pn) {
        break;
    }

    for (int i=id;i<pn-1;i++){
        t[i]=t[i+1];
    }
    pn--;
    product* newT = new product[pn];

    for (int i=0;i<pn;i++){
        newT[i]=t[i];
    }

    delete[] t;
    t = newT;
    }
}
//max
product FindMaxService(){
    if (pn==0){
        cout<<"No product available."<<endl;
        return {};
    }
    while(true){
    char m7[5];
    for(int i=0;i<5;i++) m7[i]=' ';
    m7[0]='<';
    cout<<"| Find MAX |\n";
    char v7; int i7=0,n7=0;
        while(true){
            system("cls");
            cout<<"Time "<<m7[0]<<endl;
            cout<<"Price "<<m7[1]<<endl;
            cout<<"Airflow "<<m7[2]<<endl;
            cout<<"Power "<<m7[3]<<endl;
            cout<<"Exit "<<m7[4]<<endl;
            v7=getch();
            if(v7==32){
                if(i7==4){ swap(m7[4],m7[0]); i7=0;}
                else{ swap(m7[i7],m7[i7+1]); i7++;}
            }
            else if(v7==9){
                if(i7==0){ swap(m7[4],m7[0]); i7=4;}
                else{ swap(m7[i7],m7[i7-1]); i7--;}
            }
            else {n7=i7; break;}
        }
        if(n7==4) break;
    product maxService = t[0];

         switch(n7){
            case 1:{
                for (int i=1;i<pn;i++)
            if (t[i].price>maxService.price){
                maxService=t[i];
            }
                break;}
            case 0:{
                for (int i=1;i<pn;i++)
            if (t[i].time>maxService.time){
                maxService=t[i];
            }
                break;}
            case 2:{
                for (int i=1;i<pn;i++){
                if (t[i].airflow>maxService.airflow){
                maxService=t[i];
            }}
                break;}            case 3:{
                for (int i=1;i<pn;i++)
                if (t[i].power>maxService.power){
                maxService=t[i];
            }
                break;}

    }

    cout<<setw(20)<<"Name"<<setw(15)<<"Price"<<setw(5)<<setw(10)<<"Time"<<setw(10)<<"Airflow"<<setw(10)<<"power"<<setw(20)<<"Vtype"<<endl;
    for(int i=0;i<102;i++)cout<<'_';
    cout<<endl;
        cout<<setw(20)<<maxService.name<<setw(15)<<maxService.price<<setw(10)<<maxService.time<<setw(10)<<maxService.airflow<<setw(10)<<maxService.power<<setw(20)<<maxService.vtype<<endl;
getch();
}}
void UpdateService(){
        //
    while(true){

    int id,v,i2=0;
    int menusize=pn+1;
    char m[menusize];
    for(int i=1;i<menusize;i++) m[i]=' ';
    m[0]='<';
    system("cls");
    while(true){
            system("cls");
    cout<<setw(20)<<"Name"<<setw(15)<<"Price"<<setw(10)<<"Time"<<setw(10)<<"Airflow"<<setw(10)<<"power"<<setw(20)<<"Vtype"<<endl;
    for(int i=0;i<102;i++)cout<<'_';

    cout<<endl;
    for(int i=0;i<pn;i++){
        cout<<setw(20)<<t[i].name<<setw(15)<<t[i].price<<setw(10)<<t[i].time<<setw(10)<<t[i].airflow<<setw(10)<<t[i].power<<setw(20)<<t[i].vtype<<setw(2)<<m[i]<<endl;
    }
    cout<<"Exit"<<m[menusize-1];
    v=getch();

    if(v==32){
        if(i2==menusize-1){ swap(m[menusize-1],m[0]); i2=0;}
        else{ swap(m[i2],m[i2+1]);i2++;}
    }
    else if(v==9){
        if(i2==0){ swap(m[menusize-1],m[0]); i2=menusize-1;}
        else{ swap(m[i2],m[i2-1]);i2--;}
    }
    else {id=i2; break;}

    }
    if (id>=pn) {
        break;
    }
    //

    while(true){
    char m7[7];
    for(int i=0;i<7;i++) m7[i]=' ';
    m7[0]='<';

    char v7; int i7=0,n7=0;
        while(true){
            system("cls");
            cout<<t[id].name<<' '<<m7[0]<<endl;
            cout<<t[id].price<<' '<<m7[1]<<endl;
            cout<<t[id].time<<' '<<m7[2]<<endl;
            cout<<t[id].airflow<<' '<<m7[3]<<endl;
            cout<<t[id].power<<' '<<m7[4]<<endl;
            cout<<t[id].vtype<<' '<<m7[5]<<endl;
            cout<<"Exit "<<m7[6]<<endl<<endl;
            v7=getch();
            if(v7==32){
                if(i7==6){ swap(m7[6],m7[0]); i7=0;}
                else{ swap(m7[i7],m7[i7+1]); i7++;}
            }
            else if(v7==9){
                if(i7==0){ swap(m7[6],m7[0]); i7=6;}
                else{ swap(m7[i7],m7[i7-1]); i7--;}
            }
            else {n7=i7; break;}
        }
        if(n7==6)break;
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
    case 3:
        cin>>t[id].airflow;
        break;
    case 4:
        cin>>t[id].power;
        break;
    case 5:
        cin.ignore();
        getline(cin,t[id].vtype);
        break;
    }
    continue;

}}}


//afisarea datelor
void ShowData(){
    system("cls");
    cout<<setw(20)<<"Name"<<setw(15)<<"Price"<<setw(10)<<"Time"<<setw(10)<<"Airflow"<<setw(10)<<"power"<<setw(20)<<"Vtype"<<endl;
    for(int i=0;i<102;i++)cout<<'_';
    cout<<endl;
    for(int i=0;i<pn;i++){
        cout<<setw(20)<<t[i].name<<setw(15)<<t[i].price<<setw(10)<<t[i].time<<setw(10)<<t[i].airflow<<setw(10)<<t[i].power<<setw(20)<<t[i].vtype<<endl;
    }
    getch();
}

//exportare date in fisier
void ExportData(const char* filename) {
    ofstream file;
    file.open(filename);
    file<<pn<<endl;
    for (int i=0;i<pn;i++) {
        file<<t[i].name<<' '<<t[i].price<<' '<<t[i].time<<' '<<t[i].airflow<<' '<<t[i].power<<' '<<t[i].vtype<<endl;
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

void sortdata(){

while(true){
    char m7[5];
    for(int i=0;i<5;i++) m7[i]=' ';
    m7[0]='<';
    cout<<"| Sort Data |\n";
    char v7; int i7=0,n7=0;
        while(true){
            system("cls");
            cout<<"Time "<<m7[0]<<endl;
            cout<<"Price "<<m7[1]<<endl;
            cout<<"Airflow "<<m7[2]<<endl;
            cout<<"Power "<<m7[3]<<endl;
            cout<<"Exit "<<m7[4]<<endl;
            v7=getch();
            if(v7==32){
                if(i7==4){ swap(m7[4],m7[0]); i7=0;}
                else{ swap(m7[i7],m7[i7+1]); i7++;}
            }
            else if(v7==9){
                if(i7==0){ swap(m7[4],m7[0]); i7=4;}
                else{ swap(m7[i7],m7[i7-1]); i7--;}
            }
            else {n7=i7; break;}
        }
        if(n7==4) break;
        switch(n7){
    case 0:
        for(int i=0;i<pn-1;i++)
        for(int j=0;j<pn-i-1;j++)
        if(t[j].time<t[j+1].time)
            swap(t[j].time,t[j+1].time);
        break;
    case 1:
        for(int i=0;i<pn-1;i++)
        for(int j=0;j<pn-i-1;j++)
        if(t[j].price<t[j+1].price)
            swap(t[j].price,t[j+1].price);
        break;
    case 2:
        for(int i=0;i<pn-1;i++)
        for(int j=0;j<pn-i-1;j++)
        if(t[j].airflow<t[j+1].airflow)
            swap(t[j].airflow,t[j+1].airflow);
        break;
    case 3:
        for(int i=0;i<pn-1;i++)
        for(int j=0;j<pn-i-1;j++)
        if(t[j].power<t[j+1].power)
            swap(t[j].power,t[j+1].power);
        break;
        }
    cout<<"Sorted"<<endl;
getch();
break;
    }}
void getmed(){
while(true){
    char m7[5]; int med;
    for(int i=0;i<5;i++) m7[i]=' ';
    m7[0]='<';
    cout<<"| Med Data |\n";
    char v7; int i7=0,n7=0;
        while(true){
            system("cls");
            cout<<"Time "<<m7[0]<<endl;
            cout<<"Price "<<m7[1]<<endl;
            cout<<"Airflow "<<m7[2]<<endl;
            cout<<"Power "<<m7[3]<<endl;
            cout<<"Exit "<<m7[4]<<endl;
            v7=getch();
            if(v7==32){
                if(i7==4){ swap(m7[4],m7[0]); i7=0;}
                else{ swap(m7[i7],m7[i7+1]); i7++;}
            }
            else if(v7==9){
                if(i7==0){ swap(m7[4],m7[0]); i7=4;}
                else{ swap(m7[i7],m7[i7-1]); i7--;}
            }
            else {n7=i7; break;}
        }
        if(n7==4) break;
        med=0;
        cout<<"| Med data |"<<endl;
        switch(n7){
    case 0:{
        for(int i=0;i<pn;i++) med+=t[i].time;
        med/=pn;
        break;
        }
    case 1:{
        for(int i=0;i<pn;i++) med+=t[i].price;
        med/=pn;
        break;
        }
    case 2:{
        for(int i=0;i<pn;i++) med+=t[i].airflow;
        med/=pn;
        break;
        }
    case 3:{
        for(int i=0;i<pn;i++) med+=t[i].power;
        med/=pn;
        break;
        }}
    cout<<med;
getch();
}}
void cutdata(){
    while(true){

    int id,v,i2=0;
    int menusize=pn+1;
    char m[menusize];
    for(int i=1;i<menusize;i++) m[i]=' ';
    m[0]='<';
    system("cls");
    while(true){
            system("cls");
    cout<<setw(20)<<"Name"<<setw(15)<<"Price"<<setw(10)<<"Time"<<setw(10)<<"Airflow"<<setw(10)<<"power"<<setw(20)<<"Vtype"<<endl;
    for(int i=0;i<102;i++)cout<<'_';

    cout<<endl;
    for(int i=0;i<pn;i++){
        cout<<setw(20)<<t[i].name<<setw(15)<<t[i].price<<setw(10)<<t[i].time<<setw(10)<<t[i].airflow<<setw(10)<<t[i].power<<setw(20)<<t[i].vtype<<setw(2)<<m[i]<<endl;
    }
    cout<<"Exit"<<m[menusize-1];
    v=getch();

    if(v==32){
        if(i2==menusize-1){ swap(m[menusize-1],m[0]); i2=0;}
        else{ swap(m[i2],m[i2+1]);i2++;}
    }
    else if(v==9){
        if(i2==0){ swap(m[menusize-1],m[0]); i2=menusize-1;}
        else{ swap(m[i2],m[i2-1]);i2--;}
    }
    else {id=i2; break;}
    }
    if(id==menusize-1)break;
    string vd[2]={"aer ","aer de "};
    if(t[id].vtype.compare(0,7,vd[1])==0) t[id].vtype.erase(0, 7);
    else if(t[id].vtype.compare(0,4,vd[0])==0) t[id].vtype.erase(0, 4);

}}
#endif // TEV_H_INCLUDED
