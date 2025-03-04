#include<iostream>
#include<string>

using namespace std;

void clientMode(){
    char input[9];
    scanf("%7s",input);
    bool addParity=0;
    for(int i=0;i<7;i++){
        if(input[i]=='1'){
            addParity=!addParity;
        }
    }
    input[7]=(addParity)?'1':'0';
    input[8]='\0';
    cout<<"Post formatting: "<<input<<endl;
}
void serverMode(){
    char input[9];
    scanf("%8s",input);
    bool evenParity=1;
    for(int i=0;i<8;i++){
        if(input[i]=='1'){
            evenParity=!evenParity;
        }
    }
    if(evenParity){ 
        cout<<"Parity check passed. Data: ";
        input[7]='\0';
        printf("%s\n",input);
    }else{
        cout<<"Parity check failed. Data corrupted"<<endl;
    }
}
int main(){
    int mode;
    cout<<"Choose mode: (1) Client \t(2) Server"<<endl<<"Mode: ";
    cin>>mode;
    cout<<"Enter your data: ";
    switch (mode)
    {
    case 1:
        clientMode();
        break;
    case 2:
        serverMode();
        break;
    default:
        cerr<<"Invalid option entered"<<endl;
        break;
    }
}