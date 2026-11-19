#ifndef AETHER_RENDERER_HPP
#define AETHER_RENDERER_HPP

namespace Aether {
    struct GraphicsContext;

    class Renderer {
        public:
            Renderer(void);
            ~Renderer();
        public:
            void cycle(void);
            // void update
        private:
            void load_context(void);
            void init(void);
            GraphicsContext *ctx;
    };
}


#endif