#ifndef AETHER_RENDERER_HPP
#define AETHER_RENDERER_HPP

#include <memory>

namespace Aether {
    struct GraphicsContext;

    class Renderer {
        public:
            Renderer(int width, int height);
            ~Renderer();
        public:
            void present(void);
            // void update
            void resize(int width, int height);
        private:
            void load_context(void);
            void init(int width, int height);

            std::unique_ptr<GraphicsContext> ctx;
    };
}


#endif