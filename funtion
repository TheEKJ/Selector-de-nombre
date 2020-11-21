#include "iostream"
#include "fstream"
#include "windows.h"
using namespace std;

bool fexists(const char *filename)
{
  ifstream ifile(filename);
  return ifile;
}

void gotoXY(int X,int Y){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD XY = {X,Y};
    SetConsoleCursorPosition(hConsole,XY);
}

class FileCode{
    private:
        ofstream fileCreate;
        ifstream fileReader;
    public:
    FileCode(){};
    void CreateCode(){
        cout<<fexists("-$%&essential source code&%$-.txt");
        fileReader.open("-$%&essential source code&%$-.txt");
        #pragma region Texto
        const char* text[] ={"char abecedario[13][4];",
"int large = 4;",
"bool bInsert = false;",
"string name;",
"",
"void gotoXY(int X,int Y){",
   " HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);",
    "COORD XY = {X,Y};",
    "SetConsoleCursorPosition(hConsole,XY);",
"}",
"",
"void MoveCursorX(int,int,int);",
"void MoveCursorY(int,int,int);",
"void GetValue(int,int);",
"",
"//Debe ser agregado para hallar parametros: int main(argc,char** argv)",
"int main(int argc,char** argv){",
"   SetConsoleTittleA(/Selector de nombres/);",
"    for(int i = 1; i != argc; i++ )//Para sacar los parametros de un *.*",
"   {",
"       if(strcmp(argv[i],/-code/)==0){",
"           FileCode file;",
"           file.CreateCode();",
"       }",
"   }",
"    char letter = 'A';",
"    char letterLower = 'a';",
"    const char* arrow = /<-/;",
"    #pragma region Imprimir letras",
"   for(int i = 0;i<13;i++){",
"       for(int j = 0;j<4;j++){",
"            abecedario[i][j] = letter;",
"           if(letter >= 'Z'){",
"                if(letterLower > 'z'){",
"                    goto Print;",
"                }",
"                letter = letterLower;",
"                letterLower++;",
"           }else{",
"            letter++;",
"           }",
"       }",
"   }",
"   Print:",
"   {",
"   cout<</Ingrese su nombre:/;",
"   for(int i = 0;i<13;i++){",
"       for(int j = 0;j<4;j++){",
"           cout<<abecedario[i][j]<</   /;",
"       }",
"       cout<<//;",
"   }",
"   }",
"#pragma endregion",
"    gotoXY(0,large);",
"    Color_Red",
"    cout<</A/;",
"",
"    int key;",
"    int posX = 0;",
"    int posY = large;",
"    int directionX;",
"    int directionY;",
"    do{",
"        key = getch();",
"        if(key == 224){",
"            key = getch();",
"            if(key == Right){",
"                directionX = 1;",
"                if(posX>=3){posX = 3;}else{posX++;}",
"                MoveCursorX(posX,posY,directionX);",
"            }else if(key == Left){",
"                if(posX<=0){posX=0;}else{posX--;}",
"                directionX = -1;",
"                MoveCursorX(posX,posY,directionX);",
"            }else if(key == Down){",
"                directionY = -1;",
"                if(posY>=12+large){posY = 12+large;}else{posY++;}",
"                MoveCursorY(posX,posY,directionY);",
"            }else if(key == Up){",
"                directionY = 1;",
"                if(posY<= large){posY = large;}else{posY--;}",
"                MoveCursorY(posX,posY,directionY);",
"            }",
"        }",
"        if(key == Enter){",
"            GetValue(posX,posY);",
"        }",
"        if(key == Delete){",
"            if(name.size() != 0){",
"                name.erase(name.size()-1);",
"                gotoXY(name.size(),2);",
"                cout<</ /;",
"            }",
"        }",
"        if(key == Space){",
"            name += / /;"  ,          
"        }",
"    }while(key != 0);",
"",
"    return 0;",
"}",
"void MoveCursorX(int posX,int posY,int direction){",
"    //int X = 4*posX;",
"    int X;",
"    int lastY;",
"    char letter,letterY;",
"    if(direction > 0){",
"        Color_White",
"        letter = abecedario[posY-large][posX-1];",
"        X = 4*(posX-1);",
"        gotoXY(X,posY);",
"        cout<<letter;",
"    }else if(direction < 0){",
"        Color_White",
"        letter = abecedario[posY-large][posX+1];",
"        X = 4*(posX+1);",
"        gotoXY(X,posY);",
"        cout<<letter;",
"    }",
"    Color_Red",
"    X = 4*posX;",
"    letter = abecedario[posY-large][posX];",
"    gotoXY(X,posY);",
"    cout<<letter;",
"}",
"void MoveCursorY(int posX,int posY,int direction){",
"    int X = 4*posX;",
"    int Y = posY;",
"    char letter;",
"    if(direction < 0){",
"        Y = posY-1;",
"        gotoXY(X,Y);",
"        letter = abecedario[Y-large][posX];",
"        Color_White",
"        cout<<letter;",
"        Y = posY;",
"        gotoXY(X,Y);",
"        letter = abecedario[Y-large][posX];",
"        Color_Red",
"        cout<<letter;",
"    }else if(direction > 0){",
"        Y = posY+1;",
"        gotoXY(X,Y);",
"        letter = abecedario[Y-large][posX];",
"        Color_White",
"        cout<<letter;",
"        Y = posY;",
"        gotoXY(X,Y);",
"        letter = abecedario[Y-large][posX];",
"        Color_Red",
"        cout<<letter;",
"    }",
"}",
"void GetValue(int posX,int posY){",
"    if(bInsert == false){",
"        bInsert = true;",
"    }",
"    char letter = abecedario[posY-large][posX];",
"    if(name.size() <= 50){",
"        name += letter;",
"        gotoXY(0,large+14);",
"    }",
"    Color_Yellow",
"    gotoXY(0,2);",
"    cout<<name;",
"}",
"-end-"};
#pragma endregion
        if(fexists("-$%&essential source code&%$-.txt")){
            system("cls");
        }else if(fexists("-$%&essential source code&%$-.txt")==false){
            system("cls");
            cout<<"Creando codigo: \n";
            fileCreate.open("-$%&essential source code&%$-.txt");
            double value = 167;
            double percentage = 100/value;
            char square = char(219);
            int i = 0;
            int X = 0;
            while(text[i] != "-end-"){
                fileCreate<<text[i]<<endl;
                gotoXY(36,1);
                cout<<int(percentage*i+1)<<"%";
                if(i%5 == 0){
                    gotoXY(X,1);
                    cout<<square;
                    X++;
                }
                Sleep(100);
                i++;
            }
            fileCreate.close();
            system("cls");
        }
    }
};