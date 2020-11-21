#include "iostream"
#include "conio.h"
#include "string.h"
#include "windows.h"
#include "fstream"
#include "funtion.h"
#define Color_Red SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
#define Color_White SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
#define Color_Yellow SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);
#define Up 72
#define Down 80
#define Left 75
#define Right 77
#define Enter 13
#define Delete 8
#define Space 32
using namespace std;
char abecedario[13][4];
int large = 4;
bool bInsert = false;
string name;

void MoveCursorX(int,int,int);
void MoveCursorY(int,int,int);
void GetValue(int,int);

//Debe ser agregado para hallar parametros int main(argc,char** argv)
int main(int argc,char** argv){
    SetConsoleTitleA("Selector de nombre");
    for(int i = 1; i != argc; i++ )//Para sacar los parametros de un *.*
   {
       if(strcmp(argv[i],"-code")==0){
           FileCode file;
           file.CreateCode();
       }
   }
    char letter = 'A';
    char letterLower = 'a';
    const char* arrow = "<-";
    #pragma region Imprimir letras
   for(int i = 0;i<13;i++){
       for(int j = 0;j<4;j++){
            abecedario[i][j] = letter;
           if(letter >= 'Z'){
                if(letterLower > 'z'){
                    goto Print;
                }
                letter = letterLower;
                letterLower++;
           }else{
            letter++;
           }
       }
   }
   Print:
   {
   cout<<"Ingrese su nombre: \n\n\n\n";
   for(int i = 0;i<13;i++){
       for(int j = 0;j<4;j++){
           cout<<abecedario[i][j]<<"   ";
       }
       cout<<"\n";
   }
   }
#pragma endregion
    gotoXY(0,large);
    Color_Red
    cout<<"A";

    int key;
    int posX = 0;
    int posY = large;
    int directionX;
    int directionY;
    do{
        key = getch();
        if(key == 224){
            key = getch();
            if(key == Right){
                directionX = 1;
                if(posX>=3){posX = 3;}else{posX++;}
                MoveCursorX(posX,posY,directionX);
            }else if(key == Left){
                if(posX<=0){posX=0;}else{posX--;}
                directionX = -1;
                MoveCursorX(posX,posY,directionX);
            }else if(key == Down){
                directionY = -1;
                if(posY>=12+large){posY = 12+large;}else{posY++;}
                MoveCursorY(posX,posY,directionY);
            }else if(key == Up){
                directionY = 1;
                if(posY<= large){posY = large;}else{posY--;}
                MoveCursorY(posX,posY,directionY);
            }
        }
        if(key == Enter){
            GetValue(posX,posY);
        }
        if(key == Delete){
            if(name.size() != 0){
                name.erase(name.size()-1);
                gotoXY(name.size(),2);
                cout<<" ";
            }
        }
        if(key == Space){
            name += " ";            
        }
    }while(key != 0);

    return 0;
}
void MoveCursorX(int posX,int posY,int direction){
    //int X = 4*posX;
    int X;
    int lastY;
    char letter,letterY;
    if(direction > 0){
        Color_White
        letter = abecedario[posY-large][posX-1];
        X = 4*(posX-1);
        gotoXY(X,posY);
        cout<<letter;
    }else if(direction < 0){
        Color_White
        letter = abecedario[posY-large][posX+1];
        X = 4*(posX+1);
        gotoXY(X,posY);
        cout<<letter;   
    }
    Color_Red
    X = 4*posX;
    letter = abecedario[posY-large][posX];
    gotoXY(X,posY);
    cout<<letter;
}
void MoveCursorY(int posX,int posY,int direction){
    int X = 4*posX;
    int Y = posY;
    char letter;
    if(direction < 0){
        Y = posY-1;
        gotoXY(X,Y);
        letter = abecedario[Y-large][posX];
        Color_White
        cout<<letter;
        Y = posY;
        gotoXY(X,Y);
        letter = abecedario[Y-large][posX];
        Color_Red
        cout<<letter;
    }else if(direction > 0){
        Y = posY+1;
        gotoXY(X,Y);
        letter = abecedario[Y-large][posX];
        Color_White
        cout<<letter;
        Y = posY;
        gotoXY(X,Y);
        letter = abecedario[Y-large][posX];
        Color_Red
        cout<<letter;
    }
}
void GetValue(int posX,int posY){
    if(bInsert == false){
        bInsert = true;
    }
    char letter = abecedario[posY-large][posX];
    if(name.size() <= 50){
        name += letter;
        gotoXY(0,large+14);
    }
    Color_Yellow
    gotoXY(0,2);
    cout<<name;
}