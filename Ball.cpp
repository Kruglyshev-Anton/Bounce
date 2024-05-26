#include "Ball.h"

Ball::Ball(float x, float y):x(x+one_cell_size*0.5),y(y+ one_cell_size * 0.5)
{
}

std::string Ball::getType()
{
    return "ball";
}

void Ball::Move(unsigned char k)
{
    
    if (k == 'd') {
        vx=one_cell_size*0.1;
        Draw();
    }
    if (k == 'a') {
        vx = -one_cell_size * 0.1;
        Draw();
    }
    if (k == ' '&&isJ) {
        jump = -one_cell_size*0.3;
        Draw();
        isJ = false;
    }

}

void Ball::Draw()
{
    
    float phi = 0.3141f;
    glColor3f(0.7f, 0.1f, 0.0f);
    glBegin(GL_POLYGON);
    float px = r * cosf(0) + x;
    float py = r * sinf(0) + y;
    for (float i = phi; i <= 6.282; i += phi) {
        glVertex2f(px, py);
        px = r * cosf(i) + x;
        py = r * sinf(i) + y;
        //std::cout << x << '\n';
        //glVertex2f(px, py);
    }
    glEnd();

    
    //std::cout << 1;
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    px = r * cosf(0) + x;
    py = r * sinf(0) + y;
    for (float i = 0; i <= 6.282; i += phi) {
        glVertex2f(px, py);
        px = r * cosf(i) + x;
        py = r * sinf(i) + y;
        //std::cout << x << '\n';
        glVertex2f(px, py);
    }
    glEnd();
    Phisycs();
   
}

void Ball::Phisycs()
{
    y += vy;
    x += vx;
    if (vx > 0)vx -= one_cell_size * 0.005;
    else if (vx < 0)vx += one_cell_size * 0.005;
    else vx = 0;
    float a;
    if (y + r >= 300) { 
        a = 0;
        vy = 0;
        isJ = true;
    }
    else a = one_cell_size * 0.009;
    vy += (jump + a);
    
    
    //std::cout << vy<<'\n';
    if (jump < 0)jump += one_cell_size * 0.9;
    if (jump > 0)jump = 0;
    //if (vy < one_cell_size * 0.01)vy += one_cell_size * 0.1;
    //if (vy > one_cell_size * 0.01)vy = one_cell_size * 0.01;
    

}
