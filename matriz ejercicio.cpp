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

void calcularTotales(double matriz[empresas][meses], double totales[empresas]) {

    for(int i = 0; i < empresas; i++) {

        totales[i] = 0;

        for(int j = 0; j < meses; j++) {
        	
            totales[i] += matriz[i][j];
        }
    }
}

int main () {
	double ingresos2023[empresas][meses];
	double ingresos2024[empresas][meses];
	double ingresos2025[empresas][meses];
	
	leerCSV("input/ingresos-2023.csv", ingresos2023);
	leerCSV("input/ingresos-2024.csv", ingresos2024);
	leerCSV("input/ingresos-2025.csv", ingresos2025);
	
	double total2023[empresas];
	double total2024[empresas];
	double total2025[empresas];
	
	calcularTotales(ingresos2023, total2023);
	calcularTotales(ingresos2024, total2024);
	calcularTotales(ingresos2025, total2025);
	
	string nombresEmpresas[empresas] = {
        "Empresa 1",
        "Empresa 2",
        "Empresa 3",
        "Empresa 4",
        "Empresa 5"
    };
	
	ofstream salida("output/resultados.txt");
	
	if(!salida.is_open()) {
		cout<<" Error al crear el archivo de salida";
		return 1;
	}
	
	for(int i = 0; i < empresas; i++) {
		
		double totalGeneral =
		total2023[i] +
		total2024[i] +
		total2025[i];
		
		salida << nombresEmpresas[i] <<endl;
		salida << "Total 2023: " << total2023[i] << endl;
		salida << "Total 2024: " << total2024[i] << endl;
		salida << "Total 2025: " << total2025[i] << endl;
		salida << "Total 3 años: " << totalGeneral << endl;
		salida << "__________________________" << endl;
	}
	
	salida.close();
	
	cout<<"Archivo generado, todo bien";
	
	return 0;
}
