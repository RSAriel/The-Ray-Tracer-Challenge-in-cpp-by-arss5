#include "materials.hpp"
#include "color.hpp"
#include "tuple.hpp"
//Reminder to remove equal function from tuple.hpp

Material::Material() {
    color = Color(1, 1, 1);
    ambient = 0.1;
    diffuse = 0.9;
    specular = 0.9;
    shininess = 200.0;
};

//Maybe should be in lights.hpp
Color lighting(Material material, PointLight light, Tuple point, Tuple eyev, Tuple normalv) {
    Color effective_color = material.color * light.intensity;
    Tuple lightv = normalize(light.position - point);
    Color ambient = Color(effective_color * material.ambient);
    float light_dot_normal = dot(lightv, normalv);
    Color diffuse, specular;
    if (light_dot_normal < 0) {
        diffuse = Color(0, 0, 0);
        specular = Color(0, 0, 0);
    } else {
        diffuse = effective_color * material.diffuse * light_dot_normal;
        Tuple reflectv = reflect(-lightv, normalv);
        float reflect_dot_eye = dot(reflectv, eyev);
        if (reflect_dot_eye <= 0) {
            specular = Color(0, 0, 0);
        } else {
            float factor = pow(reflect_dot_eye, material.shininess);
            specular = light.intensity * material.specular * factor;
        }
    }
    return ambient + diffuse + specular;
}


bool operator==(const Material &lhs, const Material &rhs) {
    return equal(lhs.ambient, rhs.ambient) && equal(lhs.diffuse, rhs.diffuse) && equal(lhs.specular, rhs.specular) && equal(lhs.shininess, rhs.shininess) && lhs.color == rhs.color;
}