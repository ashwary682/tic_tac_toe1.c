#include <stdio.h>
#include<conio.h> //to clear the current game 
#include<windows.h> // to sleep for 1 or 2 seconds

char arr[3][3]; //grid of 3*3
int pos; //declaration of postion which will be taken from the player
char ch ='O'; //the first will be O
int row , col , f = 0 ; //declaration for some integer used further
void setup()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr[i][j]=' ';
        
        }
        
    }
    
}

void setpos() //this is for taking numbers from the player and convert it the the foem of mtrix with the help of switch case
{
    switch (pos)
    {
    case 1 : row = 0 , col =0; break;
    case 2 : row = 0 , col =1; break;
    case 3 : row = 0 , col =2; break;
    case 4 : row = 1 , col =0; break;
    case 5 : row = 1 , col =1; break;
    case 6 : row = 1 , col =2; break;
    case 7 : row = 2 , col =0; break;
    case 8 : row = 2 , col =1; break;
    case 9 : row = 2 , col =2; break;
    
    }
}

void display()
{
    printf(" %c | %c | %c \n",arr[0][0],arr[0][1],arr[0][2]);
    printf("------------- \n");
    printf(" %c | %c | %c \n",arr[1][0],arr[1][1],arr[1][2]);
    printf("------------- \n");
    printf(" %c | %c | %c \n",arr[2][0],arr[2][1],arr[2][2]);
}

int checkwin()  //this is for checking that the player win or loose and writing this becase the main function should be clean and we can use another function inside the main funtion just by using the the simple one word
{
if (arr[0][0] == ch && arr[0][1] == ch && arr[0][2]==ch)
return 1;
if (arr[1][0] == ch && arr[1][1] == ch && arr[1][2]==ch)
return 1;
if (arr[2][0] == ch && arr[2][1] == ch && arr[2][2]==ch)
return 1;
if (arr[0][0] == ch && arr[1][0] == ch && arr[2][0]==ch)
return 1;
if (arr[0][1] == ch && arr[1][1] == ch && arr[2][1]==ch)
return 1;
if (arr[0][2] == ch && arr[1][2] == ch && arr[2][2]==ch)
return 1;
if (arr[0][0] == ch && arr[1][1] == ch && arr[2][2]==ch)
return 1;
if (arr[2][0] == ch && arr[1][1] == ch && arr[0][2]==ch)
return 1;
return 0;
}
int main()

{

    setup();
    int i = 0 ;
    while (i!=9)
    {
        checkpos:
        system("cls"); //clear the console screen
        display(); //display the new screen
        printf("current player = %c \n",ch);
        printf("Enter the position \n");
        scanf("%d", &pos);
        if (pos<1 || pos>9)
        {
            printf("Wrong position \n ");
           Sleep(1000); //pause for 1 sec
            goto checkpos;
        }
        
        setpos();
        if (arr[row][col] == ' ')
        {
            arr[row][col] = ch; //if x comes now change it to O
            i++;
            int c;
            c = checkwin() ;
            
            if (c==1)
            {
                system("cls");
                display();
                printf("Player %c win the game \n",ch);
                Sleep(2000);
                printf("Thanks for playing \n");
                return 1;
            }
            if (f==0)
            {
                ch = 'X'; //this is to switch the player from x to o or vice versa
                f = 1 ;
            
            }
            else{
                ch = 'O';
                f = 0;
            }
            
            
        }
        

    
    else{
        printf("The space is already occcupied \n");//this for the way for if doesn't work
        Sleep(1000);//pause of 1 second
        goto checkpos; // ask the player to reenter the position
    }
}
    system("cls") ; //clear the console screen
    display();
    printf("Game drawn \n");
    printf("Thanks for playing!!");
    Sleep(2000); //pause of 2 second
    return 0;
}