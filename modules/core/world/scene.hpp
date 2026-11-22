#ifndef AETHER_WORLD_SCENE_HPP
#define AETHER_WORLD_SCENE_HPP

#include <memory>

#include <core/display/types.hpp>

namespace Aether {
    class Scene {
        public:
            Scene(void);
            ~Scene();
        public:
            struct {
                int size, stride;
                std::unique_ptr<Vertex[]> buffer;
            } vertices;
        private:
            static Vertex defVertices[];
    };
}


#endif