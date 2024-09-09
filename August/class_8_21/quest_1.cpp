#include <iostream>
#include <string>

using namespace std;
int length_str(char* sentence){

    if (*sentence == '\0'){
        return 0;
    }
    
    else{
        return 1 +length_str(sentence + 1);
    }

}
int main()
{
    char *str = new char[0];
    cout<<"Enter a string"<<"\n";
    cin.getline(str,100);
    
    cout<<length_str(str);
    delete [] str;
}