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
float const MASS = 5.4; //in kg
float const PI = 3.14159265;
float angle =  3*PI/4  ;
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

        void addToAngularVelocity(float x, float y)
        {
            m_w += sqrt(x *x + y * y); // this is wrong, is magnitude for now

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
        
        void updateAngle(float theta)
        {
            m_theta = theta;
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
            float Iz = m_m * m_l* m_l / 3;
            float c = cos(m_theta);
            float s = sin(m_theta);
            mat <<
                1, 0, 0, 0, 0, 0,-1, 0, 0,
                0, 1, 0, 0, 0, 0, 0,-1, 0,
                0, 0, 1, 0, 0, 0, 0, 0,-1,
                0, 0, 0, 0, 0, 0, 0, 0, s,
                0, 0, 0, 0, 0, 0, 0, 0,-c,
                0, 0, 0, 0, 0,Iz,-s, c, 0, 
               -1, 0, 0, 0, 0,-s, 0, 0, 0,
                0,-1, 0, 0, 0, c, 0, 0, 0, 
                0, 0,-1, s,-c, 0, 0, 0, 0; 
            return mat;
            
        }
        

};






int main(){
    sf::RenderWindow window(sf::VideoMode(WIDTH,HEIGHT), "SFML works!");
    /*
    sf::RectangleShape line(sf::Vector2f(150, 5));
    line.rotate(135);
    line.setPosition(HEIGHT / 2, WIDTH / 2);
    */


    sf::CircleShape shape(10.f);
    shape.setPosition((ORIGIN.x) +   wirelength * cos(angle), ORIGIN.y + wirelength * sin(angle));
    shape.setFillColor(sf::Color::Green);

    Pendulum p(10.f, ORIGIN, 0, MASS, wirelength, angle); 
    int t = 0;
    bool goRight = false;
    float uAngle = angle;


    Eigen::VectorXf output(9);
    output <<   p.m_m * gravity * cos(angle), p.m_m * gravity * sin(angle),
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


               
        //Update positions
        /* 
        if(t < 100 && goRight) {
            uAngle += dA;
        } else if ( t < 100 && !goRight) {
            uAngle -= dA;
            
        } else {
            t = 0;
            goRight = !goRight;
        }
        p.updateAngle(uAngle);
        */
        VectorXf o =  p.getEquationsMatrix().colPivHouseholderQr().solve(output);  
        // As is, x1:3 = acceleartion, x4:6 = angularAccel, x7:9 = Fc??
        //Position = 
        std::cout<<o[0]<<std::endl;
        std::cout<<o[1]<<std::endl;
        p.addToVelocity(dt*o[0], dt*o[1]);
        p.updatePositionWithVelocity(dt); 
        p.addToAngularVelocity( dt * o[4], dt * o[5]);
        p.updateTheta(dt);
        t += dt;
        std::cout<<p.m_theta<<std::endl;
        p.updateCircle();
        //Draw images here
        window.draw(shape);
        window.draw(p.getCircle());
        sf::Vertex line[] = 
        {
            p.m_origin,
            p.m_psn
        };
        window.draw(line, 2, sf::Lines);
        
        sf::sleep(sf::milliseconds(10));
        window.display();
    }

    return 0;
}
