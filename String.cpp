#include<iostream>
#include <string.h>
#include<vector>
using namespace std;

char* StringCat (char * a, char* b){
    char * temp = a;      
    while(*temp!='\0')
    temp++;        
    while (*b!='\0')
    {
        *(temp++) = *(b++);
    }
    *temp ='\0';  
    return a;
}

void FailureFunction(string& want, vector<int>& failure){
    failure.assign(want.size(), -1);
    for(int j = 1; j < want.size(); j++){
        int i = failure[j-1];            
        while( (want[j] != want[i+1]) && (i>=0) ){
            i = failure[i];
        }            
        if(want[j] == want[i+1]){
            failure[j] = i+1;
        }
    } 
}

//KMP
int Substring(string& target,string& want){
    vector<int> failure;
    FailureFunction(want,failure);
    int i = 0, j = 0;
    while( i<target.size() && j<want.size() ){
        if( target[i] == want[j] ){               
            i++; j++;                    
        }
        else{
            if( j == 0 )
                i++;
            else
                j = failure[j-1] + 1;
        }
    }           
        if(j < want.size())
            return -1;
        else
            return i-want.size();
}

int main(){
    char one[10] ="abcde";
    char two[4] ="abc";
    printf("String Concatenation\n");
    printf("%s\n",one);
    printf("%s\n",two);
    printf("%s\n",StringCat(one,two));
    string target ="The is a dog";
    string want ="dog";
    printf("KMP Substring\n");
    cout<<target<<endl<<want<<endl;;
    printf("Position: %d\n",Substring(target,want));
    system("pause");
    return 0;
}