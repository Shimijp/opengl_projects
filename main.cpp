#include <iostream>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <cmath>
#include <complex>
#include "liniaerAlg.h"
static  float angle = M_PI/4;

//first square, with minimum depth
static f_vector ulc = {-0.5,0.5,-0.5};
static f_vector llc = {-0.5,-0.5,-0.5};
static f_vector urc = {0.5,0.5,-0.5};
static f_vector lrc = {0.5,-0.5,-0.5};

//second square all positive depth
static f_vector sulc = {-0.5,0.5,0.5};
static f_vector sllc = {-0.5,-0.5,0.5};
static f_vector surc = {0.5,0.5,0.5};
static f_vector slrc = {0.5,-0.5,0.5};

//third square one positive and one negative positive depth
static f_vector tulc = {-0.5,0.5,-0.5};
static f_vector tllc = {-0.5,-0.5,-0.5};
static f_vector turc = {-0.5,0.5,0.5};
static f_vector tlrc = {-0.5,-0.5,0.5};

static f_vector fulc = {0.5, 0.5, -0.5}; // Fourth square
static f_vector fllc = {0.5, -0.5, -0.5};
static f_vector furc = {0.5, 0.5, 0.5};
static f_vector flrc = {0.5, -0.5, 0.5};

using namespace std;
void timer(int value);
void display() {
    // Clear the color buffer with the specified clear color
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //sets color to white
    glClearColor(1,1,1,1);
    float cos_a = cosf(angle);
    float sin_a = sinf(angle);
    // rotation matrix
    matrix rotation = {
        {cos_a * cos_a, sin_a * sin_a * cos_a - sin_a * cos_a, cos_a * sin_a * sin_a + sin_a * sin_a},
   {cos_a * sin_a, sin_a * sin_a * sin_a + cos_a * cos_a, cos_a * sin_a * sin_a - sin_a * sin_a},
   {-sin_a, sin_a * cos_a, cos_a * cos_a}
    };

     // Draw the first square
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0, 0, 0);

    f_vector r_ulc = multiply(ulc, rotation);
    f_vector r_llc = multiply(llc, rotation);
    f_vector r_urc = multiply(urc, rotation);
    f_vector r_lrc = multiply(lrc, rotation);

    glVertex3f(r_ulc.at(0), r_ulc.at(1), r_ulc.at(2));
    glVertex3f(r_urc.at(0), r_urc.at(1), r_urc.at(2));
    glVertex3f(r_lrc.at(0), r_lrc.at(1), r_lrc.at(2));
    glVertex3f(r_llc.at(0), r_llc.at(1), r_llc.at(2));
    glEnd();

    // Draw the second square
    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 1.0);

    f_vector r_sulc = multiply(sulc, rotation);
    f_vector r_sllc = multiply(sllc, rotation);
    f_vector r_surc = multiply(surc, rotation);
    f_vector r_slrc = multiply(slrc, rotation);

    glVertex3f(r_sulc.at(0), r_sulc.at(1), r_sulc.at(2));
    glVertex3f(r_surc.at(0), r_surc.at(1), r_surc.at(2));
    glVertex3f(r_slrc.at(0), r_slrc.at(1), r_slrc.at(2));
    glVertex3f(r_sllc.at(0), r_sllc.at(1), r_sllc.at(2));
    glEnd();

    // Draw the third square
    glBegin(GL_LINE_LOOP);
    glColor3f(0, 1.0, 0);

    f_vector r_tulc = multiply(tulc, rotation);
    f_vector r_tllc = multiply(tllc, rotation);
    f_vector r_turc = multiply(turc, rotation);
    f_vector r_tlrc = multiply(tlrc, rotation);

    glVertex3f(r_tulc.at(0), r_tulc.at(1), r_tulc.at(2));
    glVertex3f(r_turc.at(0), r_turc.at(1), r_turc.at(2));
    glVertex3f(r_tlrc.at(0), r_tlrc.at(1), r_tlrc.at(2));
    glVertex3f(r_tllc.at(0), r_tllc.at(1), r_tllc.at(2));
    glEnd();

    // Draw the fourth square
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0, 1.0, 0);

    f_vector r_fulc = multiply(fulc, rotation);
    f_vector r_fllc = multiply(fllc, rotation);
    f_vector r_furc = multiply(furc, rotation);
    f_vector r_flrc = multiply(flrc, rotation);

    glVertex3f(r_fulc.at(0), r_fulc.at(1), r_fulc.at(2));
    glVertex3f(r_furc.at(0), r_furc.at(1), r_furc.at(2));
    glVertex3f(r_flrc.at(0), r_flrc.at(1), r_flrc.at(2));
    glVertex3f(r_fllc.at(0), r_fllc.at(1), r_fllc.at(2));
    glEnd();


    glFlush();
    glutSwapBuffers();
}



void timer(int value) {
    // Increment the angle for rotation
    angle += 0.01f;
    if (angle > 2 * M_PI) {
        angle -= 2 * M_PI;
    }

    // Request to call display again
    glutPostRedisplay();

    // Set the timer again for approximately 60 FPS
    glutTimerFunc(16, timer, 0);
}



int main(int argc, char **argv)
{


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA |GLUT_DEPTH);
    glutInitWindowPosition (1350/2, 300);
    glutInitWindowSize ( 600,600);
    glutCreateWindow ( "Hello World!" );
    glEnable(GL_DEPTH_TEST);





    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}


