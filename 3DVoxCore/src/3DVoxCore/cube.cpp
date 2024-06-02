#include "3DVoxCore\cube.h"

Cube::Cube(Vector3 position, float size, Texture2D texture)
    : position(position), size(size), texture(texture) {}

void Cube::Draw() {
    // Bind texture and draw cube
    DrawCubeTexture(texture, position, size, size, size, WHITE);
}

Vector3 Cube::GetPosition() const {
    return position;
}
