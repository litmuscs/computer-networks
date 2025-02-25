#include<iostream>
#include<string>
#define COMMON_FILE_NAME commonChannel
#define TERMINATE_CHARACTER '#'
#define ESCAPE_CHARACTER '$'

using namespace std;
int main(){
    string input;
    string output="#";
    cout<<"Enter your input: ";
    getline(cin,input);
    for(char c:input){
        if(c==TERMINATE_CHARACTER){
            output+="$#";
        }else if(c==ESCAPE_CHARACTER){
            output+="$$";
        }else{
            output+=c;
        }
    }
    output+="#";
    cout<<"Formatted string: "<<output<<endl;
    return 0;
}