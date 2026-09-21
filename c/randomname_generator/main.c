#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
//TODO:: fix the mutatebangers function , infinite loop persent
typedef unsigned short ushort;
typedef unsigned int uint;

// word ::= <syl>*
// <syl> ::= <con><vow>
// <syl> ::= <con><vow><con>
// <syl> ::= <vow><con><vow>
// <syl> ::= <vow><con>

const char* vowels = "aeiou";
const char * consonants = "bcdfghjklmnpqrstvwxyz";
const char* bangers[4]={"coix", "uwu", "bex","sipix"};

bool IsVowel(char *v){
    unsigned short i=0;
    while(vowels[i]!='\0'){
        if(*v == vowels[i]){
            return true;
            }
        }
        return false;
}

int count(const char* s){
    int length=0;
    int i=0;
    while(s[i]!='\0'){
        ++length;
        ++i;
    }
    
    return length;    
}

typedef enum {
    CONVOW,
    CONVOWCON,
    VOWCON,
    VOWCONVOW
}SyllableOrder;

void MutateBangers(const char* bangers[]){
    
    printf("Bangers::\n");
    for(int i=0; i<4; ++i){
       ushort j=0;
        while(bangers[i][j]!='\0'){
            printf("%c,", bangers[i][j]);
        }
        printf("%s\n", bangers[i]);
    }
}

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


void RandomWords(char *buffer, unsigned short no_of_words,int syl_len){
  
    printf("Words::\n");
    for(int j=0;j<no_of_words;j++){
        int offset=0;
        int rsyl=(rand()%syl_len)+1;
        for (int i=0;i<rsyl;i++){
            SingleSyllable(buffer,&offset); 
        }
        buffer[offset]='\0'; 
        printf("%s\n",buffer);
    }
  
    }
int main() {
    
    char word[13];
    for( int i=0; i < 5; i++){
        RandomWords(word, 10, 4);
        printf("\n");
    }

    return 0;
}
