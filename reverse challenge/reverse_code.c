#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX_SIZE 1024
#define CORRECT_PASSWORD "It's wh4t I do and nob0dy's go1ng 2 5top m3!"
#define NEXT_MISSION ""
#define XOR_VALUE 0x29


size_t my_strlen(const char* string)
{
    size_t size = 0;
    while(*string != '\0')
    {
        string++;
        size++;
    }
    return size;
}


char* get_input()
{
    printf("\"Impossible? check my name\" - Kim Possible\n");
    printf("Enter Kim's password:\n");

    char buff[MAX_SIZE] = { 0 };
    fgets(buff, MAX_SIZE - 1, stdin);
    size_t size = my_strlen(buff);
    char *str = malloc(size);
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
    size_t size = my_strlen(input);
    char *encrypted = malloc(size + 1);
    for(size_t i = size / 2; i < size; i++)
    {
        encrypted[i - size / 2] = input[i];
    }
    for(size_t i = 0; i < size / 2; i++)
    {
        encrypted[i + (size - size / 2)] = input[i];
    }
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
    for(size_t i = 0; i < my_strlen(encrypted_password); i++)
    {
        printf("%d, ", encrypted_password[i]);
    }
    printf("0};\n");
    free(encrypted_password);
}


bool check_correct_password(const char* input, const char* correct_password) {
    if(my_strlen(input) != my_strlen(correct_password))
    {
        return false;
    }
    for(size_t i = 0; i < my_strlen(input); i++)
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
    char correct_encrypted_password[] = {25, 77, 80, 14, 90, 9, 78, 70, 24, 71, 78, 9, 27, 9, 28, 93, 70, 89, 9, 68, 26, 8, 96, 93, 14,
                        90, 9, 94, 65, 29, 93, 9, 96, 9, 77, 70, 9, 72, 71, 77, 9, 71, 70, 75, 0};
    char* my_input = get_input();
    char* encrypted_input = encrypt(my_input);
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
