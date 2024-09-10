#include <iostream>
#include <tuple.hpp>
#include <canvas.hpp>

class Projectile {
    public:
        Tuple position;
        Tuple velocity;

    Projectile(Tuple position, Tuple velocity){
        this->position = position;
        this->velocity = velocity;
    };
};

class Environment{
    public:
        Tuple gravity;
        Tuple wind;

    Environment(Tuple gravity, Tuple wind){
        this->gravity = gravity;
        this->wind = wind;
    };
};

Projectile tick(Environment env, Projectile proj){
    Tuple position = proj.position + proj.velocity;
    Tuple velocity = proj.velocity + env.gravity + env.wind;
    return Projectile(position, velocity);
}


int main() {
    
    Projectile P(Point(0, 1, 0), normalize(Vector(1, 1.8, 0))*8);
    Environment E(Vector(0, -0.1, 0), Vector(-0.01, 0, 0));
    Canvas C(900, 550);

    while (P.position.y > 0){
        P = tick(E, P);
        std::cout << "Position: " << P.position.x << ", " << P.position.y << ", " << P.position.z << std::endl;
        int x = static_cast<int>(std::round(P.position.x));
        int y = static_cast<int>(std::round(P.position.y));
        C.write_pixel(x, C.height - y, Color(1, 0, 0));
    }
    print_ppm(C.canvas_to_ppm());
}

