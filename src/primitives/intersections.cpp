#include <intersections.hpp>

const int INT_MAX = 2147483647;
const int INT_MIN = -2147483648;



Intersections::Intersections() {
    this->list = std::vector<Intersection>();
}

Intersections::Intersections(std::vector<Intersection> list) {
    for (const auto& intersection : list) {
        this->list.push_back(intersection);
    }
    // this->list = list;
}

Intersections::Intersections(Intersection i) {
    list.push_back(i); 
}

Intersections::Intersections(Intersection i1, Intersection i2) {
    list.push_back(i1);
    list.push_back(i2);
}

void Intersections::add(Intersection i) {
    list.push_back(i);
}

void Intersections::sort() {
    std::sort(list.begin(), list.end(), [](Intersection a, Intersection b) {
        return a.t < b.t;
    });
}

int Intersections::size() {
    return list.size();
}

bool Intersections::is_empty() {
    return list.size() == 0;
} 

Intersections intersect(Sphere s, Ray r) {
    r = transform(r, s.transformation.inverse());
    Tuple sphere_to_ray = r.origin - s.center;
    float a = dot(r.direction,r.direction);
    float b = 2*dot(r.direction,sphere_to_ray);
    float c = dot(sphere_to_ray,sphere_to_ray) - 1;
    float discriminant = b * b - 4 * a * c;
    float temp;
    Intersections list;
        if (discriminant < 0) {
        return list;
    }
    float sqrt_discriminant = sqrt(discriminant);
    float t1 = (-b - sqrt_discriminant) / (2 * a);
    float t2 = (-b + sqrt_discriminant) / (2 * a);
    //Generalizar com função sort() quando for refatorar
    if (t2 < t1 && t2 > 0) {
        temp = t1;
        t1 = t2;
        t2 = temp;
    }
    list = Intersections(Intersection(t1, s), Intersection(t2, s));
    return list;
}

Intersection hit(Intersections xs) {
    Intersection i = Intersection();
    for (const auto& intersection : xs.list) {
        if (intersection.t < i.t && intersection.t > 0) {
            i = intersection;
        }
    }
    if (i.t == INT_MAX){
        i.t = INT_MIN;
    }
    return i;
}

void Intersections::print() {
    for (const auto& intersection : list) {
        std::cout << intersection.t << std::endl;
    }
}