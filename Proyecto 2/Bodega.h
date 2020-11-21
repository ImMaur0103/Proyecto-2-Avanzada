#pragma once
#include "Fila.h"
#include "Columna.h"
#include "Bahia.h"
#include "Producto.h"

using namespace System;

ref class Bodega
{
private:
	int Cantidad_Bahias;
	Fila^ Inicio_Fila = gcnew Fila();
	Columna^ Inicio_Columna = gcnew Columna();

public:
	Bodega() {
		Inicio_Fila->Posicion = 65;
		Inicio_Columna->Posicion = 1;
		Cantidad_Bahias = 0;
	}
	void Agregar_Bahia(int Peso_MAximo, int ID_Bahia, char Ubicacion_Bahia_Fila, int Ubicacion_Bahia_Columna) {
		Bahia^ Apuntador = gcnew Bahia();
		Fila^ Auxiliar_Fila = Inicio_Fila;
		Columna^ Auxiliar_Columna = Inicio_Columna;
//---------------[Fracmento que gestiona la inclusion de la bahia en los vectores  Columna(arriba y abajo)]-----------------------//
		//Inicialmente Arreglamos las Columnas
		while (Ubicacion_Bahia_Columna != Auxiliar_Columna->Posicion)
		{
			if (Auxiliar_Columna->Derecha == nullptr) {
				Columna^ Nueva_Columna = gcnew Columna();
				Nueva_Columna->Posicion = Auxiliar_Columna->Posicion + 1;
				Auxiliar_Columna->Derecha = Nueva_Columna;
			}
			Auxiliar_Columna = Auxiliar_Columna->Derecha;
		}
		while (Ubicacion_Bahia_Fila != Auxiliar_Fila->Posicion)
		{
			if (Auxiliar_Fila->Abajo == nullptr) {
				if (Auxiliar_Fila->Posicion == 90) {
					break;
				}
				Fila^ Nueva_Columna = gcnew Fila();
				Nueva_Columna->Posicion = Auxiliar_Fila->Posicion + 1;
				Auxiliar_Fila->Abajo = Nueva_Columna;
			}
			Auxiliar_Fila = Auxiliar_Fila->Abajo;
		}
		Auxiliar_Fila = Inicio_Fila;
		Bahia^ Auxiliar_Recorrer_Siguiente;
		Bahia^ Auxiliar_Recorrer_Anterior;
		Bahia^ Auxiliar_Recorrer;
		while (Ubicacion_Bahia_Fila != Auxiliar_Fila->Posicion && Auxiliar_Fila->Abajo != nullptr && Auxiliar_Columna->Abajo != nullptr)
		{
			if (Auxiliar_Recorrer_Siguiente == nullptr && Auxiliar_Recorrer == nullptr) {
				Auxiliar_Recorrer_Siguiente = Auxiliar_Columna->Abajo;
				Auxiliar_Fila = Auxiliar_Fila->Abajo;
			}
			else if (Auxiliar_Recorrer_Siguiente != nullptr && Auxiliar_Recorrer == nullptr) {
				Auxiliar_Recorrer = Auxiliar_Recorrer_Siguiente;
				Auxiliar_Recorrer_Siguiente = Auxiliar_Recorrer->Abajo;
				Auxiliar_Fila = Auxiliar_Fila->Abajo;
			}
			else if (Auxiliar_Recorrer_Siguiente != nullptr && Auxiliar_Recorrer != nullptr && Auxiliar_Recorrer_Anterior == nullptr) {
				Auxiliar_Recorrer_Anterior = Auxiliar_Recorrer->Arriba;
				Auxiliar_Recorrer = Auxiliar_Recorrer_Siguiente;
				Auxiliar_Recorrer_Siguiente = Auxiliar_Recorrer->Abajo;
				Auxiliar_Fila = Auxiliar_Fila->Abajo;
			}
			else if (Auxiliar_Recorrer_Siguiente == nullptr && Auxiliar_Fila != nullptr) {
				break;
			}
			else {
				Auxiliar_Recorrer_Anterior = Auxiliar_Recorrer;
				Auxiliar_Recorrer = Auxiliar_Recorrer_Siguiente;
				Auxiliar_Recorrer_Siguiente = Auxiliar_Recorrer->Abajo;
				Auxiliar_Fila = Auxiliar_Fila->Abajo;
			}
		}
		if (Auxiliar_Columna->Abajo != nullptr && Auxiliar_Recorrer == nullptr && Auxiliar_Recorrer_Siguiente == nullptr) {
			Auxiliar_Recorrer_Siguiente = Auxiliar_Columna->Abajo;
			if (Auxiliar_Fila->Posicion != Ubicacion_Bahia_Fila) {
				Auxiliar_Fila = Auxiliar_Fila->Abajo;
			}
		}
		if (Auxiliar_Columna->Abajo == nullptr) {
			Bahia^ New_Bahia = gcnew Bahia();
			New_Bahia->Inicializar_Bahia(Peso_MAximo, ID_Bahia, Ubicacion_Bahia_Columna, Ubicacion_Bahia_Fila);
			Auxiliar_Columna->Abajo = New_Bahia;
			Cantidad_Bahias = Cantidad_Bahias + 1;
		}
		else if (Auxiliar_Recorrer_Siguiente != nullptr) {
			Auxiliar_Recorrer = Auxiliar_Recorrer_Siguiente;
			Auxiliar_Recorrer_Siguiente = Auxiliar_Recorrer->Abajo;
			if (Auxiliar_Fila->Posicion != Auxiliar_Recorrer->Retornar_Ubicacion_Fila())
			{
				Bahia^ New_Bahia = gcnew Bahia();
				New_Bahia->Inicializar_Bahia(Peso_MAximo, ID_Bahia, Ubicacion_Bahia_Columna, Ubicacion_Bahia_Fila);
				if (Auxiliar_Recorrer->Retornar_Ubicacion_Fila() > Ubicacion_Bahia_Fila) {
					if (Auxiliar_Recorrer->Arriba == nullptr) {
						Auxiliar_Recorrer->Arriba = New_Bahia;
						Auxiliar_Columna->Abajo = Auxiliar_Recorrer->Arriba;
						Auxiliar_Recorrer_Anterior = Auxiliar_Recorrer->Arriba;
						Auxiliar_Recorrer_Anterior->Abajo = Auxiliar_Recorrer;
						Cantidad_Bahias = Cantidad_Bahias + 1;
					}
				}
				else if (Auxiliar_Recorrer->Retornar_Ubicacion_Fila() < Ubicacion_Bahia_Fila) {
					if (Auxiliar_Recorrer_Siguiente != nullptr) {
						Auxiliar_Recorrer->Abajo = New_Bahia;
						Auxiliar_Recorrer_Siguiente->Arriba = Auxiliar_Recorrer->Abajo;
						Auxiliar_Recorrer_Anterior = Auxiliar_Recorrer;
						Auxiliar_Recorrer = Auxiliar_Recorrer_Anterior->Abajo;
						Auxiliar_Recorrer->Arriba = Auxiliar_Recorrer_Anterior;
						Auxiliar_Recorrer->Abajo = Auxiliar_Recorrer_Siguiente;
						Cantidad_Bahias = Cantidad_Bahias + 1;
					}
					else {
						Auxiliar_Recorrer->Abajo = New_Bahia;
						Auxiliar_Recorrer_Siguiente = Auxiliar_Recorrer->Abajo;
						Auxiliar_Recorrer_Siguiente->Arriba = Auxiliar_Recorrer;
						Cantidad_Bahias = Cantidad_Bahias + 1;
					}
				}
			}
		}
		else if (Auxiliar_Recorrer != nullptr) {
			if (Auxiliar_Fila->Posicion != Auxiliar_Recorrer->Retornar_Ubicacion_Fila())
			{
				Bahia^ New_Bahia = gcnew Bahia();
				New_Bahia->Inicializar_Bahia(Peso_MAximo, ID_Bahia, Ubicacion_Bahia_Columna, Ubicacion_Bahia_Fila);
				if (Auxiliar_Recorrer->Retornar_Ubicacion_Fila() < Ubicacion_Bahia_Fila) {
					if (Auxiliar_Recorrer_Siguiente == nullptr) {
						Auxiliar_Recorrer->Abajo = New_Bahia;
						Auxiliar_Recorrer_Siguiente = Auxiliar_Recorrer->Abajo;
						Auxiliar_Recorrer_Siguiente->Arriba = Auxiliar_Recorrer;
					}
					else {
						Auxiliar_Recorrer->Abajo = New_Bahia;
						Auxiliar_Recorrer_Siguiente->Arriba = Auxiliar_Recorrer->Abajo;
						Auxiliar_Recorrer_Anterior = Auxiliar_Recorrer;
						Auxiliar_Recorrer = Auxiliar_Recorrer->Abajo;
						Auxiliar_Recorrer->Abajo = Auxiliar_Recorrer_Siguiente;
						Auxiliar_Recorrer->Arriba = Auxiliar_Recorrer_Anterior;
					}
					Cantidad_Bahias = Cantidad_Bahias + 1;
				}
				else if (Auxiliar_Recorrer->Retornar_Ubicacion_Fila() > Ubicacion_Bahia_Fila) {
					while (Auxiliar_Recorrer_Anterior->Retornar_Ubicacion_Fila() > Ubicacion_Bahia_Fila)
					{
						Auxiliar_Recorrer_Anterior = Auxiliar_Recorrer_Anterior->Arriba;
						Auxiliar_Recorrer = Auxiliar_Recorrer->Arriba;
					}
					if (Auxiliar_Recorrer_Anterior->Retornar_Ubicacion_Fila() < Ubicacion_Bahia_Fila) {

						Auxiliar_Recorrer_Anterior->Abajo = New_Bahia;
						Auxiliar_Recorrer->Arriba = Auxiliar_Recorrer_Anterior->Abajo;
						Cantidad_Bahias = Cantidad_Bahias + 1;
					}


				}
			}
		}

//-------------------[]-----------------------------
		//Arreglamos las filas
		Auxiliar_Fila = Inicio_Fila;
		while (Ubicacion_Bahia_Fila != Auxiliar_Fila->Posicion)
		{
			if (Auxiliar_Fila->Abajo == nullptr) {
				if (Auxiliar_Fila->Posicion == 90) {
					break;
				}
				Fila^ Nueva_Columna = gcnew Fila();
				Nueva_Columna->Posicion = Auxiliar_Fila->Posicion + 1;
				Auxiliar_Fila->Abajo = Nueva_Columna;
			}
			Auxiliar_Fila = Auxiliar_Fila->Abajo;
		}
		Apuntador = Auxiliar_Columna->Abajo;
		while (Apuntador->Retornar_Ubicacion_Fila() != Auxiliar_Fila->Posicion && Apuntador->Abajo != nullptr)
		{
			Apuntador = Apuntador->Abajo;
		}
		if (Auxiliar_Fila->Derecha == nullptr) {
			Auxiliar_Fila->Derecha = Apuntador;
			
		}
		else if(Auxiliar_Fila->Derecha != nullptr){
			Bahia^ Apuntador2 = Auxiliar_Fila->Derecha;
			while (Apuntador2->Retornar_Ubicacion_Columna() < Ubicacion_Bahia_Columna && Apuntador2->Derecha != nullptr)
			{
				Apuntador2 = Apuntador2->Derecha;
			}
			if (Apuntador2->Retornar_Ubicacion_Columna() < Ubicacion_Bahia_Columna) {
				Apuntador2->Derecha = Apuntador;
				Apuntador->Izquierda = Apuntador2;
				if (Apuntador->Retornar_Ubicacion_Columna() == 1) {
					Auxiliar_Fila->Derecha = Apuntador;
				}
			}
			else if (Apuntador2->Retornar_Ubicacion_Columna() > Ubicacion_Bahia_Columna) {
				Bahia^ Apuntador3 = Apuntador2->Izquierda;
				Apuntador->Derecha = Apuntador2;
				Apuntador->Izquierda = Apuntador3;
				Apuntador2->Izquierda = Apuntador;
				if (Apuntador->Retornar_Ubicacion_Columna() == 1) {
					Auxiliar_Fila->Derecha = Apuntador;
				}
				else {
					Apuntador3->Derecha = Apuntador;
				}
			}
		}
		
	}
	void Agregar_Producto_A_Bahia(Producto^ NewProducto, char Ubicacion_Bahia_Fila, int Ubicacion_Bahia_Columna) {
		Bahia^ Bahia_Llenar = Busqueda_Por_Posicion(Ubicacion_Bahia_Fila, Ubicacion_Bahia_Columna);
		if (Bahia_Llenar->IngresarProducto(NewProducto)) {
			Bahia_Llenar = Busqueda_Por_Espacio(NewProducto->Retornar_Id(), NewProducto->Retornar_Peso());
			if (Bahia_Llenar != nullptr) {
				Bahia_Llenar->IngresarProducto(NewProducto);
			}
		}
	}
	void Agregar_Producto_Y_Bahia(int Peso_MAximo, int ID_Bahia, char Ubicacion_Bahia_Fila, int Ubicacion_Bahia_Columna, Producto^ NewProducto) {
		Agregar_Bahia(Peso_MAximo, ID_Bahia, Ubicacion_Bahia_Fila, Ubicacion_Bahia_Columna);
		Bahia^ Bahia_Llenar = Busqueda_Por_Posicion(Ubicacion_Bahia_Fila, Ubicacion_Bahia_Columna);
		if (Bahia_Llenar->IngresarProducto(NewProducto)) {
			Bahia_Llenar = Busqueda_Por_Espacio(NewProducto->Retornar_Id(), NewProducto->Retornar_Peso());
			if (Bahia_Llenar != nullptr) {
				Bahia_Llenar->IngresarProducto(NewProducto);
			}
		}
	}
	void Eliminar_Bahia(Bahia^ Eliminar_Esta) {
		if (Eliminar_Esta != nullptr) {
			if (true) {
				Bahia^ Auxiliar_Recorrer_Arriba = Eliminar_Esta->Arriba;
				Bahia^ Auxiliar_Recorrer_Abajo = Eliminar_Esta->Abajo;
				Bahia^ Auxiliar_Recorrer_Derecha = Eliminar_Esta->Derecha;
				Bahia^ Auxiliar_Recorrer_Izquierda = Eliminar_Esta->Izquierda;

				if (Auxiliar_Recorrer_Arriba != nullptr) {
					if (Auxiliar_Recorrer_Abajo != nullptr){
						Auxiliar_Recorrer_Arriba->Abajo = Auxiliar_Recorrer_Abajo;
						Auxiliar_Recorrer_Abajo->Arriba = Auxiliar_Recorrer_Arriba;
					}
					else {
						Auxiliar_Recorrer_Arriba->Abajo = nullptr;
					}
				}
				else {
					Columna^ Auxiliar_Columna = Inicio_Columna;
					while (Eliminar_Esta->Retornar_Ubicacion_Columna() != Auxiliar_Columna->Posicion)
					{
						Auxiliar_Columna = Auxiliar_Columna->Derecha;
					}
					if (Auxiliar_Recorrer_Abajo != nullptr) {
						Auxiliar_Columna->Abajo = Auxiliar_Recorrer_Abajo;
						Auxiliar_Recorrer_Abajo->Arriba = nullptr;
					}
					else {
						Auxiliar_Columna->Abajo = nullptr;
					}
				}
				if (Auxiliar_Recorrer_Izquierda != nullptr) {
					if (Auxiliar_Recorrer_Derecha != nullptr){
						Auxiliar_Recorrer_Izquierda->Derecha = Auxiliar_Recorrer_Derecha;
						Auxiliar_Recorrer_Derecha->Izquierda = Auxiliar_Recorrer_Izquierda;
					}
					else {
						Auxiliar_Recorrer_Izquierda->Derecha = nullptr;
					}
				}
				else {
					Fila^ Auxiliar_Fila = Inicio_Fila;
					while (Eliminar_Esta->Retornar_Ubicacion_Fila() != Auxiliar_Fila->Posicion)
					{
						Auxiliar_Fila = Auxiliar_Fila->Abajo;
					}
					if (Auxiliar_Recorrer_Derecha != nullptr) {
						Auxiliar_Fila->Derecha = Auxiliar_Recorrer_Derecha;
						Auxiliar_Recorrer_Derecha->Izquierda = nullptr;
					}
					else {
						Auxiliar_Fila->Derecha = nullptr;
					}
				}
			}
			Cantidad_Bahias--;
		}

	}

	Bahia^ Busqueda_Por_Posicion(char FilaBuscando, int ColumnaBuscando) {
		Bahia^ Apuntador;
		Fila^ Auxiliar_Fila = Inicio_Fila;
		Columna^ Auxiliar_Columna = Inicio_Columna;
		while (Auxiliar_Columna->Derecha != nullptr && Auxiliar_Columna->Posicion != ColumnaBuscando) {
			Auxiliar_Columna = Auxiliar_Columna->Derecha;
		}
		Apuntador = Auxiliar_Columna->Abajo;
		if(Apuntador != nullptr){
			while (Apuntador->Abajo != nullptr && Apuntador->Retornar_Ubicacion_Fila() < FilaBuscando)
			{
				Apuntador = Apuntador->Abajo;
			}
			if (Apuntador->Retornar_Ubicacion_Columna() == ColumnaBuscando && Apuntador->Retornar_Ubicacion_Fila() == FilaBuscando) {
				return Apuntador;
			}
			else {
				return nullptr;
			}
		}
	}
	Bahia^ Busqueda_Por_ID(int Id_Buscando, char Fila_Empezar) {
		Bahia^ Apuntador;
		Fila^ Aux_Fila = Inicio_Fila;
		while (Aux_Fila->Posicion < Fila_Empezar)
		{
			if (Aux_Fila != nullptr) {
				Aux_Fila = Aux_Fila->Abajo;
			}
			else
				break;
		}
		Apuntador = Aux_Fila->Derecha;
		if (Apuntador == nullptr) {
			return Apuntador;
		}
		while (Apuntador->Retornar_ID_Bahia() != Id_Buscando && Apuntador->Retornar_ID_Bahia() != 4)
		{
			if (Aux_Fila->Derecha != nullptr) {
				Apuntador = Aux_Fila->Derecha;
				while (Apuntador->Derecha != nullptr)
				{
					if (Apuntador->Retornar_ID_Bahia() == Id_Buscando || Apuntador->Retornar_ID_Bahia() == 4)
						break;
					Apuntador = Apuntador->Derecha;
				}
			}
			Aux_Fila = Aux_Fila->Abajo;
			if (Aux_Fila == nullptr && (Apuntador->Retornar_ID_Bahia() != Id_Buscando && Apuntador->Retornar_ID_Bahia() != 4)) {
				Apuntador = nullptr;
				break;
			}
		}
		return Apuntador;
	}
	Bahia^ Busqueda_Por_Espacio(int Id_Buscando, int Peso_Minimo) {

		Bahia^ Apuntador;
		Fila^ Aux_Fila = Inicio_Fila;
		Apuntador = Aux_Fila->Derecha;
		while (Aux_Fila->Derecha == nullptr) {
			Aux_Fila = Aux_Fila->Abajo;
			Apuntador = Aux_Fila->Derecha;
		}
		while (!((Apuntador->Retornar_Peso_Actual() + Peso_Minimo) <= Apuntador->Retornar_Peso_Maximo()))
		{

			if (Apuntador->Retornar_ID_Bahia() == 5) {
				if (Id_Buscando == 1 || Id_Buscando == 2) {
					break;
				}
			}
			else if (Apuntador->Retornar_ID_Bahia() == 6) {
				if (Id_Buscando == 3 || Id_Buscando == 2) {
					break;
				}
			}
			else if (Apuntador->Retornar_ID_Bahia() == 7) {
				if (Id_Buscando == 1 || Id_Buscando == 3) {
					break;
				}
			}

			if (Aux_Fila->Derecha != nullptr) {
				Apuntador = Aux_Fila->Derecha;
				while (Apuntador->Derecha != nullptr)
				{
					if ((Apuntador->Retornar_ID_Bahia() == Id_Buscando || Apuntador->Retornar_ID_Bahia() == 4) && (Apuntador->Retornar_Peso_Actual() + Peso_Minimo) <= Apuntador->Retornar_Peso_Maximo())
						break;
					Apuntador = Apuntador->Derecha;
				}
			}
			Aux_Fila = Aux_Fila->Abajo;
			if (Aux_Fila == nullptr && (Apuntador->Retornar_ID_Bahia() != Id_Buscando && Apuntador->Retornar_ID_Bahia() != 4)) {
				Apuntador = nullptr;
				break;
			}
			else if (Aux_Fila == nullptr) {
				Apuntador = nullptr;
				break;
			}
		}
		return Apuntador;
	}
	Bahia^ Busqueda_Por_Espacio_2(int Id_Buscando, int Peso_Minimo, int Columna_ignorar, char Fila_Ignorar) {

		Bahia^ Apuntador;
		Fila^ Aux_Fila = Inicio_Fila;
		Apuntador = Aux_Fila->Derecha;
		while (Aux_Fila->Derecha == nullptr) {
			Aux_Fila = Aux_Fila->Abajo;
			Apuntador = Aux_Fila->Derecha;
		}
		while (((Apuntador->Retornar_Peso_Actual() + Peso_Minimo) <= Apuntador->Retornar_Peso_Maximo()))
		{
			if (Apuntador->Retornar_Ubicacion_Fila() == Fila_Ignorar && Apuntador->Retornar_Ubicacion_Columna() == Columna_ignorar) {
				Apuntador = Apuntador->Derecha;
			}
			if (Apuntador == nullptr) {
				Aux_Fila = Aux_Fila->Abajo;
			}
			if (Aux_Fila == nullptr) {
				Apuntador = nullptr;
				break;
			}

			if (Aux_Fila->Derecha != nullptr) {
				Apuntador = Aux_Fila->Derecha;
				while (Apuntador->Derecha != nullptr)
				{
					if (Apuntador->Retornar_Ubicacion_Fila() == Fila_Ignorar && Apuntador->Retornar_Ubicacion_Columna() == Columna_ignorar) {
						Apuntador = Apuntador->Derecha;
						if (Apuntador == nullptr)
						{
							break;
						}
					}
					if ((Apuntador->Retornar_ID_Bahia() == Id_Buscando || Apuntador->Retornar_ID_Bahia() == 4) && (Apuntador->Retornar_Peso_Actual() + Peso_Minimo) <= Apuntador->Retornar_Peso_Maximo())
						break;
					if (Apuntador->Retornar_ID_Bahia() == 5 && (Apuntador->Retornar_Peso_Actual() + Peso_Minimo) <= Apuntador->Retornar_Peso_Maximo()) {
						if (Id_Buscando == 1 || Id_Buscando == 2) {
							break;
						}
					}
					else if (Apuntador->Retornar_ID_Bahia() == 6 && (Apuntador->Retornar_Peso_Actual() + Peso_Minimo) <= Apuntador->Retornar_Peso_Maximo()) {
						if (Id_Buscando == 3 || Id_Buscando == 2) {
							break;
						}
					}
					else if (Apuntador->Retornar_ID_Bahia() == 7 && (Apuntador->Retornar_Peso_Actual() + Peso_Minimo) <= Apuntador->Retornar_Peso_Maximo()) {
						if (Id_Buscando == 1 || Id_Buscando == 3) {
							break;
						}
					}
					Apuntador = Apuntador->Derecha;
				}
			}
			if ((Apuntador->Retornar_ID_Bahia() == Id_Buscando || Apuntador->Retornar_ID_Bahia() == 4) && (Apuntador->Retornar_Peso_Actual() + Peso_Minimo) <= Apuntador->Retornar_Peso_Maximo())
				break;
			if (Apuntador->Retornar_Ubicacion_Fila() == Fila_Ignorar && Apuntador->Retornar_Ubicacion_Columna() == Columna_ignorar)
			{
				if (Apuntador->Retornar_ID_Bahia() == 5 && (Apuntador->Retornar_Peso_Actual() + Peso_Minimo) <= Apuntador->Retornar_Peso_Maximo()) {
					if (Id_Buscando == 1 || Id_Buscando == 2) {
						break;
					}
				}
				else if (Apuntador->Retornar_ID_Bahia() == 6 && (Apuntador->Retornar_Peso_Actual() + Peso_Minimo) <= Apuntador->Retornar_Peso_Maximo()) {
					if (Id_Buscando == 3 || Id_Buscando == 2) {
						break;
					}
				}
				else if (Apuntador->Retornar_ID_Bahia() == 7 && (Apuntador->Retornar_Peso_Actual() + Peso_Minimo) <= Apuntador->Retornar_Peso_Maximo()) {
					if (Id_Buscando == 1 || Id_Buscando == 3) {
						break;
					}
				}
				else if (Apuntador->Retornar_ID_Bahia() == 4 && (Apuntador->Retornar_Peso_Actual() + Peso_Minimo) <= Apuntador->Retornar_Peso_Maximo()) {
					break;
				}
			}
			Aux_Fila = Aux_Fila->Abajo;
			if (Aux_Fila == nullptr && (Apuntador->Retornar_ID_Bahia() != Id_Buscando && Apuntador->Retornar_ID_Bahia() != 4)) {
				Apuntador = nullptr;
				break;
			}
			if (Aux_Fila == nullptr) {
				Apuntador = nullptr;
				break;
			}

		}

		return Apuntador;
	}

	String^ Retornar_Informacion() {
		String^ Info;
		Bahia^ Apuntador;
		Fila^ Aux_Fila = Inicio_Fila;
		Apuntador = Aux_Fila->Derecha;
		if (Aux_Fila->Derecha == nullptr && Aux_Fila->Abajo == nullptr) {
			return Info;
		}
		while (Aux_Fila->Derecha == nullptr) {
			Aux_Fila = Aux_Fila->Abajo;
			Apuntador = Aux_Fila->Derecha;
		}
		for (int i = 0; i < Cantidad_Bahias; i++)
		{
			if (Apuntador != nullptr) {
				Info += "-----------------------------\r\n";
				Info += "\nUbicacion\r\n";
				Info += "Fila: " + Apuntador->Retornar_Ubicacion_Fila()+ "\r\nColumna: " + Convert::ToString(Apuntador->Retornar_Ubicacion_Columna()) + "\r\n";
				Info += "-----------------------------\r\n";
				Apuntador = Apuntador->Derecha;
			}
			else {
				Aux_Fila = Aux_Fila->Abajo;

				while (Aux_Fila->Derecha == nullptr)
				{
					Aux_Fila = Aux_Fila->Abajo;
				}
				Apuntador = Aux_Fila->Derecha;
				Info += "-----------------------------\r\n";
				Info += "\nUbicacion\r\n";
				Info += "Fila: " + Apuntador->Retornar_Ubicacion_Fila() + "\r\nColumna: " + Convert::ToString(Apuntador->Retornar_Ubicacion_Columna()) + "\r\n";
				Info += "-----------------------------\r\n";
				Apuntador = Apuntador->Derecha;
			}
		}
		return Info;
	}
};

