#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char* vowels = "aeiou";
const char * consonants = "bcdfghjklmnpqrstvwxyz";

int count(const char* s){
    int length=0;
    int i=0;
    while(s[i]!='\0'){
        ++length;
        ++i;
    }
    
    return length;    
}

// word ::= <syl>*
// <syl> ::= <con><vow>
// <syl> ::= <con><vow><con>
// <syl> ::= <vow><con>

typedef enum {
    CONVOW,
    CONVOWCON,
    VOWCON,
    VOWCONVOW
}SyllableOrder;

/*
Bangers::
    coix
*/

void SingleSyllable(char * word, int *offset){
    SyllableOrder Syllables[4]={CONVOW, CONVOWCON, VOWCON,VOWCONVOW};
    int k=*offset;
    switch(Syllables[rand()%4]){
    
    case CONVOW:{
        word[k++]=consonants[rand()%count(consonants)];
        word[k++]=vowels[rand()%count(vowels)];
        break;
    }

    case CONVOWCON:{
        word[k++]=consonants[rand()%count(consonants)];
        word[k++]=vowels[rand()%count(vowels)];
        word[k++]=consonants[rand()%count(consonants)];
        break;
    }
    
    case VOWCON:{
        word[k++]=vowels[rand()%count(vowels)];
        word[k++]=consonants[rand()%count(consonants)];
        break;
    }
    case VOWCONVOW:{
        word[k++]=vowels[rand()%count(vowels)];
        word[k++]=consonants[rand()%count(vowels)];
        word[k++]=vowels[rand()%count(consonants)];
        break;

        }
    default:{
        printf("Not a valid syllable order");
        break;
    }
    
}
*offset=k;
}

int main() {
    
    char word[13];
    const int SYL_LEN=4;
    srand(time(NULL));
    printf("Words::\n");
    for(int j=0;j<10;j++){
        int offset=0;
        int rsyl=(rand()%SYL_LEN)+1;
        for (int i=0;i<rsyl;i++){
            SingleSyllable(word,&offset); 
        }
        word[offset]='\0'; 
        printf("%s\n",word);
    }


    return 0;
}
