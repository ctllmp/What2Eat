/*This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA*/

#include <stdio.h>

void menu(int ii, int jj){
    printf("You are the %d. person. Please type the %d. number of the item you want\n"
" 1-Kebab\n 2-Burger\n 3-Pasta\n 4-Lahmacun\n 5-Salad\n",ii,jj);
}

void shortMenu(int sumOchoices[]){
    if(sumOchoices[0]>0){
        printf("1-Kebab\n");
    }
    if(sumOchoices[1]>0){
        printf("2-Burger\n");
    }
    if(sumOchoices[2]>0){
        printf("3-Pasta\n");
    }
    if(sumOchoices[3]>0){
        printf("4-Lahmacun\n");
    }
    if(sumOchoices[4]>0){
        printf("5-Salad\n");
    }

}



int main(){
    int numOchoices=5;
    int numOpeople=0;
    int isValid;


    printf("Please type the number of people:\n");
    scanf("%d" , &numOpeople);
    while(numOpeople==0){
    printf("Number of people cannot be 0 please type again:\n");
    scanf("%d" , &numOpeople);
    }
    int threshold=numOpeople*2;
    int choiceList[numOpeople][numOchoices];
    int sumOchoices[numOchoices];

    for (int ii=0; ii<numOpeople; ii++){
        for(int jj=0; jj<numOchoices; jj++){
            menu(ii+1,jj+1);
            scanf("%d", &choiceList[ii][jj]);
            isValid= choiceList[ii][jj];
            while(isValid<=0 || isValid>5){
               printf("Please select a valid number: ");
               scanf("%d", &choiceList[ii][jj]);
               isValid= choiceList[ii][jj];
            }
        }
     }

    for(int k=0; k<numOchoices; k++){
        sumOchoices[k]=0;
    }

    for(int ii=0; ii<numOpeople; ii++){
        for(int jj=0; jj<numOchoices; jj++){

            sumOchoices[ choiceList[ii][jj]-1]+=(5-jj);
        }
    }
    int arraySize=numOchoices;
    numOchoices=0;

    for(int kk=0; kk<arraySize; kk++){
        if(sumOchoices[kk]<=threshold){
            sumOchoices[kk]=0;
        }else{
            numOchoices+=1;
        }
    }

     if(numOchoices==0){
        printf("You are eating at home/dorm today!");
        return 0;
    }

    for (int ii=0; ii<numOpeople; ii++){
        for(int jj=0; jj<numOchoices; jj++){
            printf("You are the %d. person. Please type the %d. number of the item you want\n",ii+1,jj+1);
            shortMenu(sumOchoices);
            scanf("%d", &choiceList[ii][jj]);
            isValid= choiceList[ii][jj];
            while(isValid<=0 || isValid>arraySize){
               printf("Please select a valid number: ");
               scanf("%d", &choiceList[ii][jj]);
               isValid= choiceList[ii][jj];
            }
        }
     }
    for(int k=0; k<arraySize; k++){
        sumOchoices[k]=0;
    }

    for(int ii=0; ii<numOpeople; ii++){
        for(int jj=0; jj<numOchoices; jj++){

            sumOchoices[ choiceList[ii][jj]-1]+=(5-jj);
        }
    }

    int max=0;
    int index=-1;

    for(int k=0; k<arraySize; k++){
        if(sumOchoices[k]>max){
            max=sumOchoices[k];
            index=k;
        }
    }

    printf("You are eating ");
    if(index==0){
        printf("Kebab today!");
    }else if(index==1){
        printf("Burger today!");
    }else if(index==2){
        printf("Pasta today!");
    }else if(index==3){
        printf("Lahmacun today!");
    }else if(index==4){
        printf("Salad today!");
    }else{
        printf("nothing today!");
    }


    return 0;
}


