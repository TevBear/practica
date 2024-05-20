#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <iomanip>
#include "tev.h"

using namespace std;

int main()
{
    int menusize=15;
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
 /*?*/   cout<<"Add data "<<m[1]<<endl;
 /*?*/   cout<<"Insert data "<<m[2]<<endl;
 /*?*/   cout<<"Delete data "<<m[3]<<endl<<endl;
    cout<<"Cut data "<<m[4]<<endl;                  //C
 /*?*/   cout<<"Update data "<<m[5]<<endl;
    cout<<"Prelucrare date "<<m[6]<<endl<<endl;
    cout<<"Sort data "<<m[7]<<endl;                 //D
    cout<<"Sort specific data "<<m[8]<<endl<<endl;
 /* */   cout<<"Get max "<<m[9]<<endl;                   //E
    cout<<"Get average "<<m[10]<<endl;
 /*?*/   cout<<"Afiseaza date "<<m[11]<<endl<<endl;
 /* */   cout<<"Export data "<<m[12]<<endl<<endl;        //F

 /* */   cout<<"Cosmetic "<<m[13]<<endl;
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
break;
}
case 2:{
    InsertData();
break;
}
case 3:{
    cout<<"| Delete data |\n(Service id)\n";
    DeleteP();

break;
}
case 4:{
break;
}
case 5:{
    cout<<"| Update data |\n(Service id)\n";
    UpdateService();
break;
}
case 6:{
break;
}
case 7:{
break;
}
case 8:{
break;
}
case 9:{
    while(true){
    char m7[4]={'<',' ',' '};
    cout<<"| Find MAX |\n";
    char v7; int i7=0,n7=0;
        while(true){
            system("cls");
            cout<<"Time "<<m7[0]<<endl;
            cout<<"Price "<<m7[1]<<endl;
            cout<<"Exit "<<m7[2]<<endl;
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
        if(n7==2) break;
    FindMaxService(n7);
getch();
    }
break;
}
case 10:{
break;
}
case 11:{
    ShowData();
break;
}
case 12:{
    cout<<"| Export data |\n(filename.extension)\n";
    cin>>fname;
    ExportData(fname);
break;
}
case 13:{
color();
break;
}
case 14:{
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
/*
Sa se elaboreze in limbaj de nivel inalt un program care va gestiona o companie ce se
ocupa cu instalarea retelelor electrice si de ventilare, meniuri şi subprograme. Sa se
realizeze la solicitarea utilizatorului urmatoarele prescriptii:
A. Proiectarea descendenta a algoritmului:
 Schema-bloc generala a algoritmului.
 Interfata aplicatiei
 Fisierele de intrare asociate problemei de
rezolvat. B. Modificarea structurii unui fisier
 Subprogram pentru adaugarea unei linii noi intr-un fisier.
 Subprograme pentruinserarea unei linii noi intr-un fisier.
 Subprograme pentru excluderea liniilor din
fisier. C. Prelucrari relative sirurilor de caractere
 Subprogram pentru decuparea unui subsir dintr-un sir de caractere.
 Subprograme pentru actualizarea liniilor din fisier.
 Subprograme pentru prelucrarea datelor din fisiere conform
cerintelor specificate.
D. Sortari ale elementelor structurilor unidimensionale.

 Subprograme pentru sortarea datelor
specificate. E. Prelucrari statistice ale datelor de
intrare.
 Subprogram pentru determinarea valorilor extremale dintr-o multime.
 Subprogram pentru determinarea valorii medii ai unei multimi.
 Subprogram pentru afisarea continutului unui fisier
textual. F. Extrageri de informatii
 Subprogram pentru crearea fisierelor de
iesire. G. Aplicarea programarii modulare.
 Modulul (unitatea de program) ce include toate subprogramele
realizate. H. Testarea si depanarea aplicatiei in intregime.
 Produsul program finisat.
*/
