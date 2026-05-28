#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

const int empresas = 5;
const int meses = 12;

void leerCSV(string nombreArchivo, double matriz[empresas][meses]) {

    ifstream archivo(nombreArchivo.c_str());

    if(!archivo.is_open()) {
        cout << "Error al abrir el archivo: " << nombreArchivo << endl;
        return;
    }

    string linea;

    int fila = 0;

    while(getline(archivo, linea) && fila < empresas) {

        stringstream ss(linea);
        string dato;

        int columna = 0;

        while(getline(ss, dato, ',') && columna < meses) {

            stringstream convertir(dato);
            convertir >> matriz[fila][columna];

            columna++;
        }

        fila++;
    }

    archivo.close();
}
