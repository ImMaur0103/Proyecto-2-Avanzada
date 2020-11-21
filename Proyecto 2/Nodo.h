#pragma once
#include "Producto.h"

using namespace System;

ref class Nodo
{
public:
	int posicion;
	Producto^ producto;
	Nodo^ Siguiente;
};

