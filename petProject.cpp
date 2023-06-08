#include "vector3.h"
#include <stdio.h>

int check(int first, int second)
{
    if (second == 0)
    {
        throw std::exception("Divide by zero exception!");
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

    try
    {
        int test = check(10, 0);
        std::cout << test << std::endl;
    }
    catch (const std::exception& err)
    {
        std::cout << "Catch " << err.what() << std::endl;
    }
    
}