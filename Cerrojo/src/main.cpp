/*
 * main.cpp
 *
 *  Created on: 29 de set. de 2015
 *      Author: santiago
 */

#include <iostream>
#include "Cerrojo.h"

using namespace std;

int main() {
	bool salir = false;
	cout << "Bienvenido a Cerrojo" << endl;
	Cerrojo* cerrojo = new Cerrojo();
	while (salir!=true)
	{
	cout << "Estado: " << cerrojo->mostrarEstado() << endl;
	cout << "Poner el codigo: ";
	string codigo;
	cin >> codigo;
	cerrojo->abrirCerrojo(codigo);
	cout << endl;
	}
	delete cerrojo;
	return 0;
}

