#include <stdio.h>
#include <windows.h> 
int main() {
    int pos=0, i, dn=1;
    while(1){
        for(int i=0; i<pos; i++){
        printf(" ");
        printf("/");
        }
        pos+=dn;
        if(pos==100||pos==0){
        dn = -dn;
        }

        for(int i=pos; i>0; i--){
            printf(" ");
            printf("\\");
            }
    }
}
