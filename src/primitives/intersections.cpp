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
    Tuple sphere_to_ray = r.origin - s.center;
    float a = dot(r.direction,(r.direction));
    float b = dot(r.direction,sphere_to_ray)*2;
    float c = dot(sphere_to_ray,sphere_to_ray) - 1;
    float discriminant = b * b - 4 * a * c;
    Intersections list;
    if (discriminant < 0) {
        return list;
    }

    float t1 = (-b - sqrt(discriminant)) / (2 * a);
    float t2 = (-b + sqrt(discriminant)) / (2 * a);
    list = Intersections(Intersection(t1, s), Intersection(t2, s));
    return list;
}

Intersection hit(Intersections xs) {
    Intersection i = Intersection();
    for (const auto& intersection : xs.list) {
        if (intersection.t >= 0) {
            if (i.t == 0 || intersection.t < i.t) {
                i = intersection;
            }
        }
    }
    return i;
}

