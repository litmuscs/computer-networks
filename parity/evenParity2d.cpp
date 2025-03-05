#include<iostream>

using namespace std;


void printBuffer(char c,int n){
    for(int i=0;i<n;i++){
        cout<<c;
    }
    cout<<endl;
}
void printFormatted(string data){
    int rows=data.length()/8;
    for(int i=0;i<rows;i++){
        if(i==rows-1)
            printBuffer('-',65);
        for(int j=0;j<7;j++){
            char c=data[(8*i)+j];
            printf("%c\t",c);
        }
        printf("|\t%c\n",data[(8*i)+7]);
    }
}
string generateBlockParity(string input){
    string output="";
    int rows=input.length()/7;
    bool* columnParity=(bool*)calloc(8,sizeof(bool));   
    for(int i=0;i<rows;i++){
        bool isEvenParity=true;
        for(int j=0;j<7;j++){
            char c=input[(7*i)+j];
            if(c=='1'){
                isEvenParity=!isEvenParity;
                columnParity[j]=!columnParity[j];
            }
            output+=c;
        }
        output+=(isEvenParity)?'0':'1';
        if(!isEvenParity){
            columnParity[7]=!columnParity[7];  
        }
    }
    for(int i=0;i<8;i++){
        output+=(columnParity[i])?'1':'0';
    }
    cout<<"Parity: "<<output<<endl;
    return output;
}
int main(){
    cout<<"Enter your binary data in multiples of 7: ";
string input;
    cin>>input;
    if((input.length()%7)!=0){
        cerr<<"Wrong data length entered. Expected multiple of 7, got "<<input.length()<<endl;
        exit(-1);
    }
    string parityBlock=generateBlockParity(input);
    printFormatted(parityBlock);
}
