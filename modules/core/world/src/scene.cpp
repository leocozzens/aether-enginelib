// Local headers
#include <core/world/scene.hpp>

using namespace Aether;

// Constructor / Destructor

Vertex Scene::defVertices[] = {
    { -0.5F, -0.5F, 0.0F },
    {  0.5F, -0.5F, 0.0F },
    {  0.0F,  0.5F, 0.0F }
};

Scene::Scene(void) {
    vertices.stride = sizeof(Vertex);
    vertices.size = std::size(defVertices);
    vertices.buffer = std::make_unique<Vertex[]>(std::size(defVertices));
}

Scene::~Scene() = default;