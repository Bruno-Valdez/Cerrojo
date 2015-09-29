/*
 * Cerrojo.h
 *
 *  Created on: 28 de set. de 2015
 *      Author: santiago
 */

#ifndef CERROJO_H_
#define CERROJO_H_

#include <iostream>
#include <string>

typedef unsigned short int enteroCorto;

enum estadoCerrojo{bloqueado = -1, cerrado, abierto};

class Cerrojo{

	private:
			std::string codigoDeSeguridad;
			estadoCerrojo estado;
			enteroCorto cantidadIntentosRestantes;
			enteroCorto cantidadIntentosExitosos;
			enteroCorto maximaCantidadFallidos;

	private:
			bool validarCodigoSeguridad(std::string codigoSeguridad);

			void bloquearCerrojo();

			void calcularCantidadMaximaFallidos();

	public:
			Cerrojo();

			//Cerrojo(std::string nuevoCodigoSeguridad);

			std::string mostrarEstado();

			void abrirCerrojo(std::string codigoSeguridad);

			void cerrarCerrojo();

			enteroCorto intentosExitosos();

			enteroCorto intentosRestantesParaBloqueo();

			bool cambiarCodigoSeguridad(std::string nuevoCodigoSeguridad);

			enteroCorto intentosFallidosConsecutivosMaximo();
};

#endif /* CERROJO_H_ */
