#include <iostream>
#include <GL/glut.h>								// Indicar utilizaci�n de librer�a GLUT

double  xRang = 6.0, yRang = 6.0, zRang = 6.0;		// Unidades visibles para cada eje
double rotate_x = -54.75;
double rotate_z = -135;
double rotate_y = 0;
//GLuint textures[7];

int cubo[55] = {
	0,2,0,2,0,2,0,2,0,
	1,3,1,3,1,3,1,3,1,
	2,0,2,0,2,0,2,0,2,
	3,1,3,1,3,1,3,1,3,
	4,5,4,5,4,5,4,5,4,
	5,4,5,4,5,4,5,4,5,
	6
};

/*
int cubo[55] = {
	1,1,1,0,0,1,0,0,1,
	2,4,4,2,1,4,2,2,2,
	2,2,3,2,2,3,3,3,3,
	0,0,0,0,5,5,0,5,5,
	4,4,4,4,3,3,4,3,3,
	5,5,5,5,1,1,5,1,1,
	6
};*/
/*
int cubo[55] = {
	0,0,0,0,0,0,0,0,0,
	1,1,1,1,1,1,1,1,1,
	2,2,2,2,2,2,2,2,2,
	3,3,3,3,3,3,3,3,3,
	4,4,4,4,4,4,4,4,4,
	5,5,5,5,5,5,5,5,5,
	6
};*/

int vertices[56][3] = {
	{-3, -3,  3},		// 0 
	{-1, -3,  3},		// 1	
	{ 1, -3,  3},		// 2
	{ 3, -3,  3},       // 3
	{ 3, -1,  3},       // 4
	{ 3,  1,  3},       // 5
	{ 3,  3,  3},       // 6
	{ 1,  3,  3},       // 7
	{-1,  3,  3},       // 8
	{-3,  3,  3},       // 9
	{-3,  1,  3},       // 10
	{-3, -1,  3},       // 11

	{-3, -3,  1},		// 12 
	{-1, -3,  1},		// 13	
	{ 1, -3,  1},		// 14
	{ 3, -3,  1},       // 15
	{ 3, -1,  1},       // 16
	{ 3,  1,  1},       // 17
	{ 3,  3,  1},       // 18
	{ 1,  3,  1},       // 19
	{-1,  3,  1},       // 20
	{-3,  3,  1},       // 21
	{-3,  1,  1},       // 22
	{-3, -1,  1},       // 23

	{-3, -3, -1},		// 24 
	{-1, -3, -1},		// 25	
	{ 1, -3, -1},		// 26
	{ 3, -3, -1},       // 27
	{ 3, -1, -1},       // 28
	{ 3,  1, -1},       // 29
	{ 3,  3, -1},       // 30
	{ 1,  3, -1},       // 31
	{-1,  3, -1},       // 32
	{-3,  3, -1},       // 33
	{-3,  1, -1},       // 34
	{-3, -1, -1},       // 35

	{-3, -3, -3},		// 36
	{-1, -3, -3},		// 37	
	{ 1, -3, -3},		// 38
	{ 3, -3, -3},       // 39
	{ 3, -1, -3},       // 40
	{ 3,  1, -3},       // 41
	{ 3,  3, -3},       // 42
	{ 1,  3, -3},       // 43
	{-1,  3, -3},       // 44
	{-3,  3, -3},       // 45
	{-3,  1, -3},       // 46
	{-3, -1, -3},       // 47

	{-1, -1, 3},       // 48
	{-1,  1, 3},       // 49
	{ 1, -1, 3},       // 50
	{ 1,  1, 3},       // 51

	{ 1, -1, -3},       // 52
	{ 1,  1, -3},       // 53
	{-1, -1, -3},       // 54
	{-1,  1, -3}        // 55
};

double colores[7][3] = {
	{1.0, 0.5, 0.0}, // 0 Naranja
	{1.0, 1.0 ,1.0}, // 1 Blanco
	{1.0, 0.0, 0.0}, // 2 Rojo
	{1.0, 1.0, 0.0}, // 3 Amarillo
	{0.0, 0.0, 1.0}, // 4 Azul
	{0.0, 1.0, 0.0}, // 5 Verde
	{0.0, 0.0, 0.0}  // 6 Negro 
};

void init() {
	glClearColor(0.0, 0.0, 0.0, 1.0);				// Color negro solido para borradp
	glEnable(GL_DEPTH_TEST);						// Prueba de profundidad
	/*textures[0] = LoadTexture("\\naranja.png");
	textures[1] = LoadTexture("\\blanco.png");
	textures[2] = LoadTexture("\\rojo.png");
	textures[3] = LoadTexture("\\amarillo.png");
	textures[4] = LoadTexture("\\azul.png");
	textures[5] = LoadTexture("\\verde.png");
	textures[6] = LoadTexture("\\plano.png");*/
}

/* En caso de redimensionar la ventana*/
void reshape(int w, int h) {
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);								// Configuracion de proyecci�n ortogonal
	glLoadIdentity();											// Deshacer posibles transfromaciones
	glOrtho(-xRang, xRang, -yRang, yRang, -zRang, zRang);		// Rangos de visualizaci�n

	glMatrixMode(GL_MODELVIEW);									// Iniciar modo de modelado
	glLoadIdentity();											// Deshacer posibles transfromaciones
}
/*
GLuint LoadTexture(const char* filename) {
	GLuint texture;
	int width, height;
	unsigned char* data;
	FILE* file;

	file = fopen(filename, "rb");
	if (filename == NULL)
		return 0;
	width = 256;
	height = 256;
	data = (unsigned char*)malloc(width * height * 3);
	fseek(file, 54, 0);

	fread(data, width * height * 3, 1, file);
	fclose(file);

	for (int i = 0; i < width * height; ++i) {
		int index = i * 3;
		unsigned char B, R;
		B = data[index];
		R = data[index + 2];

		data[index] = R;
		data[index + 2] = B;
	}
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);

	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	free(data);
	return texture;
}*/

void Sticker(int a, int b, int c, int d, int i) {
	/*int color = cubo[n];
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[color]);

	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(vertices[a][0], vertices[a][1], vertices[a][2]);

	glTexCoord2f(0.0, 0.0);
	glVertex3f(vertices[b][0], vertices[b][1], vertices[b][2]);

	glTexCoord2f(1.0, 0.0);
	glVertex3f(vertices[c][0], vertices[c][1], vertices[c][2]);

	glTexCoord2f(1.0,1.0);
	glVertex3f(vertices[d][0], vertices[d][1], vertices[d][2]);
	glEnd();
	glDisable(GL_TEXTURE);
	*/
	glBegin(GL_QUADS);
	glColor3f(colores[cubo[i]][0], colores[cubo[i]][1], colores[cubo[i]][2]);
	glVertex3f(vertices[a][0], vertices[a][1], vertices[a][2]);
	glVertex3f(vertices[b][0], vertices[b][1], vertices[b][2]);
	glVertex3f(vertices[c][0], vertices[c][1], vertices[c][2]);
	glVertex3f(vertices[d][0], vertices[d][1], vertices[d][2]);
	glEnd();
}

void esquina1() {
	Sticker(2, 3, 15, 14, 2);
	Sticker(3, 4, 16, 15, 9);
	Sticker(2, 50, 4, 3, 42);
}
void esquina2() {
	Sticker(5, 6, 18, 17, 11);
	Sticker(6, 7, 19, 18, 18);
	Sticker(51, 7, 6, 5, 44);
}
void esquina3() {
	Sticker(8, 9, 21, 20, 20);
	Sticker(9, 10, 22, 21, 27);
	Sticker(10, 9, 8, 49, 38);
}
void esquina4() {
	Sticker(0, 1, 13, 12, 0);
	Sticker(11, 0, 12, 23, 29);
	Sticker(0, 11, 48, 1, 36);
}
void esquina5() {
	Sticker(26, 27, 39, 38, 8);
	Sticker(27, 28, 40, 39, 15);
	Sticker(39, 40, 52, 38, 45);
}
void esquina6() {
	Sticker(29, 30, 42, 41, 17);
	Sticker(30, 31, 43, 42, 24);
	Sticker(41, 42, 43, 43, 47);
}
void esquina7() {
	Sticker(32, 33, 45, 44, 26);
	Sticker(33, 34, 46, 45, 33);
	Sticker(55, 44, 45, 46, 53);
}
void esquina8() {
	Sticker(24, 25, 37, 36, 6);
	Sticker(35, 24, 36, 47, 35);
	Sticker(37, 54, 47, 36, 51);
}

void arista1() {
	Sticker(1, 2, 14, 13, 1);
	Sticker(1, 48, 50, 2, 39);
}

void arista2() {
	Sticker(4, 5, 17, 16, 10);
	Sticker(50, 51, 5, 4, 43);
}

void arista3() {
	Sticker(7, 8, 20, 19, 19);
	Sticker(49, 8, 7, 51, 41);
}

void arista4() {
	Sticker(10, 11, 23, 22, 28);
	Sticker(11, 18, 49, 48, 37);
}

void arista5() {
	Sticker(14, 15, 27, 26, 5);
	Sticker(15, 16, 28, 27, 12);
}

void arista6() {
	Sticker(17, 18, 30, 29, 14);
	Sticker(18, 19, 31, 30, 21);
}

void arista7() {
	Sticker(20, 21, 33, 32, 23);
	Sticker(21, 22, 34, 33, 30);
}

void arista8() {
	Sticker(12, 13, 25, 24, 3);
	Sticker(23, 12, 24, 35, 32);
}

void arista9() {
	Sticker(25, 26, 38, 37, 7);
	Sticker(38, 52, 54, 37, 48);
}

void arista10() {
	Sticker(28, 29, 41, 40, 16);
	Sticker(40, 41, 53, 52, 46);
}

void arista11() {
	Sticker(31, 32, 44, 43, 25);
	Sticker(53, 43, 44, 55, 50);
}

void arista12() {
	Sticker(34, 35, 47, 46, 34);
	Sticker(54, 55, 46, 47, 52);

}

/* Se invoca cada que se redibuja*/
void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);			// Borrar todo
	glPushMatrix();												// 

	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	

	//Sticker(2, 7, 43, 38, 54);
	

	// esquinas
	esquina1();
	esquina2();
	esquina3();
	esquina4();
	esquina5();
	esquina6();
	esquina7();
	esquina8();

	//aristas
	arista1();
	arista2();
	arista3();
	arista4();
	arista5();
	arista6();
	arista7();
	arista8();
	arista9();
	arista10();
	arista11();
	arista12();

	//centros
	Sticker(13, 14, 26, 25, 4);
	Sticker(16, 17, 29, 28, 13);
	Sticker(19, 20, 32, 31, 22);
	Sticker(22, 23, 35, 34, 31);
	Sticker(48, 49, 51, 50, 40);
	Sticker(52, 53, 55, 54, 49);

	glPopMatrix();
	glFlush();
	glutSwapBuffers();					// Intercamio entre buffers
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);										// Innicializar glut
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);	// Modo de visualizaci�n
	glutInitWindowSize(700, 700);								// Inicializar ventana
	glutInitWindowPosition(0, 0);								//
	glutCreateWindow("Rubik OpenGL");							//

	init();														// Configuracioninicial
	glutReshapeFunc(reshape);									// Funci�n que GLUT utilizar� cuando redimensiona la ventana
	glutDisplayFunc(display);									// Funci�n que GLUT invoca cada que redibuja
	glutMainLoop();												// Todo funciona en un ciclo
}

