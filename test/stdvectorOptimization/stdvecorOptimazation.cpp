#include <iostream>
#include <vector>

//为什么要优化vector？
//向vector插入的数据在栈区创建，插入时才被拷贝到vector，存在拷贝的过程

//如何优化vector?
//想办法将数据直接在vector所在得内存中创建，消除拷贝过程

class Vertex
{
private:
    float x, y, z;

public:
    Vertex(float x, float y, float z)
        : x(x), y(y), z(z)
    {
    }

    Vertex(const Vertex &vertex)
        : x(vertex.x), y(vertex.y), z(vertex.z)
    {
        std::cout << "Copied!" << std::endl;
    }
};

int main()
{
    std::vector<Vertex> vertices;
    // std::vector<Vertex> vertices(3);
    vertices.reserve(3);
    /*这里只会拷贝一次，因为vecor默认大小为1
    创建{1,2,3}时会先创建一个vertex的对象，
    之后将这个对象拷贝到vector中
    */
    // vertices.push_back({1, 2, 3});
    /*到这里总共拷贝3次，多了两次拷贝
    1.vector扩容时重新创建内存，将第一个元素拷贝过去
    2.插入第二个元素时，又拷贝了一次
      */
    // vertices.push_back(Vertex(4, 5, 6));
    /*
    到这里总共拷贝6次，多了三次拷贝
    1.vecor扩容时重新创建内存，将前两个元素拷贝过去
    2.插入第三个元素时，又拷贝了一次
    */
    // vertices.push_back(Vertex(7, 8, 9));

    vertices.emplace_back(1, 2, 3);
    vertices.emplace_back(4, 5, 6);
    vertices.emplace_back(7, 8, 9);
    std::cin.get();
}