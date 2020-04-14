#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if(argc == 2)
    {
        if(strlen(argv[1]) > 26 || strlen(argv[1]) < 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        else
        {
            char key_table[26];
            string copy = argv[1];
            for(int i = 0; i < strlen(copy); i++)
            {
                char current = copy[i];

                
                if((current > 'z' || current < 'a') && (current > 'Z' || current < 'A'))
                {
                    printf("Key must only contain alphabetic characters.\n");
                    return 1;
                }
                else
                {
                    
                    for(int b = 0; b < strlen(copy); b++)
                    {
                        char cur = toupper(copy[b]);
                        for(int j = b + 1; j < strlen(copy); j++)
                        {
                            if(cur == toupper(copy[j]))
                            {
                                printf("Key must not contain repeated characters.\n");
                                return 1;
                                
                            }
                        }
                        
                    }
                    key_table[i] = current;
                }

            }

            
            string user_input = get_string("plaintext: ");
            printf("ciphertext: ");
            for(int i = 0; i < strlen(user_input); i++)
            {
                char curr = user_input[i];
                if(isupper(curr))
                {
                     printf("%c", toupper((key_table[curr - 'A'])));
                }
                else if(islower(curr))
                {
                    printf("%c", tolower((key_table[curr -'a'])));
                }
                else
                {
                    printf("%c", curr);
                }

            }
            
            printf("\n");
            return 0;
            
        }
        
        
        
    }
    else
    {
    printf("Usage: ./substitution key\n");    
    return 1;
    }
    }
