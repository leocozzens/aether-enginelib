set_project("aether")
set_languages("c++17")

add_rules("mode.debug", "mode.release")
add_rules("plugin.compile_commands.autoupdate", { outputdir = "." })

add_requires("glfw 3.4")
add_requires("opengl", { optional = true })

target("aether_core")
    set_kind("static")
    add_files("modules/core/src/*.cpp")
    add_packages("glfw", "opengl", { public = true })
    add_includedirs("modules", { public = true })
    add_sysincludedirs(
        "external/opengl/api",
        "external/egl/api"
    )

target("aether_bin")
    set_kind("binary")
    add_files("modules/runtime/src/*.cpp")
    add_deps("aether_core")