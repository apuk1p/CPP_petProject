#include "vector3.h"
#include <stdio.h>

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
    Vector3<int> vec(3, 5, 2);
    std::cout << vec.x << ' ' << vec.y << ' ' << vec.z << std::endl;
    vec.x *= 5;
    vec.z = vec.z * 3;
    vec.y *= 10;
    std::cout << vec.x << ' ' << vec.y << ' ' << vec.z << std::endl;
    vec.x -= 3;
    vec.z = vec.z - 10;
    vec.y -= 35;
    std::cout << vec.x << ' ' << vec.y << ' ' << vec.z << std::endl;

    vec.x += 21;
    vec.z = vec.z + 2;
    vec.y += 11;
    std::cout << vec.x << ' ' << vec.y << ' ' << vec.z << std::endl;

    vec.x /= 3;
    vec.z = vec.z / 2;
    vec.y /= 2;
    std::cout << vec.x << ' ' << vec.y << ' ' << vec.z << std::endl;

    Vector3<int> vec3(7, 7, 7);
    vec += vec3;
    std::cout << vec.x << ' ' << vec.y << ' ' << vec.z << std::endl;
    Vector3<int> vec2(11, 11, 11);
    vec = vec - vec2;
    std::cout << vec.x << ' ' << vec.y << ' ' << vec.z << std::endl;
    /*Vector3<int> vec2(std::move(vec3));
    std::cout << vec2.x << ' ' << vec2.y << ' ' << vec2.z << std::endl;
    vec2 = std::move(vec);
    std::cout << vec2.x << ' ' << vec2.y << ' ' << vec2.z << std::endl;
    std::cout << vec3.x << ' ' << vec3.y << ' ' << vec3.z << std::endl;*/
    
    return 0;
}