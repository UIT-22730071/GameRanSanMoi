#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
#include <time.h>
#define MINX 2
#define MINY 2
#define MAXX 35
#define MAXY 20
using namespace std;
void gotoxy( int column, int line );
struct Point{
    int x,y;
};

class CONRAN {
public:
    struct Point A[100];
    int DoDai;
    CONRAN() {
        DoDai = 3;
        A[0].x = 10; A[0].y = 10;
        A[1].x = 11; A[1].y = 10;
        A[2].x = 12; A[2].y = 10;
    }
    void Ve(Point Qua) {
        for (int i = 0; i < DoDai; i++){
            gotoxy(A[i].x,A[i].y);
            cout<<"X";
        }
        gotoxy(Qua.x, Qua.y); cout<<"*";
    }

    void DiChuyen() {

    }

    void VeKhung() {

    }
}

int main() {
    CONRAN r;
    int huong = 0;
    char t;
    Point qua;
    srand((int)time(0));
    qua.x = rand() % (MAXX - MINX) + MINX;
    qua.y = rand() % (MAXY - MINY) + MINY;
    while (1)
    {
        if(kbhit) {
            t =getch();
            if(t == 'a') huong = 2;
            if(t == 'w') huong = 3;
            if(t == 'd') huong = 0;
            if(t == 's') huong = 1;
        }
        system("cls");
        VeKhung();
        r.Ve(qua);
        r.DiChuyen(huong, qua);
        Sleep(300);
    }
    
    return 0;
}

void gotoxy(int column, int line) {
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE),
        coord
    );
}