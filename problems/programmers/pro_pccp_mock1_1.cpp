/* Programmers pccp_mock1_1 
PCCP 모의 1회 1번문항
*/

#include <string>
#include <vector>

using namespace std;

string solution(string input_string) {
    string answer = "";
    
    int is_isoAlphabet['z'-'a'+1]={}, is_AlphabetUsed['z'-'a'+1]={};
    
    is_AlphabetUsed[input_string[0]-'a']=1;

    for(int i=1;i<input_string.length();i++){
        int strNow=input_string[i]-'a';
        if(is_AlphabetUsed[strNow]){
            if(input_string[i]!=input_string[i-1]){
                is_isoAlphabet[strNow]=1;
            }
        }else{
            is_AlphabetUsed[strNow]=1;
        }
    }
    for(int i=0;i<'z'-'a'+1;i++){
        if(is_isoAlphabet[i]){
            answer+=('a'+i);
        }
    }
    if(!answer.length())answer+='N';
    return answer;
}