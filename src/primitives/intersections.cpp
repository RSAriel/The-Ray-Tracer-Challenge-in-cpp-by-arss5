#include <intersections.hpp>

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

int Intersections::size() {
    return list.size();
}

Intersections intersect(Sphere s, Ray r) {
    r = transform(r, s.transformation.inverse());
    Tuple sphere_to_ray = r.origin - s.center;
    float a = dot(r.direction,r.direction);
    float b = 2*dot(r.direction,sphere_to_ray);
    float c = dot(sphere_to_ray,sphere_to_ray) - 1;
    float discriminant = b * b - 4 * a * c;
    Intersections list;
        if (discriminant < 0) {
        list = Intersections(Intersection(-1, s));
        return list;
    }
    float sqrt_discriminant = sqrt(discriminant);
    float t1 = (-b - sqrt_discriminant) / (2 * a);
    float t2 = (-b + sqrt_discriminant) / (2 * a);
    list = Intersections(Intersection(t1, s), Intersection(t2, s));
    return list;
}

// Intersection hit(Intersections xs) {
//     Intersection i = Intersection();
//     for (const auto& intersection : xs.list) { 
//         if (intersection.t < i.t || i.t > 0) {
//             i = intersection;
//         }
//         else{
//             i.t = -1;
//             return i;
//         }
//     }
//     return i;
// }

Intersection hit(Intersections xs) {
    Intersection i = Intersection();
    if (xs.list[0].t == -1){
        i.t = -1;
        return i;
    }
    for (const auto& intersection : xs.list) {
        if (intersection.t < i.t) {
            i = intersection;
            if (i.t < 0) {
                i.t = -1;
                return i;
            }
        }
    }
    return i;
}

void Intersections::print() {
    for (const auto& intersection : list) {
        std::cout << intersection.t << std::endl;
    }
}