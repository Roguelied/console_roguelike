#include <iostream>
#include <string>
#include <fstream>
#include "Utility.h"
#include "TextQuest.h"

bool isNum(char n){
    if ((n == '0') or (n == '1') or (n == '2') or(n == '3')
    or (n == '4') or (n == '5') or (n == '6') or (n == '7')
    or (n == '8') or (n == '9')){
        return true;
    }
    else{
        return false;
    }
}

void quest()
{
    bool game = true;
    int n = 0, inp = 0, i = 0, j;
    int a[2] = {0,0};
    string num[10], choice, str[256];
    ifstream f1;

    f1.open("quest.txt");
    while(!f1.eof()){
        getline(f1,str[i]);
        i++;
    }

    while(game){
        i = 0;
        while(i < str[n].length()){
            if ((!isNum(str[n][i])) and (str[n][i] != ' ')){
                a[0]=i; i=str[n].length();
            }
            i++;
        }
        i = i - 2;
        while(i > 0){
            if ((!isNum(str[n][i])) and (str[n][i] != ' ')){
                a[1] = i+1;
                i=-1;
            }
            i--;
        }
        choice = str[n].substr(a[1]+1,str[n].length()-a[1]);
        j = 0; i = 0;
        for(j = 0; j < 10; j++){
            num[j]="0";
        }
        j = 0; i = 0;
        if (a[1] > (str[n].length()-2)){
            for(j = 0; j < 10; j++){
                num[j] = "777";
            }
        }
        else{
            j = 0; i = 0;
            while((i < choice.length()) and (j < 10)){
                if (choice[i] == ' '){
                    num[j] = choice.substr(0,i);
                    j++;
                    choice = choice.substr(i+1, choice.length()-1-i );
                    i = 0;
                }
                else{
                    i++;
                }
            }
        }
        cout << str[n].substr(a[0],a[1]-a[0]) << endl;
        cin >> inp;
        if (inp > 10){
            inp = 10;
        }
        n = stoi(num[inp-1]);
        if (n == 777){
            game = false;
        }
    }
    f1.close();
}
