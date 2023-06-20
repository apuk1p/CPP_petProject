#include "vector3.h"
#include "matrix4x4.h"
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
    matrix4x4 check;
    //std::cout << "Write x,y,z scale values" << std::endl;
    //std::cin >> input.x >> input.y >> input.z;
    matrix4x4 newCheck(check);
    newCheck.setScale(vector3<float>(1, 5, 3));
    vector3<float> input(3,5,1);
    check.setScale(input);
    //matrix4x4 newCheck(std::move(check)); //move ctor check
    vector3<float> mtxCheck = check.getScale();
    vector3<float> mtxCheck1 = newCheck.getScale();
    //std::cout << "mtxCheck  " << mtxCheck.x << ' ' << mtxCheck.y << ' ' << mtxCheck.z << std::endl;
    //std::cout << "mtxCheck1 " << mtxCheck1.x << ' ' << mtxCheck1.y << ' ' << mtxCheck1.z << std::endl;
    std::cout << "CHECK MATRIX" << std::endl;
    check.showMatrix();
    std::cout << std::endl;
    std::cout << "NEW CHECK MATRIX" << std::endl;
    newCheck.showMatrix();

    //std::cout << "\nHello World!\n";
    //vector3<float> vec(3, 5, 2);
    //vector3<float> vec2(11, 11, 11);
    //vector3<float> vec3(7, 7, 7);
    //std::cout << vec.x << ' ' << vec.y << ' ' << vec.z << std::endl;
    //std::cout << std::endl;

    ////mul check
    //vec.x *= 5;
    //vec.z = vec.z * 3;
    //vec.y *= 10;
    //std::cout << "Mul " << vec.x << ' ' << vec.y << ' ' << vec.z << std::endl;
    //std::cout << std::endl;

    ////sub check
    //vec.x -= 3;
    //vec.z = vec.z - 10;
    //vec.y -= 35;
    //std::cout << "Sub " << vec.x << ' ' << vec.y << ' ' << vec.z << std::endl;
    //std::cout << std::endl;

    ////add check
    //vec.x += 21;
    //vec.z = vec.z + 2;
    //vec.y += 11;
    //std::cout << "Add " << vec.x << ' ' << vec.y << ' ' << vec.z << std::endl;
    //std::cout << std::endl;

    ////div check
    //vec.x /= 3;
    //vec.z = vec.z / 2;
    //vec.y /= 2;
    //std::cout << "Div " << vec.x << ' ' << vec.y << ' ' << vec.z << std::endl;
    //std::cout << std::endl;

    ////sub & add vectors check
    //vec += vec3;
    //std::cout << "Add vec " << vec.x << ' ' << vec.y << ' ' << vec.z << std::endl;
    //vec = vec - vec2;
    //std::cout << "Sub vec " << vec.x << ' ' << vec.y << ' ' << vec.z << std::endl;
    //std::cout << std::endl;

    ////move check
    //vector3<float> vec4(std::move(vec3));
    //vec2 = std::move(vec);
    //std::cout << "Vec4 move " << vec4.x << ' ' << vec4.y << ' ' << vec4.z << std::endl;
    //std::cout << "Vec2 move " << vec2.x << ' ' << vec2.y << ' ' << vec2.z << std::endl;
    //std::cout << std::endl;

    ////normalize & magnitude check
    //float length = vec2.magnitude();
    //std::cout << "Vec2 magnitude " << length << std::endl;
    //vec2.normalize();
    //std::cout << "Vec2 normalize " << vec2.x << ' ' << vec2.y << ' ' << vec2.z << std::endl;
    //std::cout << std::endl;

    ////check crossproduct
    //vector3<float> first(1, 0, 0);
    //vector3<float> second(0, 1, 0);
    //vector3<float> third;
    //third.crossProduct(first, second);

    //std::vector<vector3<float>> pivot;
    //pivot.reserve(3);
    //pivot.push_back(first);
    //pivot.push_back(second);
    //pivot.push_back(third);

    //std::cout << "pivot X: " << pivot[0].x << ' ' << pivot[0].y << ' ' << pivot[0].z << std::endl;
    //std::cout << "pivot Y: " << pivot[1].x << ' ' << pivot[1].y << ' ' << pivot[1].z << std::endl;
    //std::cout << "pivot Z: " << pivot[2].x << ' ' << pivot[2].y << ' ' << pivot[2].z << std::endl;
    //std::cout << std::endl;

    ////check dotproduct
    //vector3<float> dpFirst(2, 1, 4);
    //vector3<float> dpSecont(1, 5, 8);
    ////float cos = dpFirst.dotProduct(dpFirst, dpSecont);
    //float cos = dpFirst.dotProduct(dpFirst.normalize(), dpSecont.normalize());
    //std::cout << "normalize1 " << dpFirst.x << ' ' << dpFirst.y << ' ' << dpFirst.z << std::endl;
    //std::cout << "normalize2 " << dpSecont.x << ' ' << dpSecont.y << ' ' << dpSecont.z << std::endl;
    //std::cout << "Cos is: " << cos << std::endl;

    return 0;
}