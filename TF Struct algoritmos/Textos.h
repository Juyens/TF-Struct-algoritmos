#pragma once

#include <iostream>
#include <limits>

#ifdef _WIN32
#  include <Windows.h>
#endif

using namespace std;

enum ConsoleColor { DarkGray, Yellow, White, DarkYellow, DarkGreen, Red, Cyan, Gray };

struct ConsoleType {
    static int ForegroundColor;
    static void Clear();
    static void SetCursorPosition(int x, int y);
};

#ifdef _WIN32
inline int ConsoleType::ForegroundColor = 0;
inline void ConsoleType::Clear() { system("cls"); }
inline void ConsoleType::SetCursorPosition(int x, int y) {
    COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
#else
inline int ConsoleType::ForegroundColor = 0;
inline void ConsoleType::Clear() { cout << "\033[2J\033[H"; }
inline void ConsoleType::SetCursorPosition(int x, int y) { cout << "\033[" << y << ';' << x << 'H'; }
#endif

using Console = ConsoleType;

void limpiar()
{
    Console::Clear();
}

void cursor(int x, int y)
{
    Console::SetCursorPosition(x, y);
}

void borrar(int x, int y, int piso)
{
    if (piso == 0) Console::ForegroundColor = ConsoleColor::DarkGray;
    cursor(x, y);     cout << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219;
    cursor(x, y + 1); cout << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219;
    cursor(x, y + 2); cout << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219;
    cursor(x, y + 3); cout << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219;
    cursor(x, y + 4); cout << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219;
}

void imprimirTextoConFondo(const string& texto, int x, int y, int colorTexto, int colorFondo) {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { (SHORT)x, (SHORT)y };
    DWORD written;

    WORD attr = static_cast<WORD>(colorTexto | (colorFondo << 4));

    FillConsoleOutputAttribute(hConsole, attr, texto.length(), pos, &written);

    SetConsoleTextAttribute(hConsole, attr);
    SetConsoleCursorPosition(hConsole, pos);
    cout << texto;
    SetConsoleTextAttribute(hConsole, 7);
#else
    cursor(x, y);
    cout << texto;
#endif
}

void flecha(int x, int y) {
    imprimirTextoConFondo(" ----\\\\", x, y, 15, 8);
    imprimirTextoConFondo("      \\\\", x, y + 1, 15, 8);
    imprimirTextoConFondo("      //", x, y + 2, 15, 8);
    imprimirTextoConFondo(" ----//", x, y + 3, 15, 8);
}

inline void pauseConsole() {
#ifdef _WIN32
    system("pause>0");
#else
    cout << "Presione ENTER para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
#endif
}

void textoRecibo(int x, int y)
{
    imprimirTextoConFondo("  ____                  _   _             ", x, y, 15, 8);
    imprimirTextoConFondo(" |  _ \\    ___    ___  (_) | |__     ___  ", x, y + 1, 15, 8);
    imprimirTextoConFondo(" | |_) |  / _ \\  / __| | | | '_ \\   / _ \\ ", x, y + 2, 15, 8);
    imprimirTextoConFondo(" |  _ <  |  __/ | (__  | | | |_) | | (_) |", x, y + 3, 15, 8);
    imprimirTextoConFondo(" |_| \\_\\  \\___|  \\___| |_| |_.__/   \\___/ ", x, y + 4, 15, 8);
}

void verdirecciones(int x, int y)
{
    int colorTexto = 15;  
    int colorFondo = 8;   

    imprimirTextoConFondo(" __ __  ____ ____     ____   __ ____   ____   ___   ___ __   ___   __  __  ____  __ ", x, y, colorTexto, colorFondo);
    imprimirTextoConFondo(" || || ||    || \\\\    || \\\\  || || \\\\ ||     //    //   ||  // \\\\  ||\\ || ||    (( \\", x, y + 1, colorTexto, colorFondo);
    imprimirTextoConFondo(" \\\\ // ||==  ||_//    ||  )) || ||_// ||==  ((    ((    || ((   )) ||\\\\|| ||==   \\\\ ", x, y + 2, colorTexto, colorFondo);
    imprimirTextoConFondo("  \\V/  ||___ || \\\\    ||_//  || || \\\\ ||___  \\\\__  \\\\__ ||  \\\\_//  || \\|| ||___ \\_))", x, y + 3, colorTexto, colorFondo);
}

void TextoagregarDirecciones(int x, int y)
{
    int colorTexto = 15; 
    int colorFondo = 8;  

    imprimirTextoConFondo("  ___  ____   ____      ____   __ ____   ____   ___   ___ __   ___   __  __", x, y, colorTexto, colorFondo);
    imprimirTextoConFondo(" // \\\\ || \\\\  || \\\\     || \\\\  || || \\\\ ||     //    //   ||  // \\\\  ||\\ ||", x, y + 1, colorTexto, colorFondo);
    imprimirTextoConFondo(" ||=|| ||  )) ||  ))    ||  )) || ||_// ||==  ((    ((    || ((   )) ||\\\\||", x, y + 2, colorTexto, colorFondo);
    imprimirTextoConFondo(" || || ||_//  ||_//     ||_//  || || \\\\ ||___  \\\\__  \\\\__ ||  \\\\_//  || \\||", x, y + 3, colorTexto, colorFondo);
}


void textodirecciones(int x, int y)
{
    int colorTexto = 15;  
    int colorFondo = 8;   

    imprimirTextoConFondo("          _ _                  *                          '       ", x, y + 0, colorTexto, colorFondo);
    imprimirTextoConFondo(" *        | (_)                 (_)             +                   ", x, y + 1, colorTexto, colorFondo);
    imprimirTextoConFondo("        __| |_ _ __ ___  ___ ___ _  ___  _ __   ___  ___         +  ", x, y + 2, colorTexto, colorFondo);
    imprimirTextoConFondo("       / _` | | '__/ _ \\/ __/ __| |/ _ \\| '_ \\ / _ \\/ __|         ", x, y + 3, colorTexto, colorFondo);
    imprimirTextoConFondo("  +   | (_| | | | |  __/ (_| (__| | (_) | | | |  __/\\__ \\      *  ", x, y + 4, colorTexto, colorFondo);
    imprimirTextoConFondo("       \\__,_|_|_|  \\___|\\___\\___|_|\\___/|_| |_|\\___||___/        +", x, y + 5, colorTexto, colorFondo);
}

void textoRealizarpedido(int x, int y)
{
    int colorTexto = 15;  
    int colorFondo = 8;   

    imprimirTextoConFondo(" ____   ____  ___  __    __ ____  ___  ____     ____   ____ ____   __ ____     ___  ", x, y + 0, colorTexto, colorFondo);
    imprimirTextoConFondo(" || \\\\ ||    // \\\\ ||    ||   // // \\\\ || \\\\    || \\\\ ||    || \\\\  || || \\\\   // \\\\ ", x, y + 1, colorTexto, colorFondo);
    imprimirTextoConFondo(" ||_// ||==  ||=|| ||    ||  //  ||=|| ||_//    ||_// ||==  ||  )) || ||  )) ((   ))", x, y + 2, colorTexto, colorFondo);
    imprimirTextoConFondo(" || \\\\ ||___ || || ||__| || //__ || || || \\\\    ||    ||___ ||_//  || ||_//   \\\\_// ", x, y + 3, colorTexto, colorFondo);
}


auto creditos = []()-> void
    {
        system("cls");
        cout << "\033[31m                                     ;                                                    \033[0m" << endl;
        cout << "\033[31m                                     ED.                                :                 \033[0m" << endl;
        cout << "\033[31m        .,                       ,;  E#Wi                              t#,               .\033[0m" << endl;
        cout << "\033[31m       ,Wt  j.                 f#i   E###G.        t                  ;##W.             ;W\033[0m" << endl;
        cout << "\033[31m      i#D.  EW,              .E#t    E#fD#W;       Ej   GEEEEEEEL    :#L:WE            f#E\033[0m" << endl;
        cout << "\033[31m     f#f    E##j            i#W,     E#t t##L      E#,  ,;;L#K;;.   .KG  ,#D         .E#f \033[0m" << endl;
        cout << "\033[31m   .D#i     E###D.         L#D.      E#t  .E#K,    E#t     t#E      EE    ;#f       iWW;  \033[0m" << endl;
        cout << "\033[31m  :KW,      E#jG#W;      :K#Wfff;    E#t    j##f   E#t     t#E     f#.     t#i     L##Lffi\033[0m" << endl;
        cout << "\033[31m  t#f       E#t t##f     i##WLLLLt   E#t    :E#K:  E#t     t#E     :#G     GK     tLLG##L \033[0m" << endl;
        cout << "\033[31m   ;#G      E#t  :K#E:    .E#L       E#t   t##L    E#t     t#E      ;#L   LW.       ,W#i  \033[0m" << endl;
        cout << "\033[31m    :KE.    E#KDDDD###i     f#E:     E#t .D#W;     E#t     t#E       t#f f#:       j#E.   \033[0m" << endl;
        cout << "\033[31m     .DW:   E#f,t#Wi,,,      ,WW;    E#tiW#G.      E#t     t#E        f#D#;      .D#j     \033[0m" << endl;
        cout << "\033[31m       L#,  E#t  ;#W:         .D#;   E#K##i        E#t     t#E         G#t      ,WK,      \033[0m" << endl;
        cout << "\033[31m        jt  DWi   ,KK:          tt   E##D.         E#t      fE          t       EG.       \033[0m" << endl;
        cout << "\033[31m                                     E#t           ,;.       :                  ,         \033[0m" << endl;
        cout << "\033[31m                                     L:                                                   \033[0m" << endl << endl << endl << endl;


        cout << "                                  _          " << endl;
        cout << "|   _  _ __  _  __ _| _    |   _ |_) _  _    " << endl;
        cout << "|__(/_(_)| |(_| | (_|(_)   |__(_)|  (/_ /_   " << endl << endl;

        cout << "\\ /                           " << endl;
        cout << "|V| _  __ o  _      | |  o  |  |  _ __     _     _  " << endl;
        cout << "| |(_| |  | (_|     ^v^  |  |  | (_|| ||_|(/_\\_/(_|" << endl << endl;

        cout << "                      _  _              " << endl;
        cout << "  | _     o  _  __   |_|(_| _ __  _     " << endl;
        cout << "\\_|(_|\\_/ | (/_ |    | |__|(_||||(_|  " << endl << endl;

        cout << " _           _                            " << endl;
        cout << "| \\ _     o | \\  |/  _ __  _ _|_ _      " << endl;
        cout << "|_/(_|\\_/ | |_/  |\\ (_)|||(_| |  _> |_| " << endl << endl;

    };

auto reclamaciones = []()
    {
        int x = 0, y = 0;
        int colorTexto = 15; 
        int colorFondo = 8;  

        imprimirTextoConFondo("  _        _   _                            _            _____                  _                                      _                                              ", x, y+1,15 , 8);
        imprimirTextoConFondo(" | |      (_) | |                          | |          |  __ \\                | |                                    (_)                                            ", x, y+2,15 , 8);
        imprimirTextoConFondo(" | |       _  | |__    _ __    ___       __| |   ___    | |__) |   ___    ___  | |   __ _   _ __ ___     __ _    ___   _    ___    _ __     ___   ___              ",    x, y+3,15 , 8);
        imprimirTextoConFondo(" | |      | | | '_ \\  | '__|  / _ \\     / _` |  / _ \\   |  _  /   / _ \\  / __| | |  / _` | | '_ ` _ \\   / _` |  / __| | |  / _ \\  | '_ \\   / _ \\ / __|        ", x, y+4,15 , 8);
        imprimirTextoConFondo(" | |____  | | | |_) | | |    | (_) |   | (_| | |  __/   | | \\ \\  |  __/ | (__  | | | (_| | | | | | | | | (_| | | (__  | | | (_) | | | | | |  __/ \\__ \\            ", x, y+5,15 , 8);
        imprimirTextoConFondo(" |______| |_| |_.__/  |_|     \\___/     \\__,_|  \\___|   |_|  \\_\\  \\___|  \\___| |_|  \\__,_| |_| |_| |_|  \\__,_|  \\___| |_|  \\___/  |_| |_|  \\___| |___/    ", x, y+6,15 , 8);
        imprimirTextoConFondo("                                                                                                                                                                      ", x, y+7,15 , 8);
        cout << endl;
    };
