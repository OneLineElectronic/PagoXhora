#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

void gotoxy(int x,int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon,dwPos);
}
int main(){
    int i; //la variable i solo se utiliza para generar los decoradores de ***** junto al for

    double costoPorHora, horasTrabajadas, sueldoBruto, descuentoRenta, iss, descuentoSeguroVida, sueldoNeto;
    // Estas variables estan declaradas como doubles ya que se utiliza para expresion de dinero

    string nombre, apellido, cargo;
    //Estas variales almacenaran variables de tipo texto

    for (i=0; i<=119;i++ ){
        gotoxy(0+i,0); printf("*");
    }
    // Este for solo es un decorador de astericos **********

    /*Esta etapa es la inicial la obtencion de datos del programa */
    /* ----  En esta etapa representa lo que se mostrara de manera inicial en nuestra pantalla 
    (basicamente imprime una interfaz en CMD) ------- */
    gotoxy(45,2);printf("Calcula de sueldo final de empleado"); 
    //Ejemplo imprimiremos en el espaciado 45 de la segunda linia el texto entre comillas

    for (i=0; i<=119;i++ ){
        gotoxy(0+i,4); printf("*");
    }
   
    gotoxy(10,5);printf("Ingrese la siguiente informacion laboral:");

    gotoxy(5,7); cout << "1. Nombres  : ________________________ ";
    
    gotoxy(5,8);cout <<"2. Apellidos : __________________________";
    gotoxy(5,9);cout <<"3. Cargo: ______________________";
    gotoxy(50,7);cout <<"4. Costo de hora: $ _________";
    gotoxy(50,8);cout <<"5. Horas laboradas: _____ horas";

       for (i=0; i<=119;i++ ){
        gotoxy(0+i,12); printf("*");
    }
   ///--------------------------------------------------------------------------------------------------------------------------------------------

    /*En esta etapa regresaremos el cursor para pociscionarla en la interfaz ya antes impresa
    Tambien tomaremos en cada posicion las variables linea por linea */
    gotoxy(19,7); getline(cin,nombre); 
     /*ejemplo posicionaremos el cursor en un epaciado de 19 y al 7 reglon y 
     de esa linia extraeremos el nombre digitado y lo almacenamos como variable */
    gotoxy(20,8); getline(cin,apellido);
    gotoxy(15,9); getline(cin, cargo); 

    gotoxy(70,7); cin >> costoPorHora;  
    /*ejemplo posicionaremos el cursor en un epaciado de 70 y al 7 reglon y 
    de esa linia extraeremos el costoXhora digitado y lo almacenamos como variable */
    gotoxy(70,8); cin >> horasTrabajadas;
    //al terminar de digitar las horas trabajadas 
    //hacemos enter 
    Sleep(200); //Hacemos una pequeña espera 

    system("cls"); //Nos borra la consola o nos hace clear en la consola
    
    //////////////////////////////////////////////////////////////////////
    
    for (i=0; i<=119;i++ ){
        gotoxy(0+i,1); printf("*");
    }

    /////////////////////////////////////////////////////////////////////
    /*en esta etapa haremos los calculos respectivos en base a 
    las variables obtenidas para luego transformarlos en nuevas variales */
    // Calcular el sueldo bruto
    sueldoBruto = costoPorHora * horasTrabajadas;

    // Calcular los descuentos
    descuentoRenta = sueldoBruto * 0.075;
    iss = sueldoBruto * 0.054;
    descuentoSeguroVida = 12;

    // Calcular el sueldo neto
    sueldoNeto = sueldoBruto - descuentoRenta - iss - descuentoSeguroVida;

     ///*****************************************************************//
     //* Esta es la etapa de interfaz de respuesta
     //Despues de havber hecho un borrado de consola imprimimos las variables obtenidas con las operaciones de descuentos procesada

    gotoxy(10,3); cout <<"Empleado: "+ apellido +"  , "+ nombre<< endl; //Imprimimos el "Empleado" Apellido mas el nombre

    gotoxy(10,4); cout <<"Cargo:    "+ cargo << endl; //Imprimimos el cargo
     
     for (i=0; i<=119;i++ ){
        gotoxy(0+i,6); printf("*");
    }
    ///*****************************************************************//
    gotoxy(25, 8); cout <<"Sueldo Inicial : $"  << fixed << setprecision(2) << sueldoBruto << endl; 
    //Imprimimos el sueldo bruto o neto con el ajuste que siempre nos muestre dos decimales

    gotoxy(25, 10); cout <<"(Descuentos de ley)" << endl;
    /*Esta etapa ya esta calculada y alamacenada en nuevas variales en la parte de arriba por lo que solo la mandamos a llamar*/
    gotoxy(25, 11); cout <<"Renta            : $  "  << descuentoRenta << endl;  
    gotoxy(25, 12); cout <<"ISS              : $  "  << iss << endl;
    gotoxy(25, 13); cout <<"Seguro de vida   : $  "  << descuentoSeguroVida << endl;
    gotoxy(44, 14); cout <<"__________" << endl;

    gotoxy(25, 16); cout <<"Sueldo a pagar   : $  "  << sueldoNeto << endl;

    for (i=0; i<=119;i++ ){
        gotoxy(0+i,6); printf("*");
    }
    /*finalizamos el proceso*/
    getch();
    return 0;
}