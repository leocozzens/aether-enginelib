#ifndef AETHER_DISPLAY_RENDERER_HPP
#define AETHER_DISPLAY_RENDERER_HPP

namespace Aether {
    class DisplayDevice;

    class DisplayRenderer {
        public:
            DisplayRenderer(DisplayDevice *newDev, int width, int height);
            ~DisplayRenderer();
        public:
            void present(void);
            // void update
            void resize(int width, int height);

            DisplayDevice *dev;
        private:
    };
}


#endif