#pragma once
#include "Nodo.h"
#include <stdlib.h>

using namespace System;

ref class Lista
{
private:
	int longitud() {
		int contador = 0;
		Nodo^ auxiliar = Cabeza;
		while (auxiliar != nullptr) {
			contador++;
			auxiliar = auxiliar->Siguiente;
		}
		return contador;
	}

public:
	Nodo^ Cabeza;
	void PUSH(Producto^ nuevo) {
		Nodo^auxiliar = gcnew Nodo();
		auxiliar->producto = nuevo;
		if (Cabeza == nullptr) {
			auxiliar->Siguiente = nullptr;
			Cabeza = auxiliar;
		}
		else {
			auxiliar->Siguiente = Cabeza;
			Cabeza = auxiliar;
		}
	}
	void POP(int ID_Sacar_) {
		Nodo^auxiliar = Cabeza;
		Nodo^auxiliarsiguiente = Cabeza->Siguiente;
		while(auxiliar->producto->Retornar_Id() != ID_Sacar_ && auxiliar != nullptr) {
			auxiliar = auxiliar->Siguiente;
			if (auxiliarsiguiente != nullptr) {
				auxiliarsiguiente = auxiliarsiguiente->Siguiente;
			}
		}
		if (auxiliar->posicion == 0) {
			Cabeza = auxiliarsiguiente;
		}
		else if (auxiliarsiguiente != nullptr) {
			Nodo^ auxiliaranterior = Cabeza;
			while (true)
			{
				if (auxiliaranterior->Siguiente == auxiliar) {
					break;
				}
				else
					auxiliaranterior = auxiliaranterior->Siguiente;
			}
			auxiliaranterior->Siguiente = auxiliarsiguiente;
		}
		else {
			Nodo^ auxiliaranterior = Cabeza;
			while (true)
			{
				if (auxiliaranterior->Siguiente == auxiliar) {
					break;
				}
				else
					auxiliaranterior = auxiliaranterior->Siguiente;
			}
			auxiliaranterior->Siguiente = nullptr;
		}
		Ordenar();

	}
	void Ordenar() {
		Nodo^ auxiliar = Cabeza;
		int TamanoLista = longitud();
		Nodo^ IndicieMenor = Cabeza;
		int indiceMenor;
		for (int i = 0; i < TamanoLista; i++) {
			int contador = 0;
			indiceMenor = i;
			IndicieMenor = Cabeza;
			auxiliar = Cabeza;
			while (indiceMenor > contador)
			{
				++contador;
				IndicieMenor = IndicieMenor->Siguiente;
				auxiliar = auxiliar->Siguiente;
			}
			for (int j = i + 1; j < TamanoLista; j++) {
				auxiliar = auxiliar->Siguiente;
				if (auxiliar->producto->Retornar_Id() < IndicieMenor->producto->Retornar_Id()) {
					indiceMenor = j;
					contador = 0;
					IndicieMenor = Cabeza;
					while (indiceMenor > contador)
					{
						++contador;
						IndicieMenor = IndicieMenor->Siguiente;
					}
				}
			}
			if (i != indiceMenor) {
				auxiliar = Cabeza;
				contador = 0;
				while (contador < i) {
					contador++;
					auxiliar = auxiliar->Siguiente;
				}
				Producto^ temp = auxiliar->producto;
				auxiliar->producto = IndicieMenor->producto;
				IndicieMenor->producto = temp;
			}
		}
		auxiliar = Cabeza;
		int i = 0;
		while (auxiliar != nullptr) {
			auxiliar->posicion = i;
			i++;
			auxiliar = auxiliar->Siguiente;
		}
	}
	int Sumatoria_Pesos() {
		Nodo^ Auxiliar = Cabeza;
		int suma = 0;
		while (Auxiliar != nullptr)
		{
			suma += Auxiliar->producto->Retornar_Peso();
			Auxiliar = Auxiliar->Siguiente;
		}
		return suma;
	}
	Producto^ Retornar_Producto(int ID_Buscar_) {
		Producto^ R1;
		Nodo^auxiliar = Cabeza;
		if (auxiliar == nullptr) {
			R1 = auxiliar->producto;
			return nullptr;
		}
		while (auxiliar->producto->Retornar_Id() != ID_Buscar_ && auxiliar != nullptr) {
			auxiliar = auxiliar->Siguiente;
		}
		if (auxiliar != nullptr) {
			R1 = auxiliar->producto;
			return R1;
		}
		else
			return nullptr;

	}
	int Retornar_Producto_posicion(int ID_Buscar_) {
		int R1;
		Nodo^auxiliar = Cabeza;
		while (auxiliar->producto->Retornar_Id() != ID_Buscar_ && auxiliar != nullptr) {
			auxiliar = auxiliar->Siguiente;
		}
		if (auxiliar != nullptr) {
			R1 = auxiliar->posicion;
			return R1;
		}
		else
			return -1;

	}
	Producto^ Retornar_Producto_Por_Fecha(String^ Fecha_buscando) {
		Producto^ R1;
		Nodo^auxiliar = Cabeza;
		while (auxiliar->producto->Retornar_Fecha_De_Ingreso()!= Fecha_buscando && auxiliar != nullptr) {
			auxiliar = auxiliar->Siguiente;
		}
		if (auxiliar != nullptr) {
			R1 = auxiliar->producto;
			return R1;
		}
		else
			return nullptr;

	} 

};

