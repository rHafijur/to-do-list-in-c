/*Author: Hafijur Rahman Bokhtier
Title: To-Do List*/
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<windows.h>
#include "custom.h"
#include "tasks.h"
#include"pattern.h"

int main(){
    system("COLOR 37");
    logo();
    int i=1;
    int uid=logged_in(0);
    char ask;
    while(i){
        if(i!=1){
            printf("press SPACE to continue or any key to Exit:");
            ask=getch();
            if(ask=='\x20'){
                system("cls");
                check(uid);
            }else{
                logo();
                exit(0);
            }

        }else{
            system("cls");
            check(uid);
        }
        i++;
    }
}

