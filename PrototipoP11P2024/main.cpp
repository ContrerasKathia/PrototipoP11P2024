#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <iomanip>

using namespace std;

//DEFINIENDO CONSTANTES

#define NUMERO_EMPRESAS 5
#define MAX_MONTO 100000000
#define MIN_MONTO 0
#define NUMERO_YEAR 4
#define MAXIMA_LONGITUD_CADENA 100

//HECHO POR KATHIA CONTRERAS 9959-23-8246

//DEFINIENDO PROTOTIPO DE MATRICES

void llamaCiclo();
int busquedaAleatorios(int minimo, int maximo);
void llenarMatriz(float matriz[NUMERO_EMPRESAS][NUMERO_YEAR + 1]);
void imprimirMatrizLinea();
float imprimirMatriz(float matriz[NUMERO_EMPRESAS][NUMERO_YEAR + 1], char empresas[NUMERO_EMPRESAS][MAXIMA_LONGITUD_CADENA], string nombreIndustria);
int main()
{
    srand(getpid());
    llamaCiclo();
    return 0;
}
void llamaCiclo()
{
    //Definiendo matrices de las industrias
    float matrizIndustria1[NUMERO_EMPRESAS][NUMERO_YEAR + 1];
    float matrizIndustria2[NUMERO_EMPRESAS][NUMERO_YEAR + 1];
    float matrizIndustria3[NUMERO_EMPRESAS][NUMERO_YEAR + 1];

    // definiendo variable para repetir el programa o no
    char opcion;
    bool repetir = true;

    float promedioIndustria1;
    float promedioIndustria2;
    float promedioIndustria3;


    //Se define e inicializa el vector empresas
    char empresas[NUMERO_EMPRESAS][MAXIMA_LONGITUD_CADENA] = {"Empresa 1","Empresa 2","Empresa 3","Empresa 4","Empresa 5"};
    while(repetir)
    {
        //limpia pantalla
        system("cls");
        cout<<"Hecho Por Kathia Contreras Carne ---- 9959-23-8246 ----"<<endl;
        promedioIndustria1=0;
        promedioIndustria2=0;
        promedioIndustria3=0;
        cout << "*** Comparativo de Industrias ***" << endl << endl;
        //empieza a llamar a las funciones mandando los parametros de las matrices para llenarlas
        llenarMatriz(matrizIndustria1);
        //función para imprimir matriz y almacenar en promedioIndustria el promedio general de la industria
        promedioIndustria1= imprimirMatriz(matrizIndustria1, empresas, "Camara de Industrias");
        llenarMatriz(matrizIndustria2);
        promedioIndustria2 = imprimirMatriz(matrizIndustria2, empresas, "Camara de la Construccion");
        llenarMatriz(matrizIndustria3);
        promedioIndustria3 = imprimirMatriz(matrizIndustria3, empresas, "Camara de transporte");

        //Decisor que verifica que industria tiene el mejor pormedio
        if (promedioIndustria1 > promedioIndustria2 && promedioIndustria1 > promedioIndustria3)
        {
            cout << " La industria con el mejor promedio es : " << "Camara de Industrias" << " Promedio: Q." << promedioIndustria1 << endl;
        } else
        if (promedioIndustria2 > promedioIndustria1 && promedioIndustria2 > promedioIndustria3)
        {
            cout << " La industra con el mejor promedio es : " << "Camara de la Construccion" << " Promedio: Q." << promedioIndustria2<< endl;
        } else
        if (promedioIndustria3 > promedioIndustria2 && promedioIndustria3 > promedioIndustria1)
        {
            cout << " La industria con el mejor promedio es : " << "Camara de transporte" << " Promedio: Q." << promedioIndustria3 << endl;
        } else
        {
            cout << " Algunas industrias tienen el mismo promedio " << endl << endl;
        }
        cout<<endl;
        //ingresa en variable si desea otro calculo y si la respuesta es no, el ciclo acaba al convertirse en false la variable repetir
        cout << "Desea otro calculo (s/n)? ";
        cin >> opcion;
        if (opcion == 'n'||opcion == 'N')
        {
            repetir=false;
        }
    }
}
//funcion que genera aleatorios en el rango establecido
int busquedaAleatorios(int minimo, int maximo)
{
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

//funcion que solamente llama a la funcion busquedaAleatorios y almacena en una matriz
void llenarMatriz(float matriz[NUMERO_EMPRESAS][NUMERO_YEAR + 1])
{
    int y, x;
    for (y = 0; y < NUMERO_EMPRESAS; y++) //ciclo controla filas
    {
        float suma = 0;
        int monto = 0;
        for (x = 0; x < NUMERO_YEAR; x++) //ciclo controla columnas
        {
            monto = busquedaAleatorios(MIN_MONTO, MAX_MONTO);
            suma += (float)monto;
            matriz[y][x] = monto;
            monto=0;
        }
        //inserta el total de los montos al final de cada fila
        matriz[y][NUMERO_YEAR] = suma;
    }
}

void imprimirMatrizLinea()
{
    int x;
    cout << "---------------";
    for (x = 0; x < NUMERO_YEAR + 1; x++)
    {
        cout << "----------------";
    }
    cout << "+\n";
}
float imprimirMatriz(float matriz[NUMERO_EMPRESAS][NUMERO_YEAR + 1], char empresas[NUMERO_EMPRESAS][MAXIMA_LONGITUD_CADENA], string nombreIndustria)
{
    //Funciòn que imprime la matriz en pantalla y realizando los calculos necesarios para el promedio

    //define variables y matrices
    int y, x;
    float promedioMayor = matriz[0][NUMERO_YEAR];
    float promedioMenor = matriz[0][NUMERO_YEAR];
    float totalGeneral = 0;
    float promedioGeneral = 0;
    char empresaPromedioMayor[MAXIMA_LONGITUD_CADENA];
    char empresaPromedioMenor[MAXIMA_LONGITUD_CADENA];
    memcpy(empresaPromedioMayor, empresas[0], MAXIMA_LONGITUD_CADENA);
    memcpy(empresaPromedioMenor, empresas[0], MAXIMA_LONGITUD_CADENA);
    //empieza a imprimir los datos
    cout << nombreIndustria << endl;
    //imprime matriz
    cout << "(2015)=>Monto1  (2016)=>Monto2 (2017)=>Monto3  (2018)=>Monto4 " << endl;
    imprimirMatrizLinea();
    cout << setw(9) << "Empresa";
    int year=2015;
    //imprime los años inciando desde el 2015 y aunmenta 1 en cada iteracion
    for (x = 0; x < NUMERO_YEAR; x++)
    {
        cout << setw(15) << year++;
    }
    cout << setw(14) << "Tot" << endl;
    imprimirMatrizLinea();
    for (y = 0; y < NUMERO_EMPRESAS; y++)
    {
        cout << "|" << setw(8) << empresas[y] << setw(2)<< "|";
        float suma = 0;
        for (x = 0; x < NUMERO_YEAR; x++)
        {
            int monto = matriz[y][x];
            cout << setw(1) <<"Q."<< setw(12)<< monto << setw(2)<< "|";
        }
        float promedio = matriz[y][NUMERO_YEAR];
        totalGeneral += matriz[y][NUMERO_YEAR];
        if (promedio > promedioMayor)
        {
            promedioMayor = promedio;
            memcpy(empresaPromedioMayor, empresas[y], MAXIMA_LONGITUD_CADENA);
        }
        if (promedio < promedioMenor)
        {
            promedioMenor = promedio;
            memcpy(empresaPromedioMenor, empresas[y], MAXIMA_LONGITUD_CADENA);
        }
        cout <<"Q."<< setw(9) << fixed << setprecision(2) <<promedio << setw(2)<< "|" << endl;
        imprimirMatrizLinea();
    }
    promedioGeneral = totalGeneral / NUMERO_EMPRESAS; //calcula el promedio General por industria
    //imprime quien tiene el monto mayor, el monto menor y el monto promedio de la industria
    cout << "Monto mayor: " << setw(10) << empresaPromedioMayor << " Q." << setw(10) << promedioMayor << endl;
    cout << "Monto menor: " << setw(10) << empresaPromedioMenor << " Q." <<  setw(10) << promedioMenor << endl;
    cout << "Monto prom : " << " Q." << setw(10) <<  promedioGeneral << endl << endl;
    return promedioGeneral;
}

