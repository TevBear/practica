#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <iomanip>
#include "tev.h"

using namespace std;

int main()
{
    int menusize=13;
char m[menusize],v,fname[20];
for(int i=0;i<menusize;i++) m[i]=' ';
m[0]='<';
    int i=0, n=0;
    while(true){
    i=0;
    swap(m[n],m[0]);
    //How to use
    cout<<"Use ^ Tab/ Space v to move";
    getch();
    system("cls");
    //Meniu
    while(true){
    while(true){
    system("cls");
    cout<<"MAIN MENU"<<endl<<endl;

 /* */   cout<<"Import data "<<m[0]<<endl;               //B
 /* */   cout<<"Add data "<<m[1]<<endl;
 /* */   cout<<"Insert data "<<m[2]<<endl;
 /* */   cout<<"Delete data "<<m[3]<<endl<<endl;
 /* */   cout<<"Cut data "<<m[4]<<endl;                  //C
 /* */   cout<<"Update data "<<m[5]<<endl;
 /* */   cout<<"Sort data "<<m[6]<<endl;                 //D
 /* */   cout<<"Get max "<<m[7]<<endl;                   //E
 /* */   cout<<"Get average "<<m[8]<<endl;
 /* */   cout<<"Afiseaza date "<<m[9]<<endl<<endl;
 /* */   cout<<"Export data "<<m[10]<<endl<<endl;        //F
 /* */   cout<<"Cosmetic "<<m[11]<<endl;
 /* */   cout<<"Exit "<<m[menusize-1]<<endl;
    v=getch(); //key input
    //Bloc de miscare prin meniu bazat pe schimbarea caracterelor dintr-un sir
    if(v==32){
        if(i==menusize-1){ swap(m[menusize-1],m[0]); i=0;}
        else{ swap(m[i],m[i+1]);i++;}
    }
    else if(v==9){
        if(i==0){ swap(m[menusize-1],m[0]); i=menusize-1;}
        else{ swap(m[i],m[i-1]);i--;}
    }
    else {n=i; break;}
    }
    //
    system("cls");
    switch(n){
case 0:{
    cout<<"| Import data |\n(filename.extension)\n";
    cin>>fname;
    ImportData(fname);
break;
}
case 1:{
    AddData();
    ExportData(fname);
break;
}
case 2:{
    InsertData();
    ExportData(fname);
break;
}
case 3:{
    DeleteP();
    ExportData(fname);
break;
}
case 4:{
    cutdata();
    ExportData(fname);
break;
}
case 5:{
    cout<<"| Update data |\n(Service id)\n";
    UpdateService();
    ExportData(fname);
break;
}
case 6:{
    sortdata();
    ExportData(fname);
break;
}
case 7:{
    FindMaxService();
getch();
break;
}
case 8:{
    getmed();
break;
}
case 9:{
    ShowData();
break;
}
case 10:{
    cout<<"| Export data |\n(filename.extension)\n";
    cin>>fname;
    ExportData(fname);
break;
}
case 11:{
color();
break;
}
case 12:{
delete[] t;
return 1;
}
default: {cout<<"erroare :(";delete[] t; return 3;}
    }

    //getch();
    system("cls");
    }
    return 0;
}
}
