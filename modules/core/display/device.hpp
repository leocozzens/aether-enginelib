#ifndef AETHER_DISPLAY_DEVICE_HPP
#define AETHER_DISPLAY_DEVICE_HPP

#include <GL/glcorearb.h>

namespace Aether {
    class DisplayDevice {
        public:
            DisplayDevice(void);
            ~DisplayDevice();
        public:
            PFNGLCLEARPROC clear;
            PFNGLCLEARCOLORPROC clearColor;
            PFNGLVIEWPORTPROC viewport;
        private:
    };
}

#endif