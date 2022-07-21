#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
float angle = 0.0, x = -4;
float angle2 = 0.0, y = 4;
float speed = 0.02,anglerotationspeed=0.8;
float speedy = 0.02, anglerotationspeedy = 0.8;
int day = 1;
int farrender2nd = 0;

float dbodycr = 0.416, dbodycg = 0.353, dbodycb = 0.804;//DeepSlate
float denginer = 1.000, dengineg = 0.271, dengineb = 0.000;//OrangeRed

float enginer = 1.000, engineg = 0.271, engineb = 0.000;
float bodycr = 0.416, bodycg = 0.353, bodycb = 0.804;

void home()
{
    float roofstart = 1.45;
    float scalestart = 1.45;
   
    //draw the roof
    for (roofstart; roofstart < 1.8; roofstart += 0.05)
    {
        if (scalestart == 0)
            continue;
        glPushMatrix(); 
        glColor3f(0.91, 0.76, 0.65);
        glTranslated(0, roofstart, 0);
        glScaled(scalestart, 0.1, 1);
        glutSolidCube(1);
        glPopMatrix();
        if (scalestart <= 0.3)
            scalestart = 0;
        else
            scalestart -= 0.3;
    }
    
    glPushMatrix(); //main building
    glColor3f(0.91, 0.76, 0.65);
    glTranslated(0, 0.4, 0);
    glScaled(2, 0.8, 1);
    glutSolidCube(1);
    glColor3f(0.65, 0.49, 0.24);
    glutWireCube(1);
    glPopMatrix();

    glPushMatrix(); //door
    glColor3f(0.698, 0.133, 0.133); //FireBrick Color
    glTranslated(0, 0.17, 0);
    glScaled(0.3, 0.4, 0.01);
    glutSolidCube(1);
    glColor3f(0, 0, 0);
    glutWireCube(1);
    glPopMatrix();

    glPushMatrix(); //main building roof
    glColor3f(0.71, 0.6, 0.35);
    glTranslated(0, 0.8, 0);
    glScaled(2, 0.02, 1);
    glutSolidCube(1);
    glColor3f(0.65, 0.49, 0.24);
    glutWireCube(1);
    glPopMatrix();

    glPushMatrix(); //room on floor
    glColor3f(0.91, 0.76, 0.65);
    glTranslated(0, 1.1, 0);
    glScaled(1.4, 0.6, 1);
    glutSolidCube(1);
    glColor3f(0.65, 0.49, 0.24);
    glutWireCube(1);
    glPopMatrix();

    glPushMatrix(); //top room roof slab
    glColor3f(0.71, 0.6, 0.35);
    glTranslated(0, 1.4, 0);
    glScaled(1.45, 0.02, 1);
    glutSolidCube(1);
    glColor3f(0.65, 0.49, 0.24);
    glutWireCube(1);
    glPopMatrix();

    glPushMatrix(); //top room window
    glColor3f(0, 0, 0);
    glTranslated(0, 1.1, 0);
    glScaled(0.4, 0.3, 0.01);
    glutSolidCube(1);
    glPopMatrix();
}

void trainBox(int f= 0)
{
    float wheelr = 0.535, wheelg = 0.535, wheelb = 0.535;//Gray
    glPushMatrix(); //Right Wheel Far
    glColor3f(wheelr, wheelg, wheelb);
    if (farrender2nd == 0)
        glTranslated(0.65, -0.5, -2);
    else
        glTranslated(0.79, - 0.73, -2);
    if (farrender2nd == 0)
        glRotated(angle, 0, 0, 1); //Rotation angle for right wheel far;
    else
        glRotated(angle2, 0, 0, 1);
    glutSolidTorus(0.1, 0.2, 10, 10);
    glColor3f(0, 0, 0);
    glutWireTorus(0.1, 0.2, 10, 10);
    glPopMatrix();

    glPushMatrix(); //Left Wheel Far
    glColor3f(wheelr, wheelg, wheelb);
    if (farrender2nd == 0)
        glTranslated(-1, -0.5, -2);
    else
        glTranslated(-0.78,-0.73, -2);
    if (farrender2nd == 0)
        glRotated(angle, 0, 0, 1); //Rotation angle for left wheel far;
    else
        glRotated(angle2, 0, 0, 1);   
    glutSolidTorus(0.1, 0.2, 10, 10);
    glColor3f(0, 0, 0);
    glutWireTorus(0.1, 0.2, 10, 10);
    glPopMatrix();

    
    if (f == 1)
    {
        glPushMatrix(); //Train BOX ENGINE
        glColor3f(enginer,engineg,engineb);
        glScaled(2, 1, 1);
        glutSolidCube(1);
        glColor3f(0, 0, 0);
        glutWireCube(1);
        glPopMatrix();
    }
    else
    {
        glPushMatrix(); //Train BOX
        glColor3f(bodycr,bodycg,bodycb); //Slate Blue Color
        glScaled(2, 1, 1);
        glutSolidCube(1);
        glColor3f(0, 0, 0);
        glutWireCube(1);
        glPopMatrix();
    }


    if (f == 1)
    {
        glPushMatrix(); //For Engine Chimney Thing
        glColor3f(enginer,engineg,engineb);
        glTranslated(0.7, 0.8, 0);
        glScaled(0.2, 0.6, 0.5);
        glutSolidCube(1);
        glColor3f(0, 0, 0);
        glutWireCube(1);
        glPopMatrix();
    }
    if (f == 0)
    {
        glPushMatrix(); //Train Connection Boxes
        glColor3f(0.3, 0.3, 0.3);
        glTranslated(1.2, -0.45, 0.5);
        glScaled(0.4, 0.1, 0.5);
        glutSolidCube(1);
        glColor3f(0, 0, 0);
        glutWireCube(1);
        glPopMatrix();
    }

    glPushMatrix(); //Right Wheel Near
    glColor3f(wheelr, wheelg, wheelb);
    glTranslated(0.95, -0.7, 0.5);
    if (farrender2nd == 0)
        glRotated(angle, 0, 0, 1); //Rotation angle for right wheel near;
    else
        glRotated(angle2, 0, 0, 1); glutSolidTorus(0.1, 0.2, 10, 10);
    glColor3f(0, 0, 0);
    glutWireTorus(0.1, 0.2, 10, 10);
    glPopMatrix();

    glPushMatrix(); //Left Wheel Near
    glColor3f(wheelr, wheelg, wheelb);
    glTranslated(-0.65, -0.7, 0.5);
    if (farrender2nd == 0)
        glRotated(angle, 0, 0, 1); //Rotation angle for left wheel near;
    else
        glRotated(angle2, 0, 0, 1);
    glutSolidTorus(0.1, 0.2, 10, 10);
    glColor3f(0, 0, 0);
    glutWireTorus(0.1, 0.2, 10, 10);
    glPopMatrix();
    
    angle -= anglerotationspeed;
    angle2 -= anglerotationspeedy;
}

void tree()
{
    glPushMatrix();
    glColor3b(102, 100, 70);
    glScaled(0.2, 6, 0.2);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3b(48, 124, 66);
    glTranslated(0, 2, 0);
    glutSolidSphere(1, 8, 8);
    glColor3f(0, 1, 0);
    glutWireSphere(1, 8, 8);
    glPopMatrix();
}

void background()
{

    if (day == 1)
    {
        glColor3f(0.24, 0.56, 0.37);
        glRecti(-3, -2, 3, 0); //green grass

        glColor3f(0.13, 0.68, 0.85);
        glRecti(-3, 0, 3, 2); //sky
    }
    else
    {
        glColor3f(0.24, 0.56, 0.37);
        glRecti(-3, -2, 3, 0); //green grass

        glColor3f(0.13, 0.13, 0.13);
        glRecti(-3, 0, 3, 2); //sky


    }

    //small trees
    glPushMatrix();
    glTranslated(1.7, 0.6, 0);
    glScaled(0.3, 0.3, 0.1);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslated(1.5, 0.8, 0);
    glScaled(0.3, 0.3, 0.1);
    tree();
    glPopMatrix();

    //big trees
    glPushMatrix();
    glTranslated(-1.6, 0.4, 0);
    glScaled(0.23, 0.23, 0.1);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslated(-1.4, 0.6, 0);
    glScaled(0.23, 0.23, 0.1);
    tree();
    glPopMatrix();


    home();
}
void renderScene(void)
{
    float i = -3.50;
    farrender2nd = 0;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glRotatef(10, 1.0, 1.0, 0.0); //TO give a slightly 3Der look
    glOrtho(-3, 3, -2, 2, -4, 4);

    glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glScaled(1.1, 1.1, 2);
        background();
    //Drawing Railtracks
    for (i; i < 3.5; i += 0.4)
    {
        glPushMatrix();
        glColor3f(0, 0, 0);
        glTranslated(i, -0.4, 0);
        glScaled(1, 0.1, 0.1);
        glutWireCube(1);
        glPopMatrix();
    }

    //Drawing 2nd Railtracks
    i = -3.50;
    for (; i < 3.5; i += 0.4)
    {
        glPushMatrix();
        glColor3f(0, 0, 0);
        glTranslated(i, -0.8, 0);
        glScaled(1, 0.1, 0.1);
        glutWireCube(1);
        glPopMatrix();
    }

    
    glMatrixMode(GL_PROJECTION);
    glTranslatef(x, 0, 0); // to move train
    glScaled(0.5, 0.5, 0.5);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glTranslated(-2.4, 0, 0);
    trainBox();
    glPopMatrix();
    glPushMatrix();
    glTranslated(0, 0, 0);
    trainBox();
    glPopMatrix();
    glPushMatrix();
    glTranslated(2.4, 0, 0);
    trainBox(1);
    glPopMatrix();

    //2nd Train
    farrender2nd = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glScaled(0.5, 0.5, 0.5);
    glTranslatef(y, 0, 0); // to move train
    glRotatef(10, 1.0, 1.0, 0.0); //TO give a slightly 3Der look
    glOrtho(-3, 3, -2, 2, -4, 4);


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glRotatef(180, 0, 1, 0);
    glTranslated(2.4, -0.8, 0);
    trainBox(1);
    glPopMatrix();
    glPushMatrix();
    glRotatef(180, 0, 1, 0);
    glTranslated(0, -0.8, 0);
    trainBox();
    glPopMatrix();
    glPushMatrix();
    glRotatef(180, 0, 1, 0);
    glTranslated(-2.4, -0.8, 0);
    trainBox();
    glPopMatrix();

    
    if (x < 5)
        x += speed; //control train speed from here
    else
        x = -6;
    if (y > -4)
        y -= speedy;
    else
        y = 5;

    glutSwapBuffers();
}

void mouseContextMenu(int a)
{
    switch (a)
    {
    case 0:{
        enginer = 1;
        engineg = 0;
        engineb = 0;
        break;
    }
    case 1: {
        enginer = 0;
        engineg = 1;
        engineb = 0;
        break;
    }
    case 2: {
        enginer = 0;
        engineg = 0;
        engineb = 1;
        break;
    }
    case 3: {
        enginer = denginer;
        engineg = dengineg;
        engineb = dengineb;
        break;
    }
    case 4: {
        bodycr = 1;
        bodycg = 0;
        bodycb = 0;
        break;
    }

    case 5: {
        bodycr = 0;
        bodycg = 1;
        bodycb = 0;
        break;
    }

    case 6: {
        bodycr = 0;
        bodycg = 0;
        bodycb = 1;
        break;
    }

    case 7: {
        bodycr = dbodycr;
        bodycg = dbodycg;
        bodycb = dbodycb;
        break;
    }
    default: {
        std::cout << "There was an Error For Mouse Menu!" << std::endl;
    }
    }
}

void keyfunc(unsigned char a, int x, int y)
{
    if (a == 'a' or a == 'A')
    {
        speedy += 0.02;
        anglerotationspeedy += 0.4;
    }
    if (a == 'd' or a == 'D')
    {
        if (speedy > 0)
        {
            speedy -= 0.02;
            if (anglerotationspeedy > 0)
                anglerotationspeedy -= 0.4;
            else
                anglerotationspeedy = 0;
        }
        else
        {
            speedy = 0;
            anglerotationspeedy = 0;
        }

    }


    if (a == 'w' or a == 'W')
    {
        speed += 0.02;
        anglerotationspeed += 0.4;
    }
    if (a == 's' or a == 'S')
    {
        if (speed > 0)
        {
            speed -= 0.02;
            if (anglerotationspeed > 0)
                anglerotationspeed -= 0.4;
            else
                anglerotationspeed = 0;
        }
        else
        {
            speed = 0;
            anglerotationspeed = 0;
        }

    }
    if (a == 'z' or a == 'Z')
    {
        if (day == 1)
            day = 0;
        else
            day = 1;
    }

    if (speed <= 0)
    {
        anglerotationspeed = 0;
    }
    if (speedy <= 0)
    {
        anglerotationspeedy = 0;
    }
}


int main(int argc, char** argv) {
    std::cout << "Increase the speed of train far by w";
    std::cout << std::endl << "Decrease the speed of the train far by s" << std::endl;
    std::cout << "Increase the speed of train near by a";
    std::cout << std::endl << "Decrease the speed of the train far by d" << std::endl;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(10, 10);
    glutInitWindowSize(1366, 768);
    glutCreateWindow("Train Project");
    glutDisplayFunc(renderScene);
    glutIdleFunc(renderScene);
    glClearColor(1, 1, 1, 1);
    glutKeyboardFunc(keyfunc);
    glutCreateMenu(mouseContextMenu);
    glutAddMenuEntry("Engine Red: ", 0);
    glutAddMenuEntry("Engine Green: ", 1);
    glutAddMenuEntry("Engine Blue: ", 2);
    glutAddMenuEntry("Engine Default: ", 3);
    glutAddMenuEntry("Body Red: ", 4);
    glutAddMenuEntry("Body Green: ", 5);
    glutAddMenuEntry("Body Blue: ", 6);
    glutAddMenuEntry("Body Default: ", 7);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();
    return 0;
}
