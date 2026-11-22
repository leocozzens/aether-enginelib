#ifndef AETHER_DISPLAY_HPP
#define AETHER_DISPLAY_HPP

#include <memory>

#include <core/engine/window.hpp>

namespace Aether {
    class DisplayDevice;
    class DisplayPipeline;
    class DisplayRenderer;

    struct DisplayCfg {
        Window *target;
    };

    class Display {
        public:
            Display(Window &target);
            ~Display();
        public:
            void present(void);
            void resize(int width, int height);
            void change_device(const std::shared_ptr<DisplayDevice> &dev);

            struct {
                std::shared_ptr<DisplayDevice> dev;
                // std::unique_ptr<DisplayPipeline> pipeline;
                std::unique_ptr<DisplayRenderer> renderer;
            } active;
        private:
    };
}

#endif