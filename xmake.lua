set_project("tutorial")
set_languages("c++20")
add_rules("mode.debug", "mode.release")
set_targetdir("bin/$(plat)/$(arch)/$(mode)")


target("hello")
    set_kind("static")
    add_files("libs/header-hello-1.0.0/hello.cpp")
    add_includedirs("libs/header-hello-1.0.0", {public = true})
    set_targetdir("bin/$(plat)/$(arch)/$(mode)/static_libs")


target("tutorial")
    set_kind("binary")
    add_files("source/*.cpp") -- adds every ccp file
    add_includedirs("headers")
    add_deps("hello")
    add_defines('DATA_DIR="' .. (os.projectdir():gsub("\\", "/")) .. '/data/"')


