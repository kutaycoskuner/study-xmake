set_project("tutorial")
set_languages("c++20")
add_rules("mode.debug", "mode.release")

target("hello")
    set_kind("static")
    add_files("libs/header-hello-1.0.0/hello.cpp")
    add_includedirs("libs/header-hello-1.0.0", {public = true})

target("tutorial")
    set_kind("binary")
    add_files("source/*.cpp") -- adds every ccp file
    add_includedirs("headers")
    add_deps("hello")

