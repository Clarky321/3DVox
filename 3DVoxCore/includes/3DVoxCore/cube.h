#ifndef CUBE_H
#define CUBE_H

#include <raylib.h>

class Cube {
public:
    Cube(Vector3 position, float size, Texture2D texture);
    void Draw();
    Vector3 GetPosition() const;

private:
    Vector3 position;
    float size;
    Texture2D texture;
};

#endif // CUBE_H