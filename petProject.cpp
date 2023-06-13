#include "vector3.h"
#include <stdio.h>
#include <vector>

int check(int first, int second)
{
    if (second == 0)
    {
        throw std::domain_error("Divide by zero exception!");
    }
    return first / second;
}

int main()
{
    std::cout << "Hello World!\n";
    Vector3<float> vec(3, 5, 2);
    Vector3<float> vec2(11, 11, 11);
    Vector3<float> vec3(7, 7, 7);
    std::cout << vec.x << ' ' << vec.y << ' ' << vec.z << std::endl;
    std::cout << std::endl;
    //mul check
    vec.x *= 5;
    vec.z = vec.z * 3;
    vec.y *= 10;
    std::cout << vec.x << ' ' << vec.y << ' ' << vec.z << std::endl;
    std::cout << std::endl;

    //sub check
    vec.x -= 3;
    vec.z = vec.z - 10;
    vec.y -= 35;
    std::cout << vec.x << ' ' << vec.y << ' ' << vec.z << std::endl;
    std::cout << std::endl;

    //add check
    vec.x += 21;
    vec.z = vec.z + 2;
    vec.y += 11;
    std::cout << vec.x << ' ' << vec.y << ' ' << vec.z << std::endl;
    std::cout << std::endl;

    //div check
    vec.x /= 3;
    vec.z = vec.z / 2;
    vec.y /= 2;
    std::cout << vec.x << ' ' << vec.y << ' ' << vec.z << std::endl;
    std::cout << std::endl;

    //sub & add vectors check
    vec += vec3;
    std::cout << vec.x << ' ' << vec.y << ' ' << vec.z << std::endl;
    vec = vec - vec2;
    std::cout << vec.x << ' ' << vec.y << ' ' << vec.z << std::endl;
    std::cout << std::endl;

    //move check
    Vector3<float> vec4(std::move(vec3));
    vec2 = std::move(vec);
    std::cout << "Vec4 " << vec4.x << ' ' << vec4.y << ' ' << vec4.z << std::endl;
    std::cout << "Vec2 " << vec2.x << ' ' << vec2.y << ' ' << vec2.z << std::endl;
    std::cout << std::endl;

    //normalize & magnitude check
    float length = vec2.magnitude();
    std::cout << "Vec2 magnitude " << length << std::endl;
    vec2.normalize();
    std::cout << "Vec2 normalize " << vec2.x << ' ' << vec2.y << ' ' << vec2.z << std::endl;
    std::cout << std::endl;

    //check cross product
    Vector3<float> first(1, 0, 0);
    Vector3<float> second(0, 1, 0);
    Vector3<float> third;
    third.crossProduct(first, second);

    std::vector<Vector3<float>> pivot;
    pivot.reserve(3);
    pivot.push_back(first);
    pivot.push_back(second);
    pivot.push_back(third);

    std::cout << "pivot X: " << pivot[0].x << ' ' << pivot[0].y << ' ' << pivot[0].z << std::endl;
    std::cout << "pivot Y: " << pivot[1].x << ' ' << pivot[1].y << ' ' << pivot[1].z << std::endl;
    std::cout << "pivot Z: " << pivot[2].x << ' ' << pivot[2].y << ' ' << pivot[2].z << std::endl;

    
    return 0;
}