#include <cstring>
#include <iostream>
using namespace std;
int main(){
    string s;
    string t;
    s = "ABBCADEEFAHASGFASFASJJJEF";
    t = "SFASJJ";

    // Naive String matching algorithm.
    for(int i=0; i<s.size(); i++){
        bool found = false;
        if(s[i] == t[0]){
            // First character check passed. Process remaining pattern.
            bool flag = true;
            for(int x=0; x<t.size(); x++){
                if(s[i+x] != t[x]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                found = true;
                cout << "Found the pattern at " << i << endl;
                break;
            }
            else{
                cout << "First char match but error at : " << i << endl;
            }
        }
        if(found) break;
    }
    return 0;
}
