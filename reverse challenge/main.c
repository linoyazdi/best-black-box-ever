#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


#define MAX_SIZE 1024
#define CORRECT_PASSWORD "It's wh4t I do and nob0dy's go1ng 2 5top m3!"
#define NEXT_MISSION ""
#define XOR_VALUE 0x29


char* get_input()
{
    printf("\"Impossible? check my name\" - Kim Possible\n");
    printf("Enter Kim's password:\n");

    char buff[MAX_SIZE] = { 0 };
    fgets(buff, MAX_SIZE - 1, stdin);
    size_t size = strlen(buff);
    char *str = malloc(size);
    if(str == NULL)
    {
        return NULL;
    }
    // skip \n in the end to make it easier
    for(size_t i = 0; i < size - 1; i++)
    {
        str[i] = buff[i];
    }
    str[size - 1] = '\0';
    return str;
}


char *encrypt(const char* input)
{
    size_t size = strlen(input);
    char *encrypted = malloc(size + 1);
    if(encrypted == NULL)
    {
        return NULL;
    }
    size_t half_size = size / 2;
    size_t copy_amount = size - half_size;
    memcpy(encrypted, input + half_size, copy_amount);
    memcpy(encrypted + copy_amount, input, half_size);
    for(size_t i = 0; i < size; i++)
    {
        encrypted[i] ^= XOR_VALUE;
    }
    encrypted[size] = '\0';
    return encrypted;
}

char* decrypt(const char* encrypted_data)
{
    return encrypt(encrypted_data);
}

void helper_create_password(const char* string)
{
   char* encrypted_password = encrypt(string);
    printf("\n{");
    for(size_t i = 0; i < strlen(encrypted_password); i++)
    {
        printf("%d, ", encrypted_password[i]);
    }
    printf("0};\n");
    free(encrypted_password);
}


bool check_correct_password(const char* input, const char* correct_password) {
    if(strlen(input) != strlen(correct_password))
    {
        return false;
    }
    for(size_t i = 0; i < strlen(input); i++)
    {
        if(input[i] != correct_password[i])
        {
            return false;
        }
    }
    return true;
}

void print_success() {
    char *data[] = {"                                     ......                                     \0","                            .*/(((((((/(((((((((,                               \0","                        ./(*,*/((((///(/(,*/(((((,                              \0","                     .*/(((((//////////(/////(*///./((((,                       \0","                   ,/(((///////////(//*,,,,,,,,(/(/((((((/.                     \0","                  *(((((///(//**///////(/*.    (((/(/((*(((*                    \0","                 *((((///,//////////((.    *((/.((//(/////((/                   \0","                ./((((*////////////*  */*#&&@&. .(/(*//(//(((/                  \0","                *((/,(//////////*%.    ,  @@@%(  ,(/   /(/*(((,                 \0","                *((*(/////////*#.#@*  .,*...,   . /    *((/(((*                 \0","                *(*((/////////  &&# .   .. .  ..   (//((/////(/                 \0","                 */(((////(,      .,*,  . ..,  .  /(((/(((*(((/.                \0","                 ./(((/(/(/(.      .*@@&* ., .   ,(////////(((,                 \0","                   /(((//(//((/*      ,,.   .*,  ///////(*((((.                 \0","                    ,((/(///////////*////((/(@@@@////////((((,                  \0","                      .////////***////**#@@@@@@@&*/**/*///((*                   \0","                         .(&%@@@@@@@@@@@@@@@@@#@@@@@%(/////,                    \0","                     (@@@@@@@@@@@@&%@@@@@@@@@@@@@@@@@@&%*/.                     \0","                 .@@@@@@@@@@@@&&(/(@@@@@@@@@//*%@@@@@@@@@%                      \0","                .@@@@@@@*        ./@@@@@@@&*******#%@@@@@@@&                    \0","                 @@@@@@&.         (@@@@@@%*////*//*/*%&@@@@@@(                  \0","                 &@@@@@(          %/.,(@@*///(*/////.  .%@@@@@&                 \0","                 *@%   ,         ,.     #  *(*(//(*    (@@@@@@@,                \0","                  /    *        ,  ..   *   ,(((/    *@@@@@@@#                  \0","                   *@@%@. .@&@&%.*(     ,&@. .(.   ,,.  .@@.                    \0","                 *@&%&&&/@%&&&&&&@%,&&&@&%&&/    ##,   /,                       \0","                *&&&&%@%&%#,,*/##/**%@%%&@@&%#.@%%&&&/                          \0","                   #@&%@&((**/(*,#&#%#%&%#&%%%%&&&&&&@.                         \0","                     *@%#*,*@&##%%%%#%&****(, @&&@%&%@.                         \0","                  .@&&&%%%#@@@@%%%&#,*******( *&,                               \0","                 .&%%%%##@%%#%@/,***********/(                                  \0","           #///*//&%%##(**(****/***********/*//#                                \0","         *(////*%#/*******(****%***/********/*#//(                              \0","        *#%(*/#((*******(#*/*/  ,(//////****(/////(*                            \0","        %*#%/*#************//(    %*////*****#**/%(#(.                          \0","       (///*((***********/////.    #//////****#(//((#(%.                        \0","       %//*#/*************////#     #(////**/**/(*///*//#.                      \0","      *(/*%*/************////*%      ((/////*****#*////*//%,                    \0","      ,#/%****************/////,      /(//********/#//*////*%*                  \0","       ,#/*/*************//////%       *//////*/*****/(#((##//#(                \0","      *#///***************///////       *//////*********/***////##              \0","     ,#/////***************/////#        /*///////*********///////(%            \0","    .%/////****************/////#.        (//////*************////*/##          \0","    %/*/////*************///////#.         (////////***********//////(%         \0","   /%//////***************//////(           (//////*************//////%.        \0","   *#*////*//*/********///////%.             .(/////////*******///*//##         \0","        .,(%(*/*******//////%.                 /#*////////********//#           \0","         .#(*********///##.                       ,(%(//*/*/******#*//*.        \0","         ,***/(#%#/***%                                  */***********/#        \0","       ,%@@@@@@@@@@@@&%/                                 .#@@@@@@@@@@@@@(.      \0","   /@@@@@@@@@@@@@,    ., .,,**,,,/..                         .&@@@@@@@@@@@@@@%. \0"," /#&@@@@@&%#(*.                                                *@@@@@@@@@@@@@@(.\0", NULL};
    for(char** string_runner = data; *string_runner != NULL; string_runner++) {
        printf("%s\n", *string_runner);
    }
    printf("\"It's not the same when I rant to myself.\" - Dr. Drakken\n\n");
    printf("Well done! We found an encrypted file on the intruder's phone. \n");
    printf("Your mission, if you choose to accept it, is to decrypt the following message:\n");
}


int main() {
    // helper_create_password(CORRECT_PASSWORD);
    char* correct_encrypted_password = "\x19MP\x0eZ\tNF\x18GN\t\x1b\t\x1c]FY\tD\x1a\x08`]\x0eZ\t^A\x1d]\t`\tMF\tHGM\tGFK";
    char* my_input = get_input();
    if(my_input == NULL)
    {
        return -1;
    }
    char* encrypted_input = encrypt(my_input);
    if(encrypted_input == NULL)
    {
        return -1;
    }
    free(my_input);
    if(check_correct_password(encrypted_input, correct_encrypted_password) == true)
    {
        print_success();
    }
    else
    {
        printf("Failed, try again\n");
    }
    free(encrypted_input);
    return 0;
}
