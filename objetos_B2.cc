//**************************************************************************
// Práctica 2
//**************************************************************************

#include "objetos_B2.h"

#include "file_ply_stl.hpp"

//*************************************************************************
// _puntos3D
//*************************************************************************

_puntos3D::_puntos3D() {}

//*************************************************************************
// dibujar puntos
//*************************************************************************

void _puntos3D::draw_puntos(float r, float g, float b, int grosor) {
  int i;
  glPointSize(grosor);
  glColor3f(r, g, b);
  glBegin(GL_POINTS);

  int num_tot_v = vertices.size();
  for (i = 0; i < num_tot_v; i++) {
    glVertex3fv((GLfloat *)&vertices[i]);
  }
  glEnd();
}

//*************************************************************************
// _triangulos3D
//*************************************************************************

_triangulos3D::_triangulos3D() {}

//*************************************************************************
// dibujar en modo arista
//*************************************************************************

void _triangulos3D::draw_aristas(float r, float g, float b, int grosor) {
  int i;
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glLineWidth(grosor);
  glColor3f(r, g, b);
  glBegin(GL_TRIANGLES);

  int num_tot_caras = caras.size();

  for (i = 0; i < num_tot_caras; i++) {
    glVertex3fv((GLfloat *)&vertices[caras[i]._0]);
    glVertex3fv((GLfloat *)&vertices[caras[i]._1]);
    glVertex3fv((GLfloat *)&vertices[caras[i]._2]);
  }
  glEnd();
}

//*************************************************************************
// dibujar en modo sólido con un único color
//*************************************************************************

void _triangulos3D::draw_solido(float r, float g, float b) {
  int i;
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glColor3f(r, g, b);
  glBegin(GL_TRIANGLES);

  int num_tot_caras = caras.size();
  for (i = 0; i < num_tot_caras; i++) {
    glVertex3fv((GLfloat *)&vertices[caras[i]._0]);
    glVertex3fv((GLfloat *)&vertices[caras[i]._1]);
    glVertex3fv((GLfloat *)&vertices[caras[i]._2]);
  }
  glEnd();
}

//*************************************************************************
// dibujar en modo sólido con colores diferentes para cada cara
//*************************************************************************

void _triangulos3D::draw_solido_colores() {
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glBegin(GL_TRIANGLES);

  int num_tot_caras = caras.size();

  for (int i = 0; i < num_tot_caras; i++) {
    glColor3f(colores_caras[i].r, colores_caras[i].g, colores_caras[i].b);

    glVertex3fv((GLfloat *)&vertices[caras[i]._0]);
    glVertex3fv((GLfloat *)&vertices[caras[i]._1]);
    glVertex3fv((GLfloat *)&vertices[caras[i]._2]);
  }
  glEnd();
}

//*************************************************************************
// dibujar en modo sólido con colores diferentes para cada vertices
//*************************************************************************

void _triangulos3D::draw_solido_colores_vertices() {
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glBegin(GL_TRIANGLES);

  int num_tot_caras = caras.size();

  for (int i = 0; i < num_tot_caras; i++) {
    glColor3f(colores_caras[caras[i]._0].r, colores_caras[caras[i]._0].g,
              colores_caras[caras[i]._0].b);

    glVertex3fv((GLfloat *)&vertices[caras[i]._0]);

    glColor3f(colores_caras[caras[i]._1].r, colores_caras[caras[i]._1].g,
              colores_caras[caras[i]._1].b);
    glVertex3fv((GLfloat *)&vertices[caras[i]._1]);

    glColor3f(colores_caras[caras[i]._2].r, colores_caras[caras[i]._2].g,
              colores_caras[caras[i]._2].b);

    glVertex3fv((GLfloat *)&vertices[caras[i]._2]);
  }
  glEnd();
}
//*************************************************************************
// dibujar con distintos modos
//*************************************************************************

void _triangulos3D::draw(_modo modo, float r, float g, float b, float grosor) {
  switch (modo) {
    case POINTS:
      draw_puntos(r, g, b, grosor);
      break;
    case EDGES:
      draw_aristas(r, g, b, grosor);
      break;
    case SOLID:
      draw_solido(r, g, b);
      break;
    case SOLID_COLORS:
      draw_solido_colores();
      break;
    case SOLID_COLORS_VERTS:
      draw_solido_colores_vertices();
      break;
  }
}

//*************************************************************************
// clase cubo
//*************************************************************************

_cubo::_cubo(float tam) {
  // vertices

  float mitad_tam = tam / 2;

  vertices.resize(8);

  vertices[0].x = -mitad_tam;
  vertices[0].y = -mitad_tam;
  vertices[0].z = -mitad_tam;
  vertices[1].x = mitad_tam;
  vertices[1].y = -mitad_tam;
  vertices[1].z = -mitad_tam;
  vertices[2].x = mitad_tam;
  vertices[2].y = -mitad_tam;
  vertices[2].z = mitad_tam;
  vertices[3].x = -mitad_tam;
  vertices[3].y = -mitad_tam;
  vertices[3].z = mitad_tam;
  vertices[4].x = -mitad_tam;
  vertices[4].y = mitad_tam;
  vertices[4].z = -mitad_tam;
  vertices[5].x = mitad_tam;
  vertices[5].y = mitad_tam;
  vertices[5].z = -mitad_tam;
  vertices[6].x = mitad_tam;
  vertices[6].y = mitad_tam;
  vertices[6].z = mitad_tam;
  vertices[7].x = -mitad_tam;
  vertices[7].y = mitad_tam;
  vertices[7].z = mitad_tam;
  // triangulos

  caras.resize(12);
  caras[0]._0 = 3;
  caras[0]._1 = 0;
  caras[0]._2 = 7;
  caras[1]._0 = 0;
  caras[1]._1 = 4;
  caras[1]._2 = 7;
  caras[2]._0 = 0;
  caras[2]._1 = 1;
  caras[2]._2 = 5;
  caras[3]._0 = 0;
  caras[3]._1 = 5;
  caras[3]._2 = 4;
  caras[4]._0 = 1;
  caras[4]._1 = 2;
  caras[4]._2 = 5;
  caras[5]._0 = 2;
  caras[5]._1 = 5;
  caras[5]._2 = 6;
  caras[6]._0 = 2;
  caras[6]._1 = 3;
  caras[6]._2 = 7;
  caras[7]._0 = 2;
  caras[7]._1 = 7;
  caras[7]._2 = 6;
  caras[8]._0 = 0;
  caras[8]._1 = 1;
  caras[8]._2 = 2;
  caras[9]._0 = 0;
  caras[9]._1 = 2;
  caras[9]._2 = 3;
  caras[10]._0 = 4;
  caras[10]._1 = 5;
  caras[10]._2 = 7;
  caras[11]._0 = 5;
  caras[11]._1 = 6;
  caras[11]._2 = 7;

  // colores caras

  colores_caras.resize(12);
  int num_tot_caras = caras.size();

  for (int i = 0; i < num_tot_caras; i++) {
    colores_caras[i].r = rand() % 1000 / 1000.0;
    colores_caras[i].g = rand() % 1000 / 1000.0;
    colores_caras[i].b = rand() % 1000 / 1000.0;
  }
}

//*************************************************************************
// clase piramide
//*************************************************************************

_piramide::_piramide(float tam, float al) {
  // vertices
  vertices.resize(5);
  vertices[0].x = -tam;
  vertices[0].y = 0;
  vertices[0].z = tam;
  vertices[1].x = tam;
  vertices[1].y = 0;
  vertices[1].z = tam;
  vertices[2].x = tam;
  vertices[2].y = 0;
  vertices[2].z = -tam;
  vertices[3].x = -tam;
  vertices[3].y = 0;
  vertices[3].z = -tam;
  vertices[4].x = 0;
  vertices[4].y = al;
  vertices[4].z = 0;

  caras.resize(6);
  caras[0]._0 = 0;
  caras[0]._1 = 1;
  caras[0]._2 = 4;
  caras[1]._0 = 1;
  caras[1]._1 = 2;
  caras[1]._2 = 4;
  caras[2]._0 = 2;
  caras[2]._1 = 3;
  caras[2]._2 = 4;
  caras[3]._0 = 3;
  caras[3]._1 = 0;
  caras[3]._2 = 4;
  caras[4]._0 = 3;
  caras[4]._1 = 1;
  caras[4]._2 = 0;
  caras[5]._0 = 3;
  caras[5]._1 = 2;
  caras[5]._2 = 1;

  colores_caras.resize(6);
  for (int i = 0; i < 6; i++) {
    colores_caras[i]._0 = rand() % 1000 / 1000.0;
    colores_caras[i]._1 = rand() % 1000 / 1000.0;
    colores_caras[i]._2 = rand() % 1000 / 1000.0;
  }
}

//*************************************************************************
// clase objeto ply
//*************************************************************************

_objeto_ply::_objeto_ply() {
  // leer lista de coordenadas de vértices y lista de indices de vértices
}

void _objeto_ply::parametros(char *archivo) {
  int n_ver, n_car;

  vector<float> ver_ply;  // xyz se guardan de forma conecutiva
  vector<int> car_ply;

  _file_ply::read(archivo, ver_ply, car_ply);

  n_ver = ver_ply.size() / 3;
  n_car = car_ply.size() / 3;

  printf("Number of vertices=%d\nNumber of faces=%d\n", n_ver, n_car);

  vertices.resize(n_ver);
  caras.resize(n_car);

  // vertices

  for (int i = 0; i < n_ver; i++) {
    vertices[i].x = ver_ply[3 * i];
    vertices[i].y = ver_ply[3 * i + 1];
    vertices[i].z = ver_ply[3 * i + 2];
  }

  // caras

  for (int i = 0; i < n_car; i++) {
    caras[i].x = car_ply[3 * i];
    caras[i].y = car_ply[3 * i + 1];
    caras[i].z = car_ply[3 * i + 2];
  }

  // colores

  colores_caras.resize(n_car);

  // colores_caras.colors1();
  for (int i = 0; i < n_car; i++) {
    colores_caras[i]._0 = rand() % 1000 / 1000.0;
    colores_caras[i]._1 = rand() % 1000 / 1000.0;
    colores_caras[i]._2 = rand() % 1000 / 1000.0;
  }

  // forma 2
  for (int i = 0; i < n_car; i++) {
    if (vertices[caras[i]._0].y > 0) {
      colores_caras[i]._0 = rand() % 1000 / 1000.0;
      colores_caras[i]._1 = 0.0;
    } else {
      colores_caras[i]._0 = 0.0;
      colores_caras[i]._1 = rand() % 1000 / 1000.0;
    }

    if (vertices[caras[i]._1].x < 0)
      colores_caras[i]._2 = rand() % 1000 / 1000.0;
    else
      colores_caras[i]._2 = 50.0;
  }
}

//************************************************************************
// objeto por revolucion
//************************************************************************

_rotacion::_rotacion() {}

void _rotacion::parametros(vector<_vertex3f> perfil, int num, int tipo,
                           int tapa_in, int tapa_su) {
  int i, j;
  _vertex3f vertice_aux;
  _vertex3i cara_aux;
  int num_aux;
  float radio;

  // tratamiento de los vértice

  if (tipo == 2)
    radio = sqrt(perfil[0].x * perfil[0].x + perfil[0].y * perfil[0].y);
  num_aux = perfil.size();

  int num_tapas = 0;
  if (tipo == 1) num_aux = 1;

  if (tapa_in == 1) num_tapas++;
  if (tapa_su == 1) num_tapas++;
  vertices.resize(num_aux * num + num_tapas);  // +2 pq hemos añadido tapas
  for (j = 0; j < num; j++) {
    for (i = 0; i < num_aux; i++) {
      vertice_aux.x =
          perfil[i].x * cos(2.0 * M_PI * j / (1.0 * num)) +
          perfil[i].z * sin(2.0 * M_PI * j / (1.0 * num));  // 360º en radianes
      vertice_aux.z = -perfil[i].x * sin(2.0 * M_PI * j / (1.0 * num)) +
                      perfil[i].z * cos(2.0 * M_PI * j / (1.0 * num));
      vertice_aux.y = perfil[i].y;
      vertices[i + j * num_aux] = vertice_aux;
    }
  }

  cout << "caras" << endl;

  // tratamiento de las caras

  int n_caras =
      (2 * (num_aux - 1) * num + num_tapas * num);  // 2 num pq estan las tapas
  caras.resize(n_caras);
  int c = 0;

  for (int j = 0; j < num; j++) {
    for (int i = 0; i < num_aux - 1; i++) {
      caras[c]._0 = 0 + i + j * num_aux;
      caras[c]._1 = ((j + 1) % num) * num_aux + i;
      caras[c]._2 = 1 + i + j * num_aux;  // el 1 es para enganchar el triangulo

      c++;

      caras[c]._0 = ((j + 1) % num) * num_aux + i;
      caras[c]._1 = ((j + 1) % num) * num_aux + 1 + i;
      caras[c]._2 = 1 + i + j * num_aux;
      c++;
    }
  }
  cout << "tapainterior" << endl;

  // tapa inferior

  int total = num_aux * num;

  if (tapa_in == 1) {
    cout << "dentro" << endl;

    vertices[total].x = 0.0;

    if (tipo == 2)
      vertices[total].y = -radio;
    else
      vertices[total].y = perfil[0].y;

    vertices[total].z = 0.0;

    for (int j = 0; j < num; j++) {
      caras[c]._0 = j * num_aux;
      caras[c]._1 = ((j + 1) % num) * num_aux;
      caras[c]._2 = total;  // el 1 es para enganchar el triangulo

      c++;
    }
  }

  cout << "tapaSuperior" << endl;

  // tapa superior
  if (tapa_su == 1) {
    vertices[total + 1].x = 0.0;
    if (tipo == 1)
      vertices[total + 1].y = perfil[1].y;
    else if (tipo == 0)
      vertices[total + 1].y = perfil[num_aux - 1].y;
    else
      vertices[total + 1].y = radio;
    vertices[total + 1].z = 0.0;

    for (int j = 0; j < num; j++) {
      caras[c]._0 = total + 1;
      caras[c]._1 = ((j + 1) % num) * num_aux + num_aux - 1;
      caras[c]._2 =
          num_aux - 1 + j * num_aux;  // el 1 es para enganchar el triangulo

      c++;
    }
  }

  // colores de las caras
  colores_caras.resize(2 * (num_aux - 1) * num + 2 * num);
  srand(30);
  for (int i = 0; i < 2 * (num_aux - 1) * num + 2 * num; i++) {
    colores_caras[i]._0 = rand() % 1000 / 1000.0;
    colores_caras[i]._1 = rand() % 1000 / 1000.0;
    colores_caras[i]._2 = rand() % 1000 / 1000.0;
  }
}

//************************************************************************
//  Rotación PLY
//************************************************************************

_rotacion_PLY::_rotacion_PLY() {}

void _rotacion_PLY::parametros_PLY(char *archivo, int num) {
  int n_ver;
  vector<float> ver_ply;
  vector<int> car_ply;
  vector<_vertex3f> perfil;

  _vertex3f aux;

  _file_ply::read(archivo, ver_ply, car_ply);

  n_ver = ver_ply.size() / 3;

  printf("Number of vertices=%d", n_ver);

  vertices.resize(n_ver);

  // vertices

  for (int i = 0; i < n_ver; i++) {
    aux.x = ver_ply[3 * i];
    aux.y = ver_ply[3 * i + 1];
    aux.z = ver_ply[3 * i + 2];
    perfil.push_back(aux);
  }

  parametros(perfil, num, 0, 1, 0);
}
//************************************************************************
// objeto por extrusión
//************************************************************************

_extrusion::_extrusion(vector<_vertex3f> poligono, float x, float y, float z) {
  int i;
  _vertex3f vertice_aux;
  _vertex3i cara_aux;
  int num_aux;

  // tratamiento de los vértice

  num_aux = poligono.size();
  vertices.resize(num_aux * 2);
  for (i = 0; i < num_aux; i++) {
    vertices[2 * i] = poligono[i];
    vertices[2 * i + 1].x = poligono[i].x + x;
    vertices[2 * i + 1].y = poligono[i].y + y;
    vertices[2 * i + 1].z = poligono[i].z + z;
  }

  // tratamiento de las caras

  caras.resize(num_aux * 2);
  int c = 0;
  for (i = 0; i < num_aux; i++) {
    caras[c]._0 = i * 2;
    caras[c]._1 = (i * 2 + 2) % (num_aux * 2);
    caras[c]._2 = i * 2 + 1;
    c = c + 1;
    caras[c]._0 = (i * 2 + 2) % (num_aux * 2);
    caras[c]._1 = (i * 2 + 2) % (num_aux * 2) + 1;
    caras[c]._2 = i * 2 + 1;
    c = c + 1;
  }

  // colores de las caras
  colores_caras.resize(num_aux * 2);
  srand(30);
  for (int i = 0; i < num_aux * 2; i++) {
    colores_caras[i]._0 = rand() % 1000 / 1000.0;
    colores_caras[i]._1 = rand() % 1000 / 1000.0;
    colores_caras[i]._2 = rand() % 1000 / 1000.0;
  }
}

_cilindro::_cilindro(float radio, float altura, int num) {
  vector<_vertex3f> perfil;
  _vertex3f vert_aux;

  vert_aux.x = radio;
  vert_aux.y = -altura / 2.0;
  vert_aux.z = 0.0;
  perfil.push_back(vert_aux);

  vert_aux.x = radio;
  vert_aux.y = altura / 2.0;
  vert_aux.z = 0.0;
  perfil.push_back(vert_aux);

  parametros(perfil, num, 0, 1, 1);
}

_cono::_cono(float radio, float altura, int num) {
  vector<_vertex3f> perfil;
  _vertex3f vert_aux;

  vert_aux.x = radio;
  vert_aux.y = 0.0;
  vert_aux.z = 0.0;
  perfil.push_back(vert_aux);

  vert_aux.x = 0;
  vert_aux.y = altura;
  vert_aux.z = 0.0;
  perfil.push_back(vert_aux);

  parametros(perfil, num, 1, 1, 1);
}

_esfera::_esfera(float radio, int num1, int num2) {
  vector<_vertex3f> perfil;
  _vertex3f vert_aux;

  for (int i = 1; i < num1; i++) {
    vert_aux.x = radio * cos(M_PI * i / num1 -
                             M_PI / 2.0);  // - pq empezamos a girar desde
    vert_aux.y = radio * sin(M_PI * i / num1 - M_PI / 2.0);
    vert_aux.z = 0.0;
    perfil.push_back(vert_aux);
  }

  parametros(perfil, num2, 2, 1, 1);
}
