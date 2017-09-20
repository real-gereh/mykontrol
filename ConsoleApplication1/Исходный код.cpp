#include <gl\glut.h>
#include<gl\GLAux.h>
#include <math.h>



using namespace std;

unsigned int textures[3];
GLfloat M[] = {
	0, 0, 0,//чтобы нумеровать с1	0
	-0.6, -0.2, 0,//M1		1
	-0.5, -0.2, 0,//M2		2
	-0.45, 0, 0,//M3		3
	-0.55, 0, 0,//M4		4
	-0.5, 0.2, 0,//M5		5
	-0.4, 0.2, 0,//M6		6
	-0.3, 0.2, 0,//M7		7
	-0.2, 0.2, 0,//M8		8
	-0.15, 0, 0,//M9		9
	-0.25, 0, 0,//M10	10
	-0.2, -0.2, 0,//M11	11
	-0.1, -0.2, 0,//M12	12
	-0.35, -0.1, 0,//M13	13
	-0.35, 0.1, 0,//M14	14
	-0.6, -0.2, -0.1,//M1`	15
	-0.5, -0.2, -0.1,//M2`	16
	-0.45, 0, -0.1,//M3`	17
	-0.55, 0, -0.1,//M4`	18
	-0.5, 0.2, -0.1,//M5`	19
	-0.4, 0.2, -0.1,//M6`	20
	-0.3, 0.2, -0.1,//M7`	21
	-0.2, 0.2, -0.1,//M8`	22
	-0.15, 0, -0.1,//M9`	23
	-0.25, 0, -0.1,//M10`	24
	-0.2, -0.2, -0.1,//M11`	25
	-0.1, -0.2, -0.1,//M12`	26
	-0.35, -0.1, -0.1,//M13`	27
	-0.35, 0.1, -0.1//M14`	28

};
GLfloat S[] = {
	0, 0, 0,//чтобы начать с1	0
	-0.05, -0.1, 0,//S1		1
	-0.05, -0.2, 0,//S2		2
	0.1, -0.2, 0,//S3		3
	0.1, -0.15, 0,//S4		4
	0.1, -0.1, 0,//S5		5
	0.2, -0.05, 0,//S6		6
	0.1, 0.1, 0,//S7		7
	0, 0.05, 0,//S8		8
	-0.05, 0.1, 0,//S9		9
	0, 0.175, 0,//S10	10
	0.1, 0.2, 0,//S11	11
	0.1, 0.15, 0,//S12	12
	0.25, 0.1, 0,//S13	13
	0.25, 0.2, 0,//S14	14
	-0.05, -0.1, -0.1,//S1`	15
	-0.05, -0.2, -0.1,//S2`	16
	0.1, -0.2, -0.1,//S3`	17
	0.1, -0.15, -0.1,//S4`	18
	0.1, -0.1, -0.1,//S5`	19
	0.2, -0.05, -0.1,//S6`	20
	0.1, 0.1, -0.1,//S7`	21
	0, 0.05, -0.1,//S8`	22
	-0.05, 0.1, -0.1,//S9`	23
	0, 0.175, -0.1,//S10`	24
	0.1, 0.2, -0.1,//S11`	25
	0.1, 0.15, -0.1,//S12`	26
	0.25, 0.1, -0.1,//S13`	27
	0.25, 0.2, -0.1,//S14`	28
	0.25, -0.1, 0,//S7		29
	0.2, -0.175, 0,//S8		30
	0.25, -0.1, -0.1,//S7`	31
	0.2, -0.175, -0.1//S8`	32
};
GLfloat I[] = {
	0, 0, 0,//для удобства
	0.3, 0.2, 0,//I1		1
	0.3, 0.1, 0,//I2		2
	0.4, 0.1, 0,//I3		3
	0.4, 0.2, 0,//I4		4
	0.3, 0.05, 0,//I5		5
	0.3, -0.2, 0,//I6		6
	0.35, -0.2, 0,//I7		7
	0.35, 0.05, 0,//I8		8
	0.4, 0.05, 0,//I9		9
	0.4, -0.2, 0,//I10		10
	0.3, 0.2, -0.1,//I1`		11
	0.3, 0.1, -0.1,//I2`		12
	0.4, 0.1, -0.1,//I3`		13
	0.4, 0.2, -0.1,//I4`		14
	0.3, 0.05, -0.1,//I5`		15
	0.3, -0.2, -0.1,//I6`		16
	0.35, -0.2, -0.1,//I7`		17
	0.35, 0.05, -0.1,//I8`		18
	0.4, 0.05, -0.1,//I9`		19
	0.4, -0.2, -0.1//I10`	20
};
GLfloat SCENA[] = {
	0, 0, 0,//для удобства
	-4,-0.2,4,//		1
	4, -0.2, 4,//		2
	4, 4, 4,//		3
	-4, 4, 4,//		4
	-4, -0.2, -4,//	5
	4, -0.2, -4,//		6
	4, 4, -4,//		7
	-4, 4, -4//		8
};



void drawCircle(float x, float y, float r, int amountSegments)
{
	glBegin(GL_POLYGON);
	for (int i = 0; i < amountSegments; i++)
	{
		glColor3f(1, 1, 1);
		float angle = 2.0 * 3.1415926 * float(i) / float(amountSegments);
		float dx = r * cosf(angle);
		float dy = r * sinf(angle);
		glVertex3f(x + dx, -0.195,y + dy );

	}
	glEnd();

}
float cxx = 0, cyy = 0, czz =3, xx = 0, yy = 0, zz = 1, d = 0, r = 3, zoom = -10; // выбранные оси 
int os_x = 0, os_y = 0, os_z = 0, time = 0, shag = 30, stat = 0;
float width = 1000, height = 1000, m1 = -1, m2 = -1, m3 = -1, m4 = -1, m5 = -1, m6 = -1, s1 = -1, s2 = -1, s3 = -1, s4 = -1, s5 = -1, i1 = -1, i2 = -1, i3 = -1, rotk = 1, ihand = 0;
bool camera = true, xcor = true, rot = false, hand=true;
void LoadTextures()
{
	AUX_RGBImageRec *texture1 = auxDIBImageLoadA("texture.bmp"), *texture2 = auxDIBImageLoadA("scenback.bmp"), *texture3 = auxDIBImageLoadA("texture1.bmp");
	glGenTextures(3, &textures[0]);
	glBindTexture(GL_TEXTURE_2D, textures[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, texture1->sizeX, texture1->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, texture1->data);
	
	glBindTexture(GL_TEXTURE_2D, textures[1]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, texture2->sizeX, texture2->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, texture2->data);

	glBindTexture(GL_TEXTURE_2D, textures[2]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, texture3->sizeX, texture3->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, texture3->data);
}
void square(int a, int b, int c, int d)
{
	glBindTexture(GL_TEXTURE_2D, textures[0]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glArrayElement(a);
	glTexCoord2f(1, 0);
	glArrayElement(b);
	glTexCoord2f(0, 1);
	glArrayElement(c);
	glTexCoord2f(1,0);
	glArrayElement(d);
	glEnd();
}
void headsquare(int a, int b, int c, int d)
{
	glBindTexture(GL_TEXTURE_2D, textures[2]);
	glBegin(GL_POLYGON);
	

	glTexCoord2f(0, 0);
	glArrayElement(a);
	glTexCoord2f(0, 1);
	glArrayElement(d);
	glTexCoord2f(1, 1);
	glArrayElement(c);
	glTexCoord2f(1, 0);
	glArrayElement(b);
	glEnd();
}
void sqscen(int a, int b, int c, int d)
{
	glBindTexture(GL_TEXTURE_2D, textures[1]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 1);
	glArrayElement(a);
	glTexCoord2f(0, 0);
	glArrayElement(b);
	glTexCoord2f(1, 0);
	glArrayElement(c);
	glTexCoord2f(1, 1);
	glArrayElement(d);
	glEnd();
}
void pentagon(int a, int b, int c, int d, int e)
{
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glArrayElement(a);
	glTexCoord2f(1, 0);
	glArrayElement(b);
	glTexCoord2f(0.5, 0.5);
	glArrayElement(c);
	glTexCoord2f(0, 1);
	glArrayElement(d);
	glTexCoord2f(1, 0);
	glArrayElement(e);
	glEnd();
}
void cube(int a, int b, int c, int d, int a1, int b1, int c1, int d1)
{
	square(d1, c1, b1, a1);
	square(d, c, c1, d1);
	square(a, b, c, d);
	square(a1, b1, b, a);
	square(a1, a, d, d1);
	square(b, b1, c1, c);

};
void headcube(int a, int b, int c, int d, int a1, int b1, int c1, int d1)
{
	square(d1, c1, b1, a1);
	square(d, c, c1, d1);
	headsquare(a, b, c, d);
	square(a1, b1, b, a);
	square(a1, a, d, d1);
	square(b, b1, c1, c);

};
void pentacube(int a, int b, int c, int d, int e, int a1, int b1, int c1, int d1, int e1)
{
	square(a1, a, e, e1);
	square(e1, e, d, d1);
	square(d, c, c1, d1);
	square(b, b1, c1, c);
	pentagon(a, b, c, d, e);
	square(a1, b1, b, a);
	pentagon(a1, e1, d1, c1, b1);

};
void Draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	gluLookAt(cxx, cyy, czz, 0, 0, 0, 0.0, 1.0, 0.0);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, M);

	glPushMatrix();
	if (m1 >= 0 && m1<=10)
	{
		glTranslatef(-0.04*m1, 0, 0);
		m1++;
	}
	else
	{
		if (m1 <= 320 && m1 > 10)
		{
			glLoadIdentity();
			glTranslatef(0, 0, -3);
			glRotated(rotk*m1, 0, 1, 0);
			glTranslatef(-0.4, 0, 0);
		}
		else
		{
			if (m1 >320 && m1 <= 330)
			{
				m1 = m1 - 320;
				glTranslatef(-0.4, 0, 0);
				glTranslatef(0.08388*m1, 0.021*m1, 0);
				m1 = 320 + m1;
			}
			else
			{
				if (m1 > 330)
				{
					glTranslatef(0.2925, 0.16, 0);
					glRotated(-15, 0, 0, 1);
					cube(1, 2, 3, 4, 15, 16, 17, 18);
				}
				else
				{
					cube(1, 2, 3, 4, 15, 16, 17, 18);
				}
			}
		}
	}
	if (m1 >= 0 && m1 <= 330)
	{
		m1++;
		cube(1, 2, 3, 4, 15, 16, 17, 18);
	}
	
	glPopMatrix();

	glPushMatrix();
	if (m2 >= 0 && m2 <= 10)// нижняя часть руки------------------------------------------------------------------------------------------------------------------------
	{
		glTranslatef(-0.04*m2, 0, 0.02*m2);
		m2++;
	}
	else
	{
		if (m2 <= 300 && m2 > 10)
		{
			glLoadIdentity();
			glTranslatef(0, 0, -3);
			glRotated(rotk*m2, 0, 1, 0);
			glTranslatef(-0.4, 0, 0.2);
		}
		else
		{
			if (m2 >300 && m2 <= 320)
			{
				m2 = m2 - 300;
				glTranslatef(-0.4, 0, 0.2);
				glTranslatef(0.05025*m2, 0.01125*m2, -0.01*m2);
				m2 = 300 + m2;
			}
			else
			{
				if (m2 > 320)
				{
					glTranslatef(0.675, 0.41, 0);
					glRotated(15, 0, 0, 1);
					cube(4, 3, 6, 5, 18, 17, 20, 19);
				}
				else
				{
					cube(4, 3, 6, 5, 18, 17, 20, 19);
				}
			}
		}
	}
	if (m2 >= 0 && m2 <= 340)
	{
		m2++;
		cube(4, 3, 6, 5, 18, 17, 20, 19);
	}
	cube(4, 3, 6, 5, 18, 17, 20, 19);
	glPopMatrix();
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------	
	glPushMatrix();
	if (m3 >= 0 && m3 <= 10)
	{
		glTranslatef(-0.035*m3, 0.02*m3, 0.03*m3);
		m3++;
	}
	else
	{
		if (m3 <= 160 && m3 > 10)
		{
			glLoadIdentity();
			glTranslatef(0, 0, -3);
			glRotated(rotk*m3, 0, 1, 0);
			glTranslatef(-0.35, 0.2, 0.3);
		}
		else
		{
			if (m3 >160 && m3 <= 170)
			{
				m3 = m3 - 160;
				glTranslatef(-0.35, 0.2, 0.3);
				glTranslatef(0.085*m3, -0.02*m3, -0.03*m3);
				m3 = 160 + m3;
			}
			else
			{
				if (m3 > 170)
				{
					glTranslatef(0.485, 0.14, 0);
					glRotated(15.5, 0, 0, 1);
					cube(3, 13, 14, 6, 17, 27, 28, 20);
				}
				else
				{
					cube(3, 13, 14, 6, 17, 27, 28, 20);
				}
				
			}
		}
	}
	if (m3 >= 0 && m3 <= 170)
	{
		m3++;
		cube(3, 13, 14, 6, 17, 27, 28, 20);
	}
	glPopMatrix();

	glPushMatrix();
	if (m4 >= 0 && m4 <= 10)
	{
		glTranslatef(0.005*m4, 0.02*m4, 0.06*m4);
		m4++;
	}
	else
	{
		if (m4 <= 180 && m4 > 10)
		{
			glLoadIdentity();
			glTranslatef(0, 0, -3);
			glRotated(rotk*m4, 0, 1, 0);
			glTranslatef(0.05, 0.2, 0.6);
		}
		else
		{
			if (m4 > 180 && m4 <= 190)
			{
				m4 = m4 - 180;
				glTranslatef(0.05, 0.2, 0.6);
				glTranslatef(0.015*m4, -0.02*m4, -0.06*m4);
				m4 = 180 + m4;
			}
			else
			{
				if (m4 > 190)
				{
					glTranslatef(0.2, -0.05, 0);
					glRotated(-15.5, 0, 0, 1);
					cube(13, 10, 7, 14, 27, 24, 21, 28);
				}
				else
				{
					cube(13, 10, 7, 14, 27, 24, 21, 28);
				}
			}
		}
	}
	if (m4 >= 0 && m4 <= 190)
	{
		m4++;
		cube(13, 10, 7, 14, 27, 24, 21, 28);
	}
	glPopMatrix();

	glPushMatrix();
	if (m5 >= 0 && m5 <= 10)
	{
		glTranslatef(0, 0.04*m5, -0.07*m5);
		m5++;
	}
	else
	{
		if (m5 <= 300 && m5 > 10)
		{
			glLoadIdentity();
			glTranslatef(0, 0, -3);
			glRotated(rotk*m5, 0, 1, 0);
			glTranslatef(0, 0.4, -0.7);
		}
		else
		{
			if (m5 >300 && m5 <= 310)
			{
				m5 = m5 - 300;
				glTranslatef(0, 0.4, -0.7);
				glTranslatef(0.005*m5, -0.0175*m5, 0.07*m5);
				m5 = 300 + m5;
			}
			else
			{
				if (m5 > 310)
				{
					glTranslatef(0, 0.23, 0);
					glRotated(-15, 0, 0, 1);
					cube(10, 9, 8, 7, 24, 23, 22, 21);
				}
				else
				{
					cube(10, 9, 8, 7, 24, 23, 22, 21);
				}
			}
		}
	}
	if (m5 >= 0 && m5 <= 310)
	{
		m5++;
		cube(10, 9, 8, 7, 24, 23, 22, 21);
	}
	glPopMatrix();

	glPushMatrix();	//нижняя часть руки--------------------------------------------------------------------------------------------------------------------------------------
	if (m6 >= 0 && m6 <= 10)
	{
		glTranslatef(0, 0.01*m6, -0.06*m6);
		m6++;
	}
	else
	{
		if (m6 <= 320 && m6 > 10)
		{
			glLoadIdentity();
			glTranslatef(0, 0, -3);
			glRotated(rotk*m6, 0, 1, 0);
			glTranslatef(0, 0.1, -0.6);
		}
		else
		{
			if (m6 >320 && m6 <= 340)
			{
				m6 = m6 - 320;
				glTranslatef(0, 0.1, -0.6);
				glTranslatef(0.0206*m6, 0.0105*m6, 0.03*m6);
				m6 = 320 + m6;
			}
			else
			{
				if (m6 > 340)
				{
					glTranslatef(0.385, 0.335, 0);
					glRotated(15, 0, 0, 1);
					cube(11, 12, 9, 10, 25, 26, 23, 24);
				}
				else
				{
					cube(11, 12, 9, 10, 25, 26, 23, 24);
				}
			}
		}
	}
	if (m6 >= 0 && m6 <= 340)
	{
		m6++;
		cube(11, 12, 9, 10, 25, 26, 23, 24);
	}
	glPopMatrix();
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	glVertexPointer(3, GL_FLOAT, 0, S);

	glPushMatrix();
	if (s1 >= 0 && s1 <= 10)
	{
		glTranslatef(0.03*s1, 0.03*s1, 0.05*s1);
		s1++;
	}
	else
	{
		if (s1 <= 280 && s1 > 10)
		{
			glLoadIdentity();
			glTranslatef(0, 0, -3);
			glRotated(rotk*s1, 0, 1, 0);
			glTranslatef(0.3, 0.3, 0.5);
		}
		else
		{
			if (s1 > 280 && s1 <= 290)
			{
				s1 = s1 - 280;
				glTranslatef(0.3, 0.3, 0.5);
				glTranslatef(-0.04*s1, 0.0325*s1, -0.05*s1);
				s1 = 280 + s1;
			}
			else
			{
				if (s1 > 290)
				{
					glRotated(180, 1, 0, 0);
					glTranslatef(-0.1, -0.275, 0.1);
					cube(2, 3, 4, 1, 16, 17, 18, 15);
				}
				else
				{
					cube(2, 3, 4, 1, 16, 17, 18, 15);
				}
			}
		}
	}
	if (s1 >= 0 && s1 <= 290)
	{
		s1++;
		cube(2, 3, 4, 1, 16, 17, 18, 15);
	}
	glPopMatrix();


	glPushMatrix();
	if (s2 >= 0 && s2 <= 10)
	{
		glTranslatef(-0.07*s2, 0.03*s2, -0.045*s2);
		s2++;
	}
	else
	{
		if (s2 <= 220 && s2 > 10)
		{
			glLoadIdentity();
			glTranslatef(0, 0, -3);
			glRotated(rotk*s2, 0, 1, 0);
			glTranslatef(-0.7, 0.3, -0.45);
		}
		else
		{
			if (s2 > 220 && s2 <= 230)
			{
				s2 = s2 - 220;
				glTranslatef(-0.7, 0.3, -0.45);
				glTranslatef(0.06*s2, 0, 0.055*s2);
				s2 = 220 + s2;
			}
			else
			{
				if (s2 > 230)
				{
					glTranslatef(-0.1, 0.1, -0.1);
					glRotated(180, 1, 0, 0);
					pentacube(3, 30, 29, 6, 5, 17, 32, 31, 20, 19);
				}
				else
				{
					pentacube(3, 30, 29, 6, 5, 17, 32, 31, 20, 19);
				}
			}
		}
	}
	if (s2 >= 0 && s2 <= 230)
	{
		s2++;
		pentacube(3, 30, 29, 6, 5, 17, 32, 31, 20, 19);
	}
	glPopMatrix();
	

	glPushMatrix();
	if (s3 >= 0 && s3 <= 10)
	{
		glTranslatef(0.04*s3, 0.05*s3, 0);
		s3++;
	}
	else
	{
		if (s3 <= 240 && s3 > 10)
		{
			glLoadIdentity();
			glTranslatef(0, 0, -3);
			glRotated(rotk*s3, 0, 1, 0);
			glTranslatef(0.4, 0.5, 0);
		}
		else
		{
			if (s3 > 240 && s3 <= 250)
			{
				s3 = s3 - 240;
				glTranslatef(0.4, 0.5, 0);
				glTranslatef(-0.0544*s3, -0.0125*s3, 0);
				s3 = 240 + s3;
			}
			else
			{
				if (s3 > 250)
				{
					glTranslatef(-0.075, 0.40, 0);
					glRotated(-33, 0, 0, 1);
					cube(5, 6, 7, 8, 19, 20, 21, 22);
				}
				else
				{
					cube(5, 6, 7, 8, 19, 20, 21, 22);
				}
			}
		}
	}
	if (s3 >= 0 && s3 <= 250)
	{
		s3++;
		cube(5, 6, 7, 8, 19, 20, 21, 22);
	}
	glPopMatrix();
	

	glPushMatrix();
	if (s4 >= 0 && s4 <= 10)
	{
		glTranslatef(0.04*s4, 0.03*s4, -0.03*s4);
		s4++;
	}
	else
	{
		if (s4 <= 200 && s4 > 10)
		{
			glLoadIdentity();
			glTranslatef(0, 0, -3);
			glRotated(rotk*s4, 0, 1, 0);
			glTranslatef(0.4, 0.3, -0.3);
		}
		else
		{
			if (s4 > 200 && s4 <= 210)
			{
				s4 = s4 - 200;
				glTranslatef(0.4, 0.3, -0.3);
				glTranslatef(-0.05*s4, -0.02*s4, 0.03*s4);
				s4 = 200 + s4;
			}
			else
			{
				if (s4 > 210)
				{
					glTranslatef(-0.1, 0.1, 0);
					pentacube(8, 7, 11, 10, 9, 22, 21, 25, 24, 23);
				}
				else
				{
					pentacube(8, 7, 11, 10, 9, 22, 21, 25, 24, 23);
				}
			}
		}
	}
	if (s4 >= 0 && s4 <=210)
	{
		s4++;
		pentacube(8, 7, 11, 10, 9, 22, 21, 25, 24, 23);
	}
	glPopMatrix();
	
	glPushMatrix();
	if (s5 >= 0 && s5 <= 10)
	{
		glTranslatef(0.03*s5, -0.01*s5, -0.04*s5);
		s5++;
	}
	else
	{
		if (s5 <= 260 && s5 > 10)
		{
			glLoadIdentity();
			glTranslatef(0, 0, -3);
			glRotated(rotk*s5, 0, 1, 0);
			glTranslatef(0.3, -0.1, -0.4);
		}
		else
		{
			if (s5 > 260 && s5 <= 270)
			{
				s5 = s5 - 260;
				glTranslatef(0.3, -0.1, -0.4);
				glTranslatef(-0.04*s5, 0.0375*s5, 0.04*s5);
				s5 = 260 + s5;
			}
			else
			{
				if (s5 > 270)
				{
					glTranslatef(-0.1, 0.275, 0);
					cube(12, 13, 14, 11, 26, 27, 28, 25);
				}
				else
				{
					cube(12, 13, 14, 11, 26, 27, 28, 25);
				}
			}
		}
	}
	if (s5 >= 0 && s5 <= 270)
	{
		s5++;
		cube(12, 13, 14, 11, 26, 27, 28, 25);
	}
	glPopMatrix();
	
	glEnd();

	glVertexPointer(3, GL_FLOAT, 0, I);
	
	glPushMatrix();
	if (i1 >= 0 && i1 <= 10)
	{
		glTranslatef(0.05*i1, 0, 0);
		i1++;
	}
	else
	{
		if (i1 <= 350 && i1 > 10)
		{
			glLoadIdentity();
			glTranslatef(0, 0, -3);
			glRotated(rotk*i1, 0, 1, 0);
			glTranslatef(-0.3, 0.45, -0.5);
		}
		else
		{
			if (i1 >350 && i1 <= 360)
			{
				i1 = i1 - 350;
				glTranslatef(-0.3, 0.45, -0.5);
				glTranslatef(-0.005*i1, -0.00075 * i1, 0.05*i1);
				i1 = 350 + i1;
			}
			else
			{
				if (i1 > 360)
				{
				glTranslatef(-0.35, 0.375, 0);
				headcube(2, 3, 4, 1, 12, 13, 14, 11);
				}
				else
				{
					cube(2, 3, 4, 1, 12, 13, 14, 11);
				}
			}
		}
	}
	if (i1 >= 0 && i1 <= 360)
	{
		i1++;
		cube(2, 3, 4, 1, 12, 13, 14, 11);
	}
	glPopMatrix();
	
	glPushMatrix();
	if (i2 >= 0 && i2 <= 10)
	{
		glTranslatef(0.02*i2, 0, 0.045*i2);
	}
	else 
	{
		if (i2 <= 100 && i2 > 10)
		{
			glLoadIdentity();
			glTranslatef(0, 0, -3);
			glRotated(rotk*i2, 0, 1, 0);
			glTranslatef(0.2, 0, 0.45);
		}
		else
		{
			if (i2 >100 && i2 <= 110)
			{
				i2 = i2 - 100;
				glTranslatef(0.2, 0, 0.45);
				glTranslatef(-0.06*i2, 0, -0.045*i2);
				i2=100+i2;
			}
			else
			{
				if (i2 > 110)
				{
					glTranslatef(-0.4, 0, 0);
					cube(6, 7, 8, 5, 16, 17, 18, 15);
				}
				else
				{
					cube(6, 7, 8, 5, 16, 17, 18, 15);
				}
			}
		}	
	}
	if (i2 >= 0 && i2<=110)
	{
		i2++;
		cube(6, 7, 8, 5, 16, 17, 18, 15);
	}
	glPopMatrix();

	glPushMatrix();
	if (i3 >= 0 && i3 <= 10)
	{
		glTranslatef(0.03*i3, 0.01*i3, -0.03*i3);
	}
	else
	{
		if (i3 <= 120 && i3 > 10)
		{
			glLoadIdentity();
			glTranslatef(0, 0, -3);
			glRotated(rotk*i3, 0, 1, 0);
			glTranslatef(0.3, 0.1, -0.3);
		}
		else
		{
			if (i3 >120 && i3 <= 130)
			{
				i3= i3 - 120;
				glTranslatef(0.3, 0.1, -0.3);
				glTranslatef(-0.06*i3, -0.01*i3, -0.03*i3);
				i3 = 120 + i3;
			}
			else
			{
				if (i3 > 130)
				{
					glTranslatef(-0.3, 0, 0);
					cube(7, 10, 9, 8, 17, 20, 19, 18);
				}
				else
				{
					cube(7, 10, 9, 8, 17, 20, 19, 18);
				}
			}
		}
	}
	if (i3 >= 0&& i3 <=130)
	{
		i3++;
		cube(7, 10, 9, 8, 17, 20, 19, 18);
	}
	glPopMatrix();
	glEnd();

	glPushMatrix();
	glVertexPointer(3, GL_FLOAT, 0, SCENA);
	glColor3f(0.5, 0.5, 0.5);
	sqscen(8, 5, 6, 7); 
	square(4, 8, 7, 3);
	square(1, 4, 3, 2); 
	square(5, 8, 4, 1);
	square(2, 3, 7, 6); 
	square(5,1,2,6);
	glEnd();
	glDisableClientState(GL_VERTEX_ARRAY);
	drawCircle(0,0, 0.5, 30);
	glPopMatrix();
	if (rotk <= 50)
	{
		rotk+=0.1;
	}
	glutSwapBuffers();
}
void Initialize()
{
	LoadTextures();
	glEnable(GL_TEXTURE_2D);
	glMatrixMode(GL_MATRIX_MODE);
	// активация проекционной матрицы 
	glMatrixMode(GL_PROJECTION);
	// очистка матрицы 
	glLoadIdentity();
	// установка перспективы 
	gluPerspective(50, 1, 0.0001, 300);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_DEPTH_TEST);
	stat = 1;
}
void processNormalKeys(unsigned char key, int x, int y) {
	switch (key) {
	case 'x':
		glLoadIdentity();
		if (rot)
		{
			os_x = 1;
		}
		else{
			if (!camera)
			{
				xx += 0.05;
			}
		} break;
	case 'X':
		glLoadIdentity();
		if (rot)
		{
			os_x = 0;
		}
		else{
			if (!camera)
			{
				xx -= 0.05;
			}
		} break;
	case 'y':
		glLoadIdentity();
		if (rot)
		{
			os_y = 1;
		}
		else{
			if (!camera)
			{
				yy += 0.05;
			}
		} break;

	case 'Y':
		glLoadIdentity();
		if (rot)
		{
			os_y = 1;
		}
		else{
			if (!camera)
			{
				yy -= 0.05;
			}
		} break;
	case 'z':
		glLoadIdentity();
		if (rot)
		{
			os_z = 0;
		}
		else{
			if (!camera)
			{
				zz += 0.05;
			}
		} break;
	case 'Z':
		glLoadIdentity();
		if (rot)
		{
			os_z = 0;
		}
		else{
			if (!camera)
			{
				zz -= 0.05;
			}
		} break;
	case 'U':
		glLoadIdentity();
		if (camera)
		{
			r--;
		}
	 break;
	case 'u':
		glLoadIdentity();
		if (camera)
		{
			r++;
		}
		 break;
	case 27:
		exit(0); break;
	case 'p':
		// активация проекционной матрицы 
		glMatrixMode(GL_PROJECTION);
		// очистка матрицы 
		glLoadIdentity();
		// установка перспективы 
		gluPerspective(50, 1, 0.0001, 300);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glEnable(GL_DEPTH_TEST);
		stat = 1;
	
		zz = -zz;
		break;
	case 'f':
		// активация проекционной матрицы 
		glMatrixMode(GL_PROJECTION);
		// очистка матрицы 
		glLoadIdentity();
		// установка перспективы
		glFrustum(-1, 1, -1,1,0.7, 300);
		//gltranslatef(0,0,-20);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glEnable(GL_DEPTH_TEST);
		stat = 2;
		break;
	case 'o':
		// активация проекционной матрицы 
		glMatrixMode(GL_PROJECTION);
		// очистка матрицы 
		glLoadIdentity();
		// установка перспективы 
		glOrtho(-5, 5, -5, 5, -30, 50.5);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glEnable(GL_DEPTH_TEST);
		stat = 3;
		break;
	case 's':
		m1 = 0; m2 = 0; m3 = 0; m4 = 0; m5 = 0; m6 = 0;
		s1 = 0; s2 = 0; s3 = 0; s4 = 0; s5 = 0;
		i1 = 0; i2 = 0; i3 = 0; rotk = 0;
		break;

	case 'r':
		rot = true;
		camera = false;
		break;
	case 'R':
		rot = false;
		break;
	}
}
void processSpecialKeys(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_F1:
		if (zoom <= 10)
			zoom++;
		break;
	case GLUT_KEY_F2:
		if (zoom > 1)
			zoom--;
		break;
	case GLUT_KEY_RIGHT:
		if (camera)
		{
			if (xcor)
			{
				cxx += r / shag;
				czz = sqrt(r*r - cxx*cxx);
				if (cxx >= (r - r / shag))
				{
					xcor = false;
				}
			}
			else
			{
				cxx -= r / shag;
				czz = -sqrt(r*r - cxx*cxx);
				if (cxx <= (-r + r / shag))
				{
					xcor = true;
				}
			}
		}
		break;
	case GLUT_KEY_UP:
		if (camera && cyy <= r)
		{
			cyy += r / shag;
		}
		break;
	case GLUT_KEY_DOWN:
		if (camera && cyy >= -r&& cyy>=-0.1)
		{
			cyy -= r / shag;
		}
		break;
	case GLUT_KEY_LEFT:
		if (camera)
		{
			if (xcor)
			{
				cxx -= r / shag;
				czz = sqrt(r*r - cxx*cxx);
				if (cxx <= (-r + r / shag))
				{
					xcor = false;
				}
			}
			else
			{
				cxx += r / shag;
				czz = -sqrt(r*r - cxx*cxx);
				if (cxx >= (r - r / shag))
				{
					xcor = true;
				}
			}
		}
		break;
	}
}
void Timer(int)
{
	glutPostRedisplay();
	glutTimerFunc(50, Timer, 0);
}
int main(int argc, char** argv)
{

	//инициализаци¤
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(600, 20);
	glutCreateWindow("it's MSI nigga");
	//регистраци¤
	glutDisplayFunc(Draw);//рисование

	glutTimerFunc(50, Timer, 0);
	
	Initialize();

	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);
	system("cls");
	glutMainLoop();
	return 0;
}