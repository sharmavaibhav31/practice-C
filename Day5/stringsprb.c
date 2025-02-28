/*Reverse Words in a Sentence (Using Strings)
Problem Statement:  Write a function to reverse the words in a sentence while keeping word order intact.  
Example:  
- Input: "Hello World"  
- Output: "olleH dlroW"

Function Prototype:
void reverseWords(char str[]);

Sample Test Case:  
Input:  
Enter a sentence: Hello World  

Output:
Reversed Sentence: olleH dlroW */

#include <stdio.h>
#include <string.h>

// Function to reverse a word
void reverseWord(char *word) {
    int len = strlen(word);
    for (int i = 0; i < len / 2; i++) {
        char temp = word[i];
        word[i] = word[len - i - 1];
        word[len - i - 1] = temp;
    }
}

// Function to reverse words in a sentence
void reverseWords(char str[]) {
    char temp[100];
    strcpy(temp, str);  // Copy the original string to avoid modification

    char *token = strtok(temp, " ");
    while (token != NULL) {
        reverseWord(token);
        printf("%s ", token);
        token = strtok(NULL, " ");
    }
    printf("\n");
}

int main() {
    char str[100];
    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove trailing newline from fgets
    str[strcspn(str, "\n")] = '\0';

    printf("Reversed Sentence: ");
    reverseWords(str);

    return 0;
}



/*
Alternate code to be verified
to reverse the word and sentence
#include<stdio.h>
#include<string.h>

char str[100];
char rev[50];


// void reverseWords(char str[]);
void reverseSentence(char rev[]);

void main(){
    printf("Enter a sentence:");
    scanf("%[^\n]s", str);
    // reverseWords(str);
    reverseSentence(str);
}

// void reverseWords(char str[]){
//     strcpy(rev, strrev(str));
//     printf("Reversed Words: %s\n", rev);
// }

void reverseSentence(char str[]){
    char *revSen;
    revSen=strtok(str, " ");
    while (revSen != NULL) {
        printf("%s ", strrev(revSen));
        revSen=strtok(NULL, " ");
    }
    printf("\n");
}
*/

/*
reverse words in a sentence

Alternate code to be verified
#include <stdio.h>
 
void reverse(char* begin, char* end)
{
    char temp;
    while (begin < end) {
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}
 
void reverseWords(char* s)
{
    char *word_begin = s, *temp = s;
 
    while (*temp) {
        temp++;
        if (*temp == '\0') {
            reverse(word_begin, temp - 1);
        }
        else if (*temp == ' ') {
            reverse(word_begin, temp - 1);
            word_begin = temp + 1;
        }
    }
    reverse(s, temp - 1);
}
 
int main()
{
    char s[100];
    scanf("%[^\n]s", s);
    reverseWords(s);
    printf("%s", s);
    return 0;
}
*/


/*
reverse each words in a sentence

#include <stdio.h>
#include <string.h>

// Function to reverse a word in place
void reverseWord(char *start, char *end) {
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

// Function to reverse each word in a sentence
void reverseEachWord(char *str) {
    char *wordStart = NULL;
    char *temp = str;
   
    while (*temp) {
        if ((wordStart == NULL) && (*temp != ' ')) {
            wordStart = temp; // Mark the start of a word
        }
       
        if (wordStart && (*(temp + 1) == ' ' || *(temp + 1) == '\0')) {
            reverseWord(wordStart, temp);
            wordStart = NULL; // Reset wordStart for the next word
        }
        temp++;
    }
}

int main() {
    char str[100];
   
    printf("Enter a sentence: ");
    scanf("%[^\n]s",str);
   
    reverseEachWord(str);
   
    printf("Reversed sentence: %s\n", str);
   
    return 0;
}
*/