#pragma once

using namespace System;

ref class Producto
{
private:
	int ID_Tipo;
	int Peso;
	String^ Nombre_Almacenador;
	String^ Fecha;

public:
	Producto(int TipoDeProducto,int PesoDelProducto, String^ NombreDelQueAlmacena, String^ FechaActual) {
		ID_Tipo = TipoDeProducto;
		Peso = PesoDelProducto;
		Nombre_Almacenador = NombreDelQueAlmacena;
		Fecha = FechaActual;
	}
	String^ Tipo_Producto() {
		if (ID_Tipo == 1) {
			return "Material para oficina";
		}
		else if (ID_Tipo == 2) {
			return "Ropa";
		}
		else if (ID_Tipo == 3) {
			return "Material de construcción";
		}
	}
	int Retornar_Id() {
		return ID_Tipo;
	}
	int Retornar_Peso() {
		return Peso;
	}
	String^ Retornar_Nombre_Almacenador() {
		return Nombre_Almacenador;
	}
	String^ Retornar_Fecha_De_Ingreso() {
		return Fecha;
	}

};

