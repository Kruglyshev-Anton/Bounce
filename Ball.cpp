#include "Ball.h"

Ball::Ball(float x, float y):x(x+one_cell_size*0.5),y(y+ one_cell_size * 0.5)
{
    //std::cout << 1;
    for (float i = 0; i < 6.282; i += 3.141 / 2) {
        pois.push_back({x+r*cosf(-i)+r, y+r+sinf(-i)*r});
    }
    a = one_cell_size * 0.04;
}

std::string Ball::getType()
{
    return "ball";
}

void Ball::Move(unsigned char k)
{
    //std::cout << k;
    if (k == 'd') {
        isMove = true;
        isMoveR = true;
        vx = 0.25 * one_cell_size;
        k = 'q';
        //Draw();
    }
    if (k == 'a') {
        isMove = true;
        isMoveL = true;
        vx = -0.25 * one_cell_size;
        k = 'q';
        //Draw();
    }
    //std::cout << isJ << '\n';
    if (k == ' '&&isJ) {
        isMove = true;
        isMoveU = true;
        isMoveD = true;
        vy -= 1;
        a = one_cell_size * 0.04;
        jump = -one_cell_size*0.6;
        k = 'q';
        //Draw();
        isJ = false;
    }
    if (!(k == ' ' && isJ) && !(k == 'a') && !(k == 'd')) {
        isMove = false;
        
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
    glColor3f(0, 0, 0);
    glPointSize(3);
    glBegin(GL_POINTS);
    for (int i = 0; i < 4; ++i) {
        glVertex2f(pois[i].first, pois[i].second);
    }
    glEnd();
    glPointSize(1);
    Phisycs();
   
}

void Ball::Phisycs()
{
    if (vy > r)vy = r;
    if (vy < -r)vy = -r;
    for (int i = 0; i < 4; ++i) {
        pois[i].first += vx;
        pois[i].second += vy;
    }
    
    y += vy;
    x += vx;
    if (!isMove) {
        if (vx > one_cell_size * 0.005)vx -= one_cell_size * 0.05;
        else if (vx < -one_cell_size * 0.005)vx += one_cell_size * 0.05;
        else vx = 0;
    }
    
    if (isMoveD)a = one_cell_size * 0.04;
    else a = 0;
    vy += (jump + a);
    
    
    //std::cout << vy<<'\n';
    if (jump < 0)jump += one_cell_size * 0.9;
    if (jump > 0)jump = 0;
    //if (vy < one_cell_size * 0.01)vy += one_cell_size * 0.1;
    //if (vy > one_cell_size * 0.01)vy = one_cell_size * 0.01;
    

}

std::vector<std::pair<float, float>>& Ball::getColl()
{
    return pois;
}

void Ball::sety(float val)
{
    float pa = val - y;

    y += pa;
    for (int i = 0; i < 4; ++i) {
        
        pois[i].second += pa;
    }
    vy = 0;
    a = 0;
}



void Ball::setx(float val)
{
    float pa = val - x;

    x += pa;
    for (int i = 0; i < 4; ++i) {

        pois[i].first += pa;
    }
    
}

void Ball::setJ(bool val)
{
    isJ = val;
}



float Ball::getx()
{
    return x;
}

float Ball::gety()
{
    return y;
}

float Ball::getw()
{
    return 2*r;
}

float Ball::geth()
{
    return 2*r;
}
