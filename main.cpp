// Include standard headers

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <Eigen/Core>
#include <Eigen/Dense>

using namespace Eigen;

int const HEIGHT = 600;
int const WIDTH = 800;
sf::Vector2f const ORIGIN = sf::Vector2f(WIDTH / 2.0, 0.0);
float const MASS = 1; //in kg
float const PI = 3.14159265;
float angle =  PI/4;
float dA = angle * .01;
float wirelength = 100;
float gravity = 9.81;

float dt = 0.01;

class Pendulum
{
public:
    float m_m;
    sf::Vector2f m_origin;
    sf::Vector2f m_psn;
    sf::Vector2f m_vel;
    float m_w; // angular velocity
    float m_l; // length
    float m_theta;// R? I guess, Idk
    sf::CircleShape m_circle;
    
    Pendulum(float r, sf::Vector2f o, float w, float m, float l, float theta) :
    m_circle(r), m_origin(o) , m_w(w), m_m(m), m_l(l), m_theta(theta)
    {
        m_psn = calcPsn();
        m_vel = sf::Vector2f(0.0, 0.0);
        m_circle.setPosition(m_psn);
    }
    
    sf::Vector2f calcPsn()
    {
        return sf::Vector2f(m_origin.x + ( m_l) * cos(m_theta),
                            m_origin.y + (m_l) * sin(m_theta));
    }
    
    void addToVelocity (float x, float y)
    {
        m_vel.x += x;
        m_vel.y += y;
    }
    
    void addToAngularVelocity(float w)
    {
        m_w += w;
        
    }
    void updateTheta(float dt)
    {
        m_theta += m_w * dt;
    }
    
    void updatePositionWithVelocity(float t)
    {
        m_psn.x += t * m_vel.x;
        m_psn.y += t * m_vel.y;
        
    }
    
    void updateAngle()
    {
        m_psn = calcPsn();
        m_circle.setPosition(m_psn);
    }
    void updateCircle()
    {
        m_circle.setPosition(m_psn);
    }
    
    sf::CircleShape getCircle()
    {
        return m_circle;
    }
    
    float getMass()
    {
        return m_m;
    }
    
    MatrixXf getEquationsMatrix()
    {
        MatrixXf mat(9, 9);
        float Iz = m_m * m_l* m_l / 12;
        float c = cos(m_theta);
        float s = sin(m_theta);
        mat <<
        m_m, 0, 0, 0, 0, 0,-1, 0, 0,
        0, m_m, 0, 0, 0, 0, 0,-1, 0,
        0, 0, m_m, 0, 0, 0, 0, 0,-1,
        0, 0, 0, 1, 0, 0, 0, 0, s,
        0, 0, 0, 0, 1, 0, 0, 0,-c,
        0, 0, 0, 0, 0,Iz,-s, c, 0,
        -1,0, 0, 0, 0,-s, 0, 0, 0,
        0,-1, 0, 0, 0, c, 0, 0, 0,
        0, 0,-1, s,-c, 0, 0, 0, 0;
        return mat;
        
    }
    
};

int main(){
    sf::RenderWindow window(sf::VideoMode(WIDTH,HEIGHT), "SFML works!");
    
    Pendulum p(10.f, ORIGIN, 0, MASS, wirelength, angle);
    int t = 0;
    bool goRight = false;
    float uAngle = angle;
    
    
    Eigen::VectorXf output(9);
    output <<
    0,
    p.m_m * gravity,
    0.f,
    
    0.f,
    0.f,
    0.f,
    
    0.f,
    0.f,
    0.f;
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        window.clear();
        
        VectorXf o =  p.getEquationsMatrix().colPivHouseholderQr().solve(output);
        
        
        //Updating values
        p.updatePositionWithVelocity(dt);
        p.addToVelocity(dt*o[0], dt*o[1]);
        p.updateTheta(dt);
        p.addToAngularVelocity(dt * o[5]);
        t += dt;
        
        //updating b vector
        Eigen::Vector3f w_1(0, 0, p.m_w);
        Eigen::Vector3f r(cos(p.m_theta), sin(p.m_theta), 0);
        //Eigen::Vector3f r(p.m_psn.x, p.m_psn.y, 0);

        Eigen::Vector3f w_1_new = w_1.cross(r);
        float kp =0.1;
        float kd =0.00;

        Eigen::Vector3f p2_c( ORIGIN.x, ORIGIN.y, 0);
        Eigen::Vector3f p1_c(p.m_psn.x + r[0], p.m_psn.y + r[1], 0 + r[2]);
        Eigen::Vector3f v1_c( w_1_new[0], w_1_new[1], 0 + w_1_new[2]); 
        Eigen::Vector3f err =   kp * (p1_c - p2_c) + kd * v1_c; 
        w_1_new = w_1.cross(w_1_new);
        //w_1_new += err; 

        
        output[6] = w_1_new[0]+err[0];
        output[7] = w_1_new[1]+err[1];
        output[8] = w_1_new[2]+err[2];
        
        
        //p.updateAngle();
        p.updateCircle();
        
        //Draw images here
       // window.draw(p.getCircle());
        sf::Vertex line[] =
        {
            p.m_origin,
            p.m_psn
        };
        window.draw(line, 2, sf::Lines);
        
       // sf::sleep(sf::milliseconds(10));
        window.display();
    }
    
    return 0;
}
