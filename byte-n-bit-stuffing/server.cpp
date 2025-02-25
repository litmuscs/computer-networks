#include<iostream>
#include<string>
using namespace std;
#define TERMINATE_CHARACTER '#'
#define ESCAPE_CHARACTER '$'

int main(){
    string input,output;
    int ignoreBit=0;
    cout<<"Give the formatted string: ";
    getline(cin,input);
    for(char c:input){
        if(ignoreBit){
            output+=c;
            ignoreBit=0;
            continue;
        }
        if(c==ESCAPE_CHARACTER){
            ignoreBit=1;
        }else if(c==TERMINATE_CHARACTER){
            output+='\n';
        }else{
            output+=c;
        }
    }
    cout<<"Original: "<<output<<endl;
}