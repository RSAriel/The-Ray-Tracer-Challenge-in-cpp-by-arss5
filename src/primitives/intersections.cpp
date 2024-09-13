#include <intersections.hpp>

Intersections::Intersections() {
    list = std::vector<Intersection>();
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
    Ray new_r = transform(r, s.transformation.inverse());
    auto foo = r.origin;
    // r.print();
    Tuple sphere_to_ray = foo - Point(0, 0, 0);
    // sphere_to_ray.print();
    float a = dot(new_r.direction,new_r.direction);
    float b = dot(new_r.direction,sphere_to_ray)*2;
    float c = dot(sphere_to_ray,sphere_to_ray) - 1;
    // std::cout << a << " " <<  b << " " << c << std::endl;
    float discriminant = b * b - 4 * a * c;
    Intersections list;
    // std::cout << discriminant << std::endl;
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
    if (xs.list[0].t == 2147483647){
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