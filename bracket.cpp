#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<unistd.h>



struct Stack{
    char caracters[1000];
    int current_size = - 1;

    bool empty(){
        return current_size==-1 ? true :  false;
    
    }

    void push_back(char letter){
        
        if(current_size!=99){
        current_size++;
        caracters[current_size]=letter;
        }
    }

    void pop_back(){
        !empty()? current_size-- : 1;    
    }

    char top_display(){
        return current_size!=-1 ?  caracters[current_size] :  -1;
        
    }
    

};
bool pair(char open , char close){
    if(open=='(' && close==')')     return true;
    else if(open=='[' && close==']') return true;
    else if(open=='{' && close=='}') return true;
    else return false;
}

bool check(std::string str){
    Stack open_praket;
    for(int i =0;i<str.size();i++){
        if(str[i]=='(' || str[i]=='{' ||str[i]=='[') {

            open_praket.push_back(str[i]);
        }
        
        else if(str[i]==')' || str[i]=='}' ||str[i]==']'){

            if(open_praket.empty()) return false;

            else if(pair(open_praket.top_display(), str[i])){

                open_praket.pop_back();   
            }

            else {
                return false;
            }
        }
    
    }
    if(open_praket.empty()) return true ;
    else return false ;
}
//function generate string from determinat characters  and return a string 
std::string str_generate(){
    char elements[]={'{', '[', ']','(', ')','1','2','4','3','5','6','7','0','/','8','*','+','9','-','}'};
    int length = sizeof(elements) / sizeof(elements[0]);
    std::string str;
    for(int i =0; i<length-1 ;i++){
        str+=elements[rand()%(length-1+1)+1];
    }
    str[length-1]='\0';
    return str;
}

//this function  test the Function  check_bracket 
void test(){
   
    for(int i =0 ; i<10;i++){
        std::string result;
        std::string ste= str_generate();
        if(check(ste)){
            result="passing";
        }
        else result= "failed";
        std::cout<<"test["<<i<<"]"<<" string : "<<ste<<" "<<result<<"\n";
    }  
}

    

int main(){
    srand(time(0));
    test();
}