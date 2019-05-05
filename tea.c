#include<stdlib.h>

#include<stdio.h>

#include<GL/glut.h>

void leg1( )

{

     glPushMatrix( );//save the unscaled coordinate

     glTranslatef(-140,-160,-140);

     glScalef(20,300,20);//change the size of an object,y is stretched to 300

     glutSolidCube(1.0);//predefined solid model 1 is edge length

     glPopMatrix( );

}

void leg2( )

{

     glPushMatrix( );

     glTranslatef(-140,-160,+140);

     glScalef(20,300,20);

     glutSolidCube(1.0);

     glPopMatrix( );

}

void leg3( )

{

     glPushMatrix( );

     glTranslatef(+140,-160,-140);

     glScalef(20,300,20);

     glutSolidCube(1.0);

     glPopMatrix( );

}

void leg4( )

{

     glPushMatrix( );

     glTranslatef(+140,-160,+140);

     glScalef(20,300,20);

     glutSolidCube(1.0);

     glPopMatrix( );

}

 

 

void surface()

{

     glPushMatrix( );

     glTranslatef(0,0,0);

     glScalef(300,20,300);

     glutSolidCube(1.0);

     glPopMatrix( );

}

void table( )

{

GLfloat a[ ]={0.9,0.9,0.9,1.0};

GLfloat b[ ]={0.1,0.1,0.1,1.0};

GLfloat c[]={1.0,0.0,0.0,0.5};

GLfloat d[]={100.0};

   glMaterialfv(GL_FRONT,GL_AMBIENT,a);

   glMaterialfv(GL_FRONT,GL_SPECULAR,b);

   glMaterialfv(GL_FRONT,GL_DIFFUSE,c);

   glMaterialfv(GL_FRONT,GL_SHININESS,d);

   surface();

   leg1( );

   leg2( );

   leg3( );

   leg4( );

}

void teapot( )

{

     glPushMatrix( );

     GLfloat a[]={0.0,0.0,0.9,1.0};

     glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,a);

     glTranslatef(0,45,0);

     glutSolidTeapot(60.0);

     glPopMatrix( );

}

void myinit( )

{

     glViewport(0,0,500,500);

     glMatrixMode(GL_PROJECTION);

     glLoadIdentity( );

     glOrtho(-300,300,-300,300,-300,300);

     glMatrixMode(GL_MODELVIEW);

}

void display( )

{

     glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

     GLfloat a[ ]={0.0,350.0,+350,1.0};

     GLfloat b[ ]={0.5,0.5,1.0,1.0};

     glLightfv(GL_LIGHT0,GL_POSITION,a);

     glLightfv(GL_LIGHT0,GL_DIFFUSE,b);

      glRotatef(30,1,1,0);

     table( );

     teapot( );

     glFlush( );

}

void main(int argc,char **argv)

{

     glutInit(&argc,argv);

     glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);

     glutInitWindowPosition(0,0);

     glutInitWindowSize(1000,1000);

     glutCreateWindow("light and shade");

     myinit( );

     glutDisplayFunc(display);

     glEnable(GL_LIGHTING);

     glEnable(GL_LIGHT0);

     glShadeModel(GL_SMOOTH);

     glEnable(GL_DEPTH_TEST);

     glEnable(GL_NORMALIZE);

     glutMainLoop( );

}
