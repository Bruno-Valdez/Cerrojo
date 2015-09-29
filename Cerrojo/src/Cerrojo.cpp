/*
 * Cerrojo.cpp
 *
 *  Created on: 29 de set. de 2015
 *      Author: santiago
 */

#include "Cerrojo.h"

	Cerrojo::Cerrojo()
	{
		this->codigoDeSeguridad = "0000";
		this->estado = cerrado;
		this->cantidadIntentosRestantes = 10;
		this->cantidadIntentosExitosos = 0;
		this->maximaCantidadFallidos = 0;
	};
/*
	Cerrojo::Cerrojo(std::string nuevoCodigoSeguridad)
	{
		this->codigoDeSeguridad = nuevoCodigoSeguridad;
		this->estado = abierto;
		this->cantidadIntentosRestantes = 10;
		this->cantidadIntentosExitosos = 0;
		this->maximaCantidadFallidos = 0;
	}
*/
	bool Cerrojo::validarCodigoSeguridad(std::string codigoSeguridad)
	{
		return (this->codigoDeSeguridad == codigoSeguridad);
	}

	void Cerrojo::bloquearCerrojo()
	{
		this->estado = bloqueado;
	}

	void Cerrojo::calcularCantidadMaximaFallidos()
	{
		enteroCorto candidatoMaximo;
		candidatoMaximo = 10 - this->cantidadIntentosRestantes;
		if(this->maximaCantidadFallidos < candidatoMaximo)
		{
			this->maximaCantidadFallidos = candidatoMaximo;
		}
	}

	std::string Cerrojo::mostrarEstado()
	{
		std::string cadenaEstado;
		switch (this->estado)
		{
			case -1:
					{
						cadenaEstado = "BLOQUEADO";
						break;
					}
			case 0:
					{
						cadenaEstado = "CERRADO";
						break;
					}
			case 1:
					{
						cadenaEstado = "ABIERTO";
						break;
					}
		}
		return cadenaEstado;
	}

	void Cerrojo::abrirCerrojo(std::string codigoSeguridad)
	{
		if(this->estado != bloqueado)
		{
			if(validarCodigoSeguridad(codigoSeguridad) && (this->estado == cerrado))
			{
				this->estado = abierto;
				this->cantidadIntentosExitosos++;
				if(this->cantidadIntentosRestantes != 10)
				{
					calcularCantidadMaximaFallidos();
					this->cantidadIntentosRestantes  = 10;
				}
			}
		}
		else if(this->cantidadIntentosRestantes != 0)
		{
			this->cantidadIntentosRestantes--;
			if(this->cantidadIntentosRestantes == 0)
				bloquearCerrojo();
		}
	}

	void Cerrojo::cerrarCerrojo()
	{
		this->estado = cerrado;
	}

	enteroCorto Cerrojo::intentosExitosos()
	{
		return (this->cantidadIntentosExitosos);
	}

	enteroCorto Cerrojo::intentosRestantesParaBloqueo()
	{
		return (this->cantidadIntentosRestantes);
	}

	bool Cerrojo::cambiarCodigoSeguridad(std::string nuevoCodigoSeguridad)
	{
		bool cambioExitoso = true;
		if(this->estado == abierto)
		{
			this->codigoDeSeguridad = nuevoCodigoSeguridad;
		}
		else
		{
			cambioExitoso = false;
		}
		return cambioExitoso;
	}

	enteroCorto Cerrojo::intentosFallidosConsecutivosMaximo()
	{
		return (this->maximaCantidadFallidos);
	}
