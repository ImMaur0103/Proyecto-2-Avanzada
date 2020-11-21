#pragma once
#include "Producto.h"
#include "Lista.h"

using namespace System;

ref class Bahia
{
private:
	char FilaUbicacion;
	int ColumnaUbicacion;
	int PesoMax;
	int PesoActual = 0;
	int ID_Productos_Almacenado;
	int Cantidad_Productos = 0;

public:
	void Inicializar_Bahia(int Peso, int Id_Para_Bahia, int Columna_Ubicacion, char Fila_Ubicacion) {
		FilaUbicacion = Fila_Ubicacion;
		ColumnaUbicacion = Columna_Ubicacion;
		PesoMax = Peso;
		ID_Productos_Almacenado = Id_Para_Bahia;
	}
	Lista BahiaActiva;

	Bahia^ Arriba;
	Bahia^ Abajo;
	Bahia^ Izquierda;
	Bahia^ Derecha;

	void CalcularPesoBahia() {
		int Peso = BahiaActiva.Sumatoria_Pesos();
		PesoActual = Peso;
	}
	void SacarProducto() {
		BahiaActiva.POP(0);
		Cantidad_Productos--;
		CalcularPesoBahia();
	}
	void SacarProductoEspecifico(int Posicion) {
		BahiaActiva.POP(Posicion);
		Cantidad_Productos--;
		CalcularPesoBahia();
	}
	bool IngresarProducto(Producto^ NewProducto) {
		if ((NewProducto->Retornar_Peso() + PesoActual) <= PesoMax) {
			if (ID_Productos_Almacenado == 4) {
				BahiaActiva.PUSH(NewProducto);
				CalcularPesoBahia();
				BahiaActiva.Ordenar();
				Cantidad_Productos++;
				return true;
			}
			else if (ID_Productos_Almacenado == 5 && (NewProducto->Retornar_Id() == 1 || NewProducto->Retornar_Id() == 2)) {
				BahiaActiva.PUSH(NewProducto);
				CalcularPesoBahia();
				BahiaActiva.Ordenar();
				Cantidad_Productos++;
				return true;
			}
			else if (ID_Productos_Almacenado == 6 && (NewProducto->Retornar_Id() == 2 || NewProducto->Retornar_Id() == 3)) {
				BahiaActiva.PUSH(NewProducto);
				CalcularPesoBahia();
				BahiaActiva.Ordenar();
				Cantidad_Productos++;
				return true;
			}
			else if (ID_Productos_Almacenado == 7 && (NewProducto->Retornar_Id() == 1 || NewProducto->Retornar_Id() == 3)) {
				BahiaActiva.PUSH(NewProducto);
				CalcularPesoBahia();
				BahiaActiva.Ordenar();
				Cantidad_Productos++;
				return true;
			}
			else if (ID_Productos_Almacenado == NewProducto->Retornar_Id()) {
				BahiaActiva.PUSH(NewProducto);
				CalcularPesoBahia();
				BahiaActiva.Ordenar();
				Cantidad_Productos++;
				return true;
			}
			else {
				return false;
			}
		}
		else{
			//falta funcion que retorne nueva bahia
			return false;
		}
		//falta un else que busque la nueva Bahia
	}

	char Retornar_Ubicacion_Fila() {
		return FilaUbicacion;
	}
	int Retornar_Ubicacion_Columna() {
		return ColumnaUbicacion;
	}
	int Retornar_ID_Bahia() {
		return ID_Productos_Almacenado;
	}
	int Retornar_Peso_Actual() {
		return PesoActual;
	}
	int Retornar_Peso_Maximo() {
		return PesoMax;
	}
	int Retornar_Cantidad_Productos() {
		return Cantidad_Productos;
	}
	Producto^ Retornar_Primer_Producto() {
		if (BahiaActiva.Cabeza != nullptr) {
			return BahiaActiva.Cabeza->producto;
		}
		return nullptr;
	}

	String^ Retornar_Informacion() {
		String^ Info;
		Info += "Peso maximo: " + Convert::ToString(PesoMax) + "\r\n";
		Info += "Peso Actual: " + Convert::ToString(PesoActual) + "\r\n";
		Info += "Productos en la bahia: " + Convert::ToString(Cantidad_Productos) + "\r\n";
		switch (ID_Productos_Almacenado)
		{
		case 1:
			Info += "Productos que se pueden almacenar: Articulos de oficina\r\n";
			break;
		case 2:
			Info += "Productos que se pueden almacenar: Ropa\r\n";
			break;
		case 3:
			Info += "Productos que se pueden almacenar: Materiales de construccion\r\n";
			break;
		case 4:
			Info += "Productos que se pueden almacenar: Articulos de oficina, Ropa, Materiales de construccion\r\n";
			break;
		case 5:
			Info += "Productos que se pueden almacenar: Articulos de oficina, Ropa\r\n";
			break;
		case 6:
			Info += "Productos que se pueden almacenar: Ropa, Materiales de construccion\r\n";
			break;
		case 7:
			Info += "Productos que se pueden almacenar: Articulos de oficina, Materiales de construccion\r\n";
			break;
		}
		Info += "\nUbicacion\r\n";
		Info += "Fila: " + FilaUbicacion + "\r\nColumna: "+ Convert::ToString(ColumnaUbicacion) + "\r\n";
		Bahia^ Aux = Arriba;
		if (Arriba != nullptr) {
			Info += "Arriba: " + Convert::ToString(Aux->Retornar_Ubicacion_Columna()) + "," + Convert::ToString(Aux->Retornar_Ubicacion_Fila() + "\r\n");
		}
		else
			Info += "Arriba: null\r\n";
		Aux = Abajo;
		if (Aux != nullptr) {
			Info += "Abajo: " + Convert::ToString(Aux->Retornar_Ubicacion_Columna()) + "," + Convert::ToString(Aux->Retornar_Ubicacion_Fila() + "\r\n");
		}
		else
			Info += "Abajo: null\r\n";
		Aux = Derecha;
		if (Aux != nullptr) {
			Info += "Derecha: " + Convert::ToString(Aux->Retornar_Ubicacion_Columna()) + "," + Convert::ToString(Aux->Retornar_Ubicacion_Fila() + "\r\n");
		}
		else
			Info += "Derecha: null\r\n";
		Aux = Izquierda;
		if (Aux != nullptr) {
			Info += "Izquierda: " + Convert::ToString(Aux->Retornar_Ubicacion_Columna()) + "," + Convert::ToString(Aux->Retornar_Ubicacion_Fila() + "\r\n");
		}
		else
			Info += "Izquierda: null\r\n";
		return Info;
	}
	String^ Retornar_Informacion_Productos() {
		String^ Info;
		Nodo^ Aux = BahiaActiva.Cabeza;
		if (Aux == nullptr) {
			return Info;
		}
		for (int i = 0; i < Cantidad_Productos; i++)
		{
			if (Aux == nullptr)
				break;
			Producto^ ver = Aux->producto;
			Info += "Ingrsado por: " + Convert::ToString(ver->Retornar_Nombre_Almacenador()) + "\r\n";
			Info += "Ingrsado a las: " + Convert::ToString(ver->Retornar_Fecha_De_Ingreso()) + "\r\n";
			Info += "Peso: " + Convert::ToString(ver->Retornar_Peso()) + "\r\n";
			Info += "tipo de producto: " + ver->Tipo_Producto() + "\r\n";
			Info += "--------------------------------------\r\n";
			Aux = Aux->Siguiente;
		}
		return Info;
	}
	String^ Retornar_Informacion_Producto(int Id_Buscando) {
		Producto^ ver = BahiaActiva.Retornar_Producto(Id_Buscando);
		if (ver != nullptr) {
			String^ Info;
			Info += "Ingrsado por: " + Convert::ToString(ver->Retornar_Nombre_Almacenador()) + "\r\n";
			Info += "Ingrsado a las: " + Convert::ToString(ver->Retornar_Fecha_De_Ingreso()) + "\r\n";
			Info += "Peso: " + Convert::ToString(ver->Retornar_Peso()) + "\r\n";
			Info += "tipo de producto: " + ver->Tipo_Producto() + "\r\n";
			return Info;
		}
		else
			return "";
	}
};

