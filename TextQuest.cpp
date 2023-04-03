#include <iostream>
#include <string>
#include <fstream>
#include "Utility.h"

bool isitchislo(char lol){
    if ((lol=='0')||(lol=='1')||(lol=='2')||(lol=='3')||(lol=='4')||(lol=='5')||(lol=='6')||(lol=='7')||(lol=='8')||(lol=='9'))return true;
    else return false;
}

void quest()
{
    int n = 0, inp = 0, i = 0, j;
    int a[2]={0,0};
    string chisla[10];
    bool game=true;
    ifstream f1;
    string stroka[256];
    string choice;
    f1.open("quest.txt");


    while(!f1.eof()){
        getline(f1,stroka[i]);
        i++;
    }

    while(game){
        i = 0;
        while(i < stroka[n].length()){
            if ((!isitchislo(stroka[n][i])) && (stroka[n][i]!=' ')){a[0]=i; i=stroka[n].length();}
            i++;
        }
        i=i-2;
        while(i>0){
            if ((!isitchislo(stroka[n][i]))&&(stroka[n][i]!=' '))
            { a[1]=i+1; i=-1;};
            i--;
        }
        choice = stroka[n].substr(a[1]+1,stroka[n].length()-a[1]);
        j=0; i=0;
        for(j=0;j<10;j++){chisla[j]="0";}
        j=0; i=0;
        if (a[1]>(stroka[n].length()-2))for(j=0;j<10;j++){chisla[j]="999999999";}
        else{
            j=0; i=0;
            while((i<choice.length())&&(j<10))
            {
                if (choice[i]==' '){chisla[j]=choice.substr(0,i);j++;
                    choice = choice.substr(i+1, choice.length()-1-i );i=0;
                }
                else{i++;}
            }}
        cout<<stroka[n].substr(a[0],a[1]-a[0])<<endl;
        cin>>inp;
        if (inp>10)inp=10;
        n = stoi(chisla[inp-1]);
        if (n==999999999)game=false;
    }
}
