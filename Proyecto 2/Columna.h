#pragma once
#include "Bahia.h"

using namespace System;

ref class Columna
{
public:
	int Posicion;
	Columna^ Derecha;
	Bahia^ Abajo;
};


