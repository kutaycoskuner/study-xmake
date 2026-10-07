set_project("tutorial")
set_languages("c++20")
add_rules("mode.debug", "mode.release")

target("tutorial")
    set_kind("binary")
    add_files("source/main.cpp")
