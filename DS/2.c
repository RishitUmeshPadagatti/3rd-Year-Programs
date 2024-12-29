// Develop a Program in C for the following operations on Strings. 
// a. Read a main String (STR), a Pattern String (PAT) and a Replace String (REP) 
// b. Perform Pattern Matching Operation: Find and Replace all occurrences of PAT in STR with REP if PAT exists in STR. Report 
// suitable messages in case PAT does not exist in STR Support the program with functions for
// each of the above operations. Don't use Built-in functions.

#include <stdio.h>
#include <string.h>

int find_match(char str[100], char pat[100], char rep[100], char ans[100]){
    int s, p, r, a, flag;
    int i;
    s = p = r = a = flag = i = 0;
    while(str[s] != '\0'){
        if (str[i] == pat[p]){
            p++;
            i++;
            if (pat[p] == '\0'){
                flag = 1;
                for (r = 0; rep[r] != '\0'; r++, a++)
                    ans[a] = rep[r];
                p = 0;
                s = i;
            }
        }
        else{
            ans[a] = str[s];
            a++;
            s++;
            i = s;
            p = 0;
        }
    }

    return flag;
}

int main(){
    char str[100], pat[100], rep[100], ans[100];
    printf("Enter the main string: ");
    gets(str);
    printf("Enter the pattern string: ");
    gets(pat);
    printf("Enter the replacement string: ");
    gets(rep);

    int flag = find_match(str, pat, rep, ans);

    if (flag == 0){
        printf("Pattern not found\n");
    } else{
        printf("Pattern found!");
        printf("\n%s", ans);
    }

    return 0;
}

// int find_match(char str[100], char pat[100], char rep[100], char ans[100]){
//     int s, p, r, a, flag;
//     int i; // used when a character is found
//     s = p = r = a = flag = i = 0;
//     while(str[s] != '\0'){
//         if (str[i] == pat[p]){
//             p++;
//             i++;
//             if (pat[p] == '\0'){
//                 flag = 1;
//                 for (r = 0; rep[r] != '\0'; r++, a++)
//                     ans[a] = rep[r];
//                 p = 0;
//                 s = i;
//             }
//         }
//         else{
//             ans[a] = str[s];
//             a++;
//             s++;
//             i = s;
//             p = 0;
//         }
//     }

//     ans[a] = '\0';
//     return flag;
// }