//**************************************************************************
// Práctica 2 
//**************************************************************************

#include <vector>
#include <GL/gl.h>
#include "vertex.h"
#include <stdlib.h>


const float AXIS_SIZE=5000;
typedef enum{POINTS,EDGES,SOLID,SOLID_COLORS,SOLID_COLORS_VERTS} _modo;

//*************************************************************************
// clase punto
//*************************************************************************

class _puntos3D
{
public:

  
	_puntos3D();
void 	draw_puntos(float r, float g, float b, int grosor);

vector<_vertex3f> vertices;
};

//*************************************************************************
// clase triángulo
//*************************************************************************

class _triangulos3D: public _puntos3D
{
public:

	_triangulos3D();
void 	draw_aristas(float r, float g, float b, int grosor);
void    draw_solido(float r, float g, float b);
void 	draw_solido_colores();
void 	draw_solido_colores_vertices();
void 	colors1();

void 	draw(_modo modo, float r, float g, float b, float grosor);

vector<_vertex3i> caras;
vector<_vertex3f> colores_caras;

};


//*************************************************************************
// clase cubo
//*************************************************************************

class _cubo: public _triangulos3D
{
public:

	_cubo(float tam=0.5);
};


//*************************************************************************
// clase piramide
//*************************************************************************

class _piramide: public _triangulos3D
{
public:

	_piramide(float tam=0.5, float al=1.0);
};


//*************************************************************************
// clase objeto ply
//*************************************************************************

class _objeto_ply: public _triangulos3D
{
public:
   _objeto_ply();

void  parametros(char *archivo);
};

//************************************************************************
// objeto por revolución
//************************************************************************
// tipo= 0 --> normal | 1 --> cono | 2 esfera
// tapa_in = 0 --> sin | 1 --> con


class _rotacion: public _triangulos3D
{
public:
       _rotacion();


void  parametros(vector<_vertex3f> perfil, int num, int tipo, int tapa_in, int tapa_su);
};


//************************************************************************
// objeto por extrusión
//************************************************************************

class _extrusion: public _triangulos3D
{
public:
       _extrusion(vector<_vertex3f> poligono, float x, float y, float z);
};

//*************************************************************************
// clase Cilindro
//*************************************************************************

class _cilindro: public _rotacion
{
public:

	_cilindro(float radio=2, float altura=3, int num=15);  
};


//*************************************************************************
// clase cono
//*************************************************************************

class _cono: public _rotacion
{
public:

	_cono(float radio=2, float altura=3, int num=10); 
};

//*************************************************************************
// clase esfera
//*************************************************************************

class _esfera: public _rotacion
{
public:

	_esfera(float radio=1, int num1=2, int num2=20); 
};

//*************************************************************************
// clase rotación ply
//*************************************************************************

class _rotacion_PLY: public _rotacion
{
public:
 _rotacion_PLY();
 void parametros_PLY(char *archivo, int num);
};
