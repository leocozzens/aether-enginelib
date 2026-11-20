set_project("aether")
set_languages("c++17")

add_rules("mode.debug", "mode.release")
add_rules("plugin.compile_commands.autoupdate", { outputdir = "." })

add_requires("glfw 3.4")
add_requires("opengl", { optional = true })
add_includedirs("modules")

function add_module(name) 
    add_files("modules/" .. name .. "/src/*.cpp")
end

target("aether_graphics")
    set_kind("static")
    add_module("core/graphics")

    add_packages("glfw", "opengl", { public = true })
    add_sysincludedirs(
        "external/opengl/api",
        "external/egl/api"
    )

target("aether_world")
    set_kind("static")
    add_module("core/world")

target("aether_engine")
    set_kind("static")
    add_module("core/engine")
    add_deps(
        "aether_graphics",
        "aether_world"
    )

target("aether_bin")
    set_kind("binary")
    add_module("runtime")
    add_deps("aether_engine")